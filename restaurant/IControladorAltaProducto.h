#ifndef ICONTROLADOR_ALTA_PRODUCTO
#define ICONTROLADOR_ALTA_PRODUCTO
#include<string>
#include<list>
#include "DtProductoBase.h"
#include "DtProductoCantidad.h"

using namespace std;

class IControladorAltaProducto{
    public:
      virtual list<DtProductoBase> listarProductosComunes()=0;
      virtual void datosProductoComun(string, string, float)=0;
      virtual void cancelarProductoComun()=0;
      virtual void confirmarProductoComun()=0;
      virtual void datosProductoMenu(string, string)=0;
      virtual void agregarAlProductoMenu(DtProductoCantidad*)=0;
      virtual void cancelarProductoMenu()=0;
      virtual void confirmarProductoMenu()=0;
};

#endif