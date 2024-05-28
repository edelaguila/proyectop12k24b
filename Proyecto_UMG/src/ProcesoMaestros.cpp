
//Creado por Andy Alfonso Garcia Lopez 9959-23-1494

//Incluyendo las librerias a utilizar
#include <cstring>
#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<cstdlib>
#include<conio.h>
#include<iomanip>
#include<string>

//Incluyendo el encabezado de Proceso Maestros.h
#include "ProcesoMaestros.h"
#include "Bitacora.h"
#include "Login.h"

using namespace std;

//Constructor procemaestros y sus parametros
ProceMaestros::ProceMaestros(string Actas, string Cuadernillos, string Asistencia, string id, string nombre, string telefono, string DPI, string direccion, string Genero, string civil, string fechanaci, string anoingre)
{
    // Asignando los valores de los parámetros a los atributos del objeto
    this->id = id;
    this->Actas = Actas;
    this->Cuadernillos = Cuadernillos;
    this->Asistencia = Asistencia;
    this->nombre = nombre;
    this->telefono = telefono;
    this->DPI = DPI;
    this->direccion = direccion;
    this->Genero = Genero;
    this->civil = civil;
    this->fechanaci = fechanaci;
    this->anoingre = anoingre;
}

//Estableciendo la id del maestro
string ProceMaestros::setid(string id)
{
    this->id = id;
    return id;
}

//Obteniendo la id del maestro
string ProceMaestros::getid()
{
    return id;
}

//Estableciendo el nombre del maestro
string ProceMaestros::setnombre(string nombre)
{
    this->nombre = nombre;
    return nombre;
}

//Obteniendo el nombre del maestro
string ProceMaestros::getnombre()
{
    return nombre;
}

//Estableciendo el telefono del maestro
string ProceMaestros::setTelefono(string telefono)
{
    this->telefono = telefono;
    return telefono;
}

//Obteniendo el telefono del maestro
string ProceMaestros::getTelefono()
{
    return telefono;
}

//Estableciento el DPI del maestro
string ProceMaestros::setDPI(string DPI)
{
    this->DPI = DPI;
    return DPI;
}

//Obteniendo el DPI del maestro
string ProceMaestros::getDPI()
{
    return DPI;
}

//Estableciendo la direccion del maestro
string ProceMaestros::setdireccion(string direccion)
{
    this->direccion = direccion;
    return direccion;
}


//Estableciendo la direccion del maestro
string ProceMaestros::getdireccion()
{
    return direccion;
}


//Obteniendo la direccion del maestro
string ProceMaestros::setGenero(string Genero)
{
    this->Genero = Genero;
    return Genero;
}

//Obteniendo el genero del maestro
string ProceMaestros::getGenero()
{
    return Genero;
}

//Estableciendo el estado civil del maestro
string ProceMaestros::setcivil(string civil)
{
    this->civil = civil;
    return civil;
}

//Obteniendo el estado civil del maestro
string ProceMaestros::getcivil()
{
    return civil;
}

//Estableciendo la fecha de nacimiento del maestro
string ProceMaestros::setfechanaci(string fechanaci)
{
    this->fechanaci = fechanaci;
    return fechanaci;
}

//Obteniendo la fecha de nacimiento del maestro
string ProceMaestros::getfechanaci()
{
    return fechanaci;
}


//Estableciendo el año de ingreso del alumno
string ProceMaestros::setanoingre(string anoingre)
{
    this->anoingre = anoingre;
    return anoingre;
}

//Obteniendo el año de ingreso del alumno
string ProceMaestros::getanoingre()
{
    return anoingre;
}

//Estableciendo las actas del maestro
string ProceMaestros::setActas(string Actas)
{
    this -> Actas = Actas;
    return Actas;
}

//Obteniendo las actas del maestro
string ProceMaestros::getActas()
{

    return Actas;
}

//Estableciendo los cuadernillos del maestro
string ProceMaestros::setCuadernillos(string Cuadernillos)
{
    this -> Cuadernillos = Cuadernillos;
    return Cuadernillos;
}

//Obteniendo los cuadernillos del maestro
string ProceMaestros::getCuadernillos()
{

    return Cuadernillos;
}

//Estableciendo la asistencia del maestro
string ProceMaestros::setAsistencia(string Asistencia)
{
    this -> Asistencia = Asistencia;
    return Asistencia;
}

//Obteniendo la asistencia del maestro
string ProceMaestros::getAsistencia()
{
    return Asistencia;
}

