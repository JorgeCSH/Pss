#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "invertir.h"

void invertir(char* s) {
  /** Programe aqui la funcion invertir */

  /* Eliminamos espacios de mas. */
  char *sConEspacios = s;
  char *sSinEspacios = s;
  int unEspacio = 1;
  while (*sConEspacios != '\0') {
    if (*sConEspacios != ' ') {
      *sSinEspacios++ = *sConEspacios;
      unEspacio = 0;
    } else if (!unEspacio) {
      *sSinEspacios++ = ' ';
      unEspacio = 1;
    }
    sConEspacios++;
  }

  char* auxUltimo = sSinEspacios;
  auxUltimo--;
  if (sSinEspacios > s && *auxUltimo == ' ') {
    sSinEspacios--;
  }
  *sSinEspacios = '\0';

  /* Invertimos todo el string. */
  char *inicio = s;
  char *fin = s + strlen(s) - 1;
  while (inicio < fin) {
    char auxInicio = *inicio;
    *inicio = *fin;
    *fin = auxInicio;
    inicio++;
    fin--;
  }

  /* Invertimos cada palabra por separado. */ 
  char *sInvertir = s;
  while (*sInvertir != '\0') {
    // En caso de que nos posicionemos en un espacio, desplazamos al siguiente caracter.
    if (*sInvertir == ' ') {
      sInvertir++;
    }
    // Buscamos hasta donde llega la palabra en la que estamos.
    char *inicioPalabra = sInvertir;
    while (*sInvertir != '\0' && *sInvertir != ' ') {
      sInvertir++;
    }
    // Damos vuelta la palabra.
    char *finPalabra = sInvertir - 1;
    while (inicioPalabra < finPalabra) {
      char auxInicioPalabra = *inicioPalabra;
      *inicioPalabra = *finPalabra;
      *finPalabra = auxInicioPalabra;
      inicioPalabra++;
      finPalabra--;
    }
  }
}

char *invertido(char *s) {
  /** Programe aqui la funcion invertido */

  /* Alocamos espacios de memoria */
  char *sResultado = malloc(strlen(s) + 1);
  char *sOriginal = s;

  /* Eliminamos espacios de mas. */
  char *sNuevo = sResultado;
  int unEspacio = 1;
  while (*sOriginal != '\0') {
      if (*sOriginal != ' ') {
          *sNuevo++ = *sOriginal;
          unEspacio = 0;
      } else if (!unEspacio) {
          *sNuevo++ = ' ';
          unEspacio = 1;
      }
      sOriginal++;
  }

  char* auxUltimoNuevo = sNuevo;
  auxUltimoNuevo--;
  if (sNuevo > sResultado && *auxUltimoNuevo == ' ') {
    sNuevo--;
  }
  *sNuevo = '\0';

  /* Invertimos todo el string. */
  char *inicio = sResultado;
  char *fin = sResultado + strlen(sResultado) - 1;
  while (inicio < fin) {
      char auxInicio = *inicio;
      *inicio = *fin;
      *fin = auxInicio;
      inicio++;
      fin--;
  }

  /* Invertimos palabra por palabra */
  char *sNuevoInvertir = sResultado;
  while (*sNuevoInvertir != '\0') {
    if (*sNuevoInvertir == ' ') {
      sNuevoInvertir++;
    }
    char *inicioPalabra = sNuevoInvertir;
    while (*sNuevoInvertir != '\0' && *sNuevoInvertir != ' ') {
      sNuevoInvertir++;
    }
    char *finPalabra = sNuevoInvertir - 1;
    while (inicioPalabra < finPalabra) {
      char auxInicioPalabra = *inicioPalabra;
      *inicioPalabra = *finPalabra;
      *finPalabra = auxInicioPalabra;
      inicioPalabra++;
      finPalabra--;
    }
  }

  return sResultado;
}

