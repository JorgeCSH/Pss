# Catedra 4, 25 de mazo

## Empezemos con matraca de bits

Sea la funcion en `c`:

``` c
unsigned int redcortar(unsigned int x, int i, int j) {
  // Escriba aqui la funcion 
}
```

La cual tiene que recortar un binario, esto es dado un bit de inicio `i` tenemos que recortar los `j` en hexadecimal.[^1] Esto es, si tenemos un valor como `0x12345` con `i = 4`y `j = 12` debemos retornar `0x12` ($[i, j[$). Para esto voy a necesitar dos mascaras, una para extraer los bits desde el bit 0 hasta el bit `i-1`, donde 0 corresponde al bit menos significativo, ejemplo: `0x12345`, `i=4`, `j=12`, entonces extraemos el `5`. Despues vamos a necesitar otra mascara para rescatr/extraer los bits desde el bit `j` hacia la izquierda, ejemplo anterior: del 2 al 1.
Asi, programando lo pedido:

``` c
unsigned int recortar(unsigned int x, int i, int j) {
  /* Mascaras */
  // Mascara 1, extrae el lado derecho que yo quiero
  unsigned int mask1 = ~((-1) << i);
  // Mascara 2, extrae el lado izquierdo, aca son 32 - j porque los int son de 32 bits de largo
  unsigned int mask2 = ((-1) << j);
  // Segunda opcion de mascara para el segundo caso 
  //unsigned int mask2 = ~((unsigned int)(-1) >> (32 - j));
  
  /* Aca extraemos */
  // Lado derecho, cuidado, queda desplazado 
  unsigned int der = x & mask1;
  // Lado iquierdo
  unsigned int izq = x & mask2;
  
  // Retornamos, recordar que el valor de la derecha queda desplazado, hay que arreglarlo
  return der | (izq >> j-i);
}
```

- La mascara 1: necesitamos recuperar el lado derecho, es decir, queremos recuperar desde el bit `0`` hasta el bit`i-1`, es decir, para el lado que quiero extraer, necesitamos puros 1s en ese lado, i.e. necesitamos`i` bi1ts que sean 1.

- La mascara 2: para la mascara 2 necesitamos que sean 1s en el lado izquierdo, es decir, `32-j` 1s. Para esto tenemos dos opciones (**ambas en el codigo**), la primera es usar una mascara de puros 1s y desplazarlo para hacer aparecer 0s

## Punteros en `c`

Primero, ¿Que es un puntero?, ANTES (xd), hablemos de las variables. Las variables son todo lo que se puede inicializar (`int x = 69` inicializado, `int x` no esta inicializado) con un tipo, a estas variables, el computador le asigna un espacio de memoria representada como:

    tipo
  |------|

x |valor |

  |------|

La variable tiene: un valor, una direccion de memoria (espacio en el almacenamiento) y un tamaño (bytes). Para acceder a una variable simplemente usamos el nombre que le dimos, en este ejemplo, es llamar a `x`. Para calcular el tamaño tenemos en `c` una funcion llamada `sizeof(x)` la cual nos da el tamaño, en este ejemplo: `sizeof(x) = 4`. Para la direccion de variable debemos usar el operador amplesamp, el cual nos arroja la ubicacion de la variable.

Ahora **si**, los punteros son variables que apuntan a otras variables (*o segun el profe almacena otras variables/apuntan a otras variables). Esto quiere decir, si tenemos la variable x, el puntero se representa como[^2] (**todo un artista):

                tipo
              |------|

  O ------->x |valor |

              |------|

En `c`, los punteros se inicializan y representan con asterizco, el cual apunta a las variables que apuntan a toda variable del tipo dado. En `c`:

``` c
int x = 5;
int *p; 
int *p = &x;
```

Caracteristicas de los punteros:

- Valor: `=> p`
- Valor referenciado: `*p` (desreferencia)
- Direccion de memoria: `&p`
- Tamaño (bytes): `sizeof(p) => 8`

[^1]: lo dijo la profe: para un valor de 4 digitos, quitar la posicion 1 requerimos una mascara de largo 4 (en la unidad de medida que sea necesaria). Ademas, recordar que el -1 corresponde a puros 1s en bits. *Ademas recordar que para extraer siempre usar el `&`*.
[^2]: se puede dibujar mejor a manito xd
