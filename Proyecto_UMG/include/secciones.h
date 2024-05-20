<<<<<<< HEAD
//Creado por Rocio Guisell Lopez espinoza 9959-23-740
#ifndef SECCIONES_H
#define SECCIONES_H

=======
// Creado por Rocio Guisell Lopez espinoza 9959-23-740

// Comprueba si SECCIONES_H ya ha sido definido, si no, lo define
#ifndef SECCIONES_H
#define SECCIONES_H

// Incluye las bibliotecas est�ndar de C++ necesarias para el programa
>>>>>>> 7fee22e7c1a780459548acc106d5712411a3308b
#include<stdlib.h>
#include<cstdlib>
#include<conio.h>
#include<iomanip>

<<<<<<< HEAD
using namespace std;

=======

using namespace std;

// Define la estructura 'secciones' con los campos 'codigo', 'nombre' y 'estatus'
>>>>>>> 7fee22e7c1a780459548acc106d5712411a3308b
struct secciones
{
    int codigo;
    char nombre[45];
    char estatus[1];
};

<<<<<<< HEAD
=======
// Define la clase 'SeccionesCrud' con los m�todos p�blicos 'IngresarSeccion', 'ModificarSeccion', 'BorrarSeccion', 'DesplegarSeccion' y 'CrudSeccion'
>>>>>>> 7fee22e7c1a780459548acc106d5712411a3308b
class SeccionesCrud
{
    public:
        void IngresarSeccion();
        void ModificarSeccion();
        void BorrarSeccion();
        void DesplegarSeccion();
        void CrudSeccion();

};//fin de la clase aula

<<<<<<< HEAD
=======
// Fin de la comprobaci�n de la definici�n de SECCIONES_H
>>>>>>> 7fee22e7c1a780459548acc106d5712411a3308b
#endif // SECCIONES_H
