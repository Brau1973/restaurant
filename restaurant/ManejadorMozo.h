#ifndef MANEJADORMOZO
#define MANEJADORMOZO
class Mozo;
#include "Mozo.h"
#include <map>
#include <list>
#include <string>

using namespace std;

class ManejadorMozo{
    private:
        static ManejadorMozo* instancia;
        map<string,Mozo*> mozos;
        ManejadorMozo();
    public:
        static ManejadorMozo* getInstancia();
        list<Mozo*> getMozos();
        Mozo* getMozo(string);
        void removerMozo(string);
        void agregarMozo(Mozo*);
        virtual ~ManejadorMozo();
};
#endif