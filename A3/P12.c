/*******************************************************
 
 ** Created by Nick Major 0879292
 ** A3, 1.2
 ** Due: 03/13/17
 
 *******************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


typedef struct {
    char A[24000][12];
}arrA;

void sort(char A[], int right, int left);
void merging(char A[], int first, int last);
extern void displayAnagrams( arrA anagrams, int k );

void quickAnagram(arrA A, char anagram[12])
{
    int n, k = 0;
    char temp[12];
    arrA anagrams;
    strcpy(anagrams.A[0], "");
    clock_t begin;
    clock_t end;
    double time_spent;
    
    begin = clock();
    sort(anagram, 0, (int)strlen(anagram)-1);
    
    for(int i = 0; i < 23999; i ++)
    {
        if(strlen(anagram) == strlen(A.A[i]))
        {
            strcpy( temp, A.A[i] );
            n = (int)strlen(temp)-1;
            sort(temp, 0, n);
            if( strcmp(temp, anagram) == 0 )
            {
                strcpy(anagrams.A[k], A.A[i]);
                k ++;
            }
        }
    }
    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    
    printf("\n**Problem 1.2 Summary**\n");
    printf("Ex time: %4f seconds\n", time_spent);
    printf("Anagrams Found: %d\n", k);
    displayAnagrams(anagrams, k);
}

void merging(char A[], int first, int last)
{
    int mid = (first+last)/2;
    
    int i = first;
    int j = mid+1;
    char temp[last-first+1];
    int k = 0;
    
    while (i <= mid && j <= last)
    {
        if (A[i] < A[j])
        {
            temp[k++] = A[i++];
        }
        else
        {
            temp[k++] = A[j++];
        }
    }
    
    while (i <= mid)
    {
        temp[k++] = A[i++];
    }
    
    while (j <= last)
    {
        temp[k++] = A[j++];
    }
    
    for (int x=0 ; x<last-first+1 ; x++)
    {
        A[x+first] = temp[x];
    }
}

void sort(char A[], int right, int left)
{
    int mid = 0;
    
    if (right < left)
    {
        mid = (right + left)/2;
        
        sort(A, right, mid);
        sort(A, mid+1, left);
        merging(A, right, left);
    }
}
