#include <cstdio>
#include <iostream>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#include "multiplicacion.hpp"
 
using namespace std;


int main(void){

    // string num1 = "83";
    // string num2 = "57";
    // string byte = "00011011";

    string num1 = "";
    string num2 = "";
    string byte = "";
    
    cout << endl;
    cout << " Bienvenido." << endl;
    cout << " Ingrese el primer número. Ejemplo: 57." << endl;
    cin >> num1;

    cout << " Ingrese el segundo número. Ejemplo: 83." << endl;
    cin >> num2;

    cout << " Ingrese el byte necesario para la multiplicación. Ejemplo: AES: 00011011 | SNOW 3G: 10101001." << endl;
    cin >> byte;

    
    multiplicacion obj;

    obj.mensaje_bin(num1, num2);
    obj.op_aritmetica();
    obj.factores(byte);
    obj.resultado_prod();
    cout << endl << endl;

    return 0;
    
}
