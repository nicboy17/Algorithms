/*******************************************************
 
 ** Created by Nick Major 0879292
 ** A3, 1.1
 ** Due: 03/13/17
 
 *******************************************************/

#include <stdio.h>
#include <string.h>
#include <time.h>


typedef struct {
    char A[30000][12];
}arrA;

void displayAnagrams( arrA anagrams, int k );
void swap(char *x, char *y);
void compare(char *a, int l, int r, char *b, int *result);


void anagramDetect(arrA A, char anagram[12])
{
    int n = (int)strlen(anagram);
    int k = 0;
    int result = 0;
    arrA anagrams;
    strcpy(anagrams.A[0], "");
    clock_t begin;
    clock_t end;
    double time_spent;
    
    begin = clock();
    for( int i = 0; i < 23999; i ++ )
    {
        if(strlen(anagram) == strlen(A.A[i]))
        {
            compare(anagram, 0, n-1, A.A[i], &result);
            if( result == 1 )
            {
                strcpy(anagrams.A[k], A.A[i]);
                k ++;
            }
            result = 0;
        }
    }
    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    
    printf("\n**Problem 1.1 Summary**\n");
    printf("Ex time: %4f seconds\n", time_spent);
    printf("Anagrams Found: %d\n", k);
    displayAnagrams(anagrams, k);
}

void swap(char *x, char *y)
{
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void compare(char *a, int l, int r, char *b, int *result)
{
    int i;
    
    if (l != r && *result != 1)
    {
        for (i = l; i <= r; i++)
        {
            swap((a+l), (a+i));
            compare(a, l+1, r, b, result);
            swap((a+l), (a+i));
        }
    }
    else if( strcmp(a,b) == 0 )
    {
        *result = 1;
    }
}

void displayAnagrams( arrA anagrams, int k )
{
    if(k >= 3)
    {
        for( int i = 0; i < k; i = i+3 )
        {
            printf("%s %s %s\n", anagrams.A[i], anagrams.A[i+1], anagrams.A[i+2]);
        }
    }
    else if (k > 0)
    {
        for( int i = 0; i < k; i ++ )
        {
            printf("%s\n", anagrams.A[i]);
        }
    }
    printf("\n");
}
