/*
Autor:      Javier de Leon
Fecha:      16/3/22
Compilador: gcc 12.0
Compilar: gcc -o ejercicio1.out ejercicio1.c
Librerías:  stdio
Resumen:    Calculamos la raiz cuadrada entera de un numero positivo
*/
#include <stdio.h>

int main() {
  int R = 0;
  float N = 0;
  int i = 1;
  printf("Ingrese un numero positivo: ");
  scanf("%f", &N);
  while (i * i <= N) {
    i++;
  }
  printf("%i", i - 1);
  return 0;
}