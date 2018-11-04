/**************************************************************************
 Student Name: Nick Major                Student Number: 0879292
 Date: 06/05/15                          Course Name: cis2520
 ****************************************************************************/

#include "stack.h"
#include "linkedList.h"
#include "testing.h"

int main(void)
{
    /*initializes stacks*/
    stack * t1 = createStack();
    stack * t2 = createStack();
    stack * t3 = createStack();
    
    /*basic test*/
    int test1x[11] = {0,1,2,3,4,5,6,7,8,9,10};
    int test1y[11] = {10,9,8,7,6,5,4,3,2,1,0};
    /*large number test*/
    int test2x[6] = {2222, 3000, 9999, 5555, 1111, 6666};
    int test2y[6] = {0, 888, 999999, 44444, 666, 22222};
    /*negative test*/
    int test3x[5] = {-10, -23, -33, -42, -5};
    int test3y[5] = {-1, -3, -5, -6, -7};
    /*NULL test*/
    int test4x[1] = {0};
    int test4y[1] = {0};
    
    /*Automated Testing*/
    testing(test1x, test1y, 1, 11, t1);
    testing(test2x, test2y, 2, 6, t2);
    testing(test3x, test3y, 3, 5, t3);
    testing(test4x, test4y, 4, 1, NULL);
    
    /*Destroy stack*/
    printf("\n*Test Destroy stacks*\n");
    destroyStack(t1);
    destroyStack(t2);
    destroyStack(t3);
    
    return 0;
}

/*
 testing(arrayX, arrayY, test number, array length, stack)
 
 PreConditions: An initialized stack exists, length of the arrays, test number, and initialized arrays
 PostConditions: tests the stack through different test cases
 */
void testing (int arrayx[], int arrayy[], int x, int l, stack * myStack)
{
    int i = 0;
    bool test = false;
    bool empty = false;
    int elementx = 0;
    int elementy = 0;
    
    printf("\n***Test %d***\n", x);
    
    /*push and printing updated list*/
    printf("*test push*\n");
    for (i = 0; i < l; i ++)
    {
        myStack = push(myStack, arrayx[i], arrayy[i]);
        printList (myStack);
    }
    
    /*see if elements are in the stack*/
    printf("*test to see if -5, -7 is in the stack*\n");
    test = visit(myStack, -5, -7);
    if (test == true)
    {
        printf("yes it is\n");
    }
    else
    {
        printf("no it is not\n");
    }
    
    /*see if the stack is empty*/
    printf("*test to see if stack is empty*\n");
    empty = isEmpty(myStack);
    if (empty == true)
    {
        printf("yes it is\n");
    }
    else
    {
        printf("no it is not\n");
    }
    
    /*test pop*/
    printf("\n*Test pop*\n");
    myStack = pop(myStack);
    printList (myStack);
    
    /*peek test*/
    printf("\n*Test peek*\n");
    peek(myStack, &elementx, &elementy);
    printf("the first elements in the stack are: %d,%d\n", elementx, elementy);
}

