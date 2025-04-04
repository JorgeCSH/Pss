# Aux 4, 4 de abril

## Algunas cosas del resumen

Claramente,

## P1

Mismo ejercicio de la ultima vez, solo que esta vez la funcion solucion retornara un `char*` :

``` c
void to_lower(char* s) {
  while (*s) {
    if ('A' <= *ss && *s <= 'Z') { // Recordar la comilla simple. 
      *s -= 'A' - 'a';
    }
    s++;
  }
}

char* lowerCase(char* s) {
  char *ret = malloc(strlend(s) + 1); // Aca pedimos un cacho de memoria.
  strcpy(ret, s); 
  to_lower(ret);
  return ret;
}
```

Ahora, hagamos lo mismo sin las funciones usadas antes:

``` c
char* lowerCase_variante(char *s) {
  char *recipiente = malloc(strlen(s) + 1); 
  while (*s) {
    if ('A' <= *s && *s <= 'Z') {
      *recipiente = *s + 32;
    } else {
      *recipiente = *s;
    }
    s++;
    recipiente++;
  }
  *recipiente = '\0'; // Aca incluimos el 0 al final. ESTO ES IMPORTANTE, 1 PTO DE DESCUENTO.
  return recipiente;
}
```
