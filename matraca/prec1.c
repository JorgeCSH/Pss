#include <stdio.h>
#include <string.h>

void comprimir(char *s) {
  char *sAux1 = s; 
  char *sAux2 = s + 1;
  char *inicio = s;
  int i = 1;

  while(*sAux2 != '\0') {
    if (*sAux1 != *sAux2) {
      if(i > 1) {
        *inicio = 48+i; //ASCII 
        inicio++;
      }  
      *inicio = *sAux1;
      inicio++;
      i = 0;
    }
    i++;
    sAux1++;
    sAux2++;
  }
  if(*sAux2 == '\0') {
    char *sAux3 = sAux1;
    sAux3--;
    if (*sAux3 != *sAux1) {
      *inicio = *sAux1;
      inicio++;
    }
  }
  *inicio = '\0';
}

int main() {
  char s[] = "AABCCCD";
  printf("s: %s\n  ", s);
  comprimir(s);
  printf("s: %s\n  ", s);
  return 0;

}
