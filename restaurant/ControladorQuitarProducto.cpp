#include "ControladorQuitarProducto.h"
#include "DtProductoCantidad.h"
#include "DtProducto.h"
#include "Mesa.h"
#include "ManejadorMesa.h"

list<DtProducto> ControladorQuitarProducto::listarProductos(int idMesa){
    this->mesa=idMesa;
    ManejadorMesa* mM=ManejadorMesa::getInstancia();
    Mesa* me=mM->getMesa(idMesa);
    list<DtProducto> dtProductos=me->listarProductos();
    return dtProductos;    
}

void ControladorQuitarProducto::seleccionarProductoEliminar(DtProductoCantidad prodCant){
    this->productoVenta=prodCant;
}

void ControladorQuitarProducto::confirmarQuitarProducto(){
    cout <<"ENTRE A confirmarQuitarProducto" <<endl;
    ManejadorMesa* mM=ManejadorMesa::getInstancia();
    cout <<"ManejadorMesa::getInstancia" <<endl;
    Mesa* me=mM->getMesa(this->mesa);

    me->quitarProducto(this->productoVenta);

}

void ControladorQuitarProducto::cancelarQuitarProducto(){

}