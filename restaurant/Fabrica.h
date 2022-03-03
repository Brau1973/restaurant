#ifndef FABRICA
#define FABRICA
#include "IControladorCargaDatos.h"
#include "IControladorAltaProducto.h"
#include "IControladorBajaProducto.h"
#include "IControladorFacturacion.h"
#include "IControladorIniciarVenta.h"
#include "IControladorAgregarProdAVenta.h"
#include "IControladorQuitarProducto.h"
#include "IControladorVerInfoProducto.h"

class Fabrica{
    private:
        static Fabrica* instancia;
        Fabrica();
    public:
        static Fabrica* getInstancia();
        IControladorCargaDatos* getIControladorCargaDatos();
        IControladorAltaProducto* getIControladorAltaProducto();
        IControladorBajaProducto* getIControladorBajaProducto();
        IControladorFacturacion* getIControladorFacturacion();
        IControladorIniciarVenta* getIControladorIniciarVenta();
        IControladorAgregarProdAVenta* getIControladorAgregarProdAVenta();
        IControladorQuitarProducto* getIControladorQuitarProducto();
        IControladorVerInfoProducto* getIControladorVerInfoProducto();
        
        ~Fabrica();
};
#endif
