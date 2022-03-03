#ifndef DTPRODUCTOCANTIDAD
#define DTPRODUCTOCANTIDAD

#include<iostream>

using namespace std;

class DtProductoCantidad{
	private:
		string codigo;
        int cantidad;
	public:
		DtProductoCantidad();
		DtProductoCantidad(string,int);
		string getCodigo();
		int getCantidad();
		virtual ~DtProductoCantidad();

		friend ostream& operator << (ostream&, const DtProductoCantidad&);
};
#endif
