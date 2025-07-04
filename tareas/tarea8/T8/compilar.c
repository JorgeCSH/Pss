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
// Cola global
Queue *q;

// Verifica si un archivo .c necesita compilarse
int necesita_compilar(char *ruta_c) {
    int largo = strlen(ruta_c);

    char *ruta_o = malloc(largo + 1);
    strcpy(ruta_o, ruta_c);
    ruta_o[largo - 1] = 'o';  // reemplaza ".c" por ".o"

    struct stat st_c; 
    struct stat st_o;
    int compilar = 0;

    if (stat(ruta_c, &st_c) != 0) {
        free(ruta_o);
        return 0;
    }

    if (stat(ruta_o, &st_o) != 0) {
        compilar = 1; // .o no existe
    } else if (st_c.st_mtime > st_o.st_mtime) {
        compilar = 1; // .c es más nuevo
    }

    free(ruta_o);
    return compilar;
}

// Recorrido recursivo de directorios
void recorrer(char *ruta) {
    DIR *dir = opendir(ruta);
    if (dir == NULL)
        return;

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
            continue;

        char *path = malloc(strlen(ruta) + strlen(entry->d_name) + 2);
        sprintf(path, "%s/%s", ruta, entry->d_name);

        struct stat st;
        if (stat(path, &st) == 0) {
            if (S_ISDIR(st.st_mode)) {
                recorrer(path);
            } else if (S_ISREG(st.st_mode) && necesita_compilar(path)) {
                put(q, strdup(path));
            }
        }

        free(path);
    }

    closedir(dir);
}

// Comparador para ordenar alfabéticamentrye
int cmpStr(void *ptr, int i, int j) {
    char **arr = ptr;
    return strcmp(arr[i], arr[j]);
}

int main(int argc, char *argv[]) {
  // ... complete ...
    if (argc != 2) {
        fprintf(stderr, "Uso: %s directorio\n", argv[0]);
        return 1;
    }

    q = makeQueue();
    recorrer(argv[1]);

    int n = queueLength(q);
    char **arr = malloc(n * sizeof(char *));

    for (int i = 0; i < n; i++) {
        arr[i] = get(q);
    }

    sortPtrArray(arr, 0, n - 1, cmpStr);

    for (int i = 0; i < n; i++) {
        printf("%s\n", arr[i]);
        free(arr[i]);
    }

    free(arr);
    destroyQueue(q);
    return 0;
}
