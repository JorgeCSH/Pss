#include <stdio.h>
#include <stdlib.h>

#include "dup.h"

unsigned long long dupMasLargo(unsigned long long x) {
  unsigned long long izq, der;
  unsigned long long i = 0, j = 0;
    
  for (unsigned long long k = 32; k > 0; k--) {
    izq = (x << j) >> (32 + i);
    der = x & (((unsigned long long)1 << (32 - i)) - 1);
    if (izq == der) {
      return ((unsigned long long)(32 - i) << 32) | der;
    }
    j += 2;
    i++;
  }
  return 0;
}
