//Creado por Daniel Reyna Lopez 9959-23-5291

#include "Horarios.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <iomanip>
#include <sstream>
#include <cstring>
#include "Bitacora.h"

using namespace std;

void Horarios::menu() {
    int choice;
    char x;

    do {
        system("cls");
        cout << "\t\t\t-----------------------------------------"<<endl;
        cout << "\t\t\t|   SISTEMA DE GESTION Horarios -  6200  |"<<endl;
        cout << "\t\t\t-----------------------------------------"<<endl;
        cout << "\t\t\t 1. Ingreso Horario"<<endl;
        cout << "\t\t\t 2. Despliegue Horarios"<<endl;
        cout << "\t\t\t 3. Modifica Horarios"<<endl;
        cout << "\t\t\t 4. Borra Horario"<<endl;
        cout << "\t\t\t 5. Retornar menu anterior"<<endl;
        cout << "\t\t\t-----------------------------------------"<<endl;
        cout << "\t\t\tOpcion a escoger:[1/2/3/4/5]"<<endl;
        cout << "\t\t\t-----------------------------------------"<<endl;
        cout << "\t\t\tIngresa tu Opcion: ";
        cin >> choice;

        switch(choice) {
        case 1:
            do {
                insertar();
                cout << "\n\t\t\t Agrega otro Horario(Y,N): ";
                cin >> x;
            } while(x == 'y' || x == 'Y');
            break;
        case 2:
            desplegar();
            break;
        case 3:
            modificar();
            break;
        case 4:
            borrar();
            break;
        case 5:
            return;
        default:
            cout << "\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
            cin.get();
        }
    } while(choice != 5);
}

void Horarios::insertar() {
    system("cls");
    ofstream file("Horarios.dat", ios::binary | ios::app);

    if (!file) {
        cerr << "No se pudo abrir el archivo." << endl;
        return;
    }

    cout << "\n--------------------------------------------------------------------------------------------------------------------";
    cout << "\n-------------------------------------------------Agregar Horario-------------------------------------------------------" << endl;
    cout << "\t\t\tIngrese id del Horario       : ";
    cin.ignore();
    cin.getline(horario.id, sizeof(horario.id));
    file.write(reinterpret_cast<const char*>(&horario), sizeof(Horario));
    file.close();
    string codigoPrograma="6200";
    Bitacora Auditoria;
    string user;
    Auditoria.ingresoBitacora(user, codigoPrograma, "INS");
}

void Horarios::desplegar() {
    system("cls");
    ifstream file("Horarios.dat", ios::binary);

    if (!file) {
        cerr << "No se pudo abrir el archivo." << endl;
        return;
    }

    int total = 0;
    cout << "\n-----------------------------------------Tabla Detallada de Horarios---------------------------------------------------"<<endl;
    cout << "---------------------------------------------------------------------------------------------------------------"<<endl;
    cout << left << setw(10) << "ID";
    cout << "\n";
    cout << "---------------------------------------------------------------------------------------------------------------"<<endl;

    while (file.read(reinterpret_cast<char*>(&horario), sizeof(Horario))) {
        cout << left << setw(10) << horario.id;
        cout << "\n";
        total++;
    }

    if (total == 0) {
        cout << "\n\t\t\t No hay Horarios registrados...";
    }
    file.close();
}

void Horarios::modificar() {
    system("cls");
    fstream file("Horarios.dat", ios::binary | ios::in | ios::out);

    if (!file) {
        cerr << "No se pudo abrir el archivo." << endl;
        return;
    }

    char id[11];
    cout << "\n-------------------------------------------------------------------------------------------------------";
    cout << "\n---------------------------------Modificar Horario---------------------------------------------------"<<endl;
    cout << "\t\t\tIngrese id del Horario : ";
    cin.ignore();
    cin.getline(id, sizeof(id));

    bool found = false;
    while (file.read(reinterpret_cast<char*>(&horario), sizeof(Horario))) {
        if (strcmp(horario.id, id) == 0) {
            cout << "\t\t\tIngrese nuevo id del Horario: ";
            cin.getline(horario.id, sizeof(horario.id));
            file.seekp(-static_cast<int>(sizeof(Horario)), ios::cur);
            file.write(reinterpret_cast<const char*>(&horario), sizeof(Horario));
            found = true;
            string codigoPrograma="6200";
            Bitacora Auditoria;
            string user;
            Auditoria.ingresoBitacora(user, codigoPrograma, "UPD");
            break;
        }
    }

    if (!found) {
        cout << "\n\t\t\t Horario no encontrado...";
    }

    file.close();
}

void Horarios::borrar() {
    system("cls");
    ifstream inFile("Horarios.dat", ios::binary);
    ofstream outFile("Temp.dat", ios::binary);

    if (!inFile || !outFile) {
        cerr << "No se pudo abrir el archivo." << endl;
        return;
    }

    char id[11];
    cout << "\n-------------------------------------------------------------------------------------------------------";
    cout << "\n---------------------------------Borrar Horario--------------------------------------------------------"<<endl;
    cout << "\t\t\tIngrese id del Horario: ";
    cin.ignore();
    cin.getline(id, sizeof(id));

    bool found = false;
    while (inFile.read(reinterpret_cast<char*>(&horario), sizeof(Horario))) {
        if (strcmp(horario.id, id) != 0) {
            outFile.write(reinterpret_cast<const char*>(&horario), sizeof(Horario));
        } else {
            found = true;
            string codigoPrograma="6200";
            Bitacora Auditoria;
            string user;
            Auditoria.ingresoBitacora(user, codigoPrograma, "DEL");
        }
    }

    inFile.close();
    outFile.close();
    remove("Horarios.dat");
    rename("Temp.dat", "Horarios.dat");

    if (found) {
        cout << "\n\t\t\t Horario borrado exitosamente.";
    } else {
        cout << "\n\t\t\t Horario no encontrado...";
    }
}
