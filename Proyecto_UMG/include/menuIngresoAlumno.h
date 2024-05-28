//By Ruddyard Eduardo Castro Chavez

#ifndef MENUINGRESOALUMNO_H
#define MENUINGRESOALUMNO_H

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

// Utiliza el espacio de nombres estándar. Esto evita tener que escribir std:: antes de cada uso de objetos de la biblioteca estándar
using namespace std;

// Define una clase llamada menuIngresoAlumno
class menuIngresoAlumno
{
    // Los siguientes miembros son públicos, lo que significa que pueden ser accedidos desde fuera de la clase
    public:
        // Declara una función miembro llamada VerificarCarnet que devuelve un valor booleano (verdadero o falso)
        bool VerificarCarnet();
        // Declara una función miembro llamada Login que toma un string como argumento
        Login(string usuarios);

        // Declara una función miembro llamada setUser que toma un string como argumento y devuelve un string
        string setUser(string usuarios);
        // Declara una función miembro llamada getUser que devuelve un string
        string getUser();

    // Los siguientes miembros son privados, lo que significa que solo pueden ser accedidos desde dentro de la clase
    private:
        // Declara una variable miembro llamada usuarios de tipo string
        string usuarios;
};


#endif // MENUINGRESOALUMNO_H
