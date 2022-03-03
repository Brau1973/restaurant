#ifndef MOZO
#define MOZO
#include<iostream>
class Mesa;
#include"Mesa.h"
#include"VentaLocal.h"
#include<map>
using namespace std;
class VentaLocal;
class Mozo{
	private:
        string idMozo;
		string nombre;
		map<int,Mesa*> mesas;
	public:
		Mozo();
		Mozo(string,string);

		string getIdMozo();
        void setIdMozo(string);

		string getNombre();
        void setNombre(string);

		list<int> getMesas();
		void setMesas(map<int,Mesa*>);

		void asignarVentaAMesas(list<int>,VentaLocal*);
		list<int> mesasAsignadasSinVenta();

		~Mozo();

		friend ostream& operator <<(ostream&,const Mozo&);
};
#endif
