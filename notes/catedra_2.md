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
|Char | unsigned char| 1 byte |
| Short | unsigned short |2 bytes |
| Int| unsigned int| 4 bytes |
|Long |unsigned long | 8 bytes|
| Long Long|unsigned long long | 8 bytes|

Donde el tamaño de un byte esta dado por 8 bits (*aunque puede cambiar dependiendo de la arquitectura*). Para este ramo utilizaremos mas que nada `Int` y `Long`. Para el caso de enteros sin signo, se agrega el `unsigned`, esto para utilizar el bit mas significativo como parte del numero en vez del signo (**si no mal recuerdo el bit mas significativo corresponde al de mas a la izquierda...eso intente decir xd**).
