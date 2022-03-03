#ifndef PRODUCTO
#define PRODUCTO

#include "DtProductoBase.h"
#include "TipoProducto.h"
#include <string>

#include<iostream>

using namespace std;

class Producto{
	private:
		string codigo;
		string descripcion;
		float precio;
	public:
		Producto();
		Producto(string,string,float);
		string getCodigo();
		void setCodigo(string);
		string getDescripcion();
		void setDescripcion(string);
		float getPrecio();
		void setPrecio(float);
		~Producto();
		
        DtProductoBase getDtProductoBase();
		
        virtual TipoProducto getTipoProducto()=0;
};
#endif