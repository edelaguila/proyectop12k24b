//Encabezados de proteccion
#ifndef PROCESOMAESTROS_H
#define PROCESOMAESTROS_H

//Incluyendo librerias
#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<cstdlib>
#include<conio.h>
#include<iomanip>

using namespace std;

//Creamos la clase ProcesoMaestros
class ProceMaestros
{
    //Atributos privados de la clase maestros
    private:
    string Actas, Cuadernillos, Asistencia;

    //Atributos publicos de la clase maestros
    public:

        //Constructores
        ProceMaestros() {}
        ProceMaestros(string Actas, string Cuadernillos, string Asistencia);

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

    //Funciones
    void menu();
    void insertar();

    //Estructura del procesomaestros
    struct proceamaestros {

    char Actas[20];          // Almacena las actas de los maestros
    char Cuadernillos[50];   // Almacena los cuadernillos  del maestro ingresado
    char Asistencia[10];     // Almacena la asistencia del maestro ingresado

};
};

#endif // PROCESOMAESTROS_H
