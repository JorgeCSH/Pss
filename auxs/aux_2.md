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
