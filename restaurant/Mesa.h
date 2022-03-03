#ifndef MESA
#define MESA
#include "DtProductoCantidad.h"
#include "DtProducto.h"
class VentaLocal;
#include "VentaLocal.h"
#include <list>
#include <map>
#include <iostream>

using namespace std;

class Mesa{
        private:
                int numeroMesa;
                VentaLocal* ventaActual;
        public:
                Mesa();
                Mesa(int);
                int getNumeroMesa();
                void setNumeroMesa(int);
                void setVentaActual(VentaLocal*);
                VentaLocal* getVentaActual();
                ~Mesa();

                bool tieneVenta();
                void agregarProducto(DtProductoCantidad);
                void quitarProducto(DtProductoCantidad);
                list<DtProducto> listarProductos();
};
#endif