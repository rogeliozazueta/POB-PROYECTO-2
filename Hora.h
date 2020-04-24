#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class Hora{
	private:
	int hh;
	int mm;
		
	public:
	Hora(); // constructor default
	Hora(int hora , int minutos); // constructor por parametros
	void SetHora(int h) {  hh=((h>0 && h<25)?h:0);}; // Hora con formato 24 Hrs
	void SetMinutos(int m) {	mm=((m>=0&&m<60)?m:0);};

	int getHora(){ return hh;};
	int getMinutos(){return mm;};
	
	void muestra(); // falta implementar

};


Hora::Hora(){
	hh=0;
	mm=0;
}
Hora::Hora(int hora , int minutos)
{
	hh=hora;
	mm=minutos;
}

void Hora::muestra()
{
	cout<<hh<<":"<<mm<<endl;
}
