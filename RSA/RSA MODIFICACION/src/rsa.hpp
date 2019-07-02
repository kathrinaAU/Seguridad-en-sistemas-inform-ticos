#define _RSA_H
#ifdef _RSA_H

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
#include <time.h>


using namespace std;

class Rsa
{

private:
    
    long long int primo = 1123;
    long long int primo2 = 3527;
    vector <long long int> v_a;
    vector <long long int> v_r_a;
    long long int n = 0;
    long long int fi_n = 0;
    long long int d = 0;
    long long int e = 749395;
    string mensaje = "EL_PRESENTE_YA_ES_PASADO";
    string mensaje_copia;
    string copia = mensaje;
    long long int tam_bloque = 0;
    vector<long long int> v_mensaje;
    vector<long long int> v_msj_cod;
    vector<long long int> v_aux;
    vector<long long int> v_cifrado;
    vector<long long int> v_descifrado;
    bool in_troubles = false;

public:
    Rsa();
    ~Rsa();

    bool lehman_peralta(long long int num_primo);
    long long int euclides(long long int a, long long int b);
    void problems(bool no_troubles);
    long long int expon_rapida(long long int alpha, long long int secreto, long long int primo);
    void codificacion_numerica(string mensaje);
    string espacios (string mensaje);
    void cifrado();
    void descifrado();
    void traza();
};

#endif