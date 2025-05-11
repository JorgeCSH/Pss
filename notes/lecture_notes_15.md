# Archivos

## Recuerdo clase pasada
Funciones para manipular archivos:
``` c
// Para abrir
FILE * fopen(char *name, char *mode);

// Para cerrar
close fclose(FILE *f);

// Escritura
size_t fwrite(void *buf, size_t size, size_t nmemb, FILE *f);

// Lectura
size_t fread(void *buf, size_t size, size_t nmemb, FILE *f);
```
Veamos un ejemplo de como se inicializaria:
``` c 
char buf[] = "Hola";
fwrite(buf, 1, strlen(buf), f);
```
En la tarea nos pediran ver si alguna funcion falla, ejemplo escritura cuando return < nmemb (y lectura) al abrir cuando retorne un nulo.
Veamos un ejemplo del estilo que pueden preguntar:
``` c
// Ejemplo usando estructura.
// 20 caracteres nombre, 10 caracteres rut, int edad.
// Estructura que podemos crear para guardar la info.
typedef struct persona {
/* Importante, ,a linea puede tener menos caracteres,dejando al resto como espacos en blanco, ademas de que no es un string i.e. no termian con \0*/
	nom[20];
	rut[10];
	int edad;
} Pers

// Para leer
Pers p;
// Guardar los valores dentro en el formato de la estructura.
fread(&p, sizeof(Pers), sizeof(Pers), f);
//p.rut => rut linea leida.

// Esscribir
Pers pp = {"Juan", "1111", 20};
fwrite(&pp, sizeof(Pers), sizeof(Pers), f);
/* ======================================================================== */

// Ejemplo sin escritura.
// Lectura sin escribir
char nom[20];
char rut[10];
int edad;

// Esto podemos implementarlo para escribir tambien
fread(nom, 1, 20, f);
fread(rut, 1, 10, f);
fread(&edad, 4, 4, f);

```
Si queremos buscar dentro de un texto es importante notar que no se trata de strings lo leido en un texto (i.e. no tiene el \0), por ende nosotros deberemos agregar el \0 final para poder tratarlo como un string.

## Funciones para manipular archivos
Una funcion que falto revisar la clase pasada corresponde a `fseek`, esta realiza un acceso directo en un archivo como por ejemplo a una linea de n° especifico. Esta funcion es de la forma:
``` c 
int fseek(FILE *f, long offset, int mode);
```
Donde `FILE *f` corresponde al puntero al archivo, `long offset` la cantidad de bytes a desplazar f e `int mode` desde donde desplazar f, la cual puede ser realizado de tres formas:
- `SEEK_SET`[^1]: desplazar desde inicio del archivo.
- `SEEK_CUR`: desde la posicion actual de f.
- `SEEK_END`[^2]: desde el fin del archivo.

Una sexta funcion que esta seria `ftell`, esta funcion retorna la cantidad dde bytes desde el inicio del archivo hasta el final. Esta funcion es de la forma:
``` c
long ftell(FILE *f);
```

Veamos un ejemplo de busqueda binaria en un archivo donde cada linea tiene 100 caracteres, donde 20 caracteres son una llave y los 80 extras la definicion. Esta busqueda binaria se puede hacer porque es un archivo ordenado por llaves y buscamos la llave si es que existe. Como indicacion, en archivos siempre usaremos o nosotros implementaremos la funcion `main()` comparado a las otras tareas donde implementabamos las funciones. De esta forma el programa:
``` c
int main(int argc, char *argv[]) { // nom_archivo, llave
	/* Aca (en este condicional) lo que se hace es ver si entrega mas o menos parametros para tirar
	error. */
	if(argc != 3) { // buscar nom_archivo llave
		// stderr = salida de errores.
		fprintf(stderr, "Uso: %s nom_arch llave", argv[0]);
		/* El exit es como un return para decir que algo fallo, donde el numero del recibido es distinto de 0, pues 0 = exito, != 0 = fracaso. */
		exit(1);	
	}
	char *filename = argv[1];
	char *llave = argv[2];
	
	FILE *f = fopen(filename, "r");
	if(f == NULL) {
		// Arroja a la salida estandar de errores devolviendo el nombre del arch.
		perror(filename);
		exit(1);
	}
	fseek(f, 0, SEEK_END);
	long t_file = ftell(f);
	int lineas = tfile/100;

	// Ahora podemos partir la busqueda binaria
	int i = 0;
	int j = lineas - 1;
	/* Este buffer me va a permitir guardar los 100 caracteres que tiene la linea + 1 necesitar 0 fin de string. */
	char buffer[100+1];
	// Busqueda
	while(i <= j) {
		// Deberia ser la linea de la mitad.
		int linea = (j-i)/2;  
		fseek(f, linea*100, SEEK_SET);
		// Leemos la informacion que esta justo a mitad de archivo.
		fread(buffer, 1, 100, f);
		buffer[100] = 0; // Fin de string.
		int rc = strcmp(buf, llave, strlen(llave));
		// Caso donde encontramos la llave.
		if (rc == 0) {
			printf("%s\n", buffer + 20);
			fclose(f)
			return 0;
		}

		// Caso donde nos desplazamos.
		if (rc < 0) { // buffer < llave.
			i = linea + 1;
		} else { // buffer > llave.
			j = linea - 1;	
		}
	} // Fin while	
	printf("Llave no encontrada\n");
	fclose(f);
	return 0;
}


```



[^1]: La que mas usamos...porque es la mas simple (xd).
[^2]: Menos usado, generalmente para ubicarnos en una linea.
