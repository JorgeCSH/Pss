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
   cuatro doubles */
double integral2(Fun f, double a, double b, double c, double x1, double xf, int n) {
  double h = (xf - x1)/n;
  // Aca cambiamos la forma del llamado a la funcion.
  double
}
```

[^1]: Ya no lo usamos pero lo vemos igual, se usa en sositos.
