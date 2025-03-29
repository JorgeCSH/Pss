#include <stdio.h>
#include <stdlib.h>

#include "dup.h"

unsigned long long dupMasLargo(unsigned long long x) {
	unsigned long long izq = 0;
	unsigned long long der = 0;
	
	unsigned long long i = 0;
	unsigned long long j = 0;

	int k = 32;
	while (k) {
		izq = (x << j)>> (32+i) ;
		der = (x << (32 + i)) >> (32 + i);
		if (izq	== der) {
			unsigned long long resultado = 0;	
			resultado = ((32 - i) << 32) | der;
			return resultado;
		}
		j += 2;
		i++;
		k--;
	}
	return 0;
}
