# Catedra 6, 27 de marzo

## Recuerdo clase pasada

Punteros corresponden a variables que apuntan a la direccion de memoria de otras variables. Recordemos que, para operar con ellos:

- Inicializarlo: `int px = &x`.
- Direccion de memoria x: `Px`
- Valor almacenado: `*Px`

## Nuevo

Los arreglos poseen un puntero, los cuales se tratan de valores en espacio de memoria consecutivos. Los arreglos en `c` se escriben con los `[]`. Ejemplo:

``` c
int a[] = {valor_1, valor_2, valor_3};
```

Lo cual corresponderia a lo mismo que `int*a`, donde los valores estan dentro de las llaves `{}`. ¿Que es lo que hace `c`? `c` lo que hace es acomplar espacios de memoria con el mismo largo que la cantidad de valores en el arreglo, donde `c` lo apunta inicialmente siempre al primer valor del puntero, donde cada variable almacenada es una variable del tipo `int`. De esta forma, si tenemos algo del estilo:

``` c
int a[] = {1, 2, 3, 4};
*a;
```

`*a` apuntara a `1` en un inicio.
Para operar con punteros tenemos dos formas:

### Forma facil[^1]

Acceso de los elementos *como en python*, esto es, accediendo con los subindices, de esta forma, si tenemos algo del estilo:

``` c
int a[] = {valor_1, valor_2, valor_3, valor_4};
a[0]; // => valor_1
a[3]; // => valor_4 
```

Basicamente, usar el i-esimo elemento.

### Otra aritmetica de punteros (i.e. forma no facil)

Esto significa operar con punteros, especificamente, mover punteros. Tenemos tres opciones que se basaran en el siguiente ejemplo para no escribirlo a cada rato:

``` c
int a[] = {1, 2, 3 4};
```

Opcion 1: aprovechar el subindice para saber que el `a[0]` sabiendo que es la direccion del priemr elemento e ir sumando para mover la direccion, entonces `a[0] = *(a + 0) => 1`, podemos sumarle y tendremos que `*(a + 2) = a[2] => 3`.

Opcion 2: basada en la opcion 1, esta se trata de acceder a un i-esimo elemento de la forma `*(a + i) = a[i] => i-esimo elemento`

Opcion 3: la mas dificil (y por ende la que van a usar (**gracias cuerpo docente :)**)), corresponde a desplazarnos por los espacios de memoria uno por uno. Tambien esta inspirado en los anteriores, sin embargo en este caso solo es de uno en uno, esto de la forma `a[1] = *(a + 1) = *(a++)` donde tenemos el analogo con `a--`. Esto sera lo que usaremos para la tarea de `strings`.

Ahora, al trabajar con `c` tenemos algunas mañas con el tamaño puedo a que no sabemos a priori el largo del arreglo:

- Sabemos el largo del arreglo cuando lo inciamos: `int a[] = {1, 2, 3, 4}`.
- Inicializar un arreglo, esto crea un arreglo[^2] vacio con una cantidad i de espacio, ejemplo: `int a[i]` aloca i espacios de memoria para un arreglo de largo i.

ALgunos ejemplos de como inicializar arreglos:

``` c
/* Inicializar arreglo con rellenado de memoria (?). */
int largo = 4;
int a[largo];
for(int i = 0; i < largo; i++) {
  // Alocamos un valor en la i-esima posicion del arreglo, en este caso, 0.
  a[i] =0;
}
```

``` c
/* Inicializar arreglo con punteros....lamentablemente la que deberemos usar en strings xd. */
int largo = 4;
int a[largo];
for(int i = 0; i < largo; i++) {
  // Lo que hay en la memoria en la posicion i-esima lo igualamos a 0, le damos un valor.
  *a = 0;
  // Acanzamos el puntero.
  a++;
}
```

Tambien existen los punteros auxiliares, estos son punteros usados para desplazarnos por un arreglo sin utilizar el puntero original, asi evitar avanzar, mover o **directamente cagarla**. Estos puntero auxiliares se declaran de la siguiente forma:

``` c
int a[4];
// puntero que igualamos al puntero inicial, apuntando a lo mismo que apunta a.
int *aux = a;
```

¿Que es lo que quiere decir esto? basicamente, creo un puntero `aux` que apunte a lo mismo que apunta `a`.

Ahora, volviendo a lo anterior, el incremento en el punteor puede resumirse en una operacion que llamaremos posincremento, la cual esta dada por: `*a++` y pre incremento `*++a`, en la primera primero asigno y despues me desplazo, en la segunda me desplazo y despues asigno. Esta operacion tambien funciona con resta `*a--` y `*--a`:

[^1] Si, el cuerpo docente nos hara usar la ***OTRA*** opcion.
[^2]: En `debian 12` deberiamos de estar rellenos de `0`'s.
