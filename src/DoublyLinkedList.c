#include "doublylinkedlist.h"

// Function : createNode()
// Purpose : Create new node structure instance.
Node* createNode(int x, int y) {
	Node* newNode = (struct Node*) malloc(sizeof(struct Node));
	newNode->x = x;
	newNode->y = y;
	newNode->prev = NULL;
	newNode->next = NULL;
	return newNode;
} // end createNode()

// Function : insertAtHead()
// Purpose : Insert a new node at the head of the linked list.
void insertAtHead(int x, int y) {
	Node* newNode = createNode(x, y);
	if(list.HEAD == NULL) {
		list.HEAD = newNode;
		list.TAIL = newNode;
		return;
	} // end if
	list.HEAD->prev = newNode;
	newNode->next = list.HEAD;
	list.HEAD = newNode;
} // end insertAtHead()

// Function : insertAtTail()
// Purpose : Insert a new node at the tail of the linked list.
void insertAtTail(int x, int y) {
	Node* newNode = createNode(x, y);
	if(list.TAIL == NULL) {
		list.HEAD = newNode;
		list.TAIL = newNode;
		return;
	} // end if
	list.TAIL->next = newNode;
	newNode->prev = list.TAIL;
	list.TAIL = newNode;
} // end insertAtTail()

// Function : freeList()
// Purpose : Free memory allocate by list structure.
void freeList() {
	while (list.HEAD != NULL && list.TAIL != NULL){
		Node* oldHead = list.HEAD;
		list.HEAD = list.HEAD->next;
		if (oldHead != NULL) {
			free(oldHead);
			oldHead = NULL;
		} // end if
	} // end while
	list.HEAD = NULL;
	list.TAIL = NULL;
} // end freeList()

// Function : moveHead()
// Purpose : Move the head node located in the linked list.
void moveHead(int x, int y) {
	Node* iter = list.HEAD;
	while (iter != NULL) {
		int old_x = iter->x;
		int old_y = iter->y;
		iter->x = x;
		iter->y = y;
		iter = iter->next;
		x = old_x;
		y = old_y;
	} // end while
} // end moveHead()

// Function : moveTail()
// Purpose : Move the tail node located within the linked list.
void moveTail(int x, int y) {
	Node* iter = list.TAIL;
	while (iter != NULL) {
		int old_x = iter->x;
		int old_y = iter->y;
		iter->x = x;
		iter->y = y;
		iter = iter->prev;
		x = old_x;
		y = old_y;
	} // end while
} // end moveTail()

// Function : getLength()
// Purpose : Return the current length of the global list structure.
int getLength() {
	int length = 0;
	Node *iter = list.HEAD;
	while (iter != NULL) {
		length++;
		iter++;
	} // end while
	return length;
} // end getLength()

// Function : inList()
// Purpose : Determine whether a node already exists at given location in list.
int inList(int x, int y) {
	Node* iter = list.HEAD;
	while (iter != NULL) {
		if (iter->x == x && iter->y == y)
			return 1;
		iter = iter->next;
	} // end while
	return 0;
} // end inList()

// Function : _display()
// Purpose : Display the current list structure to the console.
void _display() {
    Node* iter = list.HEAD;
    printf("Coordinates:\n");
    while (iter != NULL) {
        printf("(%d, %d)\n", iter->x, iter->y);
        iter = iter->next;
    } // end while
} // end display()
