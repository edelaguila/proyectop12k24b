//Esqueleto proceso asignación realizado por Victor Gómez 9959-23-10733
#include "Asignacion_Maestro_curso.h"
#include "login_catedratico.h"
#include "aulas.h"
#include "secciones.h"
#include "Facultad.h"
#include "Carrera.h"
#include "Cursoss.h"
#include "jornada.h"
#include "maestros.h"
#include "Horarios.h"
#include "Sedes.h"
#include<iostream>
#include<cstring>
#include<fstream>
#include<stdlib.h>
#include<cstdlib>
#include<conio.h>
#include <random>
#include <cstdlib>
#include <ctime>
#include<iomanip>
//Implementación de Bitácora realizado por: Pablo Romeo Palencia Rosales 9959-23-736
#include "Bitacora.h"

using namespace std;
string users; //variable que manda el usuario: Pablo Palencia 736

void Asignacion_Maestro_curso::Menu_catedratico()
{
    //---------------Trae usuario, solucion a bitacora: Pablo Palencia 9959-23-736 -----------------------PR--
    fstream file;
    int total=0;
    file.open("bitaU.txt",ios::in);
    if(!file)
	{
		cout<<"\n\t\t\tNo hay usuarios registrados...";
		file.close();
	}
	else
	{
		file >> users;
		while(!file.eof())
		{
			total++;
			file >> users;
		}
		if(total==0)
		{
			cout<<"\n\t\t\tNo hay usuarios...";
		}
	}
	file.close();
    //----------------------------------fin arregla bitacora-------------------------------------------------PR--

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
	cout<<"\t\t\t|3. Imprimir Acta                          |"<<endl;
	cout<<"\t\t\t|4. regresar al menu anterior              |"<<endl;
	cout<<"\t\t\t+------------------------------------------+"<<endl;
	cout<<"\t\t\t|Opcion a escoger:[1/2/3/4]                |"<<endl;
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
        {
            actas();

            break;

        }
    case 3:

        {
            imprimir_acta();


        }            break;
 case 4:


            break;
	default:
		cout<<"\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
        break;}
        }while(opcion!= 4);

    }

}

