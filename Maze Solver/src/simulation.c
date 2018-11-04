/**************************************************************************
 Student Name: Nick Major                Student Number: 0879292
 Date: 06/05/15                          Course Name: cis2520
 ****************************************************************************/

#include "linkedList.h"
#include "stack.h"
#include "simulation.h"

int main (int argc, char * argv[])
{
    int rows = 0;
    int coloumns = 0;
    int i = 0;
    char ** maze;
    stack * toVisit = createStack();
    
    /*reads in file*/
    maze = read(argv);
    
    /*gets the number of rows and coloumns*/
    size (maze, &rows, &coloumns);
    
    /*prints the inputed maze*/
    printf("Maze to be solved:\n");
    for (i = 0; i < rows; i ++)
    {
        printf("%s", maze[i]);
    }
    
    printf("\n\nMaze solution:\n");
    /*gets the stack with the coordinates for the maze solution*/
    toVisit = solveMaze(toVisit, maze, rows, coloumns);
    printMaze(maze, toVisit, rows);

    free(maze);
    destroyStack (toVisit);
    return 0;
}

/*
 read(file): maze
 
 Preconditions: file containing maze
 PostConditions: returns the 2d char array with the maze
 */
char ** read (char * file[])
{
    FILE * mazeFile;
    int counter = 0;
    char buffer[100];
    char ** maze = malloc(sizeof(char)*1000);
    
    mazeFile = fopen(file[1], "r");
    
    if (mazeFile == NULL)
    {
        printf ("error opening maze\n");
        exit(0);
    }
    
    counter = 0;
    while (fgets(buffer, sizeof buffer, mazeFile) != NULL)
    {
        maze[counter] = malloc(sizeof(char)*1000);
        strcpy(maze[counter], buffer);
        counter ++;
    }
    fclose(mazeFile);
    
    return maze;
}

/*
 size(maze, rows, coloumns)
 
 Preconditions: 2d char array containing maze, initialized rows and coloumns
 PostConditions: returns the number of rows and coloumns
 */
void size (char ** maze, int * rows, int * coloumns)
{
    int counter = 1;
    while (maze[counter] != NULL)
    {
        counter ++;
    }
    
    *rows = counter;
    *coloumns = strlen(maze[0])-1;
}

/*
 printMaze(maze, stack, rows)
 
 Preconditions: 2d char array containing maze, initialized stack, rows
 PostConditions: prints the solution to the maze
 */
void printMaze (char ** maze, stack * myStack, int rows)
{
    int i = 0;
    
    while (myStack != NULL)
    {
        if (maze[myStack->x][myStack->y] == ' ')
        {
            maze[myStack->x][myStack->y] = '#';
        }
        myStack = myStack->next;
    }
    
    for (i = 0; i < rows; i ++)
    {
        printf("%s", maze[i]);
    }
    printf("\n");
}

/*
 solveMaze(stack, maze, rows, coloumns) : stack
 
 Preconditions: initialized stack, 2d char array containing maze, rows, coloumns
 PostConditions: solves the maze and returns the coordinates of the solution with a stack
 */
stack * solveMaze (stack * toVisit, char ** maze, int rows, int coloumns)
{
    int i = 0;
    int j = 0;
    int endX;
    int endY;
    int currentX = 0;
    int currentY = 0;
    
    struct listNode * visited = create();
    
    for (i = 0; i < rows; i ++)
    {
        for (j = 0; j < coloumns; j ++)
        {
            /*end coordinated*/
            if (maze[i][j] == 'F')
            {
                endX = i;
                endY = j;
            }
            /*start is added to the stack*/
            else if (maze[i][j] == 'S')
            {
                toVisit = push (toVisit, i, j);
            }
        }
    }
    
    /*maze solving algorithim*/
    while (visit(visited, endX, endY) == false)
    {
        /*gets value from stack and adds to list*/
        peek (toVisit, &currentX, &currentY);
        visited = addToFront (visited, currentX, currentY);
        
        /*gets neighbors*/
        if ((maze[currentX+1][currentY] == ' ' || maze[currentX+1][currentY] == 'F') && visit(visited, currentX+1, currentY) == false)
        {
            toVisit = push (toVisit, currentX+1, currentY);
        }
        else if ((maze[currentX][currentY-1] == ' ' || maze[currentX][currentY-1] == 'F') && visit(visited, currentX, currentY-1) == false)
        {
            toVisit = push (toVisit, currentX, currentY-1);
        }
        else if ((maze[currentX][currentY+1] == ' ' || maze[currentX][currentY+1] == 'F') && visit(visited, currentX, currentY+1) == false)
        {
            toVisit = push (toVisit, currentX, currentY+1);
        }
        else if ((maze[currentX-1][currentY] == ' ' || maze[currentX-1][currentY] == 'F') && visit(visited, currentX-1, currentY) == false)
        {
            toVisit = push (toVisit, currentX-1, currentY);
        }
        /*if can't go removes pops stack*/
        else
        {
            toVisit = pop (toVisit);
        }
    }
    
    destroyList (visited);
    
    return toVisit;
}
