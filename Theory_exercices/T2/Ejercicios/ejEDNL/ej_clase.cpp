/*
size()
empty()
erase(clave)
clear() (vaciar)
insert(clave) (lo inserta donde quiera)
find(clave) (devuelve el iterador donde está el elemento)
count(clave) (básicamente es como un método existe, ya que devuelve 1 si está y 0 si no)
*/
#include <iostream>
#include <set>
#include <vector>
using namespace std;
// Para recorrer sobre un set
/*
for (auto it = conjunto.begin(); it != conjunto.end(); it++)
{
    cout << (*it) << " " << endl;
}
*/

bool soncomplementarios(const set<int> & s1, const set<int> &s2)
{
    bool loson = (s1.size() == s2.size() + 1) || (s1.size() < 2);
    pair<int,int> mayor_menor;

    auto it1_first = s1.cbegin();
    auto it1_second = ++s1.cbegin();

    for (auto it2 = s2.cbegin(); it2 != s1.cend(); ++it2, ++it1_first, ++it1_second)
    {
        if ((*it1_first) <= (*it2) || (*it1_second) <= (*it2))
        {
            loson = false;
        }
    }

    return loson;
}
int main()
{

}