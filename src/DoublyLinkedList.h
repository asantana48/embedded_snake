#ifndef _DOUBLYLINKEDLIST_H
#define _DOUBLYLINKEDLIST_H

// *****************
// Standard Headers
// *****************
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

// *****************
// Node Structure
// *****************
typedef struct Node {
	int x, y;
	struct Node* prev;
	struct Node* next;
} Node;

// **********************
// Linked List Structure
// **********************
typedef struct List {
    Node* HEAD;
    Node* TAIL;
} List;

// *******************
// Global List Structure
// *******************
List list;

// *******************
// Function Prototypes
// *******************
extern void freeList();
extern int getLength();
extern void _display();
extern int inList(int x, int y);
extern void moveTail(int x, int y);
extern void moveHead(int x, int y);
extern void insertAtTail(int x, int y);
extern void insertAtHead(int x, int y);
extern Node* createNode(int x, int y);

#endif
