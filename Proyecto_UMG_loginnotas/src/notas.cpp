#include "notas.h" // Inclusion del archivo de cabecera para las definiciones relacionadas con las notas
#include "Bitacora.h" // Inclusion del archivo de cabecera para las definiciones relacionadas con la bitacora
#include <fstream> // Inclusion de la biblioteca estandar de manejo de archivos
#include <iostream> // Inclusion de la biblioteca estandar de entrada/salida
#include <cstdlib> // Inclusion de la biblioteca estandar para funciones de utilidad
#include <conio.h> // Inclusion de la biblioteca para funciones de entrada y salida en consola
#include <cstdio> // para getchart ()
using namespace std; // Uso del espacio de nombres estandar

// creado y Burificado por Diana Mishel Loeiza Ramìrez 9959/23/3457
// funcionalidad al 100%
// Definicion de la funcion para realizar operaciones CRUD en las notas

void NotaCrud::CrudNota() {
    string codigoPrograma = "5020"; // Codigo del programa
    Bitacora Auditoria; // Objeto para gestionar la bitacora de auditoria
    string user = "admin"; // Usuario actual del sistema

    int opcion; // Variable para almacenar la opcion seleccionada por el usuario

    // Menu principal de operaciones CRUD
    do {
        system("cls"); // Limpia la pantalla
        // Mostrar opciones disponibles
        cout << "\t\t\t--------------------------------------------" << endl;
        cout << "\t\t\t|     SISTEMA DE GESTION UMG - Notas       |" << endl;
        cout << "\t\t\t--------------------------------------------" << endl;
        cout << "\t\t\t 1. Ingresar Nota" << endl;
        cout << "\t\t\t 2. Modificar Nota" << endl;
        cout << "\t\t\t 3. Borrar Nota" << endl;
        cout << "\t\t\t 4. Desplegar Notas" << endl;
        cout << "\t\t\t 5. Regresar al Menu Anterior" << endl;
        cout << "\t\t\t --------------------------------------------" << endl;
        cout << "\t\t\t |   Opcion a escoger:[1|2|3|4|5|]           |" << endl;
        cout << "\t\t\t --------------------------------------------" << endl;
        cout << "\t\t\tIngrese tu Opcion: ";

        cin >> opcion; // Leer la opcion seleccionada por el usuario

        // Realizar la operacion correspondiente segun la opcion seleccionada
        switch (opcion) {
            case 1:
                IngresarNota(); // Llama a la funcion para ingresar una nota
                Auditoria.ingresoBitacora(user, codigoPrograma, "CNO"); // Registra en la bitacora la accion de creacion de nota
                break;
            case 2:
                ModificarNota(); // Llama a la funcion para modificar una nota
                Auditoria.ingresoBitacora(user, codigoPrograma, "UNO"); // Registra en la bitacora la accion de modificacion de nota
                break;
            case 3:
                BorrarNota(); // Llama a la funcion para borrar una nota
                Auditoria.ingresoBitacora(user, codigoPrograma, "DNO"); // Registra en la bitacora la accion de eliminacion de nota
                break;
            case 4:
                DesplegarNotas(); // Llama a la funcion para desplegar todas las notas
                Auditoria.ingresoBitacora(user, codigoPrograma, "RNO"); // Registra en la bitacora la accion de lectura de notas
                break;
            case 5:
                break; // Salir del bucle y regresar al menu anterior
            default:
                cout << "\n\t\t\tOpcion invalida. Por favor, prueba otra vez." << endl; // Mensaje de opcion invalida
                cin.ignore(); // Ignorar cualquier entrada no valida
                cin.get(); // Esperar a que el usuario presione Enter para continuar
        }
    } while (opcion != 5); // Repetir el bucle hasta que el usuario elija salir
}

