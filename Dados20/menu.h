#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
///DECLARACION DE VARIABLES

int o, i, j, k, opcM;
char player1[15], player2[15];
int cantRondas;
int vtirada[5], vmaximos[5], vnumgenerador[6];
int ntirada, puntosapostados, puntajeacumulado, maximo, sumamax, cRondas0, cRondasP;
int numGeneradorPuntos, cantDadosRep, puntajefinal, puntajefinal1, puntajefinal2;
char highestScorePlayer[15];
int highestScore;


/// OPCIONES DEL MENU
void menu(){
    system("cls");
            gotoxy(30,11);
            cout << (char)201;
            for (i=1; i<44; i++) cout << (char)205; ///Para que quede mas fashion
            cout << (char)187 << endl;
            gotoxy(30,12);
            cout << (char)186 << " 1. JUEGO NUEVO PARA 1 JUGADOR.";
            gotoxy(74,12);
            cout << (char)186;
            gotoxy(30,13);
            cout << (char)186 << " 2. JUEGO NUEVO PARA 2 JUGADORES.";
            gotoxy(74,13);
            cout << (char)186;
            gotoxy(30,14);
            cout << (char)186 << " 3. PUNTUACION MAS ALTA.";
            gotoxy(74,14);
            cout << (char)186;
            gotoxy(30,15);
            cout << (char)186 << " 4. MODO SIMULADO (CARGA DE DATOS MANUAL).";
            gotoxy(74,15);
            cout << (char)186;
            gotoxy(30,16);
            cout << (char)186 << " 0. FIN DEL PROGRAMA.";
            gotoxy(74,16);
            cout << (char)186;
            gotoxy(30,17);
            cout << (char)200;
            gotoxy(31,17);
            for (i=1; i<44; i++) cout << (char)205;
            gotoxy(74,17);
            cout << (char)188;
            gotoxy(32,17);
            cout << endl << endl;
            gotoxy(33,18);
            cout << "Ingrese una opcion: ";
}

