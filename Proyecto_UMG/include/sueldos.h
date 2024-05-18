#ifndef SUELDOS_H
#define SUELDOS_H

#include <string>
using namespace std;

// Definición de la estructura para almacenar los datos de los empleados
struct Empleado {
    string nombre;
    string puesto;
    float salario;
};

// Definición de la clase sueldos con sus métodos
class sueldos {
public:
    void crudsueldo();
    void menuEmpleados();
    void agregarEmpleado();// nuevo metodo para agregar empleados
    void eliminarEmpleado();
    void verEmpleados();
    void procesoAsignacionMaestros();
    void generacionNomina(); // Nuevo método para la generación de nómina
};

#endif // SUELDOS_H
