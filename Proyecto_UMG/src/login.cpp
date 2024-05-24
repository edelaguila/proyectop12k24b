<<<<<<< HEAD
//Incluyendo librerias
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <conio.h>
////Incluyendo encabezados de login y usuarios
#include "login.h"
#include "usuarios.h"
<<<<<<< HEAD:Proyecto_UMG/src/login.cpp
=======
#include "Bitacora.h"
//Definimos variable
>>>>>>> 622f8ebce2543dc8685ec46d102fff264bc41df3:Proyecto_UMG/src/Login.cpp
#define MAX 80

//Funcion para poder iniciar sesion
int Login::menuIniciarSesion() {

    // variables para el nombre de usuario y contraseña
    char nombreUsuario[MAX];
    char password[MAX];

    //Contadores
    int intento = 0;
    int loginExitoso = 0;

    //Inicio del bucle do while
    do {
    //Limpiando pantalla
    system("cls");

    //Imprimimos mensaje (titulo)
    printf("\n\t\t\tINGRESAR AL SISTEMA\n");
    printf("\t\t\t===================\n");

    //Pedimos el nombre del usuario
    printf("\n\t\tUSUARIO: ");
    fgets(nombreUsuario, MAX, stdin);
    nombreUsuario[strcspn(nombreUsuario, "\n")] = 0; // Eliminar el salto de línea

    //Pedimos la contraseña
    printf("\t\tCLAVE: ");
    leerClave(password);

    //Condiciones
    //Verificacion
    if (logear(nombreUsuario, password)) {

    loginExitoso = 1;
    }
    //Si no se logra logear exitosamente muestra el siguiente mensaje
    else {
    printf("\n\n\t\tUsuario y/o password incorrectos");
    intento++;//incrementa el contador
    getchar();
    }

    string codigoPrograma="2322";
//Instancia de la clase bitacora
    Bitacora Auditoria;
//Declarando 2 variables string con el codigo programa
    string user, contrasena;
// ingreso en la bitácora pasamos como parámetros el nombre de usuario, el código del programa y un código de operación
    Auditoria.ingresoBitacora(nombreUsuario,codigoPrograma,"LGI");

    } while (intento < MAX_INTENTOS && loginExitoso == 0);

    //si se logra logear exitosamente muestra el siguiente mensaje
    if (loginExitoso == 1) {
    printf("\n\n\t\tInicio de sesión exitoso\n");
    }
    //Si llega a los 3 intentos muestra el siguiente mensaje
    else {
    printf("\n\tHa sobrepasado el numero maximo de intentos permitidos\n");
    getchar();
    }

    //Devolvemos el resultado del inicio de sesion
    return loginExitoso;
}

//Funcion para logear
char Login::logear(char nombreUsuario[], char password[]) {
    //Puntero en la variable archivo
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
//devuelve el resultado del logeo
return logeoExitoso;
}


//Funcion para poder leer la contraseña colocandole el puntero en password
void Login::leerClave(char *password) {
    char caracter;
    //Contador
    int i = 0;

    //Ciclo while
    while ((caracter = _getch())) {
    //se leen los caracteres hasta que se presione enter
        if (caracter == TECLA_ENTER) {
            password[i] = '\0';
            break;
        } else if (caracter == TECLA_BACKSPACE) {
            //Si se presiona espacio se borra el ultimo caracter
            if (i > 0) {
                i--;
                printf("\b \b");
            }
        } else {
            //Si el usuario ingresa un caracter valido se coloca *
            if (i < MAX) {
                printf("*");
                password[i] = caracter;
                i++; //incrementa el contador
            }
=======
#include "Login.h"
#include "Bitacora.h"

using namespace std;

string Login::usuarioActual = "";

Login::Login(string nombre, string contra) : nombre(nombre), contra(contra) {}

void Login::setnombre(string nombre) {
    this->nombre = nombre;
}

string Login::getnombre() const {
    return nombre;
}

void Login::setcontra(string contra) {
    this->contra = contra;
}

string Login::getcontra() const {
    return contra;
}
bool Login::validacion() {
    system("cls");

    fstream archivo;
    string nom;
    string pass;
    bool encontrado = false;

    cout << "+---------------------------------------------------------------------------------+" << endl;
    cout << "+                      Bienvenido Al sistema                                      +" << endl;
    cout << "+---------------------------------------------------------------------------------+" << endl;

    archivo.open("Usuario.dat", ios::binary | ios::in);

    if (!archivo) {
        cout << "Error, no se encuentra información..." << endl;
        return false;
    }

    cout << "Ingrese su Nombre: ";
    cin >> nom;
    cout << "Ingrese su contraseña: ";
    cin >> pass;

    Usuarios usuario;

    while (archivo.read(reinterpret_cast<char*>(&usuario), sizeof(Usuarios))) {
        if (nom == usuario.nombre && pass == usuario.contra) {
            // Establecer el usuario actual después de la validación exitosa
            usuarioActual = nom;
            string codigoPrograma = "2350";
            Bitacora bitacora;
            bitacora.ingresoBitacora(nom, codigoPrograma, "LOG");
            encontrado = true;
            break;
>>>>>>> 3269e90fd5a942b90e4cb9fced4d11702bff902d
        }
    }

    archivo.close();

    if (encontrado) {
        cout << "Login exitoso!" << endl;
        return true;
    } else {
        cout << "Nombre o contraseña incorrectos" << endl;
        return false;
    }
}
