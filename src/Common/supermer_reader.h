#ifndef supermer_reader_h
#define supermer_reader_h

#include "stdio.h"

// Storage is char array of len sN
// Min is char array of len M
// K is according to the input
// return lenght of the supermer which starts at storage
// return -1 means file reading done do no more.
//use only once function since uses static variables initalization.
int get_next_supermer(FILE* file, int K, int M, char *Min, char* Storage, int sN);

#endif