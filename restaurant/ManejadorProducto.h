#ifndef MANEJADORPRODUCTO
#define MANEJADORPRODUCTO
class Producto;
#include "Producto.h"
#include <map>
#include <list>
#include <string>

using namespace std;

class ManejadorProducto{
    private:
        static ManejadorProducto* instancia;
        map<string,Producto*> productos;
        ManejadorProducto();
    public:
        static ManejadorProducto* getInstancia();
        list<Producto*> getProductos();
        Producto* getProducto(string);
        void removerProducto(string);
        void agregarProducto(Producto*);
        virtual ~ManejadorProducto();
};
#endif