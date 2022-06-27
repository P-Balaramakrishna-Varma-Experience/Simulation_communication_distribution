#ifndef Class_min
#define Class_min

#include "stdbool.h"

//kmer, K input kmers is passed (make sure valid)
//Ans, M is passed to store output
void Classic_Minimizer(char* Ans, int Mlength, int K, char* kmer);

//kmer, K input kmers is passed (make sure valid)
//returns the index of start of the minimizer
int Classic_Minimizer_loc(int Mlenght, int K, char* kmer);

// < 0 if str1 < str2  => str1 better than str2
int better_classic_mini(char* str1, char* str2, int M);

#endif
