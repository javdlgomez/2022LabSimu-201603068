/*
Autor:      Javier de Leon
Fecha:      16/3/22
Compilador: gcc 12.0
Compilar: gcc -o ejercicio1.out ejercicio1.c
Librerías:  stdio
Resumen:
*/

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

float f(float x) { return (cos(x) / sin(x)); }
float new_rap(float x0, int n, float err) {
  float x = x0;
  float x2 = 0;
  float absErr = sqrt(pow(err, 2));
  for (int i = 0; i < n; i++) {
    x = x + sin(2 * x) / 2;
    x2 = pow(x, 2);
    if (absErr > sqrt(pow(f(x), 2))) {
      printf("iteraciones: %i\n", n);
      return printf("posible raiz %f\n", x);
    } else if (absErr < sqrt(pow(f(x), 2)) & i == (n - 1)) {
      return printf("No se obtuvo una aproximacion suficiente");
    }
  }
  return 0;
}

int main() {
  float x00, x0, err = 0;
  int n = 0;
  printf("ingrese el valor inicial: ");
  scanf("%f", &x0);
  printf("ingrese el numero de iteraciones: ");
  scanf("%i", &n);
  x00 = x0;
  printf("ingrese la tolerancia de error: ");
  scanf("%f", &err);
  // printf("posible raiz: %f", new_rap(x0, n,err));
  new_rap(x0, n, err);

  char bufferx[1024];
  snprintf(bufferx, sizeof(bufferx), "set xrange [%f:%f]", x00 - 5, x00 + 5);
  char buffery[1024];
  snprintf(buffery, sizeof(buffery), "set yrange [%f:%f]", f(x00) - 5,
           f(x00) + 5);
  FILE *fp = NULL;
  FILE *gnupipe = NULL;
  char *GnuCommands[] = {
      "set title \"presentacion2\"", bufferx, buffery,
      "plot 'PuntoInicial.tmp' title 'Posible Raiz NR', cos(x)/sin(x)", "save 'plotPres2.eps'"};

  fp = fopen("PuntoInicial.tmp", "w");
  gnupipe = _popen("gnuplot -presistent", "w");

  fprintf(fp, "%f %f\n", x0, f(x0));
  for (int i = 0; i < 5; i++) {

    fprintf(gnupipe, "%s\n", GnuCommands[i]);
  }
  return 0;
}