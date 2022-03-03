#ifndef ICONTROLADOR_BAJA_PRODUCTO
#define ICONTROLADOR_BAJA_PRODUCTO
#include<string>
#include<list>
#include "DtProductoBase.h"

using namespace std;

class IControladorBajaProducto{
    public:
      virtual list<DtProductoBase> listarProductos()=0;
      virtual void seleccionarProducto(string)=0;
      virtual void cancelarBajaProducto()=0;
      virtual void eliminarProducto()=0;
};

#endif