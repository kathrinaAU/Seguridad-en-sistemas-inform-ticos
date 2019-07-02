#include "vernam.hpp"
#include <string>
#include <sstream>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

using namespace std;
Vernam::Vernam() {}


Vernam::~Vernam(void) {}


void Vernam::write(string msg_inicial){
    cout << "\tEntrada:" << endl;
    cout << "\t\tMensaje original: " << msg_inicial << endl;
    cout << "\tSalida:" << endl;
    cout << "\t\tMensaje original en ASCII: " << msg_ascii << endl;
    cout << "\t\tMensaje original en binario: ";

    for (int i = 0; i < longitud_binario; i++){
        cout << msg_binario[i];
    }
    cout << endl;

    cout << "\t\tLongitud del mensaje binario: " << longitud_binario * 8 << endl;
    cout << "\tEntrada:" << endl;
    cout << "\t\tClave aleatoria: ";

    for (int i = 0; i < longitud_msg_inicial; i++){
        cout << clave[i];
    }
    cout << endl;

    cout << "\tSalida:" << endl;
    cout << "\t\tMensaje cifrado en binario: ";

    for (int i = 0; i < longitud_binario; i++){

        cout << msg_binario_cifrado[i];
    }
    cout << endl << endl;

    cout << "\t\tMensaje cifrado en ASCII: " << msg_cifrado_ascii_temp << endl;
    cout << "\t\tMensaje cifrado: " << msg_cifrado << endl << endl;

    cout << "\t\tMensaje descifrado en ASCII: " << msg_descifrado_ascii_temp << endl;
    cout << "\t\tMensaje descifrado: " << msg_descifrado << endl << endl;
}


void Vernam::write_2(string msg_inicial){
    cout << "\tEntrada:" << endl;
    cout << "\t\tMensaje cifrado: " << msg_inicial << endl;
    
    cout << "\tSalida:" << endl;
    cout << "\t\tMensaje cifrado en binario: ";
    for (int i = 0; i < longitud_binario; i++){
        cout << msg_binario[i];
    }
    cout << endl;

    cout << "\t\tLongitud del mensaje binario: " << longitud_binario * 8 << endl;
    
    cout << "\tEntrada:" << endl;
    cout << "\t\tClave aleatoria: ";
    for (int i = 0; i < longitud_msg_inicial; i++){
        cout << clave[i];
    }
    cout << endl;

    cout << "\tSalida:" << endl;

    cout << "\t\tMensaje original en binario: " << msg_descifrado_ascii_temp << endl;
    
    cout << "\t\tMensaje original: " << msg_descifrado <<endl; 

}


// Primero: Paso de string a decimal/ascii
void Vernam::translate_ascii(string msg_inicial){
    longitud_msg_inicial = msg_inicial.length();

    //Recorro el mensaje inicial 
    for (int i = 0; i < longitud_msg_inicial; i++)
        //Este es para mostrarlo arriba y ya
        //  --------> OPCIONAL
        //Paso cada caracter a decimal segun tabla ascii y lo almaceno en msg_ascii.
        msg_ascii += to_string( (int) msg_inicial.at(i) );
    
    // Guardo el tamaño del nuevo mensaje para pasar al siguiente paso.
    longitud_msg_ascii = msg_ascii.length();
}



// Segundo: Paso de decimal a binario
void Vernam::translate_ascii_binario( string msg_inicial){

    //Para trabajar con bits pues se usa bitset porque son fleje largos los mensajes.
    msg_binario = new bitset<8>[longitud_msg_ascii]; //Creo el bitset en función del número de decimales que obtuve antes. Va a tener en cada posición el número decimal pasado a binario
    bitset<8> aux[longitud_msg_ascii]; // Otro bitset auxiliar del mismo tamaño vacío.

    // Recorro el 
    for (size_t i = 0; i < longitud_msg_ascii; i++){
        //cout << " mmensaje inicial: " << msg_inicial << endl;
        aux[i] = bitset<8>(msg_inicial[i]); // Le meto los 8 bits del primer CARACTER
        //cout << " aux: " << aux[i] << endl;
        msg_binario[i] = aux[i];

    }

    longitud_binario = longitud_msg_inicial;
    longitud_binario_8 = longitud_binario*8;

}



