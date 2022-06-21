//#include "src/Common/hash_interface.h"
#include "../src/Common/hash_interface.h"
#include "stdio.h"
#include "string.h"
#include "gtest/gtest.h"

TEST(Hash_function, Hash_geek)
{
    char A[] = "abcdefgh";
    int N = strlen(A);
    unsigned int Hash_geek = string_hash_geek(A, N);
    EXPECT_EQ(Hash_geek, 489951694);
}

TEST(Hash_function, Hash_Murmur3)
{
    char A[] = "abcdefgh";
    int N = strlen(A);
    unsigned int Hash_Murmur3 = string_hash_murmur3(A, N);
    EXPECT_EQ(Hash_Murmur3, 3348134347);
}