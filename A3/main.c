/*******************************************************
 
 ** Created by Nick Major 0879292
 ** A3, main
 ** Due: 03/13/17
 
 *******************************************************/
#include <string.h>
#include <stdio.h>
#include <stdlib.h>


typedef struct {
    char A[24000][12];
}arrA;

arrA readArray();
int readArray2(char **B);
char *convert(char line[]);
extern void anagramDetect(arrA A, char anagram[12]);
extern void quickAnagram(arrA A, char anagram[12]);
extern void bruteSearch(char **B, char pattern[100], int size);
extern void HorspoolSearch(char **B, char pattern[100], int size);
extern void BoyerMooreSearch(char **B, char pattern[100], int size);


int main(int argc, const char * argv[])
{
    arrA A;
    char **B = malloc(44050 * sizeof(char *));
    int cmd = 1;
    char input[100];
    int size = 0;
    
    printf("Assignment #3\n\nCommands:\n\t1 - P11\n\t2 - P12\n\t3 - P21\n\t4 - P22\n\t5 - P23\n\t0 - exit\n");
    
    while( cmd > 0 && cmd < 6 )
    {
        scanf("%d", &cmd);
        
        switch( cmd )
        {
            case 0:
                
            break;
                // /Users/nick/Desktop/data_4.txt
                // 959997301
            case 1:
                A = readArray();
                printf("Enter anagram: ");
                scanf("%s", input);
                anagramDetect(A, input);
            break;
            
            case 2:
                A = readArray();
                printf("Enter anagram: ");
                scanf("%s", input);
                quickAnagram(A, input);
            break;
            
                // /Users/nick/Desktop/data_5.txt
                // information
            case 3:
                size = readArray2(B);
                printf("Enter pattern: ");
                scanf("%s", input);
                bruteSearch(B, input, size);
            break;
                
            case 4:
                size = readArray2(B);
                printf("Enter pattern: ");
                scanf("%s", input);
                HorspoolSearch(B, input, size);
            break;
                
            case 5:
                size = readArray2(B);
                printf("Enter pattern: ");
                scanf("%s", input);
                BoyerMooreSearch(B, input, size);
            break;
                
            default:
                printf("Sorry, your input is not recognized");
            break;
        }
    }
    
    free(B);
    return 0;
}

arrA readArray()
{
    char fileName[30] = "";
    FILE* file = NULL;
    char line[100] = "";
    static arrA A;
    int temp[5];
    int k = 0;
    
    printf("Enter file name: ");
    scanf("%s", fileName);
    
    while(!(file = fopen(fileName, "r")))
    {
        printf("Enter file name: ");
        scanf("%s", fileName);
    }
    
    while (fgets(line, sizeof(line), file))
    {
        sscanf(line, "%d %d %d %d %d", &temp[0], &temp[1], &temp[2], &temp[3], &temp[4]);

        sprintf(A.A[k], "%d", temp[0]);
        sprintf(A.A[k++], "%d", temp[1]);
        sprintf(A.A[k++], "%d", temp[2]);
        sprintf(A.A[k++], "%d", temp[3]);
        sprintf(A.A[k++], "%d", temp[4]);
    }
    fclose(file);
    
    return A;
}

int readArray2(char **B)
{
    char fileName[30] = "";
    FILE* file = NULL;
    char line[150] = "";
    char temp[150];
    int size = 0;
    
    printf("Enter file name: ");
    scanf("%s", fileName);
    
    while(!(file = fopen(fileName, "r")))
    {
        printf("Enter file name: ");
        scanf("%s", fileName);
    }
    
    while (fgets(line, sizeof(line), file))
    {
        strcpy(temp, convert(line));
        B[size] = (char *)malloc(strlen(temp)+1);
        sprintf(B[size], "%s", temp);
        size ++;
    }
    
    fclose(file);
    return size;
}

char *convert(char line[])
{
    int i =0;
    int j = 0;
    
    for(i = 0; line[i] != '\0'; i ++)
    {
        while (!( (line[i] >= 'a' && line[i] <= 'z') || (line[i] >= 'A' && line[i] <= 'Z') || line[i] == ' ' || line[i] == '\0') )
        {
            for(j = i; line[j] != '\0'; j ++)
            {
                line[j] = line[j+1];
            }
            line[j] = '\0';
        }
    }
    
    return line;
}
