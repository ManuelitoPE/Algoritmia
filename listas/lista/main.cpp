//Author: MAKO
#include <iostream> 
#include <iomanip> 
#include <cstring>
using namespace std;
#include "Pila.h"
//SKYNERT
int red[][7]{
    {0,10,10,10,20,10,10},
    {10,0,20,30,0,20,40},
    {0,0,0,0,0,100,0},
    {0,0,0,0,0,80,0},
    {50,10,5,10,0,100,4},
    {100,0,0,0,0,0,0},
    {0,0,0,0,0,0,0}
};
void buscarSkynet(int red[][7],int n);
int main(){
    int n;
    cout<<"Ingrese la dimension: ";
    cin>>n;
    buscarSkynet(red,n);
    return 0;
}
void buscarSkynet(int red[][7],int n){
    Pila pila;
    int a,b,c,flag=1;
    crearPila(pila);
    for(int i = 0;i < n;i++)apilar(pila,i);
    while(pila.lista.longitud>1){
        a = desapilar(pila);
        b = desapilar(pila);
        if(red[a][b]==0)apilar(pila,b);
        else apilar(pila,a);
    }
    c = desapilar(pila);
    for(int i = 0;i<n;i++){
        //Aseguramos que siempre envie algo
        if(not red[c][i] and i!=c) flag = 0;
        else if(red[i][c]!=0)flag = 0;
    }
    if(flag)cout<<"El servidor "<<c+1<< " es SKYNERD"<<endl;
    else cout<<"SkyNerd no esta en la red"<<endl;
}