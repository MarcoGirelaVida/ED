#include <queue>
#include <string>
#include <iostream>
using namespace std;

typedef pair<int , string> mipair;

ostream& operator<<(ostream&os, const pair<int, string>&p){
    cout << p.first << ' ' << p.second << endl;
    return os;
}

int main(){


    queue<mipair> micola, otra;

    micola.push(make_pair(1, "Naranja"));
    micola.emplace(2, "Platano");

    cout << micola.front() << "" << micola.back() << micola.size();

    otra = micola;

    while (!otra.empty())
    {
        cout << otra.front();
        otra.pop();
    }
    
    micola.swap(otra);
}


int ejemplodepairs(){
    pair<float, string> a,b;

    a.first = 5.3;
    a.second = "Platano";

    b = a;
    b = make_pair(7.2, "Melón");

}