# Aux 4, 4 de abril

## Algunas cosas del resumen

Claramente,

## P1

Mismo ejercicio de la ultima vez, solo que esta vez la funcion solucion retornara un `char*` :

``` c
void to_lower(char* s) {
  while (*s) {
    if ('A' <= *ss && *s <= 'Z') { // Recordar la comilla simple. 
      *s -= 'A' - 'a';
    }
    s++;
  }
}

char* lowerCase(char* s) {
  char *ret = malloc(strlend(s) + 1); // Aca pedimos un cacho de memoria.
  strcpy(ret, s); 
  to_lower(ret);
  return ret;
}
```

Ahora, hagamos lo mismo sin las funciones usadas antes:

``` c
char* lowerCase_variante(char *s) {
  char *recipiente = malloc(strlen(s) + 1); 
  while (*s) {
    if ('A' <= *s && *s <= 'Z') {
      *recipiente = *s + 32;
    } else {
      *recipiente = *s;
    }
    s++;
    recipiente++;
  }
  *recipiente = '\0'; // Aca incluimos el 0 al final. ESTO ES IMPORTANTE, 1 PTO DE DESCUENTO.
  return recipiente - strlen(s); // Aca devolvemos el puntero, si no estaria al extremo.
}
```

## P2

Recordemos que los arboles de busqueda binaria estan en orden o pueden ser buscadoc con ordenes. Asi, tenemos que:

``` c
Tree *initTree(char rootValue) {
  Tree *ret = (Tree*) malloc(sizeof(Tree)); // Necesitamos el espacio que ocupa la estructura para poder saber cuanto alocar.
  /* Necesio llenar con todo lo que hay al hijo izquiero y al derecho,
  esto inicialmente cero */
  ret -> left = NULL;
  ret -> right = NULL;
  ret -> val = (char*) malloc(strlen(rootValue)+1); // Primero, memoria.
  strcpy(ret -> val, rootValue); // Aca le asignamos el valor al nodo.
  return ret;
}

Tree *insertValue(Tree *root, char* value) {
  // Caso donde no debemos bajar mas 
  if (root == NULL) {
    return initTree(value);
  }
  int cmp = strcmp(value, root -> val);
  if (cmp <= 0) {
    insertValue(root -> left, value);
  } else {
    insertValue(root -> right, value);
  }
  return root;
}

void printTree(Tree* root) {
  if (root == NULL) {
    return;
  }
  printTree(root -> left);
  printf("%s\t", root -> val);
  printTree(root-right);
}

char* maxValue(Tree* root) {
  if ()
}

```
