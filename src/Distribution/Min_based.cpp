#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "assert.h"
#include <stdbool.h>

#include "../Common/hash_interface.h"
#include "../Common/supermer_reader.h"

#define _M_value 4

//test file sum adds to 17 (17 supermers)
//number of bucktes == number of thread
//kmer and K in Distribute refers to supermer and its lenght
void Distribute(char* kmer, int K, int* Hash_Table, int t, unsigned int (*hash_function)(const char* kmer, const int n));
int* Init_hashTable(int t);
void PrintHashTable(int* hash_tabe, int t, char* HashName, int K);
double VarinaceHashTable(int *Input, int N);

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

    int sN = 10000, M = _M_value, len = 0;
    char supermer[sN], Min[M];

    len = get_next_supermer(file, K, M, Min, supermer, sN);
    while (len > 0)
    {
        for(int i = 0; i < No_of_t; i++)
        {
            Distribute(Min, M, Hash_Tables_geek[i], TValues[i], string_hash_geek);
            Distribute(Min, M, Hash_Tables_mur[i], TValues[i], string_hash_murmur3);
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

void PrintHashTable(int* hash_tabe, int t, char* HashName, int K)
{
    printf("%d,%d,%s,%lf\n", K, t, HashName, VarinaceHashTable(hash_tabe, t));
    /*printf("Name: %s, T: %d :  ", HashName, t);
    for(int i = 0; i < t; i++)
        printf("%d ", hash_tabe[i]);
    printf("\n");*/
}


//Generated via copilot recheck
//caliculate variance for the given numbers in the array
double VarinaceHashTable(int *Input, int N)
{
    double mean = 0;
    for(int i = 0; i < N; i++)
        mean += Input[i];
    mean /= N;

    double variance = 0;
    for(int i = 0; i < N; i++)
        variance += (Input[i] - mean) * (Input[i] - mean);
    variance /= N;

    return variance;
}