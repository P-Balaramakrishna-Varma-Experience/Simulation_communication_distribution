#ifndef __Hash_String_H
#define __Hash_String_H

#include <stdint.h>

unsigned int string_hash_geek(const char *s, const int n);
unsigned int string_hash_murmur3(const char *s, const int n);


#endif