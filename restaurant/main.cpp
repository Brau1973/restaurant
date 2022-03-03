#include"DtAsignacion.h"
#include"DtFactura.h"
#include"DtFecha.h"
#include"DtFechaHora.h"
#include"DtProducto.h"
#include"DtProductoBase.h"
#include"DtProductoCantidad.h"
#include"DtProductoFactura.h"
#include"DtAsignacion.h"
#include"DtFactura.h"
#include"DtFecha.h"
#include"DtFechaHora.h"
#include"DtProducto.h"
#include"DtProductoBase.h"
#include"DtProductoCantidad.h"
#include"DtProductoFactura.h"
#include"Mesa.h"
#include"Mozo.h"
#include <ctime>
#include <iomanip>
#include <iostream>

#include "Fabrica.h"
#include "IControladorCargaDatos.h"
#include "IControladorAgregarProdAVenta.h"
#include "IControladorAltaProducto.h"
#include "IControladorBajaProducto.h"
#include "IControladorIniciarVenta.h"
#include "IControladorQuitarProducto.h"
#include "IControladorVerInfoProducto.h"
#include "IControladorFacturacion.h"

Fabrica* fabrica;
IControladorCargaDatos* icon;
void fechaActual(int * fecha);

//OPERACION A
void altaProducto();
//OPERACION B
void iniciarVenta();
//OPRACION C
void agregarProductoAVenta();
//OPERACION D
void quitarProductoAVenta();
//OPERACION E
void facturacionDeUnaVenta();
//OPERACION F
void bajaProducto();
//OPERACION G
void cargarDatosDePrueba();

