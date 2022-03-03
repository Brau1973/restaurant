#include "Mesa.h"

Mesa::Mesa(){}
Mesa::Mesa(int NumeroMesa){
  this->numeroMesa=NumeroMesa;
}

int Mesa::getNumeroMesa(){
  return this->numeroMesa;
}
void Mesa::setNumeroMesa(int NumeroMesa){
  this->numeroMesa=NumeroMesa;
}
void Mesa::setVentaActual(VentaLocal* ventaAct){
  this->ventaActual = ventaAct;
}
VentaLocal* Mesa::getVentaActual(){
  return this->ventaActual;
}

Mesa::~Mesa(){}

bool Mesa::tieneVenta(){
  VentaLocal* vL=this->getVentaActual();
  bool tieneVenta;

  if(vL == NULL)
    return false;
  else
    return true; 
}

list<DtProducto> Mesa::listarProductos(){
  list<DtProducto> dtProductos=this->ventaActual->listarProductos();
  return dtProductos;
}

void Mesa::agregarProducto (DtProductoCantidad pc){
  bool tieneElProducto = this->ventaActual->tieneElProducto(pc.getCodigo());
  if(tieneElProducto)
    this->ventaActual->incrementar(pc);
  else
    this->ventaActual->agregarProducto(pc);
}

void Mesa::quitarProducto(DtProductoCantidad pc){
    this->ventaActual->eliminarProducto(pc.getCodigo());
}
