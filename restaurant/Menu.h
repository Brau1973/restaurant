#ifndef MENU_H
#define MENU_H

#include "DtProductoCantidad.h"
#include "TipoProducto.h"
#include "Producto.h"
#include "ProductoMenu.h"
#include "Comun.h"

#include <list>
#include <string>
#include<iostream>

using namespace std;

class Menu: public Producto{
	private:
		int cantComunes;
        TipoProducto tipoProducto;
        list<ProductoMenu*> prodMenu;
        list<DtProductoCantidad*> prodCom;
	public:
		Menu();
		Menu(string,string,float,int,TipoProducto);
		int getCantComunes();
		void setCantComunes(int);
		TipoProducto getTipoProducto();
        void setTipoProducto(TipoProducto);
        ~Menu();

        int eliminarComun(Comun*,string);
        void decrementarCantComunes();
        void agregarComunes(list<DtProductoCantidad*>);
        void calcularPrecio();
        void incrementarPrecio(float);
        void aplicarDescuento();
        void incrementarCantComunes();
};
#endif