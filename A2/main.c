/*******************************************************
 
 ** Created by Nick Major 0879292
 ** A2, main
 ** Due: 02/13/17
 
 *******************************************************/
#include <string.h>
#include <stdio.h>
#include <time.h>

struct Set
{
    double x;
    double y;
};

int * readArray(int *size);
struct Set * readSet(int *size);
extern long int inversion(int A[], int size);
extern long int count_inversion(int A[], int right, int left);
extern void BruteHull(struct Set S[], int size);
extern void QuickHull( struct Set S[], int size );


int main(int argc, const char * argv[])
{
    int *A;
    struct Set *B;
    int cmd = 1;
    int size = 0;
    clock_t begin;
    clock_t end;
    double time_spent;
    
    printf("Assignment #2\n\nCommands:\n\t1 - P11\n\t2 - P12\n\t3 - P21\n\t4 - P22\n\t0 - exit\n");
    
    while( cmd > 0 && cmd < 5 )
    {
        scanf("%d", &cmd);
        
        switch( cmd )
        {
            case 1:
                begin = clock();
                A = readArray(&size);
                printf("Inversions: %ld\n", inversion(A, size));
                end = clock();
                time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
                printf("Ex time: %4f seconds\n\n", time_spent);
            break;
            
            case 2:
                 A = readArray(&size);
                 begin = clock();
                printf("Inversions: %ld\n", count_inversion(A, 0, size-1));
                end = clock();
                time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
                printf("Ex time: %4f seconds\n\n", time_spent);
            break;
            
            case 3:
                B = readSet(&size);
                BruteHull(B, size);
            break;
                
            case 4:
                B = readSet(&size);
                QuickHull(B, size);
            break;
        }
    }
    
    return 0;
}

int * readArray(int *size)
{
    char fileName[30] = "";
    FILE* file = NULL;
    char line[100] = "";
    static int A[50005];
    int i = 0;
    
    printf("Enter file name: ");
    scanf("%s", fileName);
    
    while(!(file = fopen(fileName, "r")))
    {
        printf("Enter file name: ");
        scanf("%s", fileName);
    }
    
    while (fgets(line, sizeof(line), file))
    {
        sscanf(line, "%d %d %d %d %d", &A[i], &A[i+1], &A[i+2], &A[i+3], &A[i+4]);
        i = i + 5;
    }
    printf("\n");
    fclose(file);
    *size = i;
    
    return A;
}

struct Set * readSet(int *size)
{
    char fileName[30] = "";
    FILE* file = NULL;
    char line[100] = "";
    static struct Set B[30005];
    int i = 0;
    
    printf("Enter file name: ");
    scanf("%s", fileName);
    
    while(!(file = fopen(fileName, "r")))
    {
        printf("Enter file name: ");
        scanf("%s", fileName);
    }
    
    while (fgets(line, sizeof(line), file))
    {
        sscanf(line, "%lf %lf", &B[i].x, &B[i].y);
        i ++;
    }
    printf("\n");
    fclose(file);
    *size = i;
    
    return B;
}
