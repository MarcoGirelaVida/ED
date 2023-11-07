#include <list>

using namespace std;

template<class T>
void borrar_pares(list<T> & L){

    // Hay que poner typename porque sino el compilador se cree 
    typename list<T>::iterator it = L.begin();

    while (it != L.end())
    {
        if (!((*it) % 2))
            it = L.erase(it);
        else
            ++it;
    }
}