# Aux 1, 14 de marzo

## Importante para `c`

En `c`, para correr cada programa, debe existir la funcion main. Para esto puede usarse la version con `int` o con argumentos, esto es:

``` c
// Sin argumentos
int main() {
  return 0;
}

// No tener las dos en un codigo jeje

// Con argumentos 
int main(int argc, char* argv[]) {
  return 0;
}
```

Estas deben retornar `0` cuando funcione.

Cuando compilamos un codigo en `c`, este arrojara un archivo llamado `a.out`, para cambiarle el nombre lo que tenmos que hacer es correr:

``` bash
usuario@pc:~$ gcc -o nombre_del_archivo nombre_del_archivo.c
```

*En el ramo no vamos a compilar, hay una libreria del profe que compilara por nosotros....solo tendremos que programar*

Para el curso, recomendado el debugger `gdb`, en el cual podemos detenernos en la ejecucion en un codigo en la linea o funcion que queramos. **Hay mas funcionalidades que estan en el enunciado de auxiliar**. Con este debugger, entre diferentes cosas, se puede ver que valores hay guardados en una variable.

## Desarrollos

### P1

#### b) facotrial recursivo

Aca aplicaremos recursion, deberemos tener cuidado porque `c` es casi de bajo nivel:

``` c
int factorial_rec(int n) {
  if (n == 1) {
    return 1;
  }
  return n*factorial_rec(n-1);
}

 int main() {
  printf("%d\n", factorial_rec(5));
  return 0;
}
```

El programa retorna el 1 cuando se alcanza la condicion necesaria. La funcion toma un `int` y retorna otro.

#### c) Factorial iterativo

Considerando que `argv[]`, esto sirve para determinar los valores que recibira una funcion como main. Esto tomara el valor dependiendo de la posicion. Ahora, para iteradores como el for tenemos la siguiente estructura: `for(var_dec var_inicial; cond_que_debe_cumplir; sig_dat)`. De esta forma, el ejercicio queda como:

``` c
#include <stdio.h> // A la rapida en la libreria esta el printf
#include <stdlib.h> // A la rapida en la liberia esta el atois

int main(int argc, char* argv[]) {
  // Printeamos que esta en la posicion x de argv[x]
  printf("!%s  = ", argv[1]); 
  // Tomamos el valor recibido por la consola y lo pasamos a entero
  int n = atoi(argv[1]);
  int res = 1;
  for(int i = 1; i > 1; i--) {
    res *= i;
  }
  // Printeamos y printeamos un entero
  print("%d\n", res);
  return 0;
}
```

### P2

Buscamos que reciba un string que sea un binario y retorne como decimal. Para esto usaremos la ecuacion del binario, esto es con las potencias de dos, ejemplo:

$(101010)_{2} = 1\cdot 2^{5} + 0\cdot 2^{4} + 1\cdot 2^{3} + 0\cdot 2^{2} + 1\cdot 2^{1} + 0 \cdot 2^{0} = (42)_{10}$

*Una cosa, un binario si termina en $0$ es par, mientras que si no, entonces es impar (o deberia)*

Para el codigo, lo que podemos hacer es una funcion la cual, itere hasta que cumpla alguna condicion usando condicionales. Esto es:

``` c
#include <stdio.h>
#include <math.h> // funcion power
#include "archivo_que_queremos_importar.c" // Es el que sera usado como header

int decimal(int binario) {
  // Variables representaran las condiciones y la posicion del binario para aplicar la potencia, vamos del inicio al final (der a izq)
  // res: valor que devolveremos, pos: posicion actual
  int res = 0, pos = 0;
  while(binario) {
    // DISCLAIMER (yo, jorge): no se si tenemos que usar llaves para los condicionales xd
    if (binario%10) {
      // Pertenece a la biblioteca
      res += pow(2, pos); 
    }
    binario /= 10;
    pos++;
  }
  return res;
}
```

Ahora, aprovecharemos la instancia para asumir que estamos en otro archivo y lo "importaremos" usando los headers a otro archivo con la funcion main. Para esto, donde este la funcion main:

``` c
#include <stdio.h>
#include <stdlib.h>
#include "archivo_que_queremos_importar.c" // Header que usaremos donde esta el archivo

int main(int argc, char* argv[]) {
  int n

}
```

Para importarlo usaremos un `header`, esto usando `#include` pero en vez de `<>`, las comillas. Esto debe usarse en ambos archivos y debe compilarse el main **y hacer otra magia para compliar el otro archivo[^1]**. Asumiendo que los nombres de los archivos son `p2.c y decimal.h` (el `.h` es porque es header **creo**), para compliarlo:

``` bash
me@pc:~$ gcc -0 p2.c 
```

**NO LO ALCANZE A TERMINAR DE ANOTAR**

[^1]: Alguna de las opciones para compilar se debia usar.