void unJugador(){
    for(k=0 ; k<=5 ; k++){
        vnumgenerador[k]=20+k;
        }

    cout << "JUEGO NUEVO PARA 1 JUGADOR." << endl;
                        for (o=1; o<44; o++) cout << (char)205;
                        cout << endl;
                            cout << "Ingrese nombre del jugador: ";
                            cin >> player1;
                            cout << endl;
                            cout << "Cantidad de rondas que desea jugar: ";
                            cin >> cantRondas;
                            cout << endl;
                            puntajefinal=0;
                            cRondas0=0;
                            cRondasP=0;
                            for (i=1; i<=cantRondas; i++){/// RONDAS
                                system("cls");
                                cout << "Cuantos puntos quiere apostar para esta ronda?: ";
                                cin >> puntosapostados;
                                system("cls");
                                puntajeacumulado=0;
                                ntirada=0; /// reinicio el numero de tirada en cada ronda
                                ponerCero(vmaximos,5); /// pongo en 0 el vector de maximos de tiradas, en cada ronda
                                for(j=5; j>=1; j--){/// TIRADAS
                                        cout << "JUGADOR: " << player1 << " " << (char)186;
                                        cout << " RONDA N" << (char)167 << i << " " << (char)186;
                                        cargarAleatorio(vtirada,j,6);
                                        maximo=valormaximoVector(vtirada,j);
                                        vmaximos[j-1]=maximo;
                                        sumamax=sumarVector(vmaximos,5);
                                            cout << " PUNTAJE ACUMULADO: " << sumamax << endl;
                                            for (o=1; o<55; o++) cout << (char)205;
                                            cout << endl;
                                        ntirada++;
                                            cout << "TIRADA N" << (char)167 << ntirada << endl;
                                            for (o=1; o<55; o++) cout << (char)205;
                                            cout << endl;
                                        mostrarVector(vtirada,j);
                                        cout << endl;
                                        cout << "El valor maximo es: " << maximo << endl;
                                        for (o=1; o<55; o++) cout << (char)205;
                                                cout << endl;
                                                cout << "DADOS CON PUNTAJES MAXIMOS DE CADA TIRADA:";
                                                mostrarVectorSin0(vmaximos,5);
                                                cout << endl;
                                                cout << (char)168 << "Lanzar dados? ";
                                                system("pause");
                                                system("cls");
                                        if(j<=1){ /// Ingreso despues de la ultima tirada
                                                cout << "PUNTAJE ACUMULADO: " << sumamax << endl;
                                               if(sumamax>=20){ /// TIRO DE PUNTAJE
                                                    numGeneradorPuntos = 1 + posicionNumeroEnVector(vnumgenerador,6,sumamax);
                                                    if(numGeneradorPuntos == 0){ /// si suma mayor a 25
                                                        numGeneradorPuntos = 6;
                                                    }
                                                    cout << "NUMERO GENERADOR DE PUNTOS: " << numGeneradorPuntos << endl;
                                                    cout << "ULTIMO TIRO DE LA RONDA. POR CADA DADO CON EL VALOR " << numGeneradorPuntos  << " SE SUMAN PUNTOS." << endl;
                                                    for (o=1; o<55; o++) cout << (char)205;
                                                    cout << endl;
                                                    cout << (char)168 << "Lanzar dados? ";
                                                    system("pause");
                                                    cargarAleatorio(vtirada,5,6);
                                                    mostrarVector(vtirada,5);
                                                    cout << endl;
                                                    cantDadosRep = contarNumerosRepetidos(vtirada,5,numGeneradorPuntos);
                                                    if (cantDadosRep==0){
                                                        puntajeacumulado=0;
                                                            cout << "No hubo dados con el numero generador de puntos." << endl << "PUNTAJE PARCIAL: " << puntajeacumulado << endl;
                                                        cRondas0++;
                                                    }
                                                    else{
                                                        puntajeacumulado = puntosapostados*cantDadosRep;
                                                        cout << endl << "PUNTAJE PARCIAL: " << puntajeacumulado << endl;
                                                    }
                                               }
                                               else{
                                                    if (sumamax<=19){
                                                            cout << "Se restan los puntos apostados a su puntaje final." << endl;
                                                            puntajeacumulado = puntajeacumulado - puntosapostados;
                                                            if (puntajeacumulado<=0){
                                                                puntajeacumulado=0;
                                                                cRondas0++;
                                                            }
                                                            cout << "PUNTAJE PARCIAL: " << puntajeacumulado << endl;
                                                            cRondasP++;
                                                    }
                                               }
                                        }
                                }
                                puntajefinal = puntajefinal + puntajeacumulado;
                                system("pause");
                            }
                            if(puntajefinal>=highestScore){
                                highestScore=puntajefinal;
                                strcpy(highestScorePlayer,player1);
                            }
                            ///DATOS SALIDA PARA ESTA OPCION
                            system("cls");
                            cout << "JUGADOR: " << player1 << endl;
                            if(cRondas0==0){
                                    cout << "No hubo rondas sin puntos." << endl;
                            }
                            else{
                                cout << "Total de rondas sin puntos: " << cRondas0 << endl;
                            }
                            if(cRondasP==0){
                                cout << "No hubo rondas con perdida de puntos." << endl;
                            }
                            else{
                                cout << "Total de rondas con perdida de puntos: " << cRondasP << endl;
                            }
                            cout << "PUNTAJE FINAL: " << puntajefinal << endl;

}

