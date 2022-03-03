#include "DtAsignacion.h"
DtAsignacion::DtAsignacion(){}
DtAsignacion::DtAsignacion(string idMozo,string nombreMozo,list<int>mesas){
	this->idMozo=idMozo;
	this->nombreMozo = nombreMozo;
	this->mesas=mesas;
}
string DtAsignacion::getIdMozo(){
	return this->idMozo;
}
/*
list<string> DtAsignacion::getMesas(){
	return this->mesas;
}
*/
DtAsignacion::~DtAsignacion(){}

ostream& operator <<(ostream& salida, const DtAsignacion& dtasign){
	cout << "IdMozo: " << dtasign.idMozo << "\n" ;
	cout << "Nombre Mozo: " << dtasign.nombreMozo << "\n" ;
	list<int> aux = dtasign.mesas;
	cout << "Mesas: ";
	for (list<int>::iterator it = aux.begin() ; it != aux.end(); ++it)
		cout << *it << "  " ;
	return salida;
}
