/*
    Autor:      Javier de Leon
    Fecha:      19/7/22
    Compilador: gcc 12.0
    Compilar:   gcc -o ejercicio1.out ejercicio1.c
    Librerías:  stdio
    Resumen:    Cálculo del tiempo de vuelo, velocidad de un cohete en cierta altura y ciertas caracterísitcas particulares
*/

//incluimos la libreria que hicimos
#include "cohete.hpp"
#include <cstdio>

//separamos la clase del constructor con ::
Cohete::Cohete(std::string nombre_cohete)
{
    //aquí usamos flechas en vez de puntos porque queremos deferenciar los pointers
    this->nombre_cohete = nombre_cohete;
    this->Eo = this->TSFC = this->CD = this->A = this->mo = this->mfo = 0.0f;
}

//de nuevo separamos la clase del init
void Cohete::init()
{

    //abrimos el archivo como lectura
    FILE* archivo = fopen(this->nombre_cohete.c_str(), "r");
    if(archivo == NULL)
    {
        printf("Error al abrir el archivo '%s'", nombre_cohete.c_str());
        //control de error
        exit(-1);
    }
// aquí hay que tener cuidado porque estamos suponiendo que la base de datos está ordenada y no tiene errores
// ppero para esta aplicación es suficiente 
    fscanf(archivo, "%f", &this->Eo);
    fscanf(archivo, "%f", &this->TSFC);
    fscanf(archivo, "%f", &this->CD);
    fscanf(archivo, "%f", &this->A);
    fscanf(archivo, "%f", &this->mo);
    fscanf(archivo, "%f", &this->mfo);

    fclose(archivo);
}



//este metodo es el que imprime en consola
void Cohete::mostrar_info()
{
    printf("\n\nCohete: %s\n", this->nombre_cohete.c_str());
    printf("Eo: %f\n", this->Eo);
    printf("TSFC: %f\n", this->TSFC);
    printf("CD: %f\n", this->CD);
    printf("A: %f\n", this->A);
    printf("mo: %f\n", this->mo);
    printf("mfo: %f\n", this->mfo);
}

int main()
{
    //les vamos a agregar la extensión .txt a los archivos 
    Cohete cohete1("Ah Mun.txt");
    Cohete cohete2("Ahau Kin.txt");
    Cohete cohete3("Chac.txt");


//le damos los valores a los miembros de la clase de nuestra base de datos
    cohete1.init();
    cohete2.init();
    cohete3.init();
//impriimmos
    cohete1.mostrar_info();
    cohete2.mostrar_info();
    cohete3.mostrar_info();

    return 0;
}
