#ifndef PROCEALUMNOS_H
#define PROCEALUMNOS_H

#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<cstdlib>
#include<conio.h>
#include<iomanip>


using namespace std;

class procealumnos
{
    private:
    string dpi, certiestudios, fotoestatica, titulo, fotocedula, copiadpi;

    public:

        procealumnos() {}
        procealumnos(string dpi, string certiestudios, string fotoestatica, string titulo, string fotocedula, string copiadpi);

        string setdpi(string dpi);
        string getdpi();

        string setcertiestudios(string certiestudios);
        string getcertiestudios();

        string setfotoestatica(string fotoestatica);
        string getcfotoestatica();

        string settitulo(string titulo);
        string gettitulo();

        string setfotocedula(string fotocedula);
        string gettfotocedula();

        string setcopiadpi(string copiadpi);
        string getcopiadpi();

    void menu();
    void insertar();

    struct Procealumnos {

    char dpi[20];
    char certiestudios[50];
    char fotoestatica[10];
    char titulo[20];
    char fotocedula[100];
    char copiadpi[50];

};
};

#endif // PROCEALUMNOS_H
