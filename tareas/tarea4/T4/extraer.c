#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
  // Verificamos la cantidad de valores ingresados.
  if (argc != 2) {
    exit(1);
  }

  // cargamos el archivo
  FILE *f = fopen(argv[1], "r+");

  // Variables.
  char buffer[16 + 1];
  char textoPrioritario[10 + 1]; 
  int prioridadMayor = 999999;
  int posicionPersonaPrioritaria = 0;

  // Verificamos que el archivo exista.
  if (f == NULL) {
    perror("error");
    exit(1);
  }

  // Verificamos que, en la primera linea la cantidad de elementos tenga 4 caracteres.
  if (fread(buffer, 1, 4, f) != 4) {
    exit(1);
  }

  int n = atoi(buffer);

  // Verificamos si la cola esta vacia.
  if (n == 0) {
    fprintf(stderr, "error: %s esta vacia\n", argv[1]);
    exit(1);
  }

  /* Recorremos el archivo leyendo las lineas. */
  long posicion;
  char lineaLeida[(16 + 1) + 1];
  char textoLeido[10 + 1];
  char prioridadLeida[6 + 1];
  for (int i = 0; i < n; i++) {
    posicion = 4 + 1 + i * (16 + 1);
    // Verificamos que el texto tenga caracteres.
    if (fseek(f, posicion, SEEK_SET) != 0) {
      exit(1);
    }
    // Verificamos que la linea leida no tenga mas de 17 caracteres.
    if (fread(lineaLeida, 1, (16+1), f) <  17) {
      exit(1);
    }

    lineaLeida[16+1] = '\0';
    memcpy(textoLeido, lineaLeida, 10);
    textoLeido[10] = '\0';
    memcpy(prioridadLeida, lineaLeida + 10, 6);
    prioridadLeida[6] = '\0';
    
    int prioridad = atoi(prioridadLeida);
    if (prioridad < prioridadMayor) {
      prioridadMayor = prioridad;
      posicionPersonaPrioritaria = i;
      strncpy(textoPrioritario, textoLeido, 11);
    }
  }
  // Mostramos el texto con mayor prioridad.
  printf("%s\n", textoPrioritario);

  /* Mover elementos. */
  // Caso donde el elemento no corresponde al ultimo.
  long personaFinal = 4 + 1 + (n - 1) * (16+1);
  long personaPrioritaria = 4 + 1 + posicionPersonaPrioritaria * (16+1);
  char bufferMover[16+1];
  if (posicionPersonaPrioritaria != n - 1) {
    // Verificamos que el espacio esta vacio.
    if (fseek(f, personaFinal, SEEK_SET) != 0) {
      exit(1);
    }
    // Verificamos que el espacio es suficiente
    if (fread(bufferMover, 1, (16+1), f) < 17) {
      exit(1);
    }
    if (fseek(f, personaPrioritaria, SEEK_SET) != 0) {
      exit(1);
    }
    // Reescribimos.
    fwrite(bufferMover, 1, (16+1), f);
  }

  // Caso donde el elemento corresponde al ultimo.
  if (fseek(f, 0, SEEK_SET) != 0) {
    exit(1);
  }
  sprintf(buffer, "%-4d", n - 1);
  fwrite(buffer, 1, 4, f);

  fclose(f);
  return 0;
}


