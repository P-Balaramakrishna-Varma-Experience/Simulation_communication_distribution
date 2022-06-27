#ifndef __HASH_TABLE_DIST_H__
#define __HASH_TABLE_DIST_H__

#define _M_value 4

//test file sum adds to 17 (17 supermers)
//number of bucktes == number of thread
//kmer and K in Distribute refers to supermer and its lenght


void Distribute(char* kmer, int K, int* Hash_Table, int t, unsigned int (*hash_function)(const char* kmer, const int n), int N);

//Allocate memory for an int array of len t (each value equals to 0) and return array
int* Init_hashTable(int t);

//The function outputs the results/ what to be collected as data.
void PrintHashTable(int* hash_tabe, int t, char* HashName, int K);

//Returns variance/standard devition of the given int array of size N
double VarinaceHashTable(int *Input, int N);


#endif