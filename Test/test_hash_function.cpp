//#include "src/Common/hash_interface.h"
#include "../src/Common/hash_interface.h"
#include "stdio.h"
#include "string.h"

int main()
{
    char A[] = "abcdefgh";
    int N = strlen(A);
    unsigned int Hash_geek = string_hash_geek(A, N);
    unsigned int Hash_Murmur3 = string_hash_murmur3(A, N);
    printf("Hash_geek: %ld\n", Hash_geek);
    printf("Hash_Murmur3: %ld\n", Hash_Murmur3);
}