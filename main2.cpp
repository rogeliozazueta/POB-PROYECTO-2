#include <iostream>
#include <string>
#include <fstream>
#include "Funcion.h"
#include "Pelicula.h"


using namespace std;

int main()

{
	Actor a1;  // objetos de tipo actor ( recibe Id y Nombre)
	Funcion f1; // objeto de tipo funcion (recibe  cveFuncion , numPeli (hora(hh y mm))	y numero de sala;
	Actor arregloactores[20];   //1. Escribe ahora un programa que tenga arreglos de objetos de tipo Actor , Funcion ,Pelicula
	Funcion funciones[20];
	Pelicula peliculas[20];  // pelicula recibe atributos de int numPeli  titulo anio duracion string genero int cantActores listaActores[10];
	int nofunciones=0;
	

	
	
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	
	
	// Cargando el  Arreglo de tipo Actor  del archivo de texto Actores.txt
	ifstream ArchEntA;
	ArchEntA.open("Actores.txt");
	string TextoActores;
	int i=0;
	
	
	while (getline(ArchEntA,TextoActores))  //Todo el renglon hasta que se acabe 
	{ 
		
		int espacio=TextoActores.find(" "); //Busca el primer espacio dentro del texto y le da posicion a la variable
		string nombre=TextoActores.substr(espacio+1); // Guarda el  nombre al buscar el espacio con la variable anterior y sumarle 1;
		int ID=stoi(TextoActores.substr(0,espacio)); //convierte el id que esta en texto y buscado mediante el metodo substring a entero
		a1.Setid(ID); // se asginan el id objeto de tipo actor
		a1.Setnombre(nombre);// se asigna nombre al objeto tipo actor 
		arregloactores[i]=a1; //se guarda en el arreglo de tipo actor utilizando el objeto de tipo actor creado
		i++;
		
	}
	int actoresenlista=i; // cuenta los actores que estan en el arreglo;
	ArchEntA.close();
	
	
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	
	
	
	
	
	// Cargando Arreglo de tipo Pelicula
	i=0;
	ifstream ArchEntP;
	ArchEntP.open("peliculas.txt");

	int numPeli,anio,duracion,cantactores,ID;
	string genero,titulo;
	 
	 // el archivo pelicula no tiene clave , la clave es asignada por el usuario
 
 
  // todo se va agregando mediante el metodo de set al arreglo pelicula de tipo pelicula 
while (ArchEntP >> numPeli) 
{
        //Busca en el archivo peliculas el primer int y lo agrega
    	peliculas[i].SetnumPeli(numPeli);
    	
    	//Busca el segundo entero que es el anio y lo agrega
        ArchEntP >> anio;
     	peliculas[i].Setanio(anio);
     	
     	//Busca el 3 entero duracion y lo agrega
        ArchEntP >> duracion;
      	peliculas[i].Setduracion(duracion);
      	
      	// busca el string genero y lo agrega
        ArchEntP >> genero;
     	peliculas[i].Setgenero(genero);
     	// busca la cantidad de actores para tomarla como variable del ciclo for de los ids
        ArchEntP >> cantactores;
        
        // En cuanto al id viene dado por la cantidad de actores 
         // buscar el ID tantas veces que la cantidad de actores lo indique ya que el archivo indica cantidad y luego los ids
        for (int aux = 0; aux < cantactores; aux++)
		{
        ArchEntP >> ID;
    	for (int aux1 = 0; aux1 <actoresenlista; aux1++)  // lo hace dependiendo del numero de actores cargados 
		{
    			
        if (ID == arregloactores[aux1].getid() )//verifica que el id del archivo de texto que se leyo se encuentre en el arregloactores previamente cargado si si , este agregara a la lista actores
		{
                    peliculas[i].AgregarActor(arregloactores[aux1]); //se mete el arreglo actores a la funcion agregar actores de la clase pelicula , le pasa la lista al arreglo peliculas para depues mostrarlo
        }													// Aqui se agregan datos a la lista actores
        }
       }
            
        getline(ArchEntP, titulo);  // lee el titulo y lo agrega
         peliculas[i].Settitulo(titulo);
        i++;
    
        
}
    int peliculasenlista=i; // nos cuenta las peliculas en la lista
    ArchEntP.close();
    
    
    
    
    
    
    
    ////////////////////////////////////////////////////////////////////////////////
    
    //FUNCIONES
    
    int x=0;
    bool controlerexterno =true; 
    while(controlerexterno == 1)
	
	{ //Nos controla el numero de funciones que deseamos agregar si se establece controladorexterno a 0 se sale y va al menu
	
        int nof,Numpeli , hora , minutos , nosala;
        string cveFuncion ;
        
        go:
        cout<<"¿Cuantas funciones quieres agregar? (Maximo 20)"<<endl;  // se piden el numero de funciones a agregar 
        cin>>nof;
        
        if (nof< 21&& nof>0) // el limite de funciones es de 20 asi lo establece el proyecto
		
		{
            	for (int i = 0; i < nof; i++)  // el codigo pedira los atributos de las funciones dependiendo de cuantas funciones
			{
                cout << "Teclea la clave de la funcion: " << endl;
                cin >> cveFuncion;
               	f1.SetcveFuncion(cveFuncion);                // Pide clave funcion  , el usuario la asigna.
               	
               	
				   
				   
			////////////////////////////////////////////////////////////////////////////////////////////
				   
				   //  se pide el Numero pelicula validando que exista
               	
				bool controladorinterno=true; // nos permite movernos en el arreglo de las peliculas 
               	
				while(controladorinterno==true)
               	{
               	
            	cout << "Teclea el numero de la pelicula: " << endl;
                cin >> Numpeli;  //se ingresa el numero de la pelicula 
                
				while(x<peliculasenlista)  // se ejectua mientras se menor a las peliculasenlista de las que agregamos de el archivo de peliculas
                {
                	if(Numpeli==peliculas[x].GetnumPeli())  // busca el numero en todo el  arreglo pelicula que cargamos con el archivo pelicula
                	{
                		f1.SetnumPeli(Numpeli); // si hay uno igual quiere decir que existe entonces se agrega a mi objeto tipo funcion f1
                		controladorinterno=false; // condicion se hace falso y se sale
				    }
				    x++;
                	
				}
				
				
                if (controladorinterno == true) // si controlador sigue siendo true significa que el numerode pelicula que se ingreso no existia entonces se tiene que volver a ingresar
                {
                	cout << "Por favor ingrese un numero valido.  " << endl;
				}
				x=0;
				
				controladorinterno==true;
			    }
			   	
			  
			   ////////////////////////////////////////////////////////////////////////////////////
               // Se pide la hora 
			  
			  	controladorinterno=true;
			    while(controladorinterno==true) // se repite pedir hora y minutos hasta que se obtenga falso que indicaria que el formato de hora fue valido
                {
                cout << "Ingrese la hora de la funcion (Solo Hora): " << endl;
                cin >> hora;
                cout << "Ingrese los minutos de la hora de la funcion (Solo minutos): " << endl;
                cin >> minutos;
                if ((hora>0 && hora<25) && (minutos>=0&&minutos<60)) //condiciones del formato de hora 24 Hrs
                	{
                		 Hora horariofuncion(hora, minutos); // se crea un objeto de tipo hora para cargarlo a uno tipo funcion  y despues pasarlo al arreglo de funciones
                		 f1.Sethora(horariofuncion);
                		 controladorinterno=false;
					}
					else // se ingreso un formaot invalido
					{
						cout << "Por favor ingrese un formato valido.  " << endl;
					}
				}
				
				
				
               /////////////////////////////////////////////////////////////// 
               
               /// numero de sala 
               
                cout << "Teclea el numero de la sala " << endl;
                cin >> nosala;

                Hora horariofuncion(hora, minutos);   // se crea un objeto de tipo hora para cargarlo a uno tipo funcion  y despues pasarlo al arreglo de gfunciones
                Funcion f2(cveFuncion,Numpeli,horariofuncion,nosala);	// los datos pedidos de las funciones se guardan en un objeto que depues se guarda en el arreglo de tipo Funcion 
                funciones[i] =f2; // se cargan los valores  establecidos en el arreglo funciones
			    nofunciones++; // variable para contar cuantas funciones fueron registradas
            }
			controlerexterno = false;  // se acaboron las iteraciones y se sale
          
        } 
        
        // si el limite de funciones es mayor a 20 o menor a 0 nos vuelve a pedir el ingreso del numero
        else 
		{
            cout<<"Ingresa un numero valido de funciones (Solo se puede agregar un Maximo de 20 funciones )"<<endl;
            goto go;
        }
        
    }


    
    
    
    
    
    
    
  
      
    
        
        
        
        
        //	MENU IMPLEMENTACION 
        
    int opcion;
    Hora horaopcion4;  // objeto de tipo hora
    int hora , minutos;
 
    do{
        system("cls");        // Para limpiar la pantalla
        
        // Texto del menú 
        
        cout << "\n\nMenu de Opciones" << endl;
        cout << "1. Consulta de actores" << endl;
        cout << "2. Consulta de Peliculas" << endl;
        cout << "3. Consulta de funciones disponibles" << endl;
        cout << "4. Consulta de funciones por hora" << endl;
        cout << "5. Consulta de funciones por clave " << endl;   
        cout << "6. Consulta de funciones por ID" << endl;
        cout << "7. SALIR" << endl;
        
        cout << "\nIngrese una opcion: ";
        cin >> opcion;
        
        switch (opcion){
            case 1:
            	
            /////////////////////////////////////////////////////	
            {
			
              i=0;
              while(i<actoresenlista)  //recorrer el arreglo actores y los muestra id y nombre
			{
				arregloactores[i].muestra();
				i++;
			}
		       
                
                system("pause>nul"); // Pausa
                break;
            }
            
            ////////////////////////////////////////////////////
            case 2:
            {
			
            	i=0;      //recorre el arreglo peliculas y muestra todas las pelis
				while(i<peliculasenlista){
				peliculas[i].muestra();
				i++;	
				}
				
				 
			             
                
                system("pause>nul"); // Pausa
                break;
            }
            
            
            ///////////////////////////////////////////////////////////
            case 3:
            {
			                             /// recorre el arreglo funciones y muestra todas las funciones que se agregaron 
            	i=0;
                while (i<nofunciones)
			{
				funciones[i].muestra();
				i++;
			}
			             
                
                system("pause>nul"); // Pausa            
                break;
            }
            
            ///////////////////////////////////////////////////////////////////
            
            case 4:
            {
			
                go1:
				int hora,minutos;
				int i=0;
				bool controlador=true;
                cout << "Teclea la hora de la funcion (Solo Hora): " << endl; 
                cin >> hora;
                cout << "Teclea  los minutos de la hora de la funcion (Solo minutos): " << endl;
                cin >> minutos; // se piden los atributos 
                if ((hora>0 && hora<25) && (minutos>=0&&minutos<60)) //condiciones del formato de hora 24 Hrs // se verifica que esten en un formato valido 
                	{
                		 horaopcion4.SetHora(hora);		// se establecen en un objeto de tipo hora declarado antes
                		 horaopcion4.SetMinutos(minutos);
                	
        			while (i<nofunciones) //lo hace  mientras que el numero de funciones que se cargaron en la parte de funciones
        			{
        				//comprueba la hora se encuentre entre funciones y lo que se agrego al objeto lo mismo para minutos 
        				if(funciones[i].gethora().getHora()==horaopcion4.getHora() && funciones[i].gethora().getMinutos()==horaopcion4.getMinutos()) 
						//accede primero a la hora de la funcion (tipo hora) para luego accesar a la clase Hora y verifica que exista una igual mediante horas y minutos
        				{
        					// si si hay una hora entra aqui 
        					int aux=0;
        					while (aux<peliculasenlista) // busca el numero de pelicula 
        					{
        						if(funciones[i].getnumPeli()==peliculas[aux].GetnumPeli()) // busca que lo se cargo se encuentre en el arreglo peliculas pq tenemos que comprobar hora depues que esa hora corresponde a un numero de la clase pelicula para mostrar el titulo
								
								  {
								  cout<<peliculas[aux].Gettitulo()<<endl;         // si si se encuentra muestra el titulo  // pq titulo se encuentra en peliculas
								  aux++;
								  }		
								  aux++;
								 
								 												
							}
							funciones[i].muestra(); // muesta clave , numero de pelicula , sala , hora
							controlador=false; // si no se encontro tal hora de funcion esta variable nos ayuda a indicarlo que si si da false , si no se encuentra se va al if que nos dice que no hay funciones a tal hora
							//aux=0;
        				}
        					i++;
        					
					}
					if(controlador==true)
					   {
						
						cout << "  funciones no disponibles a esa hora. " << endl;
						
					   }
					
					}			
				else // se ingreso un formaot invalido
					{
						cout << "  Teclea un formato valido.  " << endl;
						goto go1;
				    }  
				
		
                
                system("pause>nul"); // Pausa                
                break;
        	}
            case 5:  // Consultar clave de funcion 
			{
				string clave;
				bool controlador=true;
				int i=0;
				int aux=0;
			
				cout<<"Teclea la clave de la funcion";  //se pide la clave
				cin>>clave;
				while(i<nofunciones)  // se realiza el loop que recorrera los arreglos con el numero de funciones que se ingresaron
				{
					
				  	if(clave==funciones[i].getcveFuncion())  // si la clave se encuentre en el arreglo funciones
					  {
					  
					  	while(aux<peliculasenlista) // busca el numero de pelicula en base a la clave que se le dio en arreglofuncioens en el arreglo de peliculas cargado
						  {   
						  	if(funciones[i].getnumPeli()==peliculas[aux].GetnumPeli()) // si hay una igual en las funciones que agregamos nos la mostrara
						  	{
						  		peliculas[aux].muestra(); // nos muestra a;o duracion genero y lista actores
						  		
							}
							aux++;
						  }
						  
						  funciones[i].muestra(); // Muestra las funciones cargadas clave , numero hora  sala
						  controlador=false;
						  aux=0;
						  
					  }
					  i++;
				}
				if (controlador==true)
				{
					    cout << "Teclea una clave valida." << endl;
				}	
			
				
			
				
				system("pause>nul"); // Pausa                
                break;
			}
				
			
				    
        	
			
             
			
			case 6:
			{
				int ID;
				bool controlador=true;
				int i=0;
				int aux=0;
				int j=0;
				
				cout<<"Tecle el ID deL actor";
				cin>>ID;
				while(i<actoresenlista)  // Se realiza mientras los actores que se cargaron a la lista 
				{
				  	if(ID==arregloactores[i].getid())  // Se comprueba el ID se encuentre en el arreglo previamente cargado
					  {
					 	arregloactores[i].muestra(); // muestra ID Y nombre del actor
					 	
					 	
						 while(aux<peliculasenlista)  // mientras el # de peliculas que se caragaron
						  	{
						  		while(j<peliculas[aux].GetcantActores()) // mientras la cantidad de actores
								{
									if(peliculas[aux].GetlistaActores(j).getid()==ID) // ingresa a los atributos de la clase ACTOR para buscar el id atraves de la clase pelicula
									{
										// si lo encuentra imprime
										cout<<peliculas[aux].Gettitulo()<<"  "<<peliculas[aux].Getanio()<<endl;	
									}
									j++;
								}
							 j=0;
							 aux++;
							}
							
						controlador=false;	
					  }
					  aux=0;
					  i++;
					  
			
					  
				}
				 if (controlador == true)
			{
				cout << " Teclea   un ID valido." << endl;
			}
				  	
					  
			
			 system("pause>nul"); // Pausa            
            break;
						  
			}
			
			
			    
          
				
			
				    
     
	}
                    
    }  while (opcion != 7);         
        
        
    
    
	ArchEntA.close();
	ArchEntP.close();
	return 0;
	
}

	
