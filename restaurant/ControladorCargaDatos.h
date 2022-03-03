#ifndef CONTROLADORCARGADATOS
#define CONTROLADORCARGADATOS
#include "DtAsignacion.h"
#include "Mesa.h"
#include "IControladorCargaDatos.h"
#include <list>
class ControladorCargaDatos: public IControladorCargaDatos{
    public:
        void registrarMozo(string,string,map<int,Mesa*>);
        void registrarMeza(int);
        void cargaDatos();
        void asignarMesasAMozos();
   };
#endif
