// C program to implement
// the above approach
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "assert.h"
#include<stdbool.h>

#include "../../src/Common/KmerReader_FASTA.h"
#include "../../src/Common/supermer_reader.h"
// Driver code

void PrintArray(char *A, int L)
{
    for(int i = 0; i < L; i++)
        printf("%c", A[i]);
    printf("\n");
}

int main(int argc, char* argv[])
{
    //Taking input
    assert(argc == 4);
    int X = atoi(argv[3]);
    int K = atoi(argv[2]);
    
    FILE *ptr;
    ptr = fopen(argv[1], "r");
    assert(ptr != NULL);

    int M = K/X + 1, sN = 10000, len;
    char Min[M], store[sN];
    unsigned long int cost = 0;

    len = get_next_supermer(ptr, K, M, Min, store, sN);
    while (len > 0)
    {
        cost += len;
        //PrintArray(store, len);
        len = get_next_supermer(ptr, K, M, Min, store, sN);
    }

    fclose(ptr);

    printf("%d,%lu\n", K, cost);
    return 0;
}