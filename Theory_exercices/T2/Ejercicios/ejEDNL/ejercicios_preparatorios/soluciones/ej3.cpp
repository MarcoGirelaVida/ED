/*Dado un conjunto de palabras obtener un mapa donde la clave sea la palabra del set y la información asociada el número de vocales que tiene la palabra. La función sería la siguiente
map<string,int> getNumVocales(const set<string>&s)
Ej
S={ aguila, alondra, buho,buitre canario, gavilan, gaviota, halcon}
M={<aguila,4>,<alondra,3>,<buho;2>,<buitre;3>,<canario,4>,<gavilan,3>,<gaviota,4>,<halcon,2>}*/
#include <iostream>
#include <map>
#include <set>
using namespace std;

int cuantasvocales(const string & s){
  set<char> vocales({'a','e','i','o','u'});
  int cnt=0;
  for (int i=0;i<s.size();i++){
    if (vocales.find(s[i])!=vocales.end()) cnt++;

  }
  return cnt;


}

map<string,int> getNumVocales(const set<string>&s){

    map<string,int> out;
    set<string>::const_iterator it;
    for (it=s.cbegin(); it!=s.cend();++it){
        int nv = cuantasvocales(*it);
        out.emplace(*it,nv); //out.insert(make_pair(*it,nv))

    }
    return out;

}

int main(){

    set<string> mis({"aguila", "alondra", "buho","buitre", "canario",
                    "gavilan", "gaviota", "halcon"});

    map<string ,int> mim=getNumVocales(mis);

    for (auto it = mim.begin();it!=mim.end();++it)
        cout<<it->first<<" "<<it->second<<endl;



}
