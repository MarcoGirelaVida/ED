/*
19.  Dada una pila P de enteros implementar una función 
                        void transformarpila(stack<int> & p);
que transforme una pila p en otra en la que los elementos aparezcan en el mismo
orden original y habiendo sido eliminados los elementos que siendo consecutivos
aparezcan repetidos.
Ejemplo: P =<1,1,2,3,3,4,5,5,1,1,9,8,7,7,3> pasaría a quedar como P = <1,2,3,4,5,1,9,8,7,3>

22:57
23:12
*/

#include <iostream>
#include <stack>
using namespace std;

void imprime_pila(stack<int> &S)
{ 
    stack<int> aux;
    while (!S.empty())
    {
        aux.push(S.top());
        S.pop();
    }
    while (!aux.empty())
    {
        cout << aux.top() << ",";
        S.push(aux.top());
        aux.pop();
    }
    cout << endl;
}

void transformarpila(stack<int> & p)
{
    stack<int> aux;
    aux.push(p.top());
    p.pop();

    while (!p.empty()){
        if (p.top() != aux.top())
            aux.push(p.top());
        p.pop();
    }

    while (!aux.empty()){
        p.push(aux.top());
        aux.pop();
    }
}

int main()
{
    stack<int> p;
    p.push(1);
    p.push(1);
    p.push(2);
    p.push(3);
    p.push(3);
    p.push(4);
    p.push(5);
    p.push(5);
    p.push(1);
    p.push(1);
    p.push(9);
    p.push(8);
    p.push(7);
    p.push(7);
    p.push(3);

    imprime_pila(p);
    transformarpila(p);
    imprime_pila(p);
    cout << "Expected output:" << endl;
    cout << "1,2,3,4,5,1,9,8,7,3" << endl;
}