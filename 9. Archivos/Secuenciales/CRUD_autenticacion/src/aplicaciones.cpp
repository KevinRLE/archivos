#include "aplicaciones.h"

#include "bitacora.h"
#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<cstdlib>
#include<conio.h>
#include<iomanip>
#include "usuarios.h"

using namespace std;


void aplicaciones::menu()
{
    int choice;
	char x;

	do
    {
	system("cls");

	cout<<"\t\t\t------------------------------------"<<endl;
	cout<<"\t\t\t|SISTEMA GESTION APLICACIONES - 800|"<<endl;
	cout<<"\t\t\t------------------------------------"<<endl;
	cout<<"\t\t\t 1. Ingreso aplicaciones"<<endl;
	cout<<"\t\t\t 2. Despliegue aplicaciones"<<endl;
	cout<<"\t\t\t 3. Modifica aplicaciones"<<endl;
	cout<<"\t\t\t 4. Busca aplicaciones"<<endl;
	cout<<"\t\t\t 5. Borra aplicaciones"<<endl;
	cout<<"\t\t\t 6. Exit"<<endl;

	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"\t\t\tOpcion a escoger:[1/2/3/4/5/6]"<<endl;
	cout<<"\t\t\t-------------------------------"<<endl;
    cout<<"\t\t\tIngresa tu Opcion: ";
    cin>>choice;

    switch(choice)
    {
    case 1:
    	do
    	{
    		insertar();
    		cout<<"\n\t\t\t Agrega otra aplicacion(Y,N): ";
    		cin>>x;
		}while(x=='y'||x=='Y');
		break;
	case 2:
		desplegar();
		break;
	case 3:
		modificar();
		break;
	case 4:
		buscar();
		break;
	case 5:
		borrar();
		break;
	case 6:
		break;
	default:
		cout<<"\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
		cin.get();
	}
  }while(choice!= 6);
}
void aplicaciones::insertar()
{
	system("cls");
	fstream file;
	cout<<"\n------------------------------------------------------------------------------------------------------------------------";
	cout<<"\n-------------------------------------------------Agregar detalles Aplicacion ---------------------------------------------"<<endl;
	cout<<"\t\t\tIngresa Id Aplicacion         : ";
	cin>>id;
	cout<<"\t\t\tIngresa Nombre Aplicacion     : ";
	cin>>nombre;
	cout<<"\t\t\tIngresa estatus Aplicacion   : ";
	cin>>estatus;

	file.open("aplicaciones.txt", ios::app | ios::out);
	file<<std::left<<std::setw(15)<< id <<std::left<<std::setw(15)<< nombre <<std::left<<std::setw(15)<< estatus << "\n";
	file.close();
	bitacora auditoria;
	auditoria.insertar("usuario registrado", "801", "INS");
}
void aplicaciones::desplegar()
{
	system("cls");
	fstream file;
	int total=0;
	cout<<"\n-------------------------Tabla de Detalles de aplicaciones -------------------------"<<endl;
	file.open("aplicaciones.txt",ios::in);
	if(!file)
	{
		cout<<"\n\t\t\tNo hay información...";
		file.close();
	}
	else
	{
		file >> id >> nombre >> estatus;
		while(!file.eof())
		{
			total++;
			cout<<"\n\n\t\t\t Id Aplicacion: "<<id<<endl;
			cout<<"\t\t\t Nombre Aplicacion: "<<nombre<<endl;
            cout<<"\t\t\t estatus Aplicacion: "<<estatus<<endl;

			file >> id >> nombre >> estatus;
		}
		if(total==0)
		{
			cout<<"\n\t\t\tNo hay informacion...";
		}
		system("pause");
	}
	file.close();
    bitacora auditoria;
    auditoria.insertar("usuario registrado", "801", "SEL");
}
void aplicaciones::modificar()
{
	system("cls");
	fstream file,file1;
	string participant_id;
	int found=0;
	cout<<"\n-------------------------Modificacion Detalles Aplicacion-------------------------"<<endl;
	file.open("aplicaciones.txt",ios::in);
	if(!file)
	{
		cout<<"\n\t\t\tNo hay informacion..,";
		file.close();
	}
	else
	{
		cout<<"\n Ingrese Id del Aplicacion que quiere modificar: ";
		cin>>participant_id;
		file1.open("temporal.txt",ios::app | ios::out);
		file >> id >> nombre >> estatus;
		while(!file.eof())
		{
			if(participant_id!=id)
			{
			 file1<<std::left<<std::setw(15)<< id <<std::left<<std::setw(15)<< nombre <<std::left<<std::setw(15)<< estatus << "\n";
			}
			else
			{
				cout<<"\t\t\tIngrese Id Aplicacion: ";
				cin>>id;
				cout<<"\t\t\tIngrese Nombre Aplicacion: ";
				cin>>nombre;
				cout<<"\t\t\tIngrese estatus Aplicacion: ";
				cin>>estatus;
				file1<<std::left<<std::setw(15)<< id <<std::left<<std::setw(15)<< nombre <<std::left<<std::setw(15)<< estatus << "\n";
				found++;
			}
			file >> id >> nombre >> estatus;

		}
		file1.close();
		file.close();
		remove("aplicaciones.txt");
		rename("temporal.txt","aplicaciones.txt");
        bitacora auditoria;
        auditoria.insertar("usuario registrado", "801", "UPD");
	}
}
void aplicaciones::buscar()
{
	system("cls");
	fstream file;
	int found=0;
	file.open("aplicaciones.txt",ios::in);
	if(!file)
	{
		cout<<"\n-------------------------Datos del Aplicacion buscado------------------------"<<endl;
		cout<<"\n\t\t\tNo hay informacion...";
	}
	else
	{
		string participant_id;
		cout<<"\n-------------------------Datos del Aplicacion buscado------------------------"<<endl;
		cout<<"\nIngrese Id del Aplicacion que quiere buscar: ";
		cin>>participant_id;
		file >> id >> nombre >> estatus;
		while(!file.eof())
		{
			if(participant_id==id)
			{
				cout<<"\n\n\t\t\t Id Aplicacion: "<<id<<endl;
				cout<<"\t\t\t Nombre Aplicacion: "<<nombre<<endl;
				cout<<"\t\t\t estatus Aplicacion: "<<estatus<<endl;
				found++;
			}
			file >> id >> nombre >> estatus;
		}
		if(found==0)
		{
			cout<<"\n\t\t\t Persona no encontrada...";
		}
		file.close();
        bitacora auditoria;
        auditoria.insertar("usuario registrado", "801", "SEL");
	}
}
void aplicaciones::borrar()
{
	system("cls");
	fstream file,file1;
	string participant_id;
	int found=0;
	cout<<"\n-------------------------Detalles Aplicacion a Borrar-------------------------"<<endl;
	file.open("aplicaciones.txt",ios::in);
	if(!file)
	{
		cout<<"\n\t\t\tNo hay informacion...";
		file.close();
	}
	else
	{
		cout<<"\n Ingrese el Id del Aplicacion que quiere borrar: ";
		cin>>participant_id;
		file1.open("temporal.txt",ios::app | ios::out);
		file >> id >> nombre >> estatus;
		while(!file.eof())
		{
			if(participant_id!= id)
			{
				file1<<std::left<<std::setw(15)<< id <<std::left<<std::setw(15)<< nombre <<std::left<<std::setw(15)<< estatus << "\n";
			}
			else
			{
				found++;
				cout << "\n\t\t\tBorrado de informacion exitoso";
			}
			file >> id >> nombre >> estatus;
		}
		if(found==0)
		{
			cout<<"\n\t\t\t Id Persona no encontrado...";
		}
		file1.close();
		file.close();
		remove("aplicaciones.txt");
		rename("temporal.txt","aplicaciones.txt");
        bitacora auditoria;
        auditoria.insertar("usuario registrado", "801", "DEL");
	}
}



