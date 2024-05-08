
//Creado por Jose Gallardo 9959-23-106

#include <iostream>
#include <cstdlib>
#include <conio.h>
#include "usuarios.h"
#include "Login.h"
#include "Sedes.h"

using namespace std;

void menuGeneral();
void catalogos();
void reportes();
void procesos();
void ayuda();
void seguridad();



int main()
{

    string user, contrasena;

    // Llamamos al objeto e ingresamos los parametros
    Login ingreso(user, contrasena);

    // Creamos un bool que verifique y despliegue el metodo VerificarUsuario
    bool UsuarioCorrecto = ingreso.VerificarUsuario();

    // Luego de ingresar con usuario y contrase�a se nos despliega otro menu
    if (UsuarioCorrecto)
    {
        menuGeneral();
    }

    return 0;
}

void menuGeneral()
{
    int choice;


    do
    {
        system("cls");
        cout << "\t\t\t-------------------------------" << endl;
        cout << "\t\t\t|   SISTEMA DE GESTION UMG     |" << endl;
        cout << "\t\t\t-------------------------------" << endl;
        cout << "\t\t\t 1. Catalogos" << endl;
        cout << "\t\t\t 2. Procesos" << endl;
        cout << "\t\t\t 3. Reportes" << endl;
        cout << "\t\t\t 4. Seguridad" << endl;
        cout << "\t\t\t 5. Ayuda" << endl;
        cout << "\t\t\t 6. Salir del Sistema" << endl;
        cout << "\t\t\t-------------------------------" << endl;
        cout << "\t\t\t|Opcion a escoger:[1/2/3/4/5/6]  |" << endl;
        cout << "\t\t\t-------------------------------" << endl;
        cout << "\t\t\tIngresa tu Opcion: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            catalogos();
            break;
        case 2:
            procesos();
            break;
        case 3:
            reportes();
            break;
        case 4:
            seguridad();
            break;
        case 5:
            ayuda();
            break;
        case 6:
            exit(0);
        default:
            cout << "\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
            cin.ignore();
            cin.get();
        }
    } while (choice != 6);
}

void catalogos()
{
    int choice;

    do
    {
        system("cls");
        cout << "\t\t\t--------------------------------------------" << endl;
        cout << "\t\t\t|   SISTEMA DE GESTION UMG - CATALOGOS      |" << endl;
        cout << "\t\t\t--------------------------------------------" << endl;
        cout << "\t\t\t 1. Alumnos" << endl;
        cout << "\t\t\t 2. Maestros" << endl;
        cout << "\t\t\t 3. Usuarios del sistema" << endl;
        cout << "\t\t\t 4. Carreras" << endl;
        cout << "\t\t\t 5. Facultades" << endl;
        cout << "\t\t\t 6. Cursos" << endl;
        cout << "\t\t\t 7. Jornadas" << endl;
        cout << "\t\t\t 8. Aulas" << endl;
        cout << "\t\t\t 9. Secciones" << endl;
        cout << "\t\t\t 10. Sedes" << endl;
        cout << "\t\t\t 11. Horarios" << endl;
        cout << "\t\t\t 12. Retornar menu anterior" << endl;
        cout << "\t\t\t --------------------------------------------" << endl;
        cout << "\t\t\t | Opcion a escoger:[1-12]|" << endl;
        cout << "\t\t\t --------------------------------------------" << endl;
        cout << "\t\t\tIngresa tu Opcion: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            // Implementaci�n para Alumnos
            break;
        case 2:
            // Implementaci�n para Maestros
            break;
        case 3:
        {
            usuarios usuario;
            usuario.menuUsuarios();
            break;
        }
        case 4:
            // Implementaci�n para Carreras
            break;
        case 5:
            // Implementaci�n para Facultades
            break;
        case 6:
            // Implementaci�n para Cursos
            break;
        case 7:
            // Implementaci�n para Jornadas
            break;
        case 8:
            // Implementaci�n para Aulas
            break;
        case 9:
            // Implementaci�n para Secciones
            break;
        case 10:
            Sedes sede;
            sede.menu();
            break;
        case 11:
            // Implementaci�n para Horarios
            break;
        case 12:
            menuGeneral();
            break;
        default:
            cout << "\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
            cin.ignore();
            cin.get();
        }
    } while (choice != 12);
}

void procesos()
{
    // Implementaci�n de procesos
}

void reportes()
{
    // Implementaci�n de reportes
}

void ayuda()
{
    // Implementaci�n de ayuda
}

void seguridad()
{
    // Implementaci�n de seguridad
}
