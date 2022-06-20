#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "../src/Common/Read_FASTA.h"
#include "../src/Common/KmerReader_FASTA.h"

void printState(char *Store, int N, int loc)
{
    printf("loc: %d\n", loc);
    for(int i = 0; i < N; i++)
        printf("%c", Store[i]);
    printf("\n");
}

int main(int argc, char* argv[])
{
    //Reading from command line arguments file and K value
    assert(argc == 3);
    int K = atoi(argv[2]);
    FILE *ptr = fopen(argv[1], "r");
    assert(ptr != NULL);

    char *kmer;

    int N = 20, loc = 0;
    bool init = false;
    char Store[N];

    //initialize store array with all 'z'
    for(int i = 0; i < N; i++)
        Store[i] = 'z';


    kmer = get_next_kmer(ptr, K, Store, N, &loc, &init);
    while(kmer != NULL)
    {
       // printState(Store, N, loc);
        print_kmer(kmer, K);
        kmer = get_next_kmer(ptr, K, Store, N, &loc, &init);
    }

    //closing file
    fclose(ptr);
    return 0;
}