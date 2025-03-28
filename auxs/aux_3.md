# Aux 3, 28 de marzo

## P1

Lo primero es notar que, la mayoria de ejercicios requieren de recorrer strings. Despues, sabiendo la codificacion ASCII, usaremos esto para ver los tipos de caracteres (en bits) de c/u. Ahora vamos a usar un ciclo `while` preguntando si es que la posicion a la que apuntamos es un 0, donde de serlo asi, se acaba.

``` c
#include <string.h>

// Convertir a minusculas el texto.
void to_lower(char *s) {
  while(*s) {
    /* Recordemos que "" corresponden a arreglos de caracteres, 
    strings. Pero '' corresponden a un caracter, por ende debemos 
    usar las comillas simples*/
    if ("A" <= *s && *s <= "Z") {
      /* Aca lo que hacemos es ver la diferencia entre el tamaño 
      de minuscula y mayuscula para ver si corresponde o no, asi 
      despues sumamos (en el mismo ciclo) la diferencia que lo  
      cambia a minuscula. */
      *s = 'a' - 'A';
    }
    s ++;
  }
}

// Convertir a mayusculas el texto.
void to_upper(char* s) {
  while(*s) {
    if ('a' <= *s && *s <= 'z') {
      *s -= 'a' - 'A';
    }
    s++;
  }
}
```

## P2

Para esto vamos a tener dos punteros, uno que apunta al frente y otro que apunta al final.

``` c
#include <string.h>

int palindromo(char *s) {
  char *front = s;
  char *back = s + strlen(s) - 1; // Hay que restarle 1 porque el arreglo termina con 0.
  
  /* Mientras el puntero del extremo izquierdo no se entrecruze (es decir,
  no sea mayor o igual que el de atras), entonces ejecutaremos */
  while(front < back) {
    /* Aca comparamos los caracteres */
    if (*front != *back) {
      return 0;
    }
    front++;
    back--;
  }
  return 1;
}
```

## P3

Para hacer este problema usaremos una mecanica similar a la anterior en donde ubicaremos dos punteros[^1]. Esto nos dan una variable o espacio usado con valor constante (**basicamente una variable constante (?)**). Como tenemos que dar vuelta (o mejor decido) intercambiar dos variables, usaermos una variable auxiliar para guardar un valor a, reemplazamos el valor a por b y despues el valor de b lo reemplazampos por el de la variable auxiliar.

``` c
# include <string.h>

void reverse(char *s) {
  char *front = s;
  char *back = s + strlnes(s) - 1;

  while(front < back) {
    /* Esto cuenta como O(1) puesto a que solo estamos usando 1 byte 
    cada vez */
    char aux = *front;

    // Aca las igualamos.
    *front = *back;
    *back = *front;

    front++;
    back--;
  }
}
```

## P4

Para esto, usaremos un arreglo para guardar mas de un contador dependiendo de un valor entregado.

``` c
// No usar los corchetes en el control.
char mas_repetido(char *s) {
  /* Creamos un arreglo de char's, este es de largo 256 por 
  la cantidad de bits que tiene, el cual permite recorrer de 
  todos los tamaños */
  int char[256] = {0};
  while(*s) {
    // Con el ++ aumento en 1 al valor dentro del arreglo.
    chars[(int)*s]++;
    s++;
  }
  
  int max = -1;
  char max_char;
  for(int i = 0; i < 256; i++) {
    if(chars[i] > max) {
      max = chars[i];
      max_char = chars[i];
    }
  }
}
```

[^1]: da lo mismo donde este el *, puede ser `char* s` o `char *s`.
