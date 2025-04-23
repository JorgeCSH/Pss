#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "intervalo.h"

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
  Nodo *a = *pa;
  if(a == NULL) {
    return;
  } else if ((a->id) < inf) {
    elimIntervalo(&(a->der), inf, sup);
    elimIntervalo(&(a->izq), inf, sup);
  } else if((a->id) > sup) {
    elimIntervalo(&(a->der), inf, sup);
    elimIntervalo(&(a->izq), inf, sup);
  } else {
    elimIntervalo(&(a->izq), inf, sup);
    elimIntervalo(&(a->der), inf, sup);
    *pa = mezclar(&(a->izq), &(a->der));

    
  }


    

}
