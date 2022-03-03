#ifndef DTPRODUCTO
#define DTPRODUCTO
#include "DtProductoBase.h"
class DtProducto: public DtProductoBase{
	private:
		float precio;
		int cantidad;
	public:
		DtProducto();
		DtProducto(string,string,float,int);
		float getPrecio();
		int getCantidad();
		~DtProducto();

		friend ostream& operator <<(ostream&, const DtProducto&);
};
#endif
