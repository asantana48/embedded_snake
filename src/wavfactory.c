// *****************
// Local Headers
// *****************
#include "wavfactory.h"

// ********************
// Application Variables
// ********************
int totalSize;
int intProgress;
FILE *waveFile;
float progress = 0;
snd_pcm_t *pcm_handle;
snd_mixer_t *mixer_handle;
const char *RIFF_Id = "RIFF";
const char *WAVE_Id = "WAVE";
extern PtWidget_t *ProgressBar;

// *****************
// RIFF Tag Structure
// *****************
typedef struct RIFF_Tag {
	char tag[4];
	long length;
} RIFF_Tag;

// ********************
// RIFF Header Structure
// ********************
typedef struct RIFF_Header {
	char Riff[4];
	long Size;
	char Wave[4];
} RIFF_Header;

// *********************
// WAVE Header Structure
// *********************
typedef struct WAVE_Header {
	short FormatTag;
	short Channels;
	long SamplesPerSec;
	long AvgBytesPerSec;
	short BlockAlign;
	short BitsPerSample;
} WAVE_Header;

// Function : err()
// Purpose  : Function used to output a message to the console through the pass of a character array.
int err(char *msg) {
	perror(msg);
	return -1;
} // end err()

// Function : FindTag()
// Purpose  : To get the RIFF tag from a file and convert it from little endian to native endian value based of the length of the tag's buffer.
int FindTag(FILE * fp, const char *tag) {
	int retVal;
	RIFF_Tag tagBfr = { "", 0 };
	retVal = 0;
	while (fread((unsigned char *) &tagBfr, sizeof(tagBfr), 1, fp)) {
		if (strncmp(tag, tagBfr.tag, sizeof tagBfr.tag) == 0) {
			retVal = ENDIAN_LE32 (tagBfr.length);
			break;
		} // end if
		fseek(fp, tagBfr.length, SEEK_CUR);
	} // end while
	totalSize = tagBfr.length;
	return (retVal);
} // end FindTag()

// Function : CheckFileHeader()
// Purpose  : Check to indicate whether the file headers are read correctly and matched to their respective ids.
int CheckFileHeader(FILE * fp) {
	RIFF_Header riffHdr = { "", 0 };
	if (fread((unsigned char *) &riffHdr, sizeof(RIFF_Header), 1, fp) == 0)
		return 0;
	if (strncmp(riffHdr.Riff, RIFF_Id, strlen(RIFF_Id)) || strncmp(
			riffHdr.Wave, WAVE_Id, strlen(WAVE_Id)))
		return -1;
	return 0;
} // end CheckFileHeader()

// Function : onStopped()
// Purpose  : Clear the memory for the wave file and reset the thread values for next file.
void onStopped() {
	snd_pcm_plugin_flush(pcm_handle, SND_PCM_CHANNEL_PLAYBACK);
	snd_mixer_close(mixer_handle);
	snd_pcm_close(pcm_handle);
	fclose(waveFile);
	paused = 0;
	PtEnter(Pt_EVENT_PROCESS_ALLOW);
	PtLeave(Pt_EVENT_PROCESS_ALLOW);
} // end onStopped()

