#define _POSIX_C_SOURCE 200809L
#include <dirent.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <time.h>
#include <errno.h>

#include "pss.h"

// ... agregue aca las funciones y variables globales adicionales que necesite

/* Variables globales */
// Variable global para la cola
Queue *q;

/* Funciones */
// Funcion encargada de de verificar si un archivo debe ser o no compilado.
int verificar_compilar(char *archivo_c) {
    int compilar = 0;
    int largo = strlen(archivo_c);
    char *archivo_o = malloc(largo + 1);
    struct stat st_c; 
    struct stat st_o;
    strcpy(archivo_o, archivo_c);
    archivo_o[largo - 1] = 'o'; 
    if (stat(archivo_c, &st_c) != 0) {
        compilar = 0;
    } else if (stat(archivo_o, &st_o) != 0 || st_c.st_mtime > st_o.st_mtime) {
        compilar = 1; 
    }
    free(archivo_o);
    return compilar;
}

// Funcion encargada de recorrer directorios de manera recursiva. Inspirada en list-dir.c.
void buscar(char *archivo) {
    DIR *dir = opendir(archivo);
    if (dir == NULL) {
        perror(archivo);
        exit(1);
    }
    for (struct dirent *entry = readdir(dir); entry != NULL; entry = readdir(dir)) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry -> d_name, "..") == 0) {
            continue;
        }
        char *ruta = malloc(strlen(archivo) + strlen(entry->d_name) + 2);
        strcpy(ruta, archivo);
        strcat(ruta, "/");
        strcat(ruta, entry -> d_name);
        struct stat st_buscar;
        // Aca vemos si el archivo debe o no ser compilado.
        if (stat(ruta, &st_buscar) == 0) {
            if (S_ISDIR(st_buscar.st_mode)) {
                buscar(ruta);
            } else if (S_ISREG(st_buscar.st_mode) && verificar_compilar(ruta)) {
                put(q, strdup(ruta));
            }
            free(ruta);
        }
    } 
    closedir(dir);
}

// Comparador alfabetico. 
int comparador_alfabetico(void *palabra, int i, int j) {
    char **palabra_aux = palabra;
    return strcmp(palabra_aux[i], palabra_aux[j]);
}

int main(int argc, char *argv[]) {
  // ... complete ...
  q = makeQueue();
  buscar(argv[1]);
  int largo_cola = queueLength(q);
  char **arr = malloc(largo_cola * sizeof(char *));
  for (int i = 0; i < largo_cola; i++) {
      arr[i] = get(q);
  }
  sortPtrArray(arr, 0, largo_cola - 1, comparador_alfabetico);
  for (int i = 0; i < largo_cola; i++) {
      printf("%s\n", arr[i]);
      free(arr[i]);
  }
  free(arr);
  destroyQueue(q);
  return 0;
}
