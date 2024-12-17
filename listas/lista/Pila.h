//Author: PILA
#ifndef PILA_H 
#define PILA_H
#include "Lista.h"
#include "listaEnlazada.h"
struct Pila{
    Lista lista;
};

void apilar(struct Pila & pila, int elemento);
int desapilar(Pila& pila);
void crearPila(Pila& pila);
bool esPilaVacia(const struct Pila & pila);

#endif