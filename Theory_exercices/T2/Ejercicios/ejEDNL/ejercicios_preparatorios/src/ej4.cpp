#include <iostream>
#include <set>
#include <map>
using namespace std;

void print_set(set<int> conjunto)
{
    for (auto it = conjunto.begin(); it!=conjunto.end(); it++)
        cout << *it << endl;
}

map<int,int> getFrecuencia(const multiset<int> &ms)
{
    map<int, int> output;
    auto it_set = ms.cbegin();

    while (it_set != ms.cend())
    {
        output[*it_set] = ms.count(*it_set);
        it_set = ms.upper_bound(*it_set);
    }
    
    return output;
}


int main(){
 multiset<int> MS({1,1,1,1,3,3,3,2,2,6,6,6}); // en el multiset se colocaran ordenados

 map<int,int> mimap=getFrecuencia(MS);
 for (auto it=mimap.begin();it!=mimap.end();++it)
    cout<<it->first<<" "<<it->second<<endl;

}
