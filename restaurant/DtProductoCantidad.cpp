#include "DtProductoCantidad.h"
DtProductoCantidad::DtProductoCantidad(){}
DtProductoCantidad::DtProductoCantidad(string codigo,int cantidad){
	this->codigo=codigo;
	this->cantidad=cantidad;
}
string DtProductoCantidad::getCodigo(){
	return this->codigo;
}
int DtProductoCantidad::getCantidad(){
	return this->cantidad;
}
DtProductoCantidad::~DtProductoCantidad(){}

ostream& operator <<(ostream& salida, const DtProductoCantidad& dtpc){
	cout << "codigo: " << dtpc.codigo << "\n" 
		"cantidad: " << dtpc.cantidad << "\n" <<endl;
	return salida;
}
