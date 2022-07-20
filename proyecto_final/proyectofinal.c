/*
    Autor:      Javier de Leon
    Fecha:      19/7/22
    Compilador: gcc 12.0
    Compilar:   gcc -o ejercicio1.out ejercicio1.c
    Librerías:  stdio
    Resumen:    Cálculo del tiempo de vuelo, velocidad de un cohete en cierta altura y ciertas caracterísitcas particulares
*/

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declaramos las constantes
const float G = 6.693e-11;
const float Rt = 6.378e+6;
const float Mt = 5.9736e+24;
const float R = 287.06;
const float L = 6.5e-3;
const float go = 9.81;
const float To = 288.15;
const float Po = 101325;
const float Ho = 0.68;

// Declaramos variables globales

float Eo, TSFC, CD, A, mo, mfo;

// Este es el método de euler en el que evaluamos la derivada

float dv(float v, float y, float t)
{
    float E = Eo;
    float rho = Po/(R+To)*pow((1-L*y/To), go/(Rt*L));
    float g = G*Mt/pow((Rt+y),2);
    float m = mo+mfo-TSFC*Eo*t;

//Los valores de la densidad y el empuje cambian conforme avanza la simulación

    if(t >= mfo/(TSFC*Eo)){
        E = 0;
        m = mo;
    }
    if(y >= To/L)
        rho = 0;

    // printf("E: %f rho: %f g: %f m: %f t: %f \n",E,rho,g,m,t);

    return E-(1/2)*rho*CD*A*v*v-m*g;
}  

int main(void) {

// Iniciamos las variables de usuario para abrir el archivo con los datos necesarios.

    float delta = 0.1;
    float t,v = 0;
    float y = Ho;

    char nombre_cohete[100];
    memset(nombre_cohete, 0, 100);

    printf("Ingresa el nombre del Cohete con Extension txt: ");
    
// Cambiar el input para que de automaticamente el txt es mas trabajo de lo necesario

    gets(nombre_cohete);

    FILE* fp = fopen(nombre_cohete, "r");

    // Control de error si existe el archivo
    if (fp == NULL)
    {
        printf("\n No existe el cohete\n");
        exit(-1);
    }
//Aqui leemos los archivos, el problema es que deben estar ordenados en nuestra base de datos
//porque no se hace ninguna comparacion solo se agregan los valores
    fscanf(fp, "%f", &Eo);
    fscanf(fp, "%f", &TSFC);
    fscanf(fp, "%f", &CD);
    fscanf(fp, "%f", &A);
    fscanf(fp, "%f", &mo);
    fscanf(fp, "%f", &mfo);

    fclose(fp);


    /*
    Estos prints son de control para ver que todo este funcionando en orden

    printf("Eo = %f\n", Eo);
    printf("TSFC  = %f\n", TSFC);
    printf("CD  = %f\n", CD);
    printf("A  = %f\n", A);
    printf("mo  = %f\n", mo);
    printf("mfo  = %f\n", mfo);
    */
   
    // Función principal
    FILE *pftvsy = fopen("cohetedattvsy", "w");
    FILE *pftvsv = fopen("cohetedattvsv", "w");
    FILE *pfyvsv = fopen("cohetedatyvsv", "w");

    int jota = 0;
    int contador = 200;

    //si uso while y>0 si el cohete no regresa la simuaclión nunca termina
    while (jota<contador)
    {
        fprintf(pftvsy, "%.2f\t %.2f\t\n",y,t);
        fprintf(pftvsv, "%.2f\t %.2f\t\n",v,t);
        fprintf(pfyvsv, "%.2f\t %.2f\t\n",y,v);

        // Ejecutar el método numérico
        v=v+delta*dv(v,y,t);
        y = y+delta*v;
        t+=delta;
        jota+=1;
        // Esto nos termina la función si el cohete regresa y nos da el tiempo de choque
        if (y == 0){
            printf("El tiempo de choque es: %.2f\n",t/60 );
            break;
        
        }
    }
    // Escribimos los archivos, escribo en 2 columnas para que me sea fácil graficar
    fprintf(pftvsy,"%.2f\t%.2f\t",y,t);
    fprintf(pftvsv,"%.2f\t%.2f\t",v,t);
    fprintf(pfyvsv,"%.2f\t%.2f\t",y,v);
    fclose(pftvsv);
    fclose(pftvsy);
    fclose(pfyvsv);

    float tiempo =  mfo/(TSFC*Eo);
    printf("Altura maxima: %f\n",y);
    printf("Nombre del Cohete: %s\n ",nombre_cohete);
    printf("Caracteristicas del cohete: \n Eo: %.2f\n TSFC: %.2f\n CD: %.2f\n A: %.2f\n mo: %.2f\n mfo: %.2f\n", Eo, TSFC,CD, A, mo, mfo);
    printf("Instante donde se termina el combustible: %.2f", tiempo/60);

    system("gnuplot graficatvsy.gp");
    system("gnuplot graficatvsv.gp");
    system("gnuplot graficayvsv.gp");

    return 0;
}