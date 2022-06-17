// C program to implement
// the above approach
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "assert.h"
#include<stdbool.h>

#include "../../src/Common/Read_FASTA.h"
// Driver code

int main()
{
    FILE *ptr;
    char ch = 'a';
    char a = 'a';

    // Opening file in reading mode
    ptr = fopen("test.txt", "r");
    assert(ptr != NULL);


    while (a != EOF)
    {
        a = get_next_char(ptr);
        printf("%c", a);
    }



    fclose(ptr);
    return 0;
}