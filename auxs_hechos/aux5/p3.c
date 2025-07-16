#include <stdlib.h>
#include <stdio.h> 


// estructura de nodo para p3
typedef struct node{
	char x; 
	struct node *izq, *der;
} Node;


// función reemplazarNodoK que reemplaza el k-ésimo nodo en un recorrido
// inorden y retorna k si se hizo el reemplazo o la cantidad de nodos
// encontrados en caso contrario
int reemplazarNodoK(Node **pa, int k, Node *b){
	Node *a = *pa;
	
	// caso base: la hoja no es un nodo, así que no hay nada que 
	// podamos reemplazar, ni tampoco encontramos nodos
	if(a == NULL)
		return 0;

	// siguiendo el recorrido inorden, llamamos a la función
	// recursivamente en el subárbol izquierdo
	int izq	= reemplazarNodoK(&a->izq, k, b);

	// sabiendo que la llamada a la izquierda devolvió 'k':
	// - si en el subárbol izquierdo no se hizo el reemplazo y se
	// encontraron k-1 nodos, el nodo actual es el k-ésimo
	if(izq + 1 == k){
		*pa = b; // reemplazamos el k-ésimo nodo por b
		return k; // retornamos k, pues hicimos el reemplazo
	}
	// - si en el subárbol izquierdo ya se hizo el reemplazo,
	// no tenemos que hacer nada más
	else if(izq == k){
		return k; // retornamos k, pues ya se hizo el reemplazo
	}
		
	// para la llamada recursiva hacia la derecha (siguiendo inorden)
	// hay que ajustar el valor de k, el k-ésimo nodo no es
	// el k-ésimo en el subárbol derecho
	int der = reemplazarNodoK(&a->der, k - izq - 1, b);

	// si la función llega hasta aquí es porque no se ha hecho el reemplazo
	// así que retornamos todos los nodos encontrados
	return izq + der + 1;
}


// utilidades para el test con el ejemplo del enunciado
Node *createNodeT(char x, Node *left, Node *right){
  Node *p = (Node*) malloc(sizeof(Node));
  p->x = (char) x;
  p->izq = left;
  p->der = right;
  return p;
}

void printcArbol(Node *a) {
  if(a == NULL) return;
  printcArbol(a->izq);
  printf("%c ", (char) a->x);
  printcArbol(a->der);
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
  printf("%c\n", root->x);

  printTree(root->izq, space);
}

int main(){

  printf("===============================================\n\n");

  Node *t1 = createNodeT('s',
      createNodeT('r', NULL, NULL),
      createNodeT('u',
        createNodeT('t', NULL, NULL),
        NULL));

  Node *t2 = createNodeT('s',
      createNodeT('r', NULL, NULL),
      createNodeT('u',
        createNodeT('t', NULL, NULL),
        NULL));

  Node *b = createNodeT('v', NULL, createNodeT('w', NULL, NULL));

  printf("Árbol a del enunciado \n");
  printTree(t1, 0);
  printf("\n\ninorder: ");
  printcArbol(t1);
  printf("\n\n");

  printf("Árbol b del enunciado \n");
  printTree(b, 0);
  printf("\n\ninorder: ");
  printcArbol(b);

  printf("\n\nreemplazarNodoK(&t, 4, b) = %d\n", reemplazarNodoK(&t1, 4, b));
  printTree(t1, 0);
  printf("\n\ninorder: ");
  printcArbol(t1);

  printf("\n\nreemplazarNodoK(&t, 2, b) = %d\n", reemplazarNodoK(&t2, 2, b));
  printTree(t2, 0);
  printf("\n\ninorder: ");
  printcArbol(t2);

  printf("\n\n===============================================\n");

  return 0;
}
