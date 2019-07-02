
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

class vigenere{

    private:
        string clave;
        string msg_inicial;
        vector <int> v_clave;
        vector <int> v_msg_inicial;
        vector <int> v_resultado;
        string msg_dividido;
        string clave_dividido;

        string resultado_string;
        string resultado_junto;
        string resultado_string_descifrado;
        string resultado_descifrado_junto;
        vector <int> v_descifrado;
        string anadidos = "=>?@";

       

    public:
        
        vigenere(void);
        vigenere(string msg_inicial, string clave);
        ~vigenere(void);
        void enumeracion(string msg_inicial, string clave);
        void dividir(string msg_inicial, string clave);
        void cifrado(string msg_inicial);
        void descifrado();
        void write(string msg_inicial, string clave);
        void write2(string msg_inicial, string clave);

};