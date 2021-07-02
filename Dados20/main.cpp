#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <conio.h>
#include <cstring>

using namespace std;
#include "rlutil.h"
#include "funciones.h"
#include "menu.h"

using namespace rlutil;

int main(){
    int opc;

    system("color 2f"); /// cambia color de fondo y letras
    system("title Juego de dados 20");

    while (true){
        menu();
        cin >> opc;
        switch(opc){
                case 1:
                    system("cls");
                    unJugador();
                break;
                case 2:
                    system("cls");
                    dosJugadores();
                break;
                case 3:
                    system("cls");
                    puntuacionAlta();
                break;
                case 4:
                    system("cls");
                    modoSimulado();
                break;
                case 0:
                    system("cls");
                    cout << "GRACIAS POR USAR NUESTRO PROGRAMA!" << endl;
                    return 0;
                break;
        }

        cout << endl;
        system("pause");
    }
    return 0;
}
