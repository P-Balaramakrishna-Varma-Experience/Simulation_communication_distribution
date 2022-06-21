#include <string.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "../src/Common/Read_FASTA.h"
#include "../src/Common/ClassicalMinimizer.h"
#include "../src/Common/supermer_reader.h"

#include "gtest/gtest.h"


void printCharArray(char *A, int N)
{
    for(int i = 0; i < N; i++)
    {
        printf("%c", A[i]);
    }
}

int copysupermers(char *Out, int len, int* index, char* supermer)
{
    if(supermer == NULL)
        return *index;

    for(int i = 0; i < len; i++)
    {
        Out[*index] = supermer[i];
        (*index)++;
    }

    return -1;    
}

int getsupermers(char* filename, int K, char* Out, int N, int M)
{
    FILE *ptr = fopen(filename, "r");
    assert(ptr != NULL);

    int len, index = 0;
    char store[N], Mini[M];

    len = get_next_supermer(ptr, K, M, Mini, store, N);
    while(len > 0)
    {
        copysupermers(Out, len, &index, store);
        len = get_next_supermer(ptr, K, M, Mini, store, N);
    }

    fclose(ptr);
    return index;
}


TEST(SuperMerReading, testA)
{
    char Out[10000];
    int len = getsupermers("Test/test_minhash.fasta", 7, Out, 1000, 3);
    ASSERT_TRUE(strncmp(Out, "AATGACTATGACTGCAACTGCAAGCAAGAACAAGAAAT", len) == 0);
}

TEST(SuperMerReading, testB)
{
    char Out[10000];
    int len = getsupermers("Test/test_minhash.fasta", 7, Out, 10, 3 );
    ASSERT_TRUE(strncmp(Out, "AATGACTATGACTGCAACTGCAAGCAAAAGCAAGAACAAGAAAT", len) == 0);
}

/*
int main(int argc, char* argv[])
{
   assert(argc == 4);
   int K = atoi(argv[2]);
   int M = atoi(argv[3]);
   char Out[10000];

   int len = getsupermers(argv[1], K, Out, 10, M);
   printCharArray(Out, len);
   return 0;
}
*/