// Funcion para ingresar una nueva nota al sistema
void NotaCrud::IngresarNota() {
    system("cls"); // Limpiar la pantalla
    // imprime
    cout << "\n------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "\n-------------------------------------------------Agregar Nota--------------------------------------------" << endl;
    notas nota; // Declarar una variable para almacenar la nueva nota
    cout << "Ingrese el codigo del estudiante: ";
    cin >> nota.codigoEstudiante; // Leer el codigo del estudiante
    cin.ignore(); // Limpiar el buffer de entrada


    cout << "Ingrese el nombre del estudiante: ";
    cin.getline(nota.nombreEstudiante,50); // Leer el nombre del estudiante

    cout << "Ingrese el nombre del curso: ";
    cin.getline(nota.nombreCurso,50); // Leer el nombre del curso

   // Pedir las notas parciales
    cout << "Ingrese la nota de np1: "; //nota Parcial 1
    cin >> nota.np1;
    cout << "Ingrese la nota de np2: "; //nota Parcial 2
    cin >> nota.np2;
    cout << "Ingrese la nota de za: "; //zona actividades
    cin >> nota.za;
    cout << "Ingrese la nota de ef: ";//ingreso nota final
    cin >> nota.ef;

    // Calcular la nota final (NF)
    nota.nf = nota.np1 + nota.np2 + nota.za + nota.ef;

    ofstream archivo("notas.dat", ios::binary | ios::app); // Abrir el archivo para escribir en modo binario, en modo de añadir al final
    archivo.write(reinterpret_cast<const char*>(&nota), sizeof(notas)); // Escribir la nota en el archivo
    archivo.close(); // Cerrar el archivo

    cout << "Nota agregada exitosamente!" << endl; // Mensaje de exito
    system("pause"); // Pausa el programa hasta que el usuario presione una tecla para continuar

}

void NotaCrud::ModificarNota() {
    int codigo;
    cout << "Ingrese el codigo del estudiante cuya nota desea modificar: ";
    cin >> codigo; // Leer el codigo del estudiante

    fstream archivo("notas.dat", ios::binary | ios::in | ios::out); // Abrir el archivo para lectura y escritura en modo binario
    if (!archivo) { // Si no se pudo abrir el archivo
        cout << "No hay notas registradas." << endl; // Mensaje de error
        return; // Salir de la funcion
    }

    notas nota; // Declarar una variable para almacenar la nota actual
    bool encontrada = false; // Bandera para indicar si se encontro la nota
    while (archivo.read(reinterpret_cast<char*>(&nota), sizeof(notas))) { // Leer cada registro de nota del archivo
        if (nota.codigoEstudiante == codigo) { // Si se encuentra la nota con el codigo ingresado
            encontrada = true; // Actualizar la bandera indicando que se encontro la nota

            int opcion;
            do {
                system("cls"); // Limpiar la pantalla
                cout << "Seleccione la nota que desea modificar:" << endl;
                cout << "1. np1" << endl;
                cout << "2. np2" << endl;
                cout << "3. za" << endl;
                cout << "4. ef" << endl;
                cout << "5. Cancelar" << endl;
                cout << "Ingrese su opcion: ";
                cin >> opcion;

                switch (opcion) {
                    cout << "Ingrese la nueva nota np1: ";
                        cin >> nota.np1;

                            break;
                    case 2:
                        cout << "Ingrese la nueva nota np2: ";
                        cin >> nota.np2;
                        break;
                    case 3:
                        cout << "Ingrese la nueva nota za: ";
                        cin >> nota.za;
                        break;
                    case 4:
                        cout << "Ingrese la nueva nota ef: ";
                        cin >> nota.ef;
                        break;
                    case 5:
                        cout << "Modificación cancelada." << endl;
                        break;
                    default:
                        cout << "Opción no válida. Intente de nuevo." << endl;
                }
            } while (opcion < 1 || opcion > 5);
            // Calcular la nota final (NF)
            nota.nf = nota.np1 + nota.np2 + nota.za + nota.ef;
            archivo.seekp(-static_cast<int>(sizeof(notas)), ios::cur); // Mover el puntero de escritura una posicion antes del registro actual
            archivo.write(reinterpret_cast<const char*>(&nota), sizeof(notas)); // Sobrescribir el registro actual con la nueva nota
            break; // Salir del bucle después de modificar la nota
        }
    }

    archivo.close(); // Cerrar el archivo

    if (!encontrada) { // Si la nota no se encontro
        cout << "No se encontro la nota del estudiante con el codigo ingresado." << endl; // Mensaje de error
    } else {
        cout << "Nota modificada exitosamente!" << endl; // Mensaje de exito
        system("pause"); // Pausa el programa hasta que el usuario presione una tecla para continuar

    }
}


