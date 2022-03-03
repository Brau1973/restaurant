#include "Producto.h"
#include <list>
#include "ManejadorProducto.h"
using namespace std;

ManejadorProducto* ManejadorProducto::instancia = NULL;

ManejadorProducto::ManejadorProducto(){}

ManejadorProducto* ManejadorProducto::getInstancia(){
    if (instancia == NULL)
        instancia = new ManejadorProducto();
    return instancia;
}

list<Producto*> ManejadorProducto::getProductos(){
    list<Producto*> lstProductos;
    for (map<string,Producto*>::iterator it=this->productos.begin(); it!=productos.end(); ++it)
        lstProductos.push_back(it->second);
    return lstProductos;
}
Producto* ManejadorProducto::getProducto(string producto){
  map<string,Producto*>::iterator it = this->productos.find(producto);
  return it->second;
}

void ManejadorProducto::removerProducto(string producto){
    map<string,Producto*>::iterator it = this->productos.find(producto);
    this->productos.erase(it);
}

void ManejadorProducto::agregarProducto(Producto* producto){
    productos.insert(std::pair<string,Producto*>(producto->getCodigo(),producto));
}

ManejadorProducto::~ManejadorProducto(){}