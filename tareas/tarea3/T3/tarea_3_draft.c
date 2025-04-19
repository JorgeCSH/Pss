#include <stdio.h>   // Para las funciones printf, fread, etc.

typedef struct nodo {
  int id;
  struct nodo *izq, *der;
}


Nodo *extractMax(Nodo **pa) {
    if (*pa == NULL) {
        return NULL;
    }
    if ((*pa)->der == NULL) {
        
        Nodo *res = (*pa);
        *pa = (*pa)->izq;
        return res;
    } else {
        return extractMax(&(*pa)->der);
    }
}

Nodo *mezclar(Nodo **izq, Nodo **der) {
    if (*izq == NULL) {
        return *der;
    }
    if (*der == NULL) {
        return *izq;
    }
    Nodo* res = extractMax(izq);
    res->izq = *izq;
    res->der = *der;
    return res;
}



void elimIntervalo(Nodo **pa, int inf, int sup) {
  // Complete aqui la funcion pedida en el enunciado
}


int main() {

  //elimIntervalo();

  printf("\n Este codigo ql funciono \n");
  return 0;
}
