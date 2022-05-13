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
float sumatoria(int n){
    float suma = 0;
    for (int i = 1; i<=n;i++){
        suma += i*i*(i-3);
    }
    return suma;
}

int main(){
    int n = 0;
    printf("Ingrese el n para la sumatoria: ");
    scanf("%i", &n);
    printf("La sumatoria es: %f", sumatoria(n));


    return 0;
}
