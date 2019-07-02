#include <cstdio>
#include <iostream>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#include "bluetooth.hpp"
 
using namespace std;


int main(void){

    string mensaje = "h";

    string r1_string = "0111111111111111111111111";
    cout << endl;
    cout << " Bienvenido." << endl;
    // cout << " Ingrese el primer registro, formado por 25 elementos. Ejemplo: 1001000100011010001110011" << endl;
    // cin >> r1_string;


    string r2_string = "0111111111111111111111111111111";
    cout << endl;
    cout << endl;
    // cout << " Ingrese el segundo registro, formado por 22 elementos. Ejemplo: 0101100111100010011010100101100 " << endl;
    // cin >> r2_string;

    string r3_string ="011111111111111111111111111111111";
    cout << endl;
    cout << endl;
    // cout << " Ingrese el tercer registro, formado por 23 elementos. Ejemplo: 101111001101111000011110110011011" << endl;
    // cin >> r3_string;


    string r4_string = "010101010101010101010101010101010101010";
    cout << endl;
    cout << endl;
    // cout << " Ingrese el cuarto registro, formado por 23 elementos. Ejemplo: 001101100110011000101000100101001000010" << endl;
    // cin >> r4_string;

    string r5_string = "111111111111111111111111111111111111111";
    cout << endl;
    cout << endl;

    string r1_aux_string = "01";
    cout << endl;
    cout << endl;
    // cout << " Ingrese el registro 1, formado por 2 elementos. Ejemplo: 01" << endl;
    // cin >> r1_aux_string;
    
    cout << endl;
    // cout << " Introduzca el mensaje a cifrar:" << endl;
    // cin >> mensaje;


    bluetooth obj;
    obj.mensaje_bin(mensaje);
    obj.transforma(r1_string, r2_string, r3_string, r4_string, r5_string, r1_aux_string);
    obj.desplazamiento(mensaje);
    obj.write();
    obj.cifrado(mensaje);
    obj.translate(mensaje);
    obj.descifrado(mensaje);
    obj.translate_des(mensaje);

    cout << endl << endl;

    return 0;
    
}
