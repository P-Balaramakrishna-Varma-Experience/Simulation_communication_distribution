#ifndef __HASH_TABLE_DIST_H__
#define __HASH_TABLE_DIST_H__

#define _M_value 4

//test file sum adds to 17 (17 supermers)
//number of bucktes == number of thread
//kmer and K in Distribute refers to supermer and its lenght
void Distribute(char* kmer, int K, int* Hash_Table, int t, unsigned int (*hash_function)(const char* kmer, const int n), int N);
int* Init_hashTable(int t);
void PrintHashTable(int* hash_tabe, int t, char* HashName, int K);
double VarinaceHashTable(int *Input, int N);


#endif