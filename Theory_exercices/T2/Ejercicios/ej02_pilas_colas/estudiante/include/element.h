#include <iostream>
using namespace std;

struct element { 
    int value; // Current value to store 
    int maximum; // Current max value in the structure 

    element(int v){ value = v; maximum = v;}
    friend ostream& operator<<(ostream &os, const element &e){  os << e.value << "," << e.maximum; return os; }
};
