/*
Autor:      Javier de Leon
Fecha:      16/3/22
Compilador: gcc 12.0
Compilar: gcc -o ejercicio1.out ejercicio1.c
Librerías:  stdio
Resumen:    Saca la media de 3 numeros
*/

#include <stdio.h>

int main() {
  int n = 0;
  float med = 0;
  int i = 0;

  // el primer ciclo se realiza sin comparacion
  do {
    float x = 0;
    printf("Ingresa el numero: ");
    scanf("%f", &x);
    if (x >= 0) {
      n++;
      med += x;
    }
    i++;
  }
  // ahora realizamos el loop
  while (i < 3);

  if (n == 0) {
    printf("no positivos");
  } else {
    printf("med/n %f", med / n);
  }
  /*
  int i, n, med, index = 0;
  int noMedia = 3;
  double arr[noMedia];
  int iter = noMedia;
  double *p = &arr[0];

      while (iter)
      {
          index++;
          printf("Ingresa el %d %s", (index), "numero:");
          scanf("%d", *p);
          iter--;
          p++;
      }
  */
  return 0;
}
