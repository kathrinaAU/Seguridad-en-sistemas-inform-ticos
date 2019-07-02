#define _FS_H
#ifdef _FS_H

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

class Fiat_shamir
{

private:
    long int primo = 0;
    long int primo2 = 0;
    int iteraciones;
    vector<long int> secretos;
    vector<long int> retos;
    vector<long int> retos_usuario;
    long int n = 0;
    long int s = 0;
    long int v = 0;
    long int a = 0;
    long int y = 0;
    vector<long int> a_v;
    vector<long int> y_v;
    vector<long int> y_serv;
    vector<long int> y_temp;
    vector<long int> div_s;
    vector<long int> div_n;
    long int y_servidor = 0;
    long int temp = 0;
    char d = 'd';
    char c = 'c';

    long int secreto_a = 0;
    long int secreto_b = 0;
    long int reto = 0;
    long int reto_usu = 0;
    int ciao = 0;
    bool no_troubles = false;

public:
    Fiat_shamir();
    ~Fiat_shamir();

    void op_Fiat_shamir();
    void verifica();
    void traza_entrada();

    bool comprueba(long int primo);
    bool comprueba_primo(long int s);
    int problems(bool no_troubles);
};

#endif