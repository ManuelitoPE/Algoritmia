#include "funciones.h"

void inicializarLista(Lista& lista){
    lista.cabeza = nullptr;
    lista.longitud = 0;
}
void ingresarGuerreros(Lista& guerreros,int cantGuerreros){
    ifstream arch("datos.txt",ios::in);
    int guerrero;
    char c;
    while(true){
        arch>>guerrero>>c;
        if(arch.eof())break;
        ingresarFinal(guerreros,guerrero);
    }
    
}
void ingresarInicio(Lista& lista,int dato){
    Nodo* nuevo = new Nodo;
    nuevo->dato = dato;
    nuevo->siguiente = lista.cabeza;
    lista.cabeza = nuevo;
}
void ingresarFinal(Lista& lista,int dato){
    Nodo* nuevo = new Nodo;
    nuevo->dato = dato;
    if(lista.cabeza==nullptr){
        nuevo->siguiente = lista.cabeza;
        lista.cabeza = nuevo;
    }else{
        Nodo* ptr = lista.cabeza;
        while (ptr->siguiente)ptr = ptr->siguiente;
        nuevo->siguiente = ptr->siguiente;
        ptr->siguiente = nuevo;
    }
}
void  ingresarOrdenado(Lista& lista,int poder){
    Nodo* ptr = lista.cabeza;
    Nodo* anterior = nullptr;
    Nodo* nuevo =  new Nodo;
    nuevo->dato = poder;
    while(ptr){
        if(ptr->dato>poder)break;
        anterior = ptr;
        ptr = ptr->siguiente;
    }
    nuevo->siguiente = ptr;
    if(anterior)anterior->siguiente = nuevo;
    else lista.cabeza = nuevo;
}

void imprimirLista(Lista lista){
    Nodo* ptr = lista.cabeza;
    while (ptr){
        cout<<ptr->dato<<", ";
        ptr = ptr->siguiente;
    }   
}
void formarEjercito(Lista& ejercito1,Lista& ejercito2,Lista& ejercito3,
                    int& ataque1,int& ataque2,int& ataque3,
                    Lista& guerreros){
    int ejercito, poder;
    Nodo* ptr  = guerreros.cabeza;
    while (ptr){
        ejercito = ptr->dato%10;
        poder = ptr->dato/10;
        switch (ejercito){
        case 1:
            ingresarOrdenado(ejercito1,poder);
            ataque1+=poder;
            break;
        case 2:
            ingresarOrdenado(ejercito2,poder);
            ataque2+=poder;
            break;
        case 3:
            ingresarOrdenado(ejercito3,poder);
            ataque3+=poder;
            break;
        default:
            break;
        }
        ptr = ptr->siguiente;
    }   
}