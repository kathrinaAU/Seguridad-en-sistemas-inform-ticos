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

class a5{

    private:

        string r1_string;
        string r2_string;
        string r3_string;

        vector <int> r1_vector;
        vector <int> r2_vector;
        vector <int> r3_vector;

        vector <int> secuencia_cifrante;
        int r1;
        int r2;
        int r3;


        int mayoria;

        vector <int> v_mensaje;
        vector <int> v_mensaje_aux;
        vector <int> v_cifrado;

        bitset<8> *msg_binario;
        bitset<8> *sec_binario;
        bitset<8> *msg_binario_cifrado;
        bitset<8> *msg_binario_descifrado;

        string msg_descifrado_ascii_temp;
        string msg_descifrado;

        string msg_cifrado;
        string msg_cifrado_ascii;
        string msg_cifrado_ascii_temp;
        
        
  
 
    public:

        a5();
        ~a5();

        void transforma(string r1_string, string r2_string, string r3_string);
        void desplazamiento(string mensaje);
        void cifrado(string mensaje);
        void write();
        void mensaje_bin(string mensaje);
        void translate(string mensaje);
        void descifrado();
        void translate_des();
    };
