<<<<<<< HEAD
//Incluyendo las librerias a utilizar
#include <iostream>
#include <fstream>
#include <conio.h>
#include <ctime>
#include <stdlib.h>
#include <iomanip>

//Incluyendo el encabezado de la bitacora
#include "Bitacora.h"

//Funcion para ingresar la bitacora con sus parametros
void Bitacora::ingresoBitacora(string nombre, string aplicacion, string accion)

//Parametros:  nombre: codigo de usuario autenticado.  aplicacion: codigo de aplicacion.  accion: puede ser INS->ingreso
//QRY->consulta UPD->actualizacion DEL->borrado de datos PRN->imprimir


{
    // Declaramos un objeto de la clase fstream para manejar archivos
	fstream file;
	// Abrimos el archivo "Bitacora.dat" en modo binario, de adición y de salida
	file.open("Bitacora.dat", ios::binary | ios::app | ios::out );
	// Obtenemos el tiempo actual del sistema
    time_t now = time(0);
    // Convertimos el tiempo actual a una cadena de caracteres con formato legible
    date_time = ctime(&now);
    // Escribimos los datos en el archivo usando formato de salida
    file<<std::left<<std::setw(20)<<nombre<<std::left<<std::setw(15)<<aplicacion<<std::left<<std::setw(15)<< accion <<std::left<<std::setw(15)<< date_time;
    //Cierra el archivo
    file.close();
}
//Funcion para poder visualizar la bitacora
void Bitacora::visualizarBitacora()
{
    //Limpiando pantalla
    system("cls");
    //Imprimiendo mensaje del encabezado de la tabla de detalles de bitacora
    cout<<"\n-------------------------Tabla de Detalles de Bitacora - 1000 -------------------------"<<endl;

    // Declaramos un objeto de la clase fstream
	fstream file;
	// Declaramos una cadena de texto
	string texto;
	//variable int con valor 0
	int total=0;
	//Abre un archivo en binario llamado Bitacora.dat
	file.open("Bitacora.dat",ios::binary | ios::in);

	// Leemos los primeros valores del archivo para las variables nombre, aplicacion, accion y date_time
	cout<<"\nNombre" <<setw(22)<< "Aplicacion" <<setw(12)<< "Accion" <<setw(20)<< "Fecha\n\n";
	file >> nombre >> aplicacion >> accion >> date_time;

    //Bucle while para que se repita hasta llegar al final
    while(!file.eof())
    {
        total++; //incrementa el contador total
        // Leemos una línea completa del archivo y la almacenamos en la variable texto
        getline(file,texto);
        cout<<texto<<endl;
    }
    //Condiciones
    if(total==0)
    {
        //Si no se encuentra ningun dato en el archivo
        cout<<"\n\t\t\tNo hay informacion...";
    }
    //cierra el archivo
    file.close();
    // Pausamos la ejecución del programa hasta que el usuario presione una tecla
    system("pause");
=======
#include "Bitacora.h"
#include <cstring>


void Bitacora::ingresoBitacora(const string& usuario, const string& codigoPrograma, const string& tipoIngreso) {
    ofstream archivo("Bitacora.dat", ios::binary | ios::app);
    if (archivo.is_open()) {
        RegistroBitacora registro;

        strncpy(registro.nombre, usuario.c_str(), sizeof(registro.nombre) - 1);
        registro.nombre[sizeof(registro.nombre) - 1] = '\0'; // Asegurar la terminación nula

        strncpy(registro.aplicacion, codigoPrograma.c_str(), sizeof(registro.aplicacion) - 1);
        registro.aplicacion[sizeof(registro.aplicacion) - 1] = '\0'; // Asegurar la terminación nula

        strncpy(registro.accion, tipoIngreso.c_str(), sizeof(registro.accion) - 1);
        registro.accion[sizeof(registro.accion) - 1] = '\0'; // Asegurar la terminación nula

        // Obtener la fecha y hora actual
        time_t now = time(0);
        tm *ltm = localtime(&now);
        string fechaHora = to_string(ltm->tm_year + 1900) + "-" + to_string(ltm->tm_mon + 1) + "-" + to_string(ltm->tm_mday) + " " +
                           to_string(ltm->tm_hour) + ":" + to_string(ltm->tm_min) + ":" + to_string(ltm->tm_sec);

        strncpy(registro.fechaHora, fechaHora.c_str(), sizeof(registro.fechaHora) - 1);
        registro.fechaHora[sizeof(registro.fechaHora) - 1] = '\0'; // Asegurar la terminación nula

        archivo.write(reinterpret_cast<char*>(&registro), sizeof(RegistroBitacora));
        archivo.close();
    } else {
        cout << "No se pudo abrir el archivo de bitácora." << endl;
    }
}

void Bitacora::mostrarBitacora() {
    system("cls");
    ifstream archivo("Bitacora.dat", ios::binary | ios::in);
    if (!archivo) {
        cout << "No hay información registrada en la bitácora." << endl;
        return;
    }

    RegistroBitacora registro;
    while (archivo.read(reinterpret_cast<char*>(&registro), sizeof(RegistroBitacora))) {
        cout << "Usuario: " << registro.nombre << ", Aplicacion: " << registro.aplicacion << ", Accion: " << registro.accion << ", Fecha y Hora: " << registro.fechaHora << endl;
    }
    archivo.close();

    cout << "Presione Enter para continuar";
    cin.ignore();
    cin.get();
>>>>>>> 3269e90fd5a942b90e4cb9fced4d11702bff902d
}
