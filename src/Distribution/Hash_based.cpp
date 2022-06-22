#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "assert.h"
#include <stdbool.h>

#include "../Common/hash_interface.h"
#include "../Common/KmerReader_FASTA.h"

//number of bucktes == number of thread
void Distribute(char* kmer, int K, int* Hash_Table, int t, unsigned int (*hash_function)(const char* kmer, const int n));
int* Init_hashTable(int t);
void PrintHashTable(int* hash_tabe, int t, char* HashName);

int main(int argc, char* argv[])
{
    assert(argc == 3);
    int K = atoi(argv[2]);
    FILE* file = fopen(argv[1], "r");

    int No_of_t = 3;
    int TValues[] = {5, 10, 6};

    int *Hash_Tables_geek[No_of_t], *Hash_Tables_mur[No_of_t];
    for(int i = 0; i < No_of_t; i++)
    {
        Hash_Tables_geek[i] = Init_hashTable(TValues[i]);
        Hash_Tables_mur[i] = Init_hashTable(TValues[i]);
    }


    int N = 1000, loc = 0;
    bool init = false;
    char store[N];
    char *kmer;

    kmer = get_next_kmer(file, K, store, N, &loc, &init);
    while (kmer != NULL)
    {
        for(int i = 0; i < No_of_t; i++)
        {
            Distribute(kmer, K, Hash_Tables_geek[i], TValues[i], string_hash_geek);
            Distribute(kmer, K, Hash_Tables_mur[i], TValues[i], string_hash_murmur3);
        }

        kmer = get_next_kmer(file, K, store, N, &loc, &init);
    }

    for(int i = 0; i < No_of_t; i++)    
    {
        PrintHashTable(Hash_Tables_geek[i], TValues[i], "geeks");
        PrintHashTable(Hash_Tables_mur[i], TValues[i], "murmur3");
    }

    for(int i = 0; i < No_of_t; i++)
    {
        free(Hash_Tables_geek[i]);
        free(Hash_Tables_mur[i]);
    }
}



//Taking t to be prime number gives much better performance
//Initalize Hash_Table all values to be 0
void Distribute(char* kmer, int K, int* Hash_Table, int t, unsigned int (*hash_function)(const char* kmer, const int n))
{
    unsigned int hashvalue = hash_function(kmer, K);
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

void PrintHashTable(int* hash_tabe, int t, char* HashName)
{
    printf("Name: %s, T: %d :  ", HashName, t);
    for(int i = 0; i < t; i++)
        printf("%d ", hash_tabe[i]);
    printf("\n");
}