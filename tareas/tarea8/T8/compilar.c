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

/* NOTAS DE AUTOR:
 * Actualmente me encuentro dando metodologias de diseno y programacion, donde 
 * para docuementar en scala se usa un formato. Para este caso se me ocurrio
 * incluir el analogo (llamado Doxygen) puesto a que me permite tanto:
 * 1. Experimentar documentando en otros lenguajes.
 * 2. Adaptarme a documentar mejor mis programas.
 * Especificamente en c puesto a que...probablemente tome mas cursos/ramos
 * que usen este lenguaje. Mis disculpas si no era la idea y me hago responsable
 * de cualquier inconveniente que pueda signficar.
 */

/* Variables globales */
// Variable global para la cola
Queue *q;

/* Funciones */
/** 
 * @file compilar.c
 * @brief Funcion la cual se encarga de verificar si el archivo esta 
 * 	  o no compilado.
 *
 * @param archivo_c nombre del archivo en c (supuestamente terminado en .c) el cual se
 * 		    verificara si esta o no compilado (si termina en .o).
 *
 * @return int entero de 0 o 1 analogo del booleano en "c".
 */
int verificar_compilar(char *archivo_c) {
    // "Booleano" que corresponde al valor entregado.
    int compilar = 0;
    // Largo del nombre del archivo.
    int largo = strlen(archivo_c);
    // Espacio de memoria que guardara el nombre del archivo para cambiarlo por .c o .o.
    char *archivo_o = malloc(largo + 1);
    // Copiamos el nombre del archivo en c en el espacio en o.
    strcpy(archivo_o, archivo_c);
    // Cambiamos el "nombre" de la extension por .o.
    archivo_o[largo - 1] = 'o';  // reemplaza ".c" por ".o"

    struct stat st_c; 
    struct stat st_o;

    if (stat(archivo_c, &st_c) != 0) {
        free(archivo_o);
        return 0;
    }
    if (stat(archivo_o, &st_o) != 0) {
        compilar = 1; // .o no existe
    } else if (st_c.st_mtime > st_o.st_mtime) {
        compilar = 1; // .c es más nuevo
    }

    // Liberamos el espacio de memora del archivo .o.
    free(archivo_o);
    return compilar;
}

// Recorrido recursivo de directorios
void buscar(char *archivo) {
    DIR *dir = opendir(archivo);
    if (dir == NULL)
        return;

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
            continue;

        char *ruta = malloc(strlen(archivo) + strlen(entry->d_name) + 2);
	strcpy(ruta, archivo);
	size_t largo = strlen(ruta);
	ruta[largo] = '/';
	largo++;
	char *nombre = entry->d_name;

	while (*nombre != '\0') {
	    ruta[largo] = *nombre;
	    largo++;
	    nombre++;
	}

	ruta[largo] = '\0';

        struct stat st_buscar;
        if (stat(ruta, &st_buscar) == 0) {
            if (S_ISDIR(st_buscar.st_mode)) {
                buscar(ruta);
            } else if (S_ISREG(st_buscar.st_mode) && verificar_compilar(ruta)) {
                put(q, strdup(ruta));
            }
        }

        free(ruta);
    }

    closedir(dir);
}

// Comparador para ordenar alfabéticamentrye
int alfabetico(void *palabra, int i, int j) {
    char **palabra_aux = palabra;
    return strcmp(palabra_aux[i], palabra_aux[j]);
}

int main(int argc, char *argv[]) {
  // ... complete ...
    if (argc != 2) {
        return 1;
    }

    q = makeQueue();
    buscar(argv[1]);

    int n = queueLength(q);
    char **arr = malloc(n * sizeof(char *));

    for (int i = 0; i < n; i++) {
        arr[i] = get(q);
    }

    sortPtrArray(arr, 0, n - 1, alfabetico);

    for (int i = 0; i < n; i++) {
        printf("%s\n", arr[i]);
        free(arr[i]);
    }

    free(arr);
    destroyQueue(q);
    return 0;
}
