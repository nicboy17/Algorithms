/**************************************************************************
 Student Name: Nick Major                Student Number: 0879292
 Date: 06/05/15                          Course Name: cis2520
 ****************************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

struct listNode
{
    int x;
    int y;
    struct listNode * next;
};

typedef struct listNode node;

/*
 create(): List
 Preconditions: none
 PostConditions: a new list is created and is empty
 */
struct listNode * create ();

/*
 addToFront(List, Element): theHead
 
 Preconditions: An initialized list is available. The element as the parameter is of the correct type for the list.
 PostConditions: The element is added to the front of the list, the length of the list is increased by one, the head of the list is set to point at the newly added element.
 */
struct listNode * addToFront (struct listNode * theList, int element1, int element2);

/*
 removeFromFront(theList) : temp
 
 Preconditions: A non-empty list is available
 PostConditions: The first element of the list is removed, the length of the list is decreased by one, the head of the list reduced list is returned.
 */
struct listNode * removeFromFront(struct listNode * theList);

/*
 getFirstItem(theList) : element
 
 Preconditions: A non-empty list is available
 PostConditions: The first element of the list is returned
 */
void getFirstItem (struct listNode * theList, int * element1, int * element2);

/*
 length(theList) : counter - 1
 
 Preconditions: A non-empty list is available
 PostConditions: While the next element is not the tail (NULL), the counter is increased. The counter is returned.
 */int length(struct listNode * theList);

/*
 printList(theList)
 
 Preconditions: A non-empty list is available
 PostConditions: While the counter is less than lenghth of the list, the list is printed on a single line.
 */
void printList (struct listNode * theList);

/*
 destroy(List)
 
 Preconditions: a list exists
 PostConditions: the list is destroyed
 */
void destroyList (struct listNode * theList);

/*
 initNode(element) : newNode
 
 Preconditions: An integer
 PostConditions: a newNode is initialized and malloced, the element is added, the next element is set to NULL and the newNode is returned.
 */
struct listNode * initNode(int element1, int element2);
