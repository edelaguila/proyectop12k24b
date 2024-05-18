#ifndef ASIGCURSOS_ALUMNOS_H
#define ASIGCURSOS_ALUMNOS_H
#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<cstdlib>
#include<conio.h>
#include<iomanip>
using namespace std;

class AsigCursos_Alumnos
{
    public:
       AsigCursos_Alumnos(string codigo_alumno,string nombre_alumno);

       string setCodigo(string codigo_alumno);
        string getCodigo();

        string setNombre(string nombre_alumno);
       string getNombre();


    void Menu_alumno();


    private:
         string codigo_alumno,nombre_alumno;

};



#endif // ASIGCURSOS_ALUMNOS_H
