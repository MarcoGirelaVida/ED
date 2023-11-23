/*
Dado un conjunto de palabras obtener un mapa donde  la clave sea  la palabra del set y la 
información asociada el número de vocales que tiene la palabra. La función sería la siguiente 
 
map<string,int> getNumVocales(const set<string>&s) 
Ej 
S={ aguila, alondra, buho,buitre canario, gavilan, gaviota, halcon} 
M={<aguila,4>,<alondra,3>,<buho;2>,<buitre;3>,<canario,4>,<gavilan,3>,<gaviota,4>,<halc
on,2>}
*/
#include <iostream>
#include <set>
#include <map>
#include <string>
using namespace std;

void print_set(set<string> conjunto)
{
    for (auto it = conjunto.begin(); it!=conjunto.end(); it++)
        cout << *it << endl;
}

void print_map(map<string, int> conjunto)
{
    for (auto it = conjunto.begin(); it!=conjunto.end(); it++)
        cout << it->first << " ," << it->second << endl;
}
unsigned numVocales(const string & palabra)
{
    unsigned num_vocales = 0;
    set<char> set_vocales = {'a', 'e', 'i', 'o', 'u'};

    for (size_t i = 0; i < palabra.size(); i++)
        if (set_vocales.count(palabra[i]))
            num_vocales++;
    
    return num_vocales;
}

map<string,int> getNumVocales(const set<string>&set_palabras) 
{
    map<string, int> output;

    
    for (const auto &elemento_set : set_palabras)
        output[elemento_set] = numVocales(elemento_set);
    
    
    /*
    for (auto it = set_palabras.cbegin(); it != set_palabras.cend(); ++it)
        output[*it] = numVocales(*it);
    */

    return output;
}

int main()
{
    const set<string> S= {"aguila", "alondra", "buho", "buitre", "canario", "gavilan", "gaviota", "halcon"};
    map<string, int> m = getNumVocales(S);

    cout << "Num vocales hola: " << numVocales("Hola") << endl;

    print_map(m);
    
}