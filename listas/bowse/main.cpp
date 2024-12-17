//AUTHOR: MAKO
#include "funciones.h"
 
int main(){
    // Datos
    int n, cantGuerreros;
    Lista guerreros;
    inicializarLista(guerreros);
    // cout<<"Ingrese el valor de n: ";
    // cin>>n;
    // cout<<endl<<"Ingrese la cantidad total de guerreros: ";
    // cin>>cantGuerreros;
    ingresarGuerreros(guerreros,cantGuerreros);
    cout<<endl<<"Lista Guerreros: :";
    imprimirLista(guerreros);
    //Formar los ejercitos
    Lista ejercito1,ejercito2,ejercito3;
    int ataque1,ataque2,ataque3;
    ataque1 = ataque2 = ataque3 = 0;
    inicializarLista(ejercito1);
    inicializarLista(ejercito2);
    inicializarLista(ejercito3);
    formarEjercito(ejercito1,ejercito2,ejercito3,ataque1,ataque2,ataque3,guerreros);
    cout<<endl<<"Los ejercitos formados son: "<<endl;
    cout<<"Ejercito 1 - Bowser:";
    imprimirLista(ejercito1);
    cout<<endl<<"Nivel de Ataque del Ejercito 1: "<<ataque1<<endl;
    cout<<"Ejercito 1 - Peach:";
    imprimirLista(ejercito2);
    cout<<endl<<"Nivel de Ataque del Ejercito 1: "<<ataque2<<endl;
    cout<<"Ejercito 1 - Donkey Kong:";
    imprimirLista(ejercito3);
    cout<<endl<<"Nivel de Ataque del Ejercito 1: "<<ataque3<<endl;

    return 0;
}