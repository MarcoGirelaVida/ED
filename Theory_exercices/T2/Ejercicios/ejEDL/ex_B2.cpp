/*
Dada una cola de enteros implementar una función
void transformarcola(queue<int> & c);
    que transforme una cola c en otra en la que se eliminen aquellos valores (números) pares que
aparezcan   repetidos   y   de   manera   consecutiva   en   la   cola.   Se   permite   el   uso   de   colas   (queue)
auxiliares, si fuera necesario.
Ejemplo:
C=<1,2,2,3,3,4,5,5,1,1,9,8,8,8,3> pasaría a quedar como C=<1,2,3,3,4,5,5,1,1,9,8,3>

23:51
00:08
*/

#include <iostream>
#include <queue>
using namespace std;

void imprimir_cola(queue<int> &c)
{
    int c_size = c.size();
    for (size_t i = 0; i < c_size; i++)
    {
        cout << c.front() << ",";
        c.push(c.front());
        c.pop();
    }
}

void transformarcola(queue<int> & c)
{
    int c_size = c.size();
    int cache = c.front();
    c.push(c.front());
    c.pop();

    for (size_t i = 1; i < c_size; i++){
        if (c.front()%2 || (!(c.front()%2) && c.front() != cache)){
            cache = c.front();
            c.push(c.front());
        }
        c.pop();
    }
}

int main()
{
    queue<int> c;
    c.push(1);
    c.push(2);
    c.push(2);
    c.push(3);
    c.push(3);
    c.push(4);
    c.push(5);
    c.push(5);
    c.push(1);
    c.push(1);
    c.push(9);
    c.push(8);
    c.push(8);
    c.push(8);
    c.push(3);

    imprimir_cola(c);
    cout << endl;

    transformarcola(c);

    imprimir_cola(c);
    cout << endl;

    cout << "Expected values:" << endl;
    cout << "1,2,3,3,4,5,5,1,1,9,8,3" << endl;

    return 0;
}