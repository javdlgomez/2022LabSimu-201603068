/*
Autor:      Javier de Leon
Fecha:      16/3/22
Compilador: gcc 12.0
Compilar: gcc -o ejercicio1.out ejercicio1.c
Librerías:  stdio
Resumen:    Saca la media de 3 numeros
*/

#include <stdio.h>

int main(){

    int arr[5], x, y, temp;  


    printf("Ingrese los valores a guardar: ");

    for(x = 0; x < 5; x++)

        scanf("%d", &arr[x]);

    x = 0;

    while(x < 5){

        y = 0;        

        while(y < 5- x - 1){

            if(arr[y] > arr[y + 1]){

                temp = arr[y];

                arr[y] = arr[y + 1];

                arr[y + 1] = temp;

            }

            y++;

        }       

        x++;

    }   

    printf("Numeros ordenados: ");

    for(x = 0; x < 5; x++)

        printf("%d  \n", arr[x]);

    return 0;

}