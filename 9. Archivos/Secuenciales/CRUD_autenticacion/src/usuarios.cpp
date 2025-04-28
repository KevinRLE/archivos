#include "usuarios.h"
#include<fstream>
#include<cstdlib>
#include<conio.h>
#include<iostream>//se utiliza binari para encriptar y evaluar si el archivo txt es binario
#include "bitacora.h"
#define USER "daguilae"
#define PASS "123456"

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
    string usuario, contra;
    int contador=0;
    bool ingresa=false;
    do{
        system("cls");
        cout<<"---------------------------"<<endl;
        cout<<" AUTENTICACION DE USUARIOS "<<endl;
        cout<<"---------------------------"<<endl;
        //ingresa todo el string y no solo un caracter y un enter
        cout<<"\nNombre Usuario: ";
        getline(cin, usuario);
        //getline(cin, contra);
        cout<<"\nContrasena: ";

        char caracter;
        caracter = getch();
        contra="";
        while (caracter != 13) //ASCII TECLA ENTER
        {
            if (caracter != 8) //ASCII TECLA RETROCESO
            {
                contra.push_back(caracter); //manda y obtiene a pantalla la contraseña encriptada "*" con push_back
                cout<<"*";
            } else
            {
                if (contra.length() > 0)
                {
                    cout<<"\b \b"; //Efecto caracter borrado
                    contra = contra.substr(0,contra.length()-1); //Toma todos los caracteres menos el ultimo
                }
            }
            caracter = getch();
        }
        // Obtener datos del archivo SECUENCIAL
        //instancia de clase USUARIOS, para consultar: primero se consulta el usuario, si existe, se consulta la contraseña

        if (buscar(usuario, contra)){
            ingresa=true;
            cout << "\n=== Bienvenido al Sistema ===" << endl;
            bitacora auditoria;
            auditoria.insertar(name, "100", "LOGS"); // <- Usa name (desde archivo)
            cin.get();
        } else {
            cout << "\nEl usuario y/o contrasena son incorrectos" << endl;
            bitacora auditoria;
            auditoria.insertar(usuario, "100", "LOGF"); // <- Usa usuario (input)
            cin.get();
            contador++;
        }
    }while (ingresa==false && contador<3);
    if (ingresa == false) {
        cout << "\nLo siento, no puede ingresar al sistema..." << endl;
        cin.get();
    }
    return ingresa;
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
bool usuarios::buscar(string user, string passw)
{
	//system("cls");
	cout << "entre a buscar " << endl;
	fstream file;   //objeto que representa al archivo de texto
	int found=0;
	file.open("Usuarios.txt",ios::in);
	if(!file)
	{
		cout<<"\n-------------------------Datos de la Persona buscada------------------------"<<endl;
		cout<<"\n\t\t\tNo hay informacion...";
        return false;
	}

    while (file >> id >> name >> pass) {
        if (user == id && passw == pass) {
            file.close();
            return true;
        }
    }

    file.close();
    return false;
}

string usuarios::getNombre()
{
    return name;
}
void usuarios::setNombre(string nombre)
{
    name=nombre;
}
