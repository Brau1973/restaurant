#ifndef DTASIGNACION
#define DTASIGNACION
#include<iostream>
#include<list>
using namespace std;

class DtAsignacion{
	private:
		string idMozo;
		string nombreMozo;
        list<int> mesas;
	public:
		DtAsignacion();
		DtAsignacion(string,string,list<int>);

		string getIdMozo();
		//list<string> getMesas();
        
		virtual ~DtAsignacion();

		friend ostream& operator << (ostream&, const DtAsignacion&);
};
#endif
