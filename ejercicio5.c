/*
Autor:      Javier de Leon
Fecha:      16/3/22
Compilador: gcc 12.0
Compilar: gcc -o ejercicio1.out ejercicio1.c
Librerías:  stdio
Resumen:    Algoritmo que detecta si un numero mayor a 1 es primo
*/
#include <stdio.h>

int main()
{
    int N;
    int i = 2;
    int primo = 1;
    printf("Ingrese un numero entero positivo: ");
    scanf("%d", &N);
    while (i < N - 1 && primo == 1)
    {
        if (N % i == 0)
        {
            primo = 0;
        }
        i++;
    }

    if (primo == 0)
    {
        printf("no es primo");
    }
    else
    {
        printf("es primo");
    }

    return 0;
}