#ifndef MANEJADORMESA
#define MANEJADORMESA
class Mesa;
#include "Mesa.h"
#include <map>
#include <list>
#include <string>

using namespace std;

class ManejadorMesa{
    private:
        static ManejadorMesa* instancia;
        map<int,Mesa*> mesas;
        ManejadorMesa();
    public:
        static ManejadorMesa* getInstancia();
        map<int,Mesa*> getMesas();
        Mesa* getMesa(int);
        void removerMesa(int);
        void agregarMesa(Mesa*);
        virtual ~ManejadorMesa();
};
#endif