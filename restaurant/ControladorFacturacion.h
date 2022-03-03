#ifndef CONTROLADOR_FACTURACION
#define CONTROLADOR_FACTURACION
#include "IControladorFacturacion.h"
#include <list>
#include <string>
#include <iostream>
class Mesa;

using namespace std;

class ControladorFacturacion: public IControladorFacturacion{
    public:
       DtFactura facturar(int,float);
       void fechaActual(int*) ;
   };
#endif
