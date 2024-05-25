#include "Portada.h"
#include <iostream>
#include <fstream>
using namespace std;
void Portada::dibujarPortada(const string& nombreArchivo) {
    ifstream archivo(nombreArchivo);
    if (archivo.is_open()) {
        string linea;
        while (getline(archivo, linea)) {
            cout << linea << endl;
        }
        archivo.close();
    } else {
        cout << "No se pudo abrir el archivo de portada." << endl;
    }
}
