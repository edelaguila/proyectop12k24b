<<<<<<< HEAD
//Creado por Victor Samayoa 9959-23-3424
=======
>>>>>>> ca05d99806224de811dc8563d2fc77f0fe4bf8d6
#include "Login.h"
#include "Bitacora.h"
#include "conio.h"
using namespace std;

string Login::usuarioActual = "";

Login::Login(string nombre, string contra, int maxintentos) : nombre(nombre), contra(contra), maxintentos(maxintentos), contintentos(0) {}

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

void Login::resetintentos() {
    contintentos = 0;
}

bool Login::validacion() {
    system("cls");

    fstream archivo;
    string nom;
    string pass;
    bool encontrado = false;


    archivo.open("Usuario.dat", ios::binary | ios::in);

    if (!archivo) {
        cout << "Error, no se encuentra informacion..." << endl;
        return false;
    }

<<<<<<< HEAD
    //busca el usuario en el archivo---------------------------------
    string user,pass;
    while (fileU_P>>user>>pass)
    {
        if (user==usuario && pass==contrasena)
        {
            Auditoria.ingresoBitacora(user,codigoPrograma,"LGI");
            encontrado=true;

            //arregla bitacora-----------------------------------------
            fstream file;
            file.open("bitaA.txt", ios::app | ios::out);
            //file <<std::left<<std::setw(15)<< user << "\n";
            file << std::left<<user<<"\n";
            file.close();
            //-----------------------------------------------------------

            break;
=======
    while (contintentos < maxintentos) {
        system("cls");
    cout << "+---------------------------------------------------------------------------------+" << endl;
    cout << "+                      Bienvenido Al sistema                                      +" << endl;
    cout << "+---------------------------------------------------------------------------------+" << endl;

        cout << "Intento " << (contintentos + 1) << " de " << maxintentos << "." << endl;
        cout << "Ingrese su Nombre: ";
        cin >> nom;
        cout << "Ingrese su contraseña: ";
         pass = "";
         char ch;
          while ((ch = getch()) != '\r') {
            if (ch == '\b') {
                if (!pass.empty()) {
                    cout << "\b \b";
                    pass.pop_back();
                }
            } else {
                cout << '*';
                pass += ch;
            }
        }
        cout << endl;
        Usuarios usuario;
          system("cls");
        while (archivo.read(reinterpret_cast<char*>(&usuario), sizeof(Usuarios))) {
            if (nom == usuario.nombre && pass == usuario.contra) {
                // Establecer el usuario actual después de la validación exitosa
                usuarioActual = nom;
                string codigoPrograma = "2350";
                Bitacora bitacora;
                bitacora.ingresoBitacora(nom, codigoPrograma, "LOG");
                encontrado = true;
                break;
            }
        }

        if (encontrado) {
            cout << "Login exitoso!" << endl;
            archivo.close();
            resetintentos();
            return true;
        } else {
            cout << "Nombre o contrasena incorrectos" << endl;
            contintentos++;
            archivo.clear(); // Limpiar el estado del archivo
            archivo.seekg(0, ios::beg); // Regresar al inicio del archivo
        }

        if (contintentos >= maxintentos) {
            cout << "Se ha alcanzado el numero maximo de intentos. Acceso denegado." << endl;
            archivo.close();
            return false;
>>>>>>> ca05d99806224de811dc8563d2fc77f0fe4bf8d6
        }
    }

    archivo.close();
    return false;
}
