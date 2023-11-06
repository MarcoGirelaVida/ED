/*
Implementar una función:
                       void reordena(stack<int> &P); 
que   reordena   los   elementos   de   una   pila   de   tal   forma   que   quedan   los   elementos   impares
queden en el fondo y los que si lo satisfacen arriba.
Por ejemplo si P = {1, 3, 4, 2, 3, 5, 7, 6, 8, 2, 9}  entonces debe quedar P = {4, 2, 6, 8, 2, 1, 3, 3, 5, 7, 9}. 
Restricciones: el algoritmo debe ser estable, es decir los elementos pares deben quedar en el
mismo orden entre sí, y lo mismo para los impares. Se puede solo una estructura auxiliar de
tipo cola.
22:40
22:54
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
        cout << S.top() << " ,";
        aux.push(S.top());
        S.pop();
    }
    cout << endl;

    while (!aux.empty())
    {
        S.push(aux.top());
        aux.pop();
    }
}

void reordena(stack<int> &P)
{
    queue<int> aux;

    while (!P.empty())
    {
        aux.push(P.top());
        P.pop();
    }
    
    int size_cola = aux.size();
    
    for (size_t i = 0; i < size_cola; i++)
    {
        if (aux.front()%2)
        {
            P.push(aux.front());
            aux.pop();
        }
        else
        {
            aux.push(aux.front());
            aux.pop();
        }
    }

    while (!aux.empty())
    {
        P.push(aux.front());
        aux.pop();
    }
}

int main()
{

stack<int> P;
P.push(1);
P.push(3);
P.push(4);
P.push(2);
P.push(3);
P.push(5);
P.push(7);
P.push(6);
P.push(8);
P.push(2);
P.push(9);

imprime_pila(P);
cout << endl;

reordena(P);

imprime_pila(P);
cout << endl;

cout << "Expected output: " << endl;
cout << "4, 2, 6, 8, 2, 1, 3, 3, 5, 7, 9" << endl;
}