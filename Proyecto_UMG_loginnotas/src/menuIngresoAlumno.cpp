//By Ruddyard Eduardo Castro Chavez 9959-23-1409

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

      string usuario;
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
    cout <<"\t\t\tIngrese numero de carnet: ";
    cin >> usuario;

    //abrira el archivo de User y contraseñas--------------------------
    ifstream fileU_P;
    fileU_P.open("usuarios_y_contrasenas prueba.txt",ios::in);


    //verificar si se abrio el archivo---------------------------
    if (!fileU_P)
    {
        cout<<"\n\t\t\t No es posible abrir el archivo."<<endl;
        fileU_P.close();
        return false;
    }
    string codigoPrograma="1000";
    Bitacora Auditoria;

    //busca el usuario en el archivo---------------------------------
    string user;
    while (fileU_P>>user)
    {
        if (user==usuario )
        {
            // Que esra RN
            Auditoria.ingresoBitacora(user,codigoPrograma,"RN");
            encontrado=true;
            break;
        }
    }
     fileU_P.close();

    //si no encuentra user  , el contador incrementara------------------------
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
     NotaCrud n;
            n.CrudNota();
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

