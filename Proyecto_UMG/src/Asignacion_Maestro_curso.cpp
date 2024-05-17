#include "Asignacion_Maestro_curso.h"
#include "login_catedratico.h"
#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<cstdlib>
#include<conio.h>
#include<iomanip>
using namespace std;
Asignacion_Maestro_curso:: Asignacion_Maestro_curso( string codigo_maestro,string nombre_maestro,string apellido_maestro, string sede,string aula,string seccion,string facultad,string carrera,string curso,string jornada,string horario)
{


    this -> codigo_maestro=codigo_maestro;
    this -> nombre_maestro=nombre_maestro;
    this-> apellido_maestro=apellido_maestro;
    this-> sede=sede;
    this-> aula=aula;
    this-> seccion=seccion;
    this-> facultad=facultad;
    this-> carrera=carrera;
    this-> curso=curso;
    this -> jornada=jornada;
    this-> horario=horario;
}

void Asignacion_Maestro_curso::Menu_catedratico()
{

 //variables de user y contraseñan
    string user,contrasena;
    //llmamos al objeto e ingresamos los parametros
    login_catedratico ingreso(user,contrasena);


    //creamos un bool  que verifique y despliegue el metodo verificarUsuario
    bool UsuarioCorrecto=ingreso.VerificarUsuario();


    //luego de ingresar con usuario y contraseña se nos desplega otro menu
    if(UsuarioCorrecto)
    {
        int opcion;
        char  x;
        do
        {
        	system("cls");

    cout<<"\t\t\t+------------------------------------------+"<<endl;
    cout<<"\t\t\t|      BIENVENIDO AL MENU CATEDRATICO      |"<<endl;
    cout<<"\t\t\t+------------------------------------------+"<<endl;
	cout<<"\t\t\t|1. Asignacion De Cursos                   |"<<endl;
	cout<<"\t\t\t|2. Actas                                  |"<<endl;
	cout<<"\t\t\t|3. regresar al menu anterior              |"<<endl;
	cout<<"\t\t\t+------------------------------------------+"<<endl;
	cout<<"\t\t\t|Opcion a escoger:[1/2/3]              |"<<endl;
	cout<<"\t\t\t+------------------------------------------+"<<endl;
	cout<<"\t\t\tIngresa tu Opcion: ";
    cin>>opcion;

    switch(opcion){
    case 1:

         {
          asignarse_curso();

            break;
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
void Asignacion_Maestro_curso::asignarse_curso()
{
cout<<"ingrese codigo maestro"<<endl;
cin >> codigo_maestro ;

cout <<"ingrese nombre catedratico"<<endl;
cin>> nombre_maestro;

cout <<"ingrese apellido catedratico"<<endl;
cin>> apellido_maestro;

cout <<"ingrese la sede"<<endl;
cin>> sede;

cout <<"ingrese el aula"<<endl;
cin>> aula;

cout <<"ingrese la seccion"<<endl;
cin>> seccion;

cout <<"ingrese la facultad"<<endl;
cin>> facultad;

cout <<"ingrese la carrera"<<endl;
cin>> carrera;

cout <<"ingrese el curso"<<endl;
cin>> curso;

cout <<"ingrese la jornada"<<endl;
cin>> jornada;

cout <<"ingrese el horario"<<endl;
cin>> horario;
system("pause");

}

string Asignacion_Maestro_curso::setCodigo(string codigo_maestro)
{
    this -> codigo_maestro=codigo_maestro;
}

string Asignacion_Maestro_curso::getCodigo()
{
    return this->codigo_maestro;
}

string Asignacion_Maestro_curso::setNombre(string nombre_maestro)
{
    this ->  nombre_maestro= nombre_maestro;
}

string Asignacion_Maestro_curso::getNombre()
{
    return this-> nombre_maestro;
}

string Asignacion_Maestro_curso::setApellido(string apellido_maestro)
{
    this ->  apellido_maestro= apellido_maestro;
}

string Asignacion_Maestro_curso::getApellido()
{
    return this-> apellido_maestro;
}
string Asignacion_Maestro_curso::setSede(string sede)
{
    this ->  sede= sede;
}

string Asignacion_Maestro_curso::getSede()
{
    return this-> sede;
}
string Asignacion_Maestro_curso::setAula(string aula)
{
    this ->  aula= aula;
}

string Asignacion_Maestro_curso::getAula()
{
    return this-> aula;
}

string Asignacion_Maestro_curso::setSeccion(string seccion)
{
    this ->  seccion= seccion;
}

string Asignacion_Maestro_curso::getSeccion()
{
    return this-> seccion;
}

string Asignacion_Maestro_curso::setFacultad(string facultad)
{
    this ->  facultad= facultad;
}

string Asignacion_Maestro_curso::getFacultad()
{
    return this-> facultad;
}

string Asignacion_Maestro_curso::setCarrera(string carrera)
{
    this ->  carrera= carrera;
}

string Asignacion_Maestro_curso::getCarrera()
{
    return this-> carrera;
}
string Asignacion_Maestro_curso::setCurso(string curso)
{
    this ->  curso= curso;
}

string Asignacion_Maestro_curso::getCurso()
{
    return this-> curso;
}

string Asignacion_Maestro_curso::setJornada(string jornada)
{
    this ->  jornada = jornada;
}

string Asignacion_Maestro_curso::getJorada()
{
    return this-> jornada;
}
string Asignacion_Maestro_curso::setHorario(string horario)
{
    this ->  horario= horario;
}

string Asignacion_Maestro_curso::getHorario()
{
    return this-> horario;
}
