#include "fs.hpp"
#include <iostream>
#include <sstream>
#include <bitset>
#include <string>

Fiat_shamir::~Fiat_shamir()
{
}

Fiat_shamir::Fiat_shamir()
{

    cout << endl;
    cout << " Bienvenido." << endl;
    cout << endl
         << "Ingrese el primer número primo p. Ejemplo: 7." << endl;
    cin >> primo;

    cout << endl
         << "Ingrese el segundo número primo q. Ejemplo: 5." << endl;
    cin >> primo2;

    // ¿Son números primos?
    if (comprueba(primo) == false)
    {
        problems(no_troubles);
    }

    if (comprueba(primo2) == false)
    {
        problems(no_troubles);
    }

    cout << endl
         << "Escoja un número secreto s tal que 0<s<N, y es primo con N. Ejemplo: 3" << endl;
    cin >> s;

    n = primo * primo2;

    // ¿s es primo de n?
    comprueba_primo(s);
    if (s >= n)
    {
        no_troubles = false; // Es falso que estemos sin problemas
        problems(no_troubles);  // problems(0);
    }

    // Empezamos a hacer los cálculos
    op_Fiat_shamir(); 
}

bool Fiat_shamir::comprueba_primo(long int s)
{
    for (int i = 1; i <= s; i++)
    {
        if ((s % i == 0) and (n % i == 0) and (i !=1) )
        {
            cout <<endl << "No es primo, tienen divisores en comun: " << i << " ";
            problems(0);
        }

    }
}

bool Fiat_shamir::comprueba(long int primo)
{
    int divisor = 1, divisores = 0, num = 0;

    do
    {
        if (primo % divisor == 0)
        {
            divisores++;
        }
        divisor++;

    } while (divisor <= primo);

    if (divisores == 2)
    {
        no_troubles = true;
        return no_troubles;
    }

    else
    {
        no_troubles = false;
        return no_troubles;
    }
}

void Fiat_shamir::op_Fiat_shamir()
{
    //srand(time(NULL));
    cout << endl
         << endl
         << " ------------- FIAT-SHAMIR  ------------- " << endl;

    v = pow(s, 2);
    v = v % n;

    cout << " Ingrese el número de iteraciones a realizar: " << endl;
    cin >> iteraciones;

    for (int i = 0; i < iteraciones; i++)
    {
        cout << endl
             << "Ingrese el primer secreto Xa tal que 0<X<N. Ejemplo: 16" << endl;
        cin >> secreto_a;

        // Criterios del secreto 0<X<N
        if (secreto_a > 0 and secreto_a < n)
        {
            secretos.push_back(secreto_a);
        }
        else
        {
            no_troubles = false;
            problems(no_troubles); // problems(0);
        }

        // Reto servidor
        cout << "Ingrese el bit de reto para servidor. (0-1)" << endl;
        cin >> reto;

        // Reto debe ser 0-1
        if (reto != 0)
        {
            if (reto != 1)
            {
                no_troubles = false;
                problems(no_troubles); // problems(0);
            }
        }

        retos.push_back(reto);
        cout << endl;

        // Reto usuario
        cout << "Ingrese el bit de reto para usuario. (0-1)" << endl;
        cin >> reto_usu;

        // Reto debe ser 0-1
        if (reto_usu != 0)
        {
            if (reto_usu != 1)
            {
                no_troubles = false;
                problems(no_troubles);
            }
        }

        retos_usuario.push_back(reto_usu);
        cout << endl;
    }
    
    // int num = rand();
    // for (int i = 0; i < iteraciones; i++)
    // {

    //     // num = num = rand() % 2;
    //     // retos_usuario.push_back(num);
    //     retos_usuario.push_back(0);
    //     retos_usuario.push_back(1);
    //     retos_usuario.push_back(1);
    //     retos_usuario.push_back(1);
    //     cout << retos_usuario[i] << " ";
    // }

    for (int i = 0; i < iteraciones; i++)
    {
        // a = x^2(mod n)
        a = pow(secretos[i], 2);
        a = a % n;
        a_v.push_back(a); //Por si las moscas, a vector auxiliar

        // Calculamos y según reto de usuario:
        if (retos_usuario[i] == 0)
        {
            y = secretos[i] % n; // y = x(mod n)
        }
        else
        {
            y = (secretos[i] * s) % n; // y = x*s(mod n)
        }

        y_v.push_back(y); // Meto el y a un vector

        // temp = y^2 para comprobar que es igual a lo del servidor
        long int temp = pow(y, 2);
        temp = temp % n;
        y_temp.push_back(temp);

        // Para servidor
       
        if (retos[i] == 0)
        {
            y_servidor = a % n; // y = a(mod n)
        }
        else
        {
            y_servidor = (a * v) % n; // y = a*v(mod n)
        }

        y_serv.push_back(y_servidor); 
    }
    verifica();
}

void Fiat_shamir::verifica()
{
    cout << " VERIFICANDO " << endl;

    bool continua = false;

    for (int i = 0; i < y_serv.size(); i++)
    {
        cout << " y_temp[i] " << y_temp[i] << " == "
             << " y_serv[i] " << y_serv[i] << endl;
        if (y_temp[i] == y_serv[i])
        {
            continua = true;
        }
        else
        {
            continua = false;
            problems(continua); //problems(0);
        }
    }

    // Cuando verificamos que todos son iguales
    if (continua == true)
    {
        traza_entrada();
    }
}

void Fiat_shamir::traza_entrada()
{
    cout << endl
         << endl
         << " ------------------------- TRAZA: ------------------------ " << endl;
    cout << "Entrada:" << endl;
    cout << "\t a. p=" << primo << ", q=" << primo2 << endl;
    cout << "\t b. s=" << s << endl;
    cout << "\t c. i=" << iteraciones << endl;

    for (int i = 0; i < iteraciones; i++)
    {
        if (retos[i] == 0)
        {
            cout << "\t " << d << ". " << i + 1 << "ª iteración: x=" << secretos[i] << ", e=" << retos[i] << endl;
            d++;
        }
        else
        {
            cout << "\t " << d << ". " << i + 1 << "ª iteración: x=" << secretos[i] << ", e=" << retos[i] << endl;
            d++;
        }
    }

    cout << "Salida:" << endl;
    cout << "\t a. N=" << n << endl;
    cout << "\t b. v=" << v << endl;
    char c = 'c';

    for (int j = 0; j < iteraciones; j++)
    {
        if (retos[j] == 0)
        {
            cout << "\t " << c << ". " << j + 1 << "ª iteración: a=" << a_v[j] << ", comprobar que " << y_v[j] << "^2 = " << a_v[j] << "(mod" << n << ") y dar por válida la iteración." << endl;
            c++;
        }
        else
        {
            cout << "\t " << c << ". " << j + 1 << "ª iteración: a=" << a_v[j] << ", y = " << y_v[j] << ", comprobar que " << y_v[j] << "^2 = " << a_v[j] << "*" << v << "(mod" << n << ") y dar por válida la iteración." << endl;
            c++;
        }
    }
}

int Fiat_shamir::problems(bool no_troubles)
{
    if (no_troubles == false)
    {
        cout << endl
             << "PROVOCANDO UN ABORTO, no cumplió los criterios especificados en el programa." << endl
             << endl;
        abort();
    }
}