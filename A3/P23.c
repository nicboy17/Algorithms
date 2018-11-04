/*******************************************************
 
 ** Created by Nick Major 0879292
 ** A3, 2.3
 ** Due: 03/13/17
 
 *******************************************************/

#include <stdio.h>
#include <math.h>
#include <time.h>
#include <string.h>


int BMsearch(char *B, char *pattern, int *table, int *count, int *shifts);
int *GoodTable(char *pattern, int m);
int *BadTable(char *pattern, int m);
int *suffix(char *pattern, int m);
void BoyerMoore(char *B, int n, char *pattern, int m, int *count, int *shifts);
int max(int a, int b);

void BoyerMooreSearch(char **B, char pattern[100], int size)
{
    int count = 0;
    int shifts = 0;
    int m =  (int)strlen(pattern);
    clock_t begin;
    clock_t end;
    double time_spent;
    
    begin = clock();
    
    for(int k = 0; k < size; k ++)
    {
        int n =  (int)strlen(B[k]);
        BoyerMoore(B[k], n, pattern, m, &count, &shifts);
    }
    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    
    printf("\n**Problem 2.3 Summary**\n");
    printf("Ex time: %4f seconds\n", time_spent);
    printf("pattern shifts: %d\n", shifts);
    printf("Occurences Found: %d\n", count);
}

void BoyerMoore(char *B, int n, char *pattern, int m, int *count, int *shifts)
{
    int i = 0;
    int j = 0;
    int *good;
    int *bad;
    
    good = BadTable(pattern, m);
    bad = GoodTable(pattern, m);
    
    while(i <= n-m)
    {
        j = m-1;
        while((j >= 0) && (pattern[j] == B[i+j]))
        {
            j --;
        }
        if(j < 0)
        {
            *count = *count +1;
            i += good[0];
            *shifts = *shifts +1;
        }
        else
        {
            i += max(good[j], bad[B[i + j]] - m + 1 + j);
            *shifts = *shifts +1;
        }
    }
}

int *BadTable(char *pattern, int m)
{
    int i = 0;
    int static bad[150];
    
    for (i = 0; i < 150; i ++)
    {
        bad[i] = m;
    }
    for (i = 0; i < m - 1; ++i)
    {
        bad[pattern[i]] = m - i - 1;
    }
    return bad;
}

int *suffix(char *pattern, int m)
{
    int f = 0;
    int g = 0;
    int i = 0;
    int static suff[150];
    
    suff[m - 1] = m;
    g = m - 1;
    for (i = m - 2; i >= 0; i--)
    {
        if (i > g && suff[i + m - 1 - f] < i - g)
        {
            suff[i] = suff[i + m - 1 - f];
        }
        else
        {
            if (i < g)
            {
                g = i;
            }
            f = i;
            while (g >= 0 && pattern[g] == pattern[g + m - 1 - f])
            {
                g --;
            }
            suff[i] = f - g;
        }
    }
    
    return suff;
}

int *GoodTable(char *pattern, int m)
{
    int i = 0;
    int j = 0;
    int *suff;
    int static good[150];
    
    suff = suffix(pattern, m);
    
    for (i = 0; i < m; ++i)
    {
        good[i] = m;
    }
    
    j = 0;
    for (i = m - 1; i >= 0; --i)
    {
        if (suff[i] == i + 1)
        {
            for (j = 0; j < m - 1 - i; j ++)
            {
                if (good[j] == m)
                {
                    good[j] = m - 1 - i;
                }
            }
        }
    }
    for (i = 0; i <= m - 2; ++i)
    {
        good[m - 1 - suff[i]] = m - 1 - i;
    }
    
    return good;
}

int max(int a, int b)
{
    if(a >= b)
    {
        return a;
    }
    else
    {
        return b;
    }
}
