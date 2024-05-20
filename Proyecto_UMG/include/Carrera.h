// archivo de encabezado de la clase CARRERA
//contiene definiciones de funciones, definiciones de clases
#ifndef CARRERA_H
#define CARRERA_H
#include<stdlib.h>
#include<cstdlib>
#include<conio.h>
#include<iomanip>

using namespace std;
<<<<<<< HEAD

=======
//Elaborado por : Daniel Antonio Chacón Morataya  9959-22-1827
>>>>>>> 7fee22e7c1a780459548acc106d5712411a3308b
struct Carrera {
    int codigo;
    char nombre[50];
    char facultad[50];
};
class CarrerasCRUD {
public:
    void IngresarCa();
    void ModificarCa();
    void BorrarCa();
    void DesplegarCa();
    void Crudcarrera();

};

#endif // CARRERA_H

// Usamos archivos de encabezado para tener un orden y mas limpio nuestro codigo y facil de encontrar errores
<<<<<<< HEAD
=======

>>>>>>> 7fee22e7c1a780459548acc106d5712411a3308b
