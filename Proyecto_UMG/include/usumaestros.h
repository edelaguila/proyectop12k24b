
//Creando por Andre Gonzalez 9959-23-3117

//Encabezados de proteccion
#ifndef USUMAESTROS_H
#define USUMAESTROS_H
//Incluyendo librerias
#include <iostream>
//Incluyendo encabezados
#include"usuarios.h"

using namespace std;

//Clase
class usumaestros
{
    //Atributos publicos
    public:
        //Funciones
        void menu();
        void pideDatos();
        void muestraDatos();
        void editaDatos();
        void borraDatos();

    //Atributos privados
    private:
        //Variables
        string nombre, contra;
};

#endif // USUMAESTROS_H
