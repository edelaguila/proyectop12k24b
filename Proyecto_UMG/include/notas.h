//Mishelloeiza //9959/23/3457
//creaciòn
//reconstruccion

// notas.h

#ifndef NOTAS_H
#define NOTAS_H

#include <fstream> // Para manejar archivos
#include <iostream> // Para entrada y salida estándar
#include <string> // Para manejar cadenas de texto

using namespace std;

// Definición de la estructura para almacenar notas
struct notas {00
    int codigoEstudiante;
    char nombreEstudiante[50];
    char nombreCurso[50];
    float np1, np2, za, ef, nf; // Notas parciales y nota final
};

// Clase para manejar las operaciones CRUD en las notas
class NotaCrud {
public:
    void CrudNota();
    void IngresarNota();
    void ModificarNota();
    void BorrarNota();
    void DesplegarNotas();
    bool validarAlumno(int codigoEstudiante);
   };

#endif // NOTAS_H