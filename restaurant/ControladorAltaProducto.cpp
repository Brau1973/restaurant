#include "ControladorAltaProducto.h"
#include "ManejadorProducto.h"
#include "Producto.h"
#include "DtProductoBase.h"
#include "DtProductoCantidad.h"
#include "Comun.h"
#include "Menu.h"
/*
list<DtProductoBase> ControladorAltaProducto::listarProductosComunes(){
    ManejadorProducto* mP=ManejadorProducto::getInstancia();
    list<Producto*> productos=mP->getProductos();
    list<DtProductoBase> dtProductos;
    TipoProducto tipoprod;
    //list<Comun*> comun = dynamic_cast<Comun*>(productos);
    list<Producto*>::iterator it;
    for(it=productos.begin(); it!=productos.end(); it++){  //Por cada producto (menu o comun) en Productos, iterar
        tipoprod = (*it)->getTipoProducto();
        if(tipoprod == TipoProducto::COMUN){
            DtProductoBase dtProdBaseAux=(*it)->getDtProductoBase();
            DtProductoBase* dtProdBase =new DtProductoBase(dtProdBaseAux.getCodigo(), dtProdBaseAux.getDescripcion());
            dtProductos.push_back(dtProdBase);
        }
        //Comun* comun = dynamic_cast<Comun*>((*it)); // puedo tratar este prod (menu o comun) como comun? (es comun?)
    }
    return dtProductos;
}
*/
list<DtProductoBase> ControladorAltaProducto::listarProductosComunes(){
  ManejadorProducto* mP = ManejadorProducto::getInstancia();
  list<Producto*> productos = mP->getProductos();
  list<DtProductoBase> dtProductos;
  TipoProducto tipoProd;
  Comun* comun;
  for(list<Producto*>::iterator it = productos.begin(); it != productos.end() ; ++it ){
      comun = dynamic_cast<Comun*>(*it);
      if(comun!=NULL){
         DtProductoBase dtprodbase = comun->getDtProductoBase(); 
          dtProductos.push_back(dtprodbase);
      }        
  }
  return dtProductos;
}
/*for (list<DtMascota*>::iterator it=dtMascotas.begin(); it != dtMascotas.end(); ++it){
			perro = dynamic_cast<DtPerro*>(*it);
			if (perro!=NULL)
				cout << "\n\n" << *(perro);
			else{
				gato = dynamic_cast<DtGato*>(*it);
				if (gato!=NULL)
					cout << "\n\n" << *(gato);	
			}
			cout << "-------------------------"<< endl;	
		}
*/

void ControladorAltaProducto::datosProductoComun(string cod,string desc,float precio){
    this->codComun=cod;
    this->descComun=desc;
    this->precioComun=precio;
}

void ControladorAltaProducto::confirmarProductoComun(){
    ManejadorProducto* mP=ManejadorProducto::getInstancia();
    Comun* comun=new Comun(this->codComun, this->descComun, this->precioComun, TipoProducto::COMUN);
    mP->agregarProducto(comun);
}

void ControladorAltaProducto::datosProductoMenu(string cod,string desc){
    this->codMenu=cod;
    this->descMenu=desc;
}

void ControladorAltaProducto::agregarAlProductoMenu(DtProductoCantidad* prodsComunesCantidad){
    this->productoComun.push_back(prodsComunesCantidad);
}

void ControladorAltaProducto::confirmarProductoMenu(){
    Menu* menu=new Menu(this->codMenu, this->descMenu,0,0,TipoProducto::MENU); //cantComunes=0, precio=0
    menu->agregarComunes(this->productoComun);
    menu->calcularPrecio();
    ManejadorProducto* mP=ManejadorProducto::getInstancia();
    mP->agregarProducto(menu);
}

void ControladorAltaProducto::cancelarProductoMenu(){

}

void ControladorAltaProducto::cancelarProductoComun(){
    
}