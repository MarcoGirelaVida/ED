#include <arbol_binario.cpp>

int main()
{
    ArbolBinario<char> ab('a');
    ArbolBinario<char>::nodo n = ab.getraiz();
    ab.Insertar_hi(n, 'b');
    ab.Insertar_hd(n, 'c');

    n = n.hizq();
    ab.Insertar_hi(n, 'd');
    ab.Insertar_hd(n, 'e');

    n = ab.getraiz().hijod();   // n = n.padre().hder();
    ab.Insertar_hi(n, 'f');
    ab.Insertar_hd(n, 'g');
}