void dosJugadores(){
    for(k=0 ; k<=5 ; k++){
        vnumgenerador[k]=20+k;
        }
    cout << "JUEGO NUEVO PARA 2 JUGADORES." << endl;
                        for (o=1; o<44; o++) cout << (char)205;
                        cout << endl;
                        cout << "Ingrese nombre del JUGADOR 1: ";
                        cin >> player1;
                        cout << endl;
                        cout << "Ingrese nombre del JUGADOR 2: ";
                        cin >> player2;
                        cout << endl;
                        cout << "Cantidad de rondas que desean jugar: ";
                        cin >> cantRondas;
                        system("cls");
                        puntajefinal1=0;
                        puntajefinal2=0;
                        for (i=1; i<=cantRondas; i++){/// RONDAS
                                cout << player1 << ", cuantos puntos quiere apostar para esta ronda?: ";
                                cin >> puntosapostados;
                                system("cls");
                                puntajeacumulado=0;
                                ntirada=0;
                                ponerCero(vmaximos,5);
                                for(j=5; j>=1; j--){/// TIRADAS
                                        cout << "JUGADOR: " << player1 << " " << (char)186;
                                        cout << " RONDA N" << (char)167 << i << " " << (char)186;
                                        cargarAleatorio(vtirada,j,6);
                                        maximo=valormaximoVector(vtirada,j);
                                        vmaximos[j-1]=maximo;
                                        sumamax=sumarVector(vmaximos,5);
                                        cout << " PUNTAJE ACUMULADO: " << sumamax << endl;
                                        for (o=1; o<55; o++) cout << (char)205;
                                        cout << endl;
                                        ntirada++;
                                        cout << "TIRADA N" << (char)167 << ntirada << endl;
                                        for (o=1; o<55; o++) cout << (char)205;
                                        cout << endl;
                                        mostrarVector(vtirada,j);
                                        cout << endl;
                                        cout << "El valor maximo es: " << maximo << endl;
                                        for (o=1; o<55; o++) cout << (char)205;
                                        cout << endl;
                                        cout << "DADOS CON PUNTAJES MAXIMOS DE CADA TIRADA:";
                                        mostrarVectorSin0(vmaximos,5);
                                        cout << endl;
                                        cout << (char)168 << "Lanzar dados? " << endl;
                                        system("pause");
                                        system("cls");
                                        if(j<=1){ /// Ingreso despues de la ultima tirada
                                                cout << "PUNTAJE ACUMULADO: " << sumamax << endl;
                                               if(sumamax>=20){ /// TIRO DE PUNTAJE
                                                    numGeneradorPuntos = 1 + posicionNumeroEnVector(vnumgenerador,6,sumamax);
                                                    if(numGeneradorPuntos == 0){
                                                        numGeneradorPuntos = 6;
                                                    }
                                                    cout << "NUMERO GENERADOR DE PUNTOS: " << numGeneradorPuntos << endl;
                                                    cout << "ULTIMO TIRO DE LA RONDA. POR CADA DADO CON EL VALOR " << numGeneradorPuntos  << " SE SUMAN PUNTOS." << endl;
                                                    for (o=1; o<55; o++) cout << (char)205;
                                                    cout << endl;
                                                    cout << (char)168 << "Lanzar dados? ";
                                                    system("pause");
                                                    cargarAleatorio(vtirada,5,6);
                                                    mostrarVector(vtirada,5);
                                                    cout << endl;
                                                    cantDadosRep = contarNumerosRepetidos(vtirada,5,numGeneradorPuntos);
                                                    if (cantDadosRep==0){
                                                        puntajeacumulado=0;
                                                        cout << "No hubo dados con el numero generador de puntos." << endl;
                                                        cout << "PUNTAJE PARCIAL: " << puntajeacumulado << endl;
                                                    }
                                                    else{
                                                        puntajeacumulado = puntosapostados*cantDadosRep;
                                                        cout << "PUNTAJE PARCIAL: " << puntajeacumulado << endl;
                                                        puntajefinal1 = puntajefinal1 + puntajeacumulado;
                                                    }
                                               }
                                               else{
                                                    if (sumamax<=19){
                                                            cout << "Se restan los puntos de apuesta a su puntaje final." << endl;
                                                            puntajefinal1 = puntajefinal1 - puntosapostados;
                                                            if (puntajefinal1<=0){
                                                                puntajefinal1=0;
                                                            }
                                                            cout << endl << "PUNTAJE PARCIAL: " << puntajefinal1 << endl;
                                                    }
                                               }
                                        }
                                }
                                system("pause");
                                system("cls");
                /// JUGADOR 2
                                cout << player2 << ", cuantos puntos quiere apostar para esta ronda?: ";
                                cin >> puntosapostados;
                                system("cls");
                                puntajeacumulado=0;
                                ntirada=0;
                                ponerCero(vmaximos,5);
                                for(j=5; j>=1; j--){/// TIRADAS
                                        cout << "JUGADOR: " << player2 << " " << (char)186;
                                        cout << " RONDA N" << (char)167 << i << " " << (char)186;
                                        cargarAleatorio(vtirada,j,6);
                                        maximo=valormaximoVector(vtirada,j);
                                        vmaximos[j-1]=maximo;
                                        sumamax=sumarVector(vmaximos,5);
                                        cout << " PUNTAJE ACUMULADO: " << sumamax << endl;
                                        for (o=1; o<55; o++) cout << (char)205;
                                        cout << endl;
                                        ntirada++;
                                        cout << "TIRADA N" << (char)167 << ntirada << endl;
                                        for (o=1; o<55; o++) cout << (char)205;
                                        cout << endl;
                                        mostrarVector(vtirada,j);
                                        cout << endl;
                                        cout << "El valor maximo es: " << maximo << endl;
                                        for (o=1; o<55; o++) cout << (char)205;
                                                cout << endl;
                                                cout << "DADOS CON PUNTAJES MAXIMOS DE CADA TIRADA:";
                                                mostrarVectorSin0(vmaximos,5);
                                                cout << endl;
                                                cout << (char)168 << "Lanzar dados? ";
                                                system("pause");
                                                system("cls");
                                        if(j<=1){ /// Ingreso despues de la ultima tirada
                                                cout << "PUNTAJE ACUMULADO: " << sumamax << endl;
                                               if(sumamax>=20){ /// TIRO DE PUNTAJE
                                                    numGeneradorPuntos = 1 + posicionNumeroEnVector(vnumgenerador,6,sumamax);
                                                    if(numGeneradorPuntos == 0){
                                                        numGeneradorPuntos = 6;
                                                    }
                                                    cout << "NUMERO GENERADOR DE PUNTOS: " << numGeneradorPuntos << endl;
                                                    cout << "ULTIMO TIRO DE LA RONDA. POR CADA DADO CON EL VALOR " << numGeneradorPuntos  << " SE SUMAN PUNTOS." << endl;
                                                    for (o=1; o<55; o++) cout << (char)205;
                                                    cout << endl;
                                                    cout << (char)168 << "Lanzar dados? ";
                                                    system("pause");
                                                    cargarAleatorio(vtirada,5,6);
                                                    mostrarVector(vtirada,5);
                                                    cout << endl;
                                                    cantDadosRep = contarNumerosRepetidos(vtirada,5,numGeneradorPuntos);
                                                    if (cantDadosRep==0){
                                                        puntajeacumulado=0;
                                                        cout << "No hubo dados con el numero generador de puntos." << endl;
                                                        cout << "PUNTAJE PARCIAL: " << puntajeacumulado << endl;
                                                    }
                                                    else{
                                                        puntajeacumulado = puntosapostados*cantDadosRep;
                                                        cout << endl << "PUNTAJE PARCIAL: " << puntajeacumulado << endl;
                                                        puntajefinal2 = puntajefinal2 + puntajeacumulado;
                                                        }
                                               }
                                               else{
                                                    if (sumamax<=19){
                                                            cout << "Se restan los puntos de apuesta a su puntaje final." << endl;
                                                            puntajefinal2 = puntajefinal2 - puntosapostados;
                                                            if (puntajefinal2<=0){
                                                                puntajefinal2=0;
                                                            }
                                                            cout << "PUNTAJE PARCIAL: " << puntajefinal2 << endl;
                                                    }
                                               }
                                        }
                                }
                                system("pause");
                                system("cls");
                            }
                            /// OPCION 3 CASE: PUNTUACION MAS ALTA
                            if(puntajefinal1 >= puntajefinal2){
                                    if(puntajefinal1 >= highestScore){
                                        highestScore = puntajefinal1;
                                        strcpy(highestScorePlayer,player1);
                                    }
                            }
                            else{
                                if(puntajefinal2 >= puntajefinal1){
                                    if(puntajefinal2 >= highestScore){
                                        highestScore = puntajefinal2;
                                        strcpy(highestScorePlayer,player2);
                                    }
                                }
                            }
                            ///DATOS DE SALIDA PARA ESTA OPCION
                            if(puntajefinal1>=puntajefinal2){
                                if(puntajefinal1>puntajefinal2){
                                    cout << "GANADOR: " << player1 << endl;
                                    cout << "PUNTAJE FINAL: " << puntajefinal1 << endl;;
                                }
                                else{
                                    cout << "Empate. ";
                                    cout << "PUNTAJE FINAL: " << puntajefinal1 << endl;
                                }
                            }
                            else{
                                cout << "GANADOR: " << player2 << endl;
                                cout << "PUNTAJE FINAL: " << puntajefinal2 << endl;
                            }
}

