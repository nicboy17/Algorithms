/*******************************************************
 
 ** Created by Nick Major 0879292
 ** A2, 2.1
 ** Due: 02/13/17
 
 *******************************************************/

#include <stdio.h>
#include <stdbool.h>
#include <time.h>

struct Set
{
    double x;
    double y;
};


void BruteHull(struct Set S[], int size)
{
    clock_t begin = clock();
    double a = 0;
    double b = 0;
    double c = 0;
    struct Set Convex[30000];
    int inc = 0;
    bool left;
    bool right;
    
    for( int i = 0; i < size; i ++ )
    {
        for( int j = 0; j < size; j ++)
        {
            a = S[j].y - S[i].y;
            b = S[i].x - S[j].x;
            c = (S[i].x*S[j].y) - (S[i].y*S[j].x);
            left = true;
            right = true;
            
            if(i != j)
            {
                for( int k = 0; k < size; k ++ )
                {
                    if ((k != i) && (k != j))
                    {
                        double p = a*S[k].x + b*S[k].y - c;
                        if( p < 0 )
                        {
                            left = false;
                        }
                        else
                        {
                            right = false;
                        }
                    }
                }
                if(right == true || left == true)
                {
                    Convex[inc] = S[i];
                    Convex[inc+1] = S[j];
                    inc = inc +2;
                }
            }

        }
    }
    
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Ex time: %4f seconds\n\n", time_spent);
    
    /*int i =0;
    int j =0;
    for(i = 0; i < inc; i++)
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
    }
    printf("\n");*/
}
