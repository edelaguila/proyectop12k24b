#ifndef SEDES_H
#define SEDES_H
#include <iostream>

using namespace std;

class Sedes
{
    private:
        char id[10];
        char nombre[50];
        char telefono[20];
	public:
		void menu();
		void insertar();
		void desplegar();
		void modificar();
		void buscar();
		void borrar();
};

#endif // SEDES_H
