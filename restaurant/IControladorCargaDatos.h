#ifndef ICONTROLADORCARGADATOS
#define ICONTROLADORCARGADATOS
#include "DtAsignacion.h" 
#include <list>
class IControladorCargaDatos{
    public:
        virtual void cargaDatos()=0;
        virtual void asignarMesasAMozos()=0;
   };
#endif