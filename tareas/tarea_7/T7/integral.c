#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#include "integral.h"

double integral_par(Funcion f, void *ptr, double xi, double xf, int n, int p) {
  int fdi[p][2]; 
  double h = (xf - xi) / p;
  int trapecios = n / p;
  double integral_numerica = 0;

  for (int i = 0; i < p; i++) {
    if (pipe(fdi[i]) == -1) {
      perror("pipe");
      exit(1);
    }
  }

  pid_t pid = fork();
  for (int i = 0; i < p; i++) {
    if (pid == 0) {
      close(fdi[i][0]);
      double local_xi = xi + i * h;
      double local_xf = local_xi + h;
      double integ_paso = integral(f, ptr, local_xi, local_xf, trapecios);
      write(fdi[i][1], &integ_paso, sizeof(double));
      close(fdi[i][1]);
    } else {
      close(fdi[i][1]);
      double integral_paso;
      read(fdi[i][0], &integral_paso, sizeof(double));
      integral_numerica += integral_paso; 
      close(fdi[i][0]);
    }
  }

  if (pid == 0) {
    exit(0);
  } else {
    waitpid(pid, NULL, 0);
  }

  return integral_numerica;
}
