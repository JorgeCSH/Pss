#include <stdio.h>
#include <stdlib.h>

#include "dup.h"

unsigned long long dupMasLargo(unsigned long long x) {
	unsigned long long izq = 0;
	unsigned long long der = 0;
	unsigned long long xAux = x;
	int j_izq = 0;
	int j_der = 0;
	unsigned long long cantDigitos = 32;
	while (i > 0) {
		der = xAux & ((((unsigned long long)(-1)) >> (32 + j_der)));
		izq = xAux & ((((unsigned long long)(-1)) >> (32 + j_izq)) << 32);
		if (izq == der) {
			unsigned long long derAux = der;
			unsigned long long cantDigitosDif = 0; 
			while (derAux != 0) {
				derAux = derAux >> 1;
				cantDigitosDif++;
			}
			cantDigitos = cantDigitos << (64-cantDigitosDif);
			resultado = cantDigitos | der;
			return resultado;
		}
		j_der++;
		j_izq+=2;
		cantDigitos--;
	}	
	return (unsigned long long)0;
}


// Funcion main que despues hare desaparecer por pvto
int main(){
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
  resultado_9 = dupMasLargo(0x3af13c803af13c80);
  printf("\n\nResultado 9: %llu", resultado_9);
  return 0;
}

