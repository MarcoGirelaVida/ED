#include<list>
#include<string>
using namespace std;

class Notas{
    private:
        list<pair<string,float>> datos;

    public:
        Notas(){}

        int size() const{ return datos.size(); }

        class iterator{
            private:
                list<pair<string,float>>::iterator it;
            public:
                iterator(){}
                bool operator == (const iterator &i){ return it == i.it; }
                bool operator != (const iterator &i){ return it != i.it; }
                iterator& operator++(){
                    ++it;
                    return *this;
                }
                iterator& operator--(){
                    --it;
                    return *this;
                }
        friend class Notas;
        };
        
        class const_iterator{
            private:
                list<pair<string,float>>::const_iterator it;
            public:
                const_iterator(){}
                bool operator == (const const_iterator &i) const{ return it == i.it; }
                bool operator != (const const_iterator &i) const{ return it != i.it; }
                const_iterator& operator++() {
                    ++it;
                    return *this;
                }
                const_iterator& operator--() {
                    --it;
                    return *this;
                }

        friend class Notas;
        };

        void insert(iterator i, pair<string, float> n){
            datos.insert(i.it, n);
        }

        void erase(iterator i){
            datos.erase(i.it);
            i.it--;
        }

        iterator begin(){
            iterator i;
            i.it = datos.begin();
            return i;
        }

        const_iterator begin() const{
            const_iterator i;
            i.it = datos.cbegin();
            return i;
        }

        iterator end(){
            iterator i;
            i.it = datos.end();
            return i;
        }

        const_iterator end() const{
            const_iterator i;
            i.it = datos.cend();
            return i;
        }

        list<pair<int, int>> CambiarNotas(const Notas & N){
            list<pair<int,int>> output;
            Notas::const_iterator it;
            for (it = N.begin(); it != N.end(); ++it)
            {
                int nal = (*it.).second;
            }
            
        }
};



// LA CLASE ITERATOR SIEMPRE CAE