//Incluyendo librerias
#include <iostream>
#include <fstream>
#include <iomanip>
//Incluyendo encabezados
#include "Login.h"
#include "Bitacora.h"

using namespace std;

//Clase usumaestros
class usumaestros
{
    //Atributos publicos
    public:
        //Funciones
        void menu();
        void pideDatos();
        void muestraDatos();
        void editaDatos();
        void borraDatos();

    //Atributos privados
    private:
        //Variables
        string nombre, contra;
};

//Funcion mostrar menu de usuario alumnos
void usumaestros::menu()
{
    //Implementacion de la bitacora
    // Obtener el usuario actual que ha iniciado sesión
    string usuarioActual = Login::getUsuarioActual();

    // Crear una instancia de la clase Bitacora para registrar el ingreso
    Bitacora bitacora;

    // Registro del ingreso en la bitácora
    bitacora.ingresoBitacora(usuarioActual, "2500", "UMM"); // Parámetros


    //Variable int
    int opc;
    //Ciclo do while
    do
    {
        //Limpiando pantalla
        system("cls");

        //Diseño de gestion de usuarios de alumnos
        cout<<"+-----------------------------------------------+"<<endl;
		cout<<"|       Gestion de Usuarios de Maestros         |"<<endl;
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
    } while (opc!=5);

}

//Funcion pedir datos
void usumaestros::pideDatos()
{
    //Implementacion de la bitacora
    // Obtener el usuario actual que ha iniciado sesión
    string usuarioActual = Login::getUsuarioActual();

    // Crear una instancia de la clase Bitacora para registrar el ingreso
    Bitacora bitacora;

    // Registro del ingreso en la bitácora
    bitacora.ingresoBitacora(usuarioActual, "2501", "UMPD"); // Parámetros

    //Limpiando pantalla
    system("cls");

    //Variable fstream
    fstream file;

    //Encabezado agregar detalles del usuario de maestros
    cout<<"+---------------------------------------------------------+"<< endl;
    cout<<"|       Agregar detalles del Usuario de Maestros          |"<< endl;
    cout<<"+---------------------------------------------------------+"<< endl;

    //Mensajes al usuario
    cout<<"       -> Ingrese un nombre: ";
    cin >> nombre;
    cout<<"       -> Ingrese una contrasena: ";
    cin >> contra;

    // Abre el archivo "UsuariosMaestros.txt" en modo de añadir al final y escritura
    file.open("UsuariosMaestros.txt", ios::app | ios::out);
    // Escribe los datos  en el archivo, separados por espacios
    file << left << setw(15) << nombre << left << setw(10) << contra << "\n";

    // Cierra el archivo
    file.close();
    cout << "\n" << endl;
    system("pause");
    system("cls");
}

//Funcion de maestros mostrar datos
void usumaestros::muestraDatos()
{
    //Implementacion de la bitacora
    // Obtener el usuario actual que ha iniciado sesión
    string usuarioActual = Login::getUsuarioActual();

    // Crear una instancia de la clase Bitacora para registrar el ingreso
    Bitacora bitacora;

    // Registro del ingreso en la bitácora
    bitacora.ingresoBitacora(usuarioActual, "2502", "UMMD"); // Parámetros

    //Limpiando pantalla
    system("cls");

    //Variables fstream y int
    fstream file;
    int total=0;

    //Encabezado mostrar detalles
    cout<<"+---------------------------------------------------------+"<< endl;
    cout<<"|       Mostrar detalles del Usuario de Maestros          |"<< endl;
    cout<<"+---------------------------------------------------------+"<< endl;

    //Abre un archivo en modo de lectura
    file.open("UsuariosMaestros.txt", ios::in);
    if(!file)
    {
        //Si no hay informacion muestra el mensaje
        cout << "No hay informacion registrada";
        //Cierra el archivo
        file.close();
    }
    else
    {
        file >> nombre >> contra;
        while (!file.eof())
        {
            total++; //incrementa el contador
            //Obteniendo datos
            cout<<"       -> Ingrese un nombre: "<< nombre << endl;
            cout<<"       -> Ingrese una contrasena: "<< contra << endl;
            cout << "+---------------------------------------------------------+" << endl;
            file >> nombre >> contra;
            cout << "\n";
        }
        if (total==0)
        {
            //Si no hay informacion muestra el siguiente mensaje
            cout << "No hay informacion registrada";
            //Cierra el archivo
            file.close();
        }
    }
    //Cierra el archivo
    file.close();
    system("pause");
    system("cls");
}

