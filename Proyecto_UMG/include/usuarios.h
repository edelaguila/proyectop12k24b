#ifndef USUARIOS_H
#define USUARIOS_H
<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> 622f8ebce2543dc8685ec46d102fff264bc41df3
#define MAX 80
#define ARCHIVO_USUARIOS "usuarios.dat"
#define TECLA_ENTER 13
#define TECLA_BACKSPACE 8
#define MAX_INTENTOS 3
extern char linea[];

class Usuario {
private:
<<<<<<< HEAD

=======
=======
#include <iostream>
>>>>>>> 3269e90fd5a942b90e4cb9fced4d11702bff902d


using namespace std;

struct Usuarios {

    char nombre[80];
    char contra[80];
>>>>>>> 622f8ebce2543dc8685ec46d102fff264bc41df3

};


class usuarios
{

    private:
        string nombre, contra;


    public:

        usuarios(){}
        usuarios(string nombre, string contra);

        string setnombre(string nombre);
        string getnombre();

        string setcontra(string contra);
        string getcontra();

        void menu();
        void pideDatos();
        void muestraDatos();
        void editaDatos();
        void borraDatos();
};


#endif // USUARIOS_H
