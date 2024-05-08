#include "jornada.h"
#include <fstream>
#include <iostream>
#include<stdlib.h>
#include<cstdlib>
#include<conio.h>
#include<iomanip>
using namespace std;

void JornadaCRUD::CrudJornada() {
int choice;
    //int x;
    do {
	system("cls");
	cout<<"\t\t\t--------------------------------------------"<<endl;
	cout<<"\t\t\t|   SISTEMA DE GESTION UMG - Jornada        |"<<endl;
	cout<<"\t\t\t--------------------------------------------"<<endl;
	cout<<"\t\t\t 1. Ingresar Jornada"<<endl;
	cout<<"\t\t\t 2. Modificar Jornada"<<endl;
	cout<<"\t\t\t 3. Borrar Jornada"<<endl;
	cout<<"\t\t\t 4. Desplegar Jornada"<<endl;
	cout<<"\t\t\t 5. Regresar Menu Anterior"<<endl;
    cout<<"\t\t\t --------------------------------------------"<<endl;
	cout<<"\t\t\t |   Opcion a escoger:[1|2|3|4|5|]           |"<<endl;
	cout<<"\t\t\t --------------------------------------------"<<endl;
	cout<<"\t\t\tIngresa tu Opcion: ";
    cin>>choice;

    switch(choice)
    {
	case 1:
        Ingresar();
        system("pause");
		break;
    case 2:
        Modificar();
        system("pause");
		break;
    case 3:
        Borrar();
        system("pause");
		break;
    case 4:
        Desplegar();
        system("pause");
		break;
    case 5:
		break;
	default:
		cout<<"\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
		cin.get();
	}
    }while(choice!= 5);
}



void JornadaCRUD::Ingresar() {

   system("cls");
    cout<<"\n------------------------------------------------------------------------------------------------------------------------"<<endl;
    cout<<"\n-------------------------------------------------Agregar Jornada--------------------------------------------"<<endl;
    Jornada Jornada;
    cout << "Ingrese el codigo de la Jornada: ";
    cin >> Jornada.codigo;
    cin.ignore();

    cout << "Ingrese el nombre de la Jornada: ";
    cin.getline(Jornada.nombre, 50);


    ofstream archivo("Jornadas.DAT", ios::binary | ios::app);
    archivo.write(reinterpret_cast<const char*>(&Jornada), sizeof(Jornada));
    archivo.close();

    cout << "Jornada agregada exitosamente!" << endl;
}

void JornadaCRUD::Modificar() {
    int codigo;
    cout << "Ingrese el codigo de la Jornada a modificar: ";
    cin >> codigo;

    fstream archivo("Jornadas.DAT", ios::binary | ios::in | ios::out);
    if (!archivo) {
        cout << "No hay Jornadas registradas." << endl;
        return;
    }

    Jornada Jornada;
    bool encontrada = false;
    while (archivo.read(reinterpret_cast<char*>(&Jornada), sizeof(Jornada))) {
        if (Jornada.codigo == codigo) {
            cout << "Ingrese el nuevo nombre de la Jornada: ";
            cin.ignore();
            cin.getline(Jornada.nombre, 50);



            archivo.seekp(-static_cast<int>(sizeof(Jornada)), ios::cur);
            archivo.write(reinterpret_cast<const char*>(&Jornada), sizeof(Jornada));

            encontrada = true;
            break;
        }
    }

    archivo.close();

    if (!encontrada) {
        cout << "No se encontró la Jornada con el codigo ingresado." << endl;
    } else {
        cout << "Jornada modificada exitosamente!" << endl;
    }

}

void JornadaCRUD::Borrar() {
    int codigo;
    cout << "Ingrese el codigo de la Jornada a eliminar: ";
    cin >> codigo;

    ifstream archivo("Jornadas.DAT", ios::binary);
    if (!archivo) {
        cout << "No hay Jornadas registradas." << endl;

    }

    ofstream archivoTmp("Jornadas_tmp.DAT", ios::binary);
    Jornada Jornada;
    bool eliminada = false;
    while (archivo.read(reinterpret_cast<char*>(&Jornada), sizeof(Jornada))) {
        if (Jornada.codigo != codigo) {
            archivoTmp.write(reinterpret_cast<const char*>(&Jornada), sizeof(Jornada));
        } else {
            eliminada = true;
        }
    }

    archivo.close();
    archivoTmp.close();

    remove("Jornadas.DAT");
    rename("Jornadas_tmp.DAT", "Jornadas.DAT");

    if (eliminada) {
        cout << "Jornada eliminada exitosamente!" << endl;

    } else {
        cout << "No se encontró la Jornada con el codigo ingresado." << endl;
    }

}

void JornadaCRUD::Desplegar() {
    system("cls");
    cout<<"-----------------Despliegue de Jornadas registradas---------------------"<<endl;
    ifstream archivo("Jornadas.DAT", ios::binary);
    if (!archivo) {
        cout << "No hay Jornadas registradas." << endl;
        return;
    }

    Jornada Jornada;
    while (archivo.read(reinterpret_cast<char*>(&Jornada), sizeof(Jornada))) {
        cout << "Codigo: " << Jornada.codigo << endl;
        cout << "Nombre: " << Jornada.nombre << endl;
        cout << "-----------------------------" << endl;
    }

    archivo.close();

    cout << "Presione Enter para continuar...";
    cin.ignore();
    cin.get();
}

