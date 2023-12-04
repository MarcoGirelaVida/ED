template <class T>

info_nodo<T> * CrearRaiz (const T &e)
{
    info_nodo<T> * n = new info_nodo<T>(e);
    return n;
}

template <class T>
void Copiar (info_nodo<T>*s, info_nodo<T>*&d){
    if (s == nullptr)
        d = nullptr;
    else{
        d = new info_nodo<T>(s->T);
        Copiar(s->hijoizq, d->hijoizq);
        Copiar(s->hermanodcha, d->hermanodcha);
        if (s->hermanodcha != nullptr)
        {
            d->hijoizq->padre = d;
            ifno_nodo<T>*aux = d->hijoizq->hermanodch;

            while (aux != nullptr)
            {
                aux->padre = d;
                aux = aux->hermanodch
            }
            
        }
        
    }
}


void Borrar (info_nodo <T>*s)
{
    if (s != nullptr)
    {
        Borrar(s->hijoizq);
        Borrar(s->hermanodcha);
        delete s;
    }
}


void Insertar HermanoDcha(info_nodo<T> * n, info_nodo<T>*&T2)
{
    if (T2 != nullptr){
        T2->hermanodch = n->hermanodcha;
        n->hermanodcha = T2;
        T2->padre = n->padre;
        T2 = nullptr;
    }
}

info_nodo<t>* PodarHijoIzq(info_nodo<T> * n){
    info_nodo<T> * res = nullptr;
    if (n->hijoizq != nullptr)
    {
        res = n->hijoizq;
        n->
    }   
}

info_nodo<T> * PodarHermanoDrcha(info_nodo<T> * n){
    info_nodo<T> * res = nullptr;
    if (n->hermanodecha != nullptr)
    {
        res = n->hermanodcha;
        n->hermanodcha = res->hermanodch;
        res->padre = nullptr;
        res->hermanodch = nullptr;
    }
    
    return res;
}


int Altura(info_nodo<T> * n){
    if (n == nullptr)
    {
        return -1;
    }
    else
    {
        int max = -1;
        for (info_nodo<T>*aux = n->hijoizq; aux != nullptr; aux = aux->hermanodcha){
            int v = Altura(aux);
            if (max < v)
            {
                max = v;
            }
            
        }
    }
}