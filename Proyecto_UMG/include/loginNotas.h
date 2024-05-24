#ifndef LOGINNOTAS_H
#define LOGINNOTAS_H
// Incluye la biblioteca iostream que permite la entrada y salida de datos
#include<iostream>
// Incluye la biblioteca fstream que permite la lectura y escritura de archivos
#include<fstream>
// Incluye la biblioteca string que permite el uso de cadenas de texto
#include<string>

// Utiliza el espacio de nombres estándar. Esto evita tener que escribir std:: antes de cada uso de objetos de la biblioteca estándar
using namespace std;

// Define una clase llamada loginNotas
class loginNotas
{
 public:
    // Declara una función miembro llamada menuGeneralNotas que no devuelve ningún valor (void)
    void menuGeneralNotas();
    // Declara una función miembro llamada menuGeneralNotasAlumno que no devuelve ningún valor (void)
    void menuGeneralNotasAlumno();
    // Declara una función miembro llamada menuGeneralNotasMaestro que no devuelve ningún valor (void)
    void menuGeneralNotasMaestro();
};


#endif // LOGINNOTAS_H
