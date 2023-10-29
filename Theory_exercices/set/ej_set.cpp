/*
SET
- No puede tener elmentos repetidos (multiset si)
- Se ordena automáticamente, siempre está ordenado
*/

#include <iostream>
#include <set>
#include <list>
#include <queue>
using namespace std;

set<set<int>> ql = {{1,2}, {3,4}, {1574}};
set<int> output = {1,2,3,4,5,6,7};


set<int> operator+(const set<int>&s1, const set<int>&s2){
    set<int> output(s1);
    set<int>::const_iterator it2;
    for (it2 = s2.begin(); it2 != s2.cend(); ++it2)
    {
        // Realmente el if es prescindible porque insert si ya está no lo mete
        if (output.find(*it2) == output.end())
            output.insert(*it2);
        
    }
    return output;
}

set<int> uneSet(queue<set<int>>&q){
    set<int> out;
    while (!q.empty())
    {
        set<int> aux = q.front();
        q.pop();
        out = out + aux;
    }
    return out;
}