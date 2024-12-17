//Author: MAKO
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

void cargabin(int j,int numLetras,int* cromo){
    int resto, k = 0;
    for (int i = 0; i < numLetras; i++)cromo[i]=0;
    while (j>0){
        resto = j%2;
        j /= 2;
        cromo[k] = resto;
        k++;
    }
} 
bool verficarPrimeraLetra(char letra,char primeraLetra){
    if(letra==primeraLetra)return true;
    return false;
}
bool verificarPalabra(char letras[8],int cromo[8],char palabra[4],int numletras){
    int letraApagada[4]={1,1,1,1};
    for (int i = 0; i < 4; i++){
        if(palabra[i]==' ')letraApagada[i]=0;
        else{
            //Si la letra es diferente del espacio
            //Si la letra esta prendida
            if(letraApagada){
                //Iteramos todas las palabras
                for (int j = 0; j < numletras; j++){
                    //Si encontramos la letra, nos aseguramos de ya no usar
                    //esa letra del croma y tambien no buscar la la palabra
                    if(cromo[j]==1 && letras[j]==palabra[i]){
                        letraApagada[i] = 0;
                        cromo[j] = 0;
                        break;
                    }
                }
            }
        }
    }
    
    int total = 0;
    int totalCromo = 0;
    for (int i = 0; i < 4; i++)total+=letraApagada[i];
    for (int i = 0; i < numletras; i++)totalCromo+=cromo[i];
    if(total == 0 && totalCromo ==0)return true;
    return false;
}
int main(){
    char letras[8] ={'G','A','L','A','O','G','L','M'};
    int numLetras = 8;
    char palabras[4][4] = {
        {'G','O','L',' '},
        {'G','A','L','A'},
        {'A','L','A',' '},
        {'L','O','M','A'}
    };
    int numPalabras = 4;
    int posibilidades = pow(2,numLetras);
    int cromo[numLetras];
    int soluciones[4]{};
    int cantSoluciones = 0;
    bool flag1;
    bool flag2;
    //Proceso por cada palabra
    for (int i = 0; i < numPalabras; i++){
        //Para cada palabra buscamos las posibles soluciones
        for (int j = 0; j < posibilidades; j++){
            //Cargamos el binario
            if(j==52){
                cout<<"gola";
            };
            cargabin(j,numLetras,cromo);
            //Vemos que palabras estan encendidas
            flag2 = verificarPalabra(letras,cromo,palabras[i],numLetras);
            if(flag2){
                cout<<j<<endl;
                soluciones[i]++;
            }

        }
        //Para cada palabra imprimimos una respuesta
        cout<<"La palabra ";
        for (int a = 0; a < 4; a++)cout<<palabras[i][a];
        cout<<" tiene "<<soluciones[i]<<" combinaciones de letras";
        cout<<endl;
    }
    
    return 0;
}