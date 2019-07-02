#include "a5.hpp"

a5::a5()
{
}

a5::~a5()
{
}

void a5::mensaje_bin(string mensaje){
    cout <<endl << "El mensaje es: " << mensaje << endl;
    msg_binario = new bitset<8>[mensaje.length()];
    bitset<8> temp[mensaje.length()];

    for (int i = 0; i < mensaje.length(); i ++){
        int aux = 0;
        aux = (int) mensaje[i];
        v_mensaje_aux.push_back(aux);
        temp[i] = bitset<8>(mensaje[i]);
        msg_binario[i] = temp[i];
    }
    cout << endl << endl << " Mensaje en binario: " << endl;
    for (int i = 0; i < mensaje.length(); i ++){
        cout << msg_binario[i] << endl;
    }
}

void a5::transforma(string r1_string, string r2_string, string r3_string)
{
    cout << endl;
    for (int i = 0; i < r1_string.length(); i++)
    {
        int aux = r1_string[i];

        if (aux == 49)
            r1_vector.push_back(1);
        else
        {
            r1_vector.push_back(0);
        }

    }

    cout << endl;
    for (int i = 0; i < r2_string.length(); i++)
    {
        int aux = r2_string[i];

        if (aux == 49)
            r2_vector.push_back(1);
        else
        {
            r2_vector.push_back(0);
        }

    }

    cout << endl;
    for (int i = 0; i < r3_string.length(); i++)
    {
        int aux = r3_string[i];

        if (aux == 49)
            r3_vector.push_back(1);
        else
        {
            r3_vector.push_back(0);
        }

    }
}

void a5::desplazamiento(string mensaje)
{
    for (int j = 0; j < (mensaje.length()*8); j++)
    {
        int resultado = r1_vector[0] ^ r2_vector[0] ^ r3_vector[0];
        
        secuencia_cifrante.push_back(resultado);

        write();
        // Para hacer la modificación tuve que cambiar el polinomio original.
        // x19, x15,x14,x10 y x14,x3
        // r1 = r1_vector[0] ^ r1_vector[1] ^ r1_vector[2] ^ r1_vector[5];
        r1 = r1_vector[0] ^ r1_vector[4] ^ r1_vector[9] ^ r1_vector[5] ;
        r2 = r2_vector[8] ^ r2_vector[19]; 
        // r2 = r2_vector[0] ^ r2_vector[1];
        r3 = r3_vector[0] ^ r3_vector[1] ^ r3_vector[2] ^ r3_vector[15];

        
        mayoria = ((r1_vector[10] * r2_vector[11]) ^ (r1_vector[10] * r3_vector[12]) ^ (r2_vector[11] * r3_vector[12]));

        cout << endl;   
        if (mayoria == r1_vector[10])
        {
            cout <<endl << " Moviendo el registro 1 y metiendo un " << r1 << endl;
            r1_vector.erase(r1_vector.begin(), r1_vector.begin() + 1);
            r1_vector.push_back(r1);
        }

        if (mayoria == r2_vector[11])
        {
            cout <<endl << " Moviendo el registro 2 y metiendo un " << r2 << endl;
            r2_vector.erase(r2_vector.begin(), r2_vector.begin() + 1);
            r2_vector.push_back(r2);
        }

        if (mayoria == r3_vector[12])
        {
            cout <<endl << " Moviendo el registro 3 y metiendo un  " << r3 << endl;
            r3_vector.erase(r3_vector.begin(), r3_vector.begin() + 1);
            r3_vector.push_back(r3);
        }

        cout << endl;
    }
    

    sec_binario = new bitset<8>[mensaje.length()];
  
    int k = 0;
    for (int j=0; j < mensaje.length(); j++){
        for (int i = 7; i >= 0; i--){
            sec_binario[j].set(i, secuencia_cifrante[k]);
            k++;
        }
    }
    cout << endl
         << endl;
        cout << "Secuencia cifrante en bitset: ";

    for (int i = 0; i < secuencia_cifrante.size(); i++)
    {
        cout << secuencia_cifrante[i];
   
    }

    
}

void a5::cifrado(string mensaje)
{

    cout << endl << endl;
    msg_binario_cifrado = new bitset<8>[mensaje.length()];
    for (int i = 0; i < mensaje.length(); i ++){

        msg_binario_cifrado[i] = msg_binario[i] ^ sec_binario[i];

        int aux;
        aux = (secuencia_cifrante[i] ^ v_mensaje[i]);

    }

    cout <<endl << " El cifrado es: ";
    for (int i = 0; i < mensaje.length(); i ++){
        cout << msg_binario_cifrado[i];
    }
    cout << endl;

}


void a5::translate(string mensaje){

    for (int i = 0; i < mensaje.length(); i++){

        msg_cifrado_ascii_temp += to_string( (int) msg_binario_cifrado[i].to_ulong() );
        msg_cifrado += msg_binario_cifrado[i].to_ulong();

    }
    cout <<endl << endl << endl<< " En string: " << msg_cifrado << endl;
    
}





void a5::descifrado()
{

    cout << endl << endl;
    msg_binario_descifrado = new bitset<8>[msg_cifrado.length()];
    for (int i = 0; i < msg_cifrado.length(); i ++){

        msg_binario_descifrado[i] = msg_binario_cifrado[i] ^ sec_binario[i];
        int aux;
        aux = (secuencia_cifrante[i] ^ v_mensaje[i]);


    }

    cout <<endl << " El descifrado es: ";
    for (int i = 0; i < msg_cifrado.length(); i ++){
        cout << msg_binario_descifrado[i];
    }
    cout << endl;

}



void a5::translate_des(){

    for (int i = 0; i < msg_cifrado.length(); i++){

        msg_descifrado_ascii_temp += to_string( (int) msg_binario_descifrado[i].to_ulong() );
        msg_descifrado += msg_binario_descifrado[i].to_ulong();

    }
    cout <<endl << endl << endl<< " En string: " << msg_descifrado << endl;
    
}




void a5::write()
{

    cout << endl
         << endl
         << " Writing " << endl
         << endl;
    for (int i = 0; i < r1_vector.size(); i++)
    {
        cout << r1_vector[i] << "|";
    }
    cout << endl;

    for (int i = 0; i < r2_vector.size(); i++)
    {
        cout << r2_vector[i] << "|";
    }

    cout << endl;

    for (int i = 0; i < r3_vector.size(); i++)
    {
        cout << r3_vector[i] << "|";
    }

   
}