void puntuacionAlta(){
    cout << "PUNTUACION MAS ALTA: " << highestScore << endl;
    for (o=1; o<44; o++) cout << (char)205;
    cout << endl;
    cout << "JUGADOR: " << highestScorePlayer << endl;
}

void modoSimulado(){
    for(k=0 ; k<=5 ; k++){
        vnumgenerador[k]=20+k;
        }
    cout << "MODO SIMULADO (CARGA DE DATOS MANUAL)." << endl;
                        for (o=1; o<44; o++) cout << (char)205;
                        cout << endl;
                        cout << "1. JUEGO NUEVO PARA UN JUGADOR." << endl;
                        cout << "2. JUEGO NUEVO PARA DOS JUGADORES." << endl;
                        cout << "Ingrese una opcion: ";
                        cin >> opcM;
                        system("cls");
                        if(opcM==1){ /// JUEGO NUEVO 1 JUGADOR
                            cout << "Ingrese nombre del jugador: ";
                            cin >> player1;
                            cout << endl;
                            cout << "Cantidad de rondas que desea jugar: ";
                            cin >> cantRondas;
                            cout << endl;
                            puntajefinal=0;
                            cRondas0=0;
                            cRondasP=0;
                            for (i=1; i<=cantRondas; i++){ /// RONDAS
                                cout << "Cuantos puntos quiere apostar para esta ronda?: ";
                                cin >> puntosapostados;
                                system("cls");
                                ntirada=0;
                                ponerCero(vmaximos,5);
                                for(j=5; j>=1; j--){ /// TIRADAS
                                        cout << "JUGADOR: " << player1 << " " << (char)186;
                                        cout << " RONDA N" << (char)167 << i << " " << (char)186;
                                        ntirada++;
                                        cout << "TIRADA N" << (char)167 << ntirada << endl;
                                        for (o=1; o<55; o++) cout << (char)205;
                                        cout << endl;
                                        cargarVector(vtirada,j);
                                        maximo=valormaximoVector(vtirada,j);
                                        vmaximos[j-1]=maximo;
                                        cout << "El valor maximo es: " << maximo << endl;
                                        for (o=1; o<55; o++) cout << (char)205;
                                                cout << endl;
                                                cout << "DADOS CON PUNTAJES MAXIMOS DE CADA TIRADA:";
                                                mostrarVectorSin0(vmaximos,5);
                                                cout << endl;
                                                cout << (char)168 << "Lanzar dados? ";
                                                system("pause");
                                                system("cls");
                                        if(j<=1){ /// Ingreso despues de la ultima tirada
                                            sumamax=sumarVector(vmaximos,5);
                                            cout << "PUNTAJE ACUMULADO: " << sumamax << endl;
                                               if(sumamax>=20){ /// TIRO DE PUNTAJE
                                                    numGeneradorPuntos = 1 + posicionNumeroEnVector(vnumgenerador,6,sumamax);
                                                    if(numGeneradorPuntos == 0){
                                                        numGeneradorPuntos = 6;
                                                    }
                                                    cout << "NUMERO GENERADOR DE PUNTOS: " << numGeneradorPuntos << endl;
                                                    cout << "ULTIMO TIRO DE LA RONDA. POR CADA DADO CON EL VALOR " << numGeneradorPuntos  << " SE SUMAN PUNTOS." << endl;
                                                    for (o=1; o<55; o++) cout << (char)205;
                                                    cout << endl;
                                                    system("pause");
                                                    cargarVector(vtirada,5);
                                                    cout << endl;
                                                    cantDadosRep = contarNumerosRepetidos(vtirada,5,numGeneradorPuntos);
                                                    if (cantDadosRep==0){
                                                        puntajeacumulado=0;
                                                        cout << "No hubo dados con el numero generador de puntos." << endl << "PUNTAJE PARCIAL: " << puntajeacumulado << endl;
                                                        cRondas0++;
                                                    }
                                                    else{
                                                        puntajeacumulado = puntosapostados*cantDadosRep;
                                                        cout << "PUNTAJE PARCIAL: " << puntajeacumulado << endl;
                                                    }
                                               }
                                               else{
                                                    if (sumamax<=19){
                                                            cout << "Se restan los puntos de apuesta a su puntaje final." << endl;
                                                            puntajeacumulado = puntajeacumulado - puntosapostados;
                                                            if (puntajeacumulado<=0){
                                                                puntajeacumulado=0;
                                                                cRondas0++;
                                                            }
                                                            cout << "PUNTAJE PARCIAL: " << puntajeacumulado << endl;
                                                            cRondasP++;
                                                    }
                                               }
                                        }
                                }
                                puntajefinal = puntajefinal + puntajeacumulado;

                                system("pause");

                                for (o=1; o<44; o++) cout << (char)205;
                                cout << endl;
                            }
                            if(puntajefinal>=highestScore){
                                highestScore=puntajefinal;
                                strcpy(highestScorePlayer,player1);
                            }
                            ///DATOS DE SALIDA PARA ESTA OPCION
                            cout << "JUGADOR: " << player1 << endl;
                            if(cRondas0==0){
                                    cout << "No hubo rondas sin puntos." << endl;
                            }
                            else{
                                cout << "Total de rondas sin puntos: " << cRondas0 << endl;
                            }
                            if(cRondasP==0){
                                cout << "No hubo rondas con perdida de puntos." << endl;
                            }
                            else{
                                cout << "Total de rondas con perdida de puntos: " << cRondasP << endl;
                            }

                            cout << "PUNTAJE FINAL: " << puntajefinal << endl;
                            system("pause");
                            system("cls");

                        }
                        else{
                            if(opcM==2){ /// JUEGO NUEVO 2 JUGADORES
                                cout << "JUEGO NUEVO PARA 2 JUGADORES." << endl;
                                for (o=1; o<44; o++) cout << (char)205;
                                cout << endl;
                                cout << "Ingrese nombre del JUGADOR 1: ";
                                cin >> player1;
                                cout << endl;
                                cout << "Ingrese nombre del JUGADOR 2: ";
                                cin >> player2;
                                cout << endl;
                                cout << "Cantidad de rondas que desean jugar: ";
                                cin >> cantRondas;
                                system("cls");
                                puntajefinal1=0;
                                puntajefinal2=0;
                                for (i=1; i<=cantRondas; i++){/// RONDAS
                                        cout << player1 << ", cuantos puntos quiere apostar para esta ronda?: ";
                                        cin >> puntosapostados;
                                        system("cls");
                                        puntajeacumulado=0;
                                        ntirada=0; /// reinicio el numero de tirada en cada ronda
                                        ponerCero(vmaximos,5); /// 0 al vmaximos de tiradas, en cada ronda
                                        for(j=5; j>=1; j--){/// TIRADAS
                                                cout << "JUGADOR: " << player1 << " " << (char)186;
                                                cout << " RONDA N" << (char)167 << i << " " << (char)186;
                                                ntirada++;
                                                cout << " TIRADA N" << (char)167 << ntirada << endl;
                                                for (o=1; o<55; o++) cout << (char)205;
                                                cout << endl;
                                                cargarVector(vtirada,j);
                                                maximo=valormaximoVector(vtirada,j);
                                                vmaximos[j-1]=maximo;
                                                cout << "El valor maximo es: " << maximo << endl;
                                                for (o=1; o<55; o++) cout << (char)205;
                                                        cout << endl;
                                                        cout << "DADOS CON PUNTAJES MAXIMOS DE CADA TIRADA:";
                                                        mostrarVectorSin0(vmaximos,5);
                                                        cout << endl;
                                                        cout << (char)168 << "Lanzar dados? ";
                                                        system("pause");
                                                        system("cls");
                                                if(j<=1){ /// Ingreso despues de la ultima tirada
                                                    sumamax=sumarVector(vmaximos,5);
                                                    cout << "PUNTAJE ACUMULADO: " << sumamax << endl;
                                                       if(sumamax>=20){ /// TIRO DE PUNTAJE
                                                            numGeneradorPuntos = 1 + posicionNumeroEnVector(vnumgenerador,6,sumamax);
                                                            if(numGeneradorPuntos == 0){
                                                                numGeneradorPuntos = 6;
                                                            }
                                                            cout << "NUMERO GENERADOR DE PUNTOS: " << numGeneradorPuntos << endl;
                                                            cout << "ULTIMO TIRO DE LA RONDA. POR CADA DADO CON EL VALOR " << numGeneradorPuntos  << " SE SUMAN PUNTOS." << endl;
                                                            for (o=1; o<55; o++) cout << (char)205;
                                                            cout << endl;
                                                            system("pause");
                                                            cargarVector(vtirada,5);
                                                            cantDadosRep = contarNumerosRepetidos(vtirada,5,numGeneradorPuntos);
                                                            if (cantDadosRep==0){
                                                                puntajeacumulado=0;
                                                                cout << "No hubo dados con el numero generador de puntos." << endl;
                                                                cout << "PUNTAJE PARCIAL: " << puntajeacumulado << endl;
                                                            }
                                                            else{
                                                                    puntajeacumulado = puntosapostados*cantDadosRep;
                                                                    cout << "PUNTAJE PARCIAL: " << puntajeacumulado << endl;
                                                                    puntajefinal1 = puntajefinal1 + puntajeacumulado;
                                                            }
                                                       }
                                                       else{
                                                            if (sumamax<=19){
                                                                    cout << "Se restan los puntos de apuesta a su puntaje final." << endl;
                                                                    puntajefinal1 = puntajefinal1 - puntosapostados;
                                                                    if (puntajefinal1<=0){
                                                                        puntajefinal1=0;
                                                                    }
                                                                    cout << endl << "PUNTAJE PARCIAL: " << puntajefinal1 << endl;
                                                            }
                                                       }
                                                }
                                        }
                                        system("pause");
                                        system("cls");
                                        cout << player2 << ", cuantos puntos quiere apostar para esta ronda?: ";
                                        cin >> puntosapostados;
                                        system("cls");
                                        puntajeacumulado=0;
                                        ntirada=0;
                                        ponerCero(vmaximos,5);
                                        for(j=5; j>=1; j--){ /// TIRADAS
                                                cout << "JUGADOR: " << player2 << " " << (char)186;
                                                cout << " RONDA N" << (char)167 << i << " " << (char)186;
                                                ntirada++;
                                                cout << " TIRADA N" << (char)167 << ntirada << endl;
                                                for (o=1; o<55; o++) cout << (char)205;
                                                cout << endl;
                                                cargarVector(vtirada,j);
                                                maximo=valormaximoVector(vtirada,j);
                                                vmaximos[j-1]=maximo;
                                                cout << "El valor maximo es: " << maximo << endl;
                                                for (o=1; o<55; o++) cout << (char)205;
                                                        cout << endl;
                                                        cout << "DADOS CON PUNTAJES MAXIMOS DE CADA TIRADA:";
                                                        mostrarVectorSin0(vmaximos,5);
                                                        cout << endl;
                                                        cout << (char)168 << "Lanzar dados? ";
                                                        system("pause");
                                                        system("cls");
                                                if(j<=1){ /// Ingreso despues de la ultima tirada
                                                    sumamax=sumarVector(vmaximos,5);
                                                    cout << "PUNTAJE ACUMULADO: " << sumamax << endl;
                                                       if(sumamax>=20){ /// TIRO DE PUNTAJE
                                                            numGeneradorPuntos = 1 + posicionNumeroEnVector(vnumgenerador,6,sumamax);
                                                            if(numGeneradorPuntos == 0){
                                                                numGeneradorPuntos = 6;
                                                            }
                                                            cout << "NUMERO GENERADOR DE PUNTOS: " << numGeneradorPuntos << endl;
                                                            cout << "ULTIMO TIRO DE LA RONDA. POR CADA DADO CON EL VALOR " << numGeneradorPuntos  << " SE SUMAN PUNTOS." << endl;
                                                            for (o=1; o<55; o++) cout << (char)205;
                                                            cout << endl;
                                                            system("pause");
                                                            cargarVector(vtirada,5);
                                                            cout << endl;
                                                            cantDadosRep = contarNumerosRepetidos(vtirada,5,numGeneradorPuntos);
                                                            if (cantDadosRep==0){
                                                                puntajeacumulado=0;
                                                                cout << "No hubo dados con el numero generador de puntos." << endl;
                                                                cout << "PUNTAJE PARCIAL: " << puntajeacumulado << endl;
                                                            }
                                                            else{
                                                                    puntajeacumulado = puntosapostados*cantDadosRep;
                                                                    cout << "PUNTAJE PARCIAL: " << puntajeacumulado << endl;
                                                                    puntajefinal2 = puntajefinal2 + puntajeacumulado;
                                                            }
                                                       }
                                                       else{
                                                            if (sumamax<=19){
                                                                    cout << "Se restan los puntos de apuesta a su puntaje final." << endl;
                                                                    puntajefinal2 = puntajefinal2 - puntosapostados;
                                                                    if (puntajefinal2<=0){
                                                                        puntajefinal2=0;
                                                                    }
                                                                    cout << "PUNTAJE PARCIAL: " << puntajefinal2 << endl;
                                                            }
                                                       }
                                                }
                                        }
                                        system("pause");
                                        system("cls");
                                    }
                                    /// OPCION 3 CASE: PUNTUACION MAS ALTA
                                    if(puntajefinal1 >= puntajefinal2){
                                            if(puntajefinal1 >= highestScore){
                                                highestScore = puntajefinal1;
                                                strcpy(highestScorePlayer,player1);
                                            }
                                    }
                                    else{
                                        if(puntajefinal2 >= puntajefinal1){
                                            if(puntajefinal2 >= highestScore){
                                                highestScore = puntajefinal2;
                                                strcpy(highestScorePlayer,player2);
                                            }
                                        }
                                    }
                                    ///DATOS DE SALIDA PARA ESTA OPCION
                                    if(puntajefinal1>=puntajefinal2){
                                        if(puntajefinal1>puntajefinal2){
                                            cout << "GANADOR: " << player1 << endl;
                                            cout << "Su puntaje total acumulado: " << puntajefinal1 << endl;;
                                        }
                                        else{
                                            cout << "Empate." << endl;
                                            cout << "Puntaje total acumulado: " << puntajefinal1 << endl;
                                        }
                                    }
                                    else{
                                        cout << "GANADOR: " << player2 << endl;
                                        cout << "Su puntaje total acumulado: " << puntajefinal2 << endl;
                                    }
                                    system("pause");
                                }
                        }
}



#endif // MENU_H_INCLUDED
