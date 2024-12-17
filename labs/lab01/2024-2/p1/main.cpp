//Author: Sergio Manuel Sutta Pinedo 20210646
#include <iostream>
#include <iomanip>
#include "Pila.h"

using namespace std;
#include "funcionesPila.h"
#define N  7
/*
 * IMPLEMENTACIÓN DE UNA PILA
 * ALGORITMIA Y ESTRUCTURA DE DATOS 2024-1
 */
int main(int argc, char** argv) {
    
    int tam[N] = {6,2,6,2,6,2,6};
    int numDatos = N;
    Pila pilaAux;
    construir(pilaAux);
    int a = 0,b =1;
    //Ingresamos las posiciones del arreglo a la pila
    //Datos imporantes
    int posicionMax = 0;
    int maxPilasPequenas = 0;
    int pilasPequenas = 0;
    //Apilo siempre uno (Pila Aux)
    apilar(pilaAux,a);
    //Proceso
    while(numDatos){
        //Agarro en la mano
        a = desapilar(pilaAux);
        //Comparacion
        if(tam[a]!=tam[b]){
            pilasPequenas++;
            //Añado a la pila
            if(tam[a]>tam[b]){
                apilar(pilaAux,a);
            }
            else apilar(pilaAux,b);    
        }else{
            //Si ambos son iguales
            if(maxPilasPequenas<pilasPequenas){
                maxPilasPequenas = pilasPequenas;
                posicionMax = a;
            }
            pilasPequenas = b-a-1;
            apilar(pilaAux,b);
        }
        numDatos--;
        b++;
    }
    //Salida
    if(posicionMax==0 or maxPilasPequenas<pilasPequenas)
        posicionMax = desapilar(pilaAux);
    if(maxPilasPequenas==0 or maxPilasPequenas<pilasPequenas)
        maxPilasPequenas=pilasPequenas;
    cout<<"Posicion = "<<posicionMax<<", con "<<maxPilasPequenas<<" pilas "
        <<"pequeñas alrededor"<<endl;
   
    return 0;
}