//OPERACION A
void altaProducto(){
    cout <<"__________________________________" << endl;
    cout <<"_____A L T A__P R O D U C T O_____\n" << endl;
    fabrica = Fabrica::getInstancia();
    IControladorAltaProducto* icon = fabrica->getIControladorAltaProducto();
    string codMenu,descMenu,codComun,descComun;
    float precioComun; 
    int opTipoProd, opSwitch, cant;
    int opMenu=0;
    bool existe;
    TipoProducto tipoProd;
    ManejadorProducto* mp = ManejadorProducto::getInstancia();
    list<Producto*> productos = mp->getProductos();
    bool hayProds = productos.empty();
    if(!hayProds){
        cout << endl <<"QUE TIPO DE PRODUCTO DESEA AGREGAR?:" << endl << "\t1.Comun\n\t2.Menu"<<endl<<"INDIQUE: ";
        cin >> opTipoProd;
        switch(opTipoProd){
            case 1: tipoProd=TipoProducto::COMUN;
                break;
            case 2: tipoProd=TipoProducto::MENU;
                break;
            default:
                cout << "OPCION INCORRECTA" << endl;
        }
        if(tipoProd==TipoProducto::COMUN){
            cout << "\n-----DATOS PRODUCTO COMUN:-----\n";
            cout << "-CODIGO: ";
            cin >> codComun;
            cout << "-DESCRIPCION: ";
            cin >> descComun;
            cout << "-PRECIO: ";
            cin >> precioComun;
            icon->datosProductoComun(codComun,descComun,precioComun);
            cout << "\n----- DATOS CARGADOS CON EXITO. -----" << endl;
            cout << "Desea confirmar el alta?:" << endl;
            cout << "1 - Si" << "\n" << "2 - No" << endl;
            cin >> opSwitch;
            while(opSwitch != 1 && opSwitch != 2){
                cout << "Opcion invalida" << endl;
                cin >> opSwitch;
            }
            switch (opSwitch)
            {
            case 1:
                icon->confirmarProductoComun();
                cout << "----- Alta realizada con exito -----" << endl;
                cout << "----- Datos del producto: -----" ;
                cout << "\nCodigo: "<< codComun << "\nDescripcion: " << descComun << "\nPrecio: " << precioComun << endl;
                break;
            case 2:
                icon->cancelarProductoComun();
                cout << "Alta Producto CANCELADO" << endl;
                break;
            }
        }else{
            cout << "----- DATOS PRODUCTO MENU: -----" << endl;
            cout << "CODIGO: ";
            cin >> codMenu;
            cout << "DESCRIPCION: ";
            cin >> descMenu;
            icon->datosProductoMenu(codMenu,descMenu);
            cout << "\n----- DATOS CARGADOS CON EXITO. -----" << endl;
            cout << "\n ----- LISTADO DE PRODUCTOS COMUNES: -----\n";
            list<DtProductoBase> productos = icon->listarProductosComunes();
            list<DtProductoBase>::iterator it;
            for(it=productos.begin(); it!=productos.end(); it++){
                cout << *it << endl;
            }
            while(opMenu!=2){
                cout << "Seleccione los productos a agregar al Menu: \n-Codigo: ";
                cin >> codComun;
                string codAComparar;
                existe = false;
                for(it=productos.begin(); it!=productos.end(); it++){
                    codAComparar = it->getCodigo();
                    if(codAComparar == codComun)
                        existe=true;
                }
                if(existe==true){
                    cout << "Ingrese la cantidad a agregar: ";
                    cin >> cant;
                    DtProductoCantidad* dtProdCant = new DtProductoCantidad(codComun,cant);
                    //prodsComunesCantidad.push_back(dtProdCant);
                    icon->agregarAlProductoMenu(dtProdCant);
                }else{
                    cout << "No existe un producto con ese codigo.\n";
                }
                cout << "Desea seguir agregando?" << endl;
                cout << "1 - Si" << "\n" << "2 - No" << endl;
                cin >> opMenu;
            }
            cout << "Desea confirmar el alta?:" << endl;
            cout << "1 - Si" << "\n" << "2 - No" << endl;
            cin >> opSwitch;
            while(opSwitch != 1 && opSwitch != 2){
                cout << "Opcion invalida" << endl;
                cin >> opSwitch;
            }
            switch (opSwitch)
            {
            case 1:
                icon->confirmarProductoMenu();
                cout << "----- Alta realizada con exito -----" << endl;
                cout << "----- Datos del producto: -----" ;
                cout << "\nCodigo: "<< codMenu << "\nDescripcion: " << descMenu << endl;
                break;
            case 2:
                icon->cancelarProductoMenu();
                cout << "Alta Producto CANCELADO" << endl;
                break;
            }
    }
    }else{ //NO HAY PRODS
        // cout << endl <<"PRODUCTO A AGREGAR?:" << endl << "\t1.Comun\n"<<endl<<"INDIQUE: ";
        // cin >> opTipoProd;
        // switch(opTipoProd){
        //     case 1: tipoProd=TipoProducto::COMUN;
        //         break;
        //     default:
        //         cout << "OPCION INCORRECTA" << endl;     
        // }
        tipoProd=TipoProducto::COMUN;
        if(tipoProd==TipoProducto::COMUN){
            cout << "----- DATOS PRODUCTO COMUN: -----\n";
            cout << "-CODIGO: ";
            cin >> codComun;
            cout << "-DESCRIPCION: ";
            cin >> descComun;
            cout << "-PRECIO: ";
            cin >> precioComun;
            icon->datosProductoComun(codComun,descComun,precioComun);
            cout << "\n----- DATOS CARGADOS CON EXITO. -----" << endl;
            cout << "Desea confirmar el alta?:" << endl;
            cout << "1 - Si" << "\n" << "2 - No" << endl;
            cin >> opSwitch;
            while(opSwitch != 1 && opSwitch != 2){
                cout << "Opcion invalida" << endl;
                cin >> opSwitch;
            }
            switch (opSwitch)
            {
            case 1:
                icon->confirmarProductoComun();
                cout << "----- Alta realizada con exito -----" << endl;
                cout << "----- Datos del producto: -----" ;
                cout << "\nCodigo: "<< codComun << "\nDescripcion: " << descComun << "\nPrecio: " << precioComun << endl;
                break;
            case 2:
                icon->cancelarProductoComun();
                cout << "Alta Producto CANCELADO" << endl;
                break;
            }
        }
    }
}
//OPERACION B
void iniciarVenta(){
    string idMozo;
    list<int> mesasDelMozo;
    fabrica = Fabrica::getInstancia();
    IControladorIniciarVenta* icon = fabrica->getIControladorIniciarVenta(); 
    
    cout <<"__________________________________" << endl;
    cout <<"_____I N I C I A R__V E N T A_____" << endl;

    cout <<"Ingrese su identificador" << endl;
    cin >> idMozo ;
    mesasDelMozo = icon->ingresarIdMozo(idMozo);

    if(!mesasDelMozo.empty()){

        cout << "Sus mesas sin una venta son:" << endl;
        for (auto& elm: mesasDelMozo ){ //muestro las mesas del mozo
            cout << elm << " // " ;
        }
        cout << "\n";
        cout << "Seleccione las mesas que participaran de esta nueva venta:" << endl;
        cout << "(Ingrese el numero de mesa luego presione 'Enter' y asi sucesivamente)"<<endl;
        cout << "(Para marcar el final de la seleccion, ingrese 0 y 'Enter)'" <<endl;
        int numMesa = 5;
        list<int> mesasSeleccionadas;
        while(numMesa !=0){
            cin >> numMesa;
            if (numMesa != 0)
                mesasSeleccionadas.push_back(numMesa);
        }
        icon->seleccionarMesas(mesasSeleccionadas);

        cout << "Las mesas seleccionadas son las siguientes:" <<endl;
        for (auto& elm: mesasSeleccionadas ){ //muestro las mesas del mozo
            cout << elm << " // " <<endl;
        }
        int opSwitch;
        cout << "Desea confirmar la venta?:" << endl;

        cout << "1 - Si" << "\n" << "2 - No" << endl;
        cin >> opSwitch;
        while(opSwitch != 1 && opSwitch != 2){
            cout << "Opcion invalida" << endl;
            cin >> opSwitch;
        }
        string codVenta;
        switch (opSwitch)
        {
        case 1:
            codVenta = icon->confirmarIniciarVenta();
            cout << "Venta creada con EXITO" << endl;
            cout << "Codigo de Venta: " << codVenta << endl;
            break;
        case 2:
            icon->cancelarIniciarVenta();
            cout << "Iniciar venta CANCELADO" << endl;
            break;
        }
    }else{
        cout << "Actualmente todas sus mesas esta con una venta" << endl;
    }
}

