//Author: MAKO 
#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;
#include "listaEnlazada.h"

void iniciarLista(Lista& lista){
    lista.cabeza = nullptr;
    lista.longitud = 0;
}
void ingresarInicio(Lista& lista, int dato){
    Nodo* nuevo = new Nodo;
    nuevo->dato = dato;
    nuevo->siguiente = lista.cabeza;
    lista.cabeza = nuevo;
    lista.longitud++;
}
void ingresarOrdenado(Lista& lista,int dato){
    Nodo* ptr = lista.cabeza;
    Nodo* anterior = nullptr;
    Nodo* nuevo = new Nodo;
    nuevo->dato = dato;
    while (ptr){
        if(ptr->dato > dato)break;
        anterior = ptr;
        ptr = ptr->siguiente;
    }
    nuevo->siguiente = ptr;
    if(anterior)anterior->siguiente = nuevo;
    else lista.cabeza = nuevo;

}
void imprimirLista(Lista lista){
    Nodo* ptr = lista.cabeza;
    while(ptr){
        cout<<ptr->dato<<endl;
        ptr = ptr->siguiente;
    }
}
void eliminarCola(Lista& lista){
    Nodo* ptr = lista.cabeza;
    while (true){
        if(ptr->siguiente->siguiente == nullptr){
            Nodo* destruir = ptr->siguiente;
            ptr->siguiente = nullptr;
            delete destruir;
            lista.longitud--;
            break;
        }
        ptr = ptr->siguiente;
    }
}
void destruirLista(Lista& lista){
    Nodo* ptr  = lista.cabeza;
    while (ptr != nullptr){
        Nodo* destruccion = ptr;
        ptr = ptr->siguiente;
        delete destruccion;
    }
    lista.cabeza = nullptr;
    lista.longitud = 0;
}
void eliminarNodo(Lista& lista,int dato){
    Nodo* ptr = lista.cabeza;
    while (ptr->siguiente->dato != dato and ptr->siguiente != nullptr)
        ptr = ptr->siguiente;
    if(ptr->siguiente->dato == dato){
            cout<<"Te encontre!"<<endl;
        Nodo* destruir = ptr->siguiente;
        ptr->siguiente = ptr->siguiente->siguiente;
        delete destruir;
        lista.longitud--;
        cout<<"Te Elimine!"<<endl;
    }
}
void eliminaCabeza(Lista & lista) {
    Nodo * nodoAEliminar = lista.cabeza;
    if (nodoAEliminar != nullptr) {
        lista.cabeza = lista.cabeza->siguiente;
        delete nodoAEliminar;
        lista.longitud--;
    }
}
const bool esListaVacia(const struct Lista & tad) {
    return tad.cabeza == nullptr;
}