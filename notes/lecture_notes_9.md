# Catedra 9, 8 de abril

## Estructuras recursivas

Una estructura recursiva es un tipo de estructura donde una o mas variables son del mismo tipo de la estructura creada. Ejemplo:

``` c
/* Tomemos el caso de una lista enlazada.
En este tipo de listas, cada nodo tiene dos cosas:
valor y puntero al siguiente. */
typedef struct nodo {
  int x;
  // Referencia al siguiente elemento de la lista.
  struct nodo *prox; // Apunta al siguiente de la lista, el cual es del mismo tipo.
} 
typedef struct nodo Nodo;
```

Otro ejemplo que probablemente usemos harto[^1] es el caso del arbol de busqueda binaria:

``` c
typedef struct nodo {
  int x;
  struct nodo *izq;
  struct nodo *der;
} Nodo;
```

Ahora, en las estructuras recursivas tenemos un puntero para detener este proceso de recursividad el cual es un puntero vacio o nulo, este se enuncia con `NULL` o `(void *)`. Este puntero puede ser asociado a cualquier tipo de estructuras y con este puntero podemos saber donde termina su estrcutura (**claramente el "su" no lo dijo la profe para hacer referencia a nosotros jeje**). Hagamos un ejemplo usando la estructura de lista:

``` c
typedef struct nodo {
  char *val;
  struct nodo *prox;
} Nodo;

int buscar (Nodo *pcab, char *pal) {
  // Despues veremos recursividad.
  Nodo *aux = pcab;
  while (aux != NULL) {
    /* Reviso el nodo en que estoy y si tiene pal lo retorno,
    esto mientras no llegue a un nodo con NULL */
    if (stremp(pal, aux -> val) == 0) {
      return 1;
    }
    /* Aca no nos sirve la forma normal de avanzar en punteros, 
    aca debemos pasarlle el siguiente nodo */
    aux = aux -> prox;
  }
  return 0;
}

void main() {
  /* Generalmente en las listas partimos de atras hacia adelante, 
  es decir, donde termina a donde empieza. */
  Nodo a = {"hola", NULL};
  /* Aca le pasamos la direccion memoria de a */
  Nodo b = {"chao", &a};
  Nodo c ={"xxxx", &b};
  // Nodo c -> Nodo b -> Nodo a -> ||| (final xd, no sabia como hacer tierra jeje)
  
  // Buscaremos un valor.
  int res = buscar(&c, pal);
}
```

Importante, a un puntero nulo no podemos acceder a ningun campo de la estructura, arrojando un `segfault`, esto es, hay funa si hacemos:

``` c
Nodo *a = NULL // a -> val llevara a un segfault
```

Con esto podemos ya empezar a trabajar con recursividad de estructuras, la cual incorporara punteros a punteros de estructuras.

[^1]: Algoritmos reference.
