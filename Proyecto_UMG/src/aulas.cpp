//Creado por Rocio Guisell Lopez espinoza 9959-23-740

#include "aulas.h"

=======
=======
>>>>>>> 678481e7b31f256476f53bd40df483d8780d6b84

//Incluir la biblioteca para manipulación de archivo
#include "aulas.h"

//Bibliotecas necesarias para que el codigo funcione
<<<<<<< HEAD
>>>>>>> 7fee22e7c1a780459548acc106d5712411a3308b
=======
>>>>>>> 678481e7b31f256476f53bd40df483d8780d6b84
#include <fstream>
#include <iostream>
#include<stdlib.h>
#include<cstdlib>
#include<conio.h>
#include<iomanip>
<<<<<<< HEAD
<<<<<<< HEAD
using namespace std;

void AulasCRUD::CrudAula()
{
=======
=======
>>>>>>> 678481e7b31f256476f53bd40df483d8780d6b84


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

<<<<<<< HEAD
>>>>>>> 7fee22e7c1a780459548acc106d5712411a3308b
=======
>>>>>>> 678481e7b31f256476f53bd40df483d8780d6b84
    int opcion;
    do
    {

<<<<<<< HEAD
<<<<<<< HEAD
	system("cls");
=======
=======
>>>>>>> 678481e7b31f256476f53bd40df483d8780d6b84
//Limpiamos pantalla
	system("cls");

	//Mostramos el menu principal
<<<<<<< HEAD
>>>>>>> 7fee22e7c1a780459548acc106d5712411a3308b
=======
>>>>>>> 678481e7b31f256476f53bd40df483d8780d6b84
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
<<<<<<< HEAD

=======
//Maneja las opciones del menu
>>>>>>> 7fee22e7c1a780459548acc106d5712411a3308b
=======
//Maneja las opciones del menu
>>>>>>> 678481e7b31f256476f53bd40df483d8780d6b84
     switch(opcion)
    {
	case 1:
        IngresarAula();
<<<<<<< HEAD
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
=======
>>>>>>> 678481e7b31f256476f53bd40df483d8780d6b84
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
<<<<<<< HEAD
>>>>>>> 7fee22e7c1a780459548acc106d5712411a3308b
=======
>>>>>>> 678481e7b31f256476f53bd40df483d8780d6b84
    case 5:
		break;
	default:
		cout<<"\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
		cin.get();
	}
    }while(opcion!= 5);

}

