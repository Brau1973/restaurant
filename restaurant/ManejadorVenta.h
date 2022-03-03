#ifndef MANEJADORVENTA
#define MANEJADORVENTA
class VentaLocal;
#include "VentaLocal.h"
#include <map>
#include <list>
#include <string>

using namespace std;

class ManejadorVenta{
    private:
        static ManejadorVenta* instancia;
        map<string,VentaLocal*> ventas;
        ManejadorVenta();
    public:
        static ManejadorVenta* getInstancia();
        list<VentaLocal*> getVentas();
        VentaLocal* getVenta(string);
        void removerVenta(string);
        void agregarVenta(VentaLocal*);
        virtual ~ManejadorVenta();
};
#endif