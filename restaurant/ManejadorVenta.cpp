#include "VentaLocal.h"
#include <list>
#include "ManejadorVenta.h"
using namespace std;

ManejadorVenta* ManejadorVenta::instancia = NULL;

ManejadorVenta::ManejadorVenta(){}

ManejadorVenta* ManejadorVenta::getInstancia(){
    if (instancia == NULL)
        instancia = new ManejadorVenta();
    return instancia;
}

list<VentaLocal*> ManejadorVenta::getVentas(){
    list<VentaLocal*> lstVentas;
    for (map<string,VentaLocal*>::iterator it=this->ventas.begin(); it!=ventas.end(); ++it)
        lstVentas.push_back(it->second);
    return lstVentas;
}
VentaLocal* ManejadorVenta::getVenta(string venta){
  map<string,VentaLocal*>::iterator it = this->ventas.find(venta);
  return it->second;
}

void ManejadorVenta::removerVenta(string venta){
    map<string,VentaLocal*>::iterator it = this->ventas.find(venta);
    this->ventas.erase(it);
}

void ManejadorVenta::agregarVenta(VentaLocal* venta){
    ventas.insert(std::pair<string,VentaLocal*>(venta->getCodigo(),venta));
}

ManejadorVenta::~ManejadorVenta(){}