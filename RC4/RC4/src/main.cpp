#include <cstdio>
#include <iostream>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#include "rc4.hpp"
 
using namespace std;


int main(void){

    string clave;
    string mensaje;
    rc4 obj;
    int tam;

	cout << endl <<endl;

	cout <<endl;
	cout << "	¡Bienvenido!"<< endl;
    cout << endl;

    cout << "Introduzca la clave: " <<endl;
    cin >> clave;
    cout << endl;
    cout << "Introduzca el mensaje: " <<endl;
    cin >> mensaje;

    obj.working_msg2(mensaje);
    obj.ksa(clave);
    obj.prga(mensaje);
    //obj.prga2(mensaje);
    obj.cifrado(mensaje);
    obj.binario_decimal();
    obj.write();
    
    return 0;
    
}