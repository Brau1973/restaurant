#ifndef VENTAPRODUCTO
#define VENTAPRODUCTO

#include <iostream>
#include <string>
#include "Producto.h"
#include "DtProductoFactura.h"
#include "DtProducto.h"


using namespace std;

class VentaProducto{
        private:
                int cantidad;
                Producto* producto;
        public:
                VentaProducto();
                VentaProducto(int,Producto*);
                int getCantidad();
                void setCantidad(int);
                Producto* getProducto();
                void setProducto(Producto*);
                ~VentaProducto();

                string getCodigoProducto();
                void incrementarCantidad(int);
                int decrementarCantidad(int);
                DtProductoFactura getDtProductoFactura();
                float getPrecioProductoEnVenta();
                DtProducto getDtProducto();
};
#endif