//Funcion de usuario maestros editar datos
void usumaestros::editaDatos()
 {
     //Implementacion de la bitacora
    // Obtener el usuario actual que ha iniciado sesión
    string usuarioActual = Login::getUsuarioActual();

    // Crear una instancia de la clase Bitacora para registrar el ingreso
    Bitacora bitacora;

    // Registro del ingreso en la bitácora
    bitacora.ingresoBitacora(usuarioActual, "2503", "UMED"); // Parámetros

    //Limpiando pantalla
    system("cls");
    //Variables fstream y string
    fstream file, file1;
    string foundNom;

    //Encabezado editar detalles
    cout<<"+---------------------------------------------------------+"<< endl;
    cout<<"|        Editar detalles del Usuario de Maestros          |"<< endl;
    cout<<"+---------------------------------------------------------+"<< endl;

    //Abre el archivo usuariosalumnos.txt en modo de lectura
    file.open("UsuariosMaestros.txt", ios::in);
    if(!file)
    {
        //Si no hay informacion muestra lo siguiente
        cout << "No hay informacion registrada";
        //Cierra el archivo
        file.close();
    }
    else
    {
        //Mensaje al usuario
        cout << "Ingrese el nombre del usuario que quiera modificar: ";
        cin >> foundNom;
        //Abre el archivo datos.txt
        file1.open("Datos.txt", ios::app | ios::out);
        file >> nombre >> contra;
        while (!file.eof())
        {
            //Si encuentra el nombre
            if(foundNom!=nombre)
            {
                file1 << left << setw(15) << nombre << left << setw(10) << contra << "\n";
            }
            else
            {
                cout<<"       -> Ingrese un nombre: ";
                cin >> nombre;
                cout<<"       -> Ingrese una contrasena: ";
                cin >> contra;
                file1 << left << setw(15) << nombre << left << setw(10) << contra << "\n";
            }
            file >> nombre >> contra;
        }
        //Cierra el archivo
        file1.close();
        //Cierra el archivo
        file.close();

        //Remueve el usuariosalumnos.txt
        remove("UsuariosMaestros.txt");
        //Re nombre datos a usuarios alumnos.txt
        rename("Datos.txt","UsuariosMaestros.txt");
    }
    system("pause");
    system("cls");
 }
//Funcion usuarios alumnos borrar datos
void usumaestros::borraDatos()
{
    //Implementacion de la bitacora
    // Obtener el usuario actual que ha iniciado sesión
    string usuarioActual = Login::getUsuarioActual();

    // Crear una instancia de la clase Bitacora para registrar el ingreso
    Bitacora bitacora;

    // Registro del ingreso en la bitácora
    bitacora.ingresoBitacora(usuarioActual, "2504", "UMBD"); // Parámetros

   //Limpiando pantalla
   	system("cls");
   	//Variables fstream y string
	fstream file, file1;
	string partcipante;

	int encontrados= 0;

    //Encabezado eliminar detalles
	cout<<"+---------------------------------------------------------+"<< endl;
    cout<<"|      Eliminar detalles del Usuario de Maestros          |"<< endl;
    cout<<"+---------------------------------------------------------+"<< endl;

    //Abre el archivo usuariosalumnos en modo de lectura
	file.open("UsuariosMaestros.txt", ios::in);
	if (!file)
	{
	    //Si no encuentra informacion muestra lo siguiente
		cout << "\t\t\tNo hay informacion...";

        //Cierra el archivo
		file.close();
	}
	else
	{
		//Mensaje al usuario
		cout << "\n Ingrese el nombre del usuario que desea eliminar : ";
		cin >> partcipante;

        //Abre el archivo record2.txt
		file1.open("record2.txt", ios::app | ios::out);

		file >> nombre >> contra;

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
				encontrados++;
				cout << "\n\t\t\tBorrado del sistema exitoso"<<endl;
			}
                file >> nombre >> contra;

		}

		if (encontrados == 0)
		{
		    //si no encuentra el ususario muestra lo siguiente
			cout << "\n\t\t\t Nombre de usuario no encontrada...";
		}

        //Cierra ambos archivos
		file1.close();
		file.close();

        //Remueve usuarios alumnos
		remove("UsuariosMaestros.txt");

        //Renombra record2 a usuarios alumnos
		rename("record2.txt", "UsuariosMaestros.txt");
	}
 }
