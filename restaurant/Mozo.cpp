#include "Mozo.h"
Mozo::Mozo(){}
Mozo::Mozo(string idMozo,string nombre){
	this->idMozo=idMozo;
	this->nombre=nombre;
}
string Mozo::getIdMozo(){
	return this->idMozo;
}
string Mozo::getNombre(){
	return this->nombre;
}
list<int> Mozo::getMesas(){
	list<int>mesasAsignadas;
	 for(map<int,Mesa*>::iterator it=this->mesas.begin(); it!=this->mesas.end(); ++it)
        mesasAsignadas.push_back(it->first);
	return mesasAsignadas;
}
void Mozo::setMesas(map<int,Mesa*> mesasASetear){
	for(map<int,Mesa*>::iterator it=mesasASetear.begin(); it!=mesasASetear.end(); ++it)
		this->mesas.insert(std::pair<int,Mesa*>(it->first,it->second));
}
void Mozo::asignarVentaAMesas(list<int>mesasAAsignar,VentaLocal* vL){
	for(auto& elm: mesasAAsignar){
		for(map<int,Mesa*>::iterator it=this->mesas.begin(); it!=this->mesas.end(); ++it){
			if(elm == it->first){
				Mesa* m= it->second;
				m->setVentaActual(vL);
			}
		}
	}
}
list<int> Mozo::mesasAsignadasSinVenta(){
	list<int> mesasSinVenta;
	for(map<int,Mesa*>::iterator it=this->mesas.begin(); it!=this->mesas.end(); ++it){
		bool tieneVenta;
		tieneVenta = it->second->tieneVenta(); 
		if(!tieneVenta){ //SINO TIENE VENTA ACTUAL
			int numeroMesa = ((*it).second)->getNumeroMesa();
			mesasSinVenta.push_back(numeroMesa);
		}
	}
	return mesasSinVenta;
}

Mozo::~Mozo(){}

ostream& operator <<(ostream& salida,const Mozo& mozo){
	cout << mozo.idMozo << "/" << mozo.nombre <<endl;
	return salida;
}