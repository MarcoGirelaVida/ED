/*Dado un multimap con clave un string y con información asociada un entero obtener un mapa con clave el string e información asociada una lista con los enteros asociados al string. La función sería:
map<string,list<int> > getMapa(const multimap<string,int> &multim)
Ej
Multim={<ahora,1>,<ahora,3>,<ahora,4>,<aunque,3>,<aunque,5>,<banco,2>,<banco,10>,<zanahoria,1>,<zanahoria,2>}
Map = {<ahora,{1,3,4}>,<aunque,{3,5}>,<banco,{2,10}>,<zanahoria,{1,2}>}*/
#include <iostream>
#include <map>
#include <list>
using namespace std;

map<string,list<int> > getMapa(const multimap<string,int> &multim){
     pair<multimap<string,int>::const_iterator,multimap<string,int>::const_iterator> ret;
     multimap<string,int>::const_iterator it=multim.cbegin();
     map<string,list<int> >out;

     while (it!=multim.cend()){
        ret = multim.equal_range(it->first); //(*it).first
        list<int> l;
        for (auto it2=ret.first;it2!=ret.second;++it2)
            l.push_back(it2->second); //(*it2).second

        out.emplace(it->first,l);
        it=ret.second;

     }
     return out;

}

int main(){
  multimap<string, int> mim({{"ahora",1},{"ahora",3},{"ahora",4},{"aunque",3},
                            {"aunque",5},{"banco",2},{"banco",10},
                            {"zanahoria",1},{"zanahoria",2}});
  map<string,list<int> > mimap=getMapa(mim);

  map<string,list<int> >::iterator it;
  for (it=mimap.begin(); it!=mimap.end();++it){
    cout<<"Clave: "<<it->first<<" "<< "Lista asoc. :";
    for (auto it_l = it->second.begin(); it_l!=it->second.end();++it_l)
        cout<<*it_l<<" ";
    cout<<endl;
   }
}



