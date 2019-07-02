#define DIFFIE
#ifdef DIFFIE

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

class Diffie_hellman
{

private:
  int Ya = 0;
  int Yb = 0;
  int primo = 0;
  int alpha = 0;
  int Xa = 0;
  int Xb = 0;
  int Ka = 0;
  int Kb = 0;
  int secreto_a = 0;
  int secreto_b = 0;
  int ciao = 0;
  bool no_troubles = false;
  vector<int> x_;
  vector<int> y_;
  vector<int> k_;
  int usuarios = -1;

public:
  Diffie_hellman();
  ~Diffie_hellman();

  bool comprueba();
  void op_Diffie_Hellman();
  int expon_rapida(int alfa, int secreto, int primo);
  void claves();
  void traza();
  int problems(bool no_troubles);
};

#endif