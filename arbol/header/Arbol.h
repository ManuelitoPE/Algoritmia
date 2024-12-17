//Auhtor: MAKO
#ifndef ARBOL_H
#define ARBOL_H
#include <iostream>
#include <iomanip>
#include <queue>
using namespace std;
#include "Nodo.h"
//Estructura
struct Arbol{
    Nodo* raiz;
};
//Funciones
void crearArbol(Arbol& arbol);
bool esArbolVacio(Arbol& arbol);
bool esNodoVacio(Nodo* nodo);
void plantar(Arbol& arbol, Arbol& izquierdo, Arbol& derecho,
             int peso,int id);
void plantar(Arbol& arbol, Nodo* izquierdo, Nodo* derecho,
             int peso,int id);
void plantar(Arbol& arbol, Nodo* izquierdo, Arbol& derecho,
             int peso,int id);
void plantar(Arbol& arbol, Arbol& izquierdo, Nodo* derecho,
             int peso,int id);
void enOrden(Nodo* nodo);
void insertar(Arbol& arbol,int peso,int id);
void insertarRecursivo(Nodo*& nodo,int peso,
                       int id);
void porAmplitud(Nodo* nodo);                       
Nodo* buscar(int valor,Nodo* nodo);
int calcularAlutura(Nodo* nodo);
int alturaRecursivo(Nodo * nodo);
bool arbolEquilibrado(Nodo* nodo);


#endif
