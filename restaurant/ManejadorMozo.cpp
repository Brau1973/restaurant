#include "Mozo.h"
#include <list>
#include "ManejadorMozo.h"
using namespace std;

ManejadorMozo* ManejadorMozo::instancia = NULL;

ManejadorMozo::ManejadorMozo(){}

ManejadorMozo* ManejadorMozo::getInstancia(){
    if (instancia == NULL)
        instancia = new ManejadorMozo();
    return instancia;
}

list<Mozo*> ManejadorMozo::getMozos(){
    list<Mozo*> lstMozos;
    for (map<string,Mozo*>::iterator it=this->mozos.begin(); it!=mozos.end(); ++it)
        lstMozos.push_back(it->second);
    return lstMozos;
}
Mozo* ManejadorMozo::getMozo(string mozo){
  map<string,Mozo*>::iterator it = this->mozos .find(mozo);
  return it->second;
}


void ManejadorMozo::removerMozo(string mozo){
    map<string,Mozo*>::iterator it = this->mozos.find(mozo);
    this->mozos.erase(it);
}

void ManejadorMozo::agregarMozo(Mozo* mozo){
    mozos.insert(std::pair<string,Mozo*>(mozo->getIdMozo(),mozo));
}

ManejadorMozo::~ManejadorMozo(){}