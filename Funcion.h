#include <iostream>
#include <string>
#include "Hora.h"

using namespace std;

class Funcion{
	private:
	string cveFuncion;
	int numPeli;
	Hora hora;
	int sala;
		
	public:
	Funcion(); // constructor default
	Funcion(string cve , int numpel, Hora h ,int s); // constructor por parametros
	
	void SetcveFuncion(string cve){cveFuncion=cve;}
	void Sethora(Hora h){hora=h;}
	void Setsal(int s){ sala=s;};
	void SetnumPeli(int num){numPeli=num;};
	
	int getnumPeli(){return numPeli;};
	Hora gethora(){ return hora;};
	int getsala(){ return sala;};
	string getcveFuncion(){return cveFuncion;}
	
	void muestra(); // falta implementar

};

Funcion::Funcion(){
	Hora h1(0,0);
	hora=h1;
	cveFuncion="None";
	numPeli=0;
	sala=0;
}

Funcion::Funcion(string cve , int numpel , Hora h , int s)
{
	cveFuncion=cve;
	numPeli=numpel;
	hora=h;
	sala=s;
}

void Funcion::muestra()
{
	cout << "Hora ";hora.muestra();
	cout<< "Clave: " << cveFuncion << "    Numero de pelicula: " << numPeli << " \t Sala: " << sala << endl;
	
}

