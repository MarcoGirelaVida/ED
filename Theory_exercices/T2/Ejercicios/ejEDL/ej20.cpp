/*
Implementar una función 
                    void rotación(queue<int> & C);
que saque una cierta cantidad de enteros del frente de la cola C y los vuelve a
insertar al final de cola, de forma que quede en el frente el primer número par que
haya en la cola. Por ejemplo, si
 C={1,3,5,2,4}  ====>    C={2,4,1,3,5}

 23:15
 23:23
*/

#include <iostream>
#include <queue>
using namespace std;

void imprimir_cola(queue<int> &C)
{
    int c_size = C.size();
    for (size_t i = 0; i < c_size; i++)
    {
        cout << C.front() << ",";
        C.push(C.front());
        C.pop();
    }
}

void rotacion(queue<int> & C)
{
    while (C.front()%2)
    {
        C.push(C.front());
        C.pop();
    }
}


int main()
{
    queue<int> C;
    C.push(1);
    C.push(3);
    C.push(5);
    C.push(2);
    C.push(4);

    imprimir_cola(C);
    cout << endl;
    rotacion(C);
    imprimir_cola(C);
    cout << endl;

    cout << "Expected values:" << endl;
    cout << "2,4,1,3,5" << endl;

    return 0;
}