#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

#include "Read_FASTA.h"

char get_next_char(FILE *ptr)
{
    char ch, ans;
    bool Done = false;

    while (Done == false)
    {
        ch = fgetc(ptr);
        if (ch == EOF)
        {
            ans = EOF;
            Done = true;
        }
        else if (ch == 'A' || ch == 'T' || ch == 'G' || ch == 'C')
        {
            ans = ch;
            Done = true;
        }
        else if (ch == 'a' || ch == 't' || ch == 'g' || ch == 'c')
        {
            ans = ch - 32;
            Done = true;
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
            printf("Woring undected char %c %d\n", ch, ch);
        }
    }
    return ans;
}