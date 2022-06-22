#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "assert.h"
#include <stdbool.h>

#include "../Common/hash_interface.h"
#include "../Common/KmerReader_FASTA.h"

//number of bucktes == number of thread
void Distribute(char* kmer, int K, int* Hash_Table, int t);
int* Init_hashTable(int t);
void PrintHashTable(int* hash_tabe, int t);

int main(int argc, char* argv[])
{
    assert(argc == 3);
    int K = atoi(argv[2]);
    FILE* file = fopen(argv[1], "r");

    int t = 5;
    int *hash_table = Init_hashTable(t);


    int N = 1000, loc = 0;
    bool init = false;
    char store[N];
    char *kmer;

    kmer = get_next_kmer(file, K, store, N, &loc, &init);
    while (kmer != NULL)
    {
        Distribute(kmer, K, hash_table, t);
        kmer = get_next_kmer(file, K, store, N, &loc, &init);
    }
    
    PrintHashTable(hash_table, t);
    free(hash_table);
}



//Taking t to be prime number gives much better performance
//Initalize Hash_Table all values to be 0
void Distribute(char* kmer, int K, int* Hash_Table, int t)
{
    unsigned int hashvalue = string_hash_geek(kmer, K);
    int bucket_no = hashvalue % t;
    Hash_Table[bucket_no]++;
}

int* Init_hashTable(int t)
{
    int *HashTable = (int*)malloc(sizeof(int) * t);
    for(int i = 0; i < t; i++)
        HashTable[i] = 0;
    return HashTable;
}

void PrintHashTable(int* hash_tabe, int t)
{
    printf("\n");
    for(int i = 0; i < t; i++)
        printf("%d ", hash_tabe[i]);
    printf("\n");
}