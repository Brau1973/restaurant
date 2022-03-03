#ifndef ICONTROLADOR_VER_INFO_PRODUCTO
#define ICONTROLADOR_VER_INFO_PRODUCTO
#include "DtProductoBase.h"
#include <string>
#include <list>

using namespace std;

class IControladorVerInfoProducto{
    public:
        virtual list<DtProductoBase> listarProductos()=0;
        virtual void seleccionarProducto(string)=0;
        virtual void infoProducto()=0;
};

#endif