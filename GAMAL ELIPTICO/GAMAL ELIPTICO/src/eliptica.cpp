#include "eliptica.hpp"
#include <iostream>
#include <sstream>
#include <bitset>
#include <string>
#include <math.h>

eliptica::~eliptica()
{
}

eliptica::eliptica()
{

    cout << endl;
    cout << " Bienvenido." << endl;

    if (lehman_peralta(primo) == true)
    {

        cout << " El número introducido es primo. " << endl;
    }
    else
    {
        in_troubles = true;
        problems(in_troubles);
    }

    calcula_puntos();
    codificacion_numerica();
    cifrado();
}

void eliptica::calcula_puntos()
{
    cout << endl
         << endl
         << "_______________________________________________________________" << endl
         << "CALCULANDO LOS PUNTOS DE LA RECTA: " << endl;
    puntos.clear();

    for (int i = 0; i < primo; i++)
    {
        int resultado = 0;
        resultado = pow(i, 3);
        resultado += a * i + b;
        resultado = resultado % primo;
        puntos.push_back(resultado);
    }

    for (int i = 0; i < primo; i++)
    {
        int resultado = 0;
        resultado = pow(i, 2);
        resultado = resultado % primo;
        puntos_y2.push_back(resultado);
    }
 
    for (int i = 0; i < primo; i++)
    {
        for (int j = 0; j < primo; j++)
        {
            if (puntos[i] == puntos_y2[j])
            {
                int x = i;
                int y = j;
                puntos_confirmados.push_back(x);
                las_x.push_back(x);
                puntos_confirmados.push_back(y);
                las_y.push_back(y);
            }
        }
    }
    cout << endl
         << "- Puntos confirmados: " << endl
         << endl << "   ";
    for (int i = 0; i < puntos_confirmados.size(); i++)
    {
        if (i % 2 == 0)
        {
            cout << "(" << puntos_confirmados[i] << ", ";
            i++;
        }
        cout << puntos_confirmados[i] << "), ";
    }

    cout << endl
         << endl;
}

void eliptica::sumar_puntos(int p_x_, int p_y_, int q_x, int q_y)
{

    cout << endl
         << endl
         << "_______________________________________________________________" << endl
         << " CALCULANDO SUMA DE DOS PUNTOS: " << endl;
    int lamda = 0;
    cout << " - P: " << p_x_ << " " << p_y_ << endl;
    cout << " - Q: " << q_x << " " << q_y << endl;

    resultado_suma.clear();

    cout << endl
         << "SUMANDO:  " << p_x_ << ", " << p_y_ << " + " << q_x << ", " << q_y << endl;

    if ((p_x_ == q_x) and (p_y_ == q_y))
    {
        cout << endl
             << "P = Q: " << endl;

        int numerador = (pow((p_x_), 2)) * 3 + a;
        int denominador = 2 * p_y_;
        if (numerador == 0)
        {
            lamda = 0;
        }
        else if (denominador == 0)
        {
            cout << endl
                 << endl
                 << " ERROR **** lamda es infinito. " << endl;
            in_troubles = 1;
            problems(in_troubles);
        }
        else if (numerador % denominador == 0)
        {
            lamda = (numerador / denominador);
        }
        else
        {
            int aux = euclides(denominador, primo);

            while (aux < 0)
            {
                aux = aux + primo;
            }

            lamda = aux * numerador;
        }
        cout << "   - Lamda es: " << lamda << " -> " << lamda%primo  << endl;
    }
    else
    {
        cout << endl
             << "P != Q: " << endl;

        int numerador = (q_y - p_y_);
        int denominador = (q_x - p_x_);

        if (denominador == 0)
        {
            cout << endl
                 << endl
                 << " ERROR **** lamda es infinito. " << endl;
            in_troubles = 1;
            problems(in_troubles);
        }
        else if (numerador == 0)
        {
            lamda = 0;
        }
        else if (numerador % denominador == 0)
        {
            lamda = numerador / denominador;
        }
        else
        {
            int aux = euclides(denominador, primo);

            while (aux < 0)
            {
                aux = aux + primo;
            }

            lamda =  aux * numerador;
        }
        cout << "    - Lamda es: " << lamda << " -> " << lamda%primo << endl;
    }

    int new_x = (pow(lamda, 2) - p_x_ - q_x);
    while (new_x < 0)
    {
        new_x += primo;
    }

    new_x = new_x % primo;

    int new_y = (((lamda * p_x_) - (lamda * new_x)) - p_y_);

    while (new_y < 0)
    {
        new_y += primo;
    }

    new_y = new_y % primo;

    resultado_suma.push_back(new_x);
    resultado_suma.push_back(new_y);

    cout << "   - P + Q = (" << resultado_suma[0] << "," << resultado_suma[1] << ")" << endl;
}

