#include "interface.h"
#include "MurmurHash3.h"
#include "Polynomial_rolling.h"

//For using polynomial_hash
unsigned int string_hash(const char *s, const int n)
{
    return (unsigned int) polynomial_hash(s, n);
}


//For using MurmurHahs
unsigned int string_hash(const char *s, const int n)
{
    unsigned int seed, Hash_value;
    seed = 18082002;
    MurmurHash3_x86_32((void*)s, n, seed, (void*)&Hash_value);
    return Hash_value;
}