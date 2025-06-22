#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#include "integral.h"

double integral_par(Funcion f, void *ptr, double xi, double xf, int n, int p) {
  int fdi[p][2]; 
  pid_t pid[p];
  double h = (xf - xi) / p;
  int trapecios = n / p;
  double integral_numerica = 0;

  /* Crear p pipes, uno por cada hijo. */
  for (int i = 0; i < p; i++) {
    if (pipe(fdi[i]) == -1) {
      perror("pipe");
      exit(1);
    }
  }

  /* Crear p procesos hijos. */
  for (int i = 0; i < p; i++) {
    pid[i] = fork();
    if (pid[i] == 0) {
      close(fdi[i][0]);
      double paso = xi + i * h;
      double integ_paso = integral(f, ptr, paso, paso + h, trapecios);
      write(fdi[i][1], &integ_paso, sizeof(double));
      close(fdi[i][1]);
      exit(0);
    } else {
      close(fdi[i][1]);
    }
  }

  /* Leer resultados padre y esperar terminar hijos. */
  for (int i = 0; i < p; i++) {
    double integ_paso;
    read(fdi[i][0], &integ_paso, sizeof(double));
    close(fdi[i][0]);
    integral_numerica += integ_paso;
    waitpid(pid[i], NULL, 0); 
  }

  return integral_numerica;
}
