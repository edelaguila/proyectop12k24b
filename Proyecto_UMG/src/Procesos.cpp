#include <iostream>
#include <fstream>
#include <iomanip>
#include "Procesos.h"
#include "procealumnos.h"
#include "ProcesoMaestros.h"


using namespace std;

Procesos::Procesos()
{

}

void Procesos::menuGenerar()
{
    int opc;
    do
    {
        system("cls");
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

        switch(opc)
        {
        case 1:
            {
                procealumnos procesoalu;
                procesoalu.menu();
            }
            break;
        case 2:
            {
            ProceMaestros procesomaes;
            procesomaes.menu();
            }
            break;
        case 3:
            break;
        }
    } while (opc!=3);
}
