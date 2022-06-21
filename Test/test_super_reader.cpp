#include <string.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "../src/Common/Read_FASTA.h"
#include "../src/Common/ClassicalMinimizer.h"
#include "../src/Common/supermer_reader.h"



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