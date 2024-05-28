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
<<<<<<< HEAD
#include "Bitacora.h"
=======
>>>>>>> 1a8b285e44e22ebebc8e610ca110e2ec22da6084
#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<cstdlib>
#include <cstring>
#include<conio.h>
#include<iomanip>
#include<string>

<<<<<<< HEAD

using namespace std;


string users;
Alumno alumno;
catalogo Catalogo("curso1", "curso2");
=======
using namespace std;

>>>>>>> 1a8b285e44e22ebebc8e610ca110e2ec22da6084
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
<<<<<<< HEAD


    fstream file;
    int total=0;
    file.open("BitacoraLoA.txt",ios::in);
    if(!file)
	{
		cout<<"\n\t\t\tNo hay usuarios registrados...";
		file.close();
	}
	else
	{
		file >> users;
		while(!file.eof())
		{
			total++;
			file >> users;
		}
		if(total==0)
		{
			cout<<"\n\t\t\tNo hay usuarios...";
		}
	}
	file.close();

    string user, contrasena;

     Bitacora Auditoria;
=======
    string user, contrasena;
>>>>>>> 1a8b285e44e22ebebc8e610ca110e2ec22da6084
    //llamamos al objeto e ingresamos los parametros
    Login_Alumno ingreso(user, contrasena);

    //creamos un bool que verifique y despliegue el metodo verificarUsuario
    bool UsuarioCorrecto = ingreso.VerificarUsuario();

    //luego de ingresar con usuario y contraseña se nos despliega otro menu
    if (UsuarioCorrecto) {
        int opcion;
<<<<<<< HEAD
         if (validarCarnet()){
        do {
            system("cls");
=======
        do {
            system("cls");

>>>>>>> 1a8b285e44e22ebebc8e610ca110e2ec22da6084
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
<<<<<<< HEAD
                if (ValidaAsignacion(alumno.id))
                {
                    cout << "\t\t\tAlumno ya cuenta con asignaciones..." << endl << endl << endl ;
                    system("pause");
                    break ;

                }else {
                asignacion_alumno(alumno.id);
                }
                Auditoria.ingresoBitacora(users,"3003","ACA");
=======
                validarCarnet();

>>>>>>> 1a8b285e44e22ebebc8e610ca110e2ec22da6084
                break;
            }

            case 2:
<<<<<<< HEAD
                desplegarBoleta(alumno.id,alumno.nombre);
                Auditoria.ingresoBitacora(users,"3003","DBO");
=======
                desplegarBoleta();
>>>>>>> 1a8b285e44e22ebebc8e610ca110e2ec22da6084
                break;

            case 3:
                break;

            default:
                cout << "\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
                break;
            }
        } while (opcion != 3);
<<<<<<< HEAD
        }

    }
}

bool AsigCursos_Alumnos::validarCarnet() {
=======
    }
}

