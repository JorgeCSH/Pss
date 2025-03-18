# Catedra 3, 18 de marzo

## Continuacion de `C`

### Parentizacion de Expresiones[^2]

Tenemos diferentes reglas de parentizacion. La primera es la regla de precedencia, esto es decir, sigue el orden de las operaciones y de importancia parentizando (**basicamente papomudas sin parentesis, pomudas**), la otra opcion es hacerlo manual . Ejemplo:

| Lo que escribi | Lo que `c` interpreta |
| - | - |
| `a+b*c`| `a+(b*c)`|
| (a+b)*c | (a+b)*c |

`C`, ademas de los operadores matematicos aritmeticos comunes, tenemos otros 50 y tanto con sus respectivod ordenes de precedencia que hay que considerar. Si no estamos seguros de l aprecedencia,lo mejor es usar parentesis manualmente. Algunos de estos operadores pueden ser:

* `>>`: Operador binario para desplazar bits (exclusivo de `c`), la suma tiene mayor precenencia que el operador binario.
Los otros ejemplos quedan propuestos como ejercicio para el lector[^1]

La segunda regla de parentizacion en `c` es la asociativida, en este caso de haber operaciones de igual precedencia entonces se hace de izquierda a derecha como la suma con la resta o la multiplicacion con la division. Pero, algunos se asocian de derecha a izquierda. Ejemplo:

* El operador `=`, donde de tener una expresion como `a = b = c` esta asocia de derecha a izquierda, pues en `c` se espera que a la izquierda haya una variable y a la derecha el valor, es decir, el ejemplo se lee "'c' toma el valor de 'b' y 'b' toma el valor de la variable 'a'"
* El operador `*` tambien llamado operador desreferencia, este se usa en espacios de memoria. Este tiene la misma precedencia que el `++` y se parentisa de derecha a izquierda, asi el operador `*++a = *(++a) = ++(*a) = ++*a`.

[^1]: Lo mejor es siempre parentizar **puto**.
[^2]: `c` no es mañoso en temas de memoria ni debuggeo en caso de agregar o no parentesis **no deberia hacerse mas lentos en caso de agregar parentesis**.

### Inferencia de tipos

`c`, al momento de operar, tiene distintas formas de inferir los tipos que se estan usando. Estos son:

1. Inferencia

``` c
int a = 1;
int b = 2; 
double c = a/b;
```

En este caso, `c` revisa los tipos de los operandos, de ser todos iguales, entonces el resultado sera entero y despues se traduce al tipo que se pidio. En el ejemplo anterior, `c = 0.0` puesto a que primero se hizo una division entre enteros y despues se paso a `double` o real.
