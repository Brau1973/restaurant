#ifndef CONTROLADOR_QUITAR_PRODUCTO
#define CONTROLADOR_QUITAR_PRODUCTO
#include "IControladorQuitarProducto.h"
#include <list>

class ControladorQuitarProducto: public IControladorQuitarProducto{
    private:
        int mesa;
        DtProductoCantidad productoVenta;
    public:
        list<DtProducto> listarProductos(int);
        void seleccionarProductoEliminar(DtProductoCantidad);
        void cancelarQuitarProducto();
        void confirmarQuitarProducto();
   };
#endif