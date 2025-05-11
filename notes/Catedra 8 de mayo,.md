# Assembler 
## Assembler (continuacion)
### Instrucciones (continuacion)
#### Misc[^1]
1. Salto no condicional: esta realiza un salto al label 1 (L1)
``` s
j L1
```
2. Inicializar (mal dicho) registro con otros:
``` s
mv reg_des r1; => reg_des = r1
```
3. Inicializar registros con constantes:
``` s
li reg_des valor; => reg_des = valor
```
4. Llamada a otra funcion:
``` s
jal ra, L1; => donde siempre reg ra es el que se va a ejecutar (?)
```

OJO: cuidado con `mv` y `lw`, estos son diferentes[^2] y podemos realizar la comparacion con `c` :
En c (se salto la linea 3):
``` c
/*1*/
int a = 5, z = 6;
/*2*/
int b = a;
/*3*/
int *c = &b;
/*4*/
*c = z;
/*5*/
a = *c;
```
En assembler:
``` s
; 1
li t0, 5; int a =5
li t1, 6; int z = b
; 2
mv t2, t0; int b = a
; 3
sw t2, -28(sp); c = &b
l2 t3, -28(sp); c => t3
; 4
sw; c<=>t3, t3 = t1
; 5
lw t2, o(t3); guradamos lo que hay en t3 en t0
```

### De C a Assembler
Aca vimos una serie de transcripcion de instrucciones de `c` a `Assembler`. Estas no las anote porque se me paso, sin embargo me ubique cuando ibamos por arreglos:
#### Condicional
#### Ciclos iterativos
#### Arreglos
En esta parte implementaremos el equivalente de los arrelgos en `c` pero en assembler, para esto usaremos el shift pues es mas eficiente (se puede usar el mv ve pero efciencia baja, idealmente hacerlo en con `sll` y equivalentes). De esta forma, tenemos que el equivalente:
En c:
``` c
int a[] = {};
int x = a[i];
```
En assembler:
``` s
; Assembler
; i = a0, a o a1
sll t0, a0, 2 ; => t2 = a0 << 2, a0 * 4 (donde a0 podemos decir que es i y a porque es arreglo de 4 bytes)
add t1, a1, t0; =>  t1 = a + i*4
lw t2, o(t1); => t2 = *(a + i*4)
```
Donde las primeras dos lineas de codigo en la version en assembler lo que hace es dirigirse al i-esimo elemento de a.
#### Llamado de funciones[^3]
Lo que buscamos es llamar a funciones (o creo que lineas de codigo) como lo hacemos en c pero en assembler, para lo cual lo que tenemos que hacer es mover los valores al registro, y despues llamarlos a la funcion (donde asumiremos para este ejemplo que `fun` es una funcion que existe). Viendo en codigo:
En c:
``` c
int x = fun(a, b, c);
```
En assembler:
``` s
; a = t1, b = t2, c = t3
; Movemos los parametros a los registros.
mv a0, t1
mv a1, t2
mv a2, t3
; Llamamos a la funcion (la cual retorna el valor en a0 y a0 => vive x)
jal ra, fun 
; Asociamos el valor en un registro t4 => x = fun(a, b, c)
mv t4, a0
```
#### Estrcuturas
Tambien podemos un "analogo" a las estructuras de `c` 
En c:
``` c
struct nodo {
	int x; // => 4bytes
	struct nodo*prox;
}
```
En assembler: 
``` s
; x = t0
lw t1, 4(t0); t0 + 4, donde t0 es el puntero a la estructura.
```
En la version de assembler, el `t1` corresponde a un analogo de `x->prox`,  ademas, en controles de llegar a preguntarlo podemos asumir que los int son de 4bytes. 
#### Funciones
Las funciones se crean implementando labels, para esto tenemos el analogo:
En c:
``` c
int f(a param, b param, ...) {
	/* Instrucciones */
	return x;
}
```
En assembler:
``` s
fun 
	; En a viven los parametros, en x vive t-
	mv a0, t0
	ret
```
Donde la instruccion final corresponde a mover o colocar el valor retorno en el `a0`.

[^1]: Indicacion: todo en assembler se debe hacer en un archivo, no existe el "heather" como en `c`.
[^2]: Esto porque aveces lo usamos (apuntando a nosotros*) como si fueran la misma custion.
[^3]: Importante: `ret` corresponde a la parte donde termina la ejecucuin (return).