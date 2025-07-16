#include <stdlib.h>
#include <stdio.h>

// estructura de node para p2
typedef struct node{
	int x;
	struct node *izq, *der;
} Node;


// función podar que elimina los nodos con un valor mayor a y
// del árbol. no libera memoria de los nodos eliminados
void podar(Node **pa, int y){
	Node* a = *pa;

	// caso base: nos encontramos con una hoja del árbol (no hacemos nada)
	if(a == NULL)
		return;

	// si el valor del nodo actual es mayor a 'y', lo tenemos que podar 
	if(a->x > y){
		podar(&(a->izq), y); // primero podamos el subárbol izq
		
		// el puntero que recibió la función ahora apunta al resultado de
		// podar el subárbol izq, perdiendo la referencia del nodo actual
		// que debía ser podado
		*pa = a->izq;
	}
	else // a->x <= y
	   // si este nodo no debe ser podado, seguimos recorriendo hacía la derecha
	   // pues es en ese subárbol donde pueden existir nodos mayores o iguales al 
	   // actual
	   podar(&(a->der), y);
}


// utilidades para el test con los ejemplos del enunciado
Node *createNodeT(int x, Node *left, Node *right){
  Node *p = (Node *) malloc(sizeof(Node));
  p->x = x;
  p->izq = left;
  p->der = right;
  return p;
}

void printiArbol(Node *a) {
  if(a == NULL) return;
  printiArbol(a->izq);
  printf("%i ", a->x);
  printiArbol(a->der);
}

void printTree(Node* root, int space) {
  if (root == NULL) {
    return;
  }

  int count = 5;
  space += count;

  printTree(root->der, space);

  printf("\n");
  for (int i = count; i < space; i++) {
    printf(" ");
  }
  printf("%d\n", root->x);

  printTree(root->izq, space);
}


// main que prueba la función podar con los dos ejemplos
// del enunciado
int main(){
  printf("===============================================\n\n");

  Node *t = createNodeT(4,
                createNodeT(2,
                    createNodeT(1, NULL, NULL),
                    createNodeT(3, NULL, NULL)),
                createNodeT(6,
                    createNodeT(5, NULL, NULL),
                    NULL));

  printf("Árbol del enunciado \n");
  printTree(t, 0);
  printf("\n\ninorder: ");
  printiArbol(t);

  printf("\n\n");
  printf("podar(&t, 5)\n");
  printf("Árbol depués de podar con y=5\n");
  podar(&t, 5);
  printTree(t, 0);
  printf("\n\ninorder: ");
  printiArbol(t);

  printf("\n\n");
  printf("podar(&t, 2)\n");
  printf("Árbol depués de podar con y=2\n");
  podar(&t, 2);
  printTree(t, 0);
  printf("\n\ninorder: ");
  printiArbol(t);

  printf("\n\n===============================================\n");
  return 0;
}
