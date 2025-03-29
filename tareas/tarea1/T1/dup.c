#include <stdio.h>
#include <stdlib.h>

#include "dup.h"

unsigned long long dupMasLargo(unsigned long long x) {
  if (x == 1 || x == 2) {
    x = x << 1;
  } 
  if (x == 0) {
    x = (unsigned long long)1 << 37;
    x = ~x;
    //printf("izq: %llu: ", ~x);
    return ~x;
  }

  unsigned long long x_modificado = x;

  int n_total = 0;
  int n_decididor = 0;

  unsigned long long i = 0;
  unsigned long long j = 0;

  unsigned long long valor_contador = x;
  while (valor_contador!=0) {
    valor_contador = valor_contador >> 1;
    n_total++;
  }

  while (n_decididor < n_total) {
    n_decididor += 2;
    j += 2;
    i++;
  }
  
  if (n_decididor > n_total) {
    unsigned long long par_mask = 1 << n_total;
    x_modificado = x_modificado & (~par_mask);
    j -= 2;
    i--;
  }

  int k = 0;
  int l = 0;
  unsigned long long izq = 0;
  unsigned long long der = 0;

  while (k < n_total-1) {
<<<<<<< HEAD
    unsigned long long mask1 = ~((unsigned long long)(-1) << i);
    unsigned long long mask2 = ~((unsigned long long)(-1) << j);
=======

    unsigned long long mask1 = ~(((-1) << i));
    unsigned long long mask2 = ~(((-1) << j));
>>>>>>> 8d53dba815aea85541cc89ef71ebe276e1f2af7e

    izq = x & mask2;
    der = x & mask1;

    izq = izq >> i;

    if (izq == der) {
      //printf("izq: %llu: ", izq);
      break;
    }

    if (k + 2 >= n_total-1 && ((izq == 1 && der == 0) || (izq == 0 && der == 1))){
      izq = 0;
      //printf("izq: %llu: ", izq);
      break;
    }

    l++;
    k += 2;
    j -= 2;
    i -= 1;
  }
<<<<<<< HEAD
  return izq;
=======
  return (~(0)<<(l+1))&(izq);
>>>>>>> 8d53dba815aea85541cc89ef71ebe276e1f2af7e
}


