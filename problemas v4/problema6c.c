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
double sumatoria(int n){
    double suma = 0;
    for (int i = 1; i<=n;i++){
        // pow(((1+sqrt(5))/2),n)-pow(((1-sqrt(5))/2),n)
        suma += (pow(((1+sqrt(5))/2),i)-pow(((1-sqrt(5))/2),i))/sqrt(5);
    }
    return suma;
}
/*
float fibonaci(int n){
    if (n>2){
        return fibonaci(n-1)+fibonaci(n-2);
    }
    return 1;
}   
*/
int main(){
    int n = 0;
    printf("Ingrese el n para la sumatoria: ");
    scanf("%i", &n);
    sumatoria(n);
    printf("La sumatoria es: %f \n", sumatoria(n));
    // printf("El resultado es: %f", fibonaci(n));

    return 0;
}