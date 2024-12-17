//Author: MAKO 
#include "header/Arbol.h"

void crearArbol(Arbol& arbol){
    arbol.raiz = nullptr;
}

bool esArbolVacio(Arbol& arbol){
    if(arbol.raiz == nullptr)return true;
    else return false;
}

bool esNodoVacio(Nodo* nodo){
    return nodo == nullptr;
}

Nodo* crearNuevoNodo(Nodo* izquierdo,Nodo* derecho, int peso,
                    int id){
    Nodo* nuevo = new Nodo;
    nuevo->derecha = derecho;
    nuevo->izquieda =  izquierdo;
    nuevo->id = id;
    nuevo->peso = peso;
    return nuevo;
}

void plantar(Arbol& arbol, Arbol& izquierdo, Arbol& derecho,
             int peso,int id){
    Nodo* nuevoNodo = crearNuevoNodo(izquierdo.raiz,derecho.raiz,
                      peso,id);
    arbol.raiz = nuevoNodo;
}
void plantar(Arbol& arbol, Nodo* izquierdo, Nodo* derecho,
             int peso,int id){
    Nodo* nuevoNodo = crearNuevoNodo(izquierdo,derecho,
                      peso,id);
    arbol.raiz = nuevoNodo;

}
void plantar(Nodo*& arbol, Nodo* izquierdo, Nodo* derecho,
             int peso,int id){
    Nodo* nuevoNodo = crearNuevoNodo(izquierdo,derecho,
                      peso,id);
    arbol = nuevoNodo;

}
void plantar(Arbol& arbol, Nodo* izquierdo, Arbol& derecho,
             int peso,int id){
    Nodo* nuevoNodo = crearNuevoNodo(izquierdo,derecho.raiz,
                      peso,id);
    arbol.raiz = nuevoNodo;
}
void plantar(Arbol& arbol, Arbol& izquierdo, Nodo* derecho,
             int peso,int id){
    Nodo* nuevoNodo = crearNuevoNodo(izquierdo.raiz,derecho,
                      peso,id);
    arbol.raiz = nuevoNodo;
}

void enOrden(Nodo* nodo){
    if(nodo != nullptr){
        enOrden(nodo->izquieda);
        cout<<nodo->peso<<" "<<nodo->id<<endl;
        enOrden(nodo->derecha);
    }
}

void insertar(Arbol& arbol,int peso,int id){
    insertarRecursivo(arbol.raiz,peso,id);
}
void insertarRecursivo(Nodo*& nodo,int peso,
                       int id){
    if(nodo==nullptr)
        plantar(nodo,nullptr,nullptr,peso,id);
    else if(nodo->peso > peso)
        insertarRecursivo(nodo->izquieda,peso,id);
    else if(nodo->peso < peso)
        insertarRecursivo(nodo->derecha,peso,id);
    else
        nodo->id = nodo->id*10+id;
}
void porAmplitud(Nodo* arbol){
    Nodo* ptr = arbol;
    queue<int> cola;
    int valor;
    if(ptr == nullptr)return;
    cola.push(ptr->peso);
    while(!cola.empty()){
        valor = cola.front();
        cola.pop();
        //Encontramos el valor
        ptr = buscar(valor,arbol);
        cout<<ptr->peso<<" "<<ptr->id<<endl;
        if(ptr->derecha!=nullptr)cola.push(ptr->derecha->peso);
        if(ptr->izquieda!=nullptr)cola.push(ptr->izquieda->peso);
    }
}   

Nodo* buscar(int valor,Nodo* nodo){
    if(nodo == nullptr)return nullptr;
    if(nodo->peso == valor)return nodo;
    else if(nodo->peso>valor)buscar(valor,nodo->izquieda);
    else if(nodo->peso<valor)buscar(valor,nodo->derecha);
}

int calcularAlutura(Nodo* nodo){
    if(nodo == nullptr)return 0;
    int iz = 1 + calcularAlutura(nodo->izquieda);
    int de = 1 + calcularAlutura(nodo->derecha);
    if(de>iz)return de;
    return iz;
}

