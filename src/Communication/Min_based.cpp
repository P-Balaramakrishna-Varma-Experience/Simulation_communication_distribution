// C program to implement
// the above approach
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "assert.h"
#include<stdbool.h>

#include "../../src/Common/KmerReader_FASTA.h"
#include "../../src/Common/ClassicalMinimizer.h"
// Driver code

void PrintArray(char *A, int L)
{
    for(int i = 0; i < L; i++)
        printf("%c", A[i]);
}

int main(int argc, char* argv[])
{
    //Taking input
    assert(argc == 3);
    int K = atoi(argv[2]);
    
    FILE *ptr;
    ptr = fopen(argv[1], "r");
    assert(ptr != NULL);


    unsigned long int cost = 0;
    int M = 3, N = 1000, loc;
    char Prev[M], New[M], *Kmer_read, Storage[N];
    for(int i = 0; i < N; i++)
       Storage[i] = 'Z';
    bool init = false;
    
    Kmer_read = get_next_kmer(ptr, K, Storage, N, &loc, &init);
    assert(Kmer_read != NULL);
    Classic_Minimizer(Prev, M, K, Kmer_read);
    cost = K - 1;

    while (Kmer_read != NULL)
    {
        Classic_Minimizer(New, M, K, Kmer_read);

        /*printf("Prev: ");
        PrintArray(Prev, 3);
        printf("\n");
        printf("new: ");
        PrintArray(New, 3);
        printf("\n");
        printf("kmer: ");
        PrintArray(Kmer_read, K);
        printf("\n");
        printf("\n");
        printf("\n");*/

        if(strncmp(New, Prev, M) == 0)
            cost += 1;
        else
            cost += K;

        strncpy(Prev, New, M);
        Kmer_read = get_next_kmer(ptr, K, Storage, N, &loc, &init);
    }

    fclose(ptr);

    printf("K: %d  cost: %lu\n", K, cost);
    return 0;
}