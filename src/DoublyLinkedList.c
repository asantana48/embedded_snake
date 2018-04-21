#include "DoublyLinkedList.h"

Node* createNode(int x, int y) {
	Node* newNode = (struct Node*) malloc(sizeof(struct Node));
	newNode->x = x;
	newNode->y = y;
	newNode->prev = NULL;
	newNode->next = NULL;
	return newNode;
} // end createNode()

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

void freeList() {
	while (list.HEAD != NULL && list.TAIL != NULL){
		Node* oldHead = list.HEAD;
		list.HEAD = list.HEAD->next;

		if (oldHead != NULL) {
			free(oldHead);
			oldHead = NULL;
		}
	}
	list.TAIL = NULL;
} // end freeList()

void moveHead(int x, int y) {
	Node* iter = list.HEAD;
	while (iter != NULL) {
		// Save old coords
		int old_x = iter->x;
		int old_y = iter->y;

		// Update with new coords
		iter->x = x;
		iter->y = y;
		iter = iter->next;

		// Restore old coords, so that we can pass them down
		x = old_x;
		y = old_y;
	}
} // end insertUpdateHead()

void moveTail(int x, int y) {
	Node* iter = list.TAIL;
	while (iter != NULL) {
		// Save old coords
		int old_x = iter->x;
		int old_y = iter->y;

		// Update with new coords
		iter->x = x;
		iter->y = y;
		iter = iter->prev;

		// Restore old coords, so that we can pass them down
		x = old_x;
		y = old_y;
	}
}

int getLength() {
	int length = 0;
	Node *iter = list.HEAD;
	while (iter != NULL) {
		length++;
		iter++;
	} 
	return length;
}

int inList(int x, int y) {
	Node* iter = list.HEAD;
	while (iter != NULL) {
		if (iter->x == x && iter->y == y)
			return 1;
		iter = iter->next;
	}
	return 0;
}
void _display() {
    Node* iter = list.HEAD;
    printf("Coordinates:\n");
    while (iter != NULL) {
        printf("(%d, %d)\n", iter->x, iter->y);
        iter = iter->next;
    }
} // end display()