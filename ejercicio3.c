/*
Autor:      Javier de Leon
Fecha:      16/3/22
Compilador: gcc 12.0
Compilar: gcc -o ejercicio1.out ejercicio1.c
Librerías:  stdio
Resumen:    Suma alturas dadadas y se detiene al llegar a una negativa
*/
#include <stdio.h>

int main()
{
    int n = 0;
    float med, x, max, min = 0;
    printf("Coloque una altura: ");
    scanf("%f", &x);
    max = x;
    min = x;

    //realizamos el loop hasta que den una altura negativa
    while (x >= 0)
    {
        n++;
        med = med + x;
        if (x > max)
        {
            max = x;
        }
        if (x < min)
        {
            min = x;
        }
        printf("Coloque una altura: ");
        scanf("%f", &x);
    }
    if (n == 0)
    {

        printf("no positivos");
    }
    else
    {
        printf("media: %f\nmax: %f\nmin: %f", med / n, max, min);
    }
    return 0;
}