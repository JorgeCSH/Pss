#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void to_lower(char *s) {
	for (char *s2 = s; *s2 != '\0'; s2++) {
		if ('A' <= *s2 && *s2 <= 'Z') {
			*s2 = *s2 - 'A' + 'a';
		}
	}
}

char *lowerCase(char *s) {
	char *copia = malloc(strlen(s) + 1);
	strcpy(copia, s);
	to_lower(copia);
	return copia;
}

char *lowerCase_variante(char *s) {
	// hay tres operaciones que recorren s en lowerCase
	// las operaciones son: strlen, strcpy y to_lower
	// esta variante lo reduce a 2
	char *copia = malloc(strlen(s) + 1);
	char *escritor = copia;
	for (char *lector = s; *lector; lector++) {
		if ('A' <= *lector && *lector <= 'Z') {
			*escritor = *lector - 'A' + 'a';
		} else {
			*escritor = *lector;
		}
		escritor++;
	}
	// agrega el 0 para terminar el string copia
	*escritor = '\0';
	return copia;
}

int main() {
	char *v_upper = "HoLa Soy UN String cON MAYUSCULAS!";
	char *v_lower = lowerCase(v_upper);
	printf("v_lower: string '%s' en la dirección %p\n", v_lower, v_lower);
	char *v_low2 = lowerCase_variante(v_upper);
	printf("variante: string '%s' en la dirección %p\n", v_low2, v_low2);
	printf("og string: %s\n",v_upper);
	free(v_lower);
	free(v_low2);
}
