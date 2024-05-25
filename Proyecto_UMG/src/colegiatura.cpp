// Jonathan Samuel Gonzalez Ixpata
#include "colegiatura.h"
#include <fstream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
#include <sstream>
#include <algorithm>
#include <Bitacora.h>
using namespace std;

bool colegiatura::validarID(const std::string& idEstudiante) {
    ifstream archivo("Alumnos.dat", ios::binary);
    if (!archivo) {
        cerr << "Error al abrir el archivo de alumnos." << endl;
        return false;
    }

    Alumno alumno;
    bool encontrado = false;

    while (archivo.read(reinterpret_cast<char*>(&alumno), sizeof(Alumno))) {
        if (alumno.id == idEstudiante) {
            encontrado = true;
            break;
        }
    }

    archivo.close();
    return encontrado;
}

string colegiatura::leerDatos() {
    string idIngresado;

    while (true) {
        // Limpiar la consola antes de cada intento
#ifdef _WIN32
        system("cls");
#else
        system("clear");
#endif

        cout << "Ingrese el carnet del estudiante: ";
        cin >> idIngresado;

        if (validarID(idIngresado)) {
            cout << "El carnet ingresado es válido." << endl;
            break;
        } else {
            cout << "El carnet ingresado es inválido." << endl;
            char opcion;
            cout << "Desea volver a intentar? (S/N): ";
            cin >> opcion;
            if (opcion == 'N' || opcion == 'n') {
                return "";
            }
        }
    }

    cout << "\n1. Colegiatura cursos" << endl;
    cout << "2. Examen extraordinario" << endl;
    cout << "3. Recuperacion" << endl;
    cout << "4. Regresar al menú principal" << endl;
    cout << "Opciones a escoger: [1/2/3/4]" << endl;
    cout << "Seleccione el tipo de pago: ";
    int opcionPago;
    cin >> opcionPago;

    if (opcionPago == 1) {
        procesarColegiaturaCursos(idIngresado);
    } else if (opcionPago == 2) {
        procesarExamenExtraordinario(idIngresado);
    } else if (opcionPago == 3) {
        procesarRecuperacion(idIngresado);
    } else if (opcionPago == 4) {
        return "";
    } else {
        cout << "Opción no válida." << endl;
    }

    return "";
}

void colegiatura::procesarColegiaturaCursos(const string& idIngresado) {
    string fechaHoy, semestre, mes, anio;

    cout << "Ingrese la fecha de hoy (dd/mm/yyyy): ";
    cin >> fechaHoy;
    cout << "Ingrese el semestre que cursa (1-10): ";
    cin >> semestre;
    cout << "Ingrese el mes de la colegiatura (enero-diciembre): ";
    cin >> mes;
    cout << "Ingrese el año (2023-2024): ";
    cin >> anio;

    cout << "\n\t--------- Monto de la colegiatura: Q825 ---------\n" << endl;
    cout << "Presione una tecla para continuar..." << endl;
    cin.ignore();  // Limpia el buffer de entrada
    cin.get();  // Espera a que el usuario presione una tecla

    pagarEnLinea(825, fechaHoy, semestre, mes, anio, idIngresado, "Colegiatura cursos");
}

void colegiatura::procesarExamenExtraordinario(const string& idIngresado) {
    string fechaHoy, semestre, anio, parcial;

    cout << "Ingrese la fecha de hoy (dd/mm/yyyy): ";
    cin >> fechaHoy;
    cout << "Ingrese el semestre que cursa (1-10): ";
    cin >> semestre;
    cout << "Ingrese el año (2023-2024): ";
    cin >> anio;

    int opcionParcial;
    do {
        cout << "Especifique si es pago de primer parcial (1) o segundo parcial (2): ";
        cin >> opcionParcial;
        if (opcionParcial == 1) {
            parcial = "Primer parcial";
        } else if (opcionParcial == 2) {
            parcial = "Segundo parcial";
        } else {
            cout << "Opción inválida. Por favor, ingrese 1 para primer parcial o 2 para segundo parcial." << endl;
        }
    } while (opcionParcial != 1 && opcionParcial != 2);

    cout << "\n\t--------- Monto del examen extraordinario: Q100 ---------\n" << endl;
    cout << "Presione una tecla para continuar..." << endl;
    cin.ignore();  // Limpia el buffer de entrada
    cin.get();  // Espera a que el usuario presione una tecla

    pagarEnLinea(100, fechaHoy, semestre, parcial, anio, idIngresado, "Examen extraordinario");
}


void colegiatura::procesarRecuperacion(const string& idIngresado) {
    string fechaHoy, semestre, anio;

    cout << "Ingrese la fecha de hoy (dd/mm/yyyy): ";
    cin >> fechaHoy;
    cout << "Ingrese el semestre que cursa (1-10): ";
    cin >> semestre;
    cout << "Ingrese el año (2023-2024): ";
    cin >> anio;

    cout << "\n\t--------- Monto de la recuperación: Q100 ---------\n" << endl;
    cout << "Presione una tecla para continuar..." << endl;
    cin.ignore();  // Limpia el buffer de entrada
    cin.get();  // Espera a que el usuario presione una tecla

    pagarEnLinea(100, fechaHoy, semestre, "N/A", anio, idIngresado, "Recuperación");
}

