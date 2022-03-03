#include "ProductoMenu.h"
ProductoMenu::ProductoMenu(){}
ProductoMenu::ProductoMenu(int cantidad){
	this->cantidad=cantidad;
}	
int ProductoMenu::getCantidad(){
	return this->cantidad;
}
void ProductoMenu::setCantidad(int cantidad){
	this->cantidad=cantidad;
}

ProductoMenu::~ProductoMenu(){}

string ProductoMenu::getCodigoComun(){
    return this->comun->getCodigo();
}

void ProductoMenu::asignarComun(string codigo){
    ManejadorProducto* mP=ManejadorProducto::getInstancia();
    Producto* prod = mP->getProducto(codigo);
    Comun* comun = dynamic_cast<Comun*>(prod);
    this->comun=comun;
}

float ProductoMenu::getPrecio(){
    return this->comun->getPrecio()*this->cantidad;
}