#include "ControladorFacturacion.h"
#include "DtFactura.h"
#include "ManejadorMesa.h"
#include "Mesa.h"
#include "DtProducto.h"
#include "Factura.h"

DtFactura ControladorFacturacion::facturar(int idMesa, float descuento){
    ManejadorMesa* mM=ManejadorMesa::getInstancia();
    Mesa* mesa;
    VentaLocal* venta;
    string nombreMozo;
    mesa = mM->getMesa(idMesa);
    venta = mesa->getVentaActual();
    list<DtProductoFactura> dtprodsFactura = venta->getDtProductoFactura();
    float subTotal = venta->getSubTotalVenta();
    Factura* factura = new Factura(subTotal,dtprodsFactura,descuento);
    string codVenta = venta->getCodigo();
    venta->setFactura(factura);
    nombreMozo = venta->getNombreMozo();
    float montoTotal = (subTotal*(1-descuento));
    float montoTotalVentaConIVA = montoTotal * 1.22;

    int currentTime[3];
    fechaActual(currentTime);
    DtFecha fechaIngreso = DtFecha(currentTime[0],currentTime[1],currentTime[2]);
    DtFactura dtfactura = DtFactura(codVenta,fechaIngreso,dtprodsFactura,subTotal,descuento,montoTotal,montoTotalVentaConIVA,nombreMozo);
    mesa->setVentaActual(NULL);
    return dtfactura;
}

void ControladorFacturacion::fechaActual(int * fecha){
    int dia,mes,anio;
	time_t now = time(0);
	tm *ltm = gmtime(&now);

	//hay que sumarle 1900 al anio y 1 al mes ya que el struct tm guarda los anios a partir del 1900 y los meses de 0 al 11
	dia = ltm->tm_mday;
	mes = ltm->tm_mon +1;
	anio = ltm->tm_year +1900;

	fecha[0]=dia;
	fecha[1]=mes;
	fecha[2]=anio;
}