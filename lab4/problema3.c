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
#include <math.h>

// Vamos a definir una estructura abstracta con alias Coord para evitar usar dos
// arreglos

void magnitud(int v[3], int n){
    float suma = 0;
    for( int i = 0; i<3; i++){
        suma += pow((v[i]),2);

    }
    printf("La magnitud del vector %i es: %f \n",n,sqrt(suma));

}
void suma(int v1[3], int v2[3]){
    float suma = 0;
    for( int i = 0; i<3; i++){
        suma += v1[i]+v2[i];

    }
    printf("La suma es: %f \n",suma);

}
void dot(int v1[3], int v2[3]){
    float suma = 0;
    for( int i = 0; i<3; i++){
        suma += v1[i]*v2[i];

    }
    printf("El producto interno es: %f \n",suma);

}

void vect(int v1[3], int v2[3]){
    float v[3];
    v[0] = v1[1]*v2[2]-v2[1]*v2[2];
    v[1] = -(v1[0]*v2[2]-v2[0]*v1[2]);
    v[2] = v1[0]*v2[1]-v2[0]*v1[1];
    printf("La componente x del producto cruz es: %f\n",&v[0]);
    printf("La componente y del producto cruz es: %f\n",&v[1]);
    printf("La componente x del producto cruz es: %f\n",&v[2]);

}



int main(){
int v1[3];
int v2[3];
for(int i = 0; i<3;i++){
    printf("Input v1 %i coord: ",i+1);
    scanf("%i", &v1[i]);
    printf("Input v2 %i coord: ",i+1);
    scanf("%i", &v2[i]);

}
magnitud(v1,1);
magnitud(v2,2);
suma(v1,v2);
dot(v1,v2);
vect(v1,v2);
    return 0;
}