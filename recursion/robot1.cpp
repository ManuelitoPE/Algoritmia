//Author: MAKO
#include <iostream>
#include <iomanip>
using namespace std;

int robot(int x,int y,int n,int m,int tablero[][3]){
    int derecha = -999999, abajo = -999999;
    if(x==n-1 and y==m-1)
        return tablero[x][y];
    if(y+1<m)
        derecha = robot(x,y+1,n,m,tablero);
    if(x+1<n)
        abajo = robot(x,y+1,n,m,tablero);
    if(abajo<derecha)
        return derecha+tablero[x][y];
    return abajo+tablero[x][y];
}
int main(){
    //Datos 
    int n=3, m=3;
    int tablero[][3]={
        {2,5,1},
        {2,9,1},
        {14,3,5}
    }; 
    cout<<"El total es: "<<robot(0,0,n,m,tablero);
    return 0;
}