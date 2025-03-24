#include <stdio.h>
#include <stdlib.h>

#include "dup.h"
// Aca es done despues tengo que reemplazar por la funcion
/*
unsigned long long dupMasLargo(unsigned long long x) {
  // ... programe aca la funcion pedida ...
}
*/

/* Funcion que cuenta la cantidad de bits
Funcion que cuenta la cantidad de bits que tienen un numero.
La gracia es despues ser usada para ver numeros con cantidad par e impar.
*/
int contador(unsigned long long x) {
  // Definimos el contador
  int n = 0;
  /* Aca tengo unos prints porque debuggear es pa weones
  printf("Valor original: x = %d", x);
  printf(" y contador en estado inicial: n= %d", n);
  */
  while (x!=0) {
    x = x>>1;
    n++;
    /* De nuevo, debuggear es para weones
    printf("\nx= %d", x);
    printf("\nn = %d", n);
    printf("\n");
    */
  }
  // printf("La cantidad de bits que hay es de: %d", n);
  return n;
}


/* Funcion para intentar retornar secciones
Funcion donde tomamos el extremo derecho de un numero en sus respectivos bits.
Esta funcion discrimina si el numero tiene una cantidad par o impar, esto es, si la cantidad es par
basta con obtener la mitad derecha (por eso el invariante m suma de a 2), si es impar, tenemos que deshacernos del
bit mas significativos.
Ejemplo:
0b101010, retorna 0b101
0b1101010, retorna 0b101
(Si, en este ejemplo retorna lo mismo....)
*/
unsigned long long sex(unsigned long long x, int n) {
  // Variable m, simboliza el doble del largo, asi solo realizamos la mitad de iteraciones.
  int m = 0;
  // Variable l, tiene el proposito de desplazar bits en la mascara en caso de que sea impar.
  int l = 0;
  // Aca obtenemos la mitad derecha de los numeros en bits.
  unsigned long long lado_derecho = x;
  while (m < n) {
    // Avanzamos de una para ver si llegamos al final o no.
    m += 2;
    // Aumentamos la cantidad de bits del largo de la mascara.
    l++;
    // Condicional 1, este se activa si el largo del numero es impar en bits.
    if (m > n) {
      // Creamos la variable de la mascara, esta debe valer solo 1 si es impar.
      unsigned long long purge_mask = x >> n-1;
      // Aca desplazamos, tendremos un numero potencia de 2 con un largo igual al del extremo derecho
      purge_mask = purge_mask << l-1;
      // Aca negamos el valor, asi el bit mas significativo hace poof.
      lado_derecho = lado_derecho & (~purge_mask);
    } else {
      // Si es par da lo mismo, obtendremos de una el valor.
      lado_derecho = lado_derecho >> 1;
    }
  }
  return lado_derecho;
}

// Funcion main que despues hare desaparecer por pvto
void main(){
  // variable que consideraremos para las pruebas
  unsigned long long x = 0b1101010;
  unsigned long long largo_x = x;
  // Aca probamos el contador, que gran avance!
  int n= contador(x);
  printf("La cantidad de bits que es: %d", n);

  unsigned long long lado_derecho = largo_x;
  unsigned long long lado_izquierdo = largo_x;

  lado_derecho = sex(x, n);
  lado_izquierdo = lado_derecho;
  int j = 0; 
  while (j<n) {
    lado_izquierdo = lado_izquierdo << 1;
    j += 2;
  }
  
  unsigned long long x_temp = x;
  unsigned long long purgador = 0b1;
  if (j>n){
    purgador = purgador << n-1;
  }

  printf("\nEl purgador: %d", purgador);
  printf("\nEl valor sin purgar: %d", x);
  printf("\nEl valor despues de la purga: %d", x & (~purgador));

  printf("\nEl lado derecho deberia estar dado por: %d", lado_derecho);
  printf("\nMientras que el lado izquierdo: %d", lado_izquierdo);

}


/* TO DO:
  - Intentar purgar el bit mas significativo de una cuando tenga una cantidad par, asi tendria que hacer mucho a cada
    rato si es que es una cantidad impar al buscar el lado derecho.
  - Idea de desarrollo: usar el lado derecho para deshacerme del lado izquierdo, si es que este es igual al mismo numero
    pero con los valores eliminados en 0, entonces es, esto es:
    (x >> cant_bits_mitad) << cant_bits_mitad == x & ~(mitad_derecha)
    (digo mitad derecha porque no se si ese es el termino o sirve con decir mascara xd). (creo que no sirve)
*/
