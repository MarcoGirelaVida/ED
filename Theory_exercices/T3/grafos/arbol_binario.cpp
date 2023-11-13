/*

*/
#include <iostream>
#include <istream>
#include <queue>
using namespace std;

template <class T>
class ArbolBinario
{
    private: 
        struct info_nodo
        {
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
        };
        info_nodo<T> * getPadre (info_nodo<T> *n) {
            return n->padre;
        }
  
        info_nodo<T> * getHijoIzq(info_nodo<T> *n) {
            return n->hijoizq;
        }

        info_nodo<T> * getHijoDer(info_Nodo<T> *n) {
            return n->hijoder;
        }
        
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
        
        void Borrar(info_nodo<T>*n){
            if (n != nullptr)
            {
                BorrarInfo(n->hijoizq);
                BorrarInfo(n->hijoder);
                delete n;
            }
        }
        
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
    
        void InsertarHijoDerecha(info_nodo<T>*n, const T& e)
        {
            info_nodo<T>*aux = new info_nodo<T> (e);
            InsertarHijoDerecha(n, aux);
        }
      
        void PodarHijoIzquierda(info_nodo<T> *n)
        {
            if (n->hijoizq != nullptr)
            {
                BorrarInfo(n->hijoizq);
                n->hijoizq=nullptr;
            }
        }
        
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
       
        void RecorridoPreOrden(info_nodo<T> * n)
        {
            if (n != nullptr)
            {
                cout << n->etiqueta<<' ';
                RecorridoPreorden (n->hijoizq);
                RecorridoPreorden (n->hijoder);
            } 
        }
       
        void RecorridoInorden(info_nodo<T> * n)
        {
            if (n != nullptr)
            {
                RecorridoInorden(n->hijoizq);
                cout << n->etiqueta << ' ';
                RecorridoInorden(n->hijoder);
            }
        }
       
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
       
        int cuenta_nodos(info_nodos<T> * n)
        {
            if (n == nullptr)
                return 0;
            else
                return numero_nodos(n->hijoizq) + numero_nodos(n->hijoder) +1;
        }
       
        void leer(istream &is, info_nodo<T> * &n)
        {
            char c;
            c = is.get();
            if (c == 'n')
            {
                n = new info_nodo<T>;
                n->padre = n->hijoizq() = n->hijoder() = nullptr;
                is >> n->etiqueta;
                leer(n->hijoizq());
                leer(n->hijoder());

                if (n->hijoizq != nullptr)
                    n->hijoizq->padre = n;

                if (n->hijoder != nullptr)
                    n->hijoder->padre = n;
                else if (c == 'x')
                    n = nullptr;
                else
                    cout << "Error entrada no válida" << endl;
            }
        }

        info_nodo *raiz;
    
    public:
        
        // Aquí van todos los métodos de antes pero adaptados a la clase arbol binario
        // Básicamente llaman al método correspondiente de infonodo y hacen algun cambio

        class nodo
        {
        private:
            typedef typename arbolbinario<T>::nodo tipoNodo;
            
        public:
            nodo();
        };
        
        // Es como un iterator sin operator ++

        class preorden_iterator
        {
        private:
            
        public:
            preorden_iterator();
            preorden_iterator begin_preorden();
            preorden_iterator end_preorden();
            operator++();
        };

        // lo mismo con las clases postorden inorden
};
