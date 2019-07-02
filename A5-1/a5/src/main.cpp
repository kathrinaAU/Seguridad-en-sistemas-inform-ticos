#include <cstdio>
#include <iostream>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#include "a5.hpp"
 
using namespace std;


int main(void){

    string mensaje;

    string r1_string;
    cout << endl;
    cout << " Bienvenido." << endl;
    cout << " Ingrese el primer registro, formado por 19 elementos. Ejemplo: 1001000100011010001" << endl;
    cin >> r1_string;


    string r2_string;
    cout << endl;
    cout << endl;
    cout << " Ingrese el segundo registro, formado por 22 elementos. Ejemplo: 0101100111100010011010 " << endl;
    cin >> r2_string;

    string r3_string;
    cout << endl;
    cout << endl;
    cout << " Ingrese el tercer registro, formado por 23 elementos. Ejemplo: 10111100110111100001111" << endl;
    cin >> r3_string;

    cout << endl;
    cout << " Introduzca el mensaje a cifrar:" << endl;
    cin >> mensaje;


    a5 obj;
    obj.mensaje_bin(mensaje);
    obj.transforma(r1_string, r2_string, r3_string);
    obj.desplazamiento(mensaje);
    obj.cifrado(mensaje);
    obj.translate(mensaje);
    obj.descifrado();
    obj.translate_des();

    cout << endl;

    return 0;
    
}
