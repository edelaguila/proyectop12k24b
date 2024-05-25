// Jonathan Samuel Gonzalez Ixpata.
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <string>
#include <vector>
#include <algorithm>
#include "sueldos.h"
#include "Bitacora.h"

using namespace std;

void sueldos::menu() {
    int choice;
    string codigoPrograma = "6650"; // Código del programa
    Bitacora Auditoria; // Objeto para gestionar la bitácora de auditoría
    string user = "admin"; // Usuario actual del sistema

    do {
        system("cls");
        cout << "\t\t\t-------------------------------" << endl;
        cout << "\t\t\t|    MENU DE SUELDOS          |" << endl;
        cout << "\t\t\t-------------------------------" << endl;
        cout << "\t\t\t 1. Base de datos de empleados" << endl;
        cout << "\t\t\t 2. Generación de nóminas" << endl;
        cout << "\t\t\t 3. Retorno" << endl;
        cout << "\t\t\t-------------------------------" << endl;
        cout << "\t\t\tOpción a escoger:[1/2/3]" << endl;
        cout << "\t\t\t-------------------------------" << endl;
        cout << "\t\t\tIngresa tu Opción: ";
        cin >> choice;

        switch (choice) {
            case 1:
                menuEmpleados(); // Llama a la función para el menú de empleados
                Auditoria.ingresoBitacora(user, codigoPrograma, "MEN"); // Registra en la bitácora la acción de mostrar el menú de empleados
                break;
            case 2:
                generacionNomina(); // Llama a la función para la generación de nómina
                break;
            case 3:
                // Implementa la funcionalidad para "Retorno" aquí si es necesario
                break;
            default:
                cout << "\n\t\t\t Opción inválida... Por favor prueba otra vez..";
                cin.ignore();
                cin.get();
        }
    } while (choice != 3);
}

void sueldos::menuEmpleados() {
    int choice;
    do {
        system("cls");
        cout << "\t\t\t-----------------------------------" << endl;
        cout << "\t\t\t|    BASE DE DATOS DE EMPLEADOS   |" << endl;
        cout << "\t\t\t-----------------------------------" << endl;
        cout << "\t\t\t 1. Agregar empleado" << endl;
        cout << "\t\t\t 2. Eliminar empleado" << endl;
        cout << "\t\t\t 3. Ver información de los empleados" << endl;
        cout << "\t\t\t 4. Retroceder" << endl;
        cout << "\t\t\t-----------------------------------" << endl;
        cout << "\t\t\tOpción a escoger:[1/2/3/4]" << endl;
        cout << "\t\t\t-----------------------------------" << endl;
        cout << "\t\t\tIngresa tu Opción: ";
        cin >> choice;

        switch (choice) {
            case 1:
                agregarEmpleado(); // Llama a la función para agregar un empleado
                break;
            case 2:
                eliminarEmpleado(); // Llama a la función para eliminar un empleado
                break;
            case 3:
                verEmpleados(); // Llama a la función para ver la información de los empleados
                break;
            case 4:
                // Salir del menú de empleados
                break;
            default:
                cout << "\n\t\t\t Opción inválida... Por favor prueba otra vez..";
                cin.ignore();
                cin.get();
        }
    } while (choice != 4);
}

void sueldos::agregarEmpleado() {
    Empleado empleado;
    srand(time(0)); // Inicializar el generador de números aleatorios

    // Generar un código único para el empleado
    int year = 24;
    int numAleatorio = (rand() % 9998) + 1;
    string idString = "9959-" + to_string(year) + "-" + to_string(numAleatorio);

    cout << "\n\t-> Generando código del empleado: " << idString << endl;
    empleado.id = idString;

    cout << "\n\tIngrese el nombre completo del empleado: ";
    cin.ignore();
    getline(cin, empleado.nombre);

    cout << "\tIngrese el email del empleado: ";
    getline(cin, empleado.email);

    int puesto;
    cout << "\tIngrese el puesto del empleado (1. Secretaria, 2. Limpieza, 3. Maestro): ";
    cin >> puesto;

    switch (puesto) {
        case 1:
            empleado.puesto = "Secretaria";
            empleado.salario = 3500;
            break;
        case 2:
            empleado.puesto = "Limpieza";
            empleado.salario = 3400;
            break;
        case 3:
            empleado.puesto = "Maestro";
            empleado.salario = 5000;
            break;
        default:
            cout << "\tPuesto inválido, asignando puesto de Limpieza por defecto.\n";
            empleado.puesto = "Limpieza";
            empleado.salario = 3400;
    }

    cout << "\tIngrese el teléfono del empleado: ";
    cin.ignore();
    getline(cin, empleado.telefono);

    // Guardar la información en un archivo binario
    ofstream file("empleados.dat", ios::binary | ios::app);
    if (file.is_open()) {
        file.write(empleado.id.c_str(), empleado.id.size());
        file.put('\0');
        file.write(empleado.nombre.c_str(), empleado.nombre.size());
        file.put('\0');
        file.write(empleado.email.c_str(), empleado.email.size());
        file.put('\0');
        file.write(empleado.puesto.c_str(), empleado.puesto.size());
        file.put('\0');
        file.write(reinterpret_cast<const char*>(&empleado.salario), sizeof(empleado.salario));
        file.write(empleado.telefono.c_str(), empleado.telefono.size());
        file.put('\0');
        file.close();
    } else {
        cout << "\n\tNo se pudo abrir el archivo de empleados.\n";
    }

    cout << "\n\t¡El empleado ha sido agregado con éxito!\n";
    system("pause");
}

