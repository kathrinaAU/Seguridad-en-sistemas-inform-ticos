#include "rc4.hpp"

rc4::rc4()
{
}

rc4::~rc4()
{
}

void rc4::ksa(string clave)
{
    // Inicializo el vector S
    for (int i = 0; i < 256; i++)
    {
        s.push_back(i);
    }

    // Tengo otro vector S para así mostrar luego en el write mi inicialización del vector S y su S modificado
    for (int i = 0; i < 256; i++)
    {
        s_aux.push_back(s[i]);
    }

    // Recorro la clave
    // Guardo cada posición de la clave que corresponde a un número.
    // Los números pueden ser formados por más de un número.
    // Recojo el valor de clave miestras no encuentre una coma.
    // Cuando encuentro la coma, es que finaliza ese número así que lo meto en el vector semilla.
    // Para meterlo en tipo número y no en tipo int, necesito hacerle un stoi antes.
    // Limpio la variable que almacena los dígitos para que no contenga nada correspondiente al dígito anterior.
    // Si no encuentro más comas es porque estoy tratando con el último número así que lo meto en el vector.
    for (int i = 0; i < clave.length(); i++)
    {
        clave_aux += clave[i];

        if (clave[i] == ',')
        {
            semilla.push_back(stoi(clave_aux));
            clave_aux.clear();
        }
    }
    semilla.push_back(stoi(clave_aux));

    // ALGORTIMO KSA
    for (int i = 0; i < 256; i++)
    {
        k.push_back(semilla[i % semilla.size()]);
    }

    int j = 0;
    int aux;
    for (int i = 0; i < 256; i++)
    {
        j = (j + s[i] + k[i]) % 256;
        aux = s[i];
        s[i] = s[j];
        s[j] = aux;
    }
}



// Hay que pasar el mensaje a un bitset para poder operar con él.
void rc4::working_msg2(string mensaje)
{
    int msg_aux;
    int aux = 0;
    stringstream auxi;

    // Como en el caso de la clave pues se necesita un bitset temporal y el bitset donde guardaré el resultado para luego operar.
    bitset<8> temp[v_mensaje.size()];
    msg_bin = new bitset<8>[v_mensaje.size()];

    // Recorremos el mensaje
    for (int i = 0; i < mensaje.length(); i++)
    {
    // Si en el mensaje encontramos una coma pues metemos lo anteriormente guardado en mensaje_aux.
    // Hay varios casos:

        // 1) Encontramos una coma
        if (mensaje[i] == ',')
        {
            // Limpliamos nuestra auxiliar y la inicializamos
            auxi.clear();
            auxi.str("");
            // Le decimos que va a contener a la string mensaje_aux
            auxi.str(mensaje_aux);

            // Ahora la guardamos en aux que es un int
            // Meto el entero en el vector del mensaje
            // Limpio la string mensaje_aux para pasar al siguiente
            auxi >> aux;
            v_mensaje.push_back(aux);
            mensaje_aux.clear();
        }

        // 2) LLegamos al final del mensaje
        else if (i == mensaje.length() - 1)
        {
            cout << " mensaje[i] 2 " << mensaje[i] << endl;
            // Como he llegado al final del mensaje pues se trata del último número asi que lo meto directamente en la string
            mensaje_aux += mensaje[i];
            // Limpliamos nuestra auxiliar y la inicializamos
            auxi.clear();
            auxi.str("");
            // Le decimos que va a contener a la string mensaje_aux
            auxi.str(mensaje_aux);

            // Ahora la guardamos en aux que es un int
            // Meto el entero en el vector del mensaje
            // Limpio la string mensaje_aux para pasar al siguiente
            auxi >> aux;
            v_mensaje.push_back(aux);
            mensaje_aux.clear();
        }
        // 3) Es un caso normal y simplemente almacenamos el número hasta saber que está completo
        else
        {
            mensaje_aux += mensaje[i];
        }
    }

    for (int i = 0; i < v_mensaje.size(); i++)
    {
        // El temporal contiene el entero del vector en forma de bitset de 8 bits
        // Almaceno ese dato pasandolo a unsigned long int en msg_bin
        temp[i] = bitset<8>(v_mensaje[i]);
        msg_bin[i] = temp[i];
    }
}


void rc4::prga(string mensaje)
{
    int i = 0;
    int j = 0;
    int aux;
    int t;

    // ALGORITMO PRGA
    for (int k = 0; k < v_mensaje.size(); k++)
    {
        i = (i + 1) % 256;
        j = (j + s[i]) % 256;

        aux = s[i];
        s[i] = s[j];
        s[j] = aux;

        t = (s[i] + s[j]) % 256;
        v_binario.push_back(s[t]);
    }

    // Para trabajar luego con la operación xor entre bits, necesito pasar el número obtenido en el PRGA a binario.
    // Creo un bitset temporal
    bitset<8> temp[mensaje.length()];
    // Este bitset ya se creó en el hpp y va a contener el resultado en binario del algoritmo.
    // Le asigno el tamaño.
    clave_bin = new bitset<8>[mensaje.length()];

    // Recorro la duración del mensaje.
    for (int k = 0; k < v_mensaje.size(); k++)
    {
        // Almaceno en el temporal lo que contiene el vector de PRGA pasandolo a bitset de 8 bits.

        temp[k] = bitset<8>(v_binario[k]);

        // Almaceno ese dato
        clave_bin[k] = temp[k];
    }

    cout << endl;
}




