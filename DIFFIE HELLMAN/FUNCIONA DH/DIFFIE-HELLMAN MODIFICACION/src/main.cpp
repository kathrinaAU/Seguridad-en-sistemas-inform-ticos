#include <cstdio>
#include <iostream>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#include "dh.hpp"

using namespace std;

int main(void)
{

    Diffie_hellman obj;

    obj.comprueba();
    obj.op_Diffie_Hellman();
    obj.claves();

    return 0;
}
