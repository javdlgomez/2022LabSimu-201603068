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