void Asignacion_Maestro_curso::asignarse_curso()
{
    system("cls");
    char res='S'; //variable que controla la validacion: Pablo Palencia 9959-23-736

//Proceso asignación maestro a curso realizado por Kathia Contreras 9959-23-8246

int num=1;
Asignacion Asigna;
    //PROCESO VALIDACION CODIGO MAESTRO KATHIA CONTRERAS 9959-23-8246
    string idmaestro;
    cout<<"ingrese codigo maestro: ";
    cin >> idmaestro;
    fstream archivo15("maestros.dat", ios::binary | ios::in | ios::out);
    if (!archivo15) {
        cout << "No hay Maestros registrados." << endl;
        return;
    }
    Maestro maestros1;
    bool encontrada = false;
    while (archivo15.read(reinterpret_cast<char*>(&maestros1), sizeof(Maestro))) {
        if (maestros1.id == idmaestro) {
            archivo15.seekp(-static_cast<int>(sizeof(Maestro)), ios::cur);
            strcpy(Asigna.codigo_maestro,(idmaestro).c_str());
            cin.ignore();
            strcpy(Asigna.nombre_maestro,(maestros1.nombre));
            encontrada = true;
            break;
        }
    }
    archivo15.close();
    if (!encontrada) {
        cout << "No se encontro un maestro con el ID proporcionado, intente de nuevo" << endl;
        system("pause");
    }else{
	//Pablo romeo palencia numero aleatorio para actas
        system("cls");

// Inicializar el generador de números aleatorios con una semilla
    srand(time(0)); // Establece la semilla basada en el tiempo actual
    int numero = rand() % 9000 + 1000; // Genera un número aleatorio
    // Generar un número aleatorio para el campo acta
    Asigna.acta = numero;
    // Mostrar el número de acta

    cout<<"Numero de Acta: " <<Asigna.acta<<endl;
    cin.ignore();

         system("cls");

//REVISAR QUE NOMBRE COLOCAN A CLASE Y ARCHIVO SEDE AL GRUPO ASIGNADO

/* **********   DESPLIEGUE SEDE.DAT   ********** */
    cout<<"---------------- Sedes existentes---------------------"<<endl;
    ifstream archivo7("Sedes.dat", ios::binary);
    // Verificar si el archivo se abrió correctamente
    if (!archivo7) {
        cout << "No hay aulas registradas." << endl;
        return;
    }
    Sedes sede1;
        num=1;

    // Recorrer el archivo y mostrar los datos de cada aula
    while (archivo7.read(reinterpret_cast<char*>(&sede1), sizeof(Sedes))) {

        cout << num<< ". " << sede1.nombre << endl;

        num++;
    }
    archivo7.close(); // Cerrar el archivo


cout << "------------------------------------------------" << endl;
do
{ //repite----------------------------------------------------------------------------------PR
string nomsede="";
cout <<"ingrese la sede:";
    cin >> nomsede;
    fstream archivo70("Sedes.dat", ios::binary | ios::in | ios::out);
    if (!archivo70) {
        cout << "No hay Sedes registradas." << endl;
        return;
    }
    Sedes sede1;
    bool encontrada = false;
    while (archivo70.read(reinterpret_cast<char*>(&sede1), sizeof(Sedes))) {
        if (sede1.nombre == nomsede) {
            archivo70.seekp(-static_cast<int>(sizeof(Sedes)), ios::cur);
            strcpy(Asigna.sede,(nomsede).c_str());
            cin.ignore();
            encontrada = true;
            res='N';
            break;
        }
    }
    archivo70.close();
    if (!encontrada) {
        cout << "No se encontro la sede registrada, intente de nuevo..." << endl;
        res='S';
        system("pause");
    }
    }while(res=='S');
system("cls");
//---------------------------------------------------------------------------------------------------PR




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
        num=1;

    // Recorrer el archivo y mostrar los datos de cada aula
    while (archivo.read(reinterpret_cast<char*>(&aula1), sizeof(aulas))) {

        cout << num<< ". " << aula1.nombre << endl;

        num++;
    }

    archivo.close(); // Cerrar el archivo

cout << "------------------------------------------------" << endl;
do
{ //repite y valida--------hecho por: Pablo Palencia--9959-23-736----------------------------------PR
string nomaula="";
cout <<"ingrese el aula:";
    cin >> nomaula;
    fstream archivo20("aulas.dat", ios::binary | ios::in | ios::out);
    if (!archivo20) {
        cout << "No hay Aulas registrados." << endl;
        return;
    }
    aulas aulas1;
    bool encontrada = false;
    while (archivo20.read(reinterpret_cast<char*>(&aulas1), sizeof(aulas))) {
        if (aulas1.nombre == nomaula) {
            archivo20.seekp(-static_cast<int>(sizeof(aulas)), ios::cur);
            strcpy(Asigna.aula,(nomaula).c_str());
            cin.ignore();
            encontrada = true;
            res='N';
            break;
        }
    }
    archivo20.close();
    if (!encontrada) {
        cout << "No se encontro el aula registrada, intente de nuevo..." << endl;
        res='S';
        system("pause");
    }
    }while(res=='S');
system("cls");
//------------------------------------------------------------------------------------------------------PR




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
        num++;
    }
    archivo1.close();

cout << "------------------------------------------------" << endl;

do
{ //repite----------------------------------------------------------------------------------PR
string nomsec="";
cout <<"ingrese la seccion:";
    cin >> nomsec;
    fstream archivo30("seccion.dat", ios::binary | ios::in | ios::out);
    if (!archivo30) {
        cout << "No hay Secciones registradas." << endl;
        return;
    }
    secciones seccion1;
    bool encontrada = false;
    while (archivo30.read(reinterpret_cast<char*>(&seccion1), sizeof(secciones))) {
        if (seccion1.nombre == nomsec) {
            archivo30.seekp(-static_cast<int>(sizeof(secciones)), ios::cur);
            strcpy(Asigna.seccion,(nomsec).c_str());
            cin.ignore();
            encontrada = true;
            res='N';
            break;
        }
    }
    archivo30.close();
    if (!encontrada) {
        cout << "No se encontro la seccion registrada, intente de nuevo..." << endl;
        res='S';
        system("pause");
    }
    }while(res=='S');
system("cls");
//---------------------------------------------------------------------------------------------------PR




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
        num++;
    }

    archivo2.close();
