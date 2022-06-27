#ifndef kmerReader_H
#define kmerReader_H

#include <stdio.h>

//intialize and loc are variables used across invocation. 
//Default vaulues are false and 0
//Storage and N a char array of size N (buffer)

//K is the size of the kmer. It value must be constanst throught the a file
//Return null or a pointer to the kmer. wathch for null
//The output is read only do not modify it.
char* get_next_kmer(FILE* file, int K, char* Storage, int N, int* loc, bool* Initialize);


//Gives seg fault if kmer is invalid.
void print_kmer(char* kmer, int K);

#endif