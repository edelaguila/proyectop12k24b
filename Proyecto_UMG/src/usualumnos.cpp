
//Creado por Oscar Morales 9959-23-3070

#include <iostream>
<<<<<<< HEAD
#include <fstream> //Libreria necesaria para la creacion, lectura y manejo de archivos
#include <iomanip> //Libreria necesaria para el comando setw()

using namespace std;

class usualumnos
{
    public:
=======
#include <fstream>
#include <iomanip>

//Encabezados
#include "Bitacora.h"
#include "Login.h"
using namespace std;

//Clase alumnos
class usualumnos
{
    //Atributos publicos
    public:
        //Funciones
>>>>>>> ca05d99806224de811dc8563d2fc77f0fe4bf8d6
        void menu();
        void pideDatos();
        void muestraDatos();
        void editaDatos();
        void borraDatos();

<<<<<<< HEAD
    private:
        string nombre, contra;
};

void usualumnos::menu()
{
    int opc;
    do
    {
        system("cls");
=======
    //Atributos privados
    private:
        //Variables
        string nombre, contra;
};

//Funcion mostrar menu de usuario alumnos
void usualumnos::menu()
{
    //Implementacion de la bitacora
    // Obtener el usuario actual que ha iniciado sesión
    string usuarioActual = Login::getUsuarioActual();

    // Crear una instancia de la clase Bitacora para registrar el ingreso
    Bitacora bitacora;

    // Registro del ingreso en la bitácora
    bitacora.ingresoBitacora(usuarioActual, "2400", "UAM"); // Parámetros

    //Variable int
    int opc;
    //Ciclo do while
    do
    {
        //Limpiando pantalla
        system("cls");

        //Diseño de gestion de usuarios de alumnos
>>>>>>> ca05d99806224de811dc8563d2fc77f0fe4bf8d6
        cout<<"+-----------------------------------------------+"<<endl;
		cout<<"|        Gestion de Usuarios de Alumnos         |"<<endl;
		cout<<"+-----------------------------------------------+"<<endl;
		cout<<"|            1. Agregar Usuario                 |"<<endl;
		cout<<"|            2. Mostrar Usuario                 |"<<endl;
		cout<<"|            3. Modificar Usuario               |"<<endl;
		cout<<"|            4. Borrar Usuario                  |"<<endl;
		cout<<"|            5. Regresar al menu                |"<<endl;
		cout<<"+-----------------------------------------------+"<<endl;
		cout<<"|         Ingrese su opcion [1/2/3/4/5]         |"<<endl;
		cout<<"+-----------------------------------------------+"<<endl;
        cin >> opc;

<<<<<<< HEAD
        switch(opc)
        {
        case 1:
            pideDatos();
            break;
        case 2:
            muestraDatos();
            break;
        case 3:
            editaDatos();
            break;
        case 4:
            borraDatos();
            break;
        case 5:
            break;
        }
=======
        //Switch case
        switch(opc)
        {
        //Opcion 1
        case 1:
            //Funcion pedir datos
            pideDatos();
            break;
        //Opcion 2
        case 2:
            //Funcion mostrar datos
            muestraDatos();
            break;
        //Opcion 3
        case 3:
            //Funcion editar datos
            editaDatos();
            break;
        //Opcion 4
        case 4:
            //Funcion borrar datos
            borraDatos();
            break;
        //Opcion 5
        case 5:
            break;
        }
    //Si es 5 regresa
>>>>>>> ca05d99806224de811dc8563d2fc77f0fe4bf8d6
    } while (opc!=5);

}

void usualumnos::pideDatos()
{
<<<<<<< HEAD
    system("cls");
    fstream file;

=======
    //Implementacion de la bitacora
    // Obtener el usuario actual que ha iniciado sesión
    string usuarioActual = Login::getUsuarioActual();

    // Crear una instancia de la clase Bitacora para registrar el ingreso
    Bitacora bitacora;

    // Registro del ingreso en la bitácora
    bitacora.ingresoBitacora(usuarioActual, "2401", "USPD"); // Parámetros

    //Limpiando pantalla
    system("cls");

    //Variable fstream
    fstream file;

    //Encabezado agregar detalles del usuario de alumnos
>>>>>>> ca05d99806224de811dc8563d2fc77f0fe4bf8d6
    cout<<"+---------------------------------------------------------+"<< endl;
    cout<<"|        Agregar detalles del Usuario de Alumnos          |"<< endl;
    cout<<"+---------------------------------------------------------+"<< endl;

<<<<<<< HEAD
=======
    //Mensajes al usuario
>>>>>>> ca05d99806224de811dc8563d2fc77f0fe4bf8d6
    cout<<"       -> Ingrese un nombre: ";
    cin >> nombre;
    cout<<"       -> Ingrese una contrasena: ";
    cin >> contra;

<<<<<<< HEAD
    file.open("UsuariosAlumnos.txt", ios::app | ios::out);
    file << left << setw(15) << nombre << left << setw(10) << contra << "\n";
    file.close();
    cout << "\n" << endl;
    system("pause");
    system("cls");
}

void usualumnos::muestraDatos()
{
    system("cls");
    fstream file;
    int total=0;

=======
    // Abre el archivo "UsuariosAlumnos.txt" en modo de añadir al final y escritura
file.open("UsuariosAlumnos.txt", ios::app | ios::out);

// Escribe los datos  en el archivo, separados por espacios
file << left << setw(15) << nombre << left << setw(10) << contra << "\n";

// Cierra el archivo
file.close();

// Imprime un salto de línea en la consola
cout << "\n" << endl;

// Pausa el programa r
system("pause");

// Limpia la pantalla
system("cls");
}

//Funcion de alumnos mostrar datos
void usualumnos::muestraDatos()
{
    //Implementacion de la bitacora
    // Obtener el usuario actual que ha iniciado sesión
    string usuarioActual = Login::getUsuarioActual();

    // Crear una instancia de la clase Bitacora para registrar el ingreso
    Bitacora bitacora;

    // Registro del ingreso en la bitácora
    bitacora.ingresoBitacora(usuarioActual, "2402", "USMD"); // Parámetros

    //Limpiando pantalla
    system("cls");

    //Variables fstream y int
    fstream file;
    int total=0;

    //Encabezado mostrar detalles
>>>>>>> ca05d99806224de811dc8563d2fc77f0fe4bf8d6
    cout<<"+---------------------------------------------------------+"<< endl;
    cout<<"|        Mostrar detalles del Usuario de Alumnos          |"<< endl;
    cout<<"+---------------------------------------------------------+"<< endl;

<<<<<<< HEAD
    file.open("UsuariosAlumnos.txt", ios::in);
    if(!file)
    {
        cout << "No hay informacion registrada";
=======
    //Abre un archivo en modo de lectura
    file.open("UsuariosAlumnos.txt", ios::in);
    if(!file)
    {
        //Si no hay informacion muestra el mensaje
        cout << "No hay informacion registrada";
        //Cierra el archivo
>>>>>>> ca05d99806224de811dc8563d2fc77f0fe4bf8d6
        file.close();
    }
    else
    {
        file >> nombre >> contra;
        while (!file.eof())
        {
<<<<<<< HEAD
            total++;
=======
            total++; //incrementa el contador
            //Obteniendo datos
>>>>>>> ca05d99806224de811dc8563d2fc77f0fe4bf8d6
            cout<<"       -> Ingrese un nombre: "<< nombre << endl;
            cout<<"       -> Ingrese una contrasena: "<< contra << endl;
            cout << "+---------------------------------------------------------+" << endl;
            file >> nombre >> contra;
            cout << "\n";
        }
        if (total==0)
        {
<<<<<<< HEAD
            cout << "No hay informacion registrada";
            file.close();
        }
    }
=======
            //Si no hay informacion muestra el siguiente mensaje
            cout << "No hay informacion registrada";
            //Cierra el archivo
            file.close();
        }
    }
    //Cierra el archivo
>>>>>>> ca05d99806224de811dc8563d2fc77f0fe4bf8d6
    file.close();
    system("pause");
    system("cls");
}

<<<<<<< HEAD
void usualumnos::editaDatos()
 {
    system("cls");
    fstream file, file1;
    string foundNom;

=======
//Funcion de usuario alumnos editar datos
void usualumnos::editaDatos()
 {
    //Implementacion de la bitacora
    // Obtener el usuario actual que ha iniciado sesión
    string usuarioActual = Login::getUsuarioActual();

    // Crear una instancia de la clase Bitacora para registrar el ingreso
    Bitacora bitacora;

    // Registro del ingreso en la bitácora
    bitacora.ingresoBitacora(usuarioActual, "2403", "USED"); // Parámetros

    //Limpiando pantalla
    system("cls");
    //Variables fstream y string
    fstream file, file1;
    string foundNom;

    //Encabezado editar detalles
>>>>>>> ca05d99806224de811dc8563d2fc77f0fe4bf8d6
    cout<<"+---------------------------------------------------------+"<< endl;
    cout<<"|         Editar detalles del Usuario de Alumnos          |"<< endl;
    cout<<"+---------------------------------------------------------+"<< endl;

<<<<<<< HEAD
    file.open("UsuariosAlumnos.txt", ios::in);
    if(!file)
    {
        cout << "No hay informacion registrada";
=======
    //Abre el archivo usuariosalumnos.txt en modo de lectura
    file.open("UsuariosAlumnos.txt", ios::in);
    if(!file)
    {
        //Si no hay informacion muestra lo siguiente
        cout << "No hay informacion registrada";
        //Cierra el archivo
>>>>>>> ca05d99806224de811dc8563d2fc77f0fe4bf8d6
        file.close();
    }
    else
    {
<<<<<<< HEAD
        cout << "Ingrese el nombre del usuario que quiera modificar: ";
        cin >> foundNom;
=======
        //Mensaje al usuario
        cout << "Ingrese el nombre del usuario que quiera modificar: ";
        cin >> foundNom;

        //Abre el archivo datos.txt
>>>>>>> ca05d99806224de811dc8563d2fc77f0fe4bf8d6
        file1.open("Datos.txt", ios::app | ios::out);
        file >> nombre >> contra;
        while (!file.eof())
        {
<<<<<<< HEAD
=======
            //Si encuentra el nombre
>>>>>>> ca05d99806224de811dc8563d2fc77f0fe4bf8d6
            if(foundNom!=nombre)
            {
                file1 << left << setw(15) << nombre << left << setw(10) << contra << "\n";
            }
            else
            {
<<<<<<< HEAD
=======
                //Obteniendo datos
>>>>>>> ca05d99806224de811dc8563d2fc77f0fe4bf8d6
                cout<<"       -> Ingrese un nombre: ";
                cin >> nombre;
                cout<<"       -> Ingrese una contrasena: ";
                cin >> contra;
                file1 << left << setw(15) << nombre << left << setw(10) << contra << "\n";
            }
            file >> nombre >> contra;
        }
<<<<<<< HEAD
        file1.close();
        file.close();
        remove("UsuariosAlumnos.txt");
=======
        //Cierra el archivo
        file1.close();
        //Cierra el archivo
        file.close();

        //Remueve el usuariosalumnos.txt
        remove("UsuariosAlumnos.txt");
        //Re nombre datos a usuarios alumnos.txt
>>>>>>> ca05d99806224de811dc8563d2fc77f0fe4bf8d6
        rename("Datos.txt","UsuariosAlumnos.txt");
    }
    system("pause");
    system("cls");
 }
<<<<<<< HEAD

void usualumnos::borraDatos()
{
   	system("cls");
=======
//Funcion usuarios alumnos borrar datos
void usualumnos::borraDatos()
{
    //Implementacion de la bitacora
    // Obtener el usuario actual que ha iniciado sesión
    string usuarioActual = Login::getUsuarioActual();

    // Crear una instancia de la clase Bitacora para registrar el ingreso
    Bitacora bitacora;

    // Registro del ingreso en la bitácora
    bitacora.ingresoBitacora(usuarioActual, "2404", "USBD"); // Parámetros

    //Limpiando pantalla
   	system("cls");
   	//Variables fstream y string
>>>>>>> ca05d99806224de811dc8563d2fc77f0fe4bf8d6
	fstream file, file1;
	string partcipante;

	int encontrados= 0;

<<<<<<< HEAD
=======
    //Encabezado eliminar detalles
>>>>>>> ca05d99806224de811dc8563d2fc77f0fe4bf8d6
	cout<<"+---------------------------------------------------------+"<< endl;
    cout<<"|       Eliminar detalles del Usuario de Alumnos          |"<< endl;
    cout<<"+---------------------------------------------------------+"<< endl;

<<<<<<< HEAD
	file.open("UsuariosAlumnos.txt", ios::in);
	if (!file)
	{
		cout << "\t\t\tNo hay informacion...";

=======
    //Abre el archivo usuariosalumnos en modo de lectura
	file.open("UsuariosAlumnos.txt", ios::in);
	if (!file)
	{
	    //Si no encuentra informacion muestra lo siguiente
		cout << "\t\t\tNo hay informacion...";

        //Cierra el archivo
>>>>>>> ca05d99806224de811dc8563d2fc77f0fe4bf8d6
		file.close();
	}
	else
	{
<<<<<<< HEAD
		cout << "\n Ingrese el nombre del usuario que desea eliminar : ";
		cin >> partcipante;

=======
	    //Mensaje al usuario
		cout << "\n Ingrese el nombre del usuario que desea eliminar : ";
		cin >> partcipante;

        //Abre el archivo record2.txt
>>>>>>> ca05d99806224de811dc8563d2fc77f0fe4bf8d6
		file1.open("record2.txt", ios::app | ios::out);

		file >> nombre >> contra;

<<<<<<< HEAD
		while (!file.eof())
		{
			if (partcipante != nombre)
			{
                file1<<left<<setw(15)<< nombre <<left<<setw(15)<< contra <<"\n";
			}
			else
			{
=======
        // Bucle que recorre el archivo hasta que llegue al final
		while (!file.eof())
		{
		    // Verifica si el nombre del participante actual es diferente del nombre a buscar
			if (partcipante != nombre)
			{
			    // Si son diferentes, escribe el nombre y la contraseña en el nuevo archivo
                file1<<left<<setw(15)<< nombre <<left<<setw(15)<< contra <<"\n";
			}
			else
			{   //Incrementa el contador
>>>>>>> ca05d99806224de811dc8563d2fc77f0fe4bf8d6
				encontrados++;
				cout << "\n\t\t\tBorrado del sistema exitoso"<<endl;
			}
                file >> nombre >> contra;

		}

		if (encontrados == 0)
		{
<<<<<<< HEAD
			cout << "\n\t\t\t Nombre de usuario no encontrada...";
		}

		file1.close();
		file.close();

		remove("UsuariosAlumnos.txt");

=======
		    //si no encuentra el ususario muestra lo siguiente
			cout << "\n\t\t\t Nombre de usuario no encontrada...";
		}

        //Cierra ambos archivos
		file1.close();
		file.close();

        //Remueve usuarios alumnos
		remove("UsuariosAlumnos.txt");

        //Renombra record2 a usuarios alumnos
>>>>>>> ca05d99806224de811dc8563d2fc77f0fe4bf8d6
		rename("record2.txt", "UsuariosAlumnos.txt");
	}
 }
