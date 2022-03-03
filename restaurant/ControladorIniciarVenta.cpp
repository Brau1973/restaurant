#include "ControladorIniciarVenta.h"
#include "Mesa.h"
#include "Mozo.h"
#include "ManejadorMozo.h"
#include "ManejadorVenta.h"
#include "VentaLocal.h"

list<int> ControladorIniciarVenta::ingresarIdMozo(string idMozo){
    this->mozo=idMozo;
    ManejadorMozo* mM=ManejadorMozo::getInstancia();
    Mozo* mo=mM->getMozo(idMozo);
    list<int> lstMesas=mo->mesasAsignadasSinVenta();
    return lstMesas;
}

list<int> ControladorIniciarVenta::seleccionarMesas(list<int> mMesas){
    this->mesas=mMesas;
    return mMesas;
}

string ControladorIniciarVenta::confirmarIniciarVenta(){
    ManejadorMozo* mM=ManejadorMozo::getInstancia();
    Mozo* mo=mM->getMozo(this->mozo);
    VentaLocal* vL=new VentaLocal(mo);
    mo->asignarVentaAMesas(this->mesas,vL);
    ManejadorVenta* mV=ManejadorVenta::getInstancia();
    mV->agregarVenta(vL);
    return vL->getCodigo();
}

void ControladorIniciarVenta::cancelarIniciarVenta(){
    this->mesas.clear();
}