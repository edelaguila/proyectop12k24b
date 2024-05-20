#include "AsigCursos_Alumnos.h"
#include "Login_Alumno.h"
#include "Carrera.h"
#include "aulas.h"
#include "secciones.h"
#include "Facultad.h"
#include "Cursoss.h"
#include "jornada.h"
#include "catalogo.h"
#include "alumnos.h"
#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<cstdlib>
#include <cstring>
#include<conio.h>
#include<iomanip>
#include<string>

using namespace std;

AsigCursos_Alumnos::AsigCursos_Alumnos(string codigo_alumno, string nombre_Alumno, string nom_Alumno, string curso, string jornada, string aula, string seccion, string nacionalidad, string id)
{
    this-> id = id;
    this->codigo_alumno = codigo_alumno;
    this->nombre_Alumno = nombre_Alumno;
    this->curso = curso;
    this->nom_Alumno = nom_Alumno;
    this->jornada = jornada;
    this->aula = aula;
    this->seccion = seccion;
    this->nacionalidad = nacionalidad; // Corregido
}

string AsigCursos_Alumnos::setid(string id)
{
    this -> id = id;
    return id;
}

string AsigCursos_Alumnos::getid()
{
    return id;
}

string AsigCursos_Alumnos::setnom_Alumno(string nom_Alumno)
{
    this->nom_Alumno = nom_Alumno;
    return nom_Alumno;
}
string AsigCursos_Alumnos::getnom_alumno()
{
   return nom_Alumno;
}

string AsigCursos_Alumnos::setcurso(string curso)
{
    this->curso = curso;
    return curso;
}
string AsigCursos_Alumnos::getcurso()
{
    return curso;
}

string AsigCursos_Alumnos::setjornada(string jornada)
{
    this->jornada = jornada;
    return jornada;
}
string AsigCursos_Alumnos::getjornada()
{
    return jornada;
}

string AsigCursos_Alumnos::setaula(string aula)
{
    this->aula = aula;
    return aula;
}

string AsigCursos_Alumnos::getaula()
{
    return aula;
}


string AsigCursos_Alumnos::setseccion(string seccion)
{
    this->seccion = seccion;
    return seccion;
}

string AsigCursos_Alumnos::getseccion()
{
    return seccion;
}


string AsigCursos_Alumnos::setnacionalidad(string nacionalidad)
{
    this->nacionalidad = nacionalidad;
    return nacionalidad;
}

string AsigCursos_Alumnos::getnacionalidad()
{
    return nacionalidad;
}

void AsigCursos_Alumnos::Menu_alumno() {
    //variables de user y contraseña
    string user, contrasena;
    //llamamos al objeto e ingresamos los parametros
    Login_Alumno ingreso(user, contrasena);

    //creamos un bool que verifique y despliegue el metodo verificarUsuario
    bool UsuarioCorrecto = ingreso.VerificarUsuario();

    //luego de ingresar con usuario y contraseña se nos despliega otro menu
    if (UsuarioCorrecto) {
        int opcion;
        do {
            system("cls");

            cout << "\t\t\t+------------------------------------------+" << endl;
            cout << "\t\t\t|   BIENVENIDO A NUESTRO MENU DE ALUMNOS   |" << endl;
            cout << "\t\t\t+------------------------------------------+" << endl;
            cout << "\t\t\t|1. Asignarse a Cursos                     |" << endl;
            cout << "\t\t\t|2. Imprimir boleta de asignacion          |" << endl;
            cout << "\t\t\t|3. regresar al menu anterior              |" << endl;
            cout << "\t\t\t+------------------------------------------+" << endl;
            cout << "\t\t\t|Opcion a escoger:[1/2/3]              |" << endl;
            cout << "\t\t\t+------------------------------------------+" << endl;
            cout << "\t\t\tIngresa tu Opcion: ";
            cin >> opcion;

            switch (opcion) {
            case 1: {
                validarCarnet();

                break;
            }

            case 2:
                desplegarBoleta();
                break;

            case 3:
                break;

            default:
                cout << "\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
                break;
            }
        } while (opcion != 3);
    }
}

