#include "funciones.h"

void construirLista(Lista& lista){
    lista.cabeza = nullptr;
    lista.longitud = 0;
}
void insertarDatos(Lista& lista){
    ifstream arch("datos.txt",ios::in);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir datos"<<endl;
        exit(1);
    }
    int dato;
    while(not arch.eof()){
        arch>>dato;
        insertarOrdenado(lista,dato);
    }
}
void insertarOrdenado(Lista& lista,int dato){
    Nodo *ptr = lista.cabeza;
    Nodo *anterior = nullptr;
    Nodo *nuevo = new Nodo;
    nuevo->dato = dato;
    while (ptr){
        if(ptr->dato>dato)break;
        anterior = ptr;
        ptr = ptr->siguiente;
    }
    nuevo->siguiente = ptr;
    if(anterior) anterior->siguiente = nuevo;
    else lista.cabeza = nuevo;
}
void ingresarInicio(Lista& lista,int dato){
    //Creamos un nuevo nodo
    Nodo* nuevo = new Nodo;
    nuevo->dato = dato;
    nuevo->siguiente =  lista.cabeza;
    lista.cabeza = nuevo;    
    lista.longitud++;
}
void imprimirDatos(Lista lista){
    Nodo* ptr = lista.cabeza;
    while (ptr!= nullptr){
        cout<<ptr->dato<<endl;
        ptr = ptr->siguiente;
    }   
}
void ingresarFinal(Lista& lista,int dato){
    Nodo* nuevo = new Nodo;
    nuevo->dato = dato;
    Nodo* ptr = lista.cabeza;
    if(lista.cabeza == nullptr){
        //Si la lista esta vacia
        nuevo->siguiente = lista.cabeza;
        lista.cabeza = nuevo;
    }else{
        while (true){    
            if(ptr->siguiente == nullptr){
                nuevo->siguiente = ptr->siguiente;
                ptr->siguiente = nuevo;
                lista.longitud++;
                break;
            }
            ptr = ptr->siguiente;
        }
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
