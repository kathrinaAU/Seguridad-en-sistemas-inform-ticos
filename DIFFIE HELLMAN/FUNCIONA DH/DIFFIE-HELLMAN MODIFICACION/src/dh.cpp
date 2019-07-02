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
         << "Introduzca el número de usuarios. " << endl;
        cin >> usuarios;
    
    

    cout << endl
         << "Ingrese el número primo p. Ejemplo: 13." << endl;
    cin >> primo;

    cout << endl
         << "Ingrese el número alpha (alpha < p). Ejemplo: 4." << endl;
    cin >> alpha;

    for (int i = 0; i < usuarios; i++){
         cout << endl
         << "Ingrese el secreto X." << endl;
        cin >> secreto_a;
        // Xa = secreto_a;
        x_.push_back(secreto_a);
    }
   
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
       
            
        int ind = 0;
        int ind2 = 1;  
        for (int i = 0; i < (usuarios); i++){
            secreto_a = x_[ind];
            secreto_b = x_[ind2];
             cout << endl
             << endl
             << " ------------- Obteniendo Ya y Yb:  ------------- " << endl;
            cout <<endl << "secreto " << secreto_a << " antes  ind " << ind << endl;
            cout << "secreto " << secreto_b << " antes ind2 " << ind2 << endl;
            // ab = 10; bc=3; cd = 3; da=3; 
            ind = (ind+1)%usuarios;
            ind2 = (ind2+1)%usuarios;

            // cout << " siguiente  ind " << ind << endl;
            // cout << " siguiente ind2 " << ind2 << endl;


            Ya = expon_rapida(alpha, secreto_a, primo);
            y_.push_back(Ya);
            cout << " Ya: " << Ya << endl;
            Yb = expon_rapida(alpha, secreto_b, primo);
            cout << " Yb: " << Yb << endl;
            y_.push_back(Yb);

            cout << endl
                << " ------------- Obteniendo Ka y Kb:  ------------- " << endl;
            Ka = expon_rapida(Yb, secreto_a, primo);
            k_.push_back(Ka);
            Kb = expon_rapida(Ya, secreto_b, primo);
            k_.push_back(Ka);
            // ind = ind+1;
            // ind2 = ind2+2;
            
        }
       
    }
    break;

    case 0:
    {
        cout << endl
             << endl
             << " ------------- Obteniendo Ya y Yb:  ------------- " << endl;
        int ind = 0;
        int ind2 = 1;    
        for (int i = 0; i < usuarios/2; i++){
            secreto_a = x_[ind];
            secreto_b = x_[ind2];

            Ya = pow(alpha, secreto_a);
            Ya = Ya % primo;
            y_.push_back(Ya);
            Yb = pow(alpha, secreto_b);
            Yb = Yb % primo;
            y_.push_back(Yb);

            cout << endl
                << endl
                << " ------------- Obteniendo Ka y Kb:  ------------- " << endl;
            Ka = pow(Yb, secreto_a);
            Ka = Ka % primo;
            k_.push_back(Ka);
            Kb = pow(Ya, secreto_b);
            Kb = Kb % primo;
            k_.push_back(Kb);
            ind = ind+2;
            ind2 = ind2+2;
        }
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
            // cout << endl
            //      << " - CASO PAR:  " << endl;
            y = pow(y, 2);
            y = y % mod;
            b = b / 2;
            // cout << "       y es: " << y << "   b es: " << b << endl;
        }
        else
        {
            // cout << " - CASO IMPAR " << endl;
            b = b - 1;
            x = y * x;
            x = x % mod;
            // cout << "       x es: " << x << "   b es: " << b << endl;
        }
    }

    return x;
}

void Diffie_hellman::claves()
{
    if (ciao == 0)
    {
        // cout << endl
        //      << endl
        //      << " Comprobando igualdad en las claves: " << endl;

        // cout << endl
        //      << " Ka: " << Ka << "  Kb: " << Kb << endl;

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
    cout << " p = " << primo << ", alpha = " << alpha << " " << endl;
    for (int i = 0; i < x_.size(); i++){
        cout << " X: " << x_[i];
    }
    cout << endl << endl;
    
    for (int i = 0; i < y_.size(); i++){
        cout << " Y: " << y_[i];
    }
    cout <<  endl << endl;
    cout << " A-B/B-A   B-C/C-B   C-D/D-C   D-A/A-D " << endl;
    for (int i = 0; i < k_.size(); i++){
        cout << "K: " << k_[i] << " ";
    }
    cout << endl << endl;

    
}
