#include "DtProductoFactura.h"
DtProductoFactura::DtProductoFactura(){}
DtProductoFactura::DtProductoFactura(string descripcion,float precio,int cantidad){
	this->descripcion=descripcion;
    this->precio=precio;
	this->cantidad=cantidad;
}
string DtProductoFactura::getDescripcion(){
	return this->descripcion;
}
float DtProductoFactura::getPrecio(){
	return this->precio;
}
int DtProductoFactura::getCantidad(){
	return this->cantidad;
}

DtProductoFactura::~DtProductoFactura(){}

ostream& operator <<(ostream& salida, const DtProductoFactura& dtpf){
	cout << "Descripcion: " << dtpf.descripcion << "\n" 
        << "precio: " << dtpf.precio << "\n"
        << "cantidad: " << dtpf.cantidad << "\n"  
		<<endl;
	return salida;
}