<<<<<<< HEAD
<<<<<<< HEAD
void AulasCRUD::IngresarAula() {

   system("cls");
    cout<<"\n------------------------------------------------------------------------------------------------------------------------"<<endl;
    cout<<"\n-------------------------------------------------Agregar Aula--------------------------------------------"<<endl;
    aulas aula;
=======
=======
>>>>>>> 678481e7b31f256476f53bd40df483d8780d6b84
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
<<<<<<< HEAD
>>>>>>> 7fee22e7c1a780459548acc106d5712411a3308b
=======
>>>>>>> 678481e7b31f256476f53bd40df483d8780d6b84
    cout << "Ingrese el codigo del aula: ";
    cin >> aula.codigo;
    cin.ignore();

    cout << "Ingrese el nombre del aula: ";
    cin.getline(aula.nombre, 50);

    cout << "Ingrese la estatus de la aula: ";
    cin.getline(aula.estatus, 50);

<<<<<<< HEAD
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
=======
>>>>>>> 678481e7b31f256476f53bd40df483d8780d6b84
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
<<<<<<< HEAD
>>>>>>> 7fee22e7c1a780459548acc106d5712411a3308b
=======
>>>>>>> 678481e7b31f256476f53bd40df483d8780d6b84
    if (!archivo) {
        cout << "No hay aulas registradas." << endl;
        return;
    }

<<<<<<< HEAD
<<<<<<< HEAD
    aulas aula;
    bool encontrada = false;
    while (archivo.read(reinterpret_cast<char*>(&aula), sizeof(aulas))) {
        if (aula.codigo == codigo) {
=======
=======
>>>>>>> 678481e7b31f256476f53bd40df483d8780d6b84
    // Declarar una variable para el aula
    aulas aula;
    bool encontrada = false;
    // Recorrer el archivo para encontrar el aula con el código ingresado
    while (archivo.read(reinterpret_cast<char*>(&aula), sizeof(aulas))) {
        if (aula.codigo == codigo) {
            // Solicitar al usuario ingresar los nuevos datos del aula
<<<<<<< HEAD
>>>>>>> 7fee22e7c1a780459548acc106d5712411a3308b
=======
>>>>>>> 678481e7b31f256476f53bd40df483d8780d6b84
            cout << "Ingrese el nuevo nombre de la aula: ";
            cin.ignore();
            cin.getline(aula.nombre, 50);

            cout << "Ingrese el nuevo estatus de la aula: ";
            cin.getline(aula.estatus, 50);

<<<<<<< HEAD
<<<<<<< HEAD
            archivo.seekp(-static_cast<int>(sizeof(aulas)), ios::cur);
=======
            // Mover el puntero de escritura hacia atrás para sobreescribir el aula
            archivo.seekp(-static_cast<int>(sizeof(aulas)), ios::cur);
            // Escribir el aula modificada en el archivo
>>>>>>> 7fee22e7c1a780459548acc106d5712411a3308b
=======
            // Mover el puntero de escritura hacia atrás para sobreescribir el aula
            archivo.seekp(-static_cast<int>(sizeof(aulas)), ios::cur);
            // Escribir el aula modificada en el archivo
>>>>>>> 678481e7b31f256476f53bd40df483d8780d6b84
            archivo.write(reinterpret_cast<const char*>(&aula), sizeof(aulas));

            encontrada = true;
            break;
        }
    }

<<<<<<< HEAD
<<<<<<< HEAD
    archivo.close();
=======
    archivo.close(); // Cerrar el archivo
>>>>>>> 7fee22e7c1a780459548acc106d5712411a3308b
=======
    archivo.close(); // Cerrar el archivo
>>>>>>> 678481e7b31f256476f53bd40df483d8780d6b84

    if (!encontrada) {
        cout << "No se encontró la aula con el codigo ingresado." << endl;
    } else {
        cout << "aula modificada exitosamente!" << endl;
    }

}

<<<<<<< HEAD
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
=======
>>>>>>> 678481e7b31f256476f53bd40df483d8780d6b84
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
<<<<<<< HEAD
>>>>>>> 7fee22e7c1a780459548acc106d5712411a3308b
=======
>>>>>>> 678481e7b31f256476f53bd40df483d8780d6b84
    while (archivo.read(reinterpret_cast<char*>(&aula), sizeof(aulas))) {
        if (aula.codigo != codigo) {
            archivoTmp.write(reinterpret_cast<const char*>(&aula), sizeof(aulas));
        } else {
            eliminada = true;
        }
    }

<<<<<<< HEAD
<<<<<<< HEAD
    archivo.close();
    archivoTmp.close();

=======
=======
>>>>>>> 678481e7b31f256476f53bd40df483d8780d6b84
    archivo.close(); // Cerrar el archivo original
    archivoTmp.close(); // Cerrar el archivo temporal

    // Eliminar el archivo original y renombrar el archivo temporal
<<<<<<< HEAD
>>>>>>> 7fee22e7c1a780459548acc106d5712411a3308b
=======
>>>>>>> 678481e7b31f256476f53bd40df483d8780d6b84
    remove("aulas.dat");
    rename("aulas_tmp.dat", "aulas.dat");

    if (eliminada) {
        cout << "aula eliminada exitosamente!" << endl;
<<<<<<< HEAD
<<<<<<< HEAD

=======
>>>>>>> 7fee22e7c1a780459548acc106d5712411a3308b
=======
>>>>>>> 678481e7b31f256476f53bd40df483d8780d6b84
    } else {
        cout << "No se encontró la aula con el codigo ingresado." << endl;
    }

}

<<<<<<< HEAD
<<<<<<< HEAD
void AulasCRUD::DesplegarAula() {
    system("cls");
    cout<<"-----------------Despliegue de aulas registradas---------------------"<<endl;
    ifstream archivo("aulas.dat", ios::binary);
=======
=======
>>>>>>> 678481e7b31f256476f53bd40df483d8780d6b84
// Función para desplegar todas las aulas registradas
void AulasCRUD::DesplegarAula() {
    // Limpiar la pantalla
    system("cls");
    // Mostrar mensaje de despliegue de aulas registradas
    cout<<"-----------------Despliegue de aulas registradas---------------------"<<endl;
    // Abrir el archivo de aulas en modo lectura binaria
    ifstream archivo("aulas.dat", ios::binary);
    // Verificar si el archivo se abrió correctamente
<<<<<<< HEAD
>>>>>>> 7fee22e7c1a780459548acc106d5712411a3308b
=======
>>>>>>> 678481e7b31f256476f53bd40df483d8780d6b84
    if (!archivo) {
        cout << "No hay aulas registradas." << endl;
        return;
    }

<<<<<<< HEAD
<<<<<<< HEAD
    aulas aula;
=======
    // Declarar una variable para el aula
    aulas aula;
    // Recorrer el archivo y mostrar los datos de cada aula
>>>>>>> 7fee22e7c1a780459548acc106d5712411a3308b
=======
    // Declarar una variable para el aula
    aulas aula;
    // Recorrer el archivo y mostrar los datos de cada aula
>>>>>>> 678481e7b31f256476f53bd40df483d8780d6b84
    while (archivo.read(reinterpret_cast<char*>(&aula), sizeof(aulas))) {
        cout << "Codigo: " << aula.codigo << endl;
        cout << "Nombre: " << aula.nombre << endl;
        cout << "Estatus: " << aula.estatus << endl;
        cout << "-----------------------------" << endl;
    }

<<<<<<< HEAD
<<<<<<< HEAD
    archivo.close();
=======
    archivo.close(); // Cerrar el archivo
>>>>>>> 7fee22e7c1a780459548acc106d5712411a3308b
=======
    archivo.close(); // Cerrar el archivo
>>>>>>> 678481e7b31f256476f53bd40df483d8780d6b84

    cout << "Presione Enter para continuar...";
    cin.ignore();
    cin.get();
}
<<<<<<< HEAD
<<<<<<< HEAD



=======
>>>>>>> 7fee22e7c1a780459548acc106d5712411a3308b
=======
>>>>>>> 678481e7b31f256476f53bd40df483d8780d6b84
