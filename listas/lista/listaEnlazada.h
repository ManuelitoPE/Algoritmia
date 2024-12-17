//Author: MAKO
#ifndef LISTAENLAZADA 
#define LISTAENLAZADA 
#include "Lista.h"

void iniciarLista(Lista& lista);
void ingresarInicio(Lista& lista, int dato);
void ingresarOrdenado(Lista& lista,int dato);
void imprimirLista(Lista lista);
void eliminarCola(Lista& lista);
void destruirLista(Lista& lista);
void eliminarNodo(Lista& lista,int dato);
void eliminaCabeza(Lista & lista);
const bool esListaVacia(const struct Lista & tad);
#endif