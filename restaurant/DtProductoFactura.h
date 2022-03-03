#ifndef DTPRODUCTOFACTURA
#define DTPRODUCTOFACTURA
#include<iostream>

using namespace std;

class DtProductoFactura{
	private:
		string descripcion;
        float precio;
        int cantidad;
	public:
		DtProductoFactura();
		DtProductoFactura(string,float,int);
		string getDescripcion();
		float getPrecio();
        int getCantidad();
		~DtProductoFactura();

		friend ostream& operator <<(ostream&, const DtProductoFactura&);
};
#endif
