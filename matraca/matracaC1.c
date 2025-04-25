#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
typedef unsigned long long uint64;

uint64 suma(uint64 x) {
  uint64 mask4 = ~((unsigned)(-1) << 4);
  uint64 largoSec = x & mask4;
  uint64 maskLong;
  uint64 suma = 0;

  while (largoSec != 0) {
    x = x >> 4;
    maskLong = ~((unsigned)(-1) << largoSec);
    suma += (x & maskLong);
    x = x >> (largoSec);
    largoSec = x & mask4;
  }
  return suma;
}

*/
/*
char *reemplazo(char *s, char c, char *pal) {
  char *contMem = s;
  char *sOriginal = s;

  int iMem = 0;
  while(*contMem != '\0') {
    if(*contMem == c) {
      iMem++;
      printf("%d ", iMem);
    }
    contMem++;
  }


  char *sResultado = malloc(strlen(s) + strlen(pal)*iMem + 1);
  char *sNuevo = sResultado;
  while(*sOriginal != '\0') {
    if(*sOriginal == c) {
      char *palOriginal = pal;
      while(*palOriginal != '\0') {
        *sNuevo = *palOriginal;
        sNuevo++;
        palOriginal++;
      }
      sOriginal++;
    } else {
      *sNuevo = *sOriginal;
      sNuevo++;
      sOriginal++;
    }
  }

  *sNuevo = '\0';
  return sResultado;
}



int main() {
  //uint64 choripan = suma(0b00001001101011100011010010);
  //printf("\n suma(19, 6, 1):%llu ", choripan);
  char *aaa = reemplazo("hola que tal", 'a', "xyz");
  printf("\n%s resultado: ", aaa);
  return 0;
}
*/
/*
typedef struct nodo {
  int x;
  struct nodo *prox;
} Nodo;


void elimDup(Nodo *L) {
  Nodo *a = L->prox;
  if (a == NULL) {
        return;
  } else if (L->x != a->x) {
    elimDup(a);  
  } else {
    L->prox = a->prox;
    elimDup(L);  
    free(a);
  }
}

// Agrega un nodo al final de la lista
void agregarFinal(Nodo **cabeza, int valor) {
    Nodo *nuevo = (Nodo *)malloc(sizeof(Nodo));
    nuevo->x = valor;
    nuevo->prox = NULL;

    if (*cabeza == NULL) {
        *cabeza = nuevo;
    } else {
        Nodo *temp = *cabeza;
        while (temp->prox != NULL)
            temp = temp->prox;
        temp->prox = nuevo;
    }
}

// Imprime la lista
void imprimirLista(Nodo *L) {
    while (L != NULL) {
        printf("%d ", L->x);
        L = L->prox;
    }
    printf("\n");
}

// Libera toda la memoria de la lista
void liberarLista(Nodo *L) {
    Nodo *temp;
    while (L != NULL) {
        temp = L;
        L = L->prox;
        free(temp);
    }
}

int main() {
    Nodo *lista = NULL;

    // Crear la lista: 7 7 9 3 3 3 7
    int datos[] = {7, 7, 9, 3, 3, 3, 7};
    for (int i = 0; i < sizeof(datos)/sizeof(datos[0]); i++) {
        agregarFinal(&lista, datos[i]);
    }

    printf("Lista original:\n");
    imprimirLista(lista);

    elimDup(lista);

    printf("Lista después de eliminar duplicados consecutivos:\n");
    imprimirLista(lista);

    liberarLista(lista);
    return 0;
}
*/
#include <stdio.h>

typedef unsigned long long ull;

ull elimDup(ull x, ull y) {
    // Calcular longitud de y en nibbles
    int len_y = 0;
    ull temp = y;
    while (temp) {
        temp = temp >> 4;
        len_y = len_y + 1;
    }

    // Calcular longitud de x en nibbles
    int len_x = 0;
    temp = x;
    while (temp) {
        temp = temp >> 4;
        len_x = len_x + 1;
    }

    // Procesar de izquierda a derecha (más significativo a menos)
    ull resultado = 0;
    int res_len = 0;

    int i = len_x - 1;
    while (i >= 0) {
        // Verificar si hay coincidencia con y desde posición i-len_y+1 hasta i
        if (i - len_y + 1 >= 0) {
            ull segmento = 0;
            for (int j = 0; j < len_y; j++) {
                ull nibble = (x >> ((i - len_y + 1 + j) * 4)) & 0xF;
                segmento = (segmento << 4) + nibble;
            }

            if (segmento == y) {
                i = i - len_y; // saltamos la coincidencia
                continue;
            }
        }

        // Si no coincide, guardar el nibble actual
        ull nibble = (x >> (i * 4)) & 0xF;
        resultado = (resultado << 4) + nibble;
        res_len = res_len + 1;
        i = i - 1;
    }

    // Invertir resultado (porque fue construido al revés)
    ull final = 0;
    for (int j = 0; j < res_len; j++) {
        ull nibble = (resultado >> (j * 4)) & 0xF;
        final = (final << 4) + nibble;
    }

    return final;
}

int main() {
    printf("0x%llx\n", elimDup(0x1c1c, 0x1c));        // 0x0
    printf("0x%llx\n", elimDup(0x1c1c1, 0xc1c));      // 0x11
    printf("0x%llx\n", elimDup(0x1c1c11, 0x1c1));     // 0x1c1
    return 0;
}
