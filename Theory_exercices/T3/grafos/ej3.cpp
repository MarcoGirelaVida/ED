#include <arbol_binario.cpp>

void Refleja (ArbolBinario<int>&ab, ArbolBinario<int>::nodo n)
{
    if (!n.null())
    {
        ArbolBinario<int> aizq = ab.PodarHijoIzquierda(n);
        ArbolBinario<int> ader = ab.PodarHijoDerecha(n);
        ab.InsertarHijoIzq(n, ader);
        ab.InsertarHijoDerecha(n, aizq);

        Refleja(ab, n.hizq());
        Refleja(ab, n.hder());
    }
}