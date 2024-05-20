#ifndef LOGIN_H
#define LOGIN_H
#define MAX 80
#define ARCHIVO_USUARIOS "usuarios.dat"
#define TECLA_ENTER 13
#define TECLA_BACKSPACE 8
#define MAX_INTENTOS 3

class Login {
public:
    int menuIniciarSesion();
    char logear(char nombreUsuario[], char password[]);
    void leerClave(char *password);
};
#endif // LOGIN_H
