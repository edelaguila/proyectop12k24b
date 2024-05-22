#include "menuIngresoAlumno.h"
#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<cstdlib>
#include<conio.h>
#include<iomanip>
#include "notas.h"
#include "Bitacora.h"
using namespace std;
 bool menuIngresoAlumno::VerificarCarnet()
 {

      string usuario,contrasena;
    int contador= 0; // contador de intentos
    bool encontrado =false; // indica si encontro user y contra

    //el ciclo se repite mientras el numero de intentos sea menor a 3 o no se encuentre user valido
    while(contador<3 && !encontrado)
    {
         system("cls");
    cout <<"\t\t\t+-----------------------------------+"<<endl;
    cout <<"\t\t\t|       LOGIN  Alumno                     |"<<endl;
    cout <<"\t\t\t+-----------------------------------+"<<endl;
    cout <<"\t\t\t|Solo tienes permitido 3 intentos   |"<<endl;
    cout <<"\t\t\t+-----------------------------------+"<<endl;
    cout <<"\t\t\tIngrese nombre: ";
    cin >> usuario;
 cout <<"\t\t\tIngrese la contrasena: ";
    char caracter;
    caracter = getch();

    // ocultar a la hora de escribir la contraseña
    contrasena="";
        while (caracter!=13)//ascci enter
        {
        if(caracter !=8)//ascci backs pace
            {
                contrasena.push_back(caracter);
                cout<<"*";
            }
        else
            {
                if(contrasena.length()>0)
                {
                    cout<<"\b \b";
                    contrasena=contrasena.substr(0,contrasena.length()-1);
                }
            }
            caracter=getch();
        }

    //abrira el contrasenias Estudiantes--------------------------
    ifstream fileU_P;
    fileU_P.open("contraseniaEstuantes.txt",ios::in);


    //verificar si se abrio el archivo---------------------------
    if (!fileU_P)
    {
        cout<<"\n\t\t\t No es posible abrir el archivo."<<endl;
        fileU_P.close();
        return false;
    }
    string codigoPrograma="5030";
    Bitacora Auditoria;

    //busca el usuario en el archivo---------------------------------
    string user,pass;
    while (fileU_P>>user>>pass)
    {
        if (user==usuario&&pass==contrasena )
        {
            // Que esra LGI
            Auditoria.ingresoBitacora(user,codigoPrograma,"RN");
            encontrado=true;
            break;
        }
    }
     fileU_P.close();

    //si no encuentra user y pass , el contador incrementara------------------------
    if(!encontrado)
    {
        cout << "\n\n\t\t\tCarnet incorrecto" << endl;
        cout << "\n\n\t\t\tPerdio un intento, Intente de nuevo\n" << endl;
        contador++;
        system("pause");
    }
}

    //Si encuentra a user y pass , se retornara un true
   if (encontrado)
    {
    	         system("cls");

    cout << "\n\t----- Bienvenido " << usuario << " -----" << endl;
     system("pause");

//     NotaCrud n;
//     n.DesplegarNotas();
//

//
//void consultarRegistro( fstream &leerDeArchivo )
//{
//
//   cout << left << setw( 10 ) << "nombre" << setw( 16 )
//       << "carnet" << setw( 14 ) << "Primer nota" << right
//       << setw( 10 ) << "segunda nota"<< setw( 10 ) << "tercera nota" << setw( 10 ) << "actividades nota"<< setw( 10 ) << "nota final"<< endl;
//
//   // colocar el apuntador de posición de archivo al principio del archivo de registros
//   leerDeArchivo.seekg( 0 );
//
//   // leer el primer registro del archivo de registros
//   DatosCliente cliente;
//   leerDeArchivo.read( reinterpret_cast< char * >( &cliente ),
//      sizeof( DatosCliente ) );
//
//   // copiar todos los registros del archivo de registros en el archivo de texto
//   while ( !leerDeArchivo.eof() ) {
//
//      // escribir un registro individual en el archivo de texto
//      if ( cliente.obtenerNumeroCuenta() != 0 )
//         mostrarLineaPantalla(cliente);
//
//      // leer siguiente registro del archivo de registros
//      leerDeArchivo.read( reinterpret_cast< char * >( &cliente ),
//         sizeof( DatosCliente ) );
//
//   } // fin de instrucción while
//
//} // fin de la función consultarRegistro
//


















     //cout<<"aqui debe ingresar a la visualizacion de notas"<< endl;
      //      n.CrudNota();
    return true;
    }
   else
    {
	system("cls");
    cout << "\n\n\t\t\tPERDIO LOS 3 INTENTOS" << endl;
     system("pause");
     exit(0);

    return false;
    }





}

