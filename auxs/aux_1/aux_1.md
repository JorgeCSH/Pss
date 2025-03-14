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
$(101010)_{2} = 1\cdot 2^{5} + 0\cdot 2^{4} + 1\cdot 2^{3} + 0\cdot 2^{2} + 1\cdot 2^{1} + 0\cdot 2^{0} = (42)_{10}$
*Una cosa, un binario si termina en $0$ es par, mientras que si no, entonces es impar (o deberia)*
