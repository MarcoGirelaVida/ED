#include <arbol_binario.cpp>

bool all_pares(ArbolBinario<int> &ab)
{
    return all_pares_n(ab.getraiz());
}

bool all_pares_n(ArbolBinario<int>::nodo n)
{
    if (n.null())
        return true;
    else
    {
        if ((*n)%2 != 0)
            return false;
        else
            return all_pares_n(n.hizq()) && all_pares_n(n.hder());
    }
    
}