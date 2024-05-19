//Esqueleto proceso asignación realizado por Victor Gómez 9959-23-10733
#include "Asignacion_Maestro_curso.h"
#include "login_catedratico.h"
#include "aulas.h"
#include "secciones.h"
#include "Facultad.h"
#include "Carrera.h"
#include "Cursoss.h"
#include "jornada.h"
//#include "Horario.h"
//#include "Sedes.h"
#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<cstdlib>
#include<conio.h>
#include<iomanip>
using namespace std;
/*Asignacion_Maestro_curso:: Asignacion_Maestro_curso( string codigo_maestro,string nombre_maestro,string apellido_maestro, string sede,string aula,string seccion,string facultad,string carrera,string curso,string jornada,string horario)
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
}*/
Asignacion_Maestro_curso:: Asignacion_Maestro_curso()
{

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
//Proceso asignación maestro a curso realizado por Kathia Contreras 9959-23-8246

int num=1;
Asignacion Asigna;
cout<<"ingrese codigo maestro"<<endl;
cin >> Asigna.codigo_maestro ;
cin.ignore();

cout <<"ingrese nombre catedratico"<<endl;
cin.getline(Asigna.nombre_maestro,50);

cout <<"ingrese apellido catedratico"<<endl;
cin.getline(Asigna.apellido_maestro,50);

//REVISAR QUE NOMBRE COLOCAN A CLASE Y ARCHIVO SEDE AL GRUPO ASIGNADO

/* **********   DESPLIEGUE SEDE.DAT   ********** */
    /*cout<<"---------------- Sedes existentes---------------------"<<endl;
    ifstream archivo7("sede.dat", ios::binary);
    // Verificar si el archivo se abrió correctamente
    if (!archivo7) {
        cout << "No hay aulas registradas." << endl;
        return;
    }
    Sedes sede1;
    // Recorrer el archivo y mostrar los datos de cada aula
    while (archivo7.read(reinterpret_cast<char*>(&sede1), sizeof(Sedes))) {

        cout << num<< ". " << sede1.nombre << endl;

        cout << "------------------------------------------------------" << endl;
        num++;
    }
    archivo7.close(); // Cerrar el archivo
    cout << "Presione Enter para ingresar la sede que desee...";
    cin.ignore();
    cin.get(); */

cout <<"ingrese la sede"<<endl;
cin.getline(Asigna.sede,50);

/* **********   DESPLIEGUE AULAS.DAT   ********** */

cout<<"-----------------Aulas Existentes---------------------"<<endl;
    // Abrir el archivo de aulas en modo lectura binaria
    ifstream archivo("aulas.dat", ios::binary);
    // Verificar si el archivo se abrió correctamente
    if (!archivo) {
        cout << "No hay aulas registradas." << endl;
        return;
    }

    // Declarar una variable para el aula
    aulas aula1;
    // Recorrer el archivo y mostrar los datos de cada aula
    while (archivo.read(reinterpret_cast<char*>(&aula1), sizeof(aulas))) {

        cout << num<< ". " << aula1.nombre << endl;

        cout << "------------------------------------------------------" << endl;
        num++;
    }

    archivo.close(); // Cerrar el archivo

    cout << "Presione Enter para poder ingresar el aula que desee...";
    cin.ignore();
    cin.get();

cout <<"ingrese el aula"<<endl;
cin.getline(Asigna.aula,50);

/* **********   DESPLIEGUE SECCION.DAT   ********** */
    cout<<"-----------------Secciones Existentes---------------------"<<endl;
    // Abre el archivo 'seccion.dat' en modo binario para lectura
    ifstream archivo1("seccion.dat", ios::binary);
    // Si el archivo no se pudo abrir, imprime un mensaje de error y termina la funci�n
    if (!archivo1) {
        cout << "No hay seccion registradas." << endl;
        return;
    }
    secciones seccion1;
    // Mientras se pueda leer un objeto 'seccion1' del archivo...
    num=1;
    while (archivo1.read(reinterpret_cast<char*>(&seccion1), sizeof(secciones))) {
        // Imprime los datos de la seccion1 en la consola
        cout << num <<". " << seccion1.nombre << endl;
        cout << "------------------------------------------------------" << endl;
        num++;
    }
    archivo1.close();

    // Imprime un mensaje indicando al usuario que presione Enter para continuar
    cout << "Presione Enter para poder ingresar la seccion que desee...";
    cin.ignore();
    cin.get();
cout <<"ingrese la seccion"<<endl;
cin.getline(Asigna.seccion,50);
/* **********   DESPLIEGUE FACULTAD.DAT   ********** */
    num=1;
    cout << "-----------------Facultades Existentes---------------------" << endl;
    ifstream archivo2("facultad.dat", ios::binary);
    if (!archivo2) {
        cout << "No hay facultades registradas." << endl;
        return;
    }

    Facultad facultad1;
    while (archivo2.read(reinterpret_cast<char*>(&facultad1), sizeof(Facultad))) {

        cout << num <<". "<<"Nombre: " << facultad1.nombre << endl;
        cout << "------------------------------------------------------" << endl;
    }

    archivo2.close();
    cout << "Presione Enter seleccionar la facultad que desee...";
    cin.ignore();
    cin.get();
    cout <<"ingrese la facultad"<<endl;
    cin.getline(Asigna.facultad,50);
/* **********   DESPLIEGUE CARRERA.DAT   ********** */

    cout<<"-----------------Carreras Existentes---------------------"<<endl;
    ifstream archivo3("carreras.dat", ios::binary);
    if (!archivo3) {
        cout << "No hay carreras registradas." << endl;
        return;
    }
    Carrera carrera1;
    num=1;
    while (archivo3.read(reinterpret_cast<char*>(&carrera1), sizeof(Carrera))) {
        cout << num <<". " << carrera1.nombre << endl;
        cout << "------------------------------------------------------" << endl;
    }
    archivo3.close();
    cout << "Presione Enter para poder ingresar la carrera que desee...";
    cin.ignore();
    cin.get();

    cout <<"ingrese la carrera"<<endl;
    cin.getline(Asigna.carrera,50);
/* **********   DESPLIEGUE CURSO.DAT   ********** */
    cout<<"-----------------Cursos Existentes---------------------"<<endl;
   //abre el archivo en modo lectura binaria y lee los datos del archivo
    ifstream archivo4("Cursoss.DAT", ios::binary);
    if (!archivo4) {
        cout << "No hay Cursoss registradas." << endl;
        return;
    }
    Curso Curso1;
    num=1;
    //lee de forma repetida cada registro del archivo hasta que no haya mas registros
    while (archivo4.read(reinterpret_cast<char*>(&Curso1), sizeof(Curso))) {
		//Imprime los registros leidos del archivo
        cout << num <<". " << Curso1.nombre << endl;
        cout << "------------------------------------------------------" << endl;
    }

    archivo4.close();

    cout << "Presione Enter para poder ingresar el curso que desee asignar...";
    cin.ignore();
    cin.get();

    cout <<"ingrese el curso"<<endl;
    cin.getline(Asigna.curso,50);
/* **********   DESPLIEGUE JORNADAS.DAT   ********** */

    cout<<"-----------------Jornadas Existentes---------------------"<<endl;
      //abre el archivo en modo lectura binaria y lee los datos del archivo
    ifstream archivo5("Jornadas.DAT", ios::binary);
    if (!archivo5) {
        cout << "No hay Jornadas registradas." << endl;
        return;
    }
    Jornada Jornada1;
    num=1;
        //lee de forma repetida cada registro del archivo hasta que no haya mas registros

    while (archivo5.read(reinterpret_cast<char*>(&Jornada1), sizeof(Jornada))) {
			//Imprime los registros leidos del archivo
        cout << num <<". " << Jornada1.nombre << endl;
        cout << "------------------------------------------------------" << endl;
    }
    archivo5.close();
    cout << "Presione Enter para ingresar la jornada que desee asignar...";
    cin.ignore();
    cin.get();
    cout <<"ingrese la jornada"<<endl;
    cin.getline(Asigna.jornada,50);

/* **********   DESPLIEGUE HORARIO.DAT   ********** */
   /* cout<<"-----------------Horarios Existentes---------------------"<<endl;
      //abre el archivo en modo lectura binaria y lee los datos del archivo
    ifstream archivo6("Horarios.DAT", ios::binary);
    if (!archivo6) {
        cout << "No hay Jornadas registradas." << endl;
        return;
    }

    Horario horario1;
    num=1;
        //lee de forma repetida cada registro del archivo hasta que no haya mas registros

    while (archivo6.read(reinterpret_cast<char*>(&horario1), sizeof(Horario))) {
			//Imprime los registros leidos del archivo
        cout << num <<". " << horario1.nombre << endl;
        cout << "------------------------------------------------------" << endl;
    }
    archivo6.close();
    cout << "Presione Enter para ingresar el horario que desee asignar...";
    cin.ignore();
    cin.get();*/
    cout <<"ingrese el horario"<<endl;
    cin.getline(Asigna.horario,50);
    ofstream archivo8("asignaciones.dat", ios::binary | ios::app);
    archivo8.write(reinterpret_cast<const char*>(&Asigna), sizeof(Asignacion));
    archivo8.close();
    cout << "Asignacion ingresada exitosamente!" << endl;
system("pause");


}
/*
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
}*/
