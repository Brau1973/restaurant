#include "ControladorVerInfoProducto.h"
#include "Producto.h"
#include "Menu.h"
#include "Comun.h"
#include "ManejadorProducto.h"



list<DtProductoBase> ControladorVerInfoProducto::listarProductos(){
    ManejadorProducto* mP=ManejadorProducto::getInstancia();
    list<Producto*> productos=mP->getProductos();
    list<DtProductoBase> dtProductos;
    list<Producto*>::iterator it;
    for (it = productos.begin(); it != productos.end(); it++){
        //DtProductoBase dtProdBaseAux = (*it)->getDtProductoBase();
        //DtProductoBase* dtProdBase = new DtProductoBase(dtProdBaseAux.getCodigo(), dtProdBaseAux.getDescripcion());
        dtProductos.push_back((*it)->getDtProductoBase());
    }
    return dtProductos;
}

void ControladorVerInfoProducto::seleccionarProducto(string cod){
    this->codigo = cod;
}

void ControladorVerInfoProducto::infoProducto(){
    ManejadorProducto* mP = ManejadorProducto::getInstancia();
    Producto* prod = mP -> getProducto(this->codigo);
    this->codigo = prod->Producto::getCodigo();
    this->descripcion = prod->Producto::getDescripcion();
    cout <<"Codigo producto: " << this->codigo <<"\n" <<endl;
    cout <<"Decripcion: " << this->descripcion <<"\n" <<endl;
    TipoProducto tipo = prod -> getTipoProducto();
    if(tipo == TipoProducto::COMUN){
        this->precio = prod->Producto::getPrecio();
        cout <<"Precio: " << this->precio <<"\n" <<endl;
    }
    else{
        this->precio = prod->Producto::getPrecio();
        cout <<"Precio: " << this->precio <<"\n" <<endl;
        cout <<"Contenido del Menu: " << this->codigo <<"\n\t" <<endl;
        list<Producto*> pComunes = mP ->getProductos();
        list<Producto*>::iterator it;
        for(it=pComunes.begin(); it!=pComunes.end(); it++){ 
            this->codigo = (*it)->getCodigo();
            this->descripcion = (*it)->getDescripcion();
            cout <<"Contenido del Menu: "<< this->codigo << "\t" << this->descripcion <<"\n\t" <<endl;
        }      
    }
}