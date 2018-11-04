/*******************************************************

** Created by Nick Major 0879292
** A3, 2.2
** Due: 03/13/17

*******************************************************/

#include <stdio.h>
#include <math.h>
#include <time.h>

struct Set
{
    double x;
    double y;
};

void FindHull( struct Set S[], struct Set A, struct Set B, int size, struct Set *Convex, int *index );


void QuickHull( struct Set S[], int size )
{
    struct Set min;
    struct Set max;
    clock_t begin = clock();
    struct Set S1[30000];
    struct Set S2[30000];
    struct Set Convex[30000];
    int index = 0;
    int index1 = 0;
    int index2 = 0;
    
    min = S[0];
    max = S[0];
    for( int i = 0; i < size; i ++ )
    {
        if(S[i].x < min.x)
        {
            min = S[i];
        }
        
        if(S[i].x > max.x)
        {
            max = S[i];
        }
    }
    Convex[index] = min;
    index ++;
    Convex[index] = max;
    index ++;
    
    for( int i = 0; i < size; i ++ )
    {
        int p = (max.x - min.x) * (S[i].y - min.y) - (max.y - min.y) * (S[i].x - min.x);
        
        if(p < 0)
        {
            S1[index1] = S[i];
            index1 ++;
        }
        else if( p > 0 )
        {
            S2[index2] = S[i];
            index2 ++;
        }
    }
    
    FindHull( S1, min, max, index1, Convex, &index );
    FindHull( S2, max, min, index2, Convex, &index );
    
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Ex time: %4f seconds\n\n", time_spent);
    
    /*int i =0;
    int j =0;
    for(i = 0; i < index; i++)
    {
        for (j=0; j<i; j++)
        {
            if (Convex[i].x == Convex[j].x && Convex[i].y == Convex[j].y)
            {
                break;
            }
        }
        
        if (i == j){
            printf("%f %f\n", Convex[i].x, Convex[i].y);
        }
    }*/
}

void FindHull( struct Set S[], struct Set A, struct Set B, int size, struct Set *Convex, int *index )
{
    int dist = 0;
    double distance = 0;
    int furthestPoint = 0;
    struct Set p;
    struct Set m;
    struct Set PM[30000];
    struct Set PB[30000];
    int indexM = 0;
    int indexB = 0;
    struct array;
    
    if( size < 2 )
    {
        return;
    }
    
    for (int i = 0; i < size; i++)
    {
        distance = fabs((B.x - A.x) * (A.y - S[i].y) - ( B.y - A.y) * (A.x - S[i].x));
        if (distance > dist)
        {
            dist = distance;
            furthestPoint = i;
        }
    }
    p = S[furthestPoint];
    Convex[*index] = p;
    *index = *index + 1;
    
    for (int i = 0; i < size; i++)
    {
        m = S[i];
        distance = (p.x - A.x) * (m.y - A.y) - (p.y - A.y) * (m.x - A.x);
        if (distance > 0)
        {
            PM[indexM] = m;
            indexM ++;
        }
    }
    
    for (int i = 0; i < size; i++)
    {
        m = S[i];
        distance = (B.x - p.x) * (m.y - p.y) - ( B.y - p.y) * (m.x - p.x);
        if (distance > 0)
        {
            PB[indexB] = m;
            indexB ++;
        }
    }
    
    FindHull(PM, A, p, indexM, Convex, index);
    FindHull(PB, p, B, indexB, Convex, index);
}