void rc4::prga2(string mensaje)
{
    int i = 0;
    int j = 0;
    int t = 0;
    int p = 0;
    const int w = 1;

    // ALGORITMO PRGA2
    for (int k = 0; k < v_mensaje.size(); k++)
    {
        i = (i + w) % 256;
        j = (p + s[((j + s[i]) % 256)]) % 256;
        p = (i + p + s[j]) % 256;

        int aux = s[i];
        s[i] = s[j];
        s[j] = aux;

        t = (s[(j + s[(i + s[(t + p) % 256]) % 256]) % 256]) % 256;

        v_binario.push_back(s[t]);
    }
    bitset<8> temp[v_mensaje.size()];
    clave_bin = new bitset<8>[v_mensaje.size()];

    for (int k = 0; k < v_mensaje.size(); k++)
    {
        temp[k] = bitset<8>(v_binario[k]);
        clave_bin[k] = temp[k];
    }
}


// Código de siempre... Operación XOR entre la clave y el mensaje
void rc4::cifrado(string mensaje)
{
    // Bitset en el que guardaré mi resultado
    msg_binario_cifrado = new bitset<8>[v_mensaje.size()];
    for (int i = 0; i < v_mensaje.size(); i++)
    {
        // Operación de XOR por cada bitset
        msg_binario_cifrado[i] = msg_bin[i] ^ clave_bin[i];
    }
}

// Método que pasa el bitset cifrado a números enteros para mostrarlo en la salida
void rc4::binario_decimal()
{
    // Recorro según el tamaño del vector del mensaje
    for (int i = 0; i < v_mensaje.size(); i++)
    {
        // Almaceno en una string el bitset del mensaje cifrado, pasado a unsigned long int, a int y luego a string para guardarlo.
        cifrado2 += to_string((int)msg_binario_cifrado[i].to_ulong());
    }
}

// Función para mostrar los datos
void rc4::write()
{
    cout << endl
         << endl;
    cout << "ENTRADA:" << endl
         << endl;

    cout << "Semilla clave: ";
    for (int i = 0; i < semilla.size(); i++)
    {

        if (i == semilla.size() - 1)
        {
            cout << semilla[i];
        }
        else
        {
            cout << semilla[i] << ", ";
        }
    }

    cout << endl
         << "Texto original: " << mensaje;
    for (int i = 0; i < v_mensaje.size(); i++)
    {
        cout << v_mensaje[i];
    }

    cout << endl
         << endl
         << "Inicialización: " << endl;
    cout << endl;
    cout << "S [ ";
    for (int i = 0; i < 256; i++)
    {
        if (i == 255)
        {
            cout << s_aux[i];
        }
        else
        {
            cout << s_aux[i] << ", ";
        }
    }
    cout << " ]" << endl
         << endl;

    cout << "K [ ";
    for (int i = 0; i < 256; i++)
    {
        if (i == 255)
        {
            cout << k[i];
        }
        else
        {
            cout << k[i] << ", ";
        }
    }
    cout << " ]" << endl;
    cout << endl;

    cout << endl
         << "TRAZA: "
         << endl
         << endl;

    cout << "S [ ";
    for (int i = 0; i < 256; i++)
    {
        if (i == 255)
        {
            cout << s[i];
        }
        else
        {
            cout << s[i] << ", ";
        }
    }
    cout << " ]" << endl
         << endl;

    cout << endl
         << " Salida:" << endl;
    cout << endl;

    cout << "Cifrado en binario: " << endl;
    for (int i = 0; i < v_mensaje.size(); i++)
    {
        cout << msg_binario_cifrado[i] << endl;
    }
    cout << endl;

    cout << "Cifrado en texto: " << cifrado2 << endl;

    cout << endl
         << endl;
    cout << "Generación de secuencia cifrante: y texto cifrado: " << endl;
    for (int i = 0; i < v_mensaje.size(); i++)
    {
        cout << "Byte" << i + 1 << " de secuencia cifrante: Salida " << v_binario[i] << " " << msg_bin[i] << endl;
        cout << "Byte" << i + 1 << " de texto original: Entrada " << v_mensaje[i] << " " << clave_bin[i] << endl;
        cout << "Byte" << i + 1 << " de texto cifrado: Salida " << to_string((int)msg_binario_cifrado[i].to_ulong()) << " " << msg_binario_cifrado[i] << endl;
    }
}