#ifndef FACTURA
#define FACTURA
#include<iostream>
#include"DtFechaHora.h"
#include"DtProductoFactura.h"
#include <list>
using namespace std;

class Factura{
	private:
        float subTotal;
        list<DtProductoFactura> dtprodsfact;
        float descuento;
	public:
		Factura();
		Factura(float,list<DtProductoFactura>,float);
        float getSubtotalVenta();
        list<DtProductoFactura> getDtProductosFactura();
        float getDescuento();
		~Factura();

		friend ostream& operator<<(ostream&, const Factura&); 
};
#endif