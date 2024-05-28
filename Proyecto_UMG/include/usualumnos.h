
//Creando por Andy Garcia 9959-23-1494

//Encabezados de proteccion
#ifndef PERSONAS_H
#define PERSONAS_H
//Inlcuyendo librerias
#include <iostream>
//Incluyendo encabezado
#include"usuarios.h"

using namespace std;

//Clase
class usualumnos
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
        string nombre, contra;
};

#endif // PERSONAS_H
