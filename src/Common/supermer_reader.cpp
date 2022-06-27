#include <string.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "Read_FASTA.h"
#include "ClassicalMinimizer.h"




int get_next_supermer(FILE* file, int K, int M, char *Min, char* Storage, int sN)
{
    static char Tem[1000];
    static int tN = 1000;
    static bool intialized = false, reached_eof = false;
    char TempMin[M];

    if(reached_eof == true)
        return -1;

    int loc = 0;
    if(intialized == false)
    {
        for(int i = 0; i < K; i++)
            Storage[i] = get_next_char(file);
        intialized = true;
    }
    else
    {
        for(int i = 0; i < K; i++)
            Storage[i] = Tem[i];
    }
    loc+= K;

    Classic_Minimizer(Min, M, K, Storage);
    int start_loc_min = Classic_Minimizer_loc(M, K, Storage);

    char ch;
    while(loc < sN)
    {
        ch = get_next_char(file); 
        if(ch == EOF)
        {
            reached_eof = true;
            return loc;
        }
        Storage[loc] = ch;
        
        if(start_loc_min >= loc - K + 1)
        {
            if(better_classic_mini(&Storage[loc - M + 1], Min, M) < 0)
            {
                strncpy(Tem, &Storage[loc - K + 1], K);
                return loc;
            }
            else
            {
                Storage[loc] = ch;
                loc++;
            }
        }
        else
        {
            start_loc_min = Classic_Minimizer_loc(M, K, &Storage[loc - K + 1]);
            Classic_Minimizer(TempMin, M, K, &Storage[loc - K + 1]);
            if(strncmp(TempMin, Min, M) != 0)
            {
                strncpy(Tem, &Storage[loc - K + 1], K);
                return loc;
            }
            else
            {
                Storage[loc] = ch;
                loc++;
            }
        }
    }

    strncpy(Tem, &Storage[loc - K + 1], K - 1);
    Tem[K - 1] = get_next_char(file);
    if(Tem[K - 1] == EOF)
    {
        reached_eof = true;
        return loc;
    }
    else
        return loc;
}
