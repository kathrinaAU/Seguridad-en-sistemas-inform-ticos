#include <cstdio>
#include <iostream>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#include "vigenere.hpp"
#include "colores.hpp"
using namespace std;

int main(void){

    string msg_inicial;
    string clave;
    int opcion = -1;
    

	cout << endl <<endl;
    

	cout <<endl;
	cout << "	¡Bienvenido!"<< endl;

    while(opcion!=0){
   		
        cout <<endl <<endl;
        cout<< BOLD("        *********************** OPCIONES ************************") <<endl;
        cout << "\t" << "*-------------------------------------------------------*" <<endl;
        cout << "\t" << "*----->	1. Cifrado. -----------------------------*" <<endl;
        cout << "\t" << "*----->	2. Descifrado. -----------------------------*" <<endl;
        cout << "\t" << "*----->	0. Salir. --------------------------------------*" <<endl;
        cout << "Elija una opción" <<endl;
        cin >> opcion;

        switch(opcion){

            case 0: { 
                opcion = 0;
            break;
            }

            case 1:{
                vigenere obj;
                cout << " Introduce el mensaje a cifrar: " << endl;
                getline(cin, msg_inicial);
                getline(cin, msg_inicial);

                cout << " Introduce la clave: " << endl;
                cin >> clave;
                

                obj.dividir( msg_inicial, clave);
                obj.enumeracion(msg_inicial, clave);
                obj.cifrado(msg_inicial);
                //obj.descifrado();
                obj.write(msg_inicial, clave);
            break;
            }


            case 2:{
                vigenere obj1;
                cout << " Introduce el mensaje a descifrar: " << endl;
                getline(cin, msg_inicial);
                getline(cin, msg_inicial);
                cout << " Introduce la clave: " << endl;
                cin >> clave;

                obj1.dividir( msg_inicial, clave);
                obj1.enumeracion(msg_inicial, clave);
                //obj.cifrado(msg_inicial);
                obj1.descifrado();
                obj1.write2(msg_inicial, clave);
            break;
            }
            default:{
                cout <<endl << FRED("------> ERROR <------")<< " Opción incorrecta, saliendo del programa." << endl;
				opcion = 0;
            break;
            }
        }
    }
    
}
  
		
  
