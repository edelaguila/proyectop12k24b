#ifndef USUARIOS_H
#define USUARIOS_H

#define MAX 80
#define ARCHIVO_USUARIOS "usuarios.dat"
#define TECLA_ENTER 13
#define TECLA_BACKSPACE 8
#define MAX_INTENTOS 3
extern char linea[];
class Usuario {
private:


class usuarios
{
    public:
        usuarios();
        virtual ~usuarios();
        bool loginUsuarios();
        void menuUsuarios();
        bool buscar(string user, string passw);
        string getNombre();
        string setNombre(string nombre);

        void insertar();
        void desplegar();
        void modificar();
        void borrar();
        void menuextra();

        alumnos(string usu, string contra);
        string setid(string usu);
        string getid();

        string setnombre(string contra);
        string getnombre();

        struct Usuario {
            char usu[20];
            char contra[50];
        };

    protected:

    private:
		string id;
		string name;
		string pass;



public:
    char nombre[MAX];
    char password[MAX];
    void menuInicial();
    void menuRegistrarUsuario();
    void menuListarUsuarios();
    void menuIniciarSesion();
    char insertarUsuario(Usuario usuario);
    char existeUsuario(char nombreUsuario[], Usuario* usuario);
    char logear(char nombreUsuario[], char password[]);
    int leerLinea(char *cad, int n);
    void leerClave(char *password);
    Usuario *obtenerUsuarios(int *n); // Moved inside the class
};

#endif
