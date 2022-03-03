#ifndef ICONTROLADORAGREGARPRODAVENTA
#define ICONTROLADORAGREGARPRODAVENTA
#include "Mesa.h"
#include "IControladorAgregarProdAVenta.h"
#include "DtProductoCantidad.h"
#include "DtProductoBase.h"
#include <list>
class IControladorAgregarProdAVenta{
    public:
        virtual void seleccionarMesa(int)=0;
        virtual void seleccionarProducto(DtProductoCantidad)=0;
        virtual list<DtProductoBase> listarProductos()=0;
        virtual void confirmarAgregarProductoAVenta()=0;
        virtual void cancelarAgregarProductoAVenta()=0;
   };
#endif