// Function : playingWave()
// Purpose  : Send wave file information to the pcm device and playback the indicated wave file from the device.
void *playingWave() {
	int card = -1;
	int dev = 0;
	WAVE_Header wavHdr1;
	int mSamples;
	int mSampleRate;
	int mSampleChannels;
	int mSampleBits;
	char *mSampleBfr1;
	int fragsize = -1;
	int rtn;
	snd_pcm_channel_info_t pi;
	snd_mixer_group_t group;
	snd_pcm_channel_params_t pp;
	snd_pcm_channel_setup_t setup;
	int bsize;
	int sizeRtn;
	int N = 0;
	fd_set rfds;
	fd_set wfds;
	
	if (card == -1) {
		if ((rtn = snd_pcm_open_preferred(&pcm_handle, &card, &dev,
				SND_PCM_OPEN_PLAYBACK)) < 0)
			return err("device open error");
	} else {
		if ((rtn = snd_pcm_open(&pcm_handle, card, dev, SND_PCM_OPEN_PLAYBACK))
				< 0)
			return err("device open error");
	} // end if-else
	
	char songName[50];
	strcpy(songName, musicDir);
	strcat(songName, notes[media_index]);
	printf("Song Directory: %s\n", songName);

	if ((waveFile = fopen(songName, "r")) == 0)
		return err("file open #1");
	if (CheckFileHeader(waveFile) == -1)
		return err("CheckHdr #1");

	mSamples = FindTag(waveFile, "fmt ");
	fread(&wavHdr1, sizeof(wavHdr1), 1, waveFile);
	fseek(waveFile, (mSamples - sizeof(WAVE_Header)), SEEK_CUR);
	mSampleRate = ENDIAN_LE32 (wavHdr1.SamplesPerSec);
	mSampleChannels = ENDIAN_LE16 (wavHdr1.Channels);
	mSampleBits = ENDIAN_LE16 (wavHdr1.BitsPerSample);
	printf("SampleRate = %d, Channels = %d, SampleBits = %d, Samples = %d\n",
			mSampleRate, mSampleChannels, mSampleBits, mSamples);

	if ((rtn = snd_pcm_plugin_set_disable(pcm_handle, PLUGIN_DISABLE_MMAP)) < 0) {
		fprintf(stderr, "snd_pcm_plugin_set_disable failed: %s\n",
				snd_strerror(rtn));
		return -1;
	} // end if
	
	memset(&pi, 0, sizeof(pi));
	pi.channel = SND_PCM_CHANNEL_PLAYBACK;

	if ((rtn = snd_pcm_plugin_info(pcm_handle, &pi)) < 0) {
		fprintf(stderr, "snd_pcm_plugin_info failed: %s\n", snd_strerror(rtn));
		return -1;
	} // end if

	memset(&pp, 0, sizeof(pp));
	pp.mode = SND_PCM_MODE_BLOCK;
	pp.channel = SND_PCM_CHANNEL_PLAYBACK;
	pp.start_mode = SND_PCM_START_FULL;
	pp.stop_mode = SND_PCM_STOP_STOP;
	pp.buf.block.frag_size = pi.max_fragment_size;

	if (fragsize != -1)
		pp.buf.block.frag_size = fragsize;

	pp.buf.block.frags_max = 1;
	pp.buf.block.frags_min = 1;
	pp.format.interleave = 1;
	pp.format.rate = mSampleRate;
	pp.format.voices = mSampleChannels;

	if (ENDIAN_LE16(wavHdr1.FormatTag) == 6)
		pp.format.format = SND_PCM_SFMT_A_LAW;
	else if (ENDIAN_LE16(wavHdr1.FormatTag) == 7)
		pp.format.format = SND_PCM_SFMT_MU_LAW;
	else if (mSampleBits == 8)
		pp.format.format = SND_PCM_SFMT_U8;
	else if (mSampleBits == 24)
		pp.format.format = SND_PCM_SFMT_S24;
	else
		pp.format.format = SND_PCM_SFMT_S16_LE;

	if ((rtn = snd_pcm_plugin_params(pcm_handle, &pp)) < 0) {
		fprintf(stderr, "snd_pcm_plugin_params failed: %s\n", snd_strerror(rtn));
		return -1;
	} // end if

	if ((rtn = snd_pcm_plugin_prepare(pcm_handle, SND_PCM_CHANNEL_PLAYBACK)) < 0)
		fprintf(stderr, "snd_pcm_plugin_prepare failed: %s\n",
				snd_strerror(rtn));

	memset(&setup, 0, sizeof(setup));
	memset(&group, 0, sizeof(group));
	setup.channel = SND_PCM_CHANNEL_PLAYBACK;
	setup.mixer_gid = &group.gid;

	if ((rtn = snd_pcm_plugin_setup(pcm_handle, &setup)) < 0) {
		fprintf(stderr, "snd_pcm_plugin_setup failed: %s\n", snd_strerror(rtn));
		return -1;
	} // end if

	printf("Format %s \n", snd_pcm_get_format_name(setup.format.format));
	printf("Frag Size %d \n", setup.buf.block.frag_size);
	printf("Rate %d \n", setup.format.rate);
	bsize = setup.buf.block.frag_size;

	if (group.gid.name[0] == 0) {
		printf("Mixer Pcm Group [%s] Not Set \n", group.gid.name);
		exit(-1);
	} // end if

	printf("Mixer Pcm Group [%s]\n", group.gid.name);

	if ((rtn = snd_mixer_open(&mixer_handle, card, setup.mixer_device)) < 0) {
		fprintf(stderr, "snd_mixer_open failed: %s\n", snd_strerror(rtn));
		return -1;
	} // end if

	mSamples = FindTag(waveFile, "data");
	mSampleBfr1 = malloc(bsize);
	FD_ZERO (&rfds);
	FD_ZERO (&wfds);
	sizeRtn = 1;

	while (N < mSamples && sizeRtn > 0 && stopped == 0) {
		while (paused == 1) {
			usleep(1000);

			if (stopped == 1) {
				onStopped();
				return;
			} // end if
		} // end while

		if (tcgetpgrp(0) == getpid())
			FD_SET (STDIN_FILENO, &rfds);

		FD_SET (snd_mixer_file_descriptor (mixer_handle), &rfds);
		FD_SET (snd_pcm_file_descriptor (pcm_handle, SND_PCM_CHANNEL_PLAYBACK), &wfds);
		rtn = max (snd_mixer_file_descriptor (mixer_handle),
				snd_pcm_file_descriptor (pcm_handle, SND_PCM_CHANNEL_PLAYBACK));

		if (select(rtn + 1, &rfds, &wfds, NULL, NULL) == -1)
			return err("select");

		if (FD_ISSET (snd_mixer_file_descriptor (mixer_handle), &rfds)) {
			snd_mixer_callbacks_t callbacks = { 0, 0, 0, 0 };
			snd_mixer_read(mixer_handle, &callbacks);
		} // end if

		if (FD_ISSET (snd_pcm_file_descriptor (pcm_handle, SND_PCM_CHANNEL_PLAYBACK), &wfds)) {
			snd_pcm_channel_status_t status;
			int written = 0;
			
			if ((sizeRtn = fread(mSampleBfr1, 1, min (mSamples - N, bsize),
					waveFile)) <= 0)
				continue;

			written = snd_pcm_plugin_write(pcm_handle, mSampleBfr1, sizeRtn);

			if (written < sizeRtn) {
				memset(&status, 0, sizeof(status));
				status.channel = SND_PCM_CHANNEL_PLAYBACK;

				if (snd_pcm_plugin_status(pcm_handle, &status) < 0) {
					fprintf(stderr, "underrun: playback channel status error\n");
					exit(1);
				} // end if

				if (status.status == SND_PCM_STATUS_READY || status.status
						== SND_PCM_STATUS_UNDERRUN) {
					if (snd_pcm_plugin_prepare(pcm_handle,
							SND_PCM_CHANNEL_PLAYBACK) < 0) {
						fprintf(stderr, "underrun: playback channel prepare error\n");
						exit(1);
					} // end if
				} // end if

				if (written < 0)
					written = 0;

				written += snd_pcm_plugin_write(pcm_handle, mSampleBfr1
						+ written, sizeRtn - written);
			} // end if
			
			N += written;
			progress = ((float) N / (float) totalSize) * 100;
			intProgress = (int) progress;
			PtEnter(Pt_EVENT_PROCESS_ALLOW);
			PtLeave(Pt_EVENT_PROCESS_ALLOW);
		} // end if
	} // end while
	
	if (stopped == 1) {
			PtEnter(Pt_EVENT_PROCESS_ALLOW);
			PtLeave(Pt_EVENT_PROCESS_ALLOW);
	} // end if

	sizeRtn = snd_pcm_plugin_flush(pcm_handle, SND_PCM_CHANNEL_PLAYBACK);
	rtn = snd_mixer_close(mixer_handle);
	rtn = snd_pcm_close(pcm_handle);
	fclose(waveFile);
	inFunction = 0;
} // end playingWave()




















