#ifndef CONTROLADORAGREGARPRODAVENTA
#define CONTROLADORAGREGARPRODAVENTA
#include "Mesa.h" 
#include "Mozo.h"
#include "IControladorAgregarProdAVenta.h"
#include "DtProductoCantidad.h"
#include "DtProductoBase.h"
#include <list>
class ControladorAgregarProdAVenta: public IControladorAgregarProdAVenta{
    private:
        int mesa;
        DtProductoCantidad productoVenta;
    public:
        void seleccionarMesa(int);
        void seleccionarProducto(DtProductoCantidad);
        list<DtProductoBase> listarProductos();
        void confirmarAgregarProductoAVenta();
        void cancelarAgregarProductoAVenta();
   };
#endif