int maximo(int a, int b){
    return a >= b ? a : b;
}
int alturaRecursivo(Nodo * nodo){
    if(nodo == nullptr)
        return 0;
    else if(nodo->izquieda == nullptr and nodo->derecha == nullptr)
        return 0;
    else
        return 1 + maximo(alturaRecursivo(nodo->izquieda), alturaRecursivo(nodo->derecha));
}
bool arbolEquilibrado(Nodo* nodo){
    if(nodo == nullptr)return true;
    int a = calcularAlutura(nodo->izquieda) -
                calcularAlutura(nodo->derecha); 
    if(abs(a)>1)return false;

    return arbolEquilibrado(nodo->derecha) and 
        arbolEquilibrado(nodo->izquieda);
}







//Author: MAKO
// #include <iostream>
// #include <iomanip>
// using namespace std;
// #include "header/Arbol.h"


// int calcularAltura(Nodo* raiz) {
//     if (raiz == nullptr) {
//         return 0;
//     }
//     int alturaIzquierda = calcularAltura(raiz->izquieda);
//     int alturaDerecha = calcularAltura(raiz->derecha);
//     return 1 + max(alturaIzquierda, alturaDerecha);
// }
// bool verificacion(Nodo* nodo,int patron){
//     int idA,idB,patronID, a =1;
//     if(patron==0)return true;
//     if(nodo == nullptr)return false;
//     if(nodo->id > 10){
//         idA = (nodo->id)%10;
//         idB = (nodo->id)/10;
//     }else idA = nodo->id;
//     if(patron>100){
//         patronID = patron/100;
//         a=100;
//     }else if(patron>10){
//         patronID  = patron/10;
//         a = 10;
//     }else patronID = patron;
//     if(idA==patronID or idB ==patronID){
//         if(verificacion(nodo->izquieda,patron-(a*patronID))
//          or verificacion(nodo->derecha,patron-(a*patronID)))
//          return true;
//     } 
//     return false;
// }
// void imprimirNivel(Nodo* raiz, int nivel, int patron,int& cant) {
//     if (raiz == nullptr) {
//         return;
//     }
//     if (nivel == 1) {
//         //Verificacion
//         if(verificacion(raiz,patron))cant++;
//         cout << raiz->peso << " "; // Imprimir el nodo en el nivel actual
//     } else if (nivel > 1) {
//         imprimirNivel(raiz->izquieda, nivel - 1,patron,cant);
//         imprimirNivel(raiz->derecha, nivel - 1,patron,cant);
//     }
// }

// void imprimirPorAmplitudRecursivo(Nodo* raiz,int patron) {
//     int altura = calcularAltura(raiz);
//     int cant;
//     for (int i = 1; i <= altura; i++) {
//         cant = 0;
//         cout<<"Nivel "<<i<<" = ";
//         imprimirNivel(raiz, i, patron,cant);
//         cout<<cant<<endl;
//     }
// }

// int main(){
//     Arbol arbol {};
//     crearArbol(arbol);

//     insertar(arbol,180,1);
//     insertar(arbol,250,5);
//     insertar(arbol,120,6);
//     insertar(arbol,120,8);
//     insertar(arbol,100,3);
//     insertar(arbol,150,9);
//     insertar(arbol,230,9);
//     insertar(arbol,230,2);
//     insertar(arbol,280,4);
//     insertar(arbol,80,8);
//     insertar(arbol,80,2);
//     insertar(arbol,140,2);
//     insertar(arbol,90,9);
//     insertar(arbol,160,7);
//     insertar(arbol,200,1);
//     insertar(arbol,240,3);
//     insertar(arbol,240,7);
//     insertar(arbol,260,6);

//     int cant,patron;
//     cout<<"Ingrese los cantidad de cambios de emociones: ";
//     cin>>cant;
//     while(cant--){
//         //Se ingresa un patron  1-2-3 = 123
//         cout<<endl<<"Ingrese el patron: ";
//         cin>>patron;
//         imprimirPorAmplitudRecursivo(arbol.raiz,patron);
//     }
//     return 0;
// }

