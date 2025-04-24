#include <stdio.h>
#include <string.h>

void comprimir(char *s) {
  char *sAux1 = s; 
  char *sAux2 = s + 1;
  char *inicio = s;
  int i =  0;

  while(*sAux2 != '\0') {
    if (*sAux1 != *sAux2) {
      if(i > 1) {
        *inicio = (char)i;
        inicio++;
        i = 0;
      } else {
        i = 0;
      }
      *inicio = *sAux1;
      inicio++;
    }
    sAux1++;
    sAux2++;
  }
  while (*inicio != '\0') {
    *inicio = ' ';
    inicio++;
  }
}

int main() {
  char *s = "AABCCCD";
  printf("s: %s\n  ", s);
  comprimir(s);
  printf("s: %s\n  ", s);
  return 0;

}
