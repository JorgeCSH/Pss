#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
typedef unsigned long long uint64;

uint64 suma(uint64 x) {
  uint64 mask4 = ~((unsigned)(-1) << 4);
  uint64 largoSec = x & mask4;
  uint64 maskLong;
  uint64 suma = 0;

  while (largoSec != 0) {
    x = x >> 4;
    maskLong = ~((unsigned)(-1) << largoSec);
    suma += (x & maskLong);
    x = x >> (largoSec);
    largoSec = x & mask4;
  }
  return suma;
}

*/

char *reemplazo(char *s, char c, char *pal) {
  char *contMem = s;
  char *sOriginal = s;

  int iMem = 0;
  while(*contMem != '\0') {
    if(*contMem == c) {
      iMem++;
      printf("%d ", iMem);
    }
    contMem++;
  }


  char *sResultado = malloc(strlen(s) + strlen(pal)*iMem + 1);
  char *sNuevo = sResultado;
  while(*sOriginal != '\0') {
    if(*sOriginal == c) {
      char *palOriginal = pal;
      while(*palOriginal != '\0') {
        *sNuevo = *palOriginal;
        sNuevo++;
        palOriginal++;
      }
      sOriginal++;
    } else {
      *sNuevo = *sOriginal;
      sNuevo++;
      sOriginal++;
    }
  }

  *sNuevo = '\0';
  return sResultado;
}



int main() {
  //uint64 choripan = suma(0b00001001101011100011010010);
  //printf("\n suma(19, 6, 1):%llu ", choripan);
  char *aaa = reemplazo("hola que tal", 'a', "xyz");
  printf("\n%s resultado: ", aaa);
  return 0;
}
