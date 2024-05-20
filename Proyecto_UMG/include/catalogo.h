#ifndef CATALOGO_H
#define CATALOGO_H
#include<fstream>
#include<stdlib.h>
#include<cstdlib>
#include<conio.h>
#include<iomanip>
#include"alumnos.h"
using namespace std;

class catalogo
{
    public:
        catalogo(string curso, string curso2);


        string setCurso(string curso);
        string getCurso();

        string setCurso2(string curso2);
        string getCurso2();
//metodos


        void insertar();
		void catalogoCursos(string CursosD);
		void desplegar();

    protected:

    private:
    string curso, curso2;
};
#endif // catalogo.h
