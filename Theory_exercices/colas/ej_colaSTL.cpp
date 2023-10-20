#include <queue>
#include <stack>
#include <string>
using namespace std;

typedef pair<string, int> mipair;

queue<mipair> FiltraPerYear(const queue<mipair> & q,int th_year){
    queue<mipair> c_out, aux(q);
    stack <mipair> p;

    while (!aux.empty())
    {
        if (aux.front().second >= th_year)  
        {
            p.push(aux.front());
        }
        aux.pop();
    }

    while (!p.empty())
    {
        c_out.push(p.top());
        p.pop();
    }
    
    return c_out;
}
