#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>

#include "Mapping.h"


//returns a array of length t with permution of 0..t-1
int* generate_perm(int t);
void swap(int* a, int* b);

void Remap(int** arr, int t, int n)
{
    assert(n < t);
    assert(t % n == 0);
    int* Input = *arr;
    int* perm = generate_perm(t);
    
    int *Ans = (int*)malloc(n * sizeof(int));
    assert(Ans != NULL);
    for(int i = 0; i < n; i++)
        Ans[i] = 0;

    int bin, val, loc = 0;
    for(int i = 0; i < t; i++)
    {
        bin = perm[i];
        val = Input[bin];
        Ans[loc] += val;
        loc = (loc + 1) % n;
    }

    free(perm);
    free(Input);
    *arr = Ans;
}

int* generate_perm(int t)
{
    srand(time(NULL));
    int* perm = (int*)malloc(t*sizeof(int));
    for(int i = 0; i < t; i++)
        perm[i] = i;

 
    for (int i = t - 1; i > 0; i--)
    {
        // Pick a random index from 0 to i
        int j = rand() % (i+1);
 
        // Swap arr[i] with the element at random index
        swap(&perm[i], &perm[j]);
    }
    return perm;
}

void swap(int*a, int*b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}