void sueldos::eliminarEmpleado() {
    string codigoEmpleado;
    cout << "\n\tIngrese el código del empleado que desea eliminar: ";
    cin >> codigoEmpleado;

    ifstream archivo("empleados.dat", ios::binary);
    ofstream archivoTmp("empleados_tmp.dat", ios::binary);

    Empleado empleado;
    bool eliminado = false;
    while (archivo) {
        getline(archivo, empleado.id, '\0');
        if (!archivo) break;
        getline(archivo, empleado.nombre, '\0');
        getline(archivo, empleado.email, '\0');
        getline(archivo, empleado.puesto, '\0');
        archivo.read(reinterpret_cast<char*>(&empleado.salario), sizeof(empleado.salario));
        getline(archivo, empleado.telefono, '\0');

        if (empleado.id == codigoEmpleado) {
            eliminado = true;
            // Guardar los datos del empleado eliminado en otro archivo
            ofstream archivoEliminados("empleados_eliminados.dat", ios::binary | ios::app);
            archivoEliminados.write(empleado.id.c_str(), empleado.id.size());
            archivoEliminados.put('\0');
            archivoEliminados.write(empleado.nombre.c_str(), empleado.nombre.size());
            archivoEliminados.put('\0');
            archivoEliminados.write(empleado.email.c_str(), empleado.email.size());
            archivoEliminados.put('\0');
            archivoEliminados.write(empleado.puesto.c_str(), empleado.puesto.size());
            archivoEliminados.put('\0');
            archivoEliminados.write(reinterpret_cast<const char*>(&empleado.salario), sizeof(empleado.salario));
            archivoEliminados.write(empleado.telefono.c_str(), empleado.telefono.size());
            archivoEliminados.put('\0');
            archivoEliminados.close();
        } else {
            archivoTmp.write(empleado.id.c_str(), empleado.id.size());
            archivoTmp.put('\0');
            archivoTmp.write(empleado.nombre.c_str(), empleado.nombre.size());
            archivoTmp.put('\0');
            archivoTmp.write(empleado.email.c_str(), empleado.email.size());
            archivoTmp.put('\0');
            archivoTmp.write(empleado.puesto.c_str(), empleado.puesto.size());
            archivoTmp.put('\0');
            archivoTmp.write(reinterpret_cast<const char*>(&empleado.salario), sizeof(empleado.salario));
            archivoTmp.write(empleado.telefono.c_str(), empleado.telefono.size());
            archivoTmp.put('\0');
        }
    }

    archivo.close();
    archivoTmp.close();

    remove("empleados.dat");
    rename("empleados_tmp.dat", "empleados.dat");

    if (eliminado) {
        cout << "\n\t¡El empleado ha sido eliminado con éxito!\n";
    } else {
        cout << "\n\tNo se encontró un empleado con el código proporcionado.\n";
    }

    system("pause");
}

