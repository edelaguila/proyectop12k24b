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
public:
    Login(string nombre = "", string contra = ""); // Constructor con valores predeterminados
    void setnombre(string nombre);
    string getnombre() const;
    void setcontra(string contra);
    string getcontra() const;
    bool validacion();
    static string getUsuarioActual() {
    return usuarioActual;
    }



};

#endif // LOGIN_H
