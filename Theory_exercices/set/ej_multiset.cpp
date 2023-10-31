#include<iostream>
#include<set>
#include<list>
#include<vector>
using namespace std;

vector<int> v = {1,0,9,10,1,2,9,0,0,1};
list<pair<int,int>> l = {(0,3),(1,3),(2,1),(9,2),(10,1)};

list<pair<int,int>> getValue_Freq(const vector<int> &v){
    multiset<int> m(v.cbegin(), v.cend());
    list<pair<int,int>> out;
    multiset<int>::iterator it = m.begin();
    while (it != m.end())
    {
        /*
        int cnt = m.count(*it);
        int v = *it;
        it = m.upper_bound(*it);
        out.emplace(out.end(), v, cnt);
        */
        /*
        int aux = *it;
        int cnt = 0;
        auto it2 = m.upper.bound(*it);
        while(it != it2){
            ++it;
            ++cnt;
        }
        out.emplace(out.end(), aux, cnt)
        */
        
        int aux = *it;
        pair<multiset<int>::iterator, multiset<int>::iterator> ret = m.equal_range(*it);
        int cnt = 0;
        while (it != ret.second)
        {
            cnt++;
            ++it;
        }
        out.emplace(out.end(), aux, cnt);
    }

    return out;
}