void eliptica::multiplicar_puntos(int multiplicador, int x, int y)
{
    cout << endl
         << endl
         << "_______________________________________________________________" << endl
         << " CALCULANDO MULTIPLICACION DE PUNTOS: " << endl;
    cout << "Multiplicar: " << db << "P, donde P es (" << p_x << ", " << p_y << ")" << endl;

    long long int it = multiplicador;

    while (it != 0)
    {
        sumar_puntos(x, y, x, y);
        aux_x = resultado_suma[0];
        aux_y = resultado_suma[1];
        it = it - 2;

        while ((it != 0) and (it != 1))
        {
            sumar_puntos(aux_x, aux_y, aux_x, aux_y);
            it = it - 2;
        }

        if (it == 1)
        {
            sumar_puntos(x, y, aux_x, aux_y);
            aux_x = resultado_suma[0];
            aux_y = resultado_suma[1];
            it = 0;
        }
    }
}

bool eliptica::lehman_peralta(long long int num_primo)
{
    v_r_a.clear();
    vector<long long int> v_peques = {2, 3, 5, 7, 11};
    srand(time(NULL));
    bool primo = true;
    long long int contador = 0;

    for (auto i = 0; i < v_peques.size(); i++)
    {
        if (num_primo % v_peques[i] == 0)
        {
            primo = true;
            return primo;
        }
    }

    for (auto i = 0; i < (num_primo / 2); i++)
    {
        long long int a = rand() % (num_primo - 1) + 2; // Numero aleatorio entre 2 y p-1
        v_a.push_back(a);
        long long int exponente = (num_primo - 1) / 2;
        long long int resultado = expon_rapida(a, exponente, num_primo);
        resultado = resultado % num_primo;
        v_r_a.push_back(resultado);
    }

    for (auto i = 0; i < v_r_a.size(); i++)
    {
        if (v_r_a[i] == 1)
        {
            contador++;
            if (contador == num_primo / 2)
            {
                primo = false;
                return primo;
            }
        }
        else if (v_r_a[i] != num_primo - 1)
        {
            primo = false;
            return primo;
        }
        else
        {
            primo = true;
            return primo;
        }
    }
}

long long int eliptica::euclides(long long int a, long long int b)
{
    
    long long int dividendo;
    long long int divisor;
    vector<long long int> x;
    vector<long long int> z;
    long long int i = 0;
    d = 0;
    z.push_back(0);
    z.push_back(1);

    if (a > b)
    {
        x.push_back(a);
        x.push_back(b);
        dividendo = a;
        divisor = b;
    }
    else if (b > a)
    {
        x.push_back(b);
        x.push_back(a);
        dividendo = b;
        divisor = a;
    }

    while ((x[i] % x[i + 1]) != 0)
    {

        long long int temp = -(x[i] / x[i + 1]) * z[i + 1] + z[i];
        z.push_back(temp);
        x.push_back(x[i] % x[i + 1]);
        i++;
    }

    long long int it = x.size() - 1;

    if (x[it] == 1)
    {
        if (z[it] < 0)
        {
            z[it] = fi_n + z[it];
        }
        d = z[it];
    }
    else
    {
        cout << " No son primos entre sí." << endl;
        in_troubles = true;
        problems(in_troubles);
    }

    return d;
}

