#ifndef USUARIOS_H
#define USUARIOS_H

#include <iostream>
#include <fstream>
#include <vector>

class usuarios
{
public:
    usuarios();
    ~usuarios();
    bool loginUsuarios();
    void menuUsuarios();
    bool buscar(const std::string& user, const std::string& passw);
    std::string getNombre();
    void setNombre(const std::string& nombre);
    void createUser();
    void readUsers();
    void updateUser();
    void deleteUser();
    void run();

private:
    struct User {
        std::string username;
        std::string password;
    };
    std::vector<User> users;
    void saveToFile();
    void readFromFile();

    std::string id;
    std::string name;
    std::string pass;
};

#endif
