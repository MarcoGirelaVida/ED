/*
Un functor es básicamente una clase cualquiera que tenga el operator ()
Generalmente no tiene más métodos más allá de este.
*/

#include<iostream>
#include<list>
#include<algorithm>
using namespace std;

bool iguales_enteros(double v1, double v2){ return (int)v1==(int)v2; }
bool compara(double v1, double v2){ return v1 > v2; }
void imprimir(double a){ cout << a << "\t"; }
void mostrar_lista(list<double> l1){
    for_each(l1.begin(), l1.end(), imprimir);
    cout << endl;
}

int main(){
    double m[] = {2.45,2.45,3.44,3.654,5.543,6.75,8.76,8.86,10.34,10.34};
    list<double> l1(m,m+10);

    l1.sort(); // Los ordena de forma creciente por defecto
    mostrar_lista(l1);

    l1.sort(compara);  // Los ordena de acuerdo al criterio de la función compara
    mostrar_lista(l1);

    l1.unique(); // Elimina los elementos repetidos
    mostrar_lista(l1);

    l1.unique(iguales_enteros); // Elimina los elementos que están repetidos según la función iguales enteros
    mostrar_lista(l1);
}