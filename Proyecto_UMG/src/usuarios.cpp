#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <conio.h>
#include "usuarios.h"
#include "usualumnos.h"
<<<<<<< HEAD
#include<fstream>
#include<cstdlib>
#include<conio.h>
#include<iostream>
#define USER "usuario"
#define PASS "1234"
=======
#include "usumaestros.h"
#define MAX 80
#define ARCHIVO_USUARIOS "usuarios.dat"
#define TECLA_ENTER 13
#define TECLA_BACKSPACE 8
#define MAX_INTENTOS 3
>>>>>>> fe9d22d9aea18290301fb123b219a553b09aa5e8

#include "usumaestros.h"

using namespace std;

char linea[MAX];

void Usuario::menuInicial() {
    char repite = 1;
    int opcion = -1;
        usualumnos Ualumnos;
        usumaestros Umaestros;

    do {
<<<<<<< HEAD
    char x;
	system("cls");
	cout<<"\t\t\t-------------------------------------------------------"<<endl;
	cout<<"\t\t\t |   SISTEMA GESTION DE SEGURIDAD - Catalogos Usuarios |"<<endl;
	cout<<"\t\t\t-------------------------------------------------------"<<endl;
	cout<<"\t\t\t 1. Ingreso Usuarios"<<endl;
	cout<<"\t\t\t 2. Consulta Usuarios"<<endl;
	cout<<"\t\t\t 3. Modificacion Usuarios"<<endl;
	cout<<"\t\t\t 4. Eliminacion Usuarios"<<endl;
	cout<<"\t\t\t 5. Alumnos y Maestros"<<endl;
	cout<<"\t\t\t 6. Retornar menu anterior"<<endl;
    cout<<"\t\t\t-------------------------------------------------------"<<endl;
	cout<<"\t\t\tOpcion a escoger:[1/2/3/4/5]"<<endl;
	cout<<"\t\t\t-------------------------------------------------------"<<endl;
	cout<<"\t\t\tIngresa tu Opcion: ";
    cin>>choice;

    switch(choice)
    {
    case 1:
    	do
    	{
    		insertar();
    		cout<<"\n\t\t\t Agrega otra persona(s,n): ";
    		cin>>x;
		}while(x=='s'||x=='S');
		break;
	case 2:
		desplegar();
		break;
	case 3:
		modificar();
		break;
	case 4:
		borrar();
		break;
	case 5:
	    menuextra();
		break;
    case 6:
		break;
	default:
		cout<<"\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
	}
	cin.get();
	//getch();
    }while(choice!= 6);
}
bool usuarios::buscar(string user, string passw)
{
=======
        system("cls");
        printf("\n\t\t\tMENU INICIAL\n");
        printf("\t\t\t============\n");
        printf("\n\t\t[1]. Ver usuarios registrados\n");
        printf("\t\t[2]. Registrar usuario nuevo\n");
        printf("\t\t[3]. Registrar usuario Alumon nuevo\n");
        printf("\t\t[4]. Registrar usuario Maestro nuevo\n");
        printf("\t\t[0]. Salir\n");
        printf("\n\t\tIngrese su opcion: [ ]\b\b");
        leerLinea(linea, MAX);
        sscanf(linea, "%d", &opcion);

        switch (opcion) {
            case 1:
                menuListarUsuarios();
                break;
>>>>>>> fe9d22d9aea18290301fb123b219a553b09aa5e8

            case 2:
                menuRegistrarUsuario();
                break;
            case 3:
                Ualumnos.menu();
                break;
            case 4:
                Umaestros.menu();
                break;
            case 0:
                repite = 0;
                break;
        }

    } while (repite == 1);
}

