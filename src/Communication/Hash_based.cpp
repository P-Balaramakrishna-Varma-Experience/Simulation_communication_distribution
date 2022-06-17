// C program to implement
// the above approach
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "assert.h"
#include<stdbool.h>

#include "../../src/Common/Read_FASTA.h"
// Driver code

int main(int argc, char* argv[])
{
    assert(argc == 3);
    int K = atoi(argv[2]);

    // Opening file in reading mode
    FILE *ptr;
    ptr = fopen(argv[1], "r");
    assert(ptr != NULL);


    char a;
    unsigned long int count = 0;
    while (a != EOF)
    {
        a = get_next_char(ptr);
        count++;
    }
    count--;  // To offset the EOF
    unsigned long int cost = (count + 1 - K) * K;
    printf("K: %d  cost: %lu\n", K, cost);

    //closing file
    fclose(ptr);
    return 0;
}