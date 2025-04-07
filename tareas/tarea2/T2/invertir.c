#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "invertir.h"

void invertir(char* s) {
  /** Programe aqui la funcion invertir */
  /* Eliminamos espacios de mas. */
  // Caracter de una copia del caracter actual en el que estamos posicionados del strign original.
  char *caracterActual = s;
  // Caracter donde iremos cambiando los espacios de mas por uno solo.
  char *cambiarEspacio = s;
  // Variable que usaremos como condicional mientras estemos posicionados sobre un espacio.
  int noHayEspacio = 1;
  // Ciclo mientras no hayamos recorrido todo el string.
  while (*caracterActual != '\0') {
    // Si encontramos un espacio, el caracter que representa los espacios se ira expandiendo en uno.
    if (*caracterActual != ' ') {
      // Expandimos el caracter del espacio.
      *cambiarEspacio++ = *caracterActual;
      // Cambiamos la situacion.
      noHayEspacio = 0;
      // Como detectamos un espacio, entonces hasta que no dejen de haber espacios reemplazamos la expresion que corresponde a el espacio total por uno solo.
    } else if (!noHayEspacio) {
      // Reemplazamos por uno solo.
      *cambiarEspacio++ = ' ';
      // Volvio a dejar dejar de haber espacios.
      noHayEspacio = 1;
    }
    // Desplazamos por el caracter original.
    caracterActual++;
  }
  // Corroboramos si nos pasamos del largo original. 
  if (cambiarEspacio > s && *(cambiarEspacio - 1) == ' ') {
    cambiarEspacio--;
  }
  // Como cambiar espacio apunta al caracter final despues de retirar los espacios extras, tenemos que agregar el \0 para indicar que ahora el string termina ahi.
  *cambiarEspacio = '\0';

  /* Invertimos todo el string. */
  // Esta parte esta inspirada en el aux 3.
  // Inicio del string. 
  char *inicio = s;
  // Final del string sin contar el \0 final.
  char *fin = s + strlen(s) - 1;
  while (inicio < fin) {
    // Auxiliar que guarda el caracter antes de cambiarlo.
    char auxDarVuelta = *inicio;
    // Cambiamos el caracter por el del final. 
    *inicio = *fin;
    // El del final lo cambiamos por el guardado en el auxiliar.
    *fin = auxDarVuelta;
    // Nos desplazamos
    inicio++;
    fin--;
  }

  /* Invertimos cada palabra por separado. */ 
  char *palabra = s;
  while (*palabra != '\0') {
    while (*palabra == ' ') {
      palabra++;  // Saltar espacios
    }
    char *inicioPalabra = palabra;
    while (*palabra != '\0' && *palabra != ' ') {
      palabra++;
    }
    char *finPalabra = palabra - 1;
    while (inicioPalabra < finPalabra) {
      char auxPalabra = *inicioPalabra;
      *inicioPalabra = *finPalabra;
      *finPalabra = auxPalabra;
      inicioPalabra++;
      finPalabra--;
    }
  }
}

char *invertido(char *s) {
  /** Programe aqui la funcion invertido */
  /* Eliminamos los espacios extras, proceso analgo al anterior. */
  char *auxOriginal = malloc(strlen(s) + 1);

  char *caracterActual = s;
  char *caracterSaltar = auxOriginal;

  int noHayEspacio = 1;
  while (*caracterActual != '\0') {
      if (*caracterActual != ' ') {
          *caracterSaltar++ = *caracterActual;
          noHayEspacio = 0;
      } else if (!noHayEspacio) {
          *caracterSaltar++ = ' ';
          noHayEspacio = 1;
      }
      caracterActual++;
  }

  if (caracterSaltar > auxOriginal && *(caracterSaltar - 1) == ' ') {
    caracterSaltar--;
  }
  *caracterSaltar = '\0';

  // Invertir todo el string
  char *inicio = auxOriginal;
  char *fin = auxOriginal + strlen(auxOriginal) - 1;
  while (inicio < fin) {
      char tmp = *inicio;
      *inicio = *fin;
      *fin = tmp;
      inicio++;
      fin--;
  }

  // Invertir palabra por palabra
  char *palabra = auxOriginal;
  while (*palabra != '\0') {
      while (*palabra == ' ') {
      palabra++;
    }
    char *inicioPalabra = palabra;
    while (*palabra != '\0' && *palabra != ' ') {
      palabra++;
    }
    char *finPalabra = palabra - 1;
    while (inicioPalabra < finPalabra) {
      char auxCaracter = *inicioPalabra;
      *inicioPalabra = *finPalabra;
      *finPalabra = auxCaracter;
      inicioPalabra++;
      finPalabra--;
    }
  }

  // resultadoervar justo y copiar
  char *resultado = malloc(strlen(auxOriginal) + 1);

  char *caracterSinEspacio2 = auxOriginal;
  char *caracterSaltar2 = resultado;
  while (*caracterSinEspacio2) {
      *caracterSaltar2 = *caracterSinEspacio2;
      caracterSaltar2++;
      caracterSinEspacio2++;
  }
  *caracterSaltar2 = '\0';  
  free(auxOriginal);
  return resultado;
}

