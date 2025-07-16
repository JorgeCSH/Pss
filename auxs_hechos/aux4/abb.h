typedef struct abbTree{
	char* val;
	struct abbTree *left, *right;
}Tree;

Tree* initTree(char* rootValue); // Inicializa la estructura

Tree* insertValue(Tree *root, char* value); // Inserta un valor, retorna root. Debe agregar valores aunque esten duplicados, debe pedir memoria para cada nuevo nodo que agregue

void printTree(Tree *root); // Imprime los valores guardados en el arbol en orden creciente (recorrer en in orden, primero rama izquierda)

char* maxValue(Tree *root); // Retorna el valor maximo

char* minValue(Tree *root); // Retorn el valor minimo

char* find(Tree *root, char* value); // Busca un valor, si lo encuentra lo retorna, de lo contrario retorna NULL

void destroyNode(Tree* node); // Libera la memoria del nodo.

Tree* delVal(Tree *root, char* value); // Busca si el valor esta en el arbol, si lo encuentra lo borra y libera el espacio del nodo. Tanto si tiene o no exito, debe devolver root

void freeTree(Tree *root); // Libera la memoria utilizada por el arbol, debe hacerlo recursivamente.

