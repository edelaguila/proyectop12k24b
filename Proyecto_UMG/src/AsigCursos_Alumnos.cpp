#include "AsigCursos_Alumnos.h"
#include "Login_Alumno.h"
#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<cstdlib>
#include<conio.h>
#include<iomanip>
using namespace std;
AsigCursos_Alumnos:: AsigCursos_Alumnos( string codigo_alumno,string nombre_alumno)
{


    this -> codigo_alumno=codigo_alumno;
    this -> nombre_alumno=nombre_alumno;

}
void AsigCursos_Alumnos::Menu_alumno()
{

 //variables de user y contrase�an
    string user,contrasena;
    //llmamos al objeto e ingresamos los parametros
    Login_Alumno ingreso(user,contrasena);


    //creamos un bool  que verifique y despliegue el metodo verificarUsuario
    bool UsuarioCorrecto=ingreso.VerificarUsuario();


    //luego de ingresar con usuario y contrase�a se nos desplega otro menu
    if(UsuarioCorrecto)
    {
        int opcion;
        char  x;
        do
        {
        	system("cls");

    cout<<"\t\t\t+------------------------------------------+"<<endl;
    cout<<"\t\t\t|   BIENVENIDO A NUESTRO MENU DE ALUMNOS   |"<<endl;
    cout<<"\t\t\t+------------------------------------------+"<<endl;
	cout<<"\t\t\t|1. Asignarse a Cursos                     |"<<endl;
	cout<<"\t\t\t|2. Visualizar notas                       |"<<endl;
	cout<<"\t\t\t|3. regresar al menu anterior              |"<<endl;
	cout<<"\t\t\t+------------------------------------------+"<<endl;
	cout<<"\t\t\t|Opcion a escoger:[1/2/3]              |"<<endl;
	cout<<"\t\t\t+------------------------------------------+"<<endl;
	cout<<"\t\t\tIngresa tu Opcion: ";
    cin>>opcion;

    switch(opcion){
    case 1:
        {


        }


    case 2:

        break;
    case 3:

        break;

	default:
		cout<<"\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
        break;}
        }while(opcion!= 3);

    }

}
