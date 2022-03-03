#include "DtFactura.h"
DtFactura::DtFactura(){}
DtFactura::DtFactura(string codVenta,DtFecha fechaEmision,list<DtProductoFactura> dtprodsfact,float subtotalVenta,float descuento,float montoTotalVenta,float montoTotalVentaConIVA,string nombreMozo){
	this->codVenta=codVenta;
	this->fechaEmision=fechaEmision;
    this->dtprodsfact=dtprodsfact;
    this->subtotalVenta=subtotalVenta;
    this->descuento=descuento;
    this->montoTotalVenta=montoTotalVenta;
    this->montoTotalVentaConIVA=montoTotalVentaConIVA;
    this->nombreMozo = nombreMozo;
}
string DtFactura::getCodigoVenta(){
	return this->codVenta;
}
DtFecha DtFactura::getFechaEmision(){
	return this->fechaEmision;
}
float DtFactura::getSubtotalVenta(){
	return this->subtotalVenta;
}
list<DtProductoFactura> DtFactura::getDtProdsFactura(){
	return this->dtprodsfact;
}
float DtFactura::getDescuento(){
	return this->descuento;
}
float DtFactura::getMontoTotalVenta(){
	return this->montoTotalVenta;
}
float DtFactura::getMontoTotalVentaConIVA(){
	return this->montoTotalVentaConIVA;
}
string DtFactura::getNombreMozo(){
    return this->nombreMozo;
}
DtFactura::~DtFactura(){}

/*ostream& operator <<(ostream& salida, const DtFactura& dtpb){
	cout << "Codigo: " << dtpb.codigo << "\n" 
		"Descripcion: " << dtpb.descripcion << "\n"<<endl;
	return salida;
}*/
