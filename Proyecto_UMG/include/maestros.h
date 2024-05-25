
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
#include"usuarios.h"

using namespace std;

//Estructura del maestro
struct Maestro {

    char id[20];       // Almacena la id de los maestros ingresado
    char nombre[50];   // Almacena el nombre del maestro ingresado
    char Genero[10];   // Almacena el género del maestro ingresado
    char DPI[20];       // Almacena el DPI del maestro ingresado
    char direccion[100];  // Almacena la dirección del maestro ingresado
    char telefono[15];      // Almacena el número de teléfono del maestro ingresado
    char civil[20];         // Almacena el estado civil del maestro ingresado
    char fechanaci[20];     // Almacena la fecha de nacimiento del maestro ingresado
    char anoingre[10];      // Almacena el año de ingreso del maestro ingresado
};

struct proceamaestros {

    char id[20];
    char Actas[20];          // Almacena las actas de los maestros
    char Cuadernillos[50];   // Almacena los cuadernillos  del maestro ingresado
    char Asistencia[10];     // Almacena la asistencia del maestro ingresado
    char solvente[20];

};

//Creando la clase maestros
class maestros
{
    //Atributos privados de la clase maestros
    private:
    string id, nombre, telefono, DPI, direccion, Genero, civil, fechanaci, anoingre, Actas, Cuadernillos, Asistencia;

    //Atributos publicos de la clase maestros
    public:

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


        //Estableciendo el estado civil
        string setcivil(string civil);
        //Obteniendo el estado civil
        string getcivil();


        //Estableciendo la fecha de nacimiento
        string setfechanaci(string fechanaci);
        //Obteniendo la fecha de nacimiento
        string getfechanaci();


        //Estableciendo el año de ingreso
        string setanoingre(string anoingre);
        //Obteniendo el año de ingreso
        string getanoingre();

    //Funciones
    void menu(); //Funcion menu para poder mostar el menu de maestros
    void insertar(); //Funcion para insertar un nuevo maestro
    void desplegar();  //Funcion para poder desplegar los maestros registrados
    void modificar(); //Funcion para modificar un maestro registrado
    void buscar(); //Funcion para poder buscar un maestro por medio de la id
    void borrar(); //Funcion para poder borrar algun maestro registrado

};

#endif // MAESTROS_H
