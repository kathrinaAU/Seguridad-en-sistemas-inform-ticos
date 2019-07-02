#include <string>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <bitset>
#include <set>
#include <vector>

using namespace std;

class Vernam{

     public:

        bool booleano = true;
        Vernam(void);
        ~Vernam();

        bool pedir_clave(string msg_inicial);
        void write(string msg_inicial);
        void write_2(string msg_inicial);
        void translate_ascii(string msg_inicial);
        void translate_ascii_binario(string msg_inicial);
        void cifrado(void);
        void translate(void);
        void descifrado(void);
        void aleatoria(string msg_inicial);
        void copia();
        

    private:

        int longitud_msg_inicial = 0;
        int longitud_msg_ascii = 0;
        string msg_ascii = "";

        bitset<8> *msg_binario;
        int longitud_binario = 0;
        int longitud_binario_8 = 0;

        bitset<8> *msg_binario_cifrado;
        bitset<8> *msg_binario_cifrado_temp;
        bitset<8> *msg_binario_descifrado;

        bitset<8> *clave;
        string clave_entrada = "";
        int longitud_clave = 0;
        int longitud_clave_bitset = 0;

        string msg_cifrado;
        string msg_cifrado_ascii;
        string msg_cifrado_ascii_temp;

        string msg_descifrado;
        string msg_descifrado_ascii_temp;

};
