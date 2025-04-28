#include <iostream>
#include<fstream>
//IMPORTANTE INGRESAR LA PARTE DE USUARIOS LOGIN TAMBIÉN PARA NUESTRO PROYECTO USUARIOS.H USUARIOS.CPP
#include "usuarios.h"
#include "vendedores.h"
#include "bitacora.h"
#include "aplicaciones.h"
using namespace std;
void creditosModulo();
void catalogos();
void reportes();
void menuGeneral(usuarios &usuario);
usuarios usuarioRegistrado;
int main()
{
    bool accesoUsuarios=usuarioRegistrado.loginUsuarios();
    //creditosModulo();

    if (accesoUsuarios){//falta definir acceso == true, sino va a dejar entrar siempre (IMPORTANTE)
        menuGeneral(usuarioRegistrado);
    }
    system("cls");
    cout<<"** Hasta la proxima **";
    return 0;
}
void menuGeneral(usuarios &usuario){
    system("cls");
    int choice;
	//char x;
	do
    {
	system("cls");
	cout<<"\t\t\t\t\tUsuario: "<< usuario.getNombre() <<endl;
	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"\t\t\t |   SISTEMA GESTION DE VENTAS  |"<<endl;
	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"\t\t\t 1. Catalogos"<<endl;
	cout<<"\t\t\t 2. Procesos"<<endl;
	cout<<"\t\t\t 3. Reportes"<<endl;
	cout<<"\t\t\t 4. Ayuda"<<endl;
	cout<<"\t\t\t 5. Salir del Sistema"<<endl;
		cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"\t\t\tOpcion a escoger:[1/2/3/4/5]"<<endl;
	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"\t\t\tIngresa tu Opcion: ";
    cin>>choice;

    switch(choice)
    {
    case 1:
    	/*do
    	{*/
    		catalogos();
    		/*cout<<"\n\t\t\t Agrega otra persona(Y,N): ";
    		cin>>x;
		}while(x=='y'||x=='Y');*/
		break;
	case 2:
		//display();
		break;
	case 3:
		//modify();
		reportes();
		break;
	case 4:
		//search();
		break;
	case 5:
    	break;
	default:
		cout<<"\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
		cin.get();
	}
    }while(choice!= 5);
}
void catalogos(){
    int choice;
    //int x;
    do {
	system("cls");
	cout<<"\t\t\t--------------------------------------------"<<endl;
	cout<<"\t\t\t |   SISTEMA GESTION DE VENTAS - Catalogos  |"<<endl;
	cout<<"\t\t\t--------------------------------------------"<<endl;
	cout<<"\t\t\t 1. Clientes"<<endl;
	cout<<"\t\t\t 2. Vendedores"<<endl;
	cout<<"\t\t\t 3. Cobradores"<<endl;
	cout<<"\t\t\t 4. Aplicaciones"<<endl;
	cout<<"\t\t\t 5. Retornar menu anterior"<<endl;
    cout<<"\t\t\t--------------------------------------------"<<endl;
	cout<<"\t\t\tOpcion a escoger:[1/2/3/4/5]"<<endl;
	cout<<"\t\t\t--------------------------------------------"<<endl;
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
		{
            vendedores vendedor;
            vendedor.menu();
		}
		break;
	case 3:
		//modify();
		break;
	case 4:
        {
            aplicaciones aplicacion;
            aplicacion.menu();
		}
		//search();
		break;
	case 5:
		break;
	default:
		cout<<"\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
		cin.get();
	}
    }while(choice!= 5);
}
void reportes(){
    int choice;
    //int x;
    do {
	system("cls");
	cout<<"\t\t\t--------------------------------------------"<<endl;
	cout<<"\t\t\t |   SISTEMA GESTION DE VENTAS - Reportes   |"<<endl;
	cout<<"\t\t\t--------------------------------------------"<<endl;
	cout<<"\t\t\t 1. Clientes"<<endl;
	cout<<"\t\t\t 2. Vendedores"<<endl;
	cout<<"\t\t\t 3. Cobradores"<<endl;
	cout<<"\t\t\t 4. Conceptos"<<endl;
	cout<<"\t\t\t 5. Bitacora"<<endl;
	cout<<"\t\t\t 6. Retornar menu anterior"<<endl;
    cout<<"\t\t\t--------------------------------------------"<<endl;
	cout<<"\t\t\tOpcion a escoger:[1/2/3/4/5/6]"<<endl;
	cout<<"\t\t\t--------------------------------------------"<<endl;
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
		//display();
		{
            bitacora auditoria;
            auditoria.menu();
		}
		break;
	case 6:
		break;
	default:
		cout<<"\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
		cin.get();
	}
    }while(choice!= 6);
}
void creditosModulo(){
string line;
    //char userInput = ' ';
    ifstream myFile("modulo.txt");
    if(myFile.is_open())
    {
        //Se obtiene el mapa externo y se general el mapa de celdas
        while( getline(myFile, line))
        {
            cout << line << endl;
        }
        myFile.close();
        cout<<"Presione cualquier tecla para continuar";
        cin.get();
    }
    else
    {
        cout << "Error FATAL: el archivo de modulo no pudo ser cargado" << endl;
        cin.get();
    }
}
