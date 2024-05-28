//Creado por Jonathan Samuel Gonzalez Ixpata
#ifndef SUELDOS_H
#define SUELDOS_H

#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

class sueldos {
public:
    void menu(); // Menú principal de sueldos
    void menuEmpleados(); // Menú de gestión de empleados

private:
    struct Empleado {
        string id;
        string nombre;
        string email;
        string puesto;
        double salario;
        string telefono;
    };

    void agregarEmpleado(); // Función para agregar un empleado
    void eliminarEmpleado(); // Función para eliminar un empleado
    void verEmpleados(); // Función para ver la información de los empleados
    void generacionNomina(); // Función para la generación de nómina
};

#endif // SUELDOS_H
