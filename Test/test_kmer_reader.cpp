#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "../src/Common/Read_FASTA.h"
#include "../src/Common/KmerReader_FASTA.h"
#include "gtest/gtest.h"

void printState(char *Store, int N, int loc)
{
    printf("loc: %d\n", loc);
    for(int i = 0; i < N; i++)
        printf("%c", Store[i]);
    printf("\n");
}

//copy kmers into an array
//index initialized to 0
//Out sould large
int copykmers(char *Out, int K, int* index, char* kmer)
{
    if(kmer == NULL)
        return *index;

    for(int i = 0; i < K; i++)
    {
        Out[*index] = kmer[i];
        (*index)++;
    }

    return -1;    
}

//get kmers in a string
int getkmers(char* filename, int K, char* Out, int N)
{
    FILE* fp = fopen(filename, "r");
    assert(fp != NULL);

    char *kmer;

    int  loc = 0, index = 0;
    bool init = false;
    char Store[N];


    //initialize store array with all 'z'
    for(int i = 0; i < N; i++)
        Store[i] = 'z';


    kmer = get_next_kmer(fp, K, Store, N, &loc, &init);
    while(kmer != NULL)
    {
       // printState(Store, N, loc);
        copykmers(Out, K, &index, kmer);
        kmer = get_next_kmer(fp, K, Store, N, &loc, &init);
    }

    //closing file
    fclose(fp);
    return index;
}


TEST(KmerReader, FileA)
{
    int len;
    char Out[10000];

    len = getkmers("Test/Tests_kmer_reader/test1.fasta", 2, Out, 10000);
    ASSERT_TRUE(strncmp(Out, "AAAAAAAA", len) == 0);

    len = getkmers("Test/Tests_kmer_reader/test1.fasta", 3, Out, 10000);
    ASSERT_TRUE(strncmp(Out, "AAAAAAAAA", len) == 0);

    len = getkmers("Test/Tests_kmer_reader/test1.fasta", 4, Out, 10000);
    ASSERT_TRUE(strncmp(Out, "AAAAAAAA", len) == 0);

    len = getkmers("Test/Tests_kmer_reader/test1.fasta", 5, Out, 10000);
    ASSERT_TRUE(strncmp(Out, "AAAAA", len) == 0);
}

TEST(KmerReader, FileB)
{
    int len;
    char Out[10000];

    len = getkmers("Test/Tests_kmer_reader/test2.fasta", 2, Out, 10000);
    ASSERT_TRUE(strncmp(Out, "ATTGGCCAATTGGCCAATTGGCCAATTGGC", len) == 0);

    len = getkmers("Test/Tests_kmer_reader/test2.fasta", 3, Out, 10000);
    ASSERT_TRUE(strncmp(Out, "ATGTGCGCACATATGTGCGCACATATGTGCGCACATATGTGC", len) == 0);

    len = getkmers("Test/Tests_kmer_reader/test2.fasta", 4, Out, 10000);
    ASSERT_TRUE(strncmp(Out, "ATGCTGCAGCATCATGATGCTGCAGCATCATGATGCTGCAGCATCATGATGC", len) == 0);

    len = getkmers("Test/Tests_kmer_reader/test2.fasta", 5, Out, 10000);
    ASSERT_TRUE(strncmp(Out, "ATGCATGCATGCATGCATGCATGCATGCATGCATGCATGCATGCATGCATGCATGCATGC", len) == 0);
}

TEST(kmerReader, FileC)
{
    int len;
    char Out[10000];

    len = getkmers("Test/Tests_kmer_reader/test3.fasta", 4, Out, 10);
    ASSERT_TRUE(strncmp(Out, "ATGCTGCAGCATCATGATGCTGCAGCATCATGATGCTGCAGCATCATGATGC", len) == 0);
}

/*
int main(int argc, char* argv[])
{
   assert(argc == 3);
   int K = atoi(argv[2]);
   char Out[10000];

   int len = getkmers(argv[1], K, Out, 10);
   print_kmer(Out, len);
   return 0;
}
*/
