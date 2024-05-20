//Creado por Andy Alfonso Garcia Lopez 9959-23-1494

//Incluyendo las librerias a utilizar
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

using namespace std;

//Constructor procemaestros y sus parametros
ProceMaestros::ProceMaestros(string Actas, string Cuadernillos, string Asistencia)
{
    // Asignando los valores de los parámetros a los atributos del objeto
    this->Actas = Actas;
    this->Cuadernillos = Cuadernillos;
    this->Asistencia = Asistencia;
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
    string codigoPrograma="2450";
Bitacora Auditoria;
string user, contrasena;
Auditoria.ingresoBitacora(user,codigoPrograma,"PM");
int opc;
    do
    {
        system("cls");
        cout<<"+-----------------------------------------------+"<<endl;
        cout<<"|             Procesos De Maestros              |"<<endl;
        cout<<"+-----------------------------------------------+"<<endl;
        cout<<"|           1. Procesos de Maestros             |"<<endl;
        cout<<"|           2. Regresar al menu                 |"<<endl;
        cout<<"+-----------------------------------------------+"<<endl;
        cout<<"|           Ingrese su opcion [1/2]             |"<<endl;
        cout<<"+-----------------------------------------------+"<<endl;
        cin >> opc;

        switch(opc)
        {
        case 1:
            insertar();
            break;
        case 2:
            break;
        }
    } while (opc!=2);
}

void ProceMaestros::insertar()
{
     string codigoPrograma="2624";
Bitacora Auditoria;
string user, contrasena;
Auditoria.ingresoBitacora(user,codigoPrograma,"PMI");
    //Limpiando pantalla
    system("cls");

    //Encabezado para agregregar detalles de maestros
    cout<<"+---------------------------------------------------------+"<< endl;
    cout<<"|               Agregar detalles de maestros              |"<< endl;
    cout<<"+---------------------------------------------------------+"<< endl;


    proceamaestros maestros;

    cout<<" Ingrese un numero uno (1) para confirmar y un numero cero (0) para negar." << endl;
    cin.ignore();

    cout<<"       -> El maestro cuenta con actas?: ";
    cin.getline(maestros.Actas, 15);

    cout<<"       -> El maestro cuenta con cuadernillos?: ";
    cin.getline(maestros.Cuadernillos, 15);

    cout<<"       -> El maestro cuenta con la asistencia?: ";
    cin.getline(maestros.Asistencia, 15);

    cout<<"+---------------------------------------------------------+"<< endl;
    ofstream archivo("ProcesoMaestros.dat", ios::binary | ios::app);
    archivo.write(reinterpret_cast<const char*>(&maestros), sizeof(maestros));
    archivo.close();
}
