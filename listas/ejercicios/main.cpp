//Author: MAKO
#include <iostream>
#include <iomanip>
using namespace std;
#include "header/funciones.h"
int main(){
    Lista numeros;
    construir(numeros);
    insertarEnOrden(numeros,10);
    insertarEnOrden(numeros,1);
    insertarEnOrden(numeros,3);
    insertarEnOrden(numeros,4);
    insertarEnOrden(numeros,56);
    imprime(numeros);
    return 0;
} 