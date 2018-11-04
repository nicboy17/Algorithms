/**************************************************************************
 Student Name: Nick Major                Student Number: 0879292
 Date: 06/05/15                          Course Name: cis2520
 ****************************************************************************/

#include "linkedList.h"

/*
 create(): theList
 
 Preconditions: none
 PostConditions: a new list is created and is empty
 */
struct listNode * create()
{
    struct listNode * theList = malloc(sizeof(struct listNode)*1000);
    theList->next = NULL;
    
    return theList;
}

/*
 addToFront(theList, element): theList
 
 Preconditions: An initialized list is available. The element as the parameter is of the correct type for the list.
 PostConditions: The element is added to the front of the list, the length of the list is increased by one, the head of the list is set to point at the newly added element.
 */
struct listNode * addToFront (struct listNode * theList, int element1, int element2)
{
    struct listNode * newNode = initNode(element1,element2);
    
    if (theList == NULL)
    {
        return NULL;
    }
    
    newNode->next = theList;
    theList = newNode;
    
    return theList;
}

/*
 removeFromFront(theList) : temp
 
 Preconditions: A non-empty list is available
 PostConditions: The first element of the list is removed, the length of the list is decreased by one, the head of the list reduced list is returned.
 */
struct listNode * removeFromFront(struct listNode * theList)
{
    struct listNode * temp = NULL;
    
    if (theList == NULL)
    {
        return NULL;
    }
    
    temp = theList->next;
    theList->next = NULL;
    
    return temp;
}

/*
 getFirstItem(theList) : element
 
 Preconditions: A non-empty list is available
 PostConditions: The first element of the list is returned
 */
void getFirstItem (struct listNode * theList, int * element1, int * element2)
{
    if (theList == NULL)
    {
        *element1 = 0;
        *element2 = 0;
    }
    
    *element1 = theList->x;
    *element2 = theList->y;
}

/*
 length(theList) : counter - 1
 
 Preconditions: A non-empty list is available
 PostConditions: While the next element is not the tail (NULL), the counter is increased. The counter is returned.
 */
int length(struct listNode * theList)
{
    int counter;
    
    if (theList == NULL)
    {
        return 0;
    }
    
    counter = 0;
    while (theList != NULL)
    {
        theList = theList->next;
        counter ++;
    }
    
    return counter - 1;
}

/*
 printList(theList)
 
 Preconditions: A non-empty list is available
 PostConditions: While the counter is less than lenghth of the list, the list is printed on a single line.
 */
void printList (struct listNode * theList)
{
    int counter = 0;
    int size = 0;
    
    size = length(theList);
    while (counter < size)
    {
        printf("%d,%d ", theList->x, theList->y);
        theList = theList->next;
        counter ++;
    }
    printf("\n");
}

/*
 destroy(List)
 
 Preconditions: a list exists
 PostConditions: the list is destroyed
 */
void destroyList (struct listNode * theList)
{
    while (theList != NULL)
    {
        theList->x = 0;
        theList->y = 0;
        free(theList);
        theList = theList->next;
    }
    theList = NULL;
}

/*
 initNode(element) : newNode
 
 Preconditions: An integer
 PostConditions: a newNode is initialized and malloced, the element is added, the next element is set to NULL and the newNode is returned.
*/
struct listNode * initNode(int element1, int element2)
{
    struct listNode * newNode;
    newNode = malloc(sizeof(struct listNode));
    newNode->x = element1;
    newNode->y = element2;
    newNode->next = NULL;
    
    return newNode;
}
