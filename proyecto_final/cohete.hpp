/*
    Autor:      Javier de Leon
    Fecha:      19/7/22
    Compilador: gcc 12.0
    Compilar:   gcc -o ejercicio1.out ejercicio1.c
    Librerías:  stdio
    Resumen:    Cálculo del tiempo de vuelo, velocidad de un cohete en cierta altura y ciertas caracterísitcas particulares
*/

#if !defined cohete_h_
#define cohete_h_
#include <string>
class Cohete {
    public:
        std::string nombre_cohete;
        float Eo;
        float TSFC;
        float CD;
        float A;
        float mo;
        float mfo;

        Cohete(std::string nombre_cohete);
        void init();
        void mostrar_info();
};
#endif
