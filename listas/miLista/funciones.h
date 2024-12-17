#ifndef FUNCIONES_H
#define FUNCIONES_H
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "lista.h"

void construirLista(Lista& lista);
void insertarDatos(Lista& lista);
void ingresarInicio(Lista& lista,int dato);
void ingresarFinal(Lista& lista,int dato);
void eliminarCola(Lista& lista);
void eliminarNodo(Lista& lista,int dato);
void destruirLista(Lista& lista);
void imprimirDatos(Lista lista);
void insertarOrdenado(Lista& lista,int dato);


#endif