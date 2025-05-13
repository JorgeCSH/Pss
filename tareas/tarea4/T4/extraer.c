#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
  /* Verificamos la cantidad de valores entregados. */
  if (argc != 2) {
    fprintf(stderr, "uso: %s archivo\n", argv[0]);
    exit(1);
  }

  /* Cargar .*/
  /* Cargamos el archivo. */
  FILE *f = fopen(argv[1], "r+");

  /* Creamos valores. */
  /* Aca creamos un buffer para la linea completa que se leera + 1, esto porque se tienen 16 caracteres mas el \n que no es considerado originalmente segun enunciado. */
  char buffer[16 + 1];
  /* Creamos la variable que correspondera al texto de mayor prioridad. */
  char mejor_texto[11]; 
  /* La prioridad corresponde a un valor de 6 caracteres, entonces la minima prioridad que puede alcanzar es de 999999. */
  int mejor_prioridad = 999999;
  /* */
  int mejor_indice = 0;

  /* Seccion de verificacion. */
  /* Verificamos que el archivo "exista". */
  if (f == NULL) {
    perror("error");
    exit(1);
  }

  /* Verificamos los cuatro primeros caracteres de los elementos almacenados. Esto es, usamos fread para contar los caracteres que hay en la primera linea de la posicion 1 a la 4 y, de haber una cantidad diferente de 4 entonces el tamano no calza y arrojamos error. */ 
  if (fread(buffer, 1, 4, f) != 4) {
    fprintf(stderr, "error: no se pudo leer el tamaño\n");
    exit(1);
  }

  /*Convertimos la porcion inicial en un entero (esto segun la definicion que arrojo man atoi al ejecutarlo en la terminal. */
  int n = atoi(buffer);

  /* Verificamos si la cola esta vacia o no identificando al valor que esta dentro de la cabecera.*/
  if (n == 0) {
    fprintf(stderr, "error: %s esta vacia\n", argv[1]);
    exit(1);
  }


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

  // Mostramos el texto solicitado 
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

  if (fseek(f, 0, SEEK_SET) != 0) {
    fprintf(stderr, "error: fseek al inicio fallo\n");
    exit(1);
  }
  sprintf(buffer, "%-4d", n - 1);
  fwrite(buffer, 1, 4, f);

  fclose(f);
  return 0;
}


