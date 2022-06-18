#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "../src/Common/Read_FASTA.h"
#include "../src/Common/KmerReader_FASTA.h"

int main(int argc, char* argv[])
{
    //Reading from command line arguments file and K value
    assert(argc == 3);
    int K = atoi(argv[2]);
    FILE *ptr = fopen(argv[1], "r");
    assert(ptr != NULL);

    char *kmer;
    kmer = get_next_kmer(ptr, K);
    while(kmer != NULL)
    {
        print_kmer(kmer, K);
        kmer = get_next_kmer(ptr, K);
    }

    //closing file
    fclose(ptr);
    return 0;
}