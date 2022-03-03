#include "VentaProducto.h"

VentaProducto::VentaProducto(){}

VentaProducto::VentaProducto(int cantidad, Producto* producto){
    this->cantidad=cantidad;
    this->producto=producto;
}

int VentaProducto::getCantidad(){
    return this->cantidad;
}

void VentaProducto::setCantidad(int cantidad){
    this->cantidad=cantidad;
}

Producto* VentaProducto::getProducto(){
    return this->producto;
}

void VentaProducto::setProducto(Producto* producto){
    this->producto=producto;
}

VentaProducto::~VentaProducto(){}

string VentaProducto::getCodigoProducto(){
    return this->producto->getCodigo();
}

void VentaProducto::incrementarCantidad(int cantidad){
    this->cantidad = this->cantidad + cantidad;
}

DtProducto VentaProducto::getDtProducto(){
    float precio = this->producto->getPrecio();
    string desc = this->producto->getDescripcion();
    string cod = this->producto->getCodigo();
    int cant = this->getCantidad();
    DtProducto dtProd = DtProducto(cod,desc,precio,cant);
    return dtProd;
}

int VentaProducto::decrementarCantidad(int cantidad){
    this->cantidad = this->cantidad - cantidad;
    return this->cantidad;
}

DtProductoFactura VentaProducto::getDtProductoFactura(){
    float precio = this->producto->getPrecio();
    string desc = this->producto->getDescripcion();
    int cant = this->getCantidad();
    DtProductoFactura dtProdFact = DtProductoFactura(desc,precio,cant);
    return dtProdFact;
}

float VentaProducto::getPrecioProductoEnVenta(){
    float precio = this->producto->getPrecio();
    return this->cantidad * precio;
}
