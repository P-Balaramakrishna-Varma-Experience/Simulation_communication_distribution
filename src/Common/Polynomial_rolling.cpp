#include <stdio.h>
#include <string.h>
#include "Polynomial_rolling.h"

//https://www.geeksforgeeks.org/string-hashing-using-polynomial-rolling-hash-function/
int polynomial_hash(const char *s, const int n) {
  const int p = 31, m = 1e9 + 7;
  int hash = 0;
  long p_pow = 1;
  for (int i = 0; i < n; i++) {
    hash = (hash + (s[i] - 'a' + 1) * p_pow) % m;
    p_pow = (p_pow * p) % m;
  }
  return hash;
}


