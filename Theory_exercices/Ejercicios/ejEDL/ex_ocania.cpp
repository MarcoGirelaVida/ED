/*
17:15
17:51
*/
#include <iostream>
#include <stack>
#include <queue>
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

bool sonIsomorficas (stack<int> p, queue<int> q)
{
    bool lo_son = (p.size()/2 == q.size()/2);
    stack<int> aux;

    while (!q.empty())
    {
        aux.push(q.front());
        q.pop();
    }

    // Reajuste por si hay una par y otra impar
    if (lo_son)
    {
        if (p.size()%2)
            p.pop();
        if (aux.size()%2)
            aux.pop();
    }
    bool iteracion_par = true;
    
    cout << "p.size: " << p.size() << " ,aux.size(): " << aux.size() << endl;
    while (lo_son && !p.empty())
    {
        cout << "p.top():" << p.top() << " aux.top()" << aux.top() << endl;
        if (iteracion_par && (p.top() != aux.top()))
            lo_son = false;

        p.pop();
        aux.pop();
        iteracion_par = !iteracion_par;
    }
    
    return lo_son;
}


int main()
{
    stack<int> p;
    p.push(3);
    p.push(7);
    p.push(7);
    p.push(8);
    p.push(9);
    p.push(4);
    p.push(3);
    p.push(3);
    p.push(2);
    p.push(1);
    p.push(1);

    queue<int> q;
    q.push(3);
    q.push(7);
    q.push(2);
    q.push(8);
    q.push(6);
    q.push(4);
    q.push(3);
    q.push(3);
    q.push(7);
    q.push(1);
    q.push(1);

    cout << (sonIsomorficas(p, q) ? "True" : "False") << endl;
    
    return 0;

}

