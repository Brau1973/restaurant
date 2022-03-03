#ifndef CONTROLADOR_BAJA_PRODUCTO
#define CONTROLADOR_BAJA_PRODUCTO

#include "IControladorBajaProducto.h"

#include <list>
#include <string>
#include <iostream>
#include "DtProductoBase.h"

using namespace std;

class ControladorBajaProducto: public IControladorBajaProducto{
    private:
        string codigo;
    public:
        list<DtProductoBase> listarProductos();
        void seleccionarProducto(string);
        void cancelarBajaProducto();
        void eliminarProducto();
   };
#endif
