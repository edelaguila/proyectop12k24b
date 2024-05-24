#ifndef PERSONAS_H
#define PERSONAS_H
#include <iostream>
#include"usuarios.h"

using namespace std;

class usualumnos
{
    public:
        void menu();
        void pideDatos();
        void muestraDatos();
        void editaDatos();
        void borraDatos();

    private:
        string nombre, contra;
};

#endif // PERSONAS_H
