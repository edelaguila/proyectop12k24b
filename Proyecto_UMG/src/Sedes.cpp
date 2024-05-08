//Creado por Anderson Rodriguez 9959-23-495
#include "Sedes.h"
#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<cstdlib>
#include<iomanip>
#include <sstream>
#include <cstring>

using namespace std;

struct Sede {
    char id[10];
    char nombre[50];
    char telefono[20];
};
void Sedes::menu()
{
    int choice;
	char x;

	do
    {
	system("cls");

	cout<<"\t\t\t-----------------------------------------"<<endl;
    cout<<"\t\t\t|   SISTEMA DE GESTION UMG - SEDES      |"<<endl;
	cout<<"\t\t\t-----------------------------------------"<<endl;
	cout<<"\t\t\t 1. Ingreso Sedes"<<endl;
	cout<<"\t\t\t 2. Despliegue Sedes"<<endl;
	cout<<"\t\t\t 3. Modifica Sedes"<<endl;
	cout<<"\t\t\t 4. Borra Sedes"<<endl;
	cout<<"\t\t\t 5. Retornar menu anterior"<<endl;
	cout<<"\t\t\t-----------------------------------------"<<endl;
	cout<<"\t\t\tOpcion a escoger:[1/2/3/4/5]"<<endl;
	cout<<"\t\t\t-----------------------------------------"<<endl;
    cout<<"\t\t\tIngresa tu Opcion: ";
    cin>>choice;

    switch(choice)
    {
    case 1:
    	do
    	{
    		insertar();
    		cout<<"\n\t\t\t Agrega otra Sede(Y,N): ";
    		cin>>x;
		}while(x=='y'||x=='Y');
		break;
	case 2:
		desplegar();
		break;
	case 3:
		modificar();
		break;
	case 4:
		borrar();
		break;
	case 5:
		break;
	default:
		cout<<"\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
		cin.get();
	}
  }while(choice!= 5);
}
void Sedes::insertar() {
    system("cls");
    Sede sede;
    ofstream file("Sedes.dat", ios::binary | ios::app);
    if (!file) {
        cerr << "No se pudo abrir el archivo." << endl;
        return;
    }

    cout << "\n--------------------------------------------------------------------------------------------------------------------";
    cout << "\n-------------------------------------------------Agregar Sede-------------------------------------------------------" << endl;
    cout << "\t\t\tIngrese id de Sede       : ";
    cin.ignore();
    cin.getline(sede.id, sizeof(sede.id));
    cout << "\t\t\tIngrese nombre de Sede   : ";
    cin.getline(sede.nombre, sizeof(sede.nombre));
    cout << "\t\t\tIngrese Telefono de Sede : ";
    cin.getline(sede.telefono, sizeof(sede.telefono));

    file.write(reinterpret_cast<const char*>(&sede), sizeof(Sede));
    file.close();
}


void Sedes::desplegar() {
    system("cls");
    ifstream file("Sedes.dat", ios::binary);
    if (!file) {
        cerr << "No se pudo abrir el archivo." << endl;
        return;
    }

    int total = 0;
    cout << "\n-----------------------------------------Tabla Detalles de Sedes ----------------------------------------------" << endl;
    Sede sede;
    while (file.read(reinterpret_cast<char*>(&sede), sizeof(Sede))) {
        cout << "\t\t\t ID Sede      : " << sede.id << endl;
        cout << "\t\t\t Nombre Sede  : " << sede.nombre << endl;
        cout << "\t\t\t Telefono Sede: " << sede.telefono << endl;
        cout << "-----------------------------------------------------------------------------------------------------------------" << endl;
        total++;
    }

    if (total == 0) {
        cout << "\n\t\t\tNo hay informacion..." << endl;

    }
    file.close();
    cin.ignore(); // Limpiar el buffer de entrada
    system("pause");
}

void Sedes::modificar() {
    system("cls");
    fstream file("Sedes.dat", ios::in | ios::out | ios::binary);
    if (!file) {
        cout << "\n\t\t\tNo hay información...";
        return;
    }

    string id_modificar;
    int found = 0;

    cout << "\n-------------------------------------Modificar Detalles de Sedes----------------------------------------------" << endl;
    cout << "\t\t\tIngrese ID de la Sede que desea modificar: ";
    cin >> id_modificar;

    Sede sede;
    ofstream file1("temporal.dat", ios::binary);
    if (!file1) {
        cout << "\n\t\t\tError al abrir el archivo temporal...";
        return;
    }

    while (file.read(reinterpret_cast<char*>(&sede), sizeof(Sede))) {
        if (strcmp(sede.id, id_modificar.c_str()) == 0) {
            cout << "\t\t\tIngrese nuevo ID de Sede: ";
            cin >> sede.id;
            cout << "\t\t\tIngrese nuevo nombre de Sede: ";
            cin.ignore();
            cin.getline(sede.nombre, sizeof(sede.nombre));
            cout << "\t\t\tIngrese nuevo telefono de Sede: ";
            cin.getline(sede.telefono, sizeof(sede.telefono));

            file1.write(reinterpret_cast<const char*>(&sede), sizeof(Sede));

            cout << "\n\t\t\tSede modificada correctamente!!!" << endl;
            found++;
        } else {
            file1.write(reinterpret_cast<const char*>(&sede), sizeof(Sede));
        }
    }

    if (!found) {
        cout << "\n\t\t\tNo se encontro la Sede con el ID proporcionado." << endl;
    }
    file.close();
    file1.close();
    remove("Sedes.dat");
    rename("temporal.dat", "Sedes.dat");
    cin.ignore(); // Limpiar el buffer de entrada
    system("pause");
}

void Sedes::borrar() {
    system("cls");
    string id_borrar;
    int found = 0;

    cout << "\n------------------------------------------Detalles Sede a Borrar-----------------------------------------------" << endl;

    ifstream file("Sedes.dat", ios::binary);
    if (!file) {
        cout << "\n\t\t\tNo hay informacion...";
        return;
    }

    ofstream file1("temporal.dat", ios::binary);
    if (!file1) {
        cout << "\n\t\t\tError al abrir el archivo temporal...";
        return;
    }

    cout << "\n-----------------------------------------Sistema Busqueda de Sedes---------------------------------------------" << endl;
    cout << "\n\t\t Ingrese Id de la Sede que quiere Borrar: ";
    cin >> id_borrar;

    Sede sede;
    while (file.read(reinterpret_cast<char*>(&sede), sizeof(Sede))) {
        if (strcmp(sede.id, id_borrar.c_str()) == 0) {
            cout << "\n\t\t\tBorrado de informacion exitoso!!!!" << "\n" << endl;
            found++;
        } else {
            file1.write(reinterpret_cast<const char*>(&sede), sizeof(Sede));
        }
    }

    if (found == 0) {
        cout << "\n\t\t\tId de Sede no encontrado...." << "\n" << endl;
    }

    file1.close();
    file.close();

    remove("Sedes.dat");
    rename("temporal.dat", "Sedes.dat");

    cin.ignore(); // Limpiar el buffer de entrada
    system("pause");
}
