#include <string.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "../src/Common/Read_FASTA.h"
#include "../src/Common/ClassicalMinimizer.h"

int get_next_supermer(FILE* file, int K, int M, char *Min, char* Storage, int sN)
{
    static char Tem[1000];
    static int tN = 1000;
    static bool intialized = false, reached_eof = false;
    char TempMin[M];

    if(reached_eof == true)
        return -1;

    int loc = 0;
    if(intialized == false)
    {
        for(int i = 0; i < K; i++)
            Storage[i] = get_next_char(file);
        intialized = true;
    }
    else
    {
        for(int i = 0; i < K; i++)
            Storage[i] = Tem[i];
    }
    loc+= K;

    Classic_Minimizer(Min, M, K, Storage);
    int start_loc_min = Classic_Minimizer_loc(M, K, Storage);

    char ch;
    while(loc < sN)
    {
        ch = get_next_char(file); 
        if(ch == EOF)
        {
            reached_eof = true;
            return loc;
        }
        Storage[loc] = ch;
        
        if(start_loc_min >= loc - K + 1)
        {
            if(better_classic_mini(&Storage[loc - M + 1], Min, M) < 0)
            {
                strncpy(Tem, &Storage[loc - K + 1], K);
                return loc;
            }
            else
            {
                Storage[loc] = ch;
                loc++;
            }
        }
        else
        {
            start_loc_min = Classic_Minimizer_loc(M, K, &Storage[loc - K + 1]);
            Classic_Minimizer(TempMin, M, K, &Storage[loc - K + 1]);
            if(strncmp(TempMin, Min, M) != 0)
            {
                strncpy(Tem, &Storage[loc - K + 1], K);
                return loc;
            }
            else
            {
                Storage[loc] = ch;
                loc++;
            }
        }
    }


    strncpy(Tem, &Storage[loc - K + 1], K - 1);
    Tem[K] = get_next_char(file);
    return loc;

}


void printCharArray(char *A, int N)
{
    for(int i = 0; i < N; i++)
    {
        printf("%c", A[i]);
    }
}

int main(int argc, char* argv[])
{
    assert(argc == 4);
    int M = atoi(argv[3]);
    int K = atoi(argv[2]);
    FILE *ptr = fopen(argv[1], "r");
    assert(ptr != NULL);

    int N = 1000, len;
    char store[N], Mini[M];




    len = get_next_supermer(ptr, K, M, Mini, store, N);
    while(len > 0)
    {
       // printState(Store, N, loc);
        printCharArray(store, len);
        printf("\n");
        len = get_next_supermer(ptr, K, M, Mini, store, N);
    }

    fclose(ptr);
    return 0;
}