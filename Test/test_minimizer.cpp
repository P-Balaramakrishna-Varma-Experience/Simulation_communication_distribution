#include "string.h"
#include "stdio.h"
#include "stdlib.h"
#include "assert.h"
#include "stdbool.h"
#include "../src/Common/ClassicalMinimizer.h"

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

int main(int argc, char* argv[])
{
   printf("%d\n", test(6, 3, "ATGATC", "ATC"));
   printf("%d\n", test(6, 3, "ATGAGC", "AGC"));
   printf("%d\n", test(6, 2, "ATGAGC", "AG"));
   printf("%d\n", test(6, 4, "ATGAGC", "ATGA"));
   printf("string comp\n\n");
   printf("%d ex:ans>0\n", better_classic_mini("ATGC", "AAAG", 4));
   printf("%d ex:ans<0\n", better_classic_mini("ATGC", "ATTT", 4));
}