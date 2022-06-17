// C program to implement
// the above approach
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "assert.h"
#include<stdbool.h>

// Driver code
int main()
{
    FILE *ptr;
    char ch = 'a';
    char a = 'a';

    // Opening file in reading mode
    ptr = fopen("text4.txt", "r");
    assert(ptr != NULL);


    while (a != EOF)
    {
        ch = fgetc(ptr);
        if(ch == EOF)
        {
            a = EOF;
        }
        else if (ch == 'A'|| ch == 'T' || ch == 'G' || ch == 'C')
        {
            a = ch;
        }
        else if (ch == 'a' || ch == 't' || ch == 'g' || ch == 'c')
        {
            a = ch - 32;
        }
        else if (ch == 'N' || ch == 'n' || ch == '\n')
        {
            continue;
        }
        else if (ch == '>')
        {
            while (ch != '\n')
                ch = fgetc(ptr);
            continue;
        }
        else 
        {
            assert(false);
        }

        printf("%c", a);
    }



    fclose(ptr);
    return 0;
}