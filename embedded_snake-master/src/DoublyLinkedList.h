#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

/* Node structure to use in doubly-linked list
*/
typedef struct Node {
	int x, y;
	struct Node* prev;
	struct Node* next;
} Node;

/* Doubly-linked list structure
*/
typedef struct List {
    Node* HEAD;
    Node* TAIL;
} List;
List list;

/* Construct a node object.
*  ARGS: x and y coordinates
*  RETURN: dynamically-allocated node
*/
extern Node* createNode(int x, int y);

/* Insert a node at the list head.
*  If there are no nodes, create a node and set HEAD, TAIL to point to it.
*  ARGS: x and y coordinates
*/
extern void insertAtHead(int x, int y);

/* Insert a node at the list tail.
*  If there are no nodes, create a node and set HEAD, TAIL to point to it.
*  ARGS: x and y coordinates
*/
extern void insertAtTail(int x, int y);

/* Free the memory that was allocated for the list.
*  This action also sets HEAD and TAIL to NULL.
*/
extern void freeList();

/* Move the head of the list to a new coordinate.
*  Sends the old x and y coordinates down the list until all nodes' coordinates
*  have been shifted. List stays the same size.
*  ARGS: x and y coordinates
*/
extern void moveHead(int x, int y);

/* Move the tail of the list to a new coordinate.
*  Sends the old x and y coordinates up the list until all nodes' coordinates
*  have been shifted. List stays the same size.
*  ARGS: x and y coordinates
*/
extern void moveTail(int x, int y);

/* Get the length of the list
*  RETURN: length, or 0 if nothing there
*/
extern int getLength();

/* See if a coordinate is represented in the list
*  RETURN: 1 if present, 0 if not present
*/
extern int inList(int x, int y);

/* Display the list to stdout.
*  NOTE: To be used only for debugging purposes.
*/
extern void _display();

#endif
