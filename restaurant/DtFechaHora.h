#ifndef DTFECHAHORA
#define DTFECHAHORA
#include "DtFecha.h"
class DtFechaHora: public DtFecha{
	private:
		int hora;
        int min;
        int seg;
	public:
		DtFechaHora();
		DtFechaHora(int,int,int,int,int,int);
		int getHora();
		int getMin();
        int getSeg();
		~DtFechaHora();

		friend ostream& operator <<(ostream&, const DtFechaHora&);
};
#endif
