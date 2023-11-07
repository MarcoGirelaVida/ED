/*
find(clave): Devuelve un itertator al objeto encontrado o end (si no está)

*/
#include<map>
#include<string>
#include<iostream>
using namespace std;

class Usuarios
{
private:
    multimap<string,pair<string,string>> datos;

public:
    Usuarios();
    ~Usuarios();

    pair<iterator,bool> insert(const string &c, const string &up, const string &p);
};

Usuarios::Usuarios()
{
}

Usuarios::~Usuarios()
{
}


pair<Usuarios::iterator,bool> Usuarios::insert(const string &c, const string &ip, const string &p)
{
    Iterator it = datos.find(c);
    //SI no encuentra el correo
    if (it == datos.end())
    {
        pair<string, pair<string, string>> a(c, make_pair(ip,p));
        pair<Iterator, bool> b = datos.insert(a);
        Usuarios::iterator itu;
        itu.it=b.first;
        return pair<Usuarios::iterator, bool>(itu,true);
        
    }
    // Si no encuentra el correo pe
    else
    {
        bool enc = false;
        while (it != datos.end() && (*it).first == c && !enc)
        {
            if ((*it).second, (*it).first == ip)
            {
                enc == true;
            }
            else
                ++it;
            
        }
    }
}



// EJERCICIO EXAMEN
// Iterador que itere

class iterator
{
private:
    multimap<string,pair<string,sting>>::iterator it, final;

public:
    iterator();
    ~iterator();

    bool cond();
    iterator& operator++();
};

iterator::iterator()
{
}

iterator::~iterator()
{
}

bool cond(){
    Iterator itaux = it;
    int cnt;
    while (itaux != final && (*it).first==(*itaux).first)
    {
        int++;
        ++itaux;
    }

    if (cnt>2)
    {
        return true;
    }
    else
    {
        return false;
    }
}
iterator& operator++()
{
    do
    {
        ++it;
    } while (it!=final && cond());
    return *this;
}