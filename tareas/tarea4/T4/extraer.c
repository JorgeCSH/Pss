#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {

  if (argc != 2) {
    fprintf(stderr, "uso: %s archivo\n", argv[0]);
    exit(1);
  }

  char *filename = argv[1];
  FILE *f = fopen(filename, "r+");
  if (f == NULL) {
    perror(filename);
    exit(1);
  }

  char encabezado[5] = {0};
  if (fread(encabezado, 1, 4, f) != 4) {
    fprintf(stderr, "error: archivo mal formado\n");
    fclose(f);
    exit(1);
  }

  int n = atoi(encabezado);
  if (n <= 0) {
    fprintf(stderr, "error: %s esta vacia\n", argv[1]);
    fclose(f);
    exit(1);
  }

  long mejor_pos = -1;
  int mejor_prio = 1000000;
  char mejor_texto[11] = {0};

  for (int i = 0; i < n; i++) {
    fseek(f, 4 + 1 + i * 17, SEEK_SET);
    char linea[17] = {0};
    fread(linea, 1, 17, f);

    char texto[11] = {0}; 
    char prioridad[7] = {0};

    memcpy(texto, linea, 10);
    memcpy(prioridad, linea + 10, 6);

    int prio = atoi(prioridad);

    if (prio < mejor_prio) {
        mejor_prio = prio;
        memcpy(mejor_texto, texto, 10);
        mejor_pos = i;
    }
  }

  printf("%.*s\n", 10, mejor_texto);

  if (mejor_pos != n - 1) {
    char ultima_linea[17] = {0};
    fseek(f, 4 + 1 + (n - 1) * 17, SEEK_SET);
    fread(ultima_linea, 1, 17, f);

    fseek(f, 4 + 1 + mejor_pos * 17, SEEK_SET);
    fwrite(ultima_linea, 1, 17, f);
  }

  n--;
  char nuevo_encabezado[5] = {0};
  sprintf(nuevo_encabezado, "%-4d", n);
  fseek(f, 0, SEEK_SET);
  fwrite(nuevo_encabezado, 1, 4, f);

  fclose(f);
  return 0;

}
