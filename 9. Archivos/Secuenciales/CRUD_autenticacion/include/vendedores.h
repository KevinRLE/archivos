#ifndef VENDEDORES_H
#define VENDEDORES_H
#include<iostream>


using std::string;

class vendedores
{
    private:
		string id, nombre, telefono;
	public:
		void menu();
		void insertar();
		void desplegar();
		void modificar();
		void buscar();
		void borrar();
};

#endif // VENDEDORES_H