void sueldos::verEmpleados() {
    ifstream archivo("empleados.dat", ios::binary);
    if (!archivo.is_open()) {
        cout << "\n\tNo se puede abrir el archivo de empleados.\n";
        system("pause");
        return;
    }

    vector<Empleado> empleados;

    while (true) {
        Empleado empleado;

        getline(archivo, empleado.id, '\0');
        if (archivo.eof()) break;
        getline(archivo, empleado.nombre, '\0');
        if (archivo.eof()) break;
        getline(archivo, empleado.email, '\0');
        if (archivo.eof()) break;
        getline(archivo, empleado.puesto, '\0');
        if (archivo.eof()) break;
        archivo.read(reinterpret_cast<char*>(&empleado.salario), sizeof(empleado.salario));
        if (archivo.eof()) break;
        getline(archivo, empleado.telefono, '\0');
        if (archivo.eof()) break;

        empleados.push_back(empleado);
    }

    archivo.close();

    // Ordenar empleados por id
    sort(empleados.begin(), empleados.end(), [](const Empleado& a, const Empleado& b) {
        return a.id < b.id;
    });

    cout << "\n\t-----------------------------\n";
    cout << "\t| INFORMACIÓN DE EMPLEADOS |\n";
    cout << "\t-----------------------------\n";

    for (const auto& empleado : empleados) {
        cout << "\n\tCódigo: " << empleado.id << endl;
        cout << "\tNombre: " << empleado.nombre << endl;
        cout << "\tEmail: " << empleado.email << endl;
        cout << "\tPuesto: " << empleado.puesto << endl;
        cout << "\tSalario: $" << fixed << setprecision(2) << empleado.salario << endl;
        cout << "\tTeléfono: " << empleado.telefono << endl;
        cout << "\t-----------------------------\n";
    }

    cout << "\n\tPresione cualquier tecla para regresar al menú anterior...";
    cin.ignore();
    cin.get();
}


void sueldos::generacionNomina() {
    string id, mesPago;
    Empleado empleado;
    bool empleadoEncontrado = false;

    cout << "\n\tIngrese el ID o carnet del empleado: ";
    cin.ignore();
    getline(cin, id);

    cout << "\tIngrese el mes de pago del empleado: ";
    getline(cin, mesPago);

    // Buscar al empleado en el archivo
    ifstream archivo("empleados.dat", ios::binary);
    if (!archivo.is_open()) {
        cout << "\n\tNo se puede abrir el archivo de empleados.\n";
        system("pause");
        return;
    }

    while (true) {
        getline(archivo, empleado.id, '\0');
        if (archivo.eof()) break;
        getline(archivo, empleado.nombre, '\0');
        if (archivo.eof()) break;
        getline(archivo, empleado.email, '\0');
        if (archivo.eof()) break;
        getline(archivo, empleado.puesto, '\0');
        if (archivo.eof()) break;
        archivo.read(reinterpret_cast<char*>(&empleado.salario), sizeof(empleado.salario));
        if (archivo.eof()) break;
        getline(archivo, empleado.telefono, '\0');
        if (archivo.eof()) break;

        if (empleado.id == id) {
            empleadoEncontrado = true;
            break;
        }
    }
    archivo.close();

    if (!empleadoEncontrado) {
        cout << "\n\tEmpleado no encontrado.\n";
        system("pause");
        return;
    }

    double salario = empleado.salario;

    // Calcular las deducciones
    double deduccionIGGS = salario * 0.055;
    double deduccionISR = salario * 0.0483;
    double deduccionIRTRA = salario * 0.01;
    double totalDeducciones = deduccionIGGS + deduccionISR + deduccionIRTRA;

    // Calcular las bonificaciones
    double bonificacionIncentivo = 250.0;
    double bonificacionExtra = 0.0;

    if (mesPago == "julio") {
        bonificacionExtra = salario; // Bono 14
    } else if (mesPago == "diciembre") {
        bonificacionExtra = salario; // Aguinaldo
    }

    // Calcular el salario neto
    double salarioNeto = salario - totalDeducciones + bonificacionIncentivo + bonificacionExtra;

    // Mostrar los resultados en una tabla
    cout << fixed << setprecision(2); // Establecer la precisión a dos decimales
    cout << "\n-------------------Detalle de Nómina-------------------\n";
    cout << "Empleado: " << empleado.nombre << endl;
    cout << "ID: " << empleado.id << endl;
    cout << "Sueldo Bruto: Q" << salario << endl;
    cout << "--------------------------------------------------------\n";
    cout << "Deducciones:\n";
    cout << "IGSS (5.5%): Q" << deduccionIGGS << endl;
    cout << "ISR (4.83%): Q" << deduccionISR << endl;
    cout << "IRTRA (1%): Q" << deduccionIRTRA << endl;
    cout << "Total Deducciones: Q" << totalDeducciones << endl;
    cout << "--------------------------------------------------------\n";
    cout << "Bonificaciones:\n";
    cout << "Bonificación Incentivo: Q" << bonificacionIncentivo << endl;
    if (bonificacionExtra > 0) {
        cout << "Bonificación Extra: Q" << bonificacionExtra << " (" << (mesPago == "julio" ? "Bono 14" : "Aguinaldo") << ")" << endl;
    }
    cout << "--------------------------------------------------------\n";
    cout << "Sueldo Neto: Q" << salarioNeto << endl;
    cout << "--------------------------------------------------------\n";

    cout << "\n\t¡La nómina ha sido generada con éxito!\n";
    system("pause");
}
