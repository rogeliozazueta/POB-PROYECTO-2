#include <iostream>
#include <string>


using namespace std;

class Actor{
	
	private:
		int id;
		string nombre;
	public:
	
	Actor(); // constructor default
	Actor(int id , string name); // constructor por parametros
	void Setnombre(string name){nombre=name;};
	void Setid(int num){id=num;};
	
	string getnombre( ){return nombre;};
	int getid(){return id;};

	
	void muestra(); 

		
		
};

Actor::Actor()
{
  id=0;
  nombre="None";
  	
}

Actor::Actor(int i ,string n)
{
  id=i;
  nombre=n;
  	
}

void Actor::muestra()
{
	cout << "ID del Actor: " << id << "\t Nombre:" << nombre << endl<<endl;
	cout<<"  "<<endl;
}
