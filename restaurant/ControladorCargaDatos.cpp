#include "ControladorCargaDatos.h"
#include "ManejadorMesa.h"
#include "ManejadorMozo.h"
#include "Mesa.h"
#include "Mozo.h"

void ControladorCargaDatos::registrarMeza(int numeroMesa){
    ManejadorMesa* manejMesa = ManejadorMesa::getInstancia();
    Mesa* mesa = new Mesa(numeroMesa);
    manejMesa->agregarMesa(mesa);
}
void ControladorCargaDatos::registrarMozo(string idMozo,string nombreMozo,map<int,Mesa*>mesas){
    ManejadorMozo* manejMozo = ManejadorMozo::getInstancia();
    Mozo* mozo = new Mozo(idMozo,nombreMozo);
    if(!mesas.empty())
        mozo->setMesas(mesas);
    manejMozo->agregarMozo(mozo);
}

void ControladorCargaDatos::cargaDatos(){
    registrarMeza(1);
    registrarMeza(2);
    registrarMeza(3);
    registrarMeza(4);
    registrarMeza(5);
    registrarMeza(6);
    registrarMeza(7);
    registrarMeza(8);

    ManejadorMesa* manejMesa = ManejadorMesa::getInstancia();
    map<int,Mesa*> mesas;
    mesas = manejMesa->getMesas();

    int numMesa1,numMesa2,numMesa3,numMesa4,numMesa5,numMesa6,numMesa7,numMesa8;
    Mesa* mesa1;
    Mesa* mesa2;
    Mesa* mesa3;
    Mesa* mesa4;
    Mesa* mesa5;
    Mesa* mesa6;
    Mesa* mesa7;
    Mesa* mesa8;

    int i = 0;
    for (map<int,Mesa*>::iterator it = mesas.begin() ; it != mesas.end(); ++it){
        i++;
        switch (i)
        {
        case 1:{
            numMesa1 = it->first;
            mesa1 = it->second;
            break;
            }
        case 2:
            numMesa2 = it->first;
            mesa2 = it->second;
            break;
        case 3:
            numMesa3 = it->first;
            mesa3 = it->second;
            break;
        case 4:
            numMesa4 = it->first;
            mesa4 = it->second;
            break;
        case 5:
            numMesa5 = it->first;
            mesa5 = it->second;
            break;
        case 6:
            numMesa6 = it->first;
            mesa6 = it->second;
            break;
        case 7:
            numMesa7 = it->first;
            mesa7 = it->second;
            break;
        case 8:
            numMesa8 = it->first;
            mesa8 = it->second;
            break;                 
        default:
            break;
        }
    }
    mesas.clear();
    mesas.insert(std::pair<int,Mesa*>(numMesa1,mesa1));
    mesas.insert(std::pair<int,Mesa*>(numMesa2,mesa2));
    registrarMozo("15","Cristiano Ronaldo",mesas);

    mesas.clear();
    mesas.insert(std::pair<int,Mesa*>(numMesa3,mesa3));
    mesas.insert(std::pair<int,Mesa*>(numMesa4,mesa4));
    registrarMozo("17","Alexis Sanchez",mesas);

    mesas.clear();
    mesas.insert(std::pair<int,Mesa*>(numMesa5,mesa5));
    mesas.insert(std::pair<int,Mesa*>(numMesa6,mesa6));
    registrarMozo("19","El pipa",mesas);

    mesas.clear();
    mesas.insert(std::pair<int,Mesa*>(numMesa7,mesa7));
    mesas.insert(std::pair<int,Mesa*>(numMesa8,mesa8));
    registrarMozo("11","Luquitas Torreira",mesas);

    mesas.clear();
    registrarMozo("16","Dinosaurio",mesas);

    asignarMesasAMozos();
}

void ControladorCargaDatos::asignarMesasAMozos(){
    list<DtAsignacion> asignacionMozosMezas;
    list<string> mesas;
    DtAsignacion itemAsignacion;

    ManejadorMozo* manejMozo = ManejadorMozo::getInstancia();
    list<Mozo*> mozos = manejMozo->getMozos();
    
    for (auto& elm: mozos ){
        itemAsignacion = DtAsignacion(elm->getIdMozo(),elm->getNombre(),elm->getMesas());
        asignacionMozosMezas.push_back(itemAsignacion);
    }
    cout<< "--------ASIGNACION DE MOZOS A MESAS--------"<<"\n"<<endl;
    for (list<DtAsignacion>::iterator it = asignacionMozosMezas.begin() ; it != asignacionMozosMezas.end(); ++it)
		cout << *it <<"\n" <<endl;
}