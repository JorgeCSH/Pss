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

Ahora, implementemos el mismo ejercicio pero usando `malloc`:

``` c 
char *eliminados(char *str, char x) {
  /* Primero contamos los caracteres que debe tener 
  el nuevo stirng, por ende ocupara mas tiempo. */
  char *check = str;
  int len = 0; // Permite ir contando el largo del nuevo string.
  while(*check != 0) {
    if(*check != x) {
      len++;
    }
    check++;
  }

  /* Ahora podemos generar el espacio del nuevo string. */
  char *new = malloc(len + 1);

  /* Aca rellenamos el string, esto siguiendo la misma idea 
  del metodo original. */
  char *copyNew = new; // Copiando char que sirven.
  check = str; // Recorrer str.

  while(*check != 0) {
    if(*check != x) {
      *copyNew = *check;
    }
    copyNew++;
  }

  /* 0 final. */
  *copyNew = 0;
  return new;
}
```
