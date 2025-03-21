# Aux 2, 21 de marzo

## P1

Para el desarrollo de este ejercicio utilizaremos una mascara, esto porque comprobar las posociones no es facil, por ende utilizaremos la mascara.
Para esto, recorreremos el numero. Porgramando:

``` c
int posicionBit(unsigned int n) {
  // Asumiendo que la mascara es de largo 1 
  unsigned mask = 1;
  /*
  Ahora lo qeu queremos es recorrer el numero, pues queremos revisar bit por bit por...
  esto shifteando la posicion.
  */
  // Contador del ciclo
  int count = 0;
  while(n) {
    // Cuando el digito sea 1, aumentamos el contador.
    if ((n & mask) == 1) {
      // En el condicional tambien podriamso usar solamente (n & mask), basicamente un while true.
      count++;
    }
    // Aca con la mascara la usaremos para fijarnos solamente en el bit.
    // Aca shifteamos por 1 
    n >>= 1;
  }
  return count;
}
```

## P2

``` c
// Sabemos que, para este ejercicio necesitaremos una mascara de largo n para ir comparano patrones de bits
int posicionBits(int x, int p, int n) {
  // Para la mascara, usaremos la expresion que pensamos en el comentario anterior
  unsigned m = -1;
  int mask = ~(m << n);
  // En este ejercicio especifico, utilizaremos un for
  for(unsigned int i = 0; i < sizeof(x)*8; i++) {
    // Esto nos va a aislar los primero n
    if (((x >> i) & mask) == p) {
      return i;
    } 
  }
  return -1;
}

```

## P3

``` c
// Esto es para crear un tipo uint que, basicamente sea un unsigned int (basicamente para no escribir todo xd)
typedef unsigned int uint;

// Aca hacemos una funcion con el tipo que definimos con typedef
uint reBits(uint x, int i, int k, uint val) {
  uint mask = ~((-1U) << k);
  mask <<= i;
  val <<= i;

  mask = ~mask;

  x &= mask;
  
  x |= val;

  return x;

}
```

## Recordatorio

Bits es la primera parte dle control
