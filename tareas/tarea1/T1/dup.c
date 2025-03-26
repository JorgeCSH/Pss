#include <stdio.h>
#include <stdlib.h>

#include "dup.h"
unsigned long long dupMasLargo(unsigned long long x) {
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
