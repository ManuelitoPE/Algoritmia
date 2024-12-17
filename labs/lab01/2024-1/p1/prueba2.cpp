//Author: MAK0
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
void cargaBin(int iteracion,int numArmas,int* cromo){
    int resto, k = 0;
    for (int i = 0; i < numArmas; i++) cromo[i] = 0;
    while (iteracion>0){
        resto = iteracion%2;
        iteracion/=2;
        cromo[k] = resto;
        k++;
    } 
}
bool coondicioTipo(int armasTipo[3],int armaPoderTipoREQ[5]){
    for (int i = 0; i < 3; i++){
        if(armasTipo[i]==armaPoderTipoREQ[1])return true;
    }
    return false;
}
bool coondicioPre(int armaPoderTipoREQ[5],int cromo[12],int n){
    //Las armas pre requisto
    for (int i = 2; i < 5; i++){
        if(armaPoderTipoREQ[i]!=0 && cromo[armaPoderTipoREQ[i]-1]==0)return false;
    }
    return true;
}
int main(){
    // Poder de los guerreros
    int poderGuerreros[] = {120, 160, 80}, numGuerreros = 3;
    // Armas para vencerlos (tipos permitidos)
    int armasParaVencer[][3] = { {2, 0, 0}, {1, 3, 0}, {3, 0, 0} };

    // Armas a nuestra disposición (poder, tipo y máximo 3 requisitos)
    int armaPoderTipoREQ[][5] = {
        {60, 3, 0, 0, 0}, {80, 1, 1, 0, 0}, {38, 2, 0, 0, 0}, {25, 2, 3, 0, 0}, {49, 2, 0, 0, 0},
        {57, 1, 0, 0, 0}, {68, 3, 0, 0, 0}, {35, 2, 1, 5, 0}, {62, 2, 3, 0, 0}, {42, 2, 0, 0, 0},
        {36, 1, 1, 0, 0}, {54, 3, 0, 0, 0}
    }, numArmas = 12;
    char letras[12] = {'Z','P','R','D','E','F','G','H','I','J','K','L'};
    int poderacumulado = 0;
    //Posibilidades
    int posibilidades = pow(2,numArmas);
    int cromo[numArmas];
    //Guaramos las respuestas
    int solucion[numArmas];
    int cantSoluciones = 0;
    //FLAGS
    int flag1 = true;
    int flag2 = true;
    //Para cada guerrero
    for(int i=0; i<numGuerreros; i++){
        //Reiniciamos las posibles soluciones
        cantSoluciones = 0;
        //Proceso
        //Para cada posibilidad
        for (int j = 0; j < posibilidades; j++){
            //Se genera una posibilidad
            cargaBin(j,numArmas,cromo);
            poderacumulado = 0;
            //Iteramos que armas prenden  
            for (int k = 0; k < numArmas; k++){
                //Para esta arma seleccionada 
                if(cromo[k]==1){
                    //Tiene que cumplir que
                        //Sea un tipo para el villano
                        //Cumpla los pre-requisitos
                    //Vemos si tiene alguno esos tipos
                    flag1 = coondicioTipo(armasParaVencer[i],armaPoderTipoREQ[k]);
                    //Vemos si se cumple los pre-requisitos
                    flag2 = coondicioPre(armaPoderTipoREQ[k],cromo,numArmas);
                    if(flag1&&flag2){
                        poderacumulado += armaPoderTipoREQ[k][0];
                        if(poderacumulado >= poderGuerreros[i]){
                            solucion[cantSoluciones] = j;
                            cantSoluciones++;
                            break;
                        }
                    }else break;
                }    
            }
            if(cantSoluciones)break;
        }
        
        //Imprimimos los resultados
        cout << "Guerrero " << i + 1 << ": \n";
        for (int b = 0; b < cantSoluciones; b++){
            //Ahora buscamos las combinaciones
            cargaBin(solucion[b],numArmas,cromo);
            cout<<"Armas en mochila para vencerlo: ";
            for (int c = 0; c < numArmas; c++){
                if(cromo[c]==1)cout<<letras[c]<<" ";
            }
            cout<<endl;
        }
        
    }
    return 0;
}