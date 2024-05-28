<<<<<<< HEAD
#ifndef USUMAESTROS_H
#define USUMAESTROS_H
#include <iostream>

using namespace std;

class usumaestros
{
    public:
=======
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
>>>>>>> ca05d99806224de811dc8563d2fc77f0fe4bf8d6
        void menu();
        void pideDatos();
        void muestraDatos();
        void editaDatos();
        void borraDatos();

<<<<<<< HEAD
    private:
=======
    //Atributos privados
    private:
        //Variables
>>>>>>> ca05d99806224de811dc8563d2fc77f0fe4bf8d6
        string nombre, contra;
};

#endif // USUMAESTROS_H
