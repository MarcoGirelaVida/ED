/*
Dada una cola de enteros y una lista diremos que son isomórficas si contienen los 
mismo elementos en las posiciones pares. Construir la siguiente función 
bool isomorficas (queue<int> & C, list<int> & L); 
Ejemplo: (La primera posición es la 1) 
C= {1,5,7,9,8,4} y  L={9,5,3,9,10,4} devolvería True 
    ^ 
    front 
C= {1,5,7,9,8,1} y  L={9,5,3,9,10,4} devolvería False 
    ^ 
    Front
*/

#include <iostream>
#include <queue>
#include <list>
using namespace std;

bool isomorficas (queue<int> & C, const list<int> & L)
{
    bool areEqual = C.size() == L.size();

    if (!(C.size() % 2) && areEqual)
        C.pop();
    
    for (list<int>::const_iterator it = (L.size() % 2) ? L.cbegin() : next(L.cbegin()); areEqual && it != L.cend(); ++it)
    {
        cout << " It:" << *it << " c.front:" << C.front() << endl;
        if ((*it) != C.front())
            areEqual = false;

        if (it != prev(L.cend()))
        {
            ++it;
            C.pop();
        }
    
        C.pop();
    }
    
    return areEqual;
}


int main()
{
    list<int> L = {9,5,3,9,10,4};
    queue<int> C1;
    queue<int> C2;

    C1.push(1);
    C1.push(5);
    C1.push(7);
    C1.push(9);
    C1.push(8);

    C2 = C1;
    C1.push(4);
    C2.push(1);

    cout << (isomorficas(C1, L) ? "true" : "false") << endl;
    cout << (isomorficas(C2, L) ? "true" : "false") << endl;

    return 0;
}