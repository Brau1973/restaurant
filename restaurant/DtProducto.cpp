#include "DtProducto.h"
DtProducto::DtProducto(){}
DtProducto::DtProducto(string codigo,string descripcion,float precio,int cantidad):DtProductoBase(codigo,descripcion){
    this->precio=precio;
	this->cantidad=cantidad;
}
float DtProducto::getPrecio(){
	return this->precio;
}
int DtProducto::getCantidad(){
	return this->cantidad;
}
DtProducto::~DtProducto(){}

ostream& operator <<(ostream& salida, const DtProducto& dtprod){
	cout << (DtProductoBase) dtprod << "Precio: " << dtprod.precio << "\nCantidad: " << dtprod.cantidad <<endl; 
	return salida;
}
