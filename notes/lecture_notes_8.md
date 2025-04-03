# Catedra 9, 3 de abril

## Antes, un ejercicio

Modificando string:

``` c
void eliminarChar(char *str, char x) {
  /* Puntero  que apunta a str, este lo que hace es 
  copiar/mantener la informacion que me seirvir */
  char *copy = str;
  char *check = str; // Este compara char str con x.

  /* Ciclo mientras aun no se llegue al final del 
  string. */
  while(*check != 0) {
    /* Si el caracter es distinto a x, entonces lo 
    mantengo. */
    if (*check != x) {
      *copy = *check;
      copy++
    }
    check++;
  }
  // Una vez termine el ciclo.
  *copy = 0; // Fin del string.
  return ;
}

```

Ahora, implementemos el mismo ejercicio pero usando `malloc`:

``` c
char *eliminados(char *str, char x) {
  /* Primero contamos los caracteres que debe tener 
  el nuevo stirng, por ende ocupara mas tiempo. */
  char *check = str;
  int len = 0; // Permite ir contando el largo del nuevo string.
  while(*check != 0) {
    if(*check != x) {
      len++;
    }
    check++;
  }

  /* Ahora podemos generar el espacio del nuevo string. */
  char *new = malloc(len + 1);

  /* Aca rellenamos el string, esto siguiendo la misma idea 
  del metodo original. */
  char *copyNew = new; // Copiando char que sirven.
  check = str; // Recorrer str.

  while(*check != 0) {
    if(*check != x) {
      *copyNew = *check;
    }
    copyNew++;
  }

  /* 0 final. */
  *copyNew = 0;
  return new;
}
```

## Estructuras

Las estructuras en `c` corresponden a variables de tipo compuesto *que se comportan similar a las clases*. Para crear una estructura en `c` lo que debemos hacer es usar el comandoa (?) struct:

``` c
struct nombreDeLaEstructura {
  tipo_1 campo_1;
  tipo_2 campo_2;
}
```

Como ejemplo de implementacion podemos usar los numeros complejos:

``` c
struct complejo {
  double real;
  double im;
}
```

O para almacenar la info de una persona:

``` c
struct persona {
  char* nom;
  char* rut;
  int edad;
  char genero;
}
```

Cuando usamos las estructuras, su nombre correspondera al tipo precedido por `struct`, entonces si tomamos nuevamente el numero complejo para crear una variable deberiamos hacer:

``` c
struct complejo x;
```

Para inicializar variables, lo que tenemos que tomar es la variablecon anteponiendo `struct` al nombre y entre llaves implementamos los valores *en orden, donde de izquierda a derecha se va del campo 1 al n*. Esto es:

``` c
struct nombre x = {val_1, val_2};
```

Tomando nuevalemte le caso del numero complejo, para inicializar un numero como $1 + 3i = (2,3)$:

``` c
struct complejo x = {2, 3};
```

Para acceder a los parametros, usamos los `.`, igual que las estructuras en python. De esta forma para acceder habria que realizar:

``` c
x.campo_1 
```

Siguiendo el ejemplo del numero complejo:

``` c
double real_x = x.real;
double im_x = x.im;
```

Ademas, podemos renombrar tipos usando el comando  `typedef`, donde su uso esta dado por:

``` c
typedef nuevoTipo tipoOriginal;
```

Ejemplo:

``` c
typedef ull unsigned long long;

unsigned long long funcion1(void){};

ull funcion2(void){};
```

Ademas, podemos juntarlas y crear una monstruosidad como uso de `typedef struct`, esto es para renombrar estructuraas (**?**), de esta forma:

``` c
typedef struct name {
  tipo_1 campo_1;
  tipo_2 campo_2;
} nombreTipo;
```

Como ejemplo de los numeros complejos:

``` c
typedef struct complejo {
  double real;
  double im;
} com;

com x = {2, 3};
```

Las estructuras tambien pueden manejarse como punteros *las estructuras, al ser un tipo, puede usarse la mayoria de operaciones de tipos*). Para usar los punteros tenemos que hacer:

``` c  
struct nombre* var;
```

Esto es importante porque los necesitaremos para implementar funciones sobre estructuras, de esta forma (como ejemplo) una funcion para sumar complejos poria estar dado por:

``` c
void sumar(com *x, com y){
  (*x).real += y.real;
  (*x).im += y.im;
}
```

Donde el puntero debe ser usado en la estructura que queramos modificar, la cual para poder modificar su informacion, debemos desreferenciarla antes. Para implementarlo debemos pasar la direccion de memoria, de esta forma la funcion main donde ejecutariamos este proceso estaria dado por:

``` c
void main() {
  com x = {2, 3};
  com y = {1, 2};

  sumar(&x, y);
}
```
