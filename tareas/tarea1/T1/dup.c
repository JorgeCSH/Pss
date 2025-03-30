#include <stdio.h>
#include <stdlib.h>

#include "dup.h"

unsigned long long dupMasLargo(unsigned long long x) {
  // Variables que corresponden a los dos prefijos s.
  unsigned long long izq;
  unsigned long long der;

  // Posiciones de los bits en los prefijos.
  unsigned long long i = 0;
  unsigned long long j = 0;
 
  // Ciclo donde comparamos cada prefijo.  
  for (unsigned long long k = 32; k > 0; k--) {
    // Subprefijo izquierdo, zSs.
    izq = (x << j) >> (32 + i);
    // Subprefijo derecho, zsS.
    der = x & (((unsigned long long)1 << (32 - i)) - 1);
    // Caso donde los subrefijos son iguales.
    if (izq == der) {
      // cantidad de bits | subprefijo.
      return ((unsigned long long)(32 - i) << 32) | der;
    }
    // Desplazamos los invariantes (o posiciones simplemente).
    j += 2;
    i++;
  }
  return 0;
}
