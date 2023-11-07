#include <string>
#include <queue>
#include <vector>
#include <iostream>

using namespace std;

struct fruta{
    string f;
    float precio;

    fruta (string & name, float p): f(name), precio(p){}

    bool operator<(const fruta & f){
        return (this->precio < f.precio);
    }

    friend ostream& operator<<(ostream &os, const fruta &f){
        os << f.f << " " << f.precio << endl;
        return os;
    }

    vector <fruta> ordena_frutas( const vector<fruta>& fs){
        priority_queue<fruta> q;

        for (int i = 0; i < fs.size(); i++)
        {
            q.push(fs[i]);
        }

        vector<fruta> v_out;

        while (!q.empty())
        {
            v_out.push_back(q.top());
            q.pop();
        }
        
        return v_out;
    }

};