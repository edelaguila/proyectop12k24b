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

struct horarios {
char id [11];
char Sede [11];
char Horario [11];
};

void Horarios::menu() {
    int choice;
    char x;

    do {
        system("cls");
        cout << "\t\t\t-----------------------------------------"<<endl;
        cout << "\t\t\t|   SISTEMA DE GESTION HORARIOS -  6200  |"<<endl;
        cout << "\t\t\t-----------------------------------------"<<endl;
        cout << "\t\t\t 1. Agregar Horario"<<endl;
        cout << "\t\t\t 2. Despliegue Horarios"<<endl;
        cout << "\t\t\t 3. Modificar Horario"<<endl;
        cout << "\t\t\t 4. Borrar Horario"<<endl;
        cout << "\t\t\t 5. Retornar menu anterior"<<endl;
        cout << "\t\t\t-----------------------------------------"<<endl;
        cout << "\t\t\t Opcion a escoger:[1/2/3/4/5]"<<endl;
        cout << "\t\t\t-----------------------------------------"<<endl;
        cout << "\t\t\t Ingresa tu Opcion: ";
        cin >> choice;

        switch(choice) {
        case 1:
            do {
                insertar();
                cout << "\n\t\t\t Agregar otro Horario(Y,N): ";
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
    Horarios horarios;
    ofstream file("Horarios.dat", ios::binary | ios::app);


    if (!file) {
        cerr << "No se pudo abrir el archivo." << endl;
        return;
    }


    cout << "\n--------------------------------------------------------------------------------------------------------------------";
    cout << "\n-------------------------------------------------Agregar Horario-------------------------------------------------------" << endl;
    cout << "\t\t\tIngrese id del Horario: ";
    cin.ignore();
    cin.getline(horario.id, sizeof(horario.id));
    cout << "\t\t\tIngrese nombre de la Sede   : ";
    cin.getline(horario.nombre, sizeof(horario.nombre));
    cout << "\t\t\tIngrese Horario : ";
    cin.getline(horario.Horario, sizeof(horario.Horario));
    file.write(reinterpret_cast<const char*>(&horario), sizeof(horario));
    file.close();
    string codigoPrograma="6200";
    Bitacora Auditoria;
    string user;
    Auditoria.ingresoBitacora(user,codigoPrograma,"INS");
}


void Horarios::desplegar() {
    system("cls");
    ifstream file("Horarios.dat", ios::binary);


    if (!file) {
        cerr << "No se pudo abrir el archivo." << endl;
        return;
    }

    int total = 0;


    cout << "\n-----------------------------------------Tabla Detalles de Horarios ----------------------------------------------" << endl;
    Horarios horarios;
    while (file.read(reinterpret_cast<char*>(&horario), sizeof(horario))) {
        cout << "\t\t\t ID del Horario    : " << horario.id << endl;
        cout << "\t\t\t Nombre de la Sede : " << horario.nombre << endl;
        cout << "\t\t\t Horario de la Sede: " << horario.Horario << endl;
        cout << "-----------------------------------------------------------------------------------------------------------------" << endl;
        total++;
    }

    if (total == 0) {
        cout << "\n\t\t\tNo hay informacion..." << endl;
    }

    file.close();
    cin.ignore();
    system("pause");
    string codigoPrograma="6200";
    Bitacora Auditoria;
    string user;
    Auditoria.ingresoBitacora(user,codigoPrograma,"CON");
}


void Horarios::modificar() {
    system("cls");
    fstream file("Horarios.dat", ios::in | ios::out | ios::binary);


    if (!file) {
        cout << "\n\t\t\tNo hay información...";
        return;
    }

    string id_modificar;
    int found = 0;

    cout << "\n-------------------------------------Modificar Detalles del Horario----------------------------------------------" << endl;
    cout << "\t\t\tIngrese ID del Horario que desea modificar: ";
    cin >> id_modificar;

    Horarios horarios;
    ofstream file1("temporal.dat", ios::binary);


    if (!file1) {
        cout << "\n\t\t\tError al abrir el archivo temporal...";
        return;
    }


    while (file.read(reinterpret_cast<char*>(&horario), sizeof(Horario))) {
        if (strcmp(horario.id, id_modificar.c_str()) == 0) {
            cout << "\t\t\tIngrese nuevo ID del Horario: ";
            cin >> horario.id;
            cout << "\t\t\tIngrese nuevo nombre de la Sede: ";
            cin.ignore();
            cin.getline(horario.nombre, sizeof(horario.nombre));
            cout << "\t\t\tIngrese el nuevo Horario: ";
            cin.getline(horario.Horario, sizeof(horario.Horario));

            file1.write(reinterpret_cast<const char*>(&horario), sizeof(Horario));

            cout << "\n\t\t\t Horario modificad correctamente!!!" << endl;
            found++;
        } else {
            file1.write(reinterpret_cast<const char*>(&horario), sizeof(Horario));
        }
    }

    if (!found) {
        cout << "\n\t\t\tNo se encontro algun Horario con el ID proporcionado." << endl;
    }

    file.close();
    file1.close();
    remove("Horarios.dat");
    rename("temporal.dat", "Horarios.dat");
    cin.ignore();
    system("pause");
    string codigoPrograma="6200";
    Bitacora Auditoria;
    string user;
    Auditoria.ingresoBitacora(user,codigoPrograma,"ACT");
}


void Horarios::borrar() {
    system("cls");
    string id_borrar;
    int found = 0;

    cout << "\n------------------------------------------Detalles Horario a Borrar-----------------------------------------------" << endl;

    ifstream file("Horarios.dat", ios::binary);


    if (!file) {
        cout << "\n\t\t\tNo hay informacion...";
        return;
    }

    ofstream file1("temporal.dat", ios::binary);


    if (!file1) {
        cout << "\n\t\t\tError al abrir el archivo temporal...";
        return;
    }

    cout << "\n-----------------------------------------Sistema Busqueda de Horarios---------------------------------------------" << endl;
    cout << "\n\t\t Ingrese Id del Horario que quiere Borrar: ";
    cin >> id_borrar;

    Horario horario;
    while (file.read(reinterpret_cast<char*>(&horario), sizeof(Horario))) {
        if (strcmp(horario.id, id_borrar.c_str()) == 0) {
            cout << "\n\t\t\tBorrado de informacion exitoso!!!!" << "\n" << endl;
            found++;
        } else {
            file1.write(reinterpret_cast<const char*>(&horario), sizeof(Horario));
        }
    }

    if (found == 0) {
        cout << "\n\t\t\tId de Horario no encontrado...." << "\n" << endl;
    }

    file1.close();
    file.close();

    remove("Horarios.dat");
    rename("temporal.dat", "Horarios.dat");

    cin.ignore();
    system("pause");
    string codigoPrograma="6200";
    Bitacora Auditoria;
    string user;
    Auditoria.ingresoBitacora(user,codigoPrograma,"DEL");
}
