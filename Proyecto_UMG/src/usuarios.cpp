#include "usuarios.h"
#include<fstream>
#include<cstdlib>
#include<conio.h>
#include<iostream>
#define USER "usuario"
#define PASS "1234"

using namespace std;


usuarios::usuarios()
{
    //ctor
}

usuarios::~usuarios()
{
    //dtor
}
bool usuarios::loginUsuarios(){

}
void usuarios::menuUsuarios(){
int choice;
    //int x;
    do {
	system("cls");
	cout<<"\t\t\t-------------------------------------------------------"<<endl;
	cout<<"\t\t\t |   SISTEMA GESTION DE SEGURIDAD - Catalogos Usuarios |"<<endl;
	cout<<"\t\t\t-------------------------------------------------------"<<endl;
	cout<<"\t\t\t 1. Ingreso Usuarios"<<endl;
	cout<<"\t\t\t 2. Consulta Usuarios"<<endl;
	cout<<"\t\t\t 3. Modificacion Usuarios"<<endl;
	cout<<"\t\t\t 4. Eliminacion Usuarios"<<endl;
	cout<<"\t\t\t 5. Retornar menu anterior"<<endl;
    cout<<"\t\t\t-------------------------------------------------------"<<endl;
	cout<<"\t\t\tOpcion a escoger:[1/2/3/4/5]"<<endl;
	cout<<"\t\t\t-------------------------------------------------------"<<endl;
	cout<<"\t\t\tIngresa tu Opcion: ";
    cin>>choice;

    switch(choice)
    {
    case 1:
    	/*do
    	{
    		catalogos();
    		cout<<"\n\t\t\t Agrega otra persona(Y,N): ";
    		cin>>x;
		}while(x=='y'||x=='Y');*/
		break;
	case 2:
		//display();
		break;
	case 3:
		//modify();
		break;
	case 4:
		//search();
		break;
	case 5:
		break;
	default:
		cout<<"\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
	}
	cin.get();
	//getch();
    }while(choice!= 5);
}
bool usuarios::buscar(string user, string passw )
{
	system("cls");
	fstream file;
	int found=0;
	file.open("Usuarios.txt",ios::in);
	if(!file)
	{
		cout<<"\n-------------------------Datos de la Persona buscada------------------------"<<endl;
		cout<<"\n\t\t\tNo hay informacion...";
	}
	else
	{
		file >> id >> name >> pass;
		while(!file.eof())
		{
			if(user==id)
			{
			    if (passw == pass)
                {
                    found++;
                }
			}
			file >> id >> name >> pass;
		}
		if(found==0)
		{
			return false;
		}
		else
            return true;
		file.close();
	}
}
string usuarios::getNombre()
{
    return name;
}
string usuarios::setNombre(string nombre)
{
    name=nombre;
}
