#include <stdlib.h>
#include <stdio.h>

// estrutura de nodo para p1
typedef struct node{
	int x;
	struct node* sgte;
} Node;

// función append que recibe el primer nodo de una lista a
// y enlaza b al final de esta
void append(Node **pa, Node *b){
	Node *a = *pa;

	// caso base: la función recibió un puntero al final de una lista
	if (a == NULL){
		*pa = b; // el puntero recibido ahora apunta a b
		return;
	}

	// si aún no estamos al final de la lista, la recorremos
	append(&(a->sgte), b);
}


// utilidades para el test con el ejemplo del enunciado
Node *createNodeL(int x, Node *next){
    Node *a = (Node*) malloc(sizeof(Node));
    a->x = x;
    a->sgte = next;
}

Node *createNodeList(int *list, int size){
    Node *n = malloc(sizeof(Node));
    n->x = *list;
    if (size > 1) {
        n->sgte = createNodeList(++list, --size);
    } else {
        n->sgte = NULL;
    }
    return n;
}

void printNodeList(Node *nlist, int size){
    if (nlist == NULL)
        return;

    if(size > 1)
        printf("%d -> ", nlist->x);
    else
    printf("%d -> NULL\n\n", nlist->x);

    printNodeList(nlist->sgte, --size);
}


// main que prueba la función append con el ejemplo
// del enunciado
int main(int argvc, char* argv[]){

    printf("===============================================\n\n");

    printf("> a y b listas no vacias\n");
    int l1[] = {3, 1}, l2[] = {7, 8, 4};
    Node* a1 = createNodeList(l1, 2);
    Node* b1 = createNodeList(l2, 3);

    printf("lista a:\t");
    printNodeList(a1, 2);

    printf("lista b:\t");
    printNodeList(b1, 3);

    printf("append(&a, b):\t");
    append(&a1, b1);
    printNodeList(a1, 5);

    printf("> a una lista vacía y b una lista no vacía\n");
    Node* a2 = NULL;
    Node* b2 = createNodeList(l2, 3);

    printf("lista a:\t");
    printf("NULL\n\n");

    printf("lista b:\t");
    printNodeList(b2, 3);

    printf("append(&a, b):\t");
    append(&a2, b2);
    printNodeList(a2, 3);

    printf("===============================================\n");

    return 0;
}
