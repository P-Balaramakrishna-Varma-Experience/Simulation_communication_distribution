#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "Read_FASTA.h"
#include "KmerReader_FASTA.h"

void print_kmer(char* kmer, int K)
{
    if(kmer != NULL)
    {
        for(int i = 0; i < K; i++)
            printf("%c", kmer[i]);
        printf("\n");
    }
}


char* get_next_kmer(FILE* file, int K, char* Storage, int N, int* loc, bool* Initialize)
{

    char ch;
    char* kmer = Storage;
    if(*Initialize == false) 
    {
        for(int i = 0; i < K -1; i++)
            Storage[i] = get_next_char(file);
        *loc = 0;
        *Initialize = true;
    }


    //Now lock is possible/starting index for the kmer generated in this iteration.
    if(*loc + K >= N - K)
    {
        for(int i = 0; i < K - 1; i++)            
            Storage[i] = Storage[*loc + i];
        *loc = 0;
    }

    Storage[*loc + K - 1] = get_next_char(file);  //Get next char store in k'th postion.
    if(Storage[*loc + K - 1] != EOF)
    {
        kmer = &Storage[*loc];
        *loc = *loc + 1;                                      //now lock set for next iteration.
        return kmer;
    }
    else
    {
        return NULL;
    }

}