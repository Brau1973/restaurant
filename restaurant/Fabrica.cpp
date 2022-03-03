#include "Fabrica.h"
#include "ControladorCargaDatos.h"
#include "ControladorAltaProducto.h"
#include "ControladorBajaProducto.h"
#include "ControladorFacturacion.h"
#include "ControladorIniciarVenta.h"
#include "ControladorAgregarProdAVenta.h"
#include "ControladorQuitarProducto.h"
#include "ControladorVerInfoProducto.h"

Fabrica* Fabrica::instancia = NULL;

Fabrica::Fabrica(){}

Fabrica* Fabrica::getInstancia(){
  if(instancia == NULL)
    instancia = new Fabrica();
  return instancia;
}
IControladorCargaDatos* Fabrica::getIControladorCargaDatos(){
  return new ControladorCargaDatos();
}

IControladorAltaProducto* Fabrica::getIControladorAltaProducto(){
  return new ControladorAltaProducto();
}

IControladorBajaProducto* Fabrica::getIControladorBajaProducto(){
  return new ControladorBajaProducto();
}

IControladorFacturacion* Fabrica::getIControladorFacturacion(){
	return new ControladorFacturacion();
}

IControladorIniciarVenta* Fabrica::getIControladorIniciarVenta(){
	return new ControladorIniciarVenta();
}

IControladorAgregarProdAVenta* Fabrica::getIControladorAgregarProdAVenta(){
	return new ControladorAgregarProdAVenta();
}

IControladorQuitarProducto* Fabrica::getIControladorQuitarProducto(){
	return new ControladorQuitarProducto();
}

IControladorVerInfoProducto* Fabrica::getIControladorVerInfoProducto(){
	return new ControladorVerInfoProducto();
}

Fabrica::~Fabrica(){}