cout << "------------------------------------------------" << endl;
do
{ //repite----------------------------------------------------------------------------------PR
string nomfacu="";
cout <<"ingrese la facultad:";
    cin >> nomfacu;
    fstream archivo31("facultad.dat", ios::binary | ios::in | ios::out);
    if (!archivo31) {
        cout << "No hay Facultades registradas." << endl;
        return;
    }
    Facultad facultad1;
    bool encontrada = false;
    while (archivo31.read(reinterpret_cast<char*>(&facultad1), sizeof(Facultad))) {
        if (facultad1.nombre == nomfacu) {
            archivo31.seekp(-static_cast<int>(sizeof(Facultad)), ios::cur);
            strcpy(Asigna.facultad,(nomfacu).c_str());
            cin.ignore();
            encontrada = true;
            res='N';
            break;
        }
    }
    archivo31.close();
    if (!encontrada) {
        cout << "No se encontro la facultad registrada, intente de nuevo..." << endl;
        res='S';
        system("pause");
    }
    }while(res=='S');
system("cls");
//---------------------------------------------------------------------------------------------------PR



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
        num++;
    }
    archivo3.close();
cout << "------------------------------------------------" << endl;

do
{ //repite----------------------------------------------------------------------------------PR
string nomcar="";
cout <<"ingrese la Carrera:";
    cin >> nomcar;
    fstream archivo40("carreras.dat", ios::binary | ios::in | ios::out);
    if (!archivo40) {
        cout << "No hay Carreras registradas." << endl;
        return;
    }
    Carrera carrera1;
    bool encontrada = false;
    while (archivo40.read(reinterpret_cast<char*>(&carrera1), sizeof(Carrera))) {
        if (carrera1.nombre == nomcar) {
            archivo40.seekp(-static_cast<int>(sizeof(Carrera)), ios::cur);
            strcpy(Asigna.carrera,(nomcar).c_str());
            cin.ignore();
            encontrada = true;
            res='N';
            break;
        }
    }
    archivo40.close();
    if (!encontrada) {
        cout << "No se encontro la carrera registrada, intente de nuevo..." << endl;
        res='S';
        system("pause");
    }
    }while(res=='S');
system("cls");
//---------------------------------------------------------------------------------------------------PR




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
        num++;
    }

    archivo4.close();

cout << "------------------------------------------------" << endl;

do
{ //repite----------------------------------------------------------------------------------PR
string nomcurso="";
cout <<"ingrese el curso:";
    cin >> nomcurso;
    fstream archivo50("Cursoss.dat", ios::binary | ios::in | ios::out);
    if (!archivo50) {
        cout << "No hay cursos registrados." << endl;
        return;
    }
    Curso Curso1;
    bool encontrada = false;
    while (archivo50.read(reinterpret_cast<char*>(&Curso1), sizeof(Curso))) {
        if (Curso1.nombre == nomcurso) {
            archivo50.seekp(-static_cast<int>(sizeof(Curso)), ios::cur);
            strcpy(Asigna.curso,(nomcurso).c_str());
            cin.ignore();
            encontrada = true;
            res='N';
            break;
        }
    }
    archivo50.close();
    if (!encontrada) {
        cout << "No se encontro el curso registrado, intente de nuevo..." << endl;
        res='S';
        system("pause");
    }
    }while(res=='S');
system("cls");
//---------------------------------------------------------------------------------------------------PR




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
        num++;
    }
    archivo5.close();
cout << "------------------------------------------------" << endl;

