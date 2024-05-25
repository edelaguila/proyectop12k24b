//Mishelloeiza //9959/23/3457
//creaciòn
//reconstruccion

#ifndef NOTAS_H
#define NOTAS_H

#include <vector>
#include <string>

struct Nota {
    int id;
    std::string nombre;
    std::string curso;
    float p1;
    float p2;
    float zona;
    float ef;
};

class GestorNotas {
private:
    std::vector<Nota> notas;
    const std::string filename = "notas.txt";
    std::vector<int> idsValidos;
    std::vector<std::string> nombresValidos;

public:
    GestorNotas();

    void agregarNota();
    void modificarNota(int id);
    void borrarNota(int id);
    void mostrarNotas();

private:
    void cargarNotas();
    void guardarNotas();
    void cargarAlumnosValidos();
    bool validarID(int id) const;
    bool validarNombre(const std::string& nombre) const;
};

#endif // NOTAS_H