//OPERACION C
void agregarProductoAVenta(){
    cout <<"________________________________________" << endl;
    cout <<"_____A G R E G A R__P R O D U C T O_____" << endl;
    fabrica = Fabrica::getInstancia();
    IControladorAgregarProdAVenta* icon = fabrica->getIControladorAgregarProdAVenta(); 
    int mesa, cantidad;
    int operador=1;
    string codigo,codABuscar;
    bool existe;
    DtProductoCantidad productoVenta, prodCant;
    //listar productos, seleccionar producto(dtproductocantidad), seleccionar mesa(int), confirmar o cancelar
    cout << "\nSeleccione la Mesa: ";
    cin >> mesa;
    icon->seleccionarMesa(mesa);//selecciono la mesa
    cout << "\nListado de Productos: ";
    list<DtProductoBase> productos = icon->listarProductos();
    list<DtProductoBase>::iterator it;
    for(it=productos.begin(); it!=productos.end(); it++){
        cout << "\n\n" << *it;
    }
    while(operador==1){
        existe=false;
        cout << "\nSeleccione el Producto a Agregar: ";
        cin >> codigo;
        for(it=productos.begin(); it!=productos.end(); it++){
            codABuscar = it->getCodigo();
            if(codABuscar==codigo)
                existe=true;
        }
        if(existe==true){
            cout << "\nSeleccione la Cantidad a Agregar: ";
            cin >> cantidad;
            productoVenta = DtProductoCantidad(codigo,cantidad); //creo el prodcant
            icon->seleccionarProducto(productoVenta);//lo selecciono
            int opSwitch;
            cout << "\nDesea confirmar Agregar un Producto? :" << endl;
            cout << "1-SI" << "\n" << "2-NO" << endl;
            cin >> opSwitch;
            while(opSwitch != 1 && opSwitch != 2){
                cout << "Opcion invalida" << endl;
                cin >> opSwitch;
            }
            switch (opSwitch){
            case 1:
                icon->confirmarAgregarProductoAVenta();//aca se rompe 
                cout << "\nPRODUCTO AGREGADO A VENTA CON EXITO" << endl;
                cout << "\nProducto: " << productoVenta << "\n" << "Mesa: "<< mesa <<endl;
                break;
            case 2:
                icon->cancelarAgregarProductoAVenta();
                cout << "\nAGREGAR PRODUCTO A VENTA CANCELADO" << endl;
                break;
            }
            cout << "\nDesea seguir Agregando Productos? :" << endl;
            cout << "1-SI" << "\n" << "2-NO" << endl;
            cin >> operador;
        }else{
            cout << "\nNo existe un producto con ese codigo" << endl;
            cout << "\nDesea seguir Agregando Productos? :" << endl;
            cout << "1-SI" << "\n" << "2-NO" << endl;
            cin >> operador;
        }
    }
}

