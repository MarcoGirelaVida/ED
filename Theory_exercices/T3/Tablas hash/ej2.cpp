class Contenedor{
    private:

    public:
        class iterator{
            private:
                bool cond(bintree<int>::nodo n);
                typename unordered_map<T, U>::iterator it, final;

            public:
                iterator(){}
                bool operator==(const iterator&i) const{
                    return it==i.it;
                }

                bool operator!=(const iterator&i)const{
                    return it != i_it;
                }

                pair<const T, bintree<int>> & operator*(){
                    return *it;
                }

                iterator & operator++(){
                    do
                    {
                        ++it;
                    } while (it != final && !cond((*it).second.getraiz()));

                    return *this;
                }
                friend class contenerdor;
        }

        iterator begin(){
            iterator i;
            i.it = datos.begin();
            i.final = datos.end();
            if (i.it != i.final && !cond(i.second.getraiz()))
                ++it;
            return i;
        }
}