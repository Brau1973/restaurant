#include "ControladorAgregarProdAVenta.h"
#include "ManejadorMesa.h"
#include "ManejadorMozo.h"
#include "ManejadorProducto.h"

list<DtProductoBase> ControladorAgregarProdAVenta::listarProductos(){
    ManejadorProducto* mP=ManejadorProducto::getInstancia();
    list<Producto*> productos=mP->getProductos();
    list<DtProductoBase> dtProductos;
    list<Producto*>::iterator it;
    for(it=productos.begin(); it!=productos.end(); it++){
        //DtProductoBase dtProdBAux=(*it)->getDtProductoBase();
        //DtProductoBase* dtProdB=new DtProductoBase(dtProdBAux.getCodigo(), dtProdBAux.getDescripcion());
        dtProductos.push_back((*it)->getDtProductoBase());
    }
    return dtProductos;
}

void ControladorAgregarProdAVenta::seleccionarMesa(int idMesa){
    this->mesa=idMesa;
}

void ControladorAgregarProdAVenta::seleccionarProducto(DtProductoCantidad prodCant){
    this->productoVenta=prodCant;
}

void ControladorAgregarProdAVenta::confirmarAgregarProductoAVenta(){
    ManejadorMesa* mM=ManejadorMesa::getInstancia();
    Mesa* me=mM->getMesa(this->mesa);
    me->agregarProducto(this->productoVenta);
}

void ControladorAgregarProdAVenta::cancelarAgregarProductoAVenta(){

}