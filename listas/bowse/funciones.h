#ifndef FUNCIONES_H
#define FUNCIONES_H
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "Lista.h"

void inicializarLista(Lista& lista);
void ingresarGuerreros(Lista& guerreros,int cantGuerreros);
void ingresarInicio(Lista& lista,int dato);
void ingresarFinal(Lista& lista,int dato);
void imprimirLista(Lista lista);
void formarEjercito(Lista& ejercito1,Lista& ejercito2,Lista& ejercito3,
                    int& ataque1,int& ataque2,int& ataque3,
                    Lista& guerreros);

#endif