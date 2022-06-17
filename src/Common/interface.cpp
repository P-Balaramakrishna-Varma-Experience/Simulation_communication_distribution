#include "interface.h"
#include "MurmurHash3.h"
#include "Polynomial_rolling.h"

//For using polynomial_hash
int string_hash(const char *s, const int n)
{
    return polynomial_hash(s, n);
}


//For using MurmurHahs
int string_hash(const char *s, const int n)
{
    
}