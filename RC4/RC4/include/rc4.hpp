#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iterator>
#include <algorithm>
#include <set>
#include <vector>
#include <bitset>

using namespace std;

class rc4{

    private:
        vector <int> s;
        vector <int> s_aux;
        string clave;
        string mensaje; 
        vector <int> semilla;
        vector <int> msg_vector;
        vector <int> k;
        string clave_aux;
        string mensaje_aux;
        bitset<8>* clave_bin;
        
        vector <int> v_clave;
        vector <int> v_binario;

        vector <int> v_mensaje;  
        bitset<8>* msg_bin;

        string msg_cifrado_string_temp;
        string msg_cifrado_string;

        bitset<8>* msg_binario_cifrado;
        string cifrado2 = "";
        
 
    public:
        
        void ksa(string clave);
        void prga(string mensaje);
        void prga2(string mensaje);
        rc4();
        ~rc4();
        void working_msg(string mensaje);
        void working_msg2(string mensaje);
        void write();
        void translate(string mensaje);
        void cifrado(string mensaje);
        void binario_decimal();
        
    };
