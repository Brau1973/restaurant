#include "DtFechaHora.h"
DtFechaHora::DtFechaHora(){}
DtFechaHora::DtFechaHora(int dia,int mes,int anio,int hora,int min,int seg):DtFecha(dia,mes,anio){
    this->hora = hora;
	this->min = min;
    this->seg = seg;
}
int DtFechaHora::getHora(){
	return this->hora;
}
int DtFechaHora::getMin(){
	return this->min;
}
int DtFechaHora::getSeg(){
	return this->seg;
}
DtFechaHora::~DtFechaHora(){}

ostream& operator <<(ostream& salida, const DtFechaHora& dtfecha){
	cout << (DtFecha) dtfecha << "Hora: " << dtfecha.hora << "\nMin: " << dtfecha.min << "\nSeg: " << dtfecha.min << endl; 
	return salida;
}