do
{ //repite----------------------------------------------------------------------------------PR
string nomjor="";
cout <<"ingrese la jornada:";
    cin >> nomjor;
    fstream archivo60("Jornadas.dat", ios::binary | ios::in | ios::out);
    if (!archivo60) {
        cout << "No hay jornadas registradas." << endl;
        return;
    }
    Jornada Jornada1;
    bool encontrada = false;
    while (archivo60.read(reinterpret_cast<char*>(&Jornada1), sizeof(Jornada))) {
        if (Jornada1.nombre == nomjor) {
            archivo60.seekp(-static_cast<int>(sizeof(Jornada)), ios::cur);
            strcpy(Asigna.jornada,(nomjor).c_str());
            cin.ignore();
            encontrada = true;
            res='N';
            break;
        }
    }
    archivo60.close();
    if (!encontrada) {
        cout << "No se encontro la jornada registrada, intente de nuevo..." << endl;
        res='S';
        system("pause");
    }
    }while(res=='S');
system("cls");
//---------------------------------------------------------------------------------------------------PR





/* **********   DESPLIEGUE HORARIO.DAT   ********** */
   cout<<"-----------------Horarios Existentes---------------------"<<endl;
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
        cout << num <<". " << horario1.Horario << endl;
        num++;
    }
    archivo6.close();

cout << "------------------------------------------------" << endl;

do
{ //repite----------------------------------------------------------------------------------PR
string nomhora="";
cout <<"ingrese el Horario:";
    cin >> nomhora;
    fstream archivo70("Horarios.dat", ios::binary | ios::in | ios::out);
    if (!archivo70) {
        cout << "No hay Horarios registrados." << endl;
        return;
    }
    Horario horario1;
    bool encontrada = false;
    while (archivo70.read(reinterpret_cast<char*>(&horario1), sizeof(Horario))) {
        if (horario1.Horario == nomhora) {
            archivo70.seekp(-static_cast<int>(sizeof(Horario)), ios::cur);
            strcpy(Asigna.horario,(nomhora).c_str());
            cin.ignore();
            encontrada = true;
            res='N';
            break;
        }
    }
    archivo70.close();
    if (!encontrada) {
        cout << "No se encontro el horario registrado, intente de nuevo..." << endl;
        res='S';
        system("pause");
    }
    }while(res=='S');
system("cls");
//---------------------------------------------------------------------------------------------------PR




cout << "------------------------------------------------" << endl;

    ofstream archivo8("asignaciones.dat", ios::binary | ios::app);
    archivo8.write(reinterpret_cast<const char*>(&Asigna), sizeof(Asignacion));
    archivo8.close();
    cout << "Asignacion ingresada exitosamente!" << endl;
    cout << "------------------------------------------------" << endl;

system("pause");
    }

}
void Asignacion_Maestro_curso::actas()
{
      //ACTAS HECHO POR KATHIA CONTRERAS 9959-23-8246
    system("cls");
    cout<<"------------------ ASIGNACIONES MAESTRO A CURSO--------------------"<<endl<< endl;

    // Abrir el archivo de aulas en modo lectura binaria
    ifstream archivo("asignaciones.dat", ios::binary);
    // Verificar si el archivo se abrió correctamente
    if (!archivo) {
        cout << "No hay asignaciones registradas." << endl;
        return;
    }

    // Declarar una variable para el aula
    Asignacion asign1;
    // Recorrer el archivo y mostrar los datos de cada aula
    while (archivo.read(reinterpret_cast<char*>(&asign1), sizeof(Asignacion))) {
			cout << "NO. Acta: "<<   asign1.acta<< endl;

        cout << "Codigo:   "<< asign1.codigo_maestro<< endl;
        cout << "Nombre:   "<< asign1.nombre_maestro<< endl ;
        cout << "Sede:     "<< asign1.sede<< endl ;
        cout << "Aula:     "<< asign1.aula<< endl;
        cout << "Seccion:  " << asign1.seccion<< endl;
        cout << "Facultad: "<< asign1.facultad<< endl ;
        cout << "Carrera:  "<< asign1.carrera<< endl ;
        cout << "Curso:    "<<  asign1.curso<< endl ;
        cout << "Jornada:  "<<   asign1.jornada<< endl;
        cout << "Horario:  "<<   asign1.horario<< endl;


        cout<<"-----------------------------------------------------------------"<<endl;
    }

    archivo.close();
    cout << "Presione Enter para continuar...";
    cin.ignore();
    cin.get();

}

