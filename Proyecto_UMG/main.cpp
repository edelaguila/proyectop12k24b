//Creado por Jose Gallardo 9959-23-106
#include <iostream>
#include <cstdlib>
#include <conio.h>
#include "usuarios.h"
#include "Login.h"
#include "Bitacora.h"
#include "alumnos.h"
#include "maestros.h"
#include "Login_Alumno.h"
#include "Carrera.h"
#include "Facultad.h"
#include "Cursoss.h"
#include "AsigCursos_Alumnos.h"
#include "jornada.h"
#include "aulas.h"
#include "secciones.h"

using namespace std;

void menuGeneral();
void catalogos();
void reportes();
void procesos();
void ayuda();
void seguridad();
string codigoPrograma="1";
Bitacora Auditoria;
string user, contrasena;

int main()
{
        // Llamamos al objeto e ingresamos los parametros
    Login ingreso(user, contrasena);

    // Creamos un bool que verifique y despliegue el metodo VerificarUsuario
    bool UsuarioCorrecto = ingreso.VerificarUsuario();

    // Luego de ingresar con usuario y contraseña se nos despliega otro menu
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
            {
               Bitacora Auditoria;
               Auditoria.visualizarBitacora();
            }
            break;
        case 5:
            ayuda();
            break;
        case 6:
                    Auditoria.ingresoBitacora(user,codigoPrograma,"LGO"); //llamada para registrar la bitacora de seguridad
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
        {
            alumnos alumno;
            alumno.menu();
        }
            break;
        case 2:
        {
            maestros maestro;
            maestro.menu();
        }
            break;
        case 3:
        {
            usuarios usuario;
            usuario.menuUsuarios();
            break;
        }
        case 4:
            CarrerasCRUD CCarrera;
            CCarrera.Crudcarrera();
            break;
        case 5:
             FacultadCRUD FFacultad;
             FFacultad.Crudfacultad();
            break;
        case 6:
           CursosCRUD CCurso;
           CCurso.CrudCursos();
            break;
        case 7:
            JornadaCRUD jjornada;
            jjornada.CrudJornada();
            break;
        case 8:
            AulasCRUD Aaula;
            Aaula.CrudAula();
            break;
        case 9:
            SeccionesCrud sec;
            sec.CrudSeccion();
            break;
        case 10:
            // Implementación para Sedes
            break;
        case 11:
            // Implementación para Horarios
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
    int choice;
    do {
        system("cls");
        cout << "\t\t\t--------------------------------------------" << endl;
        cout << "\t\t\t|      SISTEMA GESTION UMG - Procesos       |" << endl;
        cout << "\t\t\t--------------------------------------------" << endl;
        cout << "\t\t\t 1. Asignacion de Cursos a Alumnos" << endl;
        cout << "\t\t\t 2. Asignacion de Cursos a maestros" << endl;
        cout << "\t\t\t 3. Retornar menu anterior" << endl;
        cout << "\t\t\t--------------------------------------------" << endl;
        cout << "\t\t\tOpcion a escoger:[1/2/3]" << endl;
        cout << "\t\t\t--------------------------------------------" << endl;
        cout << "\t\t\tIngresa tu Opcion: ";
        cin >> choice;

        switch(choice)
        {
        case 1:
        {
            AsigCursos_Alumnos alumnoA;
            alumnoA.Menu_alumno();
            // Proporcionar argumentos adecuados para el constructor de Login_Alumno

        }
            break;
        case 2:
            // Implementación para la asignación de cursos a maestros
            break;
        case 3:
            break;

        default:
            cout << "\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
            cin.get();
        }
    } while (choice != 3);
}

void reportes()
{
    // Implementación de reportes
}

void ayuda()
{
    // Implementación de ayuda
}

void seguridad()
{
    // Implementación de seguridad

}
