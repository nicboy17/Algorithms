/*******************************************************
 
 ** Created by Nick Major 0879292
 ** A2, 1.1
 ** Due: 02/13/17
 
 *******************************************************/

#include <stdio.h>


long int inversion(int A[], int size)
{
    long int count = 0;

    for( int i = 0; i < size-1; i ++ )
    {
        for( int j = i+1; j < size; j ++)
        {
            if( A[i] > A[j] )
            {
                count ++;
            }
        }
    }

    return count;
}
