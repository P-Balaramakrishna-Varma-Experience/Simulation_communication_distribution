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


char* get_next_kmer(FILE* file, int K)
{
    static int Now_loc = 0;
    static bool Initalize = false;
    static char Storage[10000];                 //small enough to fit in L3 cache

    char ch;
    char* kmer = Storage;
    if(Initalize == false) 
    {
        for(int i = 0; i < K -1; i++)
            Storage[i] = get_next_char(file);
        Initalize = true;
    }


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