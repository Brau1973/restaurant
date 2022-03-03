#ifndef COMUN_H
#define COMUN_H

#include "Producto.h"
#include "TipoProducto.h"
#include <string>

#include<iostream>

using namespace std;

class Comun: public Producto{
        private:
                TipoProducto tipoProducto;
	public:
                Comun();
                Comun(string,string,float,TipoProducto);
                TipoProducto getTipoProducto();
                void setTipoProducto(TipoProducto);
                ~Comun();
};
#endif