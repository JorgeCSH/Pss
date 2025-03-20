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

Nota, hay que estar atento si negamos algun valor con signo, en ese caso cambiariamos el signo. Otra cosa, hay numeros que se pueden definir usando la negacion, como ejemplo: -1 <=> ~0.

### Operacion <<

Llamado desplazamiento a la izquierda (<-), donde la estructura esta dada por: `(numero binario) << cuantos bits desplazar`, esto quiere decir que, en un ejemplo:

``` c
0001 << 1 = 0010;
0001 << 3 = 1000;
```

Donde siempre se agrega un 0 al final (**basicamente desplazar el numero**), Importante, esto puede cambiar el signo si es que se trabaja con enteros con signo. Los valores que estan mas adelante se pierden, mientras que son rellenados por 0 al final (de pasada recordar que el bit de mas a la izquierda corresponde al mas significativo, mientras que el de mas a la derecha corresponde al menos significativo). Otra cosa importante, si desplazamos una cantidad mas grande que la del numero original (ejemplo: numero de largo 7 desplazarlo en 8), dependera de cada arquitectura de pc/OS que va a pasar, en Debian, el numero quedara igual como si nada hubiera pasado[^1]. Otra cosa importante es que al desplazar...*nos movemos musho xd**, en por 2, ejemplo (1 en binario 0001 << 1 = 0010, lo cual es 2 que, desplazando nuevamente, 0010 << 1 = 0100 = 4)[^2]. La regla de esto: $x << i \iff x*2^{i}$

### Operacion >>

Corresponde a un desplazamieno hacia la derecha, lo contrario al <<. Es una logica similar *pero un poco mas complicada*, esto porque no siempre se rellena con 0's. La estructura corresponde a una similar a la del << dada por `(numero binario) >> cuantos bits desplazar`. El como rellenar los bits depende del numero:

* Si este es del tipo `unsigned`, este siempre se va a rellenar con 0's hacia la izquierda
* Si es `signed`, este se rellenara con el bit de signo, esto eso, si desplazamos un negativo entonces lo rellenaremos con 1's hacia la izquierda, mientras que si es positivo, se rellenara con 0's.

Esto dara probleams con algunos numeros, ejemplo el -1, que permanecera igual pues; (-1) <=> 1111 1111 >> 4 => 1111 1111, lo cual es lo mismo. Sin embargo, si tomamos el -1 pero con un numero sin signo ocurrira que 1111 1111 >> 4 => 0000 1111 => 15.

``` c
-1 >> 4 = -1;
(unsigned char)-1 >> 4 = 15;
```

Importante 1, sea x un binario de n bits, x >> n se puede rellenar con 0's o 1's o se mantendra con igual. Esto es, que ocurre cuando nos desplazamos en un numero mayor al largo del numero. Es decir, siempre desplazar max (n-1) bits

Importante 2, el desplazamiento a la derecha es equivalente a una division, analogo al desplazamiento a la izquierda que era una multiplicacion. La regla de esto: $x >> i \iff x/2^{i}$.

[^1]: Importante, no desplazar mas de (n-1) bits, con n el largo del numero.
[^2]: Esto es importante porque en los controles probablemente (M U Y) tengamos prohibido usara multiplicacion y division.
