#include <stdio.h>
#include <stdlib.h>

#include "dup.h"
// Aca es done despues tengo que reemplazar por la funcion
unsigned long long dupMasLargo(unsigned long long x) {
  // Primero veremos si el numero tiene una cantidad par de bits
  unsigned long long x_modificado = x;

  int n_total = 0;
  int n_decididor = 0;

  unsigned long long i = 0;
  unsigned long long j = 0;

  unsigned long long valor_contador = x;
  while (x!=0) {
    valor_contador = valor_contador >> 1;
    n_total++;
  }

  while (n_decididor < n_total) {
    n_decididor += 2;
    j += 2;
    i++;
  }

  // Caso donde es impar, en otro caso, se salta
  if (n_decididor > n_total) {
    unsigned long long par_mask = 0b1 << n_total;
    x_modificado = x_modificado & (~par_mask);
    j -= 2;
    i--;
  }
  unsigned long long patron;
  int k = 0;
  while (k < n_total-1) {
    // Mascara lado derecho
    unsigned long long mask1 = ~((-1) << i);
    // Mascara lado izquierdo
    unsigned long long mask2 = ~((-1) << j);
    unsigned long long der = x_modificado & mask1;
    unsigned long long izq = x_modificado & mask2;
    patron = izq | der;
    k +=2;
  }

}

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

  unsigned long long x = 1010101;
  // Primero veremos si el numero tiene una cantidad par de bits
  unsigned long long x_modificado = x;

  int n_total = 0;
  int n_decididor = 0;

  unsigned long long i = 0;
  unsigned long long j = 0;

  unsigned long long valor_contador = x;
  while (x!=0) {
    valor_contador = valor_contador >> 1;
    n_total++;
  }

  while (n_decididor < n_total) {
    n_decididor += 2;
    j += 2;
    i++;
  }

  // Caso donde es impar, en otro caso, se salta
  if (n_decididor > n_total) {
    unsigned long long par_mask = 0b1 << n_total;
    x_modificado = x_modificado & (~par_mask);
    j -= 2;
    i--;
  }
  unsigned long long patron;
  int k = 0;
  while (k < n_total-1) {
    // Mascara lado derecho
    unsigned long long mask1 = ~((-1) << i);
    // Mascara lado izquierdo
    unsigned long long mask2 = ~((-1) << j);
    unsigned long long der = x_modificado & mask1;
    unsigned long long izq = x_modificado & mask2;
    patron = izq | der;
    printf("%llu\n", patron);
    k += 2;
  }


}


/* TO DO:
 * - Tomar la seccion izquierda y la seccion derecha e igualarla, no buscar duplcado como lo estaba haciendo (por la miechica)
*/
