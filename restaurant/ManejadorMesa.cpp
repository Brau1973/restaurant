#include "Mesa.h"
#include <list>
#include "ManejadorMesa.h"
using namespace std;

ManejadorMesa* ManejadorMesa::instancia = NULL;

ManejadorMesa::ManejadorMesa(){}

ManejadorMesa* ManejadorMesa::getInstancia(){
    if (instancia == NULL)
        instancia = new ManejadorMesa();
    return instancia;
}

map<int,Mesa*> ManejadorMesa::getMesas(){
    return this->mesas;
}

Mesa* ManejadorMesa::getMesa(int mesa){
  map<int,Mesa*>::iterator it = this->mesas.find(mesa);
  return it->second;
}

void ManejadorMesa::removerMesa(int mesa){
    map<int,Mesa*>::iterator it = this->mesas.find(mesa);
    this->mesas.erase(it);
}
void ManejadorMesa::agregarMesa(Mesa* mesa){
    mesas.insert(std::pair<int,Mesa*>(mesa->getNumeroMesa(),mesa));
}
ManejadorMesa::~ManejadorMesa(){}