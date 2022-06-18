#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "../../src/Common/Read_FASTA.h"
#include "../../src/Common/kmerReader_FASTA.h"

void print_kmer(const char* kmer, int K)
{
    if(kmer != NULL)
    {
        for(int i = 0; i < K; i++)
            printf("%c", kmer[i]);
        printf("\n");
    }
}


const char* get_next_kmer(FILE* file, int K)
{
    static int Now_loc = 0;
    static char Storage[10000];                 //small enough to fit in L3 cache
    for(int i = 0; i < K -1; i++)
        Storage[i] = get_next_char(file);
        
    char ch;
    char* kmer = Storage;


    //Now lock is possible/starting index for the kmer generated in this iteration.
    if(Now_loc + K >= 10000 - K)
    {
        for(int i = 0; i < K; i++)            
            Storage[i] = Storage[Now_loc + i];
        Now_loc = 0;
        //printf(":log:");
    }

    Storage[Now_loc + K - 1] = get_next_char(file);  //Get next char store in k'th postion.
    if(Storage[Now_loc + K - 1] == EOF)
        return NULL;
    else
    {
        kmer = &Storage[Now_loc];
        Now_loc++;                                      //now lock set for next iteration.
    }

    return kmer;
}