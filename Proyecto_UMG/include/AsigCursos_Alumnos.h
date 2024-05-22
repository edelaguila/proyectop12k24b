#ifndef ASIGCURSOS_ALUMNOS_H
#define ASIGCURSOS_ALUMNOS_H

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

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

class AsigCursos_Alumnos {
private:
    string codigo_alumno, nombre_Alumno, nom_Alumno, curso, jornada, aula, seccion, nacionalidad, id;

public:
    AsigCursos_Alumnos() {}
    AsigCursos_Alumnos(string id, string codigo_alumno, string nombre_Alumno, string nom_Alumno, string curso, string jornada, string aula, string seccion, string nacionalidad);

    string setid(string id);
    // obteniendo la id
    string getid();

    string setnom_Alumno(string nom_Alumno);
    string getnom_alumno();

    string setcurso(string curso);
    string getcurso();

    string setjornada(string jornada);
    string getjornada();

    string setaula(string aula);
    string getaula();

    string setseccion(string seccion);
    string getseccion();

    string setnacionalidad(string nacionalidad);
    string getnacionalidad();

    void desplegarBoleta();
    void Menu_alumno();
    void asignacion_alumno();
    void mostrar_cursos();
    void validarCarnet();

    struct Asig_al {
        char nom_alumno[100];
        char curso[100];
        char jornada[50];
        char aula[100];
        char seccion[100];
    };
};

#endif // ASIGCURSOS_ALUMNOS_H
