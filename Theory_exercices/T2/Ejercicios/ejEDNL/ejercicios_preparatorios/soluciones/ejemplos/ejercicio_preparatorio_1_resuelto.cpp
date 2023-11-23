/*
Dados dos sets construir la función
bool soncomplementarios(const set<int> & s1,const set<int> &s2)
que determine si dos conjuntos son complementarios. Diremos que dos conjuntos son complementarios si entre cada dos elementos del primer conjunto existe uno y solo uno en el segundo
Ej
s1={1,5,7} s2={2,6} --> devolveria true
s1={1,5,7} s2={2,3,6}-->devolveria false ya que 2,3 son mas de un elemento entre 1 y 5.
*/

#include <iostream>
#include <set>

using namespace std;

bool soncomplementarios(const set<int> & s1,const set<int> &s2){
    // s1 tiene que tener al menos dos elementos
    if (s1.size() < 2)
        return false;
    
    // Como entre cada pareja de elementos de s1 debe haber un único elemento de s2,
    // entonces s2 debe contener un elemento menos que s1
    if (s1.size()-1 != s2.size())
        return false;
        
    // Creo dos iteradores para s1: uno apunta a la primera posición y otro a la segunda
    auto it1_first = s1.begin();
    auto it1_second = ++s1.begin(); // Importante que el ++ vaya antes de s1.begin()
    
    // Voy iterando sobre ambos sets. En cada iteración avanzo los tres iteradores
    for (auto it2 = s2.begin(); it2 != s2.end(); it2++,it1_first++,it1_second++){
        // El elemento actual del set2 (*it2) tiene que estar entre los dos elementos correspondientes
        // del set1: *it_first e *it_second
        if ( !(*it2>*it1_first && *it2<*it1_second) )
            return false;
    }
    
    return true;
}

void print_set(set<int> conjunto){
    for (auto it = conjunto.begin(); it!=conjunto.end(); it++)
        cout << *it << endl;
}

int main(){
    set<int> s1a = {1,5,7};
    set<int> s1b = {2,6};
    cout << boolalpha << "Complementarios: " << soncomplementarios(s1a,s1b) << endl;
    
    set<int> s2a = {1,5,7};
    set<int> s2b = {2,3,6};
    cout << boolalpha << "Complementarios: " << soncomplementarios(s2a,s2b) << endl;
    
    set<int> s3a = {1,5,7};
    set<int> s3b = {2,4};
    cout << boolalpha << "Complementarios: " << soncomplementarios(s3a,s3b) << endl;
    
    set<int> s4a = {1,5,7};
    set<int> s4b = {6};
    cout << boolalpha << "Complementarios: " << soncomplementarios(s4a,s4b) << endl;
    
    set<int> s5a = {1,5,7,9,20,30};
    set<int> s5b = {2,6,8,15,29};
    cout << boolalpha << "Complementarios: " << soncomplementarios(s5a,s5b) << endl;
}