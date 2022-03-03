#include "Factura.h"
Factura::Factura(){}
Factura::Factura(float subtotalVenta,list <DtProductoFactura> dtprodsfact,float descuento){
    this->dtprodsfact=dtprodsfact;
    this->subTotal=subtotalVenta;
    this->descuento=descuento;
}
float Factura::getSubtotalVenta(){
	return this->subTotal;
}
list<DtProductoFactura> Factura::getDtProductosFactura(){
	return this->dtprodsfact;
}
float Factura::getDescuento(){
	return this->descuento;
}
Factura::~Factura(){}

/*ostream& operator <<(ostream& salida, const Factura& dtpb){
	cout << "Codigo: " << dtpb.codigo << "\n" 
		"Descripcion: " << dtpb.descripcion << "\n"<<endl;
	return salida;
}*/
