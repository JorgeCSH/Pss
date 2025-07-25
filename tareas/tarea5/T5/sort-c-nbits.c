#include <string.h>

void sort(unsigned int *nums, int n) {
  unsigned int *ult= &nums[n-1];
  unsigned int *p= nums;
  while (p<ult) {
    // No modifique nada arriba de esta linea
    // Inicio de la parte que debe cambiar
    int t1= p[0]<=p[1] ? 0 : 1; 
    unsigned int p0 = p[0];
    unsigned int p1 = p[1];
    int i = 0;
    int j = 0;
    while (p0 || p1){
      if (p0 & 1) {
        i--;
      } 
      if (p1 & 1) {
        j--;
      }
      p0 = p0 >> 1;
      p1 = p1 >> 1; 
    }    
    t1= i<=j ? 0 : 1;
    // Fin de la parte que debe cambiar
    // No Cambie nada mas a partir de aca
    if (t1 <= 0)
      p++;
    else {
      unsigned int tmp= p[0];
      p[0]= p[1];
      p[1]= tmp;
      p= nums;
    }
  }
}
