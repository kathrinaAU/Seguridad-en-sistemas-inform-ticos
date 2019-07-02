
#include "vigenere.hpp"

using namespace std;

vigenere::vigenere(void)
{
    
}

vigenere::vigenere(string msg_inicial, string clave) : msg_inicial(msg_inicial),
                                                       clave(clave)    
                                                                                             
{
    
}

vigenere::~vigenere(void)
{
}

// Método que divide al mensaje inicial en funcion del tamaño de la clave
void vigenere::dividir(string msg_inicial, string clave)
{
    int j = 0;

    if (clave.length() < msg_inicial.length())
    {
        for (int i = 0; i < msg_inicial.length(); i++)
        {
            // Si encontramos un espacio pasamos de él.
            if (msg_inicial[i] == ' ')
            {
                i++;
            }
            // Si se llega al tamaño de la clave entonces tendremos un espacio.
            if (j == clave.length())
            {
                msg_dividido += ' ';
                j = 0; // Volvemos a recorrer la clave
            }
            // Se va guardando el mensaje inicial en mensaje dividido.
            msg_dividido += msg_inicial[i];
            j++;
        }
    }
    // Hasta aquí ya tenemos el mensaje inicial dividido segun la claves
    else
    {
        for (int i = 0; i < msg_inicial.length(); i++)
        {
        // Si encontramos un espacio pasamos de él.
            if (msg_inicial[i] == ' ')
            {
                i++;
            }

            msg_dividido += msg_inicial[i];
            j++;
           
        }
    }

}


// Asignación de los valores a las letras
void vigenere::enumeracion(string msg_inicial, string clave)
{
    int k = 0;
    for (int j = 0; j < msg_dividido.length(); j++)
    {
        // ESTEME NSAJES EAUTOD ESTRUI RA

        if((int)msg_dividido[j] > 61 || (int)msg_dividido[j] == 32){
            int valor = (int)msg_dividido[j] - 65;
            v_msg_inicial.push_back(valor); // Almacena la equivalencia de cada letra
        }
        else{
            int pos = anadidos.find(msg_dividido[j]);
            v_msg_inicial.push_back(26 + pos);
        }
    }

    /* 
    Tengo que recorrer el mensaje dividido segun la clave para hacer la clave del mismo tamaño
    Entonces, voy a ir almacenando los valores de las letras convertidas a numeros en v_clave
    y las letras en sí en clave_dividido.
    */
    
    for (int i = 0; i < msg_dividido.length(); i++)
    {
        // Tengo que tener en cuenta esto porque si en el mensaje llego a un espacio significa que tengo
        // que repetir mi clave asi que pongo k a 0 y vuelvo a almacenar
        if (v_msg_inicial[i] == -33)
        {
            v_clave.push_back(-33); // v_clave es el vector
            //cout << v_clave[i];
            clave_dividido += v_clave[i]+65; // clave dividido tiene los espacios.
            i++;
            k = 0;
        }
        v_clave.push_back((int)clave[k] - 65); //Aquí meto los numeros -> equivalencias 
        clave_dividido += v_clave[i]+65; // Aquí meto las letras
        k++;
        
        // if (k == clave.length())
        // {
        //     k = 0;
        // }
    }
}


void vigenere::cifrado(string msg_inicial)
{
    int temp = 0;

    for (int i = 0; i < v_msg_inicial.size(); i++)
    {

        temp = (  v_msg_inicial[i] +  v_clave[i]);

        if (temp==-66){
            resultado_string += ' ';
            v_resultado.push_back(-33);
        }
        else {
            v_resultado.push_back(temp % 30);
            if(v_resultado[i] < 26 ){
                resultado_string += v_resultado[i] + 65;
                resultado_junto += v_resultado[i] + 65;
            }
            else {
                          
                resultado_string += anadidos[temp%30 - 26];
                resultado_junto += v_resultado[i] - 26;
                
            }
        }
    }

}


void vigenere::descifrado()
{
    int temp = 0;

    for (int i = 0; i < v_msg_inicial.size(); i++)
    { // v_descifrado es v_mensaje inicial
        temp = (v_msg_inicial[i] - v_clave[i]);
        if (v_msg_inicial[i] == -33 || v_clave[i] == -33){
            resultado_string_descifrado += ' '; // PORQUE SI DA 0 ES UNA LETRA CONFUSION 
            v_descifrado.push_back(-33);
        }
        else if (temp < 0){
            temp += 30;
            v_descifrado.push_back(temp % 30);
            if(v_descifrado[i] < 26 ){
                resultado_string_descifrado += v_descifrado[i] + 65;
                resultado_descifrado_junto += v_descifrado[i] + 65;
            }
            else {          
                resultado_string_descifrado += anadidos[temp%30 - 26];
                resultado_descifrado_junto += v_descifrado[i] - 26;
                
            }
        }
        else {
            v_descifrado.push_back(temp % 30);
            if(v_descifrado[i] < 26 ){
                resultado_string_descifrado  += v_descifrado[i] + 65;
                resultado_descifrado_junto += v_descifrado[i] + 65;
            }
            else {          
                resultado_string_descifrado += anadidos[temp%30 - 26];
               resultado_descifrado_junto += v_descifrado[i] - 26;
                
            }
        }
    }

}


void vigenere::write(string msg_inicial, string clave){
    cout <<endl<<endl <<endl;
    cout << "Palabra clave: " << clave << endl;
    cout << "Texto original: " << msg_inicial << endl;
    cout << "Mensaje dividido: " << msg_dividido << endl;
    cout << "Clave dividido:    " << clave_dividido << endl;
    cout << "Cifrado dividido: " << resultado_string <<endl;
    resultado_string.erase(remove(resultado_string.begin(), resultado_string.end(), ' '), resultado_string.end());
    cout << "Texto cifrado: " << resultado_string << endl;
    //cout << "Texto descifrado: " << resultado_string_descifrado << endl;
    cout <<endl<<endl <<endl;
}

void vigenere::write2(string msg_inicial, string clave){
    cout <<endl<<endl <<endl;
    cout << "Palabra clave: " << clave << endl;
    cout << "Texto original: " << msg_inicial << endl;
    cout << "Mensaje dividido: " << msg_dividido << endl;
    cout << "Clave dividido:    " << clave_dividido << endl;
    //cout << "Cifrado dividido: " << resultado_string <<endl;
    //cout << "Texto cifrado: " << resultado_junto << endl;
    cout << "Texto descifrado: " << resultado_string_descifrado << endl;
    cout <<endl<<endl <<endl;
}

