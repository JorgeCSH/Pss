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
  // Debuggear es pa weones
  //unsigned long long x = 0b110101011;
  unsigned long long x = 0b101100100100100100100;

  /* Constantes que se usaran para determinar largo y propiedades de los largos de los bits. */
  // Constantes que contiene la cantidad de bits.
  int n_total = 0;
  // Constante que determinara si la cant. de bits es par o impar.
  int n_decididor = 0;

  /* Varaibles que determinan los puntos de partida de cada seccion, de manera general, j > i */
  // Para determinar de donde parte el lado izquierdo
  unsigned long long i = 0;
  // Para determinar de donde parte el lado derecho
  unsigned long long j = 0;

  /* Contar bits */
  // Variable auxiliar igual a la utilizada que contara la cantidad de bits que hay sin afectar a la original.
  unsigned long long valor_contador = x;
  // Mientras no sea 0 en bits, aun hay que contar.
  while (valor_contador != 0b0) {
    // Desplazamos la variable auxiliar en 1 y contamos, esto hasta llegar a 0.
    valor_contador = valor_contador >> 1;
    // Contamos cuantas veces se desplazaron los bits.
    n_total++;
  }

  /* Contador Par */
  // Aca contamos cual seria la cantidad par mas cercana, si no es igual al total, entonces es impar.
  while (n_decididor < n_total) {
    // Mientras no sea mayor o igual al total, vamos agregando de 2 en 2.
    n_decididor += 2;;
    // Ademas, desplazamos las variables que dependeran de si espar o impar (las posiciones).
    j += 2;
    i++;
  }

  /* Es par (question). */
  // Condicional para modificar las variables (o invariantes segun algoritmos) para que se adapten al caso par e impar.
  if (n_decididor > n_total) {
    // Como la cuenta es total + 1, restamos 1 y despues otro 1 al j para estar en la posicion correcta.
    j -= 2;
    // Este solo se desplazo, no hay que purgar el extra, por ende solo se resta 1.
    i--;
  }

  /* Aca creamos las subsecuencias/divisiones/lados. */
  // Mascara 1, para el lado izquierdo.
  unsigned long long mask1;
  // Mascara 2, para el lado derecho.
  unsigned long long mask2;
  // Lado izquierdo.
  unsigned long long izq;
  // Lado derecho.
  unsigned long long der;

  /* Realizamos lo solicitado */
  // Condicion 1: vamos aumentando de 2 en 2 mientras no se encuentre un patron.
  int k = 0;
  while (k < n_total-1) {

    // Debuggear es pa weones
    printf("%llu\n", x);

    // Mascara lado derecho.
    mask1 = ~(((-1) << i));

    // Mascara lado izquierdo.
    mask2 = ~(((-1) << j));

    // Aca tenemos los valores que deberian estar dando a los lados.
    izq = x & mask2;
    der = x & mask1;

    // El lado izquierdo queda desplazado, por ende devlvemos la movemos.
    izq = izq >> i;
    // Condicion 2: se encuentra la secuencia.
    if (izq == der) {
      printf("\nLo haz logrado, s = %llu", izq);
      break;
    }

    // Debuggear es pa weones
    printf("\nSeccion izquierda: %llu", izq);
    printf("\nSeccion derecha: %llu", der);
    printf("\n");

    // Aca aumentamos el contador y desplazamos las posiciones.
    k += 2;
    j -= 2;
    i -= 1;
  }

}


/* TO DO:
 * - Tomar la seccion izquierda y la seccion derecha e igualarla, no buscar duplcado como lo estaba haciendo (por la miechica)
*/
