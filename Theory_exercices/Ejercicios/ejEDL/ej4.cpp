/*
(Es el 4 del archivo "reto_3.pdf", no de la profesora)
Implementar una función:
                          void lexico_stack(int & n); 
que   dado   un   número   natural   n   imprime   todos   los   conjuntos   ordenados   de   (1, 2,..., n).
Sugerencia: Implementar el algoritmo descripto, llamando a una función auxiliar 
                         void imprime_pila(stack<int> &S) 
que imprime la pila S en forma no-destructiva.
Restricciones: Usar la STL para pilas. En lexico_stack(): usar una sola estructura auxiliar. En
imprime_pila(): usar una sola estructura auxiliar. No usar otros algoritmos de la STL.

20:00

ME RINDO
(He interpretado que tengo que sacar el conjunto partes de un conjunto 1...n con pilas, pero no lo consigo)
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
void lexico_stack(int n)
{
    stack<int> aux;
    
    for (size_t num_elementos = 1; num_elementos <= n; num_elementos++)
    {
        cout << "num_elementos: " << num_elementos << endl;
        for (size_t i = 1; i <= n; i++)
        {
            cout << "i: " << i << endl;
            aux.push(i);
            for (size_t k = 1; k <= num_elementos; k++){
                cout << "k: " << k << " i+k:" << (i+k) << endl;
                aux.push(i+k);
                imprime_pila(aux);
                aux.pop();
                cout << endl;
            }
            aux.pop();
        }
        while (!aux.empty())
            aux.pop();
    }
}

int main()
{
    lexico_stack(2);
    return 0;
}