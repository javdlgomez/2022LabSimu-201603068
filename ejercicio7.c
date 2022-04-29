/*
Autor:      Javier de Leon
Fecha:      16/3/22
Compilador: gcc 12.0
Compilar: gcc -o ejercicio1.out ejercicio1.c
Librerías:  stdio
Resumen:    calcula el area de area de un poligono con user inputs, deben darse
el numero de vertices y sus coordenadas (x,y) en sentido anti horario
*/
#include <stdio.h>

// Vamos a definir una estructura abstracta con alias Coord para evitar usar dos
// arreglos

typedef struct coord {
  float x;
  float y;
} Coord;

// Aqui realizamos el algoritmo, ya que lo que queremos es realizar los
// determinantes a pares podemos escoger inteligentemente que la posicion dada
// en el arreglo este operada por el modulo
//  de el largo del mismo para poder obtener la ultima componente sin necesidad
//  de agregar un termino
// a nuestra definicion de sumatoria para el area

float getArea(Coord coords[], int length) {
  float summation = 0;
  for (int i = 0; i < length; i++) {
    Coord v1 = coords[i];
    Coord v2 = coords[(i + 1) % length];

    // esta impresion nos da los resultados parciales de
    // nuestro algoritmo, puede comentarse
    printf("%d.x=%f * %d.y=%f - %d.x=%f * %d.y=%f\n", i, v1.x, (i + 1) % length,
           v2.y, (i + 1) % length, v2.x, i, v1.y);
    summation += v1.x * v2.y - v2.x * v1.y;
  }
  return summation / 2;
}

int main() {
  int n;

  printf("Input vertices count: ");
  scanf("%d", &n);
  Coord coords[n];
  // aqui llenamos nuestra estructura abstracta con user inupt
  for (int i = 0; i < n; i++) {
    Coord vertice;
    printf("Input x coord: ");
    scanf("%f", &vertice.x);
    printf("Input y coord: ");
    scanf("%f", &vertice.y);
    // esto puede comentarse
    printf("Vertice #%d {x=%f, y=%f}\n", i + 1, vertice.x, vertice.y);
    coords[i] = vertice;
  }
  printf("\n");
  printf("%f", getArea(coords, n));
  return 0;
}