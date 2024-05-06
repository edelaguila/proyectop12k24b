//main creado por Jose Eduardo Gallardo Del Cid 9959-23-106
#include <iostream>
#include<fstream>
#include<stdlib.h>
#include<cstdlib>
#include<conio.h>
#include<iomanip>
#include "usuarios.h"
#include <alumnos.h>
#include <maestros.h>



using namespace std;

void creditosModulo();
void catalogos();
void reportes();
void procesos();
void menuGeneral();
void ayuda();
void seguridad();

usuarios usuarioRegistrado;

int main()
{
    bool accesoUsuarios;


    accesoUsuarios=usuarioRegistrado.loginUsuarios();
    if (accesoUsuarios){
        menuGeneral();
    }
    system("cls");
    cout<<"** Hasta la proxima **";
    return 0;
}

void menuGeneral(){
    system("cls");
    int choice;
	do
    {
	system("cls");
	cout<<"\t\t\t\t\tUsuario: "<< usuarioRegistrado.getNombre() <<endl;
	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"\t\t\t|   SISTEMA DE GESTION UMG     |"<<endl;
	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"\t\t\t 1. Catalogos"<<endl;
	cout<<"\t\t\t 2. Procesos"<<endl;
	cout<<"\t\t\t 3. Reportes"<<endl;
	cout<<"\t\t\t 4. Seguridad"<<endl;
	cout<<"\t\t\t 5. Ayuda"<<endl;
	cout<<"\t\t\t 6. Salir del Sistema"<<endl;
    cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"\t\t\t|Opcion a escoger:[1/2/3/4/5/6]  |"<<endl;
	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"\t\t\tIngresa tu Opcion: ";
    cin>>choice;

    switch(choice)
    {
    case 1:
        catalogos();
		break;
	case 2:
		procesos();
		break;
	case 3:
		reportes();
		break;
	case 4:{
		seguridad();
		break;
	}
	case 5:{
		ayuda();
		break;
	}
    case 6:
        exit(0);
	default:
		cout<<"\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
		cin.get();
	}
    }while(choice!= 7);
}

void catalogos(){


    int choice;

    do {
	system("cls");
	cout<<"\t\t\t--------------------------------------------"<<endl;
	cout<<"\t\t\t|   SISTEMA DE GESTION UMG - CATALOGOS      |"<<endl;
	cout<<"\t\t\t--------------------------------------------"<<endl;
	cout<<"\t\t\t 1. Alumnos"<<endl;
	cout<<"\t\t\t 2. Maestros"<<endl;
	cout<<"\t\t\t 3. Usuarios del sistema"<<endl;
	cout<<"\t\t\t 4. Carreras"<<endl;
	cout<<"\t\t\t 5. Facultades"<<endl;
	cout<<"\t\t\t 6. Cursos"<<endl;
	cout<<"\t\t\t 7. Jornadas"<<endl;
	cout<<"\t\t\t 8. Aulas"<<endl;
	cout<<"\t\t\t 9. Secciones"<<endl;
	cout<<"\t\t\t 10. Sedes"<<endl;
	cout<<"\t\t\t 11. Horarios"<<endl;
	cout<<"\t\t\t 12. Retornar menu anterior"<<endl;
    cout<<"\t\t\t --------------------------------------------"<<endl;
	cout<<"\t\t\t | Opcion a escoger:[1|2|3|4/5/6/7/8/9/10/11]|"<<endl;
	cout<<"\t\t\t --------------------------------------------"<<endl;
	cout<<"\t\t\tIngresa tu Opcion: ";
    cin>>choice;

    switch(choice)
    {
	case 1:
	    {
        alumnos Ralumnos;
        Ralumnos.menu();
	    }
		break;
    case 2:
        {
        maestros maestro;
        maestro.menu();
        }
		break;
    case 3:
        {
        usuarios usuario;
        usuario.menuUsuarios();
        }
		break;
    case 4:
        {
		break;
        }
    case 5:
        {
		break;
        }
    case 6:
        {
		break;
        }
    case 7:
        {
		break;
        }
    case 8:
        {
		break;
        }
    case 9:
        {
		break;
        }
    case 10:
        {
		break;
        }
    case 11:
        {
		break;
        }
    case 12:
        {
        menuGeneral();
		break;
        }

	default:
		cout<<"\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
		cin.get();
	}
    }while(choice!= 12);
}
void procesos(){

  //implementacion procesos
}
void reportes(){

   //implementacion reportes
}
void ayuda(){

    //implementacion ayuda
}
void seguridad(){
    //implementacion seguridad
}