void AsigCursos_Alumnos::validarCarnet() {
>>>>>>> 1a8b285e44e22ebebc8e610ca110e2ec22da6084
    system("cls");
    fstream archivo;
    string idPersona;
    bool encontrado = false;

    cout << "+---------------------------------------------------------------------------------+" << endl;
    cout << "+                     BIENVENIDO A NUESTRA VALIDACION                             +" << endl;
    cout << "+---------------------------------------------------------------------------------+" << endl;

<<<<<<< HEAD
    archivo.open("Alumnos.dat", ios::binary | ios::in); // Solo lectura
    if (!archivo) {
        cout << "Error, no se encuentra informacion..." << endl;
        return false;
=======
    archivo.open("Alumnos.dat", ios::binary | ios::in | ios::out); // Removed ios::app mode, as we are only reading here
    if (!archivo) {
        cout << "Error, no se encuentra informacion...";
        return;
>>>>>>> 1a8b285e44e22ebebc8e610ca110e2ec22da6084
    }

    cout << "Ingrese su numero de carnet: ";
    cin >> idPersona;

<<<<<<< HEAD
    while (archivo.read(reinterpret_cast<char*>(&alumno), sizeof(Alumno))) {

        if (alumno.id == idPersona) {
            encontrado = true;
            if (strcmp(alumno.nacionalidad, "1") == 0) { // Considerando '1' como solvente
                cout << "Alumno Solvente!!" << endl;
                cout << "Bienvenido a nuestro sistema de asignacion : " << alumno.nombre <<"!"<<endl; // Mostrar el nombre del alumno
                archivo.close(); // Cerrar el archivo antes de continuar
                system("pause");

                return true; // Salir de la función después de la asignación
            } else {
                cout << "El alumno no esta solvente. Regresando al menu anterior..." << endl;
                archivo.close();
                system("pause");
                return false; // Salir de la función si no está solvente
            }
=======
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
>>>>>>> 1a8b285e44e22ebebc8e610ca110e2ec22da6084
        }
    }

    archivo.close();

    if (!encontrado) {
        cout << "No se encontro un estudiante con el ID proporcionado." << endl;
<<<<<<< HEAD
        system("pause");
            cout << "Presione Enter Para Continuar";
    cin.ignore();
    cin.get();
        return false;

    archivo.open("Alumnos.dat", ios::binary | ios::in | ios::out); // Removed ios::app mode, as we are only reading here
    if (!archivo) {
        cout << "Error, no se encuentra informacion...";
        return;
    }

}


//-----------------------------------METODO PARA VALIDAR JORNADAS-------------------------------------------------------

bool AsigCursos_Alumnos::ValidarJO(int codigo) {
    fstream archivo("Jornadas.dat", ios::binary | ios::in);
    if (!archivo) {
        return false;
    }

    Jornada jornada;
    bool encontrada = false;
    while (archivo.read(reinterpret_cast<char*>(&jornada), sizeof(Jornada))) {
        if (jornada.codigo == codigo) {
            encontrada = true;
            break;
        }
    }

    archivo.close();
    return encontrada;
}

bool AsigCursos_Alumnos::ValidarAU(int codigo) {
    fstream archivo("aulas.dat", ios::binary | ios::in);
    if (!archivo) {
        return false;
    }

    aulas aula;
    bool encontrada = false;
    while (archivo.read(reinterpret_cast<char*>(&aula), sizeof(aulas))) {
        if (aula.codigo == codigo) {
            encontrada = true;
            break;
        }
    }

    archivo.close();
    return encontrada;
}

bool AsigCursos_Alumnos::ValidarSECC(int codigo) {
    fstream archivo("seccion.dat", ios::binary | ios::in);
    if (!archivo) {
        return false;
    }

    secciones seccion;
    bool encontrada = false;
    while (archivo.read(reinterpret_cast<char*>(&seccion), sizeof(secciones))) {
        if (seccion.codigo == codigo) {
            encontrada = true;
            break;
        }
    }

    archivo.close();
    return encontrada;
}

// Implementación de la función de asignación
void AsigCursos_Alumnos::asignacion_alumno(const char* carnet) {
    system("cls");
    Asignacion asignacion;
    strcpy(asignacion.carnet, carnet);

    cout << "---------------BIENVENIDO-----------------" << endl;
    cout << "--ELIJA LOS CURSOS A LOS QUE DESEA ASIGNARSE----" << endl;

    Catalogo.insertar(carnet);
    system("cls");

    // ----------------------------------------ENTRADA Y VALIDACION DE JORNADAS-----------------------------------------------------

    cout << "---------------BIENVENIDO-----------------" << endl;
    cout << "--ELIJA LA JORNADA A LA QUE DESEA ASIGNARSE----" << endl;
    system("pause");

    bool codigoValido = false;

    // Validar código de jornada
    while (!codigoValido) {
        JornadaCRUD jjornada;
        jjornada.Desplegar();
        cout << "Escriba el codigo de la jornada que desea :" << endl;
        cin >> asignacion.codigoJornada;
        cin.ignore();

        if (ValidarJO(asignacion.codigoJornada)) {
            codigoValido = true;
        } else {
            system("cls");
            cout << "El codigo de la Jornada no existe!! Intente de nuevo." << endl << endl;
            system("pause");
        }
    }

    cout << "Asignado Exitosamente" << endl;
    system("pause");
    system("cls");

    // ----------------------------------------ENTRADA Y VALIDACION DE AULAS-----------------------------------------------------

    cout << "---------------BIENVENIDO-----------------" << endl;
    cout << "--ELIJA EL AULA A LA QUE DESEA ASIGNARSE ----" << endl;
    system("pause");

    codigoValido = false;

    // Validar código de aula
    while (!codigoValido) {
        AulasCRUD Aaula;
        Aaula.DesplegarAula();
        cout << "Escriba el codigo del aula que desea :" << endl;
        cin >> asignacion.codigoAula;
        cin.ignore();

        if (ValidarAU(asignacion.codigoAula)) {
            codigoValido = true;
        } else {
            system("cls");
            cout << "El codigo del aula no existe!! Intente de nuevo." << endl << endl;
            system("pause");
        }
    }

    cout << "Asignado a su aula exitosamente!" << endl;
    system("pause");
    system("cls");

    // ----------------------------------------ENTRADA Y VALIDACION DE SECCIONES-----------------------------------------------------

    cout << "---------------BIENVENIDO-----------------" << endl;
    cout << "--ELIJA LA SECCION A LA QUE DESEA ASIGNARSE ----" << endl;
    system("pause");

    codigoValido = false;

    // Validar código de sección
    while (!codigoValido) {
        SeccionesCrud sec;
        sec.DesplegarSeccion();
        cout << "Escriba el codigo de la seccion que desea :" << endl;
        cin >> asignacion.codigoSeccion;
        cin.ignore();

        if (ValidarSECC(asignacion.codigoSeccion)) {
            codigoValido = true;
        } else {
            system("cls");
            cout << "El codigo de la seccion no existe!! Intente de nuevo." << endl << endl;
            system("pause");
        }
    }

    cout << "Asignado a su seccion exitosamente!" << endl;
    system("pause");
    system("cls");

    // ----------------------------------------GUARDAR EN ARCHIVO BINARIO-----------------------------------------------------

    ofstream archivo("AsigCursos_AlumnosENC.dat", ios::binary | ios::app);
    if (archivo.is_open()) {
        archivo.write(reinterpret_cast<char*>(&asignacion), sizeof(Asignacion));
        archivo.close();
        cout << "Asignaciones guardadas exitosamente!" << endl;
    } else {
        cout << "Error al abrir el archivo para guardar las asignaciones." << endl;
    }
=======
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
>>>>>>> 1a8b285e44e22ebebc8e610ca110e2ec22da6084

    system("pause");
}

<<<<<<< HEAD

void AsigCursos_Alumnos::desplegarBoleta(const char* carnet,string nombre) {
    system("cls");
    bool encontrado ;
    cout << "+------------------------------------------------------------------------------------------+" << endl;
    cout << "+                            Tabla de Detalles del Estudiante                              +" << endl;
    cout << "+------------------------------------------------------------------------------------------+" << endl;

    ifstream archivo("AsigCursos_AlumnosENC.dat", ios::binary | ios::in);
=======
void AsigCursos_Alumnos::desplegarBoleta() {
    system("cls");

    cout << "+---------------------------------------------------------------------------------+" << endl;
    cout << "+                            Tabla de Detalles del Estudiante                     +" << endl;
    cout << "+---------------------------------------------------------------------------------+" << endl;

    ifstream archivo("AsigCursos_Alumnos.dat", ios::binary | ios::app);
>>>>>>> 1a8b285e44e22ebebc8e610ca110e2ec22da6084
    if (!archivo) {
        cout << "Error, no se encuentra información...";
        return;
    }
<<<<<<< HEAD
    string scarnet = carnet ;
    Asignacion asignacion;

    while (archivo.read(reinterpret_cast<char*>(&asignacion), sizeof(Asignacion))) {

            if ( asignacion.carnet == scarnet) {
                encontrado = true ;
                cout << "                      Mostrando -> Nombre del estudiante: " << nombre << endl; // Mostrar el carnet
                cout << "                      Mostrando -> Numero de carnet: " << asignacion.carnet << endl; // Mostrar el carnet
                cout << "                      Mostrando -> Jornada elegida: " << ObtenerJornada(asignacion.codigoJornada) << endl;
                cout << "                      Mostrando -> Aula elegida: " << ObtenerAula(asignacion.codigoAula) << endl;
                cout << "                      Mostrando -> Seccion: " << ObtenerSeccion(asignacion.codigoSeccion) << endl;

                cout << "+-----------------------------------------------------------------------------------------+" << endl;
                Catalogo.desplegarcursosalumno(scarnet);
                break;

            }




=======

    Asig_al asig;

    while (archivo.read(reinterpret_cast<char*>(&asig), sizeof(Asig_al))) {
        cout << "                      Mostrando -> Nombre del estudiante: " << asig.nom_alumno << endl;
        cout << "                      Mostrando -> Jornada elegida: " << asig.jornada << endl;
        cout << "                      Mostrando -> Aula elegida: " << asig.aula << endl;
        cout << "                      Mostrando -> Seccion: " << asig.seccion << endl;

        cout << "+---------------------------------------------------------------------------------+" << endl;
>>>>>>> 1a8b285e44e22ebebc8e610ca110e2ec22da6084
    }
    archivo.close();
    system("pause");

    cout << "Presione Enter Para Continuar";
    cin.ignore();
    cin.get();
}
<<<<<<< HEAD

bool AsigCursos_Alumnos::ValidaAsignacion (const char* carnet)
{
    bool encontrado;
    string scarnet = carnet ;
    ifstream archivo("AsigCursos_AlumnosENC.dat", ios::binary | ios::in);
    if (!archivo) {
        cout << "Error, no se encuentra información...";
        encontrado = false;
    }

    Asignacion asignacion;

    while (archivo.read(reinterpret_cast<char*>(&asignacion), sizeof(Asignacion))) {
            if (  asignacion.carnet == scarnet)
                encontrado = true;
            else
                encontrado = false;
    }
    archivo.close();
    return encontrado;
}

string AsigCursos_Alumnos::ObtenerJornada(int codigo)
{
    string nombre ;
    ifstream archivo("Jornadas.dat", ios::binary | ios::in);
    if (!archivo) {
        cout << "Error, no se encuentra información...";
        return "";
    }

    Jornada jornada;

    while (archivo.read(reinterpret_cast<char*>(&jornada), sizeof(Jornada))) {
            if ( jornada.codigo == codigo) {
                nombre = jornada.nombre;
                break;
            }else {
                nombre = "[No Encontrado]";
            }

     }
    archivo.close();

    return nombre;
}

string AsigCursos_Alumnos::ObtenerSeccion(int codigo)
{
    string nombre ;
    ifstream archivo("seccion.dat", ios::binary | ios::in);
    if (!archivo) {
        cout << "Error, no se encuentra información...";
        return "";
    }

    secciones seccion;

    while (archivo.read(reinterpret_cast<char*>(&seccion), sizeof(secciones))) {
            if ( seccion.codigo == codigo) {
                nombre = seccion.nombre;
                break;
            }else {
                nombre = "[No Encontrado]";
            }

     }
    archivo.close();

    return nombre;
}
string AsigCursos_Alumnos::ObtenerAula(int codigo)
{
    string nombre ;
    ifstream archivo("aulas.dat", ios::binary | ios::in);
    if (!archivo) {
        cout << "Error, no se encuentra información...";
        return "";
    }

    aulas aula;

    while (archivo.read(reinterpret_cast<char*>(&aula), sizeof(aulas))) {
            if ( aula.codigo == codigo) {
                nombre = aula.nombre;
                break;
            }else {
                nombre = "[No Encontrado]";
            }

     }
    archivo.close();

    return nombre;
}

=======
>>>>>>> 1a8b285e44e22ebebc8e610ca110e2ec22da6084