void colegiatura::pagarEnLinea(int monto, const string& fechaHoy, const string& semestre, const string& mes, const string& anio, const string& idIngresado, const string& tipoPago) {
    // Limpiar la pantalla
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif

    // Captura de los datos de la tarjeta
    cout << "\n----------------------------------------------------------------------------------------------------------";
    cout << "\n-------------------------------------------DATOS DE LA TARJETA--------------------------------------------" << endl;
    cout << "Ingrese los datos de su tarjeta de crédito para realizar el pago en línea:" << endl;
    string numTarjeta, fExpiracion, codSeguridad;
    cout << "Número de tarjeta: ";
    cin.ignore();  // Limpia el buffer de entrada antes de capturar los datos de la tarjeta
    getline(cin, numTarjeta);
    cout << "Fecha de expiración (MM/AA): ";
    getline(cin, fExpiracion);
    cout << "Código de seguridad: ";
    getline(cin, codSeguridad);

    // Abrir el archivo de la tarjeta
    ifstream archivo("tarjeta.txt");
    if (!archivo.is_open()) {
        cout << "Error: No se pudo abrir el archivo tarjeta.txt." << endl;
        return;
    }

    // Leer los datos de la tarjeta desde el archivo
    string numeroTarjeta, fechaExpiracion, codigoSeguridad;
    int saldo;
    getline(archivo, numeroTarjeta);
    getline(archivo, fechaExpiracion);
    getline(archivo, codigoSeguridad);
    archivo >> saldo;
    archivo.close();

    // Eliminar espacios en blanco al principio y al final de las cadenas
    auto trim = [](string& str) {
        str.erase(0, str.find_first_not_of(' '));       // quitar espacios al inicio
        str.erase(str.find_last_not_of(' ') + 1);       // quitar espacios al final
    };
    trim(numTarjeta);
    trim(fExpiracion);
    trim(codSeguridad);
    trim(numeroTarjeta);
    trim(fechaExpiracion);
    trim(codigoSeguridad);

    // Convertir cadenas a minúsculas para una comparación insensible a mayúsculas/minúsculas
    auto toLower = [](string& str) {
        transform(str.begin(), str.end(), str.begin(), ::tolower);
    };
    toLower(numTarjeta);
    toLower(fExpiracion);
    toLower(codSeguridad);
    toLower(numeroTarjeta);
    toLower(fechaExpiracion);
    toLower(codigoSeguridad);

    // Comparar los datos ingresados con los del archivo
    if (numTarjeta != numeroTarjeta || fExpiracion != fechaExpiracion || codSeguridad != codigoSeguridad) {
        cout << "Datos de la tarjeta incorrectos." << endl;
        char opcion;
        cout << "Desea volver a intentar? (S/N): ";
        cin >> opcion;
        if (opcion == 'S' || opcion == 's') {
            pagarEnLinea(monto, fechaHoy, semestre, mes, anio, idIngresado, tipoPago);
        }
        return;
    }

    // Verificar si hay saldo suficiente
    if (saldo >= monto) {
        cout << "\n¡Pago realizado en línea con éxito!" << endl;
        cout << "Monto pagado: Q" << monto << endl;
        cout << "Saldo disponible en la tarjeta: Q" << saldo - monto << endl;

        // Actualizar el saldo en el archivo de la tarjeta
        ofstream archivoSalida("tarjeta.txt");
        if (!archivoSalida.is_open()) {
            cout << "Error: No se pudo abrir el archivo tarjeta.txt para escribir." << endl;
            return;
        }

        archivoSalida << numeroTarjeta << endl;
        archivoSalida << fechaExpiracion << endl;
        archivoSalida << codigoSeguridad << endl;
        archivoSalida << saldo - monto << endl;
        archivoSalida.close();

        // Mostrar comprobante de pago
        string numeroBoleta = generarNumeroBoleta();
        string nombreEstudiante;
        obtenerDatosEstudiante(idIngresado, nombreEstudiante);

        cout << "\n----------------------------------------------------------------------------------------------------------";
        cout << "\n-------------------------------------------COMPROBANTE DE PAGO--------------------------------------------" << endl;
        cout << "Número de boleta: " << numeroBoleta << endl;
        cout << "Fecha: " << fechaHoy << endl;
        cout << "Semestre: " << semestre << endl;
        cout << "Mes: " << mes << endl;
        cout << "Año: " << anio << endl;
        cout << "Monto pagado: Q" << monto << endl;
        cout << "Carnet del estudiante: " << idIngresado << endl;
        cout << "Nombre del estudiante: " << nombreEstudiante << endl;
        cout << "Tipo de pago: " << tipoPago << endl;
        cout << "----------------------------------------------------------------------------------------------------------" << endl;
    } else {
        cout << "\n¡No hay fondos suficientes en la tarjeta para realizar el pago!" << endl;
        cout << "Saldo disponible en la tarjeta: Q" << saldo << endl;
    }
    system("pause");
}

string colegiatura::generarNumeroBoleta() {
    srand(time(0));
    stringstream ss;
    for (int i = 0; i < 12; ++i) {
        if (i > 0 && i % 4 == 0) {
            ss << '-';
        }
        ss << rand() % 10;
    }
    return ss.str();
}

void colegiatura::obtenerDatosEstudiante(const string& idEstudiante, string& nombreEstudiante) {
    ifstream archivo("Alumnos.dat", ios::binary);
    if (!archivo) {
        cerr << "Error al abrir el archivo de alumnos." << endl;
        return;
    }
    Alumno alumno;
    bool encontrado = false;

    while (archivo.read(reinterpret_cast<char*>(&alumno), sizeof(Alumno))) {
        if (alumno.id == idEstudiante) {
            nombreEstudiante = alumno.nombre;
            encontrado = true;
            break;
        }
    }

    archivo.close();

    if (!encontrado) {
        cerr << "No se encontró al estudiante con el ID proporcionado." << endl;
    }
}
