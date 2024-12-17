//Author: MAKO
#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;
int main(){
    //Datos
    int arr[10] = {3,2,7,5,4,9,8,1,6,0},min,aux;
    //Se envia los numeros mayores para atras, asi ordenandolos
    //Como se va obteniendo los mayores ya ordenados, vamos acortando
    //El dominio para ordenar
    for (int i = 0; i<10-1; i++){
        for (int j = 0; j <9-i ; j++){
            //Encuentro el menor
            if(arr[j]>arr[j+1]){
                aux = arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=aux;
            }
        }
    }
    for(int i=0; i<10;i++)cout<<arr[i]<<endl;
    return 0;
}
