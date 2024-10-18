#include <iostream>
using namespace std;

// Función para copiar una matriz de tamaño m x n
void copiarMatriz(int origen[][3], int destino[][3], int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            destino[i][j] = origen[i][j];  // Copiamos el valor de origen a destino
        }
    }
}

int main() {
    // Definir una matriz origen de 2x3
    int origen[2][3] = {{1, 2, 3}, {4, 5, 6}};
    int destino[2][3];  // Matriz destino vacía

    // Llamar a la función para copiar
    copiarMatriz(origen, destino, 2, 3);

    // Imprimir la matriz destino para verificar la copia
    cout << "Matriz destino copiada:" << endl;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            cout << destino[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
