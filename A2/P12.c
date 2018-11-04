/*******************************************************
 
 ** Created by Nick Major 0879292
 ** A2, 1.2
 ** Due: 02/13/17
 
 *******************************************************/

#include <stdio.h>
#include <stdlib.h>

long int inversion_merge(int A[], int first, int last);


long int inversion_merge(int A[], int first, int last)
{
    int mid = (first+last)/2;
    int i = first;
    int j = mid+1;
    int temp[last-first+1];
    int count = 0;
    int k = 0;
    
    while (i <= mid && j <= last)
    {
        if (A[i] <= A[j])
        {
            temp[k++] = A[i++];
        }
        else
        {
            temp[k++] = A[j++];
            count += mid - i + 1;
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
    
    return count;
}

long int count_inversion(int A[], int right, int left)
{
    long int count = 0;
    int mid = 0;
    
    if (right >= left)
    {
        return 0;
    }
    
    mid = (right + left)/2;
    
    count = count_inversion(A, right, mid);
    count += count_inversion(A, mid+1, left);
    count += inversion_merge(A, right, left);
    
    return count;
}