bool Vernam::pedir_clave(string msg_inicial){

    longitud_msg_inicial = msg_inicial.length();

    cout << "Introduzca la clave para cifrar: ";
    cin >> clave_entrada;

    int aux = 0;
    clave = new bitset<8>[longitud_msg_inicial];

    if (clave_entrada.length() != msg_inicial.length()*8){
        cout << "Tamaño distintos, no se puede sumar porque el algoritmo necesita esta condición."<<endl;
        booleano = false;
    }

    // Pasar de binario a bitset
    for (int i = 0; i < longitud_msg_inicial; i++){
        for (int j = (clave_entrada.size() / longitud_msg_inicial) - 1; j >= 0; j--) {
            if (clave_entrada[aux] == '1') {
                clave[i].set(j, clave_entrada[aux]);
            }
            aux++;
        }
    }

    return booleano;
    
}


void Vernam::cifrado(void){

    msg_binario_cifrado = new bitset<8>[longitud_binario];
    // Recorro 
    for (int i = 0; i < longitud_binario; i++){
        // Guardo mi mensaje cifrado, se recorre cada bitset y se hace xor
        msg_binario_cifrado[i] = msg_binario[i] ^ clave[i];
        
    }
}


// Paso de binario a letra
// Paso los bits del bitset resultante de la operación a decimal/ascii 
// Y de bitset resultante a caracter
void Vernam::translate(void){

    for (int i = 0; i < longitud_binario; i++){
        //Este es para mostrarlo arriba y ya
        //  --------> OPCIONAL
        msg_cifrado_ascii_temp += to_string( (int) msg_binario_cifrado[i].to_ulong() );

        //  El resultado de pasar a string
        msg_cifrado += msg_binario_cifrado[i].to_ulong();

    }
    
}

// Para que me haga la operación XOR luego de forma inversa es decir que mi msg_binario sera mi msg_cifrado
// void Vernam::procesando_cifrado(string msg_inicial){
//     msg_binario_cifrado = new bitset<8>[longitud_msg_inicial];  

//     msg_binario_cifrado = msg_binario;

// }

void Vernam::copia(){
    msg_binario_cifrado = new bitset<8>[longitud_msg_inicial];
    msg_binario_cifrado = msg_binario;

}


//DESCIFRADO: Convierto binario a letra
void Vernam::descifrado(void){

    msg_binario_descifrado = new bitset<8>[longitud_binario];

    // Operación XOR entre la cifrada y la aleatoria
    for (int i = 0; i < longitud_binario; i++){
        msg_binario_descifrado[i] = msg_binario_cifrado[i] ^ clave[i];
    }

    for (int i = 0; i < longitud_binario; i++){
        //Este es para mostrarlo arriba y ya
        //  --------> OPCIONAL
        msg_descifrado_ascii_temp += to_string((int)msg_binario_descifrado[i].to_ulong());

        //Paso a letra el binario
        msg_descifrado += msg_binario_descifrado[i].to_ulong();
        //cout << " descifrandoooo: "<< msg_descifrado <<endl;
    }
}


void Vernam::aleatoria(string msg_inicial){
 
    longitud_clave = longitud_msg_inicial;
    longitud_clave_bitset = longitud_clave * 8;
    string clave_aleatoria("", longitud_msg_inicial);
    clave_aleatoria = "";

    srand(time(NULL));

    for (int i = 0; i < longitud_msg_inicial; i++){
        usleep(8000);
        clave_aleatoria[i] = rand() %80;
    }

    clave = new bitset<8>[longitud_clave];
    bitset<8> aux[longitud_clave];

    for (size_t i = 0; i < longitud_clave; i++){
        aux[i] = bitset<8>(clave_aleatoria.c_str()[i]);
        clave[i] = aux[i].to_ulong();
    }
}