void ProceMaestros::menu()
{
    //Implementacion de la bitacora
    // Obtener el usuario actual que ha iniciado sesión
    string usuarioActual = Login::getUsuarioActual();

    // Crear una instancia de la clase Bitacora para registrar el ingreso
    Bitacora bitacora;

    // Registro del ingreso en la bitácora
    bitacora.ingresoBitacora(usuarioActual, "2800", "PMM"); // Parámetros

//Variable opc
int opc;
    //Bucle do while
    do
    {
        //Limpiando pantalla
        system("cls");

        //Diseño procesos maestros
        cout<<"+-----------------------------------------------+"<<endl;
        cout<<"|             Procesos De Maestros              |"<<endl;
        cout<<"+-----------------------------------------------+"<<endl;
        cout<<"|          1. Procesos de Maestros              |"<<endl;
		cout<<"|          2. Tabla de Procesos                 |"<<endl;
		cout<<"|          3. Regresar al menu                  |"<<endl;
		cout<<"+-----------------------------------------------+"<<endl;
		cout<<"|           Ingrese su opcion [1/2/3]           |"<<endl;
		cout<<"+-----------------------------------------------+"<<endl;
        cin >> opc;

        //Switch case
        switch(opc)
        {
        //Opcion 1
        case 1:
            //Funcion validar carnet
           if (validarCarnet())
            {
                //Funcion insertar
                insertar();
            }
            break;

        //Opcion 2
        case 2:
            //Funcion para mostrar
            mostrarmenu();
            break;

        //Opcion 3
        case 3:
            //regresar
            break;
        }

    //Si es 3 regresa
    } while (opc!=3);
}

//Funcion bool para validar el carnet
bool ProceMaestros::validarCarnet() {
    //Implementacion de la bitacora
    // Obtener el usuario actual que ha iniciado sesión
    string usuarioActual = Login::getUsuarioActual();

    // Crear una instancia de la clase Bitacora para registrar el ingreso
    Bitacora bitacora;

    // Registro del ingreso en la bitácora
    bitacora.ingresoBitacora(usuarioActual, "2801", "PMVC"); // Parámetros

    //Limpia pantalla
    system("cls");

    // objeto de la clase fstream
    fstream archivo;

    // cadena de texto
    string idPersona;

    //Variable para indicar si es encontrado
    bool encontrado = false;

    //Encabezado
    cout << "+---------------------------------------------------------------------------------+" << endl;
    cout << "+                      Bienvenido, ingrese su número de carnet                     +" << endl;
    cout << "+---------------------------------------------------------------------------------+" << endl;

    // Abre el archivo Alumnos.dat en modo binario para lectura y escritura
    archivo.open("Maestros.dat", ios::binary| ios::in | ios::out);

    // Verifica si el número de carnet no fue encontrado
    if (!archivo) {
        cout << "Error, no se encuentra informacion...";
        return false;
    }

    //Mensaje al usuario
    cout << "Ingrese su numero de carnet: ";
    cin >> idPersona;

    // Declara un objeto de la clase Maestros
    Maestro maestros;

    // Lee secuencialmente el archivo para buscar el número de carnet ingresado

    while (archivo.read(reinterpret_cast<char*>(&maestros), sizeof(Maestro))) {
        if (maestros.id == idPersona) {
            encontrado = true;
            cout << "Usuario Registrado" << endl;
            break;
        }
    }
    //cierra el archivo
    archivo.close();

    //Si no encuentra
    if (!encontrado) {
        //Muestra el mensaje
        cout << "No se encontro un estudiante con el ID proporcionado." << endl;
        //Retorna falso
        return false;
    }

    //Mensaje al usuario
    cout << "Presione Enter Para Continuar";
    cin.ignore();
    cin.get();

    //Retorna verdadero
    return true;
}

