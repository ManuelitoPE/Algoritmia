#include <iostream>
#include <algorithm> // Para usar max()
using namespace std;

struct Nodo {
    int dato;
    Nodo* izquierda;
    Nodo* derecha;
};

// Función para crear un nuevo nodo
Nodo* crearNodo(int dato) {
    Nodo* nuevoNodo = new Nodo;
    nuevoNodo->dato = dato;
    nuevoNodo->izquierda = nullptr;
    nuevoNodo->derecha = nullptr;
    return nuevoNodo;
}

// Función para calcular la altura del árbol
int calcularAltura(Nodo* raiz) {
    if (raiz == nullptr) {
        return 0;
    }
    int alturaIzquierda = calcularAltura(raiz->izquierda);
    int alturaDerecha = calcularAltura(raiz->derecha);
    return 1 + max(alturaIzquierda, alturaDerecha);
}

// Función para imprimir los nodos de un nivel específico
void imprimirNivel(Nodo* raiz, int nivel) {
    if (raiz == nullptr) {
        return;
    }
    if (nivel == 1) {
        cout << raiz->dato << " "; // Imprimir el nodo en el nivel actual
    } else if (nivel > 1) {
        imprimirNivel(raiz->izquierda, nivel - 1);
        imprimirNivel(raiz->derecha, nivel - 1);
    }
}

// Función principal para imprimir por amplitud (recursiva)
void imprimirPorAmplitudRecursivo(Nodo* raiz) {
    int altura = calcularAltura(raiz);
    for (int i = 1; i <= altura; i++) {
        imprimirNivel(raiz, i);
    }
}

int main() {
    // Construcción del árbol
    Nodo* raiz = crearNodo(10);
    raiz->izquierda = crearNodo(5);
    raiz->derecha = crearNodo(15);
    raiz->izquierda->izquierda = crearNodo(3);
    raiz->izquierda->derecha = crearNodo(7);
    raiz->derecha->izquierda = crearNodo(12);
    raiz->derecha->derecha = crearNodo(18);

    cout << "Recorrido por amplitud (recursivo):" << endl;
    imprimirPorAmplitudRecursivo(raiz);

    return 0;
}

