# Catedra 4, 20 de marzo

## Una pequeña introduccion

Primero, una introduccion la cual probablemente no me sirva segun la profe, tablas de latencia (ciclos = ciclos de reloj):

| Operador | Latencia |
| - | - |
| +, - (enteros) | 1 ciclo |
| * (enteros) | 3 ciclos |
| / (enteros) | 8 - 32 cilcos|
| +, -, * (reales) | 3 - 4 ciclos |
| / (reales) | 8 -64 ciclos |

La gracia de las operaciones binarias (que es lo que veremos hoy), es que puede reemplazar las operaciones 2 y 3 de la tabla, esto utilizando operaciones `&, |, ~, <<, >>`. En otras palabras, la razon por la que nos enseñan binarios es porque es mas eficiente para realizar operaciones.

Ahora, entremos a binarios....

## Binarios

Los binarios son basicamente la operacion de binarios (numeros binarios) que, recordemos que no tienen representacion en `c`. Las operaciones binarias son:

### El `&`

No confundir como el `&&` que corresponde al `y` logico, este corresponde al `y` binario y l aoperacion corresponde a la interseccion. El funcionamiento por bits esta dado por:

``` c
0 & 0 = 0;
0 & 1 = 0; 
1 & 0 = 0;
1 & 1 = 1;
```

Basicamente, a menos que sea `1`, toda operacion estaria dada por 1. ESrto permite basicamente "interceptar" los digitos de derecha a izquierda, esto en un ejemplo matematico (la tabla esta al revez, el encabezado o resultado deberia ser la ultima fila xd, **tablas de markdown qls**):

| resultado | 0010 0100|
| - | - |
| bit 1 | 0110 0101 |
| bit 2 | 1010 0110 |

Eto permite basicamente intersectar los digitos de un bit. Esta operacion puede ser realizada con bits de diferente largo, sin embargo, `c` rellena con bits a la izquierda de `0` para que sean de igual largo todos los bits.

### El |

El `tab` o `o` binario (no confindir con `||` que corresponde al "o logico") corresponde a lo que seria una union de bits. El funcionamiento esta dado por:

``` c
0 | 0 = 0;
1 | 0 = 1;
0 | 1 = 1;
1 | 1 = 1;
```

Esto es similar a una union o un `o` de bits (**xd**). Un ejemplo operando estaria dado por (**la tabla tan logica que hice**):

| resultado | 1010 1111 |
| - | - |
| bit 1 | 0010 1101 |
| bit 2 | 1000 1110 |

Ambas herramientas, (`&` y `|` permitira manipular binarios).

### El ~

Corresponde a la negacion binaria, el funcionamiento esta dado por:

``` c
~0 = 1;
~1 = 0;
```

Donde cada bit se va negando de derecha a izquierda por separado. Un ejemplo del funcionamiento estaria dado por:

| valor original | valor negado |
| - | - |
| ~(0010 1101) | 1101 0010 |

Nota, hay que estar atento si negamos algun valor con signo, en ese caso cambiariamos el signo. Otra cosa, hay numeros que se pueden definir usando la negacion, como ejemplo: $-1 \iff ~0$
