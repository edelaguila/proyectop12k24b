#include "loginNotas.h" // Incluye el archivo de cabecera "loginNotas.h"
// Incluye el archivo de cabecera "menuIngresoAlumno.h"
#include "menuIngresoAlumno.h"
// Incluye el archivo de cabecera "menuIngresoMaestro.h"
#include "menuIngresoMaestro.h"
// Incluye el archivo de cabecera "notas.h"
#include "notas.h"

// Incluye la biblioteca iostream que permite la entrada y salida de datos
#include<iostream>
// Incluye la biblioteca fstream que permite la lectura y escritura de archivos
#include<fstream>
// Incluye la biblioteca stdlib que proporciona funciones generales de utilidad
#include<stdlib.h>
// Incluye la biblioteca cstdlib que proporciona funciones generales de utilidad
#include<cstdlib>
// Incluye la biblioteca conio.h que proporciona funciones para controlar la entrada y salida de la consola
#include<conio.h>
// Incluye la biblioteca iomanip que proporciona funciones para manipular la salida formateada
#include<iomanip>

// Utiliza el espacio de nombres estándar. Esto evita tener que escribir std:: antes de cada uso de objetos de la biblioteca estándar
using namespace std;

// Define la función miembro menuGeneralNotas de la clase loginNotas
void loginNotas::menuGeneralNotas() {
    // Declara una variable entera llamada choice
    int choice;

    // Inicia un bucle do-while
    do
    {
        // Limpia la consola
        system("cls");
        // Imprime el menú en la consola
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
        // Lee la opción del usuario desde la consola
        cin >> choice;

        // Inicia una estructura switch que ejecuta diferentes bloques de código dependiendo del valor de choice
        switch (choice)
        {
            // Si choice es 1
            case 1:
                // Llama a la función miembro menuGeneralNotasAlumno
                menuGeneralNotasAlumno();
                break;
            // Si choice es 2
            case 2:
                // Llama a la función miembro menuGeneralNotasMaestro
                menuGeneralNotasMaestro();
                break;
            // Si choice es 3
            case 3:
                // Imprime un mensaje en la consola
                cout << "Saliendo del sistema..." << endl;
                break;
            default:
                // Imprime un mensaje en la consola
                cout << "Opcion no valida, intenta de nuevo." << endl;
        }
    // El bucle do-while continúa mientras choice sea diferente de 3
    } while (choice != 3);

}

// Define la función miembro menuGeneralNotasAlumno de la clase loginNotas
void loginNotas::menuGeneralNotasAlumno(){
    // Crea un objeto ia de la clase menuIngresoAlumno
    menuIngresoAlumno ia;
    // Llama a la función miembro VerificarCarnet del objeto ia
    ia.VerificarCarnet();

}

// Define la función miembro menuGeneralNotasMaestro de la clase loginNotas
void loginNotas::menuGeneralNotasMaestro(){
    // Crea un objeto im de la clase menuIngresoMaestro
    menuIngresoMaestro im;
    // Llama a la función miembro VerificarCarnet del objeto im
    im.VerificarCarnet();

}

