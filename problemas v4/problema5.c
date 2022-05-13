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
#include<conio.h>
int factorial(int n){
    if (n <= 1){
        return(1);
    }

    return(n*factorial(n-1));

}
int main(){
    int num = 0;
    printf("ingrese el numero para el factorial:");
    scanf("%i",&num);
    printf("el factorial es: %i",factorial(num));




    return 0;
}
