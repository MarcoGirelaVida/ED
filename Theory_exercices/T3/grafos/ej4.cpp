#include <arbol_binario.cpp>
#include <queue>
#include <list>
using namespace std;

list<int> & suma_niveles(ArbolBinario<int> &ab)
{
    queue<pair<ArbolBinario<int>::nodo, int>> micola;
    micola.emplace(ab.getraiz(), 0);
    int suma = 0;
    int current_level = 0;
    list<int> output;

    while (!micola.empty())
    {
        pair<ArbolBinario<int>::nodo, int> p = micola.front();
        micola.pop();
        if (p.second = current_level)
            suma += *(p.first);
        else {
            output.push_back(suma);
            current_level = p.second;
            suma = *(p.first);
        }
        
        if (!p.first.hijoizq().null())
            micola.emplace(p.first.hijoizq(), p.second + 1);
        if (!p.first.hder().null())
            micola.emplace(p.first.hder(), p.second + 1);
    }
    
}