#include <iostream>
#include <fstream>
#include <iomanip>

//Incluyendo el encabezado procesos, procesosalumnos y procesomaestros
#include "Procesos.h"
#include "procealumnos.h"
#include "ProcesoMaestros.h"
#include "login.h"
#include "Bitacora.h"


using namespace std;

//Constructor procesos
Procesos::Procesos()
{
}

//Funcion para mostrar la funcion menu generar
void Procesos::menuGenerar()
{



    //Variable int
    int opc;

    //Inicio do while
    do
    {
        //Limpia pantalla
        system("cls");

        //Diseño del menu gestion de procesos
        cout<<"+-----------------------------------------------+"<<endl;
        cout<<"|              Gestion de Procesos              |"<<endl;
        cout<<"+-----------------------------------------------+"<<endl;
        cout<<"|          1. Procesos de Alumnos               |"<<endl;
        cout<<"|          2. Procesos de Maestros              |"<<endl;
        cout<<"|          3. Regresar al menu                  |"<<endl;
        cout<<"+-----------------------------------------------+"<<endl;
        cout<<"|          Ingrese su opcion [1/2/3]            |"<<endl;
        cout<<"+-----------------------------------------------+"<<endl;
        cin >> opc;

        //switch opcion
        switch(opc)
        {

        //Opcion 1
        case 1:
            {   //instancia de procesoalumnos
                procealumnos procesoalu;
                //abre el menu de proceso alumnos
                procesoalu.menu();
            }
            break;
        case 2:
            {
            //instancia de ProcesoMaestros
            ProceMaestros maestros;
            //abre el menu de proceso alumnos
            maestros.menu();
            }
            break;
        case 3:
            break;
        }
    //Si es opcion 3 regresa al menu
    } while (opc!=3);
}
