/*Dados dos set construir la función
bool soncomplementarios(const set<int> & s1,const set<int> &s2)
que determine si dos conjuntos son complementarios. Diremos que dos conjuntos son complementarios si entre dos elementos del primer conjunto existe uno y solo uno en el segundo
Ej
s1={1,5,7} s2={2,6} --> devolveria true
s1={1,5,7} s2={2,3,6}-->devolveria false ya que 2,3 son mas de un elemento entre 1 y 5. Además de que 6 no se podría poner entre 2 valores de s1.
*/
#include <iostream>
#include <set>
using namespace std;
bool soncomplementarios(const set<int> & s1,const set<int> &s2){
    if (s2.size()!=s1.size()-1) return false;

    set<int>::const_iterator it1,it2,it_sig,final;
    it1=s1.cbegin();
    it2=s2.cbegin();
    final = s1.cend(); --final;
    while (it1!=final){
       it_sig = it1; ++it_sig;
       if (!(*it1<=*it2 && *it2<*it_sig)) return false;
       ++it1;
       ++it2;

    }
    return true;



}
int main(){
    set<int> c1({1,5,7}), c2({2,6}),c3({2,3});
    if (soncomplementarios(c1,c3))
            cout<<" Son complmentarios" <<endl;
    else
            cout<<"No son complmentarios" <<endl;


}
