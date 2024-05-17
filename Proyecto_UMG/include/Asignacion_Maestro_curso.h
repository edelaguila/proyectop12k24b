#ifndef ASIGNACION_MAESTRO_CURSO_H
#define ASIGNACION_MAESTRO_CURSO_H
#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<cstdlib>
#include<conio.h>
#include<iomanip>
using namespace std;

class Asignacion_Maestro_curso
{
    public:
        Asignacion_Maestro_curso( string codigo_maestro,string nombre_maestro,string apellido_maestro, string sede,string aula,string seccion,string facultad,string carrera,string curso,string jornada,string horario);

       string setCodigo(string codigo_maestro);
        string getCodigo();

        string setNombre(string nombre_maestro);
       string getNombre();

     string setApellido(string apellido_maestro);
        string getApellido();

        string setSede(string sede);
        string getSede();

        string setAula(string aula);
        string getAula();

        string setSeccion(string seccion);
       string getSeccion();

        string setFacultad(string facultad);
        string getFacultad();

        string setCarrera(string carrera);
    string getCarrera();


        string setCurso(string curso);
        string getCurso();

        string setJornada(string jornada);
        string getJorada();

        string setHorario(string horario);
    string getHorario();


    void Menu_catedratico();
    void asignarse_curso();
    void actas();

    private:
         string codigo_maestro,nombre_maestro,apellido_maestro,sede,aula,seccion,facultad,carrera,curso,jornada,horario;

};

#endif // ASIGNACION_MAESTRO_CURSO_H
