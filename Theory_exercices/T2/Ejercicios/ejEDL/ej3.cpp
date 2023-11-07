/*
Dada una lista de enteros y una pila de enteros deducir si todos los elementos de la 
lista están contenidos en la pila y además contienen el mismo numero de enteros. La 
cabecera de la función es: 
bool es_permutacion(const list<int> &L, const stack<int> & q); 
Ejemplo: 
L={1,2,4,5{ y q ={5,4,1,2} devolvería True 
 
L={1,3,9} y q={3,9,9,1} devolvería False
*/

// PROBLEMA la pila de la cabecera no puede ser constante no?
#include <iostream>
#include <list>
#include <stack>
using namespace std;

bool es_permutacion(const list<int> &L, stack<int> & q)
{
    bool es = L.size() == q.size();

    while (es && !q.empty())
    {
        bool skip = false;
        for (list<int>::const_iterator it = L.cbegin(); !skip && es && it != L.cend(); ++it)
            if (q.top() == (*it))
                skip = true;   

        es = skip;
        q.pop();
    }
    
    return es;
}

int main()
{
    list<int> L={1,2,4,5};
    stack<int> q;
    q.push(5);
    q.push(4);
    q.push(1);
    q.push(2);
    cout << (es_permutacion(L, q) ? "True" : "False") << endl;

    L= {1,3,9};
    q.push(3);
    q.push(9);
    q.push(9);
    q.push(1);
    cout << (es_permutacion(L, q) ? "True" : "False") << endl;
}