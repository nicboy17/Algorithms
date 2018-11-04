/**************************************************************************
 Student Name: Nick Major                Student Number: 0879292
 Date: 06/05/15                          Course Name: cis2520
 ****************************************************************************/

/*
 read(file): maze
 
 Preconditions: file containing maze
 PostConditions: returns the 2d char array with the maze
 */
char ** read (char * file[]);

/*
 size(maze, rows, coloumns)
 
 Preconditions: 2d char array containing maze, initialized rows and coloumns
 PostConditions: returns the number of rows and coloumns
 */
void size (char ** maze, int * rows, int * coloumns);

/*
 solveMaze(stack, maze, rows, coloumns) : stack
 
 Preconditions: initialized stack, 2d char array containing maze, rows, coloumns
 PostConditions: solves the maze and returns the coordinates of the solution with a stack
 */
stack * solveMaze (stack * toVisit, char ** maze, int rows, int coloumns);

/*
 printMaze(maze, stack, rows)
 
 Preconditions: 2d char array containing maze, initialized stack, rows
 PostConditions: prints the solution to the maze
 */
void printMaze (char ** maze, stack * myStack, int rows);

