# Catedra 2, 13 de marzo

## Tipos de datos en C (aunque en verdad una introduccion)

En el lenguaje ```C``` tenemos dos tipos de datos "primitivos" (*segun la profe los que usaremos para resolver nuestra primera tarea*). Estos son los tipos de datos que vienen en ```C```. Despues veremos como se crean nuevos tipos, para esto se utilizan estructuras. En esta clase veremos los tipos de datos primitivos.

```C``` ademas tiene la capacidad de inferencia de tipos, esto es, dependiendo de los tipos usados en una operacion, el compilador puede inferir el tipo de dato resultante. Por ejemplo, si sumamos dos enteros, el resultado sera un entero. Si sumamos un entero con un flotante, el resultado sera un flotante. *Esto puede ser usado en la tarea para ver como esta funcionando*.

En ```C```, al igual vimos en otros lenguajes tenemos las expresiones y operadores, estos son +, -, *, / y operadores binarios. En las expresiones tenemos una serie de reglas de precedencia para mantener la coherencia matematica y orden, ```C``` en caso de no tener parentesis (o incluso si tenemos) intentara inferir que tipo de operacion queriamos hacer (cuidadito).

`C` es un lenguaje tipado, esto es, cualquier de los 7 tipos en `C` debe ser declarado para cada variable. Estos datos son:

## Tipos de datos, formalmente

### Enteros

Existen dos tipos:

1. Enteros con signo (c/s): van del negativo al positivo (- o +)
2. Enteros sin signo (s/s): solo positivos (+)

Formalmente:

|Enteros (c/s)|Enteros (s/s)| Tamaño|
|-|-|-|
|Char[^1] | unsigned char| 1 byte |
| Short | unsigned short |2 bytes |
| Int| unsigned int| 4 bytes |
|Long |unsigned long | 8 bytes|
| Long Long|unsigned long long | 8 bytes|

Donde el tamaño de un byte esta dado por 8 bits (*aunque puede cambiar dependiendo de la arquitectura*). Para este ramo utilizaremos mas que nada `Int` y `Long` *esto para los enteros*. Para el caso de enteros sin signo, se agrega el `unsigned`, esto para utilizar el bit mas significativo como parte del numero en vez del signo (**si no mal recuerdo el bit mas significativo corresponde al de mas a la izquierda...eso intente decir xd**).

### Reales

Existen dos tipos de formas para representar los reales (*asumiremos siempre con signo*):

|Reles |Tamaño |
|-|-|
|double | 8 bytes |
| float | 4 bytes |

En los numeros reales, generalmente usaremos double *para irnos a la segura*.

## Ordenamiento de tipos

Los tipos pueden ser ordenados en tamaño, esto esta dado por:

$char < short < int < long < long long < float < double$

Siendo ordenado desde el que tiene menos bytes al que tiene mas bytes, donde los reales tienen una mayor jerarquia que los enteros. Esto es importante porque los tipos deben calzar para realizar las operaciones, si no **cosas feas pueden pasar**

`C`, a diferencia de otros lenguajes como `python` no tiene tipos booleanos (`bool`). Para identificiar cual es cual se usan numeros, donde $0$ correspondera `false` mientras que cualquier (**literal cualquier otra wea parece**) sera un `true` (ejemplo: enteros que no sean $0$ o un `string`).

Hagamos un ejemplo haciendo una funcion factorial en `C` ($n!$)

```c
// tipo nombre_funcion() {}
int factorial(int n) {
  // tipo nombre_de_variable = valor;
  int res = 1;
  while(n > 0) {
    // como res ya lo declare, no es necesario re declararlo
    res = res*n;
    n = n - 1;
  }
  // retornamos como en python
  return res;
}
```

Para hacer una funcion en `c` debemos empezar con el tipo que queremos que retorne, y en los valores que recibe tambien debemos declarar los tipos. En las funciones, en vez de jerarquia por tabs, tenemos jerarquia por brackets. IMPORTANTE: finalizar cada linea con el semicol (*y si, se puede hacer un codigo entero en una sola linea xd*).

Ahora, intentemos usando los "booleanos" de `c`:

``` c
int factorial(int n) {
  int res = 1;
  // while 1 es como un while true
  while(1) {
    // Para esto tenemos que usar condiciones de quiebre, esto con condiciones
    if (n == 0) {
      break;
    }
    res = res*n;
    n = n-1;
  }
}
```

Donde los condicionales tambien tienen lo que realizaran en parentesis.

`c` puede escribirse de forma abreviada, donde algunas operaciones pueden ser reescritas como la operacion antes del igual (**como en python**). De esta forma:

|i = i + n | i = i - 1| i = i * n| i = i / n[^2]|
|-|-|-|-|
|i += n| i -= n |i *= n | |
| |i--[^3] | | |

Finalmente, la representabilidad (o como se escriba) de valores se puede representar numericamente desde:

|Entero c/s | Maquina de 64 bits| tamaño|
|-|-|-|
| char | $[-2^7, 2^7[$ |1 byte |
| short | $[-2^{15}, 2^{15}[$|2 bytes |
| int| $[-2^{31}, 2^{31}[$|4 bytes |
|long | $[-2^{63}, 2^{63}[$| 8 bytes (4 si es de 32 bits)|
| long long | $[-2^{63}, 2^{63}[$| 8 bytes|
|Entero s/s | Maquina de 64 bits| tamaño|
|-|-|-|
| unsigned char | $[0, 2^8[$ |1 byte |
| unsigned short | $[0, 2^{16}[$|2 bytes |
| unsigned int| $[0, 2^{32}[$|4 bytes |
| unsigned long | $[0, 2^{64}[$| 8 bytes (4 si es de 32 bits)|
| unsigned long long | $[0, 2^{64}[$| 8 bytes|

En `c`, si llegamos a un valor que tenga un tamaño mayor al de la representabilididad, `c` no falla pero si tiene un overflow.

---
[^1]: *char es un numero que puede representar caracteres tambien, de manera general, representa caracteres (complicaciones con ASCII). En ASCII todos los caracteres son (o deberian ser) numeros positivos.*
[^2]: **Este no estoy seguro xd**
[^3]: **Creo que solo cuando se resta 1 (POR AHORA)**
