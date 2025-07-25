# Catedra 12, 24 de abril

## Clase de ejercicios propuestos pre control

### P1. Binarios

Sea `x, y` enteros sin signo eliminar de `x` todas las repeticiones de `y`, es decir, programe la funcion:

``` c
unsinged long long elimDup(unsigned long long x, unsigned long long y);
```

Esta debe hacer, por ejemplo:
`elimDup(0x1c1c, 0x1c) => 0x0`
`elimDup(0x1c1c1, 0xc1c) => 0x11`
`elimDup(0x1c1c11, 0x1c1) => 0x1c1`

``` c
typedef unsigned long long ull;

ull elimDup(ull x, ull y) {
  // Programe aqui su funcion
}
```

### P2. Strings

Sea `s` un string, se desea comprimir `s` de la siguiente forma utilizando la siguiente funcion:

``` c
void comprimir(char *s);
```

La cual debe comprimir de la forma:
`comprimir("AABCCCD") => "2AB3CD"`
`comprimir("ABBAA") => "A2B2A"`
Nota: las repetciones consecutivas de caracteres estan entre 1 y 9.
Nota: `int x = 1; => x + '0'`.

``` c
void comprimir(char *s) {
  // Programe aqui su solucion
  char *saux1 = s; 
  char *saux2 = s + 1;
  char *inicio = s;
  int i = 1;

  while(*saux2 != '\0') {
    if (*saux1 != *saux2) {
      if(i > 1) {
        *inicio = 48+i; //ascii 
        inicio++;
      }  
      *inicio = *saux1;
      inicio++;
      i = 0;
    }
    i++;
    saux1++;
    saux2++;
  }

  if(*saux2 == '\0') {
    char *saux3 = saux1;
    int j = 1;
    saux3--;
    while (*saux3 == *saux1) {
      j++;
      saux3--;
    }

    if (j > 1) {
      *inicio = 48 + j; //ascii 
      inicio++;
    }
    *inicio = *saux1;
    inicio++;
  }
  *inicio = '\0';
}

```

### P3. Estructuras (pero con iteracion)

Sea L lista enlazada ordenada, eliminar todos los nodos duplicados de L. Ejemplo:
`L = 1-> 1-> 2 -> 2 -> 2, elim(L) = 1 -> 2;`
Para esto, programe la funcion:

``` c
typedef struct nodo {
  int x;
  struct nodo *prox;
} Nodo;

void elim(Nodo *l);
```

Nota: mantener 1 nodo repetido  eliminar los siguientes.

``` c  
typedef struct nodo {
  int x;
  struct nodo *prox;
} Nodo;

void elim(Nodo *l) {
  // Programe aqui su funcion
}

```
