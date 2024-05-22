#include "loginNotas.h"
#include "menuIngresoAlumno.h"
#include "menuIngresoMaestro.h"
#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<cstdlib>
#include<conio.h>
#include<iomanip>
#include "notas.h"
using namespace std;

void loginNotas::menuGeneralNotas() {
     int choice;

    do
    {
        system("cls");
        cout << "\t\t\t-------------------------------" << endl;
        cout << "\t\t\t|   Login notas     |" << endl;
        cout << "\t\t\t-------------------------------" << endl;
        cout << "\t\t\t 1. Ingreso alumno" << endl;
        cout << "\t\t\t 2. Ingreso Maestro" << endl;
        cout << "\t\t\t 3. Regresar al menu anterior" << endl;
        cout << "\t\t\t-------------------------------" << endl;
        cout << "\t\t\t|Opcion a escoger:[1/2/3]  |" << endl;
        cout << "\t\t\t-------------------------------" << endl;
        cout << "\t\t\tIngresa tu Opcion: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                menuGeneralNotasAlumno();
                break;
            case 2:
                menuGeneralNotasMaestro();
                break;
            case 3:
                cout << "Saliendo del sistema..." << endl;
                break;
            default:
                cout << "Opcion no valida, intenta de nuevo." << endl;
        }
    } while (choice != 3);

}

void loginNotas::menuGeneralNotasAlumno(){



            menuIngresoAlumno ia;
            ia.VerificarCarnet();

}
void loginNotas::menuGeneralNotasMaestro(){

            menuIngresoMaestro im;
            im.VerificarCarnet();


}