void Usuario::menuRegistrarUsuario() {
    Usuario usuario;
    char nombreUsuario[MAX];
    char respuesta[MAX];
    char repite = 1;

    do {
        system("cls");
        printf("\n\t\t\tREGISTRAR USUARIO\n");
        printf("\t\t\t=================\n");
        printf("\n\tIngrese nombre de usuario: ");
        leerLinea(linea, MAX);
        sscanf(linea, "%s", nombreUsuario);

        // Verifica que el nombre de usuario no exista
        if (!existeUsuario(nombreUsuario, &usuario)) {
            strcpy(usuario.nombre, nombreUsuario);

            printf("\tIngrese la clave: ");
            leerLinea(usuario.password, MAX);

            // Inserta el usuario en el archivo de usuarios
            if (insertarUsuario(usuario)) {
                printf("\n\tEl usuario fue registrado satisfactoriamente!\n");
            } else {
                printf("\n\tOcurrio un error al registrar el usuario\n");
                printf("\nInténtelo mas tarde\n");
            }
        } else {
            printf("\n\tEl usuario \"%s\" ya ha sido registrado previamente\n", usuario.nombre);
            printf("\tNo puede registrar dos usuarios con el mismo nombre de usuario.\n");
        }

        printf("\n\tDesea seguir registrando usuarios? [S/N]: ");
        leerLinea(respuesta, MAX);

        if (!(strcmp(respuesta, "S") == 0 || strcmp(respuesta, "s") == 0)) {
            repite = 0;
        }

    } while (repite == 1);
}

void Usuario::menuListarUsuarios() {
    int numeroUsuarios = 0;
    Usuario *usuarios;
    int i;

    system("cls");
    usuarios = obtenerUsuarios(&numeroUsuarios); // Retorna un vector dinámico de usuarios

    if (numeroUsuarios == 0) {
        printf("\n\tNo existe ningun usuario registrado!\n");
    } else {
        printf("\n\t\t    ==> LISTADO DE USUARIOS REGISTRADOS <==\n");
        printf(" ------------------------------------------------------------------------------\n");
        printf("%10s%25s%25s\n", "#", "NOMBRE", "PASSWORD");
        printf(" ------------------------------------------------------------------------------\n");

        // Recorre el vector dinámico de productos
        for (i = 0; i < numeroUsuarios; i++) {
            printf("%10d%25s%25s\n", (i + 1), usuarios[i].nombre, usuarios[i].password);
        }
        printf(" ------------------------------------------------------------------------------\n");
    }

    // Libera la memoria asignada al vector dinámico
    free(usuarios);
    usuarios = NULL;
    getchar();
}

void Usuario::menuIniciarSesion() {
    char nombreUsuario[MAX];
    char password[MAX];
    int intento = 0;
    int loginExitoso = 0;

    do {
        system("cls");
        printf("\n\t\t\tINGRESAR AL SISTEMA\n");
        printf("\t\t\t===================\n");

        printf("\n\t\tUSUARIO: ");
        leerLinea(linea, MAX);
        sscanf(linea, "%s", nombreUsuario);

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

    } else {
        printf("\n\tHa sobrepasado el numero maximo de intentos permitidos\n");
        getchar();
    }
}
// Retorna 1 si se registró el usuario en el archivo correctamente
char Usuario::insertarUsuario(Usuario usuario) {
    FILE *archivo;
    char insercion = 0;

    // Abre el archivo en modo de añadidura, para agregar datos al final. Si no existe es creado
    archivo = fopen(ARCHIVO_USUARIOS, "ab");

    if (archivo == NULL) {
        insercion = 0;
    } else {
        // Registra el struct usuario en el archivo
        fwrite(&usuario, sizeof(usuario), 1, archivo);
        insercion = 1;

        // Cierra el archivo
        fclose(archivo);
    }

    return insercion;
}

// Retorna 1 si existe el nombre de usuario. Retorna el usuario buscado si existe
char Usuario::existeUsuario(char nombreUsuario[], Usuario* usuario) {
    FILE *archivo;
    char existe;

    // Abre el archivo en modo de lectura
    archivo = fopen(ARCHIVO_USUARIOS, "rb");

    if (archivo == NULL) {
        existe = 0;
    } else {
        existe = 0;

        // Lee secuencialmente del archivo de usuarios
        fread(&(*usuario), sizeof(*usuario), 1, archivo);
        while (!feof(archivo)) {
            if (strcmp((*usuario).nombre, nombreUsuario) == 0) {
                // Encuentra un usuario del archivo con el nombre de usuario buscado
                existe = 1;
                break;
            }

            fread(&(*usuario), sizeof(*usuario), 1, archivo);
        }

        // Cierra el archivo
        fclose(archivo);
    }

    return existe;
}

