#include <arbol_binario>
// Este ejercicio es solo si nos dejan usar los iteradores de arbol binario

bool inorden_postorden_iguales(ArbolBinario<int> & ab)
{
    ArboBinario<int>::preorden_it it_pre;
    ArbolBinario<int>::inorder_iterator it_in;

    for (it_pre = ab.begin_preorden(),  it_in = ab.begin_inorden(); it_pre != ab.end_preorden(); ++it_pre, ++ it_in)
        if (*it_pre != *it_in)
            return false;
    
    return true;
}