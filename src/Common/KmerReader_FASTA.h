#ifndef kmerReader_H
#define kmerReader_H

#include <stdio.h>

char* get_next_kmer(FILE* file, int K, char* Storage, int N, int* loc, bool* Initialize);
void print_kmer(char* kmer, int K);

#endif