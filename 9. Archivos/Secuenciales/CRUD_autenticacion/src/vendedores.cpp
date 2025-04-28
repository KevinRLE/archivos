#include "vendedores.h"
#include "bitacora.h"
#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<cstdlib>
#include<conio.h>
#include<iomanip>
#include "usuarios.h"

using namespace std;


void vendedores::menu()
{
    int choice;
	char x;

	do
    {
	system("cls");

	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"\t\t\t |   SISTEMA GESTION VENDEDORES -700 |"<<endl;
	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"\t\t\t 1. Ingreso Vendedores"<<endl;
	cout<<"\t\t\t 2. Despliegue Vendedores"<<endl;
	cout<<"\t\t\t 3. Modifica Vendedores"<<endl;
	cout<<"\t\t\t 4. Busca Vendedores"<<endl;
	cout<<"\t\t\t 5. Borra Vendedores"<<endl;
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
    		cout<<"\n\t\t\t Agrega otro vendedor(Y,N): ";
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
void vendedores::insertar()
{
	system("cls");
	fstream file;
	cout<<"\n------------------------------------------------------------------------------------------------------------------------";
	cout<<"\n-------------------------------------------------Agregar detalles Vendedor ---------------------------------------------"<<endl;
	cout<<"\t\t\tIngresa Id Vendedor         : ";
	cin>>id;
	cout<<"\t\t\tIngresa Nombre Vendedor     : ";
	cin>>nombre;
	cout<<"\t\t\tIngresa Telefono Vendedor   : ";
	cin>>telefono;

	file.open("vendedores.txt", ios::app | ios::out);
	file<<std::left<<std::setw(15)<< id <<std::left<<std::setw(15)<< nombre <<std::left<<std::setw(15)<< telefono << "\n";
	file.close();
	bitacora auditoria;
	auditoria.insertar("usuario registrado", "701", "INS");
}
void vendedores::desplegar()
{
	system("cls");
	fstream file;
	int total=0;
	cout<<"\n-------------------------Tabla de Detalles de Vendedores -------------------------"<<endl;
	file.open("vendedores.txt",ios::in);
	if(!file)
	{
		cout<<"\n\t\t\tNo hay información...";
		file.close();
	}
	else
	{
		file >> id >> nombre >> telefono;
		while(!file.eof())
		{
			total++;
			cout<<"\n\n\t\t\t Id Vendedor: "<<id<<endl;
			cout<<"\t\t\t Nombre Vendedor: "<<nombre<<endl;
            cout<<"\t\t\t Telefono Vendedor: "<<telefono<<endl;

			file >> id >> nombre >> telefono;
		}
		if(total==0)
		{
			cout<<"\n\t\t\tNo hay informacion...";
		}
		system("pause");
	}
	file.close();
    bitacora auditoria;
    auditoria.insertar("usuario registrado", "701", "SEL");
}
void vendedores::modificar()
{
	system("cls");
	fstream file,file1;
	string participant_id;
	int found=0;
	cout<<"\n-------------------------Modificacion Detalles Vendedor-------------------------"<<endl;
	file.open("vendedores.txt",ios::in);
	if(!file)
	{
		cout<<"\n\t\t\tNo hay informacion..,";
		file.close();
	}
	else
	{
		cout<<"\n Ingrese Id del vendedor que quiere modificar: ";
		cin>>participant_id;
		file1.open("temporal.txt",ios::app | ios::out);
		file >> id >> nombre >> telefono;
		while(!file.eof())
		{
			if(participant_id!=id)
			{
			 file1<<std::left<<std::setw(15)<< id <<std::left<<std::setw(15)<< nombre <<std::left<<std::setw(15)<< telefono << "\n";
			}
			else
			{
				cout<<"\t\t\tIngrese Id Vendedor: ";
				cin>>id;
				cout<<"\t\t\tIngrese Nombre Vendedor: ";
				cin>>nombre;
				cout<<"\t\t\tIngrese Telefono Vendedor: ";
				cin>>telefono;
				file1<<std::left<<std::setw(15)<< id <<std::left<<std::setw(15)<< nombre <<std::left<<std::setw(15)<< telefono << "\n";
				found++;
			}
			file >> id >> nombre >> telefono;

		}
		file1.close();
		file.close();
		remove("vendedores.txt");
		rename("temporal.txt","vendedores.txt");
        bitacora auditoria;
        auditoria.insertar("usuario registrado", "701", "UPD");
	}
}
void vendedores::buscar()
{
	system("cls");
	fstream file;
	int found=0;
	file.open("vendedores.txt",ios::in);
	if(!file)
	{
		cout<<"\n-------------------------Datos del vendedor buscado------------------------"<<endl;
		cout<<"\n\t\t\tNo hay informacion...";
	}
	else
	{
		string participant_id;
		cout<<"\n-------------------------Datos del vendedor buscado------------------------"<<endl;
		cout<<"\nIngrese Id del vendedor que quiere buscar: ";
		cin>>participant_id;
		file >> id >> nombre >> telefono;
		while(!file.eof())
		{
			if(participant_id==id)
			{
				cout<<"\n\n\t\t\t Id Vendedor: "<<id<<endl;
				cout<<"\t\t\t Nombre Vendedor: "<<nombre<<endl;
				cout<<"\t\t\t Telefono Vendedor: "<<telefono<<endl;
				found++;
			}
			file >> id >> nombre >> telefono;
		}
		if(found==0)
		{
			cout<<"\n\t\t\t Persona no encontrada...";
		}
		file.close();
        bitacora auditoria;
        auditoria.insertar("usuario registrado", "701", "SEL");
	}
}
void vendedores::borrar()
{
	system("cls");
	fstream file,file1;
	string participant_id;
	int found=0;
	cout<<"\n-------------------------Detalles Vendedor a Borrar-------------------------"<<endl;
	file.open("vendedores.txt",ios::in);
	if(!file)
	{
		cout<<"\n\t\t\tNo hay informacion...";
		file.close();
	}
	else
	{
		cout<<"\n Ingrese el Id del vendedor que quiere borrar: ";
		cin>>participant_id;
		file1.open("temporal.txt",ios::app | ios::out);
		file >> id >> nombre >> telefono;
		while(!file.eof())
		{
			if(participant_id!= id)
			{
				file1<<std::left<<std::setw(15)<< id <<std::left<<std::setw(15)<< nombre <<std::left<<std::setw(15)<< telefono << "\n";
			}
			else
			{
				found++;
				cout << "\n\t\t\tBorrado de informacion exitoso";
			}
			file >> id >> nombre >> telefono;
		}
		if(found==0)
		{
			cout<<"\n\t\t\t Id Persona no encontrado...";
		}
		file1.close();
		file.close();
		remove("vendedores.txt");
		rename("temporal.txt","vendedores.txt");
        bitacora auditoria;
        auditoria.insertar("usuario registrado", "701", "DEL");
	}
}



