#include "dh.hpp"
#include <iostream>
#include <sstream>
#include <bitset>
#include <string>

Diffie_hellman::Diffie_hellman()
{

    cout << endl;
    cout << " Bienvenido." << endl;
    cout << endl
         << "Ingrese el número primo p. Ejemplo: 13." << endl;
    cin >> primo;

    cout << endl
         << "Ingrese el número alpha (alpha < p). Ejemplo: 4." << endl;
    cin >> alpha;

    cout << endl
         << "Ingrese el secreto Xa. Ejemplo: 5" << endl;
    cin >> secreto_a;
    Xa = secreto_a;

    cout << endl
         << "Ingrese el secreto Xb. Ejemplo: 2" << endl;
    cin >> secreto_b;
    Xb = secreto_b;
}

Diffie_hellman::~Diffie_hellman()
{
}

bool Diffie_hellman::comprueba()
{
    cout << endl
         << "Comprobando los datos introducidos." << endl;

    // El número es primo?
    int divisor = 1, divisores = 0, num = 0;

    do
    {
        if (primo % divisor == 0)
        {
            divisores++;
        }
        divisor++;

    } while (divisor <= primo);

    if ((divisores == 2) and (primo > alpha))
    {
        cout << "El numero " << primo << " es PRIMO y el número primo es mayor que alpha." << endl;
        no_troubles = true;
        return no_troubles;
    }
    else if (primo < alpha)
    {
        cout << "El numero " << primo << " es menor que alpha." << endl;
        no_troubles = false;
        return no_troubles;
    }
    else
    {
        cout << "El numero " << primo << " NO es PRIMO." << endl;
        no_troubles = false;
        return no_troubles;
    }
    
}

int Diffie_hellman::problems(bool no_troubles)
{
    if (no_troubles == false)
    {
        cout << endl << "PROVOCANDO UN ABORTO, no cumplió los criterios especificados en el programa." << endl << endl;
        abort();
    }
}

void Diffie_hellman::op_Diffie_Hellman()
{
    
    problems(no_troubles);
    int opcion = -1;
    bool no_valida = false;

    cout << endl
         << endl
         << "¿Desea emplear exponenciación rápida? Use la tecla 1 para indicar que sí y la tecla 0 para indicar que no." << endl;
    cin >> opcion;
    switch (opcion)
    {
    case 1:
    {
        cout << endl
             << endl
             << " ------------- Obteniendo Ya y Yb:  ------------- " << endl;
        Ya = expon_rapida(alpha, secreto_a, primo);
        Yb = expon_rapida(alpha, secreto_b, primo);

        cout << endl
             << " ------------- Obteniendo Ka y Kb:  ------------- " << endl;
        Ka = expon_rapida(Yb, secreto_a, primo);
        Kb = expon_rapida(Ya, secreto_b, primo);
    }
    break;

    case 0:
    {
        cout << endl
             << endl
             << " ------------- Obteniendo Ya y Yb:  ------------- " << endl;
        Ya = pow(alpha, secreto_a);
        Ya = Ya % primo;
        Yb = pow(alpha, secreto_b);
        Yb = Yb % primo;

        cout << endl
             << endl
             << " ------------- Obteniendo Ka y Kb:  ------------- " << endl;
        Ka = pow(Yb, secreto_a);
        Ka = Ka % primo;
        Kb = pow(Ya, secreto_b);
        Kb = Kb % primo;
    }

    break;
    default:
    {
        cout << endl
             << " Opción no válida." << endl;
        ciao = 1;
    }
    break;
    }
}

int Diffie_hellman::expon_rapida(int alpha, int secreto, int primo)
{
    cout << endl
         << endl
         << "EXPONENCIACIÓN RÁPIDA: " << endl;
    cout << endl
         << "   ALPHA: " << alpha << endl;
    cout << "   SECRETO: " << secreto << endl;
    cout << "   PRIMO: " << primo << endl
         << endl;

    int mod = primo;
    int x = 1;
    int y = alpha;
    int b = secreto;

    while ((b > 0) and (y > 1))
    {
        if (b % 2 == 0)
        {
            cout << endl
                 << " - CASO PAR:  " << endl;
            y = pow(y, 2);
            y = y % mod;
            b = b / 2;
            cout << "       y es: " << y << "   b es: " << b << endl;
        }
        else
        {
            cout << " - CASO IMPAR " << endl;
            b = b - 1;
            x = y * x;
            x = x % mod;
            cout << "       x es: " << x << "   b es: " << b << endl;
        }
    }

    return x;
}

void Diffie_hellman::claves()
{
    if (ciao == 0)
    {
        cout << endl
             << endl
             << " Comprobando igualdad en las claves: " << endl;

        cout << endl
             << " Ka: " << Ka << "  Kb: " << Kb << endl;

        if (Ka != Kb)
        {
            cout << " - UPS! CLAVES DISTINTAS." << endl;
        }
        else
        {
            traza();
        }
    }
    else
    {
        cout << " CIAO." << endl;
    }
}

void Diffie_hellman::traza()
{
    cout << endl
         << endl
         << " ------------------------- TRAZA: ------------------------ " << endl;
    cout << " p = " << primo << ", alpha = " << alpha << ", Xa = " << Xa << ", Xb = " << Xb << ", Ya = " << Ya << ", Yb = " << Yb << ", K = " << Ka << endl;
}
