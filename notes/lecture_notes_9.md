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





[^1]: Algoritmos reference.