Usuario *Usuario::obtenerUsuarios(int *n) { // Moved inside the class
    FILE *archivo;
    Usuario usuario;
    Usuario *usuarios; // Vector dinámico de usuarios
    int i;

    // Abre el archivo en modo lectura
    archivo = fopen(ARCHIVO_USUARIOS, "rb");

    if (archivo == NULL) { // Si no se pudo abrir el archivo, el valor de archivo es NULL
        *n = 0; // No se pudo abrir. Se considera n = 0
        usuarios = NULL;
    } else {
        fseek(archivo, 0, SEEK_END); // Posiciona el cursor al final del archivo
        *n = ftell(archivo) / sizeof(Usuario); // # de usuarios almacenados en el archivo. (# de registros)
        usuarios = (Usuario *)malloc((*n) * sizeof(Usuario)); // Asigna memoria para todos los usuarios almacenados en el archivo

        // Recorre el archivo secuencialmente
        fseek(archivo, 0, SEEK_SET); // Posiciona el cursor al principio del archivo
        fread(&usuario, sizeof(usuario), 1, archivo);
        i = 0;
        while (!feof(archivo)) {
            usuarios[i++] = usuario;
            fread(&usuario, sizeof(usuario), 1, archivo);
        }

        // Cierra el archivo
        fclose(archivo);
    }

    return usuarios;
}

// Retorna 1 o 0 si el usuario y password son correctos para un usuario en particular
char Usuario::logear(char nombreUsuario[], char password[]) {
    FILE *archivo;
    char logeoExitoso;
    Usuario usuario;

    // Abre el archivo en modo de lectura
    archivo = fopen(ARCHIVO_USUARIOS, "rb");

    if (archivo == NULL) {
        logeoExitoso = 0;
    } else {
        logeoExitoso = 0;

        // Lee secuencialmente del archivo de usuarios
        fread(&usuario, sizeof(usuario), 1, archivo);
        while (!feof(archivo)) {
            if (strcmp(usuario.nombre, nombreUsuario) == 0 && strcmp(usuario.password, password) == 0) {
                // Encuentra un usuario del archivo con el nombre de usuario y password buscado
                logeoExitoso = 1;
                break;
            }

            fread(&usuario, sizeof(usuario), 1, archivo);
        }

        // Cierra el archivo
        fclose(archivo);
    }

    return logeoExitoso;
}

int Usuario::leerLinea(char *cad, int n) {
    int i, c;

    // 1. Comprobación de datos iniciales en el buffer
    c = getchar();
    if (c == EOF) {
        cad[0] = '\0';
        return 0;
    }

    if (c == '\n') {
        i = 0;
    } else {
        cad[0] = c;
        i = 1;
    }

    // 2. Lectura de la cadena
    for (; i < n - 1 && (c = getchar()) != EOF && c != '\n'; i++) {
        cad[i] = c;
    }
    cad[i] = '\0';

    // 3. Limpieza del buffer
    if (c != '\n' && c != EOF) // Es un caracter
        while ((c = getchar()) != '\n' && c != EOF);

    return 1;
}

void Usuario::leerClave(char *password) {
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

void usuarios::menuextra()
{
   int choice;
    do {
    char x;
	system("cls");
	cout<<"\t\t\t-------------------------------------------------------"<<endl;
	cout<<"\t\t\t |   SISTEMA GESTION DE SEGURIDAD - Catalogos Usuarios |"<<endl;
	cout<<"\t\t\t-------------------------------------------------------"<<endl;
	cout<<"\t\t\t 1. Menu de usuarios de alumnos"<<endl;
	cout<<"\t\t\t 2. Menu de usuarios de maestros"<<endl;
	cout<<"\t\t\t 3. Retornar menu anterior"<<endl;
    cout<<"\t\t\t-------------------------------------------------------"<<endl;
	cout<<"\t\t\tOpcion a escoger:[1/2/3]"<<endl;
	cout<<"\t\t\t-------------------------------------------------------"<<endl;
	cout<<"\t\t\tIngresa tu Opcion: ";
    cin>>choice;

    switch(choice)
    {
    case 1:
        {
            usualumnos alum;
            alum.menu();
        }
		break;
	case 2:
	    {
	        usumaestros maestros;
	        maestros.menu();
	    }
	    break;
	case 3:
		break;
	default:
		cout<<"\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
	}
	cin.get();
	//getch();
    }while(choice!= 3);
}