void AsigCursos_Alumnos::validarCarnet() {
    system("cls");
    fstream archivo;
    string idPersona;
    bool encontrado = false;

    cout << "+---------------------------------------------------------------------------------+" << endl;
    cout << "+                     BIENVENIDO A NUESTRA VALIDACION                             +" << endl;
    cout << "+---------------------------------------------------------------------------------+" << endl;

    archivo.open("Alumnos.dat", ios::binary | ios::in | ios::out); // Removed ios::app mode, as we are only reading here
    if (!archivo) {
        cout << "Error, no se encuentra informacion...";
        return;
    }

    cout << "Ingrese su numero de carnet: ";
    cin >> idPersona;

    Alumno alumno;

    while (archivo.read(reinterpret_cast<char*>(&alumno), sizeof(Alumno))) {
        if (alumno.id == idPersona) {
            encontrado = true;
            cout << "Ingreso aceptado" << endl;

            if ((bool)alumno.nacionalidad) {
                archivo.seekp(-static_cast<int>(sizeof(Alumno)), ios::cur);
                archivo.write(reinterpret_cast<char*>(&alumno), sizeof(Alumno));
                archivo.close();
                cout<<"Alumno Solvente!!"<<endl;
                system("Pause");
                asignacion_alumno();


            } else {
                cout << "El alumno no esta solvente. Regresando al menu anterior..." << endl;
                system("pause");
                archivo.close();
                return;
            }
            break;
        }
    }

    archivo.close();

    if (!encontrado) {
        cout << "No se encontro un estudiante con el ID proporcionado." << endl;
    }

    cout << "Presione Enter Para Continuar";
    cin.ignore();
    cin.get();
}

void AsigCursos_Alumnos::asignacion_alumno() {

    system("cls");
    Asig_al asig;

    cout << "Ingrese su nombre completo: " << endl;
    cin.ignore();
    cin.getline(asig.nom_alumno, 100);
    system("cls");

    cout << "---------------BIENVENIDO-----------------" << endl;
    cout << "--ELIJA LOS CURSOS A LOS QUE DESEA ASIGNARSE----" << endl;
    catalogo Catalogo("curso1", "curso2");
    Catalogo.insertar();
    system("cls");

    cout << "---------------BIENVENIDO-----------------" << endl;
    cout << "--ELIJA LA JORNADA A LA QUE DESEA ASIGNARSE----" << endl;
    system("pause");
    JornadaCRUD jjornada;
    jjornada.Desplegar();

    cout << "Escriba la jornada que desea :" << endl;
    cin.getline(asig.jornada, 50);

    system("cls");

    cout << "---------------BIENVENIDO-----------------" << endl;
    cout << "--ELIJA EL AULA A LA QUE DESEA ASIGNARSE ----" << endl;
    system("pause");
    AulasCRUD Aaula;
    Aaula.DesplegarAula();

    cout << "Escriba el aula que desea :" << endl;
    cin.getline(asig.aula, 100);

    system("cls");

    cout << "---------------BIENVENIDO-----------------" << endl;
    cout << "--ELIJA LA SECCION A LA QUE DESEA ASIGNARSE ----" << endl;
    system("pause");
    SeccionesCrud sec;
    sec.DesplegarSeccion();

    cout << "Escriba la seccion que desea :" << endl;
    cin.getline(asig.seccion, 100);

    system("cls");

    ofstream archivo("AsigCursos_Alumnos.dat", ios::binary | ios::app);
    archivo.write(reinterpret_cast<const char*>(&asig), sizeof(Asig_al));
    archivo.close();
    cout << "Su asignacion ha sido procesada exitosamente!" << endl;
    cout << "Estamos generando su boleta...!" << endl;

    cout << "------------------------------------------------" << endl;

    system("pause");
}

void AsigCursos_Alumnos::desplegarBoleta() {
    system("cls");

    cout << "+---------------------------------------------------------------------------------+" << endl;
    cout << "+                            Tabla de Detalles del Estudiante                     +" << endl;
    cout << "+---------------------------------------------------------------------------------+" << endl;

    ifstream archivo("AsigCursos_Alumnos.dat", ios::binary | ios::app);
    if (!archivo) {
        cout << "Error, no se encuentra información...";
        return;
    }

    Asig_al asig;

    while (archivo.read(reinterpret_cast<char*>(&asig), sizeof(Asig_al))) {
        cout << "                      Mostrando -> Nombre del estudiante: " << asig.nom_alumno << endl;
        cout << "                      Mostrando -> Jornada elegida: " << asig.jornada << endl;
        cout << "                      Mostrando -> Aula elegida: " << asig.aula << endl;
        cout << "                      Mostrando -> Seccion: " << asig.seccion << endl;

        cout << "+---------------------------------------------------------------------------------+" << endl;
    }
    archivo.close();
    system("pause");

    cout << "Presione Enter Para Continuar";
    cin.ignore();
    cin.get();
}
