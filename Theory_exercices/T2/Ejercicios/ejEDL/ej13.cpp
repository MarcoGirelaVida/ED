/*
13. Implementar una función:
  stack<int> mergeSortedStacks(stack<int> A, stack<int> B);
que dadas 2 pilas ordenadas (el mínimo valor está en el tope) devuelva una pila
ordenada (el mínimo en el tope) que contenga todos los elementos de A y B. No
pueden usarse estructuras auxiliares salvo pilas.
18:53
19:12
*/

#include <iostream>
#include <stack>
using namespace std;

stack<int> mergeSortedStacks(stack<int> A, stack<int> B)
{
    stack<int> output;
    int next_element;

    while (!A.empty() && !B.empty())
    {
        if (A.top() < B.top())
        {
            next_element = A.top();
            A.pop();
        }
        else
        {
            next_element = B.top();
            B.pop();
        }
        
        output.push(next_element);
    }
    
    while (!A.empty()){
        output.push(A.top());
        A.pop();
    }
    while (!B.empty())
    {
        output.push(B.top());
        B.pop();
    }
    
    return output;
}


int main()
{
    stack<int> A;
    stack<int> B;
    A.push(8);
    A.push(5);
    A.push(3);
    A.push(2);
    A.push(1);
    A.push(0);

    B.push(10);
    B.push(9);
    B.push(7);
    B.push(6);
    B.push(4);
    B.push(3);
    B.push(2);

    stack<int> output = mergeSortedStacks(A,B);
    while (!output.empty())
    {
        cout << output.top() << " ,";
        output.pop();
    }
    cout << endl;

    cout << "Expected output:\n10, 9, 8, 7, 6, 5, 4, 3, 3, 2, 2, 1, 0" << endl;

    return 0;
}