// Funcion para borrar la nota de un estudiante
void NotaCrud::BorrarNota() {
    int codigo; // Variable para almacenar el codigo del estudiante cuya nota se desea eliminar
    cout << "Ingrese el codigo del estudiante cuya nota desea eliminar: ";
    cin >> codigo; // Leer el codigo del estudiante

    ifstream archivo("notas.dat", ios::binary); // Abrir el archivo para lectura en modo binario
    if (!archivo) { // Si no se pudo abrir el archivo
        cout << "No hay notas registradas." << endl; // Mensaje de error
        return; // Salir de la funcion
    }

    ofstream archivoTmp("notas_tmp.dat", ios::binary); // Abrir un archivo temporal para escribir en modo binario
    notas nota; // Declarar una variable para almacenar la nota actual

    bool eliminada = false; // Bandera para indicar si se elimino la nota

    while (archivo.read(reinterpret_cast<char*>(&nota), sizeof(notas))) { // Leer cada registro de nota del archivo
        if (nota.codigoEstudiante != codigo) { // Si el codigo del estudiante no coincide con el codigo ingresado
            archivoTmp.write(reinterpret_cast<const char*>(&nota), sizeof(notas)); // Escribir la nota en el archivo temporal
        } else {
            eliminada = true; // Actualizar la bandera indicando que se elimino la nota
        }
    }

    archivo.close(); // Cerrar el archivo original
    archivoTmp.close(); // Cerrar el archivo temporal

    remove("notas.dat"); // Eliminar el archivo original
    rename("notas_tmp.dat", "notas.dat"); // Renombrar el archivo temporal como el archivo original

    if (eliminada) { // Si la nota fue eliminada
        cout << "Nota eliminada exitosamente!" << endl; // Mensaje de exito
       cout << "Presione Enter para continuar...";
        cin.ignore(); // Limpiar el buffer de entrada
        cin.get(); // Esperar a que el usuario presione Enter para continuar
    } else {
        cout << "No se encontro la nota del estudiante con el codigo ingresado." << endl; // Mensaje de error
        system("pause"); // Pausa el programa hasta que el usuario presione una tecla para continuar

    }
}

// Funcion para desplegar todas las notas registradas en el sistema
void NotaCrud::DesplegarNotas() {
    system("cls"); // Limpiar la pantalla
    cout << "-----------------Despliegue de notas registradas---------------------" << endl; // Encabezado
    ifstream archivo("notas.dat", ios::binary); // Abrir el archivo para lectura en modo binario
    if (!archivo) { // Si no se pudo abrir el archivo
        cout << "No hay notas registradas." << endl; // Mensaje de error
        return; // Salir de la funcion
    }
    notas nota; // Declarar una variable para almacenar la nota actual
    while (archivo.read(reinterpret_cast<char*>(&nota), sizeof(notas))) { // Leer cada registro de nota del archivo
        // Mostrar los detalles de la nota
        cout << "Codigo del estudiante: " << nota.codigoEstudiante << endl;
        cout << "Nombre del estudiante: " << nota.nombreEstudiante << endl;
        cout << "Nombre del curso: " << nota.nombreCurso << endl;
        cout << "Nota final: " << nota.nf << endl; // Mostrar la nota final (NF)
        cout << "-----------------------------" << endl; // Separador entre notas
    }

    archivo.close(); // Cerrar el archivo

    cout << "Presione Enter para continuar..."; // Mensaje para el usuario
    cin.ignore(); // Ignorar cualquier entrada adicional
    cin.get(); // Esperar a que el usuario presione Enter para continuar
}
