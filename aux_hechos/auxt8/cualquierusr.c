//
// Created by Vicente González on 09-06-23.
//
#include <stdio.h>
#include <string.h>

#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_PATH 512

typedef unsigned int uint;

char ROOT[MAX_PATH];

void cualquierusr();

int main() {
	getcwd(ROOT, MAX_PATH);
	cualquierusr();
}

void cualquierusr() {
	DIR* d = opendir(".");
	if (d == NULL) {
		return;
	}

	for (struct dirent* entry = readdir(d); entry != NULL; entry = readdir(d)) {
		char* nombre = entry->d_name;
		struct stat statbuf;
		stat(nombre, &statbuf);

		if (strcmp("..", nombre) == 0 || strcmp(".", nombre) == 0) {
			continue;
		}

		// aqui no mas cambia el codigo con respecto a buscar.c
		uint permisos = statbuf.st_mode; // obtenemos los permisos
		if ((permisos & (S_IWOTH | S_IROTH)) == 06) { // buscamos archivos con permisos rw- en otros, es decir, 0006, o simplemente 06
			char path[MAX_PATH];
			getcwd(path, MAX_PATH); // obtenemos el path al archivo
			printf("%s/%s\n", path + strlen(ROOT) + 1, nombre); // imprimimos el path relativo al root del archivo
		}

		if (S_ISDIR(statbuf.st_mode)) {
			chdir(nombre);
			cualquierusr();
			chdir("..");
		}
	}
	closedir(d);
}
