#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "assert.h"
#include <stdbool.h>

#include "../Common/hash_interface.h"
#include "../Common/KmerReader_FASTA.h"
#include "../Common/hash_table_dist.h"

int main(int argc, char* argv[])
{
    assert(argc == 4);
    int X = atoi(argv[3]);
    int K = atoi(argv[2]);
    FILE* file = fopen(argv[1], "r");
    assert(file != NULL);

    int No_of_t = 12;
    int TValues[] = {4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192};

    int *Hash_Tables_geek[No_of_t], *Hash_Tables_mur[No_of_t];
    for(int i = 0; i < No_of_t; i++)
    {
        Hash_Tables_geek[i] = Init_hashTable(TValues[i]);
        Hash_Tables_mur[i] = Init_hashTable(TValues[i]);
    }


    int N = 10000, loc = 0;
    bool init = false;
    char store[N];
    char *kmer;

    int* old = Hash_Tables_mur[0];

    kmer = get_next_kmer(file, K, store, N, &loc, &init);
    while (kmer != NULL)
    {
        for(int i = 0; i < No_of_t; i++)
        {
            Distribute(kmer, K, Hash_Tables_geek[i], TValues[i], string_hash_geek, 1);
            Distribute(kmer, K, Hash_Tables_mur[i], TValues[i], string_hash_murmur3, 1);
        }

        kmer = get_next_kmer(file, K, store, N, &loc, &init);
    }

    for(int i = 0; i < No_of_t; i++)    
    {
        PrintHashTable(Hash_Tables_geek[i], TValues[i], "geeks", K);
        PrintHashTable(Hash_Tables_mur[i], TValues[i], "murmur3", K);
    }

    for(int i = 0; i < No_of_t; i++)
    {
        free(Hash_Tables_geek[i]);
        free(Hash_Tables_mur[i]);
    }
}