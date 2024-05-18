#ifndef SUELDOS_H
#define SUELDOS_H

#include <string>
using namespace std;

// Definici�n de la estructura para almacenar los datos de los empleados
struct Empleado {
    string nombre;
    string puesto;
    float salario;
};

// Definici�n de la clase sueldos con sus m�todos
class sueldos {
public:
    void crudsueldo();
    void menuEmpleados();// nuevo metodo menu empleados
    void agregarEmpleado();// nuevo metodo para agregar empleados
    void eliminarEmpleado(); //nuevo metodo para eliminar empleados
    void verEmpleados();
    void procesoAsignacionMaestros();
    void generacionNomina(); // Nuevo m�todo para la generaci�n de n�mina
};

#endif // SUELDOS_H
