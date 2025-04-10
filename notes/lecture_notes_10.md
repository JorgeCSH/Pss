# Catedra 10, 10 de abril

## Puntero a funciones (o punteros opacos)[^1]

Empezemos con una funcion para calcular integrales como inspiracion:

``` c
// Funcion de una funcion (es para representar  una funcion mat).
double fn(double x);

// Funcion para calcular la integral de fn.
double integral(double xi, double xf, int n) {
  double h = (xf - x1)/n;
  double sum = (fn(xi) + fn(xf))/2;
  for (int i = 1; i < n; i++) {
    sum += fn(xi + i*h);
  }
  return sum*h;
}
```

Siendo la integral de $\int_{x_{1}}^{x_{f}}fn$. Esta funcion es especifica,, deberiamos cambiar el tipo de funcion en la funcion de `c` para poder calcular multiples integrales, esto es, deberiamos copiar y pegar el codigo por cada integral de diferente funcion que queramos hacer. La idea es hacerlo generico, lo cual tendremos diversas tecnicas que haran uso de punteros:

La primera es intentar que la funcion integral funcione con todas las funciones que reciban un `double` y retornen un `double` (mismos tipos en otras palabras). Para esto lo que debemos hacer es poner el tipo de retorno, el nombre de la variable y todas las variables de la funcion, esto de la forma `(tip_retorno)(*var)(T1 var1, T2 var2, ...);` con `*var` siendo el nombre de la variable. De esta forma, la funcion integral seguiria:

``` c
double integral ((double)(*f)(double x), double xi, double xf, int n) {
  double h = (xf - x1)/n;
  // Cuando pasamos un puntero a una funcion, hay que desreferenciarlo.
  double sum = ((*f)(xi) + (*f)(xf))/2;
  for (int i = 1; i < n; i++) {
    sum += (*f)(xi + i*h);
  }
  return sum*h;
}
```

Esta funcion permitiendo integral cualquier funcion que tome y retorne un double.

Otra forma es utilizando `typedef`, para esto lo que tenemos que realizar es usar el tipo de retorno, el nuevo tipo y los parametros que reciba la funcion, esto de la forma: `typedef tipo_ret (*Nuevo_tipo)(T1 var1, T2 var2, ... );`, donde `Nuevo_tipo` representa a la funcion que reibe todo el corcho siguiente de las variables `T1 var 1....` y retorna algo del tipo `tipo_ret`. De esta forma nuestro ejemplo de la integral estaria dada por:

``` c
// Donde *Fun ya es un puntero
typedef double (*Fun)(double x);

// La funcion de la integral queda como:

// Aca esta la funcion con el tipo Fun definido previamente.
double integral (Fun f, double xi, double xf, int n) {
  double h = (xf - x1)/n;
  // Cuando pasamos un puntero a una funcion, hay que desreferenciarlo.
  double sum = ((*f)(xi) + (*f)(xf))/2;
  for (int i = 1; i < n; i++) {
    sum += (*f)(xi + i*h);
  }
  return sum*h;
}
```

Ahora, la otra opcion la razonaremos por una funcion que use polinomios:

``` c
double pol (double a, double b, double c, double x) {
  return a*x*x + b*x +c;
}
```

Donde queremos sacarle la integral, sin embargo esta funcion no cumple con el encabezado de la funcion integral original, por ende debemos hacer otra forma (**otra magia**), para lo cual deberiamos redefinir:

``` c
typedef double (*Fun)(double a, double b, double c, double x);
```

Para lo cual debemos crear una nueva funcion integral que reciba este parametro, es decir:

``` c
/* Funcion que retorne la integral de toda funcion que tome cuatro 
   cuatro doubles, necesitamos tomar las variables del polinomio. */
double integral2(Fun f, double a, double b, double c, double x1, double xf, int n) {
  double h = (xf - x1)/n;
  // Aca cambiamos la forma del llamado a la funcion.
  double sum = ((*f)(a, b, c, xi) + (*f)(a, b, c, xf))/2;
  for (int i = 1; i < n; i++) {
    sum += (*f)(a, b, c, xi + i*h);
  }
  return sum*h;
}
```

Ahora, esto puede ser aun mas generalizado, esto usando variables globales. Estas variables, definidas al inicio del codigo, son variables que existen desde su definicion hasta el termino de ejecucion de un codigo. Este tipo de variables se define como cualqueir otra variable:

``` c
// Variable global de nombre g_a
double g_a;
```

Este tipo de variables hay que tratarlas con cuidado, dado a que ante cualquier cambio puede alterarse todo el codigo. Lo que en este caos cambia es la inicializacion, puesto a que no puede inicializarse con cualquier valor, pues solo puede inicializarse con valores constantes, es decir, no pueden inicializarse con valores de variables. Esto es:

``` c
// Valido, pues es una constante.
double g_a = 10;

// No valido, pues depende de otra variable, en este caso, g_a.
double g_b = 2*g_a;
```

Indicacion, si se puede redefinir el valor en el codigo, esto siempre y cuando sea una constante. Este tipo de valores permite generalizar incluso mas las variables globales :

``` c
double g_a;
double g_b;
double g_c;

// Podemos generalizar para solo tener que recibir un valor x.
double pol2(double x) {
  return g_a*x*x + g_b *x + g_c;
}

/* Ahora podemos usar solo la funcion integral del inicio */
integra(pol2, xi, xf, n);
```

Mas aun, podemos definir una funcion `h` que haga el proceso:

``` c
// Opcion 1:
double h(double a, double b, double c, double xi, double xf, int n) {
  g_a = a;
  g_b = b;
  g_c = c;
  return integral(pol2, xi, xf, n);
}

// Opcion 2:
double h(Fun pol, double a, double b, double c, double xi, double xf, int n) {
  g_a = a;
  g_b = b;
  g_c = c;
  return integral(pol, xi, xf, n);
}

```

Ahora, como ultima forma tendremos la opcion de utilizar punteros opacos (**si, recien xd**), puntero que se caracteriza por ser del tipo que nosotros queramos y que podemos usar a conveniencia. Este tipo de puntero esta dado por `(void *)` y sera del tipo de la variable a la que apunta (**?**). Este tipo de puntero no puede ser desreferenciado y no puede acceder a ningun campo de una estructura (*siendo qeu es la gracia del puntero apuntar a estas estructuras). Ejemplo:

``` c
// Puntero 
void *ptr;

// Aca lo asignamos a una variable que me sirva.
// Creamos un puntero auxiliar que asignaremos de la variable al puntero opaco:
int *aux = ptr;
```

Para el caso de estructuras tenemos que:

``` c
typedef struct nodo {
  int x; 
  struct nodo *prox;
} Nodo;

void * ptr;
// Lo casteamos asociando a otro puntero, uno auxiliar.
Nodo * aux = ptr;
// De ahi se puede acceder a las componentes.
aux -> x;
```

[^1]: Ya no lo usamos pero lo vemos igual, se usa en sositos.
