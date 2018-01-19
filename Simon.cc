#define _POSIX_C_SOURCE 200112L

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <unistd.h>
#include <ctime>

#define TOTAL 6

using namespace std;

int creasecuencia();
int letras();
int pintarsecuencia();

int array[10];
string resultado;

int main()
{
    string usuario;
    int temps = 12;
    unsigned int tiempo = int(time(NULL));
    srand(tiempo);
    string secuencia;
    cout << "SIMON DICE\n"
         << endl;
    string nombre;
    cout << "¿Cómo te llamas?" << endl;
    getline(cin, nombre);
    cout << "¡Muy bien " << nombre << ", ahora vamos a empezar a jugar!" << endl;
    cout << endl;
    sleep(1);
    cout << "Ahora mismo vamos a poner una secuencia de colores y," << endl;
    sleep(3);
    cout << "vas a tener que recordarlos para después escribirlos." << endl;
    sleep(3);
    cout << "¡Aquí va la secuencia!" << endl;
    sleep(3);
    cout << endl;
    for (int i = 0; i < TOTAL; i++)
    {
        creasecuencia();
        letras();
        pintarsecuencia();
        cout << "Recuerda la secuencia de colores" << endl;
        sleep(temps);
        temps = temps - 2;
        system ("clear");
        cout << "Has de escribir la secuencia en letras mayúsculas: ";
        cin >> usuario;
        if (usuario.compare(resultado) != 0)
        {
            cout << "Has fallado :-(" << endl;
            cout << "¡Ya habrá más suerte la proxima vez!" << endl;
            return 1;
        }
        cout << "¡Muy bien! :-)" << endl;
        sleep(1);
        if (i != 5)
        {
            cout << "¡Pasas de ronda!" << endl;
            sleep(1);
            cout << "¡Ahora un poquito más rápido!" << endl;
            sleep(1);
        }
    }
    cout << "¡Has ganado!" << endl;
    cout << "¡Enhorabuena!" << endl;
    return 0;
}
int letras()
{   resultado.clear();
    for (int i = 0; i < TOTAL; i++)
    {
        switch (array[i])
        {
        case 1:
            resultado += 'R';
            break;
        case 2:
            resultado += 'G';
            break;
        case 3:
            resultado += 'Y';
            break;
        case 4:
            resultado += 'B';
            break;
        case 5:
            resultado += 'M';
            break;
        case 6:
            resultado += 'C';
            break;
        case 7:
            resultado += 'W';
            break;
        }
    }
    return 0;
}

int pintarsecuencia()
{
    string secuencia;
    string nrandom;
    for (int i = 0; i < TOTAL; i++)
    {
        nrandom = to_string(array[i]);
        secuencia += "\033[1;3" + nrandom + "m■\033[0m\t";
    }
    cout << secuencia << endl;
    return 0;
}

int creasecuencia()
{
    for (int i = 0; i < TOTAL; i++)
    {
        array[i] = random() % 7 + 1;
    }
    return 0;
}
