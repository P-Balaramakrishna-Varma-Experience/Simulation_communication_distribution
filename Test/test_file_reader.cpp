// C program to implement
// the above approach
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "assert.h"
#include <stdbool.h>
#include "../src/Common/Read_FASTA.h"
#include "gtest/gtest.h"

//Ans size should be equal to that of the file.
//returns size of the Ans
int readFile(char *FileName, char *Ans)
{
    FILE *ptr;
    ptr = fopen(FileName, "r");
    assert(ptr != NULL);

    char a = get_next_char(ptr);
    int i = 0;
    while (a != EOF)
    {
        Ans[i] = a;
        i++;
        a = get_next_char(ptr);
    }
    fclose(ptr);
    return i;
}

TEST(CharFileReader, allfiles)
{
    char Ans[10000];
    int a;
    
    a = readFile("Test/Tests_File_char_reader/test1.fasta", Ans);
    ASSERT_EQ(a, 20);
    ASSERT_TRUE(strncmp(Ans, "ATGCAAAATTTTGGGGCCCC", a) == 0);

    a = readFile("Test/Tests_File_char_reader/test2.fasta", Ans);
    ASSERT_EQ(a, 20);
    ASSERT_TRUE(strncmp(Ans, "ATGCAAAATTTTGGGGCCCC", a) == 0);

    a = readFile("Test/Tests_File_char_reader/test3.fasta", Ans);
    ASSERT_EQ(a, 14);
    ASSERT_TRUE(strncmp(Ans, "AAAATTTTGGGAAA", a) == 0);

    a = readFile("Test/Tests_File_char_reader/test4.fasta", Ans);
    ASSERT_EQ(a, 16);
    ASSERT_TRUE(strncmp(Ans, "ATCGATCGATCGATCG", a) == 0);
}

/*
int main(int argc, char* argv[])
{

    char Ans[10000];

    int a = readFile(argv[1], Ans);

    for(int i = 0; i < a; i++)
        printf("%c", Ans[i]);
//    printf("\n");

    return 0;
}
*/