//Creado por Rocio Guisell Lopez espinoza 9959-23-740
<<<<<<< HEAD
#include "aulas.h"

=======

//Incluir la biblioteca para manipulación de archivo
#include "aulas.h"

//Bibliotecas necesarias para que el codigo funcione
>>>>>>> 7fee22e7c1a780459548acc106d5712411a3308b
#include <fstream>
#include <iostream>
#include<stdlib.h>
#include<cstdlib>
#include<conio.h>
#include<iomanip>
<<<<<<< HEAD
using namespace std;

void AulasCRUD::CrudAula()
{
=======


//implementacion de bitacora

#include "Bitacora.h"

using namespace std;

//Definir la función principal del CRUD
void AulasCRUD::CrudAula()
{
 //implementacion de variables para bitacora
    string codigoPrograma= "5000";
    Bitacora Auditoria;
    string user ="admin";

>>>>>>> 7fee22e7c1a780459548acc106d5712411a3308b
    int opcion;
    do
    {

<<<<<<< HEAD
	system("cls");
=======
//Limpiamos pantalla
	system("cls");

	//Mostramos el menu principal
>>>>>>> 7fee22e7c1a780459548acc106d5712411a3308b
	cout<<"\t\t\t--------------------------------------------"<<endl;
	cout<<"\t\t\t|     SISTEMA DE GESTION UMG - Aulas       |"<<endl;
	cout<<"\t\t\t--------------------------------------------"<<endl;
	cout<<"\t\t\t 1. Ingresar Aula"<<endl;
	cout<<"\t\t\t 2. Modificar Aula"<<endl;
	cout<<"\t\t\t 3. Borrar Aula"<<endl;
	cout<<"\t\t\t 4. Desplegar Aula"<<endl;
	cout<<"\t\t\t 5. Regresar Menu Anterior"<<endl;
    cout<<"\t\t\t --------------------------------------------"<<endl;
	cout<<"\t\t\t |   Opcion a escoger:[1|2|3|4|5|]           |"<<endl;
	cout<<"\t\t\t --------------------------------------------"<<endl;
	cout<<"\t\t\tIngresa tu Opcion: ";
    cin>>opcion;

<<<<<<< HEAD

=======
//Maneja las opciones del menu
>>>>>>> 7fee22e7c1a780459548acc106d5712411a3308b
     switch(opcion)
    {
	case 1:
        IngresarAula();
<<<<<<< HEAD
		break;
    case 2:
        ModificarAula();
		break;
    case 3:
        BorrarAula();
		break;
    case 4:
        DesplegarAula();
		break;
=======
        //registro de bitacora ingreso
        Auditoria.ingresoBitacora(user,codigoPrograma,"CUA");//CAU = Create aulas

		break;
    case 2:
        ModificarAula();
		//registro de bitacora Modificar
        Auditoria.ingresoBitacora(user,codigoPrograma,"UAU");//UAU = Update aulas

		break;
    case 3:
        BorrarAula();
		//registro de bitacora borrar
        Auditoria.ingresoBitacora(user,codigoPrograma,"DAU");//DAU = Delete aulas

		break;
    case 4:

        DesplegarAula();
		//registro de bitacora despliegle
        Auditoria.ingresoBitacora(user,codigoPrograma,"RAU");//RCU = Read aulas
        break;
>>>>>>> 7fee22e7c1a780459548acc106d5712411a3308b
    case 5:
		break;
	default:
		cout<<"\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
		cin.get();
	}
    }while(opcion!= 5);

}

<<<<<<< HEAD
void AulasCRUD::IngresarAula() {

   system("cls");
    cout<<"\n------------------------------------------------------------------------------------------------------------------------"<<endl;
    cout<<"\n-------------------------------------------------Agregar Aula--------------------------------------------"<<endl;
    aulas aula;
=======
// Función para agregar un aula
void AulasCRUD::IngresarAula() {
    // Limpiar la pantalla
    system("cls");
    // Mostrar mensaje de agregar aula
    cout<<"\n------------------------------------------------------------------------------------------------------------------------"<<endl;
    cout<<"\n-------------------------------------------------Agregar Aula--------------------------------------------"<<endl;
    // Declarar una variable para el aula
    aulas aula;
    // Solicitar al usuario ingresar los datos del aula
>>>>>>> 7fee22e7c1a780459548acc106d5712411a3308b
    cout << "Ingrese el codigo del aula: ";
    cin >> aula.codigo;
    cin.ignore();

    cout << "Ingrese el nombre del aula: ";
    cin.getline(aula.nombre, 50);

    cout << "Ingrese la estatus de la aula: ";
    cin.getline(aula.estatus, 50);

<<<<<<< HEAD
    ofstream archivo("aulas.dat", ios::binary | ios::app);
    archivo.write(reinterpret_cast<const char*>(&aula), sizeof(aulas));
    archivo.close();

    cout << "aula agregada exitosamente!" << endl;
}

void AulasCRUD::ModificarAula() {
    int codigo;
    cout << "Ingrese el codigo de la aula a modificar: ";
    cin >> codigo;

    fstream archivo("aulas.dat", ios::binary | ios::in | ios::out);
=======
    // Abrir el archivo de aulas en modo binario para agregar el aula
    ofstream archivo("aulas.dat", ios::binary | ios::app);
    // Escribir el aula en el archivo
    archivo.write(reinterpret_cast<const char*>(&aula), sizeof(aulas));
    archivo.close(); // Cerrar el archivo

    cout << "aula agregada exitosamente!" << endl; // Mostrar mensaje de éxito
}

// Función para modificar un aula
void AulasCRUD::ModificarAula() {
    int codigo;
    // Solicitar al usuario ingresar el código del aula a modificar
    cout << "Ingrese el codigo de la aula a modificar: ";
    cin >> codigo;

    // Abrir el archivo de aulas en modo lectura y escritura binaria
    fstream archivo("aulas.dat", ios::binary | ios::in | ios::out);
    // Verificar si el archivo se abrió correctamente
>>>>>>> 7fee22e7c1a780459548acc106d5712411a3308b
    if (!archivo) {
        cout << "No hay aulas registradas." << endl;
        return;
    }

<<<<<<< HEAD
    aulas aula;
    bool encontrada = false;
    while (archivo.read(reinterpret_cast<char*>(&aula), sizeof(aulas))) {
        if (aula.codigo == codigo) {
=======
    // Declarar una variable para el aula
    aulas aula;
    bool encontrada = false;
    // Recorrer el archivo para encontrar el aula con el código ingresado
    while (archivo.read(reinterpret_cast<char*>(&aula), sizeof(aulas))) {
        if (aula.codigo == codigo) {
            // Solicitar al usuario ingresar los nuevos datos del aula
>>>>>>> 7fee22e7c1a780459548acc106d5712411a3308b
            cout << "Ingrese el nuevo nombre de la aula: ";
            cin.ignore();
            cin.getline(aula.nombre, 50);

            cout << "Ingrese el nuevo estatus de la aula: ";
            cin.getline(aula.estatus, 50);

<<<<<<< HEAD
            archivo.seekp(-static_cast<int>(sizeof(aulas)), ios::cur);
=======
            // Mover el puntero de escritura hacia atrás para sobreescribir el aula
            archivo.seekp(-static_cast<int>(sizeof(aulas)), ios::cur);
            // Escribir el aula modificada en el archivo
>>>>>>> 7fee22e7c1a780459548acc106d5712411a3308b
            archivo.write(reinterpret_cast<const char*>(&aula), sizeof(aulas));

            encontrada = true;
            break;
        }
    }

<<<<<<< HEAD
    archivo.close();
=======
    archivo.close(); // Cerrar el archivo
>>>>>>> 7fee22e7c1a780459548acc106d5712411a3308b

    if (!encontrada) {
        cout << "No se encontró la aula con el codigo ingresado." << endl;
    } else {
        cout << "aula modificada exitosamente!" << endl;
    }

}

<<<<<<< HEAD
void AulasCRUD::BorrarAula() {
    int codigo;
    cout << "Ingrese el codigo de la aula a eliminar: ";
    cin >> codigo;

    ifstream archivo("aulas.dat", ios::binary);
    if (!archivo) {
        cout << "No hay aulas registradas." << endl;

    }

    ofstream archivoTmp("aulas_tmp.dat", ios::binary);
    aulas aula;
    bool eliminada = false;
=======
// Función para eliminar un aula
void AulasCRUD::BorrarAula() {
    int codigo;
    // Solicitar al usuario ingresar el código del aula a eliminar
    cout << "Ingrese el codigo de la aula a eliminar: ";
    cin >> codigo;

    // Abrir el archivo de aulas en modo lectura binaria
    ifstream archivo("aulas.dat", ios::binary);
    // Verificar si el archivo se abrió correctamente
    if (!archivo) {
        cout << "No hay aulas registradas." << endl;
        return;
    }

    // Abrir un archivo temporal para escribir las aulas que no se van a eliminar
    ofstream archivoTmp("aulas_tmp.dat", ios::binary);
    // Declarar una variable para el aula
    aulas aula;
    bool eliminada = false;
    // Recorrer el archivo para copiar las aulas que no se van a eliminar al archivo temporal
>>>>>>> 7fee22e7c1a780459548acc106d5712411a3308b
    while (archivo.read(reinterpret_cast<char*>(&aula), sizeof(aulas))) {
        if (aula.codigo != codigo) {
            archivoTmp.write(reinterpret_cast<const char*>(&aula), sizeof(aulas));
        } else {
            eliminada = true;
        }
    }

<<<<<<< HEAD
    archivo.close();
    archivoTmp.close();

=======
    archivo.close(); // Cerrar el archivo original
    archivoTmp.close(); // Cerrar el archivo temporal

    // Eliminar el archivo original y renombrar el archivo temporal
>>>>>>> 7fee22e7c1a780459548acc106d5712411a3308b
    remove("aulas.dat");
    rename("aulas_tmp.dat", "aulas.dat");

    if (eliminada) {
        cout << "aula eliminada exitosamente!" << endl;
<<<<<<< HEAD

=======
>>>>>>> 7fee22e7c1a780459548acc106d5712411a3308b
    } else {
        cout << "No se encontró la aula con el codigo ingresado." << endl;
    }

}

<<<<<<< HEAD
void AulasCRUD::DesplegarAula() {
    system("cls");
    cout<<"-----------------Despliegue de aulas registradas---------------------"<<endl;
    ifstream archivo("aulas.dat", ios::binary);
=======
// Función para desplegar todas las aulas registradas
void AulasCRUD::DesplegarAula() {
    // Limpiar la pantalla
    system("cls");
    // Mostrar mensaje de despliegue de aulas registradas
    cout<<"-----------------Despliegue de aulas registradas---------------------"<<endl;
    // Abrir el archivo de aulas en modo lectura binaria
    ifstream archivo("aulas.dat", ios::binary);
    // Verificar si el archivo se abrió correctamente
>>>>>>> 7fee22e7c1a780459548acc106d5712411a3308b
    if (!archivo) {
        cout << "No hay aulas registradas." << endl;
        return;
    }

<<<<<<< HEAD
    aulas aula;
=======
    // Declarar una variable para el aula
    aulas aula;
    // Recorrer el archivo y mostrar los datos de cada aula
>>>>>>> 7fee22e7c1a780459548acc106d5712411a3308b
    while (archivo.read(reinterpret_cast<char*>(&aula), sizeof(aulas))) {
        cout << "Codigo: " << aula.codigo << endl;
        cout << "Nombre: " << aula.nombre << endl;
        cout << "Estatus: " << aula.estatus << endl;
        cout << "-----------------------------" << endl;
    }

<<<<<<< HEAD
    archivo.close();
=======
    archivo.close(); // Cerrar el archivo
>>>>>>> 7fee22e7c1a780459548acc106d5712411a3308b

    cout << "Presione Enter para continuar...";
    cin.ignore();
    cin.get();
}
<<<<<<< HEAD



=======
>>>>>>> 7fee22e7c1a780459548acc106d5712411a3308b
