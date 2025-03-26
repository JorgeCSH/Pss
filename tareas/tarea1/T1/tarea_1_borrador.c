#include <stdio.h>
#include <stdlib.h>

#include "dup.h"

unsigned long long dupMasLargo(unsigned long long x) {
  if (x == 1 || x == 2) {
    x = x << 1;
  } 
  if (x == 0) {
    x = ~((~x) << 1);
  }
  // Primero veremos si el numero tiene una cantidad par de bits
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
  
  // Caso donde es impar, en otro caso, se salta
  if (n_decididor > n_total) {
    unsigned long long par_mask = 1 << n_total;
    x_modificado = x_modificado & (~par_mask);
    j -= 2;
    i--;
  }

  unsigned long long patron;
  int k = 0;

  unsigned long long izq = 0;
  unsigned long long der = 0;
  while (k < n_total-1) {

    //printf("%llu\n", x);

    // Mascara lado derecho
    unsigned long long mask1 = ~(((-1) << i));

    // Mascara lado izquierdo
    unsigned long long mask2 = ~(((-1) << j));

    // Aca tenemos los valores que deberian estar dando a los lados
    izq = x & mask2;
    der = x & mask1;

    izq = izq >> i;

    if (izq == der) {
      //printf("\nLo haz logrado, s = %llu", izq);
      break;
    }

    if (k + 2 >= n_total-1 && ((izq == 1 && der == 0) || (izq == 0 && der == 1))){
      //printf("\nFuiste, los que tienes es: %llu", izq >> 2);
      break;
    }

    // Debuggear es pa weones
    /*
    printf("\nSeccion izquierda: %llu", izq);
    printf("\nSeccion derecha: %llu", der);
    printf("\n");
    */
    k += 2;
    j -= 2;
    i -= 1;
    }
  unsigned long long resultado = izq;
  return resultado;
}


// Funcion main que despues hare desaparecer por pvto
void main(){
  unsigned long long resultado_1;
  unsigned long long resultado_2;
  unsigned long long resultado_3;
  unsigned long long resultado_4;
  unsigned long long resultado_5;
  unsigned long long resultado_6;
  unsigned long long resultado_7;
  unsigned long long resultado_8;
  unsigned long long resultado_9;
  resultado_1 = dupMasLargo(427);
  printf("\n\nResultado 1: %llu", resultado_1);
  resultado_2 = dupMasLargo(42);
  printf("\n\nResultado 2: %llu", resultado_2);
  resultado_3 = dupMasLargo(12);
  printf("\n\nResultado 3: %llu", resultado_3);
  resultado_4 = dupMasLargo(69);
  printf("\n\nResultado 4: %llu", resultado_4);
  resultado_5 = dupMasLargo(5);
  printf("\n\nResultado 5: %llu", resultado_5);
  resultado_6 = dupMasLargo(2);
  printf("\n\nResultado 6: %llu", resultado_6);
  resultado_7 = dupMasLargo(1);
  printf("\n\nResultado 7: %llu", resultado_7);
  resultado_8 = dupMasLargo(0);
  printf("\n\nResultado 8: %llu", resultado_8);
  resultado_9 = dupMasLargo(3);
  printf("\n\nResultado 9: %llu", resultado_9);
}

