/*
ESPECIFICACIÓN: Contienen una secuencia de valores especialmente diseñadas
para realizar los accesos y borrados por el frente y las inserciones se realizan
en cualquier punto de acuerdo con un criterio de prioridad.
*\

/*
OPERACIONES:
    - top: devuelve el elemento del frente (con más prioridad)
    - push: añadir un nuevo elemento
    - pop: eliminar el elemento más prioritario
    - size: nº elementos
    - empty: si está vacio o no
*/

/* COLAS CON PRIORIDAD EN LA STL */
#include <queue> // Es la misma librería, pero la clase se llama priority.queue
#include <iostream>

using namespace std;

int main(){
    priority_queue<int> mipq, otra; 
    /* La clase automáticamente si es una cola de enteros considera como criterio
     de prioridad el orden de los enteros (a mayor, más prioritario) */

    mipq.push(10);
    mipq.push(20);
    mipq.push(15);
    cout << mipq.top(); // Devolverá 20 por que es el más grande


    mipq.swap(otra);

    while(!otra.empty()){
    cout << otra.top();
    otra.pop();
    }

    priority_queue<pair<int, float>> mipq2, mipq3;
    // Es un push con "constructor automático", en
    // este caso lo usamos para los pair, pero valdría para cualquier otro objeto.
    // Equivale a un mipq.push(make_pair(2,10.1))
    mipq2.emplace(5,3.2);
    mipq3.emplace(3,9.5);
    /* Estas dos últimas ordenes no funcionarán sin añadir nada antes puesto
    que no sabe cómo ordenar los pair int, float, por tanto deberíamos sobrecargar
    el operator < con dos pair pra que me lo ordene */
}

bool operator<(const pair<int,float>&p1, const pair<int,float>&p2)
{
    return p1.second < p2.second;
}