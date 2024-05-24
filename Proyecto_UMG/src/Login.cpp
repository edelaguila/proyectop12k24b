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
