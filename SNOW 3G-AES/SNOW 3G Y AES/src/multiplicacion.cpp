#include "multiplicacion.hpp"
#include <iostream>
#include <sstream>
#include <bitset>
#include <string>

multiplicacion::multiplicacion()
{
}

multiplicacion::~multiplicacion()
{
}

int multiplicacion::hex_dec(string num)
{
    // Hay que pasar el numero hexadecimal a decimal
    int aux = 0;
    stringstream ss;
    ss << hex << num;
    unsigned n;
    ss >> n;
    int numero = n;

    return numero;
}

void multiplicacion::mensaje_bin(string num1, string num2)
{
    int numerito_1 = hex_dec(num1);
    int numerito_2 = hex_dec(num2);
    vector<int> prueba;

    // Quien es el que tiene más unos?
    int cp_num1 = numerito_1;
    while (cp_num1 > 0)
    {
        if (cp_num1 % 2 == 0)
        {
            prueba.push_back(0);
        }
        else
        {
            prueba.push_back(1);
        }
        cp_num1 = cp_num1 / 2;
    }

    cout << endl;
    for (int i = prueba.size() - 1; i >= 0; i--)
    {
        int aux = prueba[i];
        vector_num1.push_back(aux);
    }

    cout << endl;

    for (int i = 0; i < vector_num1.size(); i++)
    {
        if (vector_num1.size() < 8)
        {
            vector_num1.insert(vector_num1.begin(), 0);
        }
    }

    cout << "Número 1 en vector: ";
    for (int i = 0; i < vector_num1.size(); i++)
    {
        cout << vector_num1[i];
    }

    // Introduzco lo del vector al bitset
    int k = vector_num1.size() - 1;
    for (int i = vector_num1.size() - 1; i >= 0; i--)
    {
        bitset_num_1.set(i, vector_num1[k]);
        k--;
    }

    prueba.clear();
    int cp_num2 = numerito_2;

    while (cp_num2 > 0)
    {
        if (cp_num2 % 2 == 0)
        {
            prueba.push_back(0);
        }
        else
        {
            prueba.push_back(1);
        }
        cp_num2 = cp_num2 / 2;
    }

    cout << endl;
    for (int i = prueba.size() - 1; i >= 0; i--)
    {
        int aux = prueba[i];
        vector_num2.push_back(aux);
    }

    for (int i = 0; i < vector_num2.size(); i++)
    {
        if (vector_num2.size() < 8)
        {
            vector_num2.insert(vector_num2.begin(), 0);
        }
    }

    cout << "Número 2 en vector: ";
    for (int i = 0; i < vector_num2.size(); i++)
    {
        cout << vector_num2[i];
    }
    // Introduzco lo del vector al bitset
    int q = vector_num2.size() - 1;
    for (int i = vector_num2.size() - 1; i >= 0; i--)
    {
        bitset_num_2.set(i, vector_num2[q]);
        q--;
    }
}

void multiplicacion::op_aritmetica()
{
    // Voy a ver que polinomio tiene menos 1 para seleccionarlo:
    vector<int> nuevo_1 = vuelta(vector_num1);
    vector<int> nuevo_2 = vuelta(vector_num2);

    for (int i = 0; i < vector_num1.size(); i++)
    {
        if (nuevo_1[i] == 1)
        {
            contador_1++;
            contador_n1.push_back(i);
        }
    }
    for (int i = 0; i < vector_num2.size(); i++)
    {
        if (nuevo_2[i] == 1)
        {
            contador_2++;
            contador_n2.push_back(i);
        }
    }
    if (contador_n1.size() > contador_n2.size())
    {

        contador_n = contador_n2;
    }
    else
    {
        contador_n = contador_n1;
    }

    cout << "Utilizaremos los desplazamientos: ";
    for (int i = 0; i < contador_n.size(); i++)
        cout << contador_n[i] << " ";
}

void multiplicacion::factores(string byte)
{

    for (int i = 0; i < byte.length(); i++)
    {
        if (byte[i] == 48)
        {
            multiplicador.push_back(0);
        }
        else
        {
            multiplicador.push_back(1);
        }
    }

    if (multiplicador.size() < 8)
    {
        while (multiplicador.size() != 8)
        {
            multiplicador.insert(multiplicador.begin(), 0);
        }
    }

    for (int i = 0; i < multiplicador.size(); i++)
    {
        cout << multiplicador[i];
    }

    // Introduzco lo del vector al bitset
    int q = multiplicador.size() - 1;
    for (int i = multiplicador.size() - 1; i >= 0; i--)
    {
        bit_multiplicador.set(i, multiplicador[q]);
        q--;
    }

    if (contador_1 > contador_2)
    {
        multiplicando = vector_num1;
        cont = contador_2;
    }
    else
    {
        multiplicando = vector_num2;
        cont = contador_1;
    }

    int p = multiplicando.size() - 1;
    for (int i = multiplicando.size() - 1; i >= 0; i--)
    {
        bit_multiplicando.set(i, multiplicando[p]);
        p--;
    }
    cout << endl;
    producto(multiplicando);
}

vector<int> multiplicacion::vuelta(vector<int> v)
{
    vector<int> aux;
    aux.clear();

    for (int i = 0; i < v.size(); i++)
    {

        int azucar = v[i];
        aux.insert(aux.begin(), azucar);
    }

    cout << endl;
    return aux;
}

void multiplicacion::producto(vector<int> multiplicando)
{

    resultados.push_back(multiplicando);

    for (int j = 1; j < 8; j++)
    {
        aux.clear();

        // Si en el primero o anterior tiene un 0 pues desplazo y ya
        if (resultados[j - 1][0] == 0)
        {
            multiplicando.insert(multiplicando.end(), 0);
            multiplicando.erase(multiplicando.begin(), multiplicando.begin() + 1);
        }
        else // Sino lo tiene entonces tengo que  hacer un xor con el otro
        {    // Me quedo con el byte desplazado y metiendo el 0 antes de hacer la xor
            multiplicando.insert(multiplicando.end(), 0);
            multiplicando.erase(multiplicando.begin(), multiplicando.begin() + 1);

            for (int i = 0; i < multiplicando.size(); i++)
            {

                int mete = multiplicando[i] ^ multiplicador[i];
                aux.push_back(mete);
            }

            multiplicando = aux;
        }

        resultados.insert(resultados.begin() + j, multiplicando);
    }
    cout << endl
         << endl
         << "************************************"
         << endl
         << "    Desplazamientos y resultados " << endl;
    for (int q = 0; q < resultados.size(); q++)
    {
        cout << endl
             << "*       Desplazamiento: " << q << endl;
        cout << "*       Resultado: ";
        for (int i = 0; i < 8; i++)
        {
            cout << resultados[q][i];
        }
        cout << endl;
    }
    cout << endl
         << "************************************" << endl;
}

void multiplicacion::resultado_prod()
{
    vector<int> prueba;
    int k = 0;

    for (int i = 0; i < contador_n.size(); i++)
    {
        for (int j = 0; j < producto_vector.size(); j++)
        {
            producto_vector[j] = resultados[contador_n[i]][j] ^ producto_vector[j];
        }
    }
    cout << endl
         << " PRODUCTO entre: ";

    for (int i = 0; i < vector_num1.size(); i++)
    {
        cout << vector_num1[i];
    }
    cout << " y ";

    for (int i = 0; i < vector_num2.size(); i++)
    {
        cout << vector_num2[i];
    }
    cout << " = ";
    for (int j = 0; j < 8; j++)
    {

        cout << producto_vector[j];
    }
    cout << endl;
}
