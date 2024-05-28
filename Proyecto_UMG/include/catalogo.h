<<<<<<< HEAD
// encabezado catalogo
=======
>>>>>>> 1a8b285e44e22ebebc8e610ca110e2ec22da6084
#ifndef CATALOGO_H
#define CATALOGO_H
#include<fstream>
#include<stdlib.h>
#include<cstdlib>
#include<conio.h>
#include<iomanip>
#include"alumnos.h"
using namespace std;
<<<<<<< HEAD
// creando clase
=======

>>>>>>> 1a8b285e44e22ebebc8e610ca110e2ec22da6084
class catalogo
{
    public:
        catalogo(string curso, string curso2);


        string setCurso(string curso);
        string getCurso();

        string setCurso2(string curso2);
        string getCurso2();
<<<<<<< HEAD
//metodos que realizara la clase


        void insertar(const char* carnet);
		void catalogoCursos(string CursosD);
		void desplegar();
		void desplegarcursosalumno(string carnet);
=======
//metodos


        void insertar();
		void catalogoCursos(string CursosD);
		void desplegar();
>>>>>>> 1a8b285e44e22ebebc8e610ca110e2ec22da6084

    protected:

    private:
    string curso, curso2;
};
#endif // catalogo.h
