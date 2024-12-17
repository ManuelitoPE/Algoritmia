//Author: MAKO
#include <iostream>
#include <iomanip>
using namespace std;
#include "Pila.h"

void crearPila(Pila& pila){
    iniciarLista(pila.lista);
}
void apilar(Pila& pila, int elemento){
    ingresarInicio(pila.lista, elemento);
}
int desapilar(Pila& pila){
    int elemento = pila.lista.cabeza->dato;
    eliminaCabeza(pila.lista);  
    return elemento;
}
bool esPilaVacia(const struct Pila & pila){
    return esListaVacia(pila.lista);
}
