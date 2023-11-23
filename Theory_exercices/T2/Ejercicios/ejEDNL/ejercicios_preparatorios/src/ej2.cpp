#include <iostream>
#include <set>
#include <map>
using namespace std;

void print_set(set<int> conjunto)
{
    for (auto it = conjunto.begin(); it!=conjunto.end(); it++)
        cout << *it << endl;
}

int main()
{
    set<int> s1a = {};
    set<int> s1b = {};
    cout << boolalpha << ": " << (s1a,s1b) << endl;
    
    set<int> s2a = {};
    set<int> s2b = {};
    cout << boolalpha << ": " << (s2a,s2b) << endl;
    
    set<int> s3a = {};
    set<int> s3b = {};
    cout << boolalpha << ": " << (s3a,s3b) << endl;
    
    set<int> s4a = {};
    set<int> s4b = {};
    cout << boolalpha << ": " << (s4a,s4b) << endl;
    
}