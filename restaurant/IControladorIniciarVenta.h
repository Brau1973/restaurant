#ifndef ICONTROLADOR_INICIAR_VENTA
#define ICONTROLADOR_INICIAR_VENTA
#include "Mesa.h"
#include<string>
#include<list>
#include<map>

using namespace std;

class IControladorIniciarVenta{
    public:
      virtual list<int> ingresarIdMozo(string)=0;
      virtual list<int> seleccionarMesas(list<int>)=0;
      virtual void cancelarIniciarVenta()=0;
      virtual string confirmarIniciarVenta()=0;
};

#endif