// Author: mako
#include <iostream>
#include <cmath>
using namespace std;

void cargabin(int iteracion, int numArmas, int* cromo) {
    int resto, k = 0;
    for (int i = 0; i < numArmas; i++) cromo[i] = 0;
    while (iteracion > 0) {
        resto = iteracion % 2;
        iteracion /= 2;
        cromo[k] = resto;
        k++;
    }
}

void cargarArmas(int armaPelea[][5], int armaAlmacen[][5], int numArmas) {
    for (int i = 0; i < numArmas; i++) {
        for (int k = 0; k < 5; k++) {
            armaPelea[i][k] = armaAlmacen[i][k];
        }
    }
}

bool verificarArma(int* armasParaVencer, int* armasParaPelear) {
    for (int i = 0; armasParaVencer[i]; i++) {
        if (armasParaVencer[i] == armasParaPelear[1])  // Verificar si el tipo de arma coincide
            return true;
    }
    return false;
}

bool verificarRequisitos(int* armasParaPelear, int* cromo, int numArmas) {
    for (int i = 2; i < 5; i++) {
        int requisito = armasParaPelear[i];
        if (requisito != 0 && cromo[requisito - 1] == 0)
            return false; // Si tiene un requisito y no está seleccionado
    }
    return true;
}

int main() {
    // Poder de los guerreros
    int poderGuerreros[] = {120, 160, 80}, numGuerreros = 3;
    // Armas para vencerlos (tipos permitidos)
    int armasParaVencer[][3] = { {2, 0}, {1, 3, 0}, {3, 0} };

    // Armas a nuestra disposición (poder, tipo y máximo 3 requisitos)
    int armaPoderTipoREQ[][5] = {
        {60, 3, 0, 0, 0}, {80, 1, 1, 0, 0}, {38, 2, 0, 0, 0}, {25, 2, 3, 0, 0}, {49, 2, 0, 0, 0},
        {57, 1, 0, 0, 0}, {68, 3, 0, 0, 0}, {35, 2, 1, 5, 0}, {62, 2, 3, 0, 0}, {42, 2, 0, 0, 0},
        {36, 1, 1, 0, 0}, {54, 3, 0, 0, 0}
    }, numArmas = 12, armasParaPelear[12][5];
    
    int mejorPoder = 0, mejorCombinacion = 0;
    int soluciones[30] = {}, contSolu = 0;
    // Posibilidades (2^numArmas combinaciones)
    int posibilidades = pow(2, numArmas);
    int cromo[numArmas];

    // Para cada guerrero
    for (int k = 0; k < numGuerreros; k++) {
        // Revisamos todas las posibilidades
        for (int i = 0; i < posibilidades; i++) {
            int poderCalculado = 0;
            cargarArmas(armasParaPelear, armaPoderTipoREQ, numArmas);
            cargabin(i, numArmas, cromo);

            // Posibilidad de armas seleccionadas
            for (int h = 0; h < numArmas; h++) {
                if (cromo[h] == 1) {  // Si el arma está seleccionada
                    // Verificar si el tipo de arma puede contra el guerrero
                    if (verificarArma(armasParaVencer[k], armasParaPelear[h])) {
                        // Verificar si los requisitos se cumplen
                        if (verificarRequisitos(armasParaPelear[h], cromo, numArmas)) {
                            poderCalculado += armaPoderTipoREQ[h][0]; // Sumar poder del arma
                        }
                    }
                }
            }

            // Si el poder calculado es mayor o igual al poder del guerrero
            if (poderCalculado >= poderGuerreros[k]) {
                soluciones[contSolu] = i;
                contSolu++;
            }
        }
    }

    // Imprimir las combinaciones que vencen a los guerreros
    for (int a = 0; a < contSolu; a++) {
        cout << "Combinación: " << soluciones[a] << endl;
        cargabin(soluciones[a], numArmas, cromo);
        for (int s = 0; s < numArmas; s++) {
            if (cromo[s] == 1) {  // Si el arma está seleccionada
                cout << "Arma con poder: " << armaPoderTipoREQ[s][0] << " Tipo: " << armaPoderTipoREQ[s][1] << endl;
            }
        }
        cout << "-----------------" << endl;
    }

    return 0;
}
