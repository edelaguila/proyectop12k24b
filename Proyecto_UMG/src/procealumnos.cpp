
#include "procealumnos.h"
#include "Bitacora.h"

#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<cstdlib>
#include<conio.h>
#include<iomanip>
#include<string>

using namespace std;


procealumnos::procealumnos(string dpi, string certiestudios, string fotoestatica, string titulo, string fotocedula, string copiadpi)
{
    this->dpi = dpi;
    this->certiestudios = certiestudios;
    this->fotoestatica = fotoestatica;
    this->titulo = titulo;
    this->fotocedula = fotocedula;
    this->copiadpi = copiadpi;
}

string procealumnos::setdpi(string dpi)
{
    this->dpi = dpi;
    return dpi;
}

string procealumnos::getdpi()
{
    return dpi;
}

string procealumnos::setcertiestudios(string certiestudios)
{
    this->certiestudios = certiestudios;
    return certiestudios;
}

string procealumnos::getcertiestudios()
{
    return certiestudios;
}

string procealumnos::setfotoestatica(string fotoestatica)
{
    this->fotoestatica = fotoestatica;
    return fotoestatica;
}

string procealumnos::getcfotoestatica()
{
    return fotoestatica;
}

string procealumnos::settitulo(string titulo)
{
    this->titulo = titulo;
    return titulo;
}

string procealumnos::gettitulo()
{
    return titulo;
}

string procealumnos::setfotocedula(string fotocedula)
{
    this->fotocedula = fotocedula;
    return fotocedula;
}

string procealumnos::gettfotocedula()
{
    return fotocedula;
}

string procealumnos::setcopiadpi(string copiadpi)
{
    this->copiadpi = copiadpi;
    return copiadpi;
}

string procealumnos::getcopiadpi()
{
    return copiadpi;
}

void procealumnos::menu()
{
    string codigoPrograma="2050";
Bitacora Auditoria;
string user, contrasena;
Auditoria.ingresoBitacora(user,codigoPrograma,"PA");
    int opc;
    do
    {
        system("cls");
        cout<<"+-----------------------------------------------+"<<endl;
		cout<<"|              Procesos de Alumnos              |"<<endl;
		cout<<"+-----------------------------------------------+"<<endl;
		cout<<"|          1. Procesos de Alumnos               |"<<endl;
		cout<<"|          2. Regresar al menu                  |"<<endl;
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

void procealumnos::insertar()
{
    string codigoPrograma="2175";
Bitacora Auditoria;
string user, contrasena;
Auditoria.ingresoBitacora(user,codigoPrograma,"PAI");
    system("cls");

    cout<<"+---------------------------------------------------------+"<< endl;
    cout<<"|                Agregar detalles de alumno               |"<< endl;
    cout<<"+---------------------------------------------------------+"<< endl;

    Procealumnos proalumnos;

    cout<<" Ingrese un numero uno (1) para confirmar y un numero cero (0) para negar." << endl;
    cin.ignore();

    cout<<"       -> El alumno cuenta con DPI?: ";
    cin.getline(proalumnos.dpi, 15);

    cout<<"       -> El alumno cuenta con la certificacion de estudio?: ";
    cin.getline(proalumnos.certiestudios, 15);

    cout<<"       -> El alumno cuenta con la foto estatica?: ";
    cin.getline(proalumnos.fotoestatica, 15);

    cout<<"       -> El alumno cuenta con el titulo original?: ";
    cin.getline(proalumnos.titulo, 15);

    cout<<"       -> El alumno cuenta con la foto cedula?: ";
    cin.getline(proalumnos.fotocedula, 15);

     cout<<"       -> El alumno cuenta con una copia del DPI al 200%?: ";
    cin.getline(proalumnos.copiadpi, 15);

    cout<<"+---------------------------------------------------------+"<< endl;
    ofstream archivo("ProcesoAlumnos.dat", ios::binary | ios::app);
    archivo.write(reinterpret_cast<const char*>(&proalumnos), sizeof(proalumnos));
    archivo.close();
}
