# Catedra 7, 1 de abril

## Antes de introducir la materia, veamos una funcion

La siguiente funcion, tenemos el caso donde (primer print) retorne (o mejor decido imprima) `"hola"`, sin embargo, del segundo print podemos esperar cualuqier cosa antes que el hola.

``` c
char *copy(char *s) {
  char res[strlen(s) + 1];
  return strcpy(res, s);
}

void main() {
  char *res = copy("hola");
  printf("%s\n", res);
  printf("%s\n", res);
}
```

Considerando el tiempo de vidade una variable, esta se definde desde que se define una variable hasta que se destruye. Este *destruir* es un problema, puesto a que nosotros consideramos que una variable se destruye cuando sale de su bloque de codigo (cuando sale de las `{}` del codigo). Por ejemplo, tomemos una funcion como:

``` c
int fn() {
  int n = 0;
  while (n<10) {
    int j = 10;
    n++;
  }
}
```

La variable `n` es creada cuando se define `int n` y solo se mantiene con vida cuando mientras este dentro del os `{}`, mientras que el caso de la `j` ocurre que esta dentreo de los `{}` del while, lo cual significa que se mantiene  vivo dentro de los `{}` del while.

Ahora, volviendo al codigo con la funcion `copy`, en este caso la variable se destruye, sin embargo la informacion guardada en la memoria de la variable permanece con vida, esta libre para usarse, pero hasta que no se cambie permanece con el ultimo agregado. Especificamente, se queda apuntando al espacio de memoria que esta libre pero nunca se sobreescribio.

## Memoria

La memoria se divide en tres segmentos (*de los cuales veremos solo dos en el curso*): un segmento donde esta el codigo creado y compilado, otro llamado datos y el tercero llamado pilas.

| Codigo | Datos | Pila |
|-|-|-|

Donde en "Codigo" se guardan todas las lineas de codigo (*en binario*) mientras que en pila todas las variables conocidas, las variables locales.

Cuando un pc compila, reserva los espacios en una pila donde estaran alocada la informacion. Los bytes relacionados con la implementacion son guardados en un registro de activacion que despues empezara a agregar al informacion en la pila.

Para trabajar bien con todas estas mañas, tenemos lo que se llama "variables dinamicas" (*variable global para nosotros*), lo cual son variables que no se destruyen una vez utilizada dentro de un codigo. Una de las gracias es que, podemos definir variables globales o dinamicas tanto fuera como dentro de funciones y seguiran existiendo afuera. Este tipo de variables hay que destruirlas manualmente. Estas variables se crean usando una funcion llamada `malloc` dentro de la libreria `stdlib.h`. Malloc recibe la cantidad de bytes que debe reservar y tiene una firma que se asemeje a :

``` c
#include <stdlib.h>

void * malloc(int len);
```

Malloc retorna un "punteor opaco", el cual puede ser de cualquier tipo de variable la cual, su clase de puntero dependera de la variable asociada al malloc, ejemplo:

``` c
int * n = malloc(20);
```

Donde en este caso, los 20 bytes de memoria se asumiran que son del tipo `int`.