void ProceMaestros::insertar()
{
    int pro1=0, pro2=0, pro3=0, bd1=0, sisop1=0;
    //Implementacion de la bitacora
    // Obtener el usuario actual que ha iniciado sesión
    string usuarioActual = Login::getUsuarioActual();

    // Crear una instancia de la clase Bitacora para registrar el ingreso
    Bitacora bitacora;

    // Registro del ingreso en la bitácora
    bitacora.ingresoBitacora(usuarioActual, "2802", "PMI"); // Parámetros


    //Limpiando pantalla
    system("cls");

    //Encabezado para agregregar detalles de maestros
    cout<<"+---------------------------------------------------------+"<< endl;
    cout<<"|               Agregar detalles de maestros              |"<< endl;
    cout<<"+---------------------------------------------------------+"<< endl;

    //Instancia ProcesoMaestros
    proceamaestros maestros;

        cout<<" Ingrese un numero uno (1) para confirmar y un numero cero (0) para negar." << endl;
    cin.ignore();

    cout<<"       -> El maestro cuenta con actas?: ";
    cin.getline(maestros.Actas, 15);

    cout<<"       -> El maestro cuenta con la asistencia?: ";
    cin.getline(maestros.Asistencia, 15);

    cout << "\n";
    cout << "-----------------------Cuadernillos de Materias-----------------------" << endl;
    cout << "\n";
    cout << "    -> Cuenta con el cuadernillo de Programacion I?: ";
    cin >> pro1;
    cout << "    -> Cuenta con el cuadernillo de Programacion II?: ";
    cin >> pro2;
    cout << "    -> Cuenta con el cuadernillo de Programacion III?: ";
    cin >> pro3;
    cout << "    -> Cuenta con el cuadernillo de Base de Datos I?: ";
    cin >> bd1;
    cout << "    -> Cuenta con el cuadernillo de Sistemas Operativos I?: ";
    cin >> sisop1;

    if ( (pro1 == 1) && (pro2 == 1) && (pro3 == 1) && (bd1 == 1) && (sisop1 == 1) )
    {
        cout<<"       -> El maestro cuenta con los cuadernillos";
        cout << "\n";
        system("pause");
        cout << "\n";

    } else
    {
        cout<<"       -> El maestro no cuenta con los cuadernillos";
        cout << "\n";
        system("pause");
        cout << "\n";
    }

    int solvente = 1;

    if ((string(maestros.Actas) != "1" || string(maestros.Cuadernillos) != "1" || string(maestros.Asistencia) != "1" )
        && (pro1 != 1) || (pro2 != 1) || (pro3 != 1) || (bd1 != 1) || (sisop1 != 1))
    {
        solvente = 0;
    }



    // Asignar el valor de solvencia
    strcpy(maestros.solvente, (solvente == 1) ? "1" : "0");

    cout<<"+---------------------------------------------------------+"<< endl;

    // Abre el archivo "ProcesoMaestros.dat" en modo de escritura binaria, añadiendo al final
ofstream archivo("ProcesoMaestros.dat", ios::binary | ios::app);

// Escribe el contenido de la estructura maestros en el archivo
archivo.write(reinterpret_cast<const char*>(&maestros), sizeof(maestros));

// Cierra el archivo después de escribir
archivo.close();
}

//Funcion para mostrar menu
void ProceMaestros::mostrarmenu()
{
    //Implementacion de la bitacora
    // Obtener el usuario actual que ha iniciado sesión
    string usuarioActual = Login::getUsuarioActual();

    // Crear una instancia de la clase Bitacora para registrar el ingreso
    Bitacora bitacora;

    // Registro del ingreso en la bitácora
    bitacora.ingresoBitacora(usuarioActual, "2803", "PMMM"); // Parámetros


    //Limpia pantalla
    system("cls");

    //Diseño de la tabla Mostrar detalles de los maestros
    cout << "+---------------------------------------------------------+" << endl;
    cout << "|           Mostrar detalles de los maestros              |" << endl;
    cout << "+---------------------------------------------------------+" << endl;
    cout << "|              (solvente=1 | pendiente=0)                 |" << endl;
    cout << "+---------------------------------------------------------+" << endl;

    //abre el archivo ProcesoMaestros.dat en modo binario y en lectura
    ifstream archivo("ProcesoMaestros.dat", ios::binary| ios::app);
    //Verificacion del archivo

    if (!archivo)
    {
        //Si no se puso abrir muestra el mensaje
        cout << "Error al abrir el archivo." << endl;
        return;
    }

    // Declara un objeto de la clase ProceMaestros
    ProceMaestros maestros;

    //Inicio del ciclo while
    // Lee  el archivo y muestra los detalles de cada registro
    while (archivo.read(reinterpret_cast<char *>(&maestros), sizeof(ProceMaestros)))
    {
        cout << "       -> Actas: " << maestros.Actas << endl;
        cout << "       -> Cuadernillos: " << maestros.Cuadernillos << endl;
        cout << "       -> Asistencia: " << maestros.Asistencia << endl;
        cout << "+---------------------------------------------------------+" << endl;
    }
    //Cierra el archivo
    archivo.close();

    //Mensaje al usuario
    cout << "Presione Enter Para Continuar";
    cin.ignore();
    cin.get();
}
