#include "string.h"
#include "stdio.h"
#include "stdlib.h"
#include "assert.h"
#include "ClassicalMinimizer.h"

void Classic_Minimizer(char* Ans, int Mlength, int K, char* kmer)
{
    for(int i = 0; i < Mlength; i++)
        Ans[i] = 'Z';

    //printf("K - Mlenght + 1: %d\n\n", K - Mlength + 1);
    for(int i = 0; i < K - Mlength + 1; i++) 
    {
        if(strncmp(&kmer[i], Ans, Mlength) < 0)
        {
            strncpy(Ans, &kmer[i], Mlength);
        }
    }
}

int Classic_Minimizer_loc(int Mlength, int K, char* kmer)
{
    int loc = 0;

    char Ans[Mlength];
    for(int i = 0; i < Mlength; i++)
        Ans[i] = 'Z';

    //printf("K - Mlenght + 1: %d\n\n", K - Mlength + 1);
    for(int i = 0; i < K - Mlength + 1; i++) 
    {
        if(strncmp(&kmer[i], Ans, Mlength) < 0)
        {
            strncpy(Ans, &kmer[i], Mlength);
            loc = i;
        }
    }
    return loc;
}

// < 0 if str1 < str2  => str1 better than str2
int better_classic_mini(char* str1, char* str2, int M)
{
    return strncmp(str1, str2, M);
}