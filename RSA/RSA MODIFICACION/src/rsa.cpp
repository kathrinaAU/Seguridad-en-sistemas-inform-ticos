#include "rsa.hpp"
#include <iostream>
#include <sstream>
#include <bitset>
#include <string>

Rsa::~Rsa()
{
}

Rsa::Rsa()
{

    cout << endl;
    cout << " Bienvenido." << endl;
    // cout << endl
    //      << "Ingrese el primer número primo p. Ejemplo: 7." << endl;
    // cin >> primo;

    // cout << endl
    //      << "Ingrese el segundo número primo q. Ejemplo: 5." << endl;
    // cin >> primo2;

    if ((lehman_peralta(primo) == true) && (lehman_peralta(primo2) == true))
    {

        cout << " Los números introducidos son primos " << endl;
    }
    else
    {
        in_troubles = true;
        problems(in_troubles);
    }

    n = primo * primo2;
    fi_n = (primo - 1) * (primo2 - 1);

    // cout << endl
    //      << "Ingrese el número d. Ejemplo: 5." << endl;
    // cin >> d;

    euclides(e, fi_n);

    // cout << endl
    //      << "Introduzca el texto a cifrar:" << endl;
    // getline(cin, mensaje);
    // getline(cin, mensaje);

    
    codificacion_numerica(mensaje);
    cifrado();
    descifrado();
    traza();
}

bool Rsa::lehman_peralta(long long int num_primo)
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






long long int Rsa::euclides(long long int a, long long int b)
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
        // if( (z[it]*divisor) % dividendo == 1){
            d = z[it];
        // }else{
        //     d= NULL;
        //     cout << endl << " El valor de e es no valido." << endl;
        // }

    }
    else
    {
        cout << " No son primos entre sí." << endl;
        in_troubles = true;
        problems(in_troubles);
    }

    return d;
}



void Rsa::codificacion_numerica(string mensaje)
{
    int tam_alfabeto = 30;
    bool ya = false;

    for (long long int i = 0; i <= n && ya == false; i++)
    {
        long long int aux = pow(tam_alfabeto, i);
        if (aux > n)
        {
            tam_bloque = i - 1;
            ya = true;
        }
    }

    mensaje = espacios(mensaje);
    
    for (auto i = 0; i < mensaje.size(); i++)
    {
        long long int aux;
        if (mensaje[i] == '.'){
                aux = 46;
        }
        if (mensaje[i] == '_'){
                aux = 95;
        }
        if (mensaje[i] == '*'){
            aux = 42;
        }
        if (mensaje[i] == '#'){
            aux = 35;
        }
        if ( (mensaje[i] != '#') && (mensaje[i] != '.') && (mensaje[i] != '_') && (mensaje[i] != '*')){
            aux = (long long int)mensaje[i] - 65;
        }
            
        
        v_mensaje.push_back(aux);
    }

    long long int dato = 0;
    long long int it = 0;

    for (long long int i = 0; i < mensaje.size(); i = i++)
    {
        dato = 0;
        for (long long int j = tam_bloque - 1; j >= 0; j--)
        {
            dato += v_mensaje[i] * pow(30, j);
            i++;
        }

        v_msj_cod.push_back(dato);
    }
}


string Rsa::espacios(string mensaje)
{
    mensaje_copia.clear();
    for (auto i = 0; i < mensaje.size(); i++)
    {

        if (mensaje[i] == ' ')
        {
            i++;
        }
        mensaje_copia += mensaje[i];
    }

    while (mensaje_copia.size() % tam_bloque != 0)
    {
        mensaje_copia += "X";
    }

    return mensaje_copia;
}


void Rsa::cifrado()
{
    for (long long int i = 0; i < v_msj_cod.size(); i++)
    {
        long long int aux = 0;
        aux = expon_rapida(v_msj_cod[i], e, n);

        v_cifrado.push_back(aux);
    }
}

void Rsa::descifrado()
{
    for (long long int i = 0; i < v_cifrado.size(); i++)
    {
        long long int aux = 0;
        aux = expon_rapida(v_cifrado[i], d, n);
        v_descifrado.push_back(aux);
    }
}

long long int Rsa::expon_rapida(long long int alpha, long long int secreto, long long int primo)
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

void Rsa::traza()
{
    cout << endl
         << endl;
    cout << "   - p = " << primo << endl;
    cout << "   - q = " << primo2 << endl;
    cout << "   - d = " << d << endl;
    cout << "   - n = " << n << endl;
    cout << "   - Φ(n) = " << fi_n << endl;
    cout << "   - e = " << e << endl;
    cout << "   - Tamaño del bloque = " << tam_bloque << endl;
    cout << "   - Mensaje original: " << mensaje << endl;
    cout << "   - Mensaje sin espacios: " << mensaje_copia << endl;
    cout << "   - Mensaje codificado: ";
    for (auto i = 0; i < v_msj_cod.size(); i++)
    {
        cout << v_msj_cod[i] << " ";
    }
    cout << endl;
    cout << "   - Mensaje cifrado ";
    for (auto i = 0; i < v_cifrado.size(); i++)
    {
        cout << v_cifrado[i] << " ";
    }
    cout << endl;
    cout << "   - Mensaje descifrado ";
    for (auto i = 0; i < v_descifrado.size(); i++)
    {
        cout << v_descifrado[i] << " ";
    }
    cout << endl << endl;
}

void Rsa::problems(bool no_troubles)
{
    if (in_troubles == true)
    {
        cout << endl
             << "PROVOCANDO UN ABORTO, no cumplió los criterios especificados en el programa." << endl
             << endl;
        abort();
    }
}