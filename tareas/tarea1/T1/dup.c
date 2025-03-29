#include <stdio.h>
#include <stdlib.h>

#include "dup.h"

unsigned long long dupMasLargo(unsigned long long x) {
	unsigned long long izq = 0;
	unsigned long long der = 0;
	
	unsigned long long i = 0;
	unsigned long long j = 0;

	unsigned long long resultado = 0;	
	
	int k = 32;
	if (x == 0) {
		return (unsigned long long)1 << 37;
	}
	if ((x << 32) == ((x >> 32)<<32)) {
		printf("\n oof");
		return ((unsigned long long)1 << 37) | (x >> 32);
	}
	while (k) {
		izq = (x << j)>> (32+i) ;
		der = (x << (32 + i)) >> (32 + i);
		if (izq	== der) {
			unsigned long long largoSecuencia = (32-i);
			
			largoSecuencia = largoSecuencia << 32;
			resultado = largoSecuencia | der;
			break;
		}
		j += 2;
		i++;
		k--;
	}
	return resultado;

