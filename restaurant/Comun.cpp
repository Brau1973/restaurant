#include "Comun.h"

Comun::Comun(){}

Comun::Comun(string codigo,string descripcion,float precio, TipoProducto tipoProducto):Producto(codigo,descripcion,precio){
    this->tipoProducto=tipoProducto;
}

TipoProducto Comun::getTipoProducto(){
    return this->tipoProducto;
}

void Comun::setTipoProducto(TipoProducto tipoProducto){
    this->tipoProducto=tipoProducto;
}

Comun::~Comun(){}