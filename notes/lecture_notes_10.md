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

Siendo la integral de $\int_{x_{1}}^{x_{f}}fn$. Esta funcion es especifica,, deberiamos cambiar el tipo de funcion en la funcion de `c` para poder calcular multiples integrales, esto es, deberiamos copiar y pegar el codigo por cada integral de diferente funcion que queramos hacer.

[^1]: Ya no lo usamos pero lo vemos igual, se usa en sositos.
