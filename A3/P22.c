/*******************************************************
 
 ** Created by Nick Major 0879292
 ** A3, 2.2
 ** Due: 03/13/17
 
 *******************************************************/

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>


void HorspoolMatching(char *B, char pattern[100], int *Table, int *count, int *shifts);
int *shiftTable(char pattern[100]);

void HorspoolSearch(char **B, char pattern[100], int size)
{
    int count = 0;
    int shifts = 0;
    clock_t begin;
    clock_t end;
    double time_spent;
    
    begin = clock();
    int *Table = shiftTable(pattern);
    
    for(int k = 0; k < size; k ++)
    {
        HorspoolMatching(B[k], pattern, Table, &count, &shifts);
    }
    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    
    printf("\n**Problem 2.2 Summary**\n");
    printf("Ex time: %4f seconds\n", time_spent);
    printf("pattern shifts: %d\n", shifts);
    printf("Occurences Found: %d\n", count);
}

void HorspoolMatching(char *B, char *pattern, int *Table, int *count, int *shifts)
{
    int i = 0;
    int k = 0;
    int n = (int)strlen(B);
    int m = (int)strlen(pattern);
    
    i=m-1;
    while(i<n)
    {
        k=0;
        while((k<m) && (pattern[m-1-k] == B[i-k]))
        {
            k++;
            *shifts = *shifts +1;
        }
        if(k == m)
        {
            *count = *count +1;
            i += Table[B[i]];
            *shifts = *shifts +1;
        }
        else
        {
            i += Table[B[i]];
            *shifts = *shifts +1;
        }
    }
}

int *shiftTable(char pattern[100])
{
    int static Table[150];
    int m = (int)strlen(pattern);
    
    for(int i = 0; i < 150; i ++)
    {
        Table[i] = m;
    }
    for(int j = 0; j < m-1; j ++)
    {
        Table[pattern[j]]=m-1-j;
    }

    return Table;
}