//OPERACION D
void quitarProductoAVenta(){
    cout <<"______________________________________" << endl;
    cout <<"_____Q U I T A R__P R O D U C T O_____" << endl;
    fabrica = Fabrica::getInstancia();
    IControladorQuitarProducto* icon = fabrica->getIControladorQuitarProducto(); 
    //listar productos, seleccionar producto, confirmar o cancelar
    int mesa, cantidad;
    int operador=1;
    string codigo,codABuscar;
    bool existe=false;
    DtProductoCantidad productoVenta, prodCant;
    cout << "\nSeleccione la Mesa: ";
    cin >> mesa;
    cout << "\nListado de Productos: ";
    list<DtProducto> productos = icon->listarProductos(mesa);
    list<DtProducto>::iterator it;
    for(it=productos.begin(); it!=productos.end(); it++){
        cout << "\n\n" << *it;
    }
    while(operador==1){
        existe=false;
        cout << "Seleccione el Producto a Quitar\nCodigo: ";
        cin >> codigo;
        for(it=productos.begin(); it!=productos.end(); it++){
            codABuscar=it->getCodigo();
            if(codABuscar==codigo)
                existe=true;
        }
        if(existe==true){
            cout << "\nSeleccione la Cantidad a Quitar\nCantidad: ";
            cin >> cantidad;
            productoVenta = DtProductoCantidad(codigo,cantidad);
            icon->seleccionarProductoEliminar(productoVenta);
            int opSwitch;
            cout << "\nDesea confirmar Quitar Producto? :" << endl;
            cout << "1-SI" << "\n" << "2-NO" << endl;
            cin >> opSwitch;
            while(opSwitch != 1 && opSwitch != 2){
                cout << "\nOpcion invalida" << endl;
                cin >> opSwitch;
            }
            switch (opSwitch)
            {
            case 1:
                icon->confirmarQuitarProducto();
                cout << "\nProducto Quitado con Exito" << endl;
                cout << "\nProducto: " << productoVenta << "\n" << "Mesa: "<< mesa <<endl;
                break;
            case 2:
                icon->cancelarQuitarProducto();
                cout << "\nQUITAR PRODUCTO A VENTA CANCELADO" << endl;
                break;
            }
            cout << "\nDesea seguir Agregando Productos? :" << endl;
            cout << "1-SI" << "\n" << "2-NO" << endl;
            cin >> operador;
        }else{
            cout << "\nNo existe un Producto con ese Codigo" << endl;
            cout << "\nDesea seguir Quitando Productos? :" << endl;
            cout << "1-SI" << "\n" << "2-NO" << endl;
            cin >> operador;
        }
    }
}
//OPERACION E
void facturacionDeUnaVenta(){
    cout <<"____________________________________" << endl;
    cout <<"_____F A C T U R A R__V E N T A_____" << endl;
    fabrica = Fabrica::getInstancia();
    IControladorFacturacion* icon = fabrica->getIControladorFacturacion();
    int idMesa, operador;
    float descuento = 0.10;
    int subtotal, totalVenta, totalVentaConIVA;
    string codigoVenta, nombreMozo;
    DtFecha dtFechaEmision;
    DtFactura dtFactura;
    operador =1;
    while(operador == 1){
        cout <<"Ingrese numero de mesa: "<< endl;
        cin >> idMesa;
        dtFactura = icon->facturar(idMesa, descuento);
        cout << "Venta codigo: " << dtFactura.getCodigoVenta() << endl;
        cout << "Fecha: " << dtFechaEmision.getDia() << "/" << dtFechaEmision.getMes() << "/" << dtFechaEmision.getAnio() << endl;
        cout << "Usted fue atendid@ por: " << dtFactura.getNombreMozo() <<endl; 
        cout << "Subtotal: $" << setprecision(2) << dtFactura.getSubtotalVenta() << endl;
        cout << "Total: $" << setprecision(2) << dtFactura.getMontoTotalVenta() << endl;
        cout << "Total + IVA: $" << setprecision(2) << dtFactura.getMontoTotalVentaConIVA() << endl;

        cout << "\nDesea seguir Facturando?\n" << endl;
        cout << "1-SI" << "\n" << "2-NO" << endl;
        cin >> operador;
    }
}
//OPERACION F
void bajaProducto(){
    //system("clear");
    cout <<"__________________________________" << endl;
    cout <<"_____B A J A__P R O D U C T O_____" << endl;
    fabrica = Fabrica::getInstancia();
    IControladorBajaProducto* icon = fabrica->getIControladorBajaProducto();
    string codigo,codABuscar;
    int operador,elim;
    bool existe;
    operador = 1;
    list<DtProductoBase> lstProductos = icon->listarProductos();
    list<DtProductoBase>::iterator it;
    cout << "\nListado de Productos: \n";
    for(it=lstProductos.begin(); it!=lstProductos.end(); it++){
        cout << *it << endl;
    }
    while(operador==1){
        existe=false;
        cout << "\nIngrese el codigo del producto a eliminar: \nCodigo: ";
        cin >> codigo;
        for(it=lstProductos.begin(); it!=lstProductos.end(); it++){
            codABuscar= it->getCodigo();
            if(codABuscar==codigo)
                existe=true;
        }
        if(existe){
            icon->seleccionarProducto(codigo);
            cout << "\nDesea Eliminar el Producto? :" << endl;
            cout << "1-SI" << "\n" << "2-NO" << endl;
            cin >> elim;
            if(elim==1){
                icon->eliminarProducto();
                cout << "\nSE HA ELIMINADO EL PRODUTO CON CODIGO: " << codigo <<endl;
            }else{
                icon->cancelarBajaProducto();
            }
        }else{
            cout << "\nNO EXISTE PRODUCTO CON ESE CODIGO\n";
        }
        cout << "\nDesea Seguir Eliminando Productos? :" << endl;
        cout << "1-SI" << "\n" << "2-NO" << endl;
        cin >> operador;
    }
}
//OPERACION G
void verInfoProducto(){
    cout <<"________________________________________________________" << endl;
    cout <<"_____I N F O R M A C I O N__D E__U N__P R O D U C T O___" << endl;
    fabrica = Fabrica::getInstancia();
    IControladorVerInfoProducto* icon = fabrica->getIControladorVerInfoProducto();
    string codigo;
    string descripcion,codABuscar;
    float precio;
    int operador=1;
    bool existe;
    cout << "\nListado de Productos: \n";
    list<DtProductoBase> productos = icon->listarProductos();
    list<DtProductoBase>::iterator it;
    for(it=productos.begin(); it!=productos.end(); it++){
        cout << *it << endl;
    }
    while(operador==1){
        existe=false;
        cout << "\nSeleccione un producto: ";
        cin >> codigo;
        for(it=productos.begin(); it!=productos.end(); it++){
            codABuscar=it->getCodigo();
            if(codABuscar==codigo);
                existe=true;
        }
        if(existe==true){
            icon->seleccionarProducto(codigo);
            cout << "\nInformacion del producto " << codigo << ":\n" <<endl;
            icon->infoProducto();
            cout << "\nDesea Ver la Info de Otro Producto? :" << endl;
            cout << "1-SI" << "\n" << "2-NO" << endl;
            cin >> operador;
        }else{
            cout << "\nNo existe el producto con codigo " << codigo << endl;
            cout << "\nDesea Ver la Info de Otro Producto? :" << endl;
            cout << "1-SI" << "\n" << "2-NO" << endl;
            cin >> operador;
        }
    }
}

