#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <conio.h>
#include "login.h"
#include "usuarios.h"
#define MAX 80

int Login::menuIniciarSesion() {
    char nombreUsuario[MAX];
    char password[MAX];
    int intento = 0;
    int loginExitoso = 0;

    do {
    system("cls");
    printf("\n\t\t\tINGRESAR AL SISTEMA\n");
    printf("\t\t\t===================\n");

    printf("\n\t\tUSUARIO: ");
    fgets(nombreUsuario, MAX, stdin);
    nombreUsuario[strcspn(nombreUsuario, "\n")] = 0; // Eliminar el salto de línea

    printf("\t\tCLAVE: ");
    leerClave(password);

    if (logear(nombreUsuario, password)) {
    loginExitoso = 1;
    } else {
     printf("\n\n\t\tUsuario y/o password incorrectos");
    intento++;
    getchar();
    }
    } while (intento < MAX_INTENTOS && loginExitoso == 0);

    if (loginExitoso == 1) {
    printf("\n\n\t\tInicio de sesión exitoso\n");
    } else {
    printf("\n\tHa sobrepasado el numero maximo de intentos permitidos\n");
    getchar();
    }

    return loginExitoso;
}

char Login::logear(char nombreUsuario[], char password[]) {
    FILE *archivo;
char logeoExitoso = 0;
    Usuario usuario;

    // Abre el archivo en modo de lectura
archivo = fopen(ARCHIVO_USUARIOS, "rb");

if (archivo != NULL) {
    // Lee secuencialmente del archivo de usuarios
while (fread(&usuario, sizeof(usuario), 1, archivo)) {
if (strcmp(usuario.nombre, nombreUsuario) == 0 && strcmp(usuario.password, password) == 0) {
    logeoExitoso = 1;
    break;
    }
    }

    // Cierra el archivo
    fclose(archivo);
    }

return logeoExitoso;
}



void Login::leerClave(char *password) {
    char caracter;
    int i = 0;

    while ((caracter = _getch())) {
        if (caracter == TECLA_ENTER) {
            password[i] = '\0';
            break;
        } else if (caracter == TECLA_BACKSPACE) {
            if (i > 0) {
                i--;
                printf("\b \b");
            }
        } else {
            if (i < MAX) {
                printf("*");
                password[i] = caracter;
                i++;
            }
        }
    }
}
