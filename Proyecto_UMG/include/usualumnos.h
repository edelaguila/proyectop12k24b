<<<<<<< HEAD
#ifndef PERSONAS_H
#define PERSONAS_H
#include <iostream>

using namespace std;

class usualumnos
{
    public:
=======
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
>>>>>>> ca05d99806224de811dc8563d2fc77f0fe4bf8d6
        void menu();
        void pideDatos();
        void muestraDatos();
        void editaDatos();
        void borraDatos();

<<<<<<< HEAD
=======
    //Atributos privados
>>>>>>> ca05d99806224de811dc8563d2fc77f0fe4bf8d6
    private:
        string nombre, contra;
};

#endif // PERSONAS_H
