#include <stdio.h>
#include <stdlib.h>

#include "dup.h"
// Aca es done despues tengo que reemplazar por la funcion
/*
unsigned long long dupMasLargo(unsigned long long x) {
  // ... programe aca la funcion pedida ...
}
*/

// Funcion que cuenta la cantidad de bits
int contador(unsigned long long x) {
  // Definimos el contador
  int n = 0;
  /* Aca tengo unos prints porque debuggear es pa weones
  printf("Valor original: x = %d", x);
  printf(" y contador en estado inicial: n= %d", n);
  */
  while (x!=0) {
    x = x>>1;
    n++;
    /* De nuevo, debuggear es para weones
    printf("\nx= %d", x);
    printf("\nn = %d", n);
    printf("\n");
    */
  }
  // printf("La cantidad de bits que hay es de: %d", n);
  return n;
}

void main(){
  // variable que consideraremos para las pruebas
  unsigned long long x = 0b101010;

  // Aca probamos el contador, que gran avance!
  int poto = contador(x);
  printf("La cantidad de bits que es: %d", poto);

}