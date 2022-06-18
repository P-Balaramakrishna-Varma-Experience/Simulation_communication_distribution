#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "../../src/Common/Read_FASTA.h"

void print_kmer(char *kmer, int K)
{
    if(kmer != NULL)
    {
        for(int i = 0; i < K; i++)
            printf("%c", kmer[i]);
        printf("\n");
    }
}


int main(int argc, char* argv[])
{
    //Reading from command line arguments file and K value
    assert(argc == 3);
    int K = atoi(argv[2]);
    FILE *ptr = fopen(argv[1], "r");
    assert(ptr != NULL);



    int N = 10;
    char Storage[N];
    for(int i = 0; i < K -1; i++)
        Storage[i] = get_next_char(ptr);
    int Now_loc = 0;
        
    char ch;
    char* kmer = Storage;


    while(kmer != NULL)
    {
        //Now lock is possible/starting index for the kmer generated in this iteration.
        if(Now_loc + K >= N - K)
        {
            for(int i = 0; i < K; i++)            
                Storage[i] = Storage[Now_loc + i];
            Now_loc = 0;
            //printf(":log:");
        }

        Storage[Now_loc + K - 1] = get_next_char(ptr);  //Get next char store in k'th postion.
        if(Storage[Now_loc + K - 1] == EOF)
            break;
        kmer = &Storage[Now_loc];
        Now_loc++;                                      //now lock set for next iteration.

        print_kmer(kmer, K);
    }



    //closing file
    fclose(ptr);
    return 0;
}