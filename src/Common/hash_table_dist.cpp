#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "assert.h"
#include <stdbool.h>
#include <math.h>

#include "hash_table_dist.h"

//Taking t to be prime number gives much better performance
//Initalize Hash_Table all values to be 0
void Distribute(char* kmer, int K, int* Hash_Table, int t, unsigned int (*hash_function)(const char* kmer, const int n), int N)
{
    unsigned int hashvalue = hash_function(kmer, K);
    int bucket_no = hashvalue % t;
    Hash_Table[bucket_no] += N;
}

int* Init_hashTable(int t)
{
    int *HashTable = (int*)malloc(sizeof(int) * t);
    assert(HashTable != NULL);
    for(int i = 0; i < t; i++)
        HashTable[i] = 0;
    return HashTable;
}

void PrintHashTable(int* hash_tabe, int t, char* HashName, int K)
{
    //printf("%d,%d,%s,%lf\n", K, t, HashName, VarinaceHashTable(hash_tabe, t));
    printf("{\n");
    printf("\t\"Name\": \"%s\"\,\n", HashName);
    printf("\t\"K\": %d\,\n", K);
    printf("\t\"T\": %d\,\n", t);
    printf("\t\"Data\": [");
    for(int i = 0; i < t; i++)
    {
        if(i != t - 1)
            printf("%d, ", hash_tabe[i]);
        else
            printf("%d", hash_tabe[i]);

    }
    printf("]\n");
    printf("},\n");
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

    //return square root of variance
    return sqrt(variance);
}