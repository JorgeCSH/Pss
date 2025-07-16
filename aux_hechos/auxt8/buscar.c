//
// Created by Vicente González on 09-06-23.
//
#include <stdio.h>
#include <string.h>

#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_PATH 512

char ROOT[MAX_PATH];

void buscar(const char* file);

int main(int argc, char* argv[]) {
	getcwd(ROOT, MAX_PATH); // lo necesitamos para más adelante
	buscar("t3.c");
}

void buscar(const char* file) {
	DIR* d = opendir(".");
	if (d == NULL) {
		return;
	}

	// loop para recorrer los archivos dentro del directorio actual "."
	for (struct dirent* entry = readdir(d); entry != NULL; entry = readdir(d)) {
		char* nombre = entry->d_name;
		struct stat statbuf;
		stat(nombre, &statbuf);

		// caso archivo: revisamos si tiene el nombre que buscamos e imprimimos el path relativo al root
		if (S_ISREG(statbuf.st_mode) && strcmp(nombre, file) == 0) {
			char buf[MAX_PATH];
			getcwd(buf, MAX_PATH);
			printf("%s/%s\n", buf + strlen(ROOT) /* avanzamos el puntero para evitar doxeo */, nombre);
		}

		// tenemos que evitar que se haga recursión infinita
		if (strcmp("..", nombre) == 0 || strcmp(".", nombre) == 0) {
			continue;
		}

		// caso directorio: hacemos recursión
		if (S_ISDIR(statbuf.st_mode)) {
			chdir(nombre);
			buscar(file);
			chdir("..");
		}
	}
	closedir(d);
}