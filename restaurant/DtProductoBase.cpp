#include "DtProductoBase.h"
DtProductoBase::DtProductoBase(){}
DtProductoBase::DtProductoBase(string codigo,string descripcion){
	this->codigo=codigo;
	this->descripcion=descripcion;
}
string DtProductoBase::getCodigo(){
	return this->codigo;
}
string DtProductoBase::getDescripcion(){
	return this->descripcion;
}
DtProductoBase::~DtProductoBase(){}

ostream& operator <<(ostream& salida, const DtProductoBase& dtpb){
	cout << "Codigo: " << dtpb.codigo << "\n" 
		"Descripcion: " << dtpb.descripcion << "\n"<<endl;
	return salida;
}
