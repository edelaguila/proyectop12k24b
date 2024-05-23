//By Ruddyard Eduardo Castro Chavez


#include "menuIngresoMaestro.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <conio.h>
#include <iomanip>
#include "notas.h"
#include "Bitacora.h"

using namespace std;

bool menuIngresoMaestro::VerificarCarnet() {
    string usuario, contrasena;
    int contador = 0; // contador de intentos
    bool encontrado = false; // indica si encontró user y contra

    // el ciclo se repite mientras el número de intentos sea menor a 3 o no se encuentre user válido
    while (contador < 3 && !encontrado) {
        system("cls");
        cout << "\t\t\t+-----------------------------------+" << endl;
        cout << "\t\t\t|       LOGIN  Maestro              |" << endl;
        cout << "\t\t\t+-----------------------------------+" << endl;
        cout << "\t\t\t|Solo tienes permitido 3 intentos   |" << endl;
        cout << "\t\t\t+-----------------------------------+" << endl;
        cout << "\t\t\tIngrese el nombre: ";
        cin >> usuario;
        cout << "\t\t\tIngrese la contrasena: ";
        char caracter;
        caracter = getch();

        // ocultar a la hora de escribir la contraseña
        contrasena = "";
        while (caracter != 13) { // ASCII enter
            if (caracter != 8) { // ASCII backspace
                contrasena.push_back(caracter);
                cout << "*";
            } else {
                if (contrasena.length() > 0) {
                    cout << "\b \b";
                    contrasena = contrasena.substr(0, contrasena.length() - 1);
                }
            }
            caracter = getch();
        }

        // abrir el archivo de User y contraseñas
        ifstream fileU_P;
        fileU_P.open("contraseniaMaestro.txt", ios::in);

        // verificar si se abrió el archivo
        if (!fileU_P) {
            cout << "\n\t\t\t No es posible abrir el archivo." << endl;
            fileU_P.close();
            return false;
        }
        string codigoPrograma = "5600";
        Bitacora Auditoria;

        // busca el usuario en el archivo
        string user, pass;
        while (fileU_P >> user >> pass) {
            if (user == usuario && pass == contrasena) {
                Auditoria.ingresoBitacora(user, codigoPrograma, "LMA");
                encontrado = true;
                break;
            }
        }
        fileU_P.close();

        // si no encuentra user y pass, el contador incrementará
        if (!encontrado) {
            cout << "\n\n\t\t\tNombre incorrecto" << endl;
            cout << "\n\n\t\t\tPerdio un intento, intente de nuevo\n" << endl;
            contador++;
            system("pause");
        }
    }

    // Si encuentra a user y pass, se retornará un true
    if (encontrado) {
        system("cls");
        cout << "\n\t----- Bienvenido " << usuario << " -----" << endl;
        system("pause");

        // abrir el archivo de cursos asignados
        ifstream fileCursos;
        fileCursos.open("cursosAsignadosMaestro.txt", ios::in);

        // verificar si se abrió el archivo
        if (!fileCursos) {
            cout << "\n\t\t\t No es posible abrir el archivo." << endl;
            fileCursos.close();
            return false;
        }

        system("cls");

//Gabriela Pinto García carne: 9959 - 23 - 1087
//modificacion de menu maestro

        // busca el nombre de el usuario en el archivo txt, y lee las clases asignadas
        cout << "\n\t----- Clases Dadas -----" << endl;
        string line;
        vector<string> clases;
        bool clasesEncontradas = false;

        // leer las líneas del archivo
        while (getline(fileCursos, line)) {
            stringstream ss(line);
            string nombreMaestro, clase;
            // leer el nombre del catedratico
            ss >> nombreMaestro;
            if (nombreMaestro == usuario) {
                clasesEncontradas = true;
                while (ss >> clase) { // Leer todas las clases asignadas al maestro
                    clases.push_back(clase);
                }
                break; //Deja de buscar más líneas, una vez se encuentran las clases del maestro
            }
        }
        fileCursos.close();

        if (!clasesEncontradas) {
            cout << "\n\tNo se encontraron clases dadas para este usuario." << endl;
        } else {

            // despliega un menu de clases
            for (int i = 0; i < clases.size(); i++) {
                cout << "\t" << (i + 1) << ". " << clases[i] << endl;
            }

            //Se le pide que ingrese una opcion
            cout << "\n\tSeleccione una clase [1/2/3]: ";
            cout << " ";
            int opcion;
            cin >> opcion; //Lee las opciones seleccionadas por el usuario

            if (opcion > 0 && opcion <= clases.size()) {

                    // Verificar que la opción seleccionada sea válida
                string claseSeleccionada = clases[opcion - 1]; // Obtener la clase seleccionada
                cout << "\n\tClase seleccionada: " << claseSeleccionada << endl;
                system("pause");

                // lógica para manejar la clase seleccionada
                NotaCrud n;
                n.CrudNota();
            } else {
                cout << "\n\tOpción inválida." << endl;
            }
        }

        return true; // Retornar true si se encuentra un usuario y contraseña válidos
    } else {
        system("cls");//limpiamos

        // Mensaje de error si el usuario no logró ingresar correctamente después de 3 intentos
        cout << "\n\n\t\t\tPERDIÓ LOS 3 INTENTOS" << endl;
        system("pause");
        exit(0);// Terminar el programa si se alcanzan los 3 intentos fallidos


        return false;
    }
}

