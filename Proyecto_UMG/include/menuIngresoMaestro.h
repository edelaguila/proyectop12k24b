//By Ruddyard Eduardo Castro Chavez

#ifndef MENUINGRESOMAESTRO_H
#define MENUINGRESOMAESTRO_H


// Incluye la biblioteca iostream que permite la entrada y salida de datos
#include<iostream>
// Incluye la biblioteca fstream que permite la lectura y escritura de archivos
#include<fstream>
// Incluye la biblioteca stdlib que proporciona funciones generales de utilidad
#include<stdlib.h>
// Incluye la biblioteca cstdlib que proporciona funciones generales de utilidad
#include<cstdlib>
// Incluye la biblioteca conio.h que proporciona funciones para controlar la entrada y salida de la consola
#include<conio.h>
// Incluye la biblioteca iomanip que proporciona funciones para manipular la salida formateada
#include<iomanip>

// Utiliza el espacio de nombres estándar. Esto evita tener que escribir std:: antes de cada uso de objetos
using namespace std;

// Define una clase llamada menuIngresoMaestro
class menuIngresoMaestro
{
    public:
        // Declara una función miembro llamada VerificarCarnet que devuelve un valor booleano (verdadero o falso)
        bool VerificarCarnet();
        // Declara una función miembro llamada Login que toma un string como argumento
        Login(string usuarios);

        // Declara una función miembro llamada setUser que toma un string como argumento y devuelve un string
        string setUser(string usuarios);
        // Declara una función miembro llamada getUser que devuelve un string
        string getUser();

    private:
        // Declara una variable miembro llamada usuarios de tipo string
        string usuarios;
};


#endif // MENUINGRESOMAESTRO_H
