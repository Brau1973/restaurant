#ifndef ICONTROLADOR_QUITAR_PRODUCTO
#define ICONTROLADOR_QUITAR_PRODUCTO
#include<string>
#include <iostream>
#include <list>
#include "DtProducto.h"
#include "DtProductoCantidad.h"

using namespace std;

class IControladorQuitarProducto{
    public:
      virtual list<DtProducto> listarProductos(int)=0;
      virtual void seleccionarProductoEliminar(DtProductoCantidad)=0;
      virtual void cancelarQuitarProducto()=0;
      virtual void confirmarQuitarProducto()=0;
};

#endif