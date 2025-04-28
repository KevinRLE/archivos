#ifndef APLICACIONES_H
#define APLICACIONES_H
#include<iostream>


using std::string;

class aplicaciones
{
    private:
		string id, nombre, estatus;
	public:
		void menu();
		void insertar();
		void desplegar();
		void modificar();
		void buscar();
		void borrar();
};


#endif // APLICACIONES_H
