
//Creando por Andre Gonzalez 9959-23-3117

//Encabezados de proteccion
#ifndef MAESTROS_H
#define MAESTROS_H

//Incluyendo librerias a utilizar
#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<cstdlib>
#include<conio.h>
#include<iomanip>
<<<<<<< HEAD
#include"usuarios.h"

using namespace std;

<<<<<<< HEAD
=======
//Estructura del maestro
>>>>>>> ca05d99806224de811dc8563d2fc77f0fe4bf8d6
=======


using namespace std;

>>>>>>> 1a8b285e44e22ebebc8e610ca110e2ec22da6084
struct Maestro {

    char id[20];       // Almacena la id de los maestros ingresado
    char nombre[50];   // Almacena el nombre del maestro ingresado
<<<<<<< HEAD
    char Genero[10];   // Almacena el género del maestro ingresado
    char DPI[20];       // Almacena el DPI del maestro ingresado
    char direccion[100];  // Almacena la dirección del maestro ingresado
<<<<<<< HEAD
    char nacionalidad[50];  // Almacena la nacionalidad del maestro ingresado
=======
>>>>>>> ca05d99806224de811dc8563d2fc77f0fe4bf8d6
    char telefono[15];      // Almacena el número de teléfono del maestro ingresado
    char civil[20];         // Almacena el estado civil del maestro ingresado
    char fechanaci[20];     // Almacena la fecha de nacimiento del maestro ingresado
    char anoingre[10];      // Almacena el año de ingreso del maestro ingresado
};
<<<<<<< HEAD
=======

struct proceamaestros {

    char id[20];
    char Actas[20];          // Almacena las actas de los maestros
    char Cuadernillos[50];   // Almacena los cuadernillos  del maestro ingresado
    char Asistencia[10];     // Almacena la asistencia del maestro ingresado
    char solvente[20];

};
>>>>>>> ca05d99806224de811dc8563d2fc77f0fe4bf8d6
=======
    char Genero[10];   // Almacena el gï¿½nero del maestro ingresado
    char DPI[20];       // Almacena el DPI del maestro ingresado
    char direccion[100];  // Almacena la direcciï¿½n del maestro ingresado
    char nacionalidad[50];  // Almacena la nacionalidad del maestro ingresado
    char telefono[15];      // Almacena el nï¿½mero de telï¿½fono del maestro ingresado
    char civil[20];         // Almacena el estado civil del maestro ingresado
    char fechanaci[20];     // Almacena la fecha de nacimiento del maestro ingresado
    char anoingre[10];      // Almacena el aï¿½o de ingreso del maestro ingresado
};
>>>>>>> 1a8b285e44e22ebebc8e610ca110e2ec22da6084

//Creando la clase maestros
class maestros
{
    //Atributos privados de la clase maestros
    private:
<<<<<<< HEAD
    string id, nombre, telefono, DPI, direccion, Genero, civil, fechanaci, anoingre, Actas, Cuadernillos, Asistencia;
=======
    string id, nombre, telefono, DPI, direccion, Genero, nacionalidad, civil, fechanaci, anoingre;
>>>>>>> 1a8b285e44e22ebebc8e610ca110e2ec22da6084

    //Atributos publicos de la clase maestros
    public:

<<<<<<< HEAD
        string solvente;
        //Constructores
        maestros() {}
        maestros(string Actas, string Cuadernillos, string Asistencia, string id, string nombre, string telefono, string DPI, string direccion, string Genero, string civil, string fechanaci, string anoingre, string solvente);

        string setsolvente(string solvente);
        //Obteniendo el año de ingreso
        string getsolvente();

        //Estableciendo las actas
        string setActas(string Actas);

        //obteniendo las actas
        string getActas();

        //Estableciendo los cuadernillos
        string setCuadernillos(string Cuadernillos);

        //obteniendo los cuadernillos
        string getCuadernillos();

        //Estableciendo la asistencia
        string setAsistencia(string Asistencia);

        //obteniendo la asistencia
        string getAsistencia();

=======
        //Constructores
        maestros() {}
        maestros(string id, string nombre, string telefono, string DPI, string direccion, string Genero, string nacionalidad, string civil, string fechanaci, string anoingre);
>>>>>>> 1a8b285e44e22ebebc8e610ca110e2ec22da6084

        //Estableciendo la id
        string setid(string id);
        //Obteniendo la id
        string getid();


        //Estableciendo el nombre
        string setnombre(string nombre);
        //Obteniendo el nombre
        string getnombre();


        //Estableciendo el numero de telefono
        string setTelefono(string telefono);
        //Obteniendo el numero de telefono
        string getTelefono();


        //Estableciendo el DPI
        string setDPI(string DPI);
        //Obteniendo el DPI
        string getDPI();


        //Estableciendo la direccion
        string setdireccion(string direccion);
        //Obteniendo la direccion
        string getdireccion();


        //Estableciendo el genero
        string setGenero(string Genero);
        //Obteniendo el genero
        string getGenero();


<<<<<<< HEAD
=======
        //Estableciendo la nacionalidad
        string setnacionalidad(string nacionalidad);
        //Obteniendo la nacionalidad
        string getnacionalidad();


>>>>>>> 1a8b285e44e22ebebc8e610ca110e2ec22da6084
        //Estableciendo el estado civil
        string setcivil(string civil);
        //Obteniendo el estado civil
        string getcivil();


        //Estableciendo la fecha de nacimiento
        string setfechanaci(string fechanaci);
        //Obteniendo la fecha de nacimiento
        string getfechanaci();


<<<<<<< HEAD
        //Estableciendo el año de ingreso
        string setanoingre(string anoingre);
        //Obteniendo el año de ingreso
=======
        //Estableciendo el aï¿½o de ingreso
        string setanoingre(string anoingre);
        //Obteniendo el aï¿½o de ingreso
>>>>>>> 1a8b285e44e22ebebc8e610ca110e2ec22da6084
        string getanoingre();

    //Funciones
    void menu(); //Funcion menu para poder mostar el menu de maestros
    void insertar(); //Funcion para insertar un nuevo maestro
    void desplegar();  //Funcion para poder desplegar los maestros registrados
    void modificar(); //Funcion para modificar un maestro registrado
    void buscar(); //Funcion para poder buscar un maestro por medio de la id
    void borrar(); //Funcion para poder borrar algun maestro registrado

<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> 1a8b285e44e22ebebc8e610ca110e2ec22da6084

    //Estructura del maestro

};

<<<<<<< HEAD
=======
};
>>>>>>> ca05d99806224de811dc8563d2fc77f0fe4bf8d6
=======
>>>>>>> 1a8b285e44e22ebebc8e610ca110e2ec22da6084

#endif // MAESTROS_H
