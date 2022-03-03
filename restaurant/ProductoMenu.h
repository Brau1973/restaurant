#ifndef PRODUCTOMENU
#define PRODUCTOMENU

#include "ManejadorProducto.h"
#include "Comun.h"
#include "DtProducto.h"
#include <string>
#include<iostream>

using namespace std;

class ProductoMenu{
	private:
		int cantidad;
        Comun* comun;
	public:
		ProductoMenu();
		ProductoMenu(int);
		int getCantidad();
		void setCantidad(int);
		~ProductoMenu();

        string getCodigoComun();
        void asignarComun(string);
        float getPrecio();
};
#endif