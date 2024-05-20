#ifndef JORNADA_H
#define JORNADA_H
<<<<<<< HEAD

=======
//blibliotecas
#include<stdlib.h>
#include<cstdlib>
#include<conio.h>
#include<iomanip>
>>>>>>> 7fee22e7c1a780459548acc106d5712411a3308b

using namespace std;

struct Jornada{
    int codigo;
    char nombre[50];
};
class JornadaCRUD {
public:
    void Ingresar();
    void Modificar();
    void Borrar();
    void Desplegar();
    void CrudJornada();

};

#endif // JORNADA_H
