#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "assert.h"
#include <stdbool.h>

#include "../Common/hash_interface.h"
#include "../Common/supermer_reader.h"
#include "../Common/hash_table_dist.h"

#define _M_value 4

int main(int argc, char* argv[])
{
    assert(argc == 3);
    int K = atoi(argv[2]);
    FILE* file = fopen(argv[1], "r");

    int No_of_t = 12;
    int TValues[] = {4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192};

    int *Hash_Tables_geek[No_of_t], *Hash_Tables_mur[No_of_t];
    for(int i = 0; i < No_of_t; i++)
    {
        Hash_Tables_geek[i] = Init_hashTable(TValues[i]);
        Hash_Tables_mur[i] = Init_hashTable(TValues[i]);
    }

    int sN = 10000, M = _M_value, len = 0;
    char supermer[sN], Min[M];

    len = get_next_supermer(file, K, M, Min, supermer, sN);
    while (len > 0)
    {
        for(int i = 0; i < No_of_t; i++)
        {
            Distribute(Min, M, Hash_Tables_geek[i], TValues[i], string_hash_geek, len - K + 1);
            Distribute(Min, M, Hash_Tables_mur[i], TValues[i], string_hash_murmur3, len - K + 1);
        }

        len = get_next_supermer(file, K, M, Min, supermer, sN);
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