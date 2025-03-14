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
