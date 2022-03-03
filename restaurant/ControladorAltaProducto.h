#ifndef CONTROLADOR_ALTA_PRODUCTO
#define CONTROLADOR_ALTA_PRODUCTO

#include "IControladorAltaProducto.h"
#include "DtProductoCantidad.h"
#include "DtProductoBase.h"

#include <list>
#include <string>
#include <iostream>

using namespace std;

class ControladorAltaProducto: public IControladorAltaProducto{
    private:
        string codMenu;
        string descMenu;
        list<DtProductoCantidad*> productoComun;
        string codComun;
        string descComun;
        float precioComun;
    public:
        list<DtProductoBase> listarProductosComunes();
        void datosProductoComun(string,string,float);
        void cancelarProductoComun();
        void confirmarProductoComun();
        void datosProductoMenu(string,string);
        void agregarAlProductoMenu(DtProductoCantidad*);
        void cancelarProductoMenu();
        void confirmarProductoMenu();
   };
#endif
