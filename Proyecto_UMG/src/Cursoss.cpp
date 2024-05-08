#include "Cursoss.h"
#include <fstream>
#include <iostream>
#include<stdlib.h>
#include<cstdlib>
#include<conio.h>
#include<iomanip>
using namespace std;

void CursosCRUD::CrudCursos() {
int choice;
    //int x;
    do {
	system("cls");
	cout<<"\t\t\t--------------------------------------------"<<endl;
	cout<<"\t\t\t|   SISTEMA DE GESTION UMG - Cursos      |"<<endl;
	cout<<"\t\t\t--------------------------------------------"<<endl;
	cout<<"\t\t\t 1. Ingresar Cursos"<<endl;
	cout<<"\t\t\t 2. Modificar Cursos"<<endl;
	cout<<"\t\t\t 3. Borrar Cursos"<<endl;
	cout<<"\t\t\t 4. Desplegar Cursos"<<endl;
	cout<<"\t\t\t 5. Regresar Menu Anterior"<<endl;
    cout<<"\t\t\t --------------------------------------------"<<endl;
	cout<<"\t\t\t |   Opcion a escoger:[1|2|3|4|5|]           |"<<endl;
	cout<<"\t\t\t --------------------------------------------"<<endl;
	cout<<"\t\t\tIngresa tu Opcion: ";
    cin>>choice;

    switch(choice)
    {
	case 1:
        IngresarCa();
         system("pause");
		break;
    case 2:
        ModificarCa();
         system("pause");
		break;
    case 3:
        BorrarCa();
         system("pause");
		break;
    case 4:
        DesplegarCa();
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



void CursosCRUD::IngresarCa() {

   system("cls");
    cout<<"\n------------------------------------------------------------------------------------------------------------------------"<<endl;
    cout<<"\n-------------------------------------------------Agregar Cursos--------------------------------------------"<<endl;
    Curso Curso;
    cout << "Ingrese el codigo de la Cursos: ";
    cin >> Curso.codigo;
    cin.ignore();

    cout << "Ingrese el nombre del Cursos: ";
    cin.getline(Curso.nombre, 50);

    cout << "Ingrese los Creditos del Curso: ";
    cin.getline(Curso.Creditos, 50);

    cout <<"Ingrese los Prerequisitos del Curso: ";
    cin.getline (Curso.requisitos,50);


    ofstream archivo("Cursoss.DAT", ios::binary | ios::app);
    archivo.write(reinterpret_cast<const char*>(&Curso), sizeof(Curso));
    archivo.close();

    cout << "Cursos agregada exitosamente!" << endl;
}

void CursosCRUD::ModificarCa() {
    int codigo;
    cout << "Ingrese el codigo del curso a modificar: ";
    cin >> codigo;

    fstream archivo("Cursoss.DAT", ios::binary | ios::in | ios::out);
    if (!archivo) {
        cout << "No hay Cursoss registradas." << endl;
        return;
    }

    Curso Curso;
    bool encontrada = false;
    while (archivo.read(reinterpret_cast<char*>(&Curso), sizeof(Curso))) {
        if (Curso.codigo == codigo) {
            cout << "Ingrese el nuevo nombre del Cursos: ";
            cin.ignore();
            cin.getline(Curso.nombre, 50);

            cout << "Ingrese los nuevos creditos del Cursos: ";
            cin.getline(Curso.Creditos, 50);

            cout <<"Ingrese los nuevos Prerequisitos del Curso";
            cin.getline(Curso.requisitos, 50);


            archivo.seekp(-static_cast<int>(sizeof(Curso)), ios::cur);
            archivo.write(reinterpret_cast<const char*>(&Curso), sizeof(Curso));

            encontrada = true;
            break;
        }
    }

    archivo.close();

    if (!encontrada) {
        cout << "No se encontró la Cursos con el codigo ingresado." << endl;
    } else {
        cout << "Cursos modificada exitosamente!" << endl;
    }

}

void CursosCRUD::BorrarCa() {
    int codigo;
    cout << "Ingrese el codigo de la Cursos a eliminar: ";
    cin >> codigo;

    ifstream archivo("Cursoss.DAT", ios::binary);
    if (!archivo) {
        cout << "No hay Cursoss registradas." << endl;

    }

    ofstream archivoTmp("Cursoss_tmp.DAT", ios::binary);
    Curso Curso;
    bool eliminada = false;
    while (archivo.read(reinterpret_cast<char*>(&Curso), sizeof(Curso))) {
        if (Curso.codigo != codigo) {
            archivoTmp.write(reinterpret_cast<const char*>(&Curso), sizeof(Curso));
        } else {
            eliminada = true;
        }
    }

    archivo.close();
    archivoTmp.close();

    remove("Cursoss.DAT");
    rename("Cursoss_tmp.DAT", "Cursoss.DAT");

    if (eliminada) {
        cout << "Cursos eliminada exitosamente!" << endl;

    } else {
        cout << "No se encontró la Cursos con el codigo ingresado." << endl;
    }

}

void CursosCRUD::DesplegarCa() {
    system("cls");
    cout<<"-----------------Despliegue de Cursoss registradas---------------------"<<endl;
    ifstream archivo("Cursoss.DAT", ios::binary);
    if (!archivo) {
        cout << "No hay Cursoss registradas." << endl;
        return;
    }

    Curso Curso;
    while (archivo.read(reinterpret_cast<char*>(&Curso), sizeof(Curso))) {
        cout << "Codigo: " << Curso.codigo << endl;
        cout << "Nombre: " << Curso.nombre << endl;
        cout << "Creditos: " << Curso.Creditos << endl;
        cout << "Requisitos: " << Curso.requisitos << endl;
        cout << "-----------------------------" << endl;
    }

    archivo.close();

    cout << "Presione Enter para continuar...";
    cin.ignore();
    cin.get();
}
