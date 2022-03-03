#ifndef VENTALOCAL
#define VENTALOCAL

#include <map>
#include <iostream>
#include <string>
#include <list>
#include "DtProductoFactura.h"
#include "DtProductoCantidad.h"
#include "DtProducto.h"
#include "VentaProducto.h"
#include "Mozo.h"
class Mozo;
#include "ManejadorProducto.h"
#include "Factura.h"
using namespace std;

class VentaLocal{
        private:
                string codigo;
                list<VentaProducto*> ventaProds;
                Mozo* mozo;
                static int autoGenerado;
                Factura* factura;
        public:
                VentaLocal();
                VentaLocal(Mozo*);
                string getCodigo();
                void setCodigo(string);
                ~VentaLocal();
                void setFactura(Factura*);

                void eliminarProducto(string);
                bool tieneElProducto(string);
                void agregarProducto(DtProductoCantidad);
                void incrementar(DtProductoCantidad);
                list<DtProducto> listarProductos();
                string getNombreMozo();
                float getSubTotalVenta();
                list<DtProductoFactura> getDtProductoFactura();
};
#endif