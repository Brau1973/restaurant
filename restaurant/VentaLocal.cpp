#include "VentaLocal.h"
int VentaLocal::autoGenerado = 0;
VentaLocal::VentaLocal(){}

VentaLocal::VentaLocal(Mozo* mozo){
    this->codigo=autoGenerado;
    this->mozo=mozo;
    autoGenerado++;
}

string VentaLocal::getCodigo(){
    return this->codigo;
}

void VentaLocal::setCodigo(string codigo){
    this->codigo=codigo;
}

VentaLocal::~VentaLocal(){}

bool VentaLocal::tieneElProducto(string cod){
    bool tiene=false;
    string codigo;
    list<VentaProducto*>::iterator it;
    if(!tiene){
        for(it=ventaProds.begin(); it!=ventaProds.end(); it++){
            codigo=(*it)->getCodigoProducto();
            if(codigo==cod)
                tiene = true;
        }
    }
    return tiene;
}

void VentaLocal::agregarProducto(DtProductoCantidad prodCant){
    ManejadorProducto* mP = ManejadorProducto::getInstancia();
    Producto* prod = mP->getProducto(prodCant.getCodigo());
    VentaProducto* vProd = new VentaProducto(prodCant.getCantidad(), prod);
    //this->ventaProds.insert(std::pair<int,VentaProducto*>(vProd->getCantidad(),vProd));
    this->ventaProds.push_back(vProd); //cambie insert por push back
}


list<DtProducto> VentaLocal::listarProductos(){
    list<DtProducto> dtProductos;
    list<VentaProducto*>::iterator it;
    for(it=ventaProds.begin(); it!= ventaProds.end(); it++){
        //DtProducto dtprod;
        //dtprod = (*it)->getDtProducto();
        //DtProducto* dtProd = new DtProducto(dtprod.getCodigo(),dtprod.getDescripcion(),dtprod.getPrecio(),dtprod.getCantidad());
        dtProductos.push_back((*it)->getDtProducto());
    }
    return dtProductos;
}


list<DtProductoFactura> VentaLocal::getDtProductoFactura(){
    list<DtProductoFactura> dtProdFact;
    list<VentaProducto*>::iterator it;
    for(it=ventaProds.begin(); it!= ventaProds.end(); it++){
        //DtProductoFactura dtProdFAux = (*it)->getDtProductoFactura();
        //DtProductoFactura* dtProdF = new DtProductoFactura(dtProdFAux.getDescripcion(),dtProdFAux.getPrecio(),dtProdFAux.getCantidad());
        dtProdFact.push_back((*it)->getDtProductoFactura());
    }
    return dtProdFact;
}

string VentaLocal::getNombreMozo(){
    return this->mozo->getNombre();
}

float VentaLocal::getSubTotalVenta(){
    float suma;
    list<VentaProducto*>::iterator it;
    for(it = ventaProds.begin(); it!= ventaProds.end(); it++){
        float costoItem = (*it)->getPrecioProductoEnVenta();
        suma=suma+costoItem;
    }
    return suma;
}

void VentaLocal::incrementar(DtProductoCantidad prodCant){
    list<VentaProducto*>::iterator it;
    for(it = ventaProds.begin(); it != ventaProds.end(); it++){
        string codigo = (*it)->getCodigoProducto();
        if(codigo==prodCant.getCodigo()){
            //(*it)->getCantidad()=(*it)->getCantidad()+prodCant.getCantidad();
            (*it)->incrementarCantidad(prodCant.getCantidad());
        }
    }
}

void VentaLocal::eliminarProducto(string codigo){
    for(auto it = ventaProds.begin(); it != ventaProds.end(); it++){
        string cod = (*it)->getCodigoProducto();
        if(cod == codigo){
            this->ventaProds.remove(*it);
            //delete (*it);
        }
    }
}

void VentaLocal::setFactura(Factura* factura){
    this->factura = factura;
}
