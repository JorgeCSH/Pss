# Catedra 9, 3 de abril

## Antes, un ejercicio

Modificando string:

``` c
void eliminarChar(char *str, char x) {
  /* Puntero  que apunta a str, este lo que hace es 
  copiar/mantener la informacion que me seirvir */
  char *copy = str;
  char *check = str; // Este compara char str con x.

  /* Ciclo mientras aun no se llegue al final del 
  string. */
  while(*check != 0) {
    /* Si el caracter es distinto a x, entonces lo 
    mantengo. */
    if (*check != x) {
      *copy = *check;
      copy++
    }
    check++;
  }
  // Una vez termine el ciclo.
  *copy = 0; // Fin del string.
  return ;
}

```
