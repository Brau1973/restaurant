#include "ControladorBajaProducto.h"
#include "Producto.h"
#include "VentaLocal.h"
#include "Menu.h"
#include "Comun.h"
#include "ManejadorProducto.h"
#include "ManejadorVenta.h"

void ControladorBajaProducto::seleccionarProducto(string cod){
    this->codigo=cod;
}

list<DtProductoBase> ControladorBajaProducto::listarProductos(){
    ManejadorProducto* mP=ManejadorProducto::getInstancia();
    list<Producto*> productos=mP->getProductos();
    list<DtProductoBase> dtProductos;
    list<Producto*>::iterator it;
    for (it = productos.begin(); it != productos.end(); it++){
        //DtProductoBase dtProdBaseAux = (*it)->getDtProductoBase();
        //DtProductoBase* dtProdBase=new DtProductoBase(dtProdBaseAux.getCodigo(), dtProdBaseAux.getDescripcion());
        dtProductos.push_back((*it)->getDtProductoBase());
    }
    return dtProductos;
}

void ControladorBajaProducto::eliminarProducto(){
    ManejadorProducto* mP=ManejadorProducto::getInstancia();
    Producto* pro=mP->getProducto(this->codigo);
    ManejadorVenta* mV=ManejadorVenta::getInstancia();
    list<VentaLocal*> ventas=mV->getVentas();
    list<VentaLocal*>::iterator it;
    cout << "PRE ELIMINAR PRODUCTO DE VENTAS" <<endl;
    for(it=ventas.begin(); it!=ventas.end(); it++){
        (*it)->eliminarProducto(this->codigo);
    }
    cout << "POST ELIMINAR PRODUCTO DE VENTAS" <<endl;
	Comun* comun = dynamic_cast<Comun*>(pro);
    if(comun != NULL){
        cout << "PRODUCTO COMUN" <<endl;
		list<Producto*> productos=mP->getProductos();
        //list<Menu*> men;
        list<Producto*>::iterator iter;
        for(iter=productos.begin(); iter!=productos.end(); iter++){ //TODOS LOS PRODS DEL SISTEMA
            cout << "FOR TODOS LOS PRODUCTOS DEL SISTEMA" <<endl;
            Menu* menu = dynamic_cast<Menu*>(*iter); //ME INTERESAN SOLOS LOS MENUS // ESTOY HACIENDO ALGO SOLO SOBRE LOS MENUS
            if(menu!=NULL){
                cout << "ESTE PROD ES MENU" <<endl;
                int cant=menu->eliminarComun(comun, this->codigo);
                cout << "DESPUES DE ELIMINAR COMUN" <<endl;
                if(cant==0){
                    cout << "MENU QUEDO CON CANT 0" <<endl;
                    string codM=menu->getCodigo();
                    for(it=ventas.begin(); it!=ventas.end(); it++){
                        cout << "FOR TODAS LAS VENTAS EN EL SISTEMA" <<endl;
                        (*it)->eliminarProducto(codM);  
                        cout << "DESPUES DE ELIMINAR EL MENU DE UNA VENTA DADA" <<endl;
                    }
                    cout << "DESPUES DE ELIMINAR EL MENU DE TODAS LAS VENTAS" <<endl;
                    mP->removerProducto(menu->getCodigo());
                    cout << "DESPUES DE REMOVER EL MENU DEL MANEJADOR DE PRODUCTOS" <<endl;
                    delete menu;
                }
            }

        }
	}
    mP->removerProducto(pro->getCodigo());
    delete pro;
}

void ControladorBajaProducto::cancelarBajaProducto(){
    
}