#ifndef DTFACTURA
#define DTFACTURA
#include<iostream>
#include"DtFecha.h"
#include"DtFechaHora.h"
#include"DtProductoFactura.h"
#include<list>
using namespace std;

class DtFactura{
	private:
        string codVenta;
        DtFecha fechaEmision;
        list <DtProductoFactura> dtprodsfact;
        float subtotalVenta;
        float descuento;
        float montoTotalVenta;
        float montoTotalVentaConIVA;
        string nombreMozo;
	public:
		DtFactura();
		DtFactura(string,DtFecha,list<DtProductoFactura>,float,float,float,float,string);
        list <DtProductoFactura> getDtProdsFactura();
		string getCodigoVenta();
		DtFecha getFechaEmision();
        float getSubtotalVenta();
        float getDescuento();
        float getMontoTotalVenta();
        float getMontoTotalVentaConIVA();
        string getNombreMozo();
		~DtFactura();

		friend ostream& operator<<(ostream&, const DtFactura&); 
};
#endif