#ifndef CURSOSS_H
#define CURSOSS_H
<<<<<<< HEAD

=======
#include<stdlib.h>
#include<cstdlib>
#include<conio.h>
#include<iomanip>
>>>>>>> 7fee22e7c1a780459548acc106d5712411a3308b

using namespace std;

struct Curso {
    int codigo;
    char nombre[50];
    char Creditos[50];
    char requisitos[50];

};
class CursosCRUD {
public:
    void IngresarCa();
    void ModificarCa();
    void BorrarCa();
    void DesplegarCa();
    void CrudCursos();

};
<<<<<<< HEAD
=======

>>>>>>> 7fee22e7c1a780459548acc106d5712411a3308b
#endif // CURSOSS_H
