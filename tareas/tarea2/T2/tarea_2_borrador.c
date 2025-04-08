
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "invertir.h"

void invertir(char* s) {
  /** Programe aqui la funcion invertir */

  char *src = s *dst = s;
  int hayEspacio = 1;
  while (*src != '\0') {
      if (*src != ' ') {
          *dst++ = *src;
          espacio = 0;
      } else if (!espacio) {
          *dst++ = ' ';
          espacio = 1;
      }
      src++;
  }
  if (dst > s && *(dst - 1) == ' ') dst--;
  *dst = '\0';

  // Invertir todo el string
  char *inicio = s;
  char *fin = s + strlen(s) - 1;
  while (inicio < fin) {
      char tmp = *inicio;
      *inicio = *fin;
      *fin = tmp;
      inicio++;
      fin--;
  }

  // Invertir palabra por palabra
  char *p = s;
  while (*p != '\0') {
      while (*p == ' ') p++;  // Saltar espacios
      char *pal_inicio = p;
      while (*p != '\0' && *p != ' ') p++;
      char *pal_fin = p - 1;
      while (pal_inicio < pal_fin) {
          char tmp = *pal_inicio;
          *pal_inicio = *pal_fin;
          *pal_fin = tmp;
          pal_inicio++;
          pal_fin--;
      }
  }
}

char *invertido(char *s) {
  /** Programe aqui la funcion invertido */
  // Primero eliminamos espacios redundantes y copiamos
  char *temp = (char *)malloc(strlen(s) + 1);
  if (!temp) return NULL;
  char *src = s, *dst = temp;
  int espacio = 1;
  while (*src != '\0') {
      if (*src != ' ') {
          *dst++ = *src;
          espacio = 0;
      } else if (!espacio) {
          *dst++ = ' ';
          espacio = 1;
      }
      src++;
  }
  if (dst > temp && *(dst - 1) == ' ') dst--;
  *dst = '\0';

  // Invertir todo el string
  char *inicio = temp;
  char *fin = temp + strlen(temp) - 1;
  while (inicio < fin) {
      char tmp = *inicio;
      *inicio = *fin;
      *fin = tmp;
      inicio++;
      fin--;
  }

  // Invertir palabra por palabra
  char *p = temp;
  while (*p != '\0') {
      while (*p == ' ') p++;
      char *pal_inicio = p;
      while (*p != '\0' && *p != ' ') p++;
      char *pal_fin = p - 1;
      while (pal_inicio < pal_fin) {
          char tmp = *pal_inicio;
          *pal_inicio = *pal_fin;
          *pal_fin = tmp;
          pal_inicio++;
          pal_fin--;
      }
  }

  // Reservar justo y copiar
  char *res = (char *)malloc(strlen(temp) + 1);
  if (!res) {
      free(temp);
      return NULL;
  }
  char *src2 = temp, *dst2 = res;
  while ((*dst2++ = *src2++));
  free(temp);
  return res;
}
