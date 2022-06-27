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
    assert(argc == 4);
    int X = atoi(argv[3]);
    int K = atoi(argv[2]);

    // Opening file in reading mode
    FILE *ptr;
    ptr = fopen(argv[1], "r");
    assert(ptr != NULL);


    char a = 'a';
    unsigned long int count = 0;
    while (a != EOF)
    {
        a = get_next_char(ptr);
        if (a != EOF)
            count++;
    }
    assert(count >= K);
    unsigned long int cost = (count + 1 - K) * K;
    printf("%d,%lu\n", K, cost);

    //closing file
    fclose(ptr);
    return 0;
}