void eliptica::codificacion_numerica()
{

    cout << endl
         << endl
         << "_______________________________________________________________" << endl
         << " CODIFICACION DE MENSAJE: " << endl;

    int mensaje_int;
    int aux = 0;
    int j = 0;

    for (int i = mensaje.size() - 1; i >= 0; i--)
    {
        if (mensaje[i] == 49)
        {
            aux += pow(2, j);
        }
        j++;
    }

    mensaje_int = aux;

    if (tam_alfabeto % 2 != 0)
    {
        cout << endl
             << " El tamaño del alfabeto no es potencia de 2." << endl;
        in_troubles = true;
        problems(in_troubles);
    }

    if ((0 >= mensaje_int) || (mensaje_int >= tam_alfabeto))
    {
        cout << endl
             << " Se incumple la siguiente restricción: 0<m<M." << endl;
        in_troubles = true;
        problems(in_troubles);
    }

    float temp = ((float)primo / (float)tam_alfabeto);

    for (auto i = tam_alfabeto; i >= 1; i--)
    {
        if (i <= (temp))
        {
            h = i;
            i = 0;
        }
    }

    int x_cod = 0;
    for (int i = 0; i <= h - 1; i++)
    {
        x_cod = (mensaje_int * h) + i;
        x_cod = x_cod % primo;
        for (int j = 0; j <= las_x.size(); j++)
        {
            if (x_cod == las_x[j])
            { // Compruebo que está en las coordenadas x que pertenecen
                x_pos_posibles.push_back(j);
                y_pos_posibles.push_back(j);
            }
        }
    }

    cout << endl
         << "   EL PUNTO CODIFICADO ES: ";
    cout << "(" << las_x[x_pos_posibles[0]] << ", " << las_y[y_pos_posibles[0]] << ")" << endl;
    punto_cod.push_back(las_x[x_pos_posibles[0]]);
    punto_cod.push_back(las_y[y_pos_posibles[0]]);
}

void eliptica::cifrado()
{
    cout << endl
         << endl
         << "_______________________________________________________________" << endl
         << " CIFRADO DEl MENSAJE: " << endl;
    cout << endl
         << " Datos para hacer: {Qm+aA(dBP), aAP}" << endl;
    cout << "aA: " << aA << endl;
    cout << "P (" << p_x << ", " << p_y << ")" << endl;
    
    multiplicar_puntos(aA, p_x, p_y);
    cout << endl
         << "---------------------------> aA*P: (" << resultado_suma[0] << ", " << resultado_suma[1] << ")" << endl << endl;
    int x_def = resultado_suma[0] ;
    int y_def = resultado_suma[1] ;
    multiplicar_puntos(db, resultado_suma[0] , resultado_suma[1] );
    cout << endl
         << "---------------------------> db(aA*P): (" << aux_x << ", " << aux_y << ")" << endl << endl;
    cout << endl
         << "- {Qm+aA(dBP), aAP} "
         << "{(" << punto_cod[0] << ", " << punto_cod[1] << " + (" << resultado_suma[0]  << ", " << resultado_suma[1]  << "), (" << x_def << ", " << y_def << ")}" << endl;
    sumar_puntos(punto_cod[0], punto_cod[1], resultado_suma[0] , resultado_suma[1] );
    cout << endl << endl
         << "RESULTADO FINAL CIFRADO: (" << resultado_suma[0] << ", " << resultado_suma[1] << "), (" << x_def << ", " << y_def << ")" << endl;
}

long long int eliptica::expon_rapida(long long int alpha, long long int secreto, long long int primo)
{
    long long int mod = primo;
    long long int x = 1;
    long long int y = alpha;
    long long int b = secreto;

    while ((b > 0) and (y > 1))
    {
        if (b % 2 == 0)
        {
            y = pow(y, 2);
            y = y % mod;
            b = b / 2;
        }
        else
        {
            b = b - 1;
            x = y * x;
            x = x % mod;
        }
    }
    return x;
}

void eliptica::problems(bool no_troubles)
{
    if (in_troubles == true)
    {
        cout << endl
             << "PROVOCANDO UN ABORTO, no cumplió los criterios especificados en el programa." << endl
             << endl;
        abort();
    }
}