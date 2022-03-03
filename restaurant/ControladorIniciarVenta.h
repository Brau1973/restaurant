#ifndef CONTROLADOR_INICIAR_VENTA
#define CONTROLADOR_INICIAR_VENTA
#include "IControladorIniciarVenta.h"

#include <list>
#include <map>
#include <string>
#include <iostream>

using namespace std;

class ControladorIniciarVenta: public IControladorIniciarVenta{
    private:
        string mozo;
        list<int> mesas;
    public:
        list<int> ingresarIdMozo(string);
        list<int> seleccionarMesas(list<int>);
        void cancelarIniciarVenta();
        string confirmarIniciarVenta();
   };
#endif