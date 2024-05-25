//Encabezados de proteccion
#ifndef PROCEALUMNOS_H
#define PROCEALUMNOS_H

//Librerias
#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<cstdlib>
#include<conio.h>
#include<iomanip>
//Incluyendo encabezados
#include"usuarios.h"


using namespace std;

struct Alumno {

    char id[20];          // Almacena la id de los alumnos ingresados
    char nombre[50];      // Almacena el nombre  del alumno ingresado
    char Genero[10];      // Almacena el género del alumno ingresado
    char DPI[20];         // Almacena el DPI del alumno ingresado
    char direccion[100];  // Almacena la dirección del alumno ingresado
    char nacionalidad[50];// Almacena la nacionalidad del alumno ingresado
    char telefono[15];    // Almacena el número de teléfono del alumno ingresado
    char civil[20];       // Almacena el estado civil del alumno ingresado
    char fechanaci[20];   // Almacena la fecha de nacimiento del alumno ingresado
    char anoingre[10];    // Almacena el año de ingreso del alumno ingresado
};

//Clase procealumnos
class procealumnos
{
    //Atributos privados
    private:
    //Variables
    string id, nombre, telefono, DPI, direccion, Genero, nacionalidad, civil, fechanaci, anoingre, dpi , certiestudios, fotoestatica, titulo, fotocedula, copiadpi;

    //Atributos Publicos
    public:

        //Variable string
        string solvente;
        //constructores y sus parametros
        procealumnos() {}
        procealumnos(string dpi, string certiestudios, string fotoestatica, string titulo, string fotocedula, string copiadpi, string id, string nombre, string telefono, string DPI, string direccion, string Genero, string nacionalidad, string civil, string fechanaci, string anoingre, string solvente);

        //Estableciendo y obteniendo dpi
        string setdpi(string dpi);
        string getdpi();

        //Estableciendo y obteniendo certificado de estudios
        string setcertiestudios(string certiestudios);
        string getcertiestudios();

        //Estableciendo y obteniendo la foto estatica
        string setfotoestatica(string fotoestatica);
        string getcfotoestatica();

        //Estableciendo y obteniendo titulo
        string settitulo(string titulo);
        string gettitulo();

        //Estableciendo y obteniendo fotocedula
        string setfotocedula(string fotocedula);
        string gettfotocedula();

        //Estableciendo y obteniendo copiadpi
        string setcopiadpi(string copiadpi);
        string getcopiadpi();

        //Estableciendo y obteniendo id
        string setid(string id);
        string getid();


        //Estableciendo el nombre
        string setnombre(string nombre);
        //obteniendo el nombre
        string getnombre();


        //Estableciendo el numero del telefono
        string setTelefono(string telefono);
        //obteniendo el numero del telefono
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

        //Estableciendo la nacionalidad
        string setnacionalidad(string nacionalidad);
        //Obteniendo la nacionalidad
        string getnacionalidad();


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

        string setsolvente(string solvente);
        //Obteniendo el año de ingreso
        string getsolvente();

    //Funciones
    void menu();
    void insertar();
    bool validarCarnet();
    void mostrarmenu();


    //Estructura proceso alumnos
    struct Procealumnos {

    char dpi[20];              // Almacena el número de DPI (Documento Personal de Identificación) del usuario.
    char certiestudios[50];    // Almacena información relacionada con la certificación de estudios del usuario.
    char fotoestatica[10];     // Almacena información sobre una foto estática del usuario.
    char titulo[20];           // Almacena información relacionada con el título del usuario.
    char fotocedula[100];      // Almacena información relacionada con una foto de la cédula del usuario.
    char copiadpi[50];         // Almacena información relacionada con una copia del DPI del usuario al 200%.
    char solvente[20];         // Almacena información sobre el estado de solvencia del usuario.

};
};

#endif // PROCEALUMNOS_H
