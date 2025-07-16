<<<<<<< HEAD
# Catedra 11, 22 de abril

## Datos freak que parece deberian ser materia

### Memoria

Regla de alineamiento de `c`: corresponde a las reglas con que `c` ordena la memoria del computador. Esta regla dice que el $1^{er}$ espacio de memoria de la variable debe ser multiplo del tamaño de la variable. Por ejemplo, si tenemos un `int x`, este es de 4 bytes que debe encontrar de manera consecutiva, despues verifica que el $1^{er}$ espacio de memoria sea multiplo de 4, de esta forma se hace mas sencillo acceder a las variables. Esta regla tambien se puede aplicar a estructuras (ademas de que tambien para punteros y bla bla bla), pero estructuras pasa que no es tan intuitivo, tomemos el siguiente ejemplo:

``` c
typedef struct test {
  char c;
  int x;
} T
```

Esto tiene que cumplir con la regla de alineamiento, por ende la memoria necesaria sera la suma de la memoria de cada uno de los elementos ordenandolo de arriba para abajo en prioridad de quien primero (en este ejemplo ordena `c` antes que `x`), de esta forma si seguimos el ejemplo y tenemos una memoia de 8 bytes, entonces en el espacio 1 se ubicaria la variable `c` minetras que `x` estara ubicada en el multiplo mas cercano, lo que significa que nuestra estructura por ahora necesitaria 7 bytes, 5 de tamaño y dos de desplazamiento para ubicar el int en el multiplo de 4. Mas aun, se pone en la situacion donde pueda hacerse un arreglo, en este caso se busca un indice donde el mismo patron se pueda repetir, esto es, por ejemplo, 8 (con c), (9 vacio), (10 vacio), (11 vacio), (12: con x). (13 con x), (14 con x), (15 con x), (16 con c), etc.... Esta es la razon por la cual no podemos suponer que el `sizeof(T)` donde `T` es una estructura, no necesariamente va a ser igual a la ausma del tamaño de las variables.

### Big endian/Little endian

Forma de ordenar los bits y entregar la direccion de memoria. Esto depende del procesador del computador, donde si es "big endian" entonces entrega la direccion e memoria del bit mas significativo, mientras que si es little endian entonces entregara la direccion de memoria del bit menos significativo. Por ejemplo, tomemos el siguiente codigo (big endian = bit mas significativo a la izquierda, little endian a la derecha) (**claramente no olvide copiar algo aca jejE**):

``` c
int x = 1;
int *p = &x;
return p[0];
```

De esta forma tendremos en la memoria:

| 0 | 0 | 0 | 0 | 0 | 0 | 0 | 1 |
| - | - | - | - | - | - | - | - |
| d | d+1 |   |   |   |   |    | d+7|

Entonces en un computador big endian leer d (es decir, 0), mientras que en un little endian sera d+7 (es decir, 0), actualmente no es un problema, pero antes era un problema, ya que si teniamos un archivo de texto y lo pasabamos a binario, el mismo archivo no se podia leer en otro computador. Por lo que se tuvo que estandarizar el formato de los archivos, por lo que se decidio que el formato de los archivos binarios es little endian[^1]. Para evitar esto, se creo el protocolo que dice que todo archivo tiene que mandarse en formato/codificacion big endian, por eso considermos que el bit mas significativo es el de mas a la izquierda, si es little endian entonces se le transforma a big endian (se lee alverre).

## Materia nueva: archivos

Esta materia se basa mucho en funciones de `c`, donde nos enfocaremos en manipular archivos, principlamente texto y binarios (`.txt` y `.bin`). Las funcones son:

1. Para abrir un archivo: `FILE fopen(char *filename, char *mode)`, donde todos los archivos que se trabajen seran del tipo `FILE *` y se trabajara con punteros. Los parametros que reciben son el nombre del archivo y el modo de apertura. Existen cuatro tipos de modo de escritura: "w" solo para escribir, "r" solo para leer, "a" solo para escribir pero sin dejar borrar/sobreescribir lo que hay en el archivo original (no lo limpia), "r+" para lectura y escritura (y el que mas usaremos puesto a que nos pediran escribir y/o leer), siendo siempre todo en dobles comillas. Ejemplo:
Archivo (llamado `hola.txt`):

```txt
Hola (contenido del archivo de texto)
```

```c
FILE *f = fopen("hola.txt", "r+"); // entregando un puntero al primer caracter.
```

2. Cerrar archivos: `int fclose(FILE *f);` es buena practica hacerlo, no es necesario de manera general, PERO EN EL CONTROL SI HAY QUE HACERLO, tiene puntaje (xd).

3. Lectura: tenemos diferentes casos:

3.1. Caracter por caracter: `int fgetc(f)`, retorna el caracter al cual se esta apuntando.

3.2. Para leer cadenas de caracteres: `char *fgets(char *s, int bytes, FILE *f)`, donde llamaremos buffer a `char *s` que almacena lo leido, `int bytes` la cantidad de bytes a leer y `FILE *f` el archivo. Retorna `NULL` si la lectura falla.

3.3. El que probablemente ocupemos siempre, `size_t fread(void *ptr, size_t size, size_t nmemb, FILE *f)` donde `void *ptr` es el buffer (donde almacenamos lo que leemos), `FILE *f` es el puntero del archivo, `size_t size` tamaño de bytes de 1er elemento a leer y `size_t nmemb` la cantidad de bytes al leer, el cual falla cuando le paso una cantidad de diferente de bits a la que va a leer (leyendo menos bytes/caracteres de los que va a leer).

[^1]: Gracias copilot.
=======
# Catedra 11, 22 de abril 

##
>>>>>>> origin/develop_tarea_3
