//Creado por Anderson Rodriguez 9959-23-495
#ifndef MATRICULA_H
#define MATRICULA_H
#include<iostream>

using namespace std;

class matricula
{
    private:
		//int choice;
		//string facultad, nombre, apellido1, apellido2, fechaNacimiento, direccion, fecha, telefono, DPI, correo, numeroBoleta;
		//double monto;
	public:
	    char x;
	    int choice;
	    //string carnet;
	    string facultad, nombre, apellido1, apellido2, fechaNacimiento, direccion, fecha, telefono, DPI, correo, numeroBoleta;
		double monto;
		string numTarjeta, fExpiracion, codSeguridad;
		void menu();
		void insertar();
		void desplegar();
		void modificar();
		void borrar();

		//void datosEstudiante();
		string generarNumeroCarnet();
		int generarNumeroAleatorio();
		string generarCorreoInstitucional(string nombre, string apellido1, string apellido2);
		string generarNumeroBoleta();
		void pagarEnLinea();

		struct Alumno {

		    char id[20];
		    char nombre[50];
		    char Genero[10];
		    char DPI[20];
		    char direccion[100];
		    char nacionalidad[50];
		    char telefono[15];
		    char civil[20];
		    char fechanaci[20];
		    char anoingre[10];
		};


};

#endif // MATRICULA_H
