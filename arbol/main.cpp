//Author: MAKO
#include <iostream>
#include <iomanip>
using namespace std;
#include "header/Arbol.h"
int main(){
    Arbol raiz;
    crearArbol(raiz);

    insertar(raiz, 50, 1);  // Nodo raíz
    insertar(raiz, 30, 2);  // Subárbol izquierdo
    insertar(raiz, 70, 3);  // Subárbol derecho
    insertar(raiz, 20, 4);  // Subárbol izquierdo del nodo 2
    insertar(raiz, 35, 5);  // Subárbol derecho del nodo 2
    insertar(raiz, 90, 6);  // Subárbol derecho del nodo 3
    insertar(raiz, 100, 7); // Subárbol derecho del nodo 6    

    porAmplitud(raiz.raiz);
    int x = calcularAlutura(raiz.raiz);
    cout<<endl<<x<<endl;
     x = alturaRecursivo(raiz.raiz);
    cout<<endl<<x<<endl;

    if(arbolEquilibrado(raiz.raiz))
        cout<<"Arbol equilibridado"<<endl;
    else cout<<"Arbol no equilibridado"<<endl;

    return 0;
}