#include "usuarios.h"
#include <cstdlib>
#include <conio.h> // Para getch()

usuarios::usuarios() {
    readFromFile();
}

usuarios::~usuarios() {
    saveToFile();
}

bool usuarios::loginUsuarios() {
    std::string usuario, contra;
    int contador = 0;
    bool ingresa = false;
    do {
        system("cls");
        std::cout << "---------------------------" << std::endl;
        std::cout << " AUTENTICACION DE USUARIOS " << std::endl;
        std::cout << "---------------------------" << std::endl;
        std::cout << "Codigo Usuario: ";
        getline(std::cin, usuario);
        std::cout << "\nContrasena: ";
        char caracter;
        caracter = getch();
        contra = "";
        while (caracter != 13) { // ASCII TECLA ENTER
            if (caracter != 8) { // ASCII TECLA RETROCESO
                contra.push_back(caracter);
                std::cout << "*";
            } else {
                if (contra.length() > 0) {
                    std::cout << "\b \b"; // Efecto caracter borrado en pantalla
                    contra = contra.substr(0, contra.length() - 1); // Toma todos los caracteres menos el ultimo
                }
            }
            caracter = getch();
        }
        if (buscar(usuario, contra)) {
            ingresa = true;
        } else {
            std::cout << "\nEl usuario y/o contrasena son incorrectos" << std::endl;
            contador++;
        }
    } while (ingresa == false && contador < 3); // Salir del bucle si el usuario ingresa o falla 3 veces

    return ingresa;
}

void usuarios::menuUsuarios() {
    char option;
    do {
        system("cls");
        std::cout << "\t\t\t-------------------------------------------------------" << std::endl;
        std::cout << "\t\t\t |   SISTEMA GESTION DE SEGURIDAD - Catalogos Usuarios |" << std::endl;
        std::cout << "\t\t\t-------------------------------------------------------" << std::endl;
        std::cout << "\t\t\t 1. Ingreso Usuarios" << std::endl;
        std::cout << "\t\t\t 2. Consulta Usuarios" << std::endl;
        std::cout << "\t\t\t 3. Modificacion Usuarios" << std::endl;
        std::cout << "\t\t\t 4. Eliminacion Usuarios" << std::endl;
        std::cout << "\t\t\t 5. Retornar menu anterior" << std::endl;
        std::cout << "\t\t\t-------------------------------------------------------" << std::endl;
        std::cout << "\t\t\tOpcion a escoger:[1/2/3/4/5]" << std::endl;
        std::cout << "\t\t\t-------------------------------------------------------" << std::endl;
        std::cout << "\t\t\tIngresa tu Opcion: ";
        std::cin >> option;

        switch (option) {
        case '1':
            system("cls");
            createUser();
            break;
        case '2':

            readUsers();
            break;
        case '3':
            system("cls");
            updateUser();
            break;
        case '4':
            system("cls");
            deleteUser();
            break;
        case '5':
            std::cout << "Saliendo..." << std::endl;
            break;
        default:
            std::cout << "Opción inválida. Inténtelo de nuevo." << std::endl;
        }
    } while (option != '5');
}

bool usuarios::buscar(const std::string& user, const std::string& passw) {
    std::ifstream file;
    int found = 0;
    file.open("Usuarios.txt", std::ios::in);
    if (!file) {
        std::cout << "\n-------------------------Datos de la Persona buscada------------------------" << std::endl;
        std::cout << "\n\t\t\tNo hay informacion...";
    } else {
        file >> id >> name >> pass;
        while (!file.eof()) {
            if (user == id) {
                if (passw == pass) {
                    found++;
                }
            }
            file >> id >> name >> pass;
        }
        if (found == 0) {
            return false;
        } else
            return true;
        file.close();
    }
}

std::string usuarios::getNombre() {
    return name;
}

void usuarios::setNombre(const std::string& nombre) {
    name = nombre;
}

void usuarios::createUser() {
    system("cls");
    User newUser;
    std::cout << "Ingrese el nombre de usuario: ";
    std::cin >> newUser.username;
    std::cout << "Ingrese la contraseña: ";
    std::cin >> newUser.password;
    users.push_back(newUser);
    saveToFile();
}

void usuarios::readUsers() {
    if (users.empty()) {
        std::cout << "No hay usuarios registrados." << std::endl;
        return;
    }
    std::cout << "Usuarios registrados:" << std::endl;
    for (const auto& user : users) {
        std::cout << "Nombre de usuario: " << user.username << ", Contraseña: " << user.password << std::endl;
    }
}

void usuarios::updateUser() {
    system("cls");
    if (users.empty()) {
        std::cout << "No hay usuarios para actualizar." << std::endl;
        return;
    }

    std::string username;
    std::cout << "Ingrese el nombre de usuario que desea actualizar: ";
    std::cin >> username;

    for (auto& user : users) {
        if (user.username == username) {
            std::cout << "Ingrese la nueva contraseña: ";
            std::cin >> user.password;
            saveToFile();
            std::cout << "Usuario actualizado exitosamente." << std::endl;
            return;
        }
    }

    std::cout << "No se encontró el usuario especificado." << std::endl;
}

void usuarios::deleteUser() {
    system("cls");
    if (users.empty()) {
        std::cout << "No hay usuarios para eliminar." << std::endl;
        return;
    }

    std::string username;
    std::cout << "Ingrese el nombre de usuario que desea eliminar: ";
    std::cin >> username;

    auto it = users.begin();
    while (it != users.end()) {
        if (it->username == username) {
            it = users.erase(it);
            saveToFile();
            std::cout << "Usuario eliminado exitosamente." << std::endl;
            return;
        } else {
            ++it;
        }
    }

    std::cout << "No se encontró el usuario especificado." << std::endl;
}

void usuarios::saveToFile() {
    std::ofstream file("users.dat", std::ios::binary);
    if (!file) {
        std::cerr << "Error al abrir el archivo para escritura." << std::endl;
        return;
    }

    for (const auto& user : users) {
        file.write(user.username.c_str(), user.username.size() + 1);
        file.write(user.password.c_str(), user.password.size() + 1);
    }

    file.close();
}

void usuarios::readFromFile() {
    std::ifstream file("users.dat", std::ios::binary);
    if (!file) {
        std::cerr << "El archivo de usuarios no existe todavía." << std::endl;
        return;
    }

    while (!file.eof()) {
        User user;
        char buffer[256];
        file.read(buffer, sizeof(buffer));
        if (file.gcount() == 0)
            break;
        user.username = buffer;
        file.read(buffer, sizeof(buffer));
        user.password = buffer;
        users.push_back(user);
    }

    file.close();
}
