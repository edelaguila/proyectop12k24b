//Creado por Andy Alfonso Garcia Lopez 9959-23-1494

//Incluyendo las librerias a utilizar
<<<<<<< HEAD
=======
#include <cstring>
>>>>>>> 622f8ebce2543dc8685ec46d102fff264bc41df3
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
<<<<<<< HEAD
=======
#include "login.h"
>>>>>>> 622f8ebce2543dc8685ec46d102fff264bc41df3

using namespace std;

//Constructor procemaestros y sus parametros
<<<<<<< HEAD
ProceMaestros::ProceMaestros(string Actas, string Cuadernillos, string Asistencia)
{
    // Asignando los valores de los parámetros a los atributos del objeto
    this->Actas = Actas;
    this->Cuadernillos = Cuadernillos;
    this->Asistencia = Asistencia;
=======
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
>>>>>>> 622f8ebce2543dc8685ec46d102fff264bc41df3
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
<<<<<<< HEAD

=======
>>>>>>> 622f8ebce2543dc8685ec46d102fff264bc41df3
    return Asistencia;
}

void ProceMaestros::menu()
{
<<<<<<< HEAD
    string codigoPrograma="2450";
Bitacora Auditoria;
string user, contrasena;
Auditoria.ingresoBitacora(user,codigoPrograma,"PM");
=======


>>>>>>> 622f8ebce2543dc8685ec46d102fff264bc41df3
int opc;
    do
    {
        system("cls");
        cout<<"+-----------------------------------------------+"<<endl;
        cout<<"|             Procesos De Maestros              |"<<endl;
        cout<<"+-----------------------------------------------+"<<endl;
<<<<<<< HEAD
        cout<<"|           1. Procesos de Maestros             |"<<endl;
        cout<<"|           2. Regresar al menu                 |"<<endl;
        cout<<"+-----------------------------------------------+"<<endl;
        cout<<"|           Ingrese su opcion [1/2]             |"<<endl;
        cout<<"+-----------------------------------------------+"<<endl;
=======
        cout<<"|          1. Procesos de Maestros              |"<<endl;
		cout<<"|          2. Tabla de Procesos                 |"<<endl;
		cout<<"|          3. Regresar al menu                  |"<<endl;
		cout<<"+-----------------------------------------------+"<<endl;
		cout<<"|           Ingrese su opcion [1/2/3]           |"<<endl;
		cout<<"+-----------------------------------------------+"<<endl;
>>>>>>> 622f8ebce2543dc8685ec46d102fff264bc41df3
        cin >> opc;

        switch(opc)
        {
        case 1:
<<<<<<< HEAD
            insertar();
            break;
        case 2:
            break;
        }
    } while (opc!=2);
=======
           if (validarCarnet())
            {
                //Funcion insertar
                insertar();
            }
            break;
        case 2:
            mostrarmenu();
            break;
        case 3:
            //Funcion mostrar menu
            break;
        }
    } while (opc!=3);
}

//Funcion bool para validar el carnet
bool ProceMaestros::validarCarnet() {
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
        cout << "No se encontro un estudiante con el ID proporcionado." << endl;
        return false;
    }

    cout << "Presione Enter Para Continuar";
    cin.ignore();
    cin.get();

    return true;
>>>>>>> 622f8ebce2543dc8685ec46d102fff264bc41df3
}

void ProceMaestros::insertar()
{
<<<<<<< HEAD
     string codigoPrograma="2624";
Bitacora Auditoria;
string user, contrasena;
Auditoria.ingresoBitacora(user,codigoPrograma,"PMI");
=======

>>>>>>> 622f8ebce2543dc8685ec46d102fff264bc41df3
    //Limpiando pantalla
    system("cls");

    //Encabezado para agregregar detalles de maestros
    cout<<"+---------------------------------------------------------+"<< endl;
    cout<<"|               Agregar detalles de maestros              |"<< endl;
    cout<<"+---------------------------------------------------------+"<< endl;


    proceamaestros maestros;

<<<<<<< HEAD
=======


>>>>>>> 622f8ebce2543dc8685ec46d102fff264bc41df3
    cout<<" Ingrese un numero uno (1) para confirmar y un numero cero (0) para negar." << endl;
    cin.ignore();

    cout<<"       -> El maestro cuenta con actas?: ";
    cin.getline(maestros.Actas, 15);

    cout<<"       -> El maestro cuenta con cuadernillos?: ";
    cin.getline(maestros.Cuadernillos, 15);

    cout<<"       -> El maestro cuenta con la asistencia?: ";
    cin.getline(maestros.Asistencia, 15);

<<<<<<< HEAD
=======

    int solvente = 1;
    if (string(maestros.Actas) != "1" ||
        string(maestros.Cuadernillos) != "1" ||
        string(maestros.Asistencia) != "1" ){
        solvente = 0;
    }

    // Asignar el valor de solvencia
    strcpy(maestros.solvente, (solvente == 1) ? "1" : "0");

>>>>>>> 622f8ebce2543dc8685ec46d102fff264bc41df3
    cout<<"+---------------------------------------------------------+"<< endl;
    ofstream archivo("ProcesoMaestros.dat", ios::binary | ios::app);
    archivo.write(reinterpret_cast<const char*>(&maestros), sizeof(maestros));
    archivo.close();
}
<<<<<<< HEAD
=======

//Funcion para mostrar menu
void ProceMaestros::mostrarmenu()
{
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
>>>>>>> 622f8ebce2543dc8685ec46d102fff264bc41df3
