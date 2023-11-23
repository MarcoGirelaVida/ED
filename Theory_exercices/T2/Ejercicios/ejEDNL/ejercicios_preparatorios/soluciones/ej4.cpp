/*Dado un multiset de enteros obtener un mapa con clave el entero en el multiset y con información asociada el número de veces que aparece. La función sería:
map<int,int> getFrecuencia(const multiset<int> &ms)
Ej
Ms={1,1,1,1,3,3,3,2,2,6,6,6}
Map={<1,4>,<3,3>,<2,2>,<6,3>}
*/
#include <iostream>
#include <set>
#include <map>
using namespace std;

map<int,int> getFrecuencia(const multiset<int> &ms){
    map<int,int> out; //salida

    typedef multiset<int>::const_iterator iteratorMs;

    pair<iteratorMs,iteratorMs> ret;
    iteratorMs it=ms.cbegin();
    while (it!=ms.cend()){
        ret =ms.equal_range(*it);//par de iteradores a la primera aparicion de *it y el segundo iterador donde termina
                                 // la aparición de *it

        int cnt=0;
        //contabilizamos cuantas veces aparece *it
        for (auto it2=ret.first;it2!=ret.second;++it2)
            cnt++;
        out.emplace(*it,cnt);
        //avanzamos al iterador hasta que sea diferente al valor *it
        it = ret.second;

    }
    return out;
}
int main(){
 multiset<int> MS({1,1,1,1,3,3,3,2,2,6,6,6}); // en el multiset se colocaran ordenados

 map<int,int> mimap=getFrecuencia(MS);
 for (auto it=mimap.begin();it!=mimap.end();++it)
    cout<<it->first<<" "<<it->second<<endl;

}
