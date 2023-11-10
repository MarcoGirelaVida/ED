/*

*/
#include <iostream>
#include <queue>
using namespace std;
template <class T>
struct info_nodo{
    T et;
    info_nodo * padre;
    info_nodo * hijoizq;
    info_nodo * hijoder;
    info_nodo(){
        padre = 0;
        hijoizq = hijoder = 0;
    }

    info_nodo(const T &e){
        et = e;
        padre = 0;
        hijoizq = hijoder = 0;
    }


    template<class T>
    info_nodo<T> * getPadre (info_nodo<T> *n) {
        return n->padre;
    }

    template<class T>
    info_nodo<T> * getHijoIzq(info_nodo<T> *n) {
        return n->hijoizq;
    }

    template<class T>
    info_nodo<T> * getHijoDer(info_Nodo<T> *n) {
        return n->hijoder;
    }
};

template<class T>
void Copiar (const info_nodo<T> *s, info_nodo<T> *&d) {
    if (s == nullptr)
        d == nullptr;
    else{
        d = new info_nodo<T> (s->et);       // Aplicamos recursividad
        Copiar (s->hijoizq, d->hijoizq);
        Copiar (s->hijoder, d->hijoder);
        if (d->hijoizq != nullptr)
            d->hijoizq->padre = d;  
        if (d->hijoder != nullptr)
            d->hijoder->padre = d;
    }
}

template<class T>
void Borrar(info_nodo<T>*n){
    if (n != nullptr)
    {
        BorrarInfo(n->hijoizq);
        BorrarInfo(n->hijoder);
        delete n;
    }
}

template<class T>
void InsertarHijoDerecha(info_nodo<T>*n, info_nodo<T>*sub){
    info_nodo<T>*aux = n->hijoder;
    if (sub != nullptr){
        n->hijoder = sub;
        sub->padre = n;
    }
    else
        n->hijoder= nullptr;

    BorrarInfo(aux);
}

template<class T>
void InsertarHijoIzq(info_nodo<T>*n, info_nodo<T>*sub){
    info_nodo<T>*aux = n->hijoizq;
    if (sub != nullptr){
        n->hijoizq = sub;
        sub->padre = n;
    }
    else
        n->hijoizq= nullptr;

    BorrarInfo(aux);
}

template<class T>
void InsertarHijoDerecha(info_nodo<T>*n, const T& e)
{
    info_nodo<T>*aux = new info_nodo<T> (e);
    InsertarHijoDerecha(n, aux);
}

template<class T>
void PodarHijoIzquierda(info_nodo<T> *n)
{
    if (n->hijoizq != nullptr)
    {
        BorrarInfo(n->hijoizq);
        n->hijoizq=nullptr;
    }
}

template<class T>
void PodarHijoIzquierdaGetSubtree(info_nodo<T> *n)
{
    info_nodo <T> * aux = n->hijoizq;
    n->hijoizq = nullptr;
    if (auv != nullptr)
    {
        aux->padre=nullptr;
    }

    return aux;
}

template<class T>
void RecorridoPreOrden(info_nodo<T> * n)
{
    if (n != nullptr)
    {
        cout << n->etiqueta<<' ';
        RecorridoPreorden (n->hijoizq);
        RecorridoPreorden (n->hijoder);
    } 
}

template<class T>
void RecorridoInorden(info_nodo<T> * n)
{
    if (n != nullptr)
    {
        RecorridoInorden(n->hijoizq);
        cout << n->etiqueta << ' ';
        RecorridoInorden(n->hijoder);
    }
}

template<class T>
void RecorridoPostorden(info_nodo<T> * n)
{
    if (n != nullptr)
    {
        RecorridoInorden(n->hijoizq);
        RecorridoInorden(n->hijoder);
        cout << n->etiqueta << ' ';
    }
}
// TRUCO: Postorden, el cout va al final, inorden en medio, preorden al principio

// Ejercicio ejemplo que requiera recorrido por niveles: Calcular la suma de cada nivel
// Una opción sería añadir un parámetro en infonodo que nos diga el nivel
template<class T>
void RecorridoNiveles (info_nodo<T> * n)
{
    queue<info_nodo<T>> micola;
    micola.push(n);
    while (!micola.empty())
    {
        info_nodo<T> * aux = micola.front();
        micola.pop();
        cout << aux->etiqueta << ' ';
        if (aux->hijoizq != nullptr)
            micola.push(aux->hijoizq);
        
        if (aux->hijoder != nullptr)
            micola.push(aux->hijoder);
    }

    recorrido.pop();
}

template<class T>
bool iguales(info_nodo<T>*n1, info_nodo<T> *n2) {
    if (n1 == nullptr && n2 == nullptr) 
        return true;

    if (n1==nullptr || n2==nullptr)
        return false;
    
    if (n1->etiqueta != n2->etiqueta)
        return false;
    else
        return iguales(n1->hijoizq, n2->hijoizq) && iguales(n1->hijoder, n2->hijoder);
}

template<class T>
int cuenta_nodos(info_nodos<T> * n)
{
    if (n == nullptr)
        return 0;
    else
        return numero_nodos(n->hijoizq) + numero_nodos(n->hijoder) +1;
}