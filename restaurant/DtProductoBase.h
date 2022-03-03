#ifndef DTPRODUCTOBASE
#define DTPRODUCTOBASE
#include<iostream>

using namespace std;

class DtProductoBase{
	private:
		string codigo;
		string descripcion;
	public:
		DtProductoBase();
		DtProductoBase(string,string);
		string getCodigo();
		string getDescripcion();
		~DtProductoBase();

		friend ostream& operator<<(ostream&, const DtProductoBase&); 
};
#endif