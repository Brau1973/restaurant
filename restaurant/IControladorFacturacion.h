#ifndef ICONTROLADOR_FACTURACION
#define ICONTROLADOR_FACTURACION
#include<string>
#include "DtFactura.h"

using namespace std;

class IControladorFacturacion{
    public:
      virtual DtFactura facturar(int, float)=0;
};

#endif