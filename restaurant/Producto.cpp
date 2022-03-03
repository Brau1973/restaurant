#include "Producto.h"

Producto::Producto(){}
Producto::Producto(string codigo, string descripcion, float precio){
    this->codigo=codigo;
    this->descripcion=descripcion;
    this->precio=precio;
}
string Producto::getCodigo(){
    return this->codigo;
}
void Producto::setCodigo(string codigo){
    this->codigo=codigo;
}
string Producto::getDescripcion(){
    return this->descripcion;
}
void Producto::setDescripcion(string descripcion){
    this->descripcion=descripcion;
}
float Producto::getPrecio(){
    return this->precio;
}
void Producto::setPrecio(float precio){
    this->precio=precio;
}
Producto::~Producto(){}

DtProductoBase Producto::getDtProductoBase(){
    DtProductoBase dtpb=DtProductoBase(this->getCodigo(),this->getDescripcion());
    return dtpb;
}