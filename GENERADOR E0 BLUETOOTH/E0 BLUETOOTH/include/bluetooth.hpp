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
#include <cmath>

using namespace std;

class bluetooth{

    private:

        string r1_string;
        string r2_string;
        string r3_string;
        string r1_aux_string;
        string r4_string;


        vector <int> r1_vector;
        vector <int> r2_vector;
        vector <int> r3_vector;
        vector <int> r4_vector;
 

        vector <int> r1_aux_vector;
        vector <int> r2_aux_vector;
        vector <int> t1_vector;
        vector <int> t2_vector;
        vector <int> sec_cifrante_vector;
        vector <int> div_vector;

        vector <int> div_xor_t2;
        vector <int> nuevo_r1;
        // vector <int> secuencia_cifrante;
        int r1;
        int r2;
        int r3;
        int r4;



        int resultado=0;
        int contador=0;


        vector <int> v_mensaje_aux;
        bitset<8> *msg_binario;
        // bitset<8> *sec_cifrante_bitset;
        bitset<2> div_bitset;
        bitset<8> *sec_cifrante_bitset;
        
        bitset<2> div_xor_t2_bitset;
        bitset<2> nuevo_r1_bitset;

        bitset<8> *msg_binario_cifrado;
        bitset<8> *msg_binario_descifrado;

        string msg_cifrado="";
        string msg_cifrado_ascii_temp;
        string msg_descifrado_ascii_temp;
        string msg_descifrado=""; 

 
    public:

        bluetooth();
        ~bluetooth();

        void transforma(string r1_string, string r2_string, string r3_string, string r4_string, string r1_aux_string);
        void desplazamiento(string mensaje);
        void cifrado(string mensaje);
        void write();
        void mensaje_bin(string mensaje);
        void translate(string mensaje);
        void descifrado(string mensaje);
        void translate_des(string mensaje);

    };
