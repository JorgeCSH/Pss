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
  /* Desarrollo */
  // Variables
  Nodo *a = *pa;
  /* Implementacion */
  if (a == NULL) {
   // Llegamos a la hoja del arbol, fin de la recursividad (caso base). 
    return;
  } else if ((a->id) < inf) {
    /* Si el nodo tiene un valor menor al inferior del intervalo, entonces solo analizamos
     * su nodo derecho puesto a que todas los derechos seguiran teniendo un valor menor 
     * que el actual que no pertenece al intervalo, mientras que la hoja derecha si puede
     * ser mayor y por ende puede ocurrir que pertenezca al intervalo (i.e. haya que 
     * eliminar) */
    elimIntervalo(&(a->der), inf, sup);
  } else if((a->id) > sup) {
    /* Caso analogo al valor mayor pero con el valor menor, todos los valores de los nodos 
     * derechos seran mayores y por ende no perteneceran al intervalo dejandono solo los 
     * del lado izquierdo que son menores y puede ocurrir que pertenezca */
    elimIntervalo(&(a->izq), inf, sup);
  } else {
    /* Caso donde esta en el intervalo, aca llamamos recursivamente a ambos lados debido
     * a que puede haber tanto en el lado izquierdo como derecho un nodo con valor en el 
     * intervalo, despues, sobreescribimos el puntero al arbol (es decir, *pa) y liberamos
     * usando free() el nodo "a" que estabamos revisando */
    elimIntervalo(&(a->izq), inf, sup);
    elimIntervalo(&(a->der), inf, sup);
    *pa =  mezclar(&(a->izq), &(a->der));
    free(a);
  }
}
