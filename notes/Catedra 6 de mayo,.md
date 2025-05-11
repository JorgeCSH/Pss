# Assembler
## Recomendaciones para el futuro control 2
- Traer las instrucciones anotadas.
- Traer anotado la ejecucion de cada comando.

## Como funciona Risc-v
Assembler Risc-v esta compuesto por:
- Label: indicada donde partir  o donde realizar salto.
- En el label esta el fragmento de codigo que son lineas codigo e instrucciones.
Un ejemplo 
En c:
``` c
int fun(int x, int a, int b) {
	return a*x + b;
}
```
En risc-v:
```s
fun:
	mul a0, a0, a1
	add a0, a0, a2
	ret
```
Donde en el formato `a, a, c` significa que a se opera con c y se guarda en a, es decir, el de mas a la izquierda es el registro donde se guarda y los siguientes son los que ese operan. Importante: en risc-v el valor que se retorna se guarda en `a0`.

Ahora veamoslo mas profundo.
## Assembler 
### Registros de RISC-V
La version que vamos a usasr es de 32 reistros de los cuales "podemos usar libremente", sin embargo, los que mas usaremos seran dos (que altiro veremos).
Los registros se anotan generalmente como `x0,_,x31`. De estos, los que mas usaremos o como los usaremos:
- `x0` => zero, el valor cero (0), es el unico con nombre exotico.
- `x10,_, x17` => registros `a`, que van del `a0,_, a7`. Estos almacenan los argumentos de la funcion. Sepase que en caso de que la funcion esta usando los regstros, estos estan siendo usado. El `a0` cumple con ser dual, esto es, ademas de ser un registro comun y corriente tambien funciona como el registro de retorno.
- `x5,_, x7, x28,_, x31` => registros "t" `t0,_, t6`, son los registos temporales de una instruccion, es decir, como las variables locales de una funcion.
- `x18,_, x27` => registros "s", porfavor nunca usar[^1], `s0,_, s11`, llamados registros resguardados de los cuales hay que restaurar el valor original del registro esto es, guardar la informacion que tenia el registro y despues de ejecutarlo hay que restaurar el valor guardado previo a su uso.
- `x1,_, x4` => registros exoticos que si usamos (o puede), donde `x1 = ra`[^2] retorno de la funcion (direccion). `x2 = sp` es un "start point" que marca el inicio de la pila de ejecucion (bien usado en otras versiones de assembler), en este curso probablemente no lo ocupemos, generalmente se usa para guardar valores en el registro de la pila de RISC-V. `x3 = gp`, para apuntar a las variables globales del codigo (muy raramente usado). `x4 = tp` (para variar tampoco ocupado) que correspone a un puntero a variables locales de un thread.

De forma resumida, los rgistros que mas vamos a usar (o deberiamos usar) son los registros `a -> a0,_, a7` y los `t -> t0,_, t6` y aveces (muy pocas veces, probablemente solo para hacer comparaciones), zero.

### Instrucciones
#### Instrucciones aritmeticas/logicas[^3]
1. Instruccion para sumar (`add`): En este tipo de instrucciones usamos registros, entonces no podemos agregar un entero (como por ejemplo), esto a menos que usemos addi, la cual si permoite (y es la forma mas facil). 
```s
sumar:
	add registro-destino, r1, r2
	addi registro-destino_val, r1, valor
```
2. Registro para guardar valores (li): para guardar un valor dentro de un registro
```s
li registro_destino, valor
; Ejemplo, guardar 5 en el 3er registro.
li a2, 5
```
3. Instruccion para restar (sub):
```s
restar:
	sub registro_destino, r1, r2; => registro_destino = r1 - r2
	subi registro_destino_val a0, a0, 5; => a0 = a0 - 5, funciona para neg tb
```
4. Instruccion para multiplicar (mul):
```s
multiplicar:
	mul registro_destino, r1, r2; => registro_destino = r1*r2
```
5. Instruccion para dividir (div):
```s
division:
	div registro_destino, r1, r2; => registro_destino = r1/r2
```
6. "Y" logico (and):
```s
sipo:
	and reg_des, r1, r2; => reg_des = r1 && r2
```
7. "O" logico (or):
```s
opo:
	or reg_des, r1, r2; => reg_des = r1 || r2
```
8. "XOR" (xor):
```s
soyenterochoro:
	xor reg_des, r1, r2
```
9. "Shift izquierda", desplazar bits a la izq (sll):
```s
comunacho:
	sll reg_des, r1, r2; => reg_des = r1 << r2
	slli reg_des, r1, valor
```
10. "Shift derecha", desplazar a la derecha (srl):
```s
facho:
	srl reg_des, r1, r2; => r1 >> r2
```
#### Instrucciones de acceso a memoria
1. Cargar desde la memoria un registro (lw[^4]): en este caso lo usamos para realizar la operacion reg_des = reg_des + r1, donde offset es un valor numerico, guardando en ese registro lo que esta en la posicion r1 + offset.
```s
aloquemos:
	lw reg_des, offset(r1)
```
	ejemplo:
```s 
lw a0, 4(a1); => *(a1 + 4)
```
	es decir, si tenemos un `int*`, entonces de tener `|0|1|2|3|`, el vlaor guardado seria de `a0 = 1`, porque nos movemos por bytes (recordar que 4 -> 1 en bytes).
2. Guardar direccion de registro (sw):
```s
sacoredacted:
	sw r1, offset(reg_des)
```
	Esto es, guardar en DIR reg_des + offset el valor de r1. Ejemplo:
```s
sw a0, 4(a1); => *(a1+4) = a0
```
#### Saltos condicionales
---
1. Caso de dos registros `r1, r2` iguales saltar al registro de label `l1` (`==`):
```s
beq r1, r2, l1
```
esto es, `if(r1 == r2) => saltar al label l1`
2. Caso de dos registros `r1, r2` diferentes saltamos al label l1 (!=):
```s
bne r1, r2, l1
```
esto es, `if(r1 != r2) => salto al label l1`
3. (y 4.) Caso registros menor (<) y mayor (>) respectivamente:
```s
blt r1, r2, l1
ble r1, r2, l1
```
esto es, `if(r1 < r2) => salto al label l1` y viceverdsa con el ble
5. Mayor o menor o igual (<=, >=):
```s
bge r1, r2, l1
```
esto es, `if(r1 >= r2) => salto a l1`




[^1]: No es que no podamos, es que es harto mucho cacho, de hecho podemos usarlos pero no es recomendados.
[^2]: Dato grep lo usa jeje.
[^3]: Usaremos "r" para denotar registro. Importante, estas operaciones siempre se consideran con signo.
[^4]: El mitico, el inigualable, el sistemas digitales.