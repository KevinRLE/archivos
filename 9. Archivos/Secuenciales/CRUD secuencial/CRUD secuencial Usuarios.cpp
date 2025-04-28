#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<cstdlib>
#include<conio.h>
#include<iomanip>
using namespace std;
class persona
{
	private:
		string id,name,pass;
	public:
		void menu();
		void insertar();
		void desplegar();
		void modificar();
		void buscar();
		void borrar();
};
void persona::menu()
{
    int choice;
	char x;
	do
    {
	system("cls");

	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"\t\t\t |   SISTEMA GESTION PERSONAS  |"<<endl;
	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"\t\t\t 1. Ingreso Personas"<<endl;
	cout<<"\t\t\t 2. Despliegue Personas"<<endl;
	cout<<"\t\t\t 3. Modifica Personas"<<endl;
	cout<<"\t\t\t 4. Busca Personas"<<endl;
	cout<<"\t\t\t 5. Borra Personas"<<endl;
	cout<<"\t\t\t 6. Exit"<<endl;

	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"\t\t\tOpcion a escoger:[1/2/3/4/5/6]"<<endl;
	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"Ingresa tu Opcion: ";
    cin>>choice;

    switch(choice)
    {
    case 1:
    	do
    	{
    		insertar();
    		cout<<"\n\t\t\t Agrega otra persona(Y,N): ";
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
		exit(0);
	default:
		cout<<"\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
	}
	getch();
    }while(choice!= 6);
}
void persona::insertar()
{
	system("cls");
	fstream file; //instancia la clase fstream y crea una variable (objeto) llamada file, que se convertirá en usuarios.txt
	cout<<"\n------------------------------------------------------------------------------------------------------------------------";
	cout<<"\n-------------------------------------------------Agregar detalles Persona ---------------------------------------------"<<endl;
	cout<<"\t\t\tIngresa Id Persona         : ";
	cin>>id;
	cout<<"\t\t\tIngresa Nombre Persona     : ";
	cin>>name;
	cout<<"\t\t\tIngresa Contraseña Persona   : ";
	cin>>pass;
	file.open("Usuarios.txt", ios::app | ios::out); //crea y abre el archivo, agrega y si no está creado lo crea
	file<<std::left<<std::setw(15)<< id <<std::left<<std::setw(15)<< name <<std::left<<std::setw(15)<< pass << "\n";    //el left justifica el texto hacia la izquierda
	file.close(); //cierra el archivo lo saca de ram y lo coloca en disco duro
}
void persona::desplegar()
{
	system("cls");
	fstream file;
	int total=0;
	cout<<"\n-------------------------Tabla de Detalles de Personas -------------------------"<<endl;
	file.open("Usuarios.txt",ios::in);  //abre y lee el archivo "entrada"
	if(!file)
	{
		cout<<"\n\t\t\tNo hay información..."; //existe datos en archivo?
		file.close();
	}
	else
	{
		file >> id >> name >> pass; //si existe extrae datos por el objeto file >>
		while(!file.eof()) //mientras no sea eof "end of file" (final del archivo) ingresa, eof es como \n, no se ve pero lo agrega para identificar el final de datos del archivo
		{
			total++;    //recorre el listado
			cout<<"\n\n\t\t\t Id Persona: "<<id<<endl;
			cout<<"\t\t\t Nombre Persona: "<<name<<endl;
			cout<<"\t\t\t Contraseña Persona: "<<pass<<endl;
			file >> id >> name >> pass; //vuelve a extraer datos
		}
		if(total==0) //validación extra
		{
			cout<<"\n\t\t\tNo hay informacion..."; //si no existe info
		}
	}
	file.close();
}
void persona::modificar()
{
	system("cls");
	fstream file,file1;  //creacion de dos objetos, representando diferentes archivos despues
	string participant_id;
	int found=0;
	cout<<"\n-------------------------Modificacion Detalles Persona-------------------------"<<endl;
	file.open("Usuarios.txt",ios::in);  //abre y lee el archivo
	if(!file)   //pregunta si existe el archivo, sino se sale
	{
		cout<<"\n\t\t\tNo hay informacion..,";
		file.close();
	}
	else    //si existe ingresa
	{
		cout<<"\n Ingrese Id de la personas que quiere modificar: ";
		cin>>participant_id;    //ingresa el id persona
		file1.open("Record.txt",ios::app | ios::out);   //adjunta y sale archivos (de agregar o (|) de creacion), ademas file1 identifica al archivo record
		file >> id >> name >> pass;
		while(!file.eof())
		{
			if(participant_id!=id)    //id usuario de file de usuarios mientras sea diferente del id ingresado para record
			{
			 file1<<std::left<<std::setw(15)<< id <<std::left<<std::setw(15)<< name <<std::left<<std::setw(15)<< pass << "\n";  //toma el registro nuevo si es diferente y lo coloca en record.txt
			}
			else    //si no es diferente osea igual va a pedir ingresar de nuevo los datos para modificar
			{
				cout<<"\t\t\tIngrese Id Persona: ";
				cin>>id;
				cout<<"\t\t\tIngrese Nombre Persona: ";
				cin>>name;
				cout<<"\t\t\tIngrese Contraseña Persona: ";
				cin>>pass;
				file1<<std::left<<std::setw(15)<< id <<std::left<<std::setw(15)<< name <<std::left<<std::setw(15)<< pass << "\n";
				found++;    //encontrado incrementa en 1
			}
			file >> id >> name >> pass; //saca otro registro

		}
		file1.close();
		file.close();
		remove("Usuarios.txt");
		rename("Record.txt","Usuarios.txt");    //borra usuarios y renombra record a usuarios, es como que lo actualizara, lo cual es un método arcaico, ahora actualizaría el cambio
	}
}
void persona::buscar()
{
	system("cls");
	fstream file;
	int found=0;
	file.open("Usuarios.txt",ios::in);  //abre y lee
	if(!file)   //si no hay datos
	{
		cout<<"\n-------------------------Datos de la Persona buscada------------------------"<<endl;
		cout<<"\n\t\t\tNo hay informacion...";
	}
	else //si los hay
	{
		string participant_id;
		cout<<"\n-------------------------Datos de Persona buscada------------------------"<<endl;
		cout<<"\nIngrese Id de la Persona que quiere buscar: ";
		cin>>participant_id;    //Ingresa id
		file >> id >> name >> pass; //extrae id
		while(!file.eof())
		{
			if(participant_id==id) //si es igual a la id consulta de manera secuencial (es ineficiente pero funcional)
			{
				cout<<"\n\n\t\t\t Id Persona: "<<id<<endl;
				cout<<"\t\t\t Nombre Persona: "<<name<<endl;
				cout<<"\t\t\t Contraseña Persona: "<<pass<<endl;
				found++;
			}
			file >> id >> name >> pass;
		}
		if(found==0)    //sino no se encontró
		{
			cout<<"\n\t\t\t Persona no encontrada...";
		}
		file.close();
	}
}
void persona::borrar()
{
	system("cls");
	fstream file,file1;
	string participant_id;
	int found=0;
	cout<<"\n-------------------------Detalles Persona a Borrar-------------------------"<<endl;
	file.open("Usuarios.txt",ios::in);  //abre y lee
	if(!file)
	{
		cout<<"\n\t\t\tNo hay informacion...";
		file.close();
	}
	else
	{
		cout<<"\n Ingrese el Id de la Persona que quiere borrar: ";
		cin>>participant_id;
		file1.open("Record.txt",ios::app | ios::out);   //record es un temporal digamos, por lo que agrega o crea record
		file >> id >> name >> pass; //extrae
		while(!file.eof())  //recorre
		{
			if(participant_id!= id) //compara la id si es diferente
			{
				file1<<std::left<<std::setw(15)<< id <<std::left<<std::setw(15)<< name <<std::left<<std::setw(15)<< pass << "\n";
			}
			else    //si es igual borra datos pero aqui no hace nada, simplemente no agrega a nada a record, por lo que no lo agregará a usuarios ahora, por lo que cuenta como un borrado
			{
				found++;
				cout << "\n\t\t\tBorrado de informacion exitoso";
			}
			file >> id >> name >> pass;
		}
		if(found==0)
		{
			cout<<"\n\t\t\t Id Persona no encontrado...";
		}
		file1.close();
		file.close();
		remove("Usuarios.txt");
		rename("Record.txt","Usuarios.txt");
	}
}
main()
{
	persona estudiante;
	estudiante.menu();
	return 0;
}


