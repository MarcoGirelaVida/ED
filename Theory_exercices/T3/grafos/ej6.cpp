#include <arbol_binario.cpp>

bool sonReflejados (ArbolBinario<int>&ab1, ArbolBinario<int>&ab2)
{
    return sonReflejadosN(a1.getraiz(), a2.getraiz());
}

bool sonReflejadosN(ArbolBinario<int>::nodo n1, ArbolBinario<int>::nodo n2)
{
    if (n1.null() && n2.null())
        return true;
    else if (n1.null() || n2.null())
        return false;
    else if (*n1 != *n2)
        return false;
    else
        return sonReflejadosN(n1.hijoz(), n2.hder()) && sonReflejadosN(n1.hder(), n2.hizq());
}

// Si te fijas es igula que la función sonIguales solo que al comparar comparas hijoder con hijoizq en vez de hijoder con hijoder