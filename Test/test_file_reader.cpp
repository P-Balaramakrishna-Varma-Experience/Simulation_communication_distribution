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

    // Opening file in reading mode
    assert(argc == 2);
    FILE *ptr;
    ptr = fopen(argv[1], "r");
    assert(ptr != NULL);

    char a;
    while (a != EOF)
    {
        a = get_next_char(ptr);
        printf("%c", a);
    }


    //closing file
    fclose(ptr);
    return 0;
}