void menu(){
    cout <<"_____________________________________________" <<endl;
    cout <<"____________R E S T A U R A N T E____________"<< endl;
    cout <<"1. Alta Producto"<<endl;
    cout <<"2. Iniciar Venta"<<endl;
    cout <<"3. Agregar Producto A Una Venta"<<endl;
    cout <<"4. Quitar Producto A Una Venta"<<endl;
    cout <<"5. Facturacion De Una Venta"<<endl;
    cout <<"6. Baja Producto"<<endl;
    cout <<"7. Ver Info De Un Producto"<<endl;
    cout <<"8. Salir"<<endl;
    cout <<"_____________________________________________" <<endl;
    cout <<"OPCION: ";
}

int main(){
    cout << ("*-------Comienza programa restaurante-------*")<<endl;
    fabrica = Fabrica::getInstancia();
    icon = fabrica->getIControladorCargaDatos(); 
    int opcion;
    icon->cargaDatos();
    menu();
    cin >> opcion;
    while(opcion!=8){
        switch(opcion){
            case 1: altaProducto();
                break;
            case 2: iniciarVenta();
                break;
            case 3: agregarProductoAVenta();
                break;
            case 4: quitarProductoAVenta();
                break;
            case 5: facturacionDeUnaVenta();
                break;
            case 6: bajaProducto();
                break;
            case 7: verInfoProducto();
                break;
            case 8: system("exit");
                cout << "SALIENDO..." << endl;
            default:
                cout << "OPCION INCORRECTA" << endl;
        }
        //system("sleep 5");
        menu();
        cin >> opcion;
    }
    return 0;
}
