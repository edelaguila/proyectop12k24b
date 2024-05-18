//Creado por Daniel Reyna Lopez 9959-23-5291

#ifndef HORARIOS_H
#define HORARIOS_H

class Horarios {
public:
    void menu();
    void insertar();
    void desplegar();
    void modificar();
    void borrar();
private:
    struct Horario {
        char id[11];
        char nombre[11];
        char Horario[11];

    };
    Horario horario;
};

#endif // HORARIOS_H
