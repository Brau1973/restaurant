#ifndef CONTROLADOR_VER_INFO_PRODUCTO
#define CONTROLADOR_VER_INFO_PRODUCTO
#include "IControladorVerInfoProducto.h"

#include <list>
#include <string>
#include <iostream>

using namespace std;

class ControladorVerInfoProducto: public IControladorVerInfoProducto{
    private:
        string codigo;
        string descripcion;
        float precio;
    public:
        list<DtProductoBase> listarProductos();
        void seleccionarProducto(string);
        void infoProducto();
   };
#endif