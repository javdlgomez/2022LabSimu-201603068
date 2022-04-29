/*
Autor:      Javier de Leon
Fecha:      16/3/22
Compilador: gcc 12.0
Compilar: gcc -o ejercicio1.out ejercicio1.c
Librerías:  stdio
Resumen:    Encuentra todos los numeros primos entre un rango de enteros
*/
#include <stdio.h>

// Declaramos un metodo con el algoritmo
// del ejercicio5
int Es_primo(int i) {
  int j = 2;
  int primo = 1;

  while (j < i - 1 && primo == 1) {
    if (i % j == 0) {
      primo = 0;
    }
    j++;
  }
  return primo;
}

int main() {
  int N1, N2, i;
  printf("ingrese el rango inferior: ");
  scanf("%i", &N1);
  printf("ingrese el rango superior: ");
  scanf("%i", &N2);
  // ahora que ya sabemos el rango de enteros
  // realizamos el procedimiento de busqueda de
  // primos para todos los numeros dentro del rango
  for (int i = N1; i <= N2; i++) {

    int primo = Es_primo(i);
    if (primo == 1) {
      printf("%i ", i);
    }
  }

  return 0;
}