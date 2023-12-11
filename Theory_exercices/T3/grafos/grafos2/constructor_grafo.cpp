template<class T>
set<info_link<T>> Graph<T>::getConexiones(const T & v){
    auto it = datos.find(v);

    if (it != datos.end())
    {
        return it -> second;
    }
    else
        return set<info_link<T>>()
}


void Graph<T>::addEdge(const T & v1, const T & v2, unsigned int w){
    info_lin<T> a = {v2, w};

    auto it = datos.find(v1);
    if (it != datos.end())
    {
        auto it2 = it->second.find(a);

        if (it2 == it->second.end())
        {
            it->second.insert(a);
        }
    }
    else
    {
        set<info_link<T>>s1;
        S1.insert(a);
        datos.emplace(v1, v2);
        it = datos.find(v2);
        if (it == datos.end())
        {
            datos.emplace(v2, set<info_link<T>());
        }
    }
}

void Graph<T>::eraseVertice( const T & v){
    for (auto it = 0; it < datos.end(); ++it)
    {
        auto its = it->second.begin();
        bool enc = false;
        while (its != it->second.end() && !end)
        {
            if (its->vert == v) 
            {
                its = it->second->erase(its);
            }
            else
                ++its;
        }
    }
    auto it = datos.fmd(v);
    if (datos.end() != it)
    {
        datos.erase(it);
    }
}

unsigned int Graph<T>::degree_output(const T & v)
{
    auto it = datos.find(v);

    if (datos.end() != it)
    {
        return it->second.size();
    }
    else
        return 0;
    
}

void Graph<T>::degreen_input( const T & v){
    int cnt = 0;
    for (auto it = 0; it < datos.end(); ++it)
    {
        auto its = it->second.begin();
        bool enc = false;
        while (its != it->second.end() && !end)
        {
            if (its->vert == v) 
            {
                its = it->second->erase(its);
            }
            else
                ++its;
        }
    }
    auto it = datos.fmd(v);
    if (datos.end() != it)
    {
        datos.erase(it);
    }
}

unsigned int ** Graph<T>::GetAdjacencia()const{
    int n = datos.size();

    unsigned int ** m = new unsigned * int[n];
    for (size_t i = 0; i < n; i++)
    {
        m[i] = new unsigned int [n];
        for (size_t j = 0; j < n; j++)
        {
            m[i][j] = 0;
        }
    }
    
    map<T, unsigned int> aux;
    int pos = 0;

    for (auto it = datos.begin(); it != datos.end(); ++it)
    {
        aux[it->first] = pos;
        pos++;
    }
}

class iterator {
    typename map<T, set<info_link<T>>>::iterator map, map_final;
    typename set<info_link<T>>::iterator set;

    public:
        iterator(){}
        bool operator==(const iterator & it) const{
            if ((final == it.map_final) || (it.map == it && it.set == this))
            {
                
            }   
        }
};

iterator begin();
iterator end();