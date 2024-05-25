// Diana Mishel Loeiza //9959-23-3457 //reconstrucion para validar alumnos 
// rangos de notas especificos
//uso de archivos txt
#include "notas.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>

GestorNotas::GestorNotas() {
    cargarNotas(); // Carga las notas desde el archivo al iniciar el gestor de notas
    cargarAlumnosValidos(); // Carga los alumnos válidos desde el archivo al iniciar el gestor de notas
}

void GestorNotas::agregarNota() {
    Nota nuevaNota; // Crea una nueva nota
    std::cout << "Ingrese ID del alumno: ";
    std::cin >> nuevaNota.id; // Lee el ID del alumno
    if (!validarID(nuevaNota.id)) { // Valida que el ID sea único
        std::cout << "ID no válido. Debe ser único." << std::endl;
        return;
    }

    std::cout << "Ingrese nombre del alumno: ";
    std::cin >> nuevaNota.nombre; // Lee el nombre del alumno
    if (!validarNombre(nuevaNota.nombre)) { // Valida que el nombre esté en la lista de nombres válidos
        std::cout << "Nombre no válido. Debe estar en la lista de nombres válidos." << std::endl;
        return;
    }

    std::cout << "Ingrese curso: ";
    std::cin >> nuevaNota.curso; // Lee el curso
    std::cout << "Ingrese nota de P1 (max 20): ";
    std::cin >> nuevaNota.p1; // Lee la nota de P1
    std::cout << "Ingrese nota de P2 (max 25): ";
    std::cin >> nuevaNota.p2; // Lee la nota de P2
    std::cout << "Ingrese nota de Zona (max 20): ";
    std::cin >> nuevaNota.zona; // Lee la nota de Zona
    std::cout << "Ingrese nota de EF (max 35): ";
    std::cin >> nuevaNota.ef; // Lee la nota de EF

    // Validación de notas
    if (nuevaNota.p1 > 20 || nuevaNota.p2 > 25 || nuevaNota.zona > 20 || nuevaNota.ef > 35) {
        std::cout << "Error: Las notas no pueden exceder los límites." << std::endl;
        return;
    }

    notas.push_back(nuevaNota); // Agrega la nueva nota al vector de notas
    guardarNotas(); // Guarda las notas en el archivo
    std::cout << "Nota agregada exitosamente." << std::endl;
}

bool GestorNotas::validarID(int id) const {
    for (const auto& nota : notas) {
        if (nota.id == id) {
            return false; // El ID ya existe
        }
    }
    return std::find(idsValidos.begin(), idsValidos.end(), id) != idsValidos.end();
}

bool GestorNotas::validarNombre(const std::string& nombre) const {
    return std::find(nombresValidos.begin(), nombresValidos.end(), nombre) != nombresValidos.end();
}

void GestorNotas::cargarAlumnosValidos() {
    std::ifstream file("cursosAlumnosMaestro.txt"); // Abre el archivo de alumnos válidos
    if (!file) {
        std::cerr << "Error al abrir el archivo de nombres válidos." << std::endl;
        return;
    }

    int id;
    std::string nombre;
    while (file >> id >> nombre) { // Lee los IDs y nombres de los alumnos válidos desde el archivo
        idsValidos.push_back(id);
        nombresValidos.push_back(nombre);
    }
}

void GestorNotas::modificarNota(int id) {
    // Buscar la nota por ID
    for (auto& nota : notas) {
        if (nota.id == id) {
            int opcion;
            std::cout << "Seleccione la nota que desea modificar:\n"
                      << "1. P1\n"
                      << "2. P2\n"
                      << "3. Zona\n"
                      << "4. EF\n";
            std::cin >> opcion;

            float nuevaNota;
            switch (opcion) {
                case 1:
                    std::cout << "Nueva nota de P1: ";
                    std::cin >> nuevaNota;
                    nota.p1 = nuevaNota;
                    break;
                case 2:
                    std::cout << "Nueva nota de P2: ";
                    std::cin >> nuevaNota;
                    nota.p2 = nuevaNota;
                    break;
                case 3:
                    std::cout << "Nueva nota de Zona: ";
                    std::cin >> nuevaNota;
                    nota.zona = nuevaNota;
                    break;
                case 4:
                    std::cout << "Nueva nota de EF: ";
                    std::cin >> nuevaNota;
                    nota.ef = nuevaNota;
                    break;
                default:
                    std::cout << "Opción inválida." << std::endl;
                    return;
            }
            // Recalcular la suma de las notas
            float sumaNotas = nota.p1 + nota.p2 + nota.zona + nota.ef;
            if (sumaNotas > 100) {
                std::cout << "La suma de las notas supera 100. Se recomienda verificar." << std::endl;
            } else {
                std::cout << "Suma de notas: " << sumaNotas << std::endl;
            }

            guardarNotas();
            std::cout << "Nota modificada exitosamente." << std::endl;
            return;
        }
    }
    std::cout << "ID de alumno no encontrado." << std::endl;
}

void GestorNotas::borrarNota(int id) {
    for (auto it = notas.begin(); it != notas.end(); ++it) {
        if (it->id == id) {
            notas.erase(it);
            guardarNotas();
            std::cout << "Nota eliminada exitosamente." << std::endl;
            return;
        }
    }
    std::cout << "ID de alumno no encontrado." << std::endl;
}

void GestorNotas::mostrarNotas() {
    for (const auto& nota : notas) { // Muestra las notas de todos los alumnos
        float notaFinal = nota.p1 + nota.p2 + nota.zona + nota.ef;
        std::cout << "ID: " << nota.id << std::endl;
        std::cout << "Nombre: " << nota.nombre << std::endl;
        std::cout << "Curso: " << nota.curso << std::endl;
        std::cout << "Nota final: " << notaFinal << std::endl;
        std::cout << "------------------------------------" << std::endl;
    }
}

void GestorNotas::cargarNotas() {
    std::ifstream file(filename); // Abre el archivo de notas
    if (!file) {
        std::cerr << "Error al abrir el archivo de notas." << std::endl;
        return;
    }

    Nota nota;
    while (file >> nota.id >> nota.nombre >> nota.curso >> nota.p1 >> nota.p2 >> nota.zona >> nota.ef) { // Lee las notas desde el archivo
        notas.push_back(nota);
    }
    file.close();
}

void GestorNotas::guardarNotas() {
    std::ofstream file(filename); // Abre el archivo de notas para escritura
    if (!file) {
        std::cerr << "Error al abrir el archivo de notas." << std::endl;
        return;
    }

    for (const auto& nota : notas) { // Escribe las notas en el archivo
        file << nota.id << " " << nota.nombre << " " << nota.curso << " "
             << nota.p1 << " " << nota.p2 << " " << nota.zona << " " << nota.ef << std::endl;
    }
    file.close();
}
