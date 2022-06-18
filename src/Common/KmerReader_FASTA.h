#ifndef kmerReader_H
#define kmerReader_H

#include <stdio.h>

char* get_next_kmer(FILE* file, int K);
void print_kmer(char* kmer, int K);

#endif