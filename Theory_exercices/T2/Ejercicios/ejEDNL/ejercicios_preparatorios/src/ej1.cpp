#include <iostream>
#include <set>
using namespace std;

bool soncomplementarios(const set<int> & s1,const set<int> &s2)
{
    bool lo_son = s1.size() == (s2.size() + 1);

    for (auto it_s1 = s1.cbegin(), it_s2 = s2.cbegin(); lo_son && it_s1 != (--s1.cend()); ++it_s2)
        if (*it_s1 > *it_s2 || *(++it_s1) < *it_s2)
            lo_son = false;
    
    return lo_son;
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