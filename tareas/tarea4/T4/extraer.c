#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
  if (argc != 2) {
    fprintf(stderr, "uso: %s archivo\n", argv[0]);
    exit(1);
  }

  FILE *f = fopen(argv[1], "r+");
  if (f == NULL) {
    perror("error");
    exit(1);
  }

  char buffer[17];
  if (fread(buffer, 1, 4, f) != 4) {
    fprintf(stderr, "error: no se pudo leer el tamaño\n");
    exit(1);
  }
  buffer[5] = '\0';
  int n = atoi(buffer);

  if (n == 0) {
    fprintf(stderr, "error: %s esta vacia\n", argv[1]);
    exit(1);
  }

  char mejor_texto[11]; 
  int mejor_prioridad = 999999;
  int mejor_indice = -1;

  for (int i = 0; i < n; i++) {
    long pos = 4 + 1 + i * 17;
      if (fseek(f, pos, SEEK_SET) != 0) {
        fprintf(stderr, "error: fseek fallo\n");
        exit(1);
      }
      char linea[18];
      if (fread(linea, 1, 17, f) != 17) {
        fprintf(stderr, "error: lectura incompleta\n");
        exit(1);
      }
      linea[17] = '\0';

      char texto[10];
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

  printf("%s\n", mejor_texto);

  long ultima_pos = 4 + 1 + (n - 1) * 17;
  if (mejor_indice != n - 1) {
    if (fseek(f, ultima_pos, SEEK_SET) != 0) {
      fprintf(stderr, "error: fseek fallo al leer ultimo\n");
      exit(1);
    }

   char ultimo[17];
   if (fread(ultimo, 1, 17, f) != 17) {
     fprintf(stderr, "error: no se pudo leer el ultimo\n");
     exit(1);
   }

   long mejor_pos = 4 + 1 + mejor_indice * 17;
   if (fseek(f, mejor_pos, SEEK_SET) != 0) {
     fprintf(stderr, "error: fseek fallo al escribir\n");
     exit(1);
   }
   fwrite(ultimo, 1, 17, f);
  }

  n--;
  if (fseek(f, 0, SEEK_SET) != 0) {
    fprintf(stderr, "error: fseek al inicio fallo\n");
    exit(1);
  }
  sprintf(buffer, "%-4d", n);
  fwrite(buffer, 1, 4, f);

  fclose(f);
  return 0;
}


