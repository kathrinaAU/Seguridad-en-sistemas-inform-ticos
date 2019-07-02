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

class multiplicacion
{

private:
  string num1 = "";
  string num2 = "";
  int numero = 0;
  int cont = 0;

  vector<int> vector_num1;
  vector<int> vector_num2;
  vector<int> contador_n1;
  vector<int> contador_n2;
  vector<int> contador_n;

  vector<int> producto_vector = {0,0,0,0,0,0,0,0};
  vector<vector<int>> resultados;
  vector<int> aux;

  vector<int> multiplicador;
  vector<int> multiplicando;

  int contador_1 = 0;
  int contador_2 = 0;


  bitset<8> bitset_num_1;
  bitset<8> bitset_num_2;

  bitset<8> bit_multiplicando;
  bitset<8> bit_multiplicador;
  // bitset<8> bit_multiplicando_2;

 

public:

  multiplicacion();
  ~multiplicacion();

  void resultado_prod();
  void op_aritmetica();
  int hex_dec(string num);
  void factores(string byte);
  void producto(vector<int> multiplicando);
  vector<int> vuelta(vector<int> v);
  void mensaje_bin(string num1, string num2);

};
