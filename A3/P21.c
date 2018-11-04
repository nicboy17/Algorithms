/*******************************************************
 
 ** Created by Nick Major 0879292
 ** A3, 2.1
 ** Due: 03/13/17
 
 *******************************************************/

#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>


void StringSearch(char *B, char pattern[100], int *count, int *shifts);

void bruteSearch(char **B, char pattern[100], int size)
{
    int count = 0;
    int shifts = 0;
    clock_t begin;
    clock_t end;
    double time_spent;
    
    begin = clock();
    for(int k = 0; k < size; k ++)
    {
        StringSearch(B[k], pattern, &count, &shifts);
    }
    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    
    printf("\n**Problem 2.1 Summary**\n");
    printf("Ex time: %4f seconds\n", time_spent);
    printf("pattern shifts: %d\n", shifts);
    printf("Occurences Found: %d\n", count);
}

void StringSearch(char *B, char pattern[100], int *count, int *shifts)
{
    int i = 0;
    int j = 0;
    
    int n = (int)strlen(B);
    int m = (int)strlen(pattern);
    
    while (i <= n-m)
    {
        j = 0;
        while( j < m && pattern[j] == B[i+j])
        {
            j ++;
        }
        if( j == m )
        {
            *count = *count +1;
            i ++;
            *shifts = *shifts +1;
        }
        else
        {
            i ++;
            *shifts = *shifts +1;
        }
    }
}
