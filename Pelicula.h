#include <iostream>
#include <string>
#include "Actor.h"

using namespace std;

class Pelicula{
	
	private:
		int numPeli;
		string titulo;
		int anio;
		int duracion;
		string genero;
		int cantActores;
		Actor listaActores[10];
		
	public:
	Pelicula();
	Pelicula(int num, string title , int a , int d , string g , int c);
		
	void SetnumPeli(int n){numPeli=n;};
	void Settitulo(string t){titulo=t;};
	void Setanio(int an){anio=an;};
	void Setduracion(int d){duracion=d;};
	void Setgenero(string g){genero=g;};
	void Setcantidadactores(int ca){cantActores=ca;};
	
	
	
	int GetnumPeli( ){return numPeli;};
	string Gettitulo(){return titulo;};
	int Getanio(){return anio;};
	int Getduracion(){return duracion;};
	string Getgenero(){return genero;};
	int GetcantActores(){return cantActores;};
	
	Actor GetlistaActores(int x){return listaActores[x];}; //Debe recibir como parámetro un entero. Este entero corresponderá al subíndice del arreglo de listaActores que se quiere accesar
	bool AgregarActor(Actor a); 	
	void muestra();
};

Pelicula::Pelicula()
{
  	numPeli=0;
	titulo="None";
	anio=0;
	duracion=0;
	genero="None";
	cantActores=0;
	listaActores[10]; 
	
  	
}

Pelicula::Pelicula(int n , string title , int a ,int d , string g , int c)
{
  	numPeli=n;
	titulo=title;
	anio=a;
	duracion=d;
	genero=g;
	cantActores=c;
	listaActores[c];
	
}

bool Pelicula::AgregarActor(Actor a) //recibe objeto de tipo actor( id y nombre)  en este caso recibe el arregloactores del arrhico previamente cargado de txt

{
	
	if (cantActores != 0) 
	{
	// Recorre la listaacotres que no es mayor a 10
		for (int i = 0; i < 10; i++) 
		{
			if ((a.getid() == listaActores[i].getid()) ) //busca que  en la lista actores no se encuentre repetido nombre , id
			{
	
				return false;
			}
			
			
			if ((a.getid() != listaActores[i].getid()) && listaActores[i].getid() == 0) // si es diferente a lo que hay en listaactores es decir que no esta y lo agrega
			
			{
				listaActores[i].Setid(a.getid()); // le da id a la lista acotres
				listaActores[i].Setnombre(a.getnombre()); // le da nombre lista
				cantActores = cantActores + 1; // le suma uno a la cantAct
				return true;
			}
			
			
		}
	}
	
	if (cantActores == 10)
	{
		return false;  // La lista ya se lleno 
	}
	
	if (cantActores == 0) // primer caso 3
	{
		listaActores[0].Setid(a.getid());
		listaActores[0].Setnombre(a.getnombre());
		cantActores = cantActores + 1;
		return true;
	}
	
}

void Pelicula::muestra()
{
	

	
	int i = 0;
	cout << numPeli << "  " << titulo << "   Anio: " << anio << "  Duracion: " << duracion << "  Genero: " << genero << endl<<endl;
	
	while (i<cantActores)
	{
		listaActores[i].muestra();
		
		i++;
	}
		
		
	

}
  	

