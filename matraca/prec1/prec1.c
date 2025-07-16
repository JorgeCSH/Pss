#include <stdio.h>
#include <string.h>

void comprimir(char *s) {
  char *saux1 = s; 
  char *saux2 = s + 1;
  char *inicio = s;
  int i = 1;

  while(*saux2 != '\0') {
    if (*saux1 != *saux2) {
      if(i > 1) {
        *inicio = 48+i; //ascii 
        inicio++;
      }  
      *inicio = *saux1;
      inicio++;
      i = 0;
    }
    i++;
    saux1++;
    saux2++;
  }

  if(*saux2 == '\0') {
    char *saux3 = saux1;
    int j = 1;
    saux3--;
    while (*saux3 == *saux1) {
      j++;
      saux3--;
    }

    if (j > 1) {
      *inicio = 48 + j; //ascii 
      inicio++;
    }
    *inicio = *saux1;
    inicio++;
  }
  *inicio = '\0';
}

int main() {
  char s[] = "AABCCCD";
  char ss[] = "ABBAA";
  comprimir(s);
  printf("s: %s\n  ", s);
  comprimir(ss);
  printf("ss: %s\n  ", ss);
  return 0;

}
