//By Ruddyard Eduardo Castro Chavez

#ifndef MENUINGRESOMAESTRO_H
#define MENUINGRESOMAESTRO_H


#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<cstdlib>
#include<conio.h>
#include<iomanip>



using namespace std;

class menuIngresoMaestro
{
    public:
          bool VerificarCarnet();
    Login(string usuarios);

        string setUser(string usuarios);
        string getUser();




    private:
            string usuarios;
};

#endif // MENUINGRESOMAESTRO_H
