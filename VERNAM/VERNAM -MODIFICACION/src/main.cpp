#include <cstdio>
#include <iostream>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#include "colores.hpp"

#include "vernam.hpp"
 
using namespace std;

void animacion_inicio(void){

	system("clear");

	int contador=1;
	
	do{	
	
		cout <<endl<<endl;
		cout<<FCYN("			CIFRADO Y DESCIFRADO:");
		cout<<endl;
		cout <<FYEL( "                     Kathrina Arrocha Umpiérrez") <<endl;
		cout <<FYEL( "                 Seguridad en sistemas informáticos") <<endl;
		sleep(3);
		system("clear");
		
	
		cout <<endl<<endl;
		cout<<FGRN("					CARGANDO.");
		cout<<endl;
		sleep(1);
		system("clear");
		
	
		cout <<endl<<endl;
		cout<<FGRN("					CARGANDO..");
		cout<<endl;
		sleep(1);
		system("clear");
		
		cout <<endl<<endl;
		cout<<FGRN("					CARGANDO...");
		cout<<endl;
    	sleep(1);
		system("clear");
		
		
		contador++;
	
	}while(contador<=1);
}

int main(void){

	animacion_inicio();
	cout << endl <<endl;
	int opcion = -1;
	bool boolean;
	cout <<endl;
	cout << "	¡Bienvenido!"<< endl;
	cout << "	Seleccione el cifrado a realizar: "; 
		
  
   					
		while(opcion!=0){
   		
   			cout <<endl <<endl;
   			cout<< BOLD("        *********************** OPCIONES ************************") <<endl;
   			cout << "\t" << "*-------------------------------------------------------*" <<endl;
			cout << "\t" << "*----->	1. Cifrado y descifrado Vernam. -----------------------------*" <<endl;
			cout << "\t" << "*----->	2. Descifrado Vernam. -----------------------------*" <<endl;
			cout << "\t" << "*----->	3. Cifrado y descifrado con modificación. ------------------*" <<endl;
            cout << "\t" << "*----->	0. Salir. --------------------------------------*" <<endl;
			cout << BOLD ( "	*-----> Introduce la opción deseada: -------------------*") <<endl;
			cout << "\t" << "*-------------------------------------------------------*" <<endl;
			cout << "\t" << "*********************************************************" <<endl <<endl;;
			cin >> opcion;
			Vernam obj;
			string msg_inicial;
			

			switch (opcion){
				
				case 0:
					opcion = 0;
				break;

				case 1:
					
					cout << endl;
					cout << "Introduce el mensaje a cifrar: ";
					getline(cin, msg_inicial);
					getline(cin, msg_inicial);
					boolean = obj.pedir_clave(msg_inicial);

                    if (boolean){
						obj.translate_ascii(msg_inicial);
						obj.translate_ascii_binario(msg_inicial);
						obj.cifrado();
						obj.translate();
						obj.descifrado();
						obj.write(msg_inicial);
					}
					
		        	
		        break;

				case 2:

					cout << endl;
					cout << "Introduce el mensaje a descifrar: ";
					getline(cin, msg_inicial);
					getline(cin, msg_inicial);
					boolean = obj.pedir_clave(msg_inicial);

					if (boolean){
						
						obj.translate_ascii(msg_inicial);
						obj.translate_ascii_binario(msg_inicial);
						obj.translate();
						obj.copia();
						obj.descifrado();
						obj.write_2(msg_inicial);
					}
					
				break;

				case 3:
					cout << endl;
					cout << "Introduce el mensaje a cifrar: ";
					getline(cin, msg_inicial);
					getline(cin, msg_inicial);

					
					obj.translate_ascii(msg_inicial);
					obj.translate_ascii_binario(msg_inicial);
					obj.aleatoria(msg_inicial);
					obj.cifrado();
					obj.translate();
					obj.descifrado();
					obj.write(msg_inicial);
					

				break;

				default:
					cout <<endl << FRED("------> ERROR <------")<< " Opción incorrecta, saliendo del programa." << endl;
					opcion = 0;
				break;
					
			}
		}
		return 0;
	
}
	   		
   		
   		
   	
				
