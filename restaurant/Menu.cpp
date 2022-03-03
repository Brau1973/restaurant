#include "Menu.h"
Menu::Menu(){}

Menu::Menu(string codigo,string descripcion,float precio,int cantComunes,TipoProducto tipoProducto):Producto(codigo,descripcion,precio){
    this->cantComunes=cantComunes;
    this->tipoProducto=tipoProducto;
}

int Menu::getCantComunes(){
	return this->cantComunes;
}

void Menu::setCantComunes(int cantComunes){
	this->cantComunes=cantComunes;
}

TipoProducto Menu::getTipoProducto(){
    return this->tipoProducto;
}

void Menu::setTipoProducto(TipoProducto tipoProducto){
    this->tipoProducto=tipoProducto;
}

Menu::~Menu(){}

int Menu::eliminarComun(Comun* comun, string codigo){
    list<ProductoMenu*>::iterator it;
    for(it=prodMenu.begin(); it!=prodMenu.end(); it++){
        string cod = (*it)->getCodigoComun();
        if(cod==codigo){
            this->prodMenu.remove((*it));
            delete (*it);
            this->decrementarCantComunes();
        }
    }
    int cant=getCantComunes();
    return cant;
}

void Menu::decrementarCantComunes(){
    this->cantComunes--;
}

void Menu::incrementarCantComunes(){
    this->cantComunes++;
}

void Menu::incrementarPrecio(float precio){
    float total = this->getPrecio() + precio;
    this->setPrecio(total);
}

void Menu::aplicarDescuento(){
    float total = this->getPrecio() * 0.90;
    this->setPrecio(total);
}

void Menu::calcularPrecio(){
    list<ProductoMenu*>::iterator it;
    for(it=this->prodMenu.begin(); it!=this->prodMenu.end(); it++){
        float precioCom=(*it)->getPrecio();
        this->incrementarPrecio(precioCom);
    }
    this->aplicarDescuento();
}

void Menu::agregarComunes(list<DtProductoCantidad*> productosComun){
    list<DtProductoCantidad*>::iterator it;
    for(it=productosComun.begin(); it!=productosComun.end(); it++){
        ProductoMenu* pM=new ProductoMenu((*it)->getCantidad());
        pM->asignarComun((*it)->getCodigo());
        this->prodMenu.push_back(pM);
        this->incrementarCantComunes();
    }
}
