#define _eliptica_H
#ifdef _eliptica_H

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

class eliptica
{

private:
    
    long long int primo = 13;
    long long int a = 5;
    long long int b = 3;
    long long int p_x = 9;
    long long int p_y= 6;
    long long int db = 2;
    string mensaje = "10";
    int tam_alfabeto = 4;
    int aA = 4;
    int h = 0;
    int aux_x = 0;
    int aux_y = 0;



    vector <long long int> msj;
    vector <long long int> puntos;
    vector <long long int> resultado_suma;
    vector <long long int> puntos_y2;
    vector <long long int> puntos_confirmados;
    vector <long long int> las_x;
    vector <long long int> las_y;
    vector <long long int> x_pos_posibles;
    vector <long long int> y_pos_posibles;
    vector < long long int> punto_cod;
    vector <long long int> v_r_a;
    vector <long long int> v_a;
    long long int n = 0;
    long long int fi_n = 0;
    long long int d = 0;
    long long int e = 0;
    

    bool in_troubles = false;

public:
    eliptica();
    ~eliptica();
    void calcula_puntos();
    void sumar_puntos(int p_x_, int p_y_, int q_x, int q_y);
    void multiplicar_puntos(int multiplicador, int x, int y);
    bool lehman_peralta(long long int num_primo);
    long long int euclides(long long int a, long long int b);
    void problems(bool no_troubles);
    long long int expon_rapida(long long int alpha, long long int secreto, long long int primo);
    void codificacion_numerica();
    string espacios (string mensaje);
    void cifrado();
    void descifrado();
    void traza();
};

#endif