#ifndef BITACORA_H
#define BITACORA_H

#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include "usuarios.h"
#include <cstring>


using namespace std;

struct RegistroBitacora {

    char accion[80];
    char aplicacion[80];
    char nombre[80];
    char fechaHora[80];
};


class Bitacora {
public:
    void ingresoBitacora(const string& usuario, const string& codigoPrograma, const string& tipoIngreso);
    void mostrarBitacora();
};
#endif // BITACORA_H
