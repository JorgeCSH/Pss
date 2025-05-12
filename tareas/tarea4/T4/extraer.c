#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "uso: %s archivo\n", argv[0]);
        return 1;
    }

    FILE *f = fopen(argv[1], "r+b");
    if (!f) {
        perror("error");
        return 1;
    }

    // Leer los primeros 4 bytes para obtener el número de elementos
    char buffer[16];
    if (fread(buffer, 1, 4, f) != 4) {
        fprintf(stderr, "error: no se pudo leer el tamaño\n");
        fclose(f);
        return 1;
    }
    buffer[4] = '\0';
    int cantidad = atoi(buffer);

    if (cantidad == 0) {
        fprintf(stderr, "error: %s esta vacia\n", argv[1]);
        fclose(f);
        return 1;
    }

    // Variables para mantener el mejor elemento
    char mejor_texto[11];  // +1 para \0
    int mejor_prioridad = 999999;
    int mejor_indice = -1;

    for (int i = 0; i < cantidad; i++) {
        // Calcular la posición del elemento i
        long pos = 4 + 1 + i * 17;
        if (fseek(f, pos, SEEK_SET) != 0) {
            fprintf(stderr, "error: fseek fallo\n");
            fclose(f);
            return 1;
        }

        char linea[18];  // 17 + 1 para \0
        if (fread(linea, 1, 17, f) != 17) {
            fprintf(stderr, "error: lectura incompleta\n");
            fclose(f);
            return 1;
        }
        linea[17] = '\0';

        char texto[11];
        strncpy(texto, linea, 10);
        texto[10] = '\0';

        char prioridad_str[7];
        strncpy(prioridad_str, linea + 10, 6);
        prioridad_str[6] = '\0';
        int prioridad = atoi(prioridad_str);

        if (prioridad < mejor_prioridad) {
            mejor_prioridad = prioridad;
            mejor_indice = i;
            strncpy(mejor_texto, texto, 11);
        }
    }

    // Mostrar el texto extraído (siempre 10 caracteres)
    printf("%s\n", mejor_texto);

    // Leer el último elemento de la cola
    long ultima_pos = 4 + 1 + (cantidad - 1) * 17;
    if (mejor_indice != cantidad - 1) {
        if (fseek(f, ultima_pos, SEEK_SET) != 0) {
            fprintf(stderr, "error: fseek fallo al leer ultimo\n");
            fclose(f);
            return 1;
        }

        char ultimo[17];
        if (fread(ultimo, 1, 17, f) != 17) {
            fprintf(stderr, "error: no se pudo leer el ultimo\n");
            fclose(f);
            return 1;
        }

        // Escribir el último elemento en la posición del mejor
        long mejor_pos = 4 + 1 + mejor_indice * 17;
        if (fseek(f, mejor_pos, SEEK_SET) != 0) {
            fprintf(stderr, "error: fseek fallo al escribir\n");
            fclose(f);
            return 1;
        }
        fwrite(ultimo, 1, 17, f);
    }

    // Actualizar la cantidad (en primera línea)
    cantidad--;
    if (fseek(f, 0, SEEK_SET) != 0) {
        fprintf(stderr, "error: fseek al inicio fallo\n");
        fclose(f);
        return 1;
    }
    sprintf(buffer, "%-4d", cantidad);
    fwrite(buffer, 1, 4, f);

    fclose(f);
    return 0;
}


