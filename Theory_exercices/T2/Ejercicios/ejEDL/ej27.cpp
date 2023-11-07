/*
Escribir una función
                         void creciente(queue<int> &Q);
que elimina elementos de Q de tal manera de que los elementos que quedan estén
ordenados en forma creciente.
Por ejemplo, si Q={5,5,9,13,19,17,16,20, 19, 21} tras aplicar la función, debe quedar Q={5,5,9,13,19,20,21}
23:36
23:45
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

void creciente(queue<int> &Q)
{
    int Q_size = Q.size();
    int cache = Q.front();
    for (size_t i = 0; i < Q_size; i++)
    {
        if (Q.front() >= cache){
            Q.push(Q.front());
            cache = Q.front();
        }
        Q.pop();
    }
}

int main()
{
    queue<int> Q;
    Q.push(5);
    Q.push(5);
    Q.push(9);
    Q.push(13);
    Q.push(19);
    Q.push(17);
    Q.push(16);
    Q.push(20);
    Q.push(19);
    Q.push(21);

    imprimir_cola(Q);
    cout << endl;
    creciente(Q);
    imprimir_cola(Q);
    cout << endl;

    cout << "Expected values: " << endl;
    cout << "5,5,9,13,19,20,21" << endl;
    return 0;
}