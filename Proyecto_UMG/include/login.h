#ifndef LOGIN_H
#define LOGIN_H

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <conio.h>
#include <iomanip>
#include <ctime>
#include "Bitacora.h"
#include "usuarios.h"
#include <cstring>


using namespace std;


class Login {
private:
    static string usuarioActual;
    string nombre;
    string contra;
    int maxintentos;
    int contintentos;
public:
    Login(string nombre = "", string contra = "",int intentos = 3); // Constructor con valores predeterminados
    void setnombre(string nombre);
    string getnombre() const;
    void setcontra(string contra);
    string getcontra() const;
    bool validacion();
    void resetintentos();
    static string getUsuarioActual() {
    return usuarioActual;
    }



};
