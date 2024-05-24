//By Ruddyard Eduardo Castro Chavez

#include "menuIngresoMaestro.h"
#include "notas.h"
#include "Bitacora.h"

#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <conio.h>
#include <iomanip>

using namespace std;
// Variables para almacenar el usuario y la contraseña
bool menuIngresoMaestro::VerificarCarnet() {
    string usuario, contrasena;
    // Contador de intentos fallidos
    int contador = 0;
    // Bandera para indicar si se encontró el usuario y la contraseña correctos
    bool encontrado = false;

    // Bucle que se repite mientras el número de intentos sea menor a 3 y no se haya encontrado un usuario válido
    while (contador < 3 && !encontrado) {
        system("cls"); // Limpiar la pantalla
        cout << "\t\t\t+-----------------------------------+" << endl;
        cout << "\t\t\t|       LOGIN  Maestro              |" << endl;
        cout << "\t\t\t+-----------------------------------+" << endl;
        cout << "\t\t\t|Solo tienes permitido 3 intentos   |" << endl;
        cout << "\t\t\t+-----------------------------------+" << endl;
        cout << "\t\t\tIngrese el nombre: ";
        // Leer el nombre de usuario
        cin >> usuario;
        cout << "\t\t\tIngrese la contrasena: ";
        char caracter;
        // Leer un carácter sin mostrarlo en la pantalla
        caracter = getch();

        // Ocultar la entrada de la contraseña mientras se escribe
        contrasena = "";
        // 13 es el código ASCII para Enter
        while (caracter != 13) {
                // 8 es el código ASCII para Backspace
            if (caracter != 8) {
                // Añadir el carácter a la contraseña
                contrasena.push_back(caracter);
        // Mostrar un asterisco en lugar del carácter
                cout << "*";
            } else {
                if (contrasena.length() > 0) {
                        // Borrar el último asterisco
                    cout << "\b \b";
                // Eliminar el último carácter de la contraseña
                    contrasena = contrasena.substr(0, contrasena.length() - 1);
                }
            }
            caracter = getch(); // Leer el siguiente carácter
        }

        // Abrir el archivo de usuarios y contraseñas
        ifstream fileU_P;
        fileU_P.open("contraseniaMaestro.txt", ios::in);

        // Verificar si el archivo se abrió correctamente
        if (!fileU_P) {
            cout << "\n\t\t\t No es posible abrir el archivo." << endl;
            fileU_P.close();
            return false;
        }
        // Código del programa para bitacora
        string codigoPrograma = "5600";
        // Objeto para registrar en la bitacora
        Bitacora Auditoria;

        // Buscar el usuario en el archivo
        string user, pass;
        while (fileU_P >> user >> pass) {
            if (user == usuario && pass == contrasena) {
                    // Registrar el ingreso en la bitacora
                Auditoria.ingresoBitacora(user, codigoPrograma, "LMA");
            // Usuario y contraseña encontrados
                encontrado = true;
                break;
            }
        }
        // Cerrar el archivo
        fileU_P.close();

        // Si no se encuentra el usuario y la contraseña, incrementar el contador
        if (!encontrado) {
            cout << "\n\n\t\t\tNombre incorrecto" << endl;
            cout << "\n\n\t\t\tPerdio un intento, intente de nuevo\n" << endl;
            // Incrementar el contador de intentos fallidos
            contador++;
            // Pausar el sistema para que el usuario vea el mensaje
            system("pause");
        }
    }

    // Si se encuentra el usuario y la contraseña, retornar true
    if (encontrado) {
             // Limpiar la pantalla
        system("cls");
        // Pausar el sistema para que el usuario vea el mensaje
        cout << "\n\t----- Bienvenido " << usuario << " -----" << endl;
        system("pause");

        // Abrir el archivo de cursos asignados
        ifstream fileCursos;
        fileCursos.open("cursosAsignadosMaestro.txt", ios::in);

        // Verificar si el archivo se abrió correctamente
        if (!fileCursos) {
            cout << "\n\t\t\t No es posible abrir el archivo." << endl;
            fileCursos.close();
            return false;
        }
    // Limpiar la pantalla
        system("cls");

//Gabriela Pinto García carne: 9959 - 23 - 1087
//modificacion de menu maestro

        // buscar el nombre de usuario en el archivo y mostrar las clases asociadas
        cout << "\n\t----- Clases Dadas -----" << endl;
        string line;
        vector<string> clases;
        bool clasesEncontradas = false;

        // leer cada línea del archivo
        while (getline(fileCursos, line)) {
            stringstream ss(line);
            string nombreMaestro, clase;
            ss >> nombreMaestro; // leer el nombre del maestro
            if (nombreMaestro == usuario) {
                clasesEncontradas = true;
                while (ss >> clase) {
                    clases.push_back(clase);
                }
                break;
            }
        }
        fileCursos.close();

        if (!clasesEncontradas) {
            cout << "\n\tNo se encontraron clases dadas para este usuario." << endl;
        } else {
            // mostrar el menú de clases
            for (int i = 0; i < clases.size(); i++) {
                cout << "\t" << (i + 1) << ". " << clases[i] << endl;
            }

            cout << "\n\tSeleccione una clase ingresando el número correspondiente: ";
            int opcion;
            cin >> opcion;

            if (opcion > 0 && opcion <= clases.size()) {
                string claseSeleccionada = clases[opcion - 1];
                cout << "\n\tClase seleccionada: " << claseSeleccionada << endl;
                system("pause");

                // lógica para manejar la clase seleccionada
                NotaCrud n;
                n.CrudNota();
            } else {
                cout << "\n\tOpción inválida." << endl;
            }
        }

        return true;
    } else {
        system("cls");
        cout << "\n\n\t\t\tPERDIÓ LOS 3 INTENTOS" << endl;
        system("pause");
        exit(0);

        return false;
    }
}

