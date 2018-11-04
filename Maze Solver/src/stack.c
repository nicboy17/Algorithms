/**************************************************************************
 Student Name: Nick Major                Student Number: 0879292
 Date: 06/05/15                          Course Name: cis2520
 ****************************************************************************/

#include "linkedList.h"
#include "stack.h"

/*
createStack() : myStack
 
PreConditions: none
PostConditions: A stack is created and initialized to empty
 */
stack * createStack ()
{
    stack * myStack;
    myStack = create();
    return myStack;
}

/*
destroyStack()
 
PreConditions: An initialized stack exists
PostConditions: The stack is destroyed and all associated memory is freed.
 */
void destroyStack (stack * temp)
{
    destroyList(temp);
}

/*
push(Stack, Element) : myStack

PreConditions: The stack is not full
PostConditions: An element is added to the stack, the length is increased by one, the top of the stack points to the newly added element
 */
stack * push (stack * myStack, int element1, int element2)
{
    myStack = addToFront (myStack, element1, element2);
    return myStack;
}

/*
pop(Stack) : myStack
 
PreConditions: The stack is not empty
PostConditions: The first (top) element of the stack is removed and returned to the caller. The top of the stack is set to the successor of the removed element, the length of the stack is decremented by one.
 */
stack * pop (stack * myStack)
{
    myStack = removeFromFront(myStack);
    return myStack;
}

/*
peek (Stack): element

PreConditions: The stack is not empty
PostConditions: Returns the element that is at the top of the stack but does not remove that element from the stack.
*/
void peek (stack * myStack, int * element1, int * element2)
{
    if (myStack == NULL)
    {
        element1 = 0;
        element2 = 0;
    }
    else
    {
        getFirstItem(myStack, element1, element2);
    }
}

/*
isEmpty(Stack) : bool

PreConditions: The stack is not empty
PostConditions: Returns if the stack is true or false.
*/
bool isEmpty (stack * myStack)
{
    if (myStack == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/*
visit(Stack, element1, element2) : bool

PreConditions: The stack is not empty
PostConditions: Returns true or false if the elements are in the stack.
*/
bool visit (stack * myStack, int element1, int element2)
{
    bool temp = false;
    while (myStack != NULL)
    {
        if (myStack->x == element1 && myStack->y == element2)
        {
            temp = true;
            break;
        }
        else if (myStack->x != element1 && myStack->y != element2)
        {
            temp = false;
            break;
        }
        
        myStack = myStack->next;
    }
    return temp;
}
