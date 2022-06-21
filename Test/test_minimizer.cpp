#include "string.h"
#include "stdio.h"
#include "stdlib.h"
#include "assert.h"
#include "stdbool.h"
#include "../src/Common/ClassicalMinimizer.h"
#include "gtest/gtest.h"

bool test(int K, int M, char* Kmer, char* min)
{
    char Ans[M];
    //printf("M: %d   ans: ", M);
    Classic_Minimizer(Ans, M, K, Kmer);
    //printf("%s\n", Ans);

    if(strncmp(Ans, min, M) == 0)
        return true;
    else
        return false;
    
}


TEST(ClassicMinimizersTest, MinimizerStringTest)
{
    ASSERT_TRUE(test(6, 3, "ATGATC", "ATC"));
    ASSERT_TRUE(test(6, 3, "ATGAGC", "AGC"));
    ASSERT_TRUE(test(6, 2, "ATGAGC", "AG"));
    ASSERT_TRUE(test(6, 4, "ATGAGC", "ATGA"));
}

TEST(ClassicMinimizersTest, ComparisionTest)
{
    ASSERT_GT(better_classic_mini("ATGC", "AAAG", 4), 0);
    ASSERT_LT(better_classic_mini("ATGC", "ATTT", 4), 0);
}


TEST(ClassicMinimizersTest, LocationTest)
{
    ASSERT_EQ(Classic_Minimizer_loc(4, 6, "ATGATC"), 0);
    ASSERT_EQ(Classic_Minimizer_loc(3, 7, "AGCAAAT"), 3);
    ASSERT_EQ(Classic_Minimizer_loc(2, 8, "ATAGACGC"), 4);
    ASSERT_EQ(Classic_Minimizer_loc(2, 6, "GTGAGC"), 3);
}