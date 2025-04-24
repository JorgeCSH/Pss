#include <stdio.h>

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

int main() {
  uint64 choripan = suma(0b00001001101011100011010010);
  printf("\n suma(19, 6, 1):%llu ", choripan);
  return 0;
}