Asignacion_Maestro_curso:: Asignacion_Maestro_curso()
{

}
//Imprimir acta por Maria Florencia Ariaga Chiroy 9959-23-6741
void Asignacion_Maestro_curso::imprimir_acta()

{     system("cls");

	// Variable para almacenar el número de acta
    int numero_acta;
    cout << "Ingrese el numero de acta que desea imprimir: ";
    cin >> numero_acta;
    // Abrir el archivo binario de asignaciones para lectura

    ifstream archivo("asignaciones.dat", ios::binary);
    if (!archivo) {
        cout << "No hay asignaciones registradas." << endl;
        return;
    }

    Asignacion asign1;
    bool encontrada = false;
    // Lee el archivo por registro
    while (archivo.read(reinterpret_cast<char*>(&asign1), sizeof(Asignacion))) {
		// Se compara el numero de acta del registro actual con el numero ingresado por el usuario
        if (asign1.acta == numero_acta) {
        	            // Si se encuentra el acta, se imprimen sus datos en la pantalla.
            cout << endl << "-----------------------Acta--------------------------" << endl << endl;
            cout << "NO. Acta: " << asign1.acta << endl;
            cout << "Codigo:   " << asign1.codigo_maestro << endl;
            cout << "Nombre:   " << asign1.nombre_maestro << endl;
            cout << "Sede:     " << asign1.sede << endl;
            cout << "Aula:     " << asign1.aula << endl;
            cout << "Seccion:  " << asign1.seccion << endl;
            cout << "Facultad: " << asign1.facultad << endl;
            cout << "Carrera:  " << asign1.carrera << endl;
            cout << "Curso:    " << asign1.curso << endl;
            cout << "Jornada:  " << asign1.jornada << endl;
            cout << "Horario:  " << asign1.horario << endl;
            cout << endl << "-----------------------------------------------------" << endl << endl;

            //imprimir en archivo - ALISSON LOPEZ 9959-23-7225

			// Se abre el archivo de texto en modo escritura
            FILE *arch = fopen("Acta_Impresa.txt", "wt");
			// Se verifica si se abrió correctamente el archivo de texto
            if (arch == NULL) {
                cerr << "Error al imprimir acta." << endl;
                // Si hay un error, se termina la ejecución del programa
                exit(1);
            }
			// Se escriben los datos del acta en el archivo de texto
            fprintf(arch, "No. Acta: %d\n", asign1.acta);
            fprintf(arch, "Codigo:   %d\n", asign1.codigo_maestro);
            fprintf(arch, "Nombre:   %s\n", asign1.nombre_maestro);
            fprintf(arch, "Sede:     %s\n", asign1.sede);
            fprintf(arch, "Aula:     %s\n", asign1.aula);
            fprintf(arch, "Seccion:  %s\n", asign1.seccion);
            fprintf(arch, "Facultad: %s\n", asign1.facultad);
            fprintf(arch, "Carrera:  %s\n", asign1.carrera);
            fprintf(arch, "Curso:    %s\n", asign1.curso);
            fprintf(arch, "Jornada:  %s\n", asign1.jornada);
            fprintf(arch, "Horario:  %s\n", asign1.horario);
            // Se cierra el archivo de texto.
            fclose(arch);
                        // Se informa al usuario que se creó el archivo de texto con los datos del acta
            cout << "Se imprimio correctamente (Acta_Impresa)" << endl;
            getch();

 encontrada = true;
            break;
        }
    }

    if (!encontrada) {
        cout << "La asignacion No. " << numero_acta << " no existe." << endl;
    }

    archivo.close();
    cout << "Presione Enter para continuar...";
    cin.ignore();
    cin.get();
}
