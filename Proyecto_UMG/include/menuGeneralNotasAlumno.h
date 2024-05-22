#ifndef MENUGENERALNOTASALUMNO_H
#define MENUGENERALNOTASALUMNO_H

#include<iostream>
#include<fstream>
#include<string>

using namespace std;


class menuGeneralNotasAlumno
{
    public:
     loginAlumno(string carnet);

        string setcarnet(string carnet);
        string getcarnet();



        bool verificarCarnet();


    private:
        string carnet;

};

#endif // MENUGENERALNOTASALUMNO_H
