#ifndef kmerReader_H
#define kmerReader_H

#include <stdio.h>

const char* get_next_kmer(FILE* file, int K);
void print_kmer(const char* kmer, int K);

#endif