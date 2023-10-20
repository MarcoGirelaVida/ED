#include <list>

using namespace std;

list<int> operator+(const list<int>&L1, const list<int>&L2)
{
    list<int>output(L1);

    for (auto it2 = L2.cbegin(); it2 != L2.cend(); ++it2)
    {
        bool enc = false;
        auto it_o = output.begin();
        while (it_o != output.end() && !enc)
        {
            if (*it_o == *it2)
                enc = true;
            else
                ++it_o;
        }
        
        if (!enc)
            output.insert(output.end(), *it2);
    }
    
    return output;
}

list<int> operator-(const list<int>&L1, const list<int>&L2)
{
    list<int>output(L1);

    for (auto it2 = L2.cbegin(); it2 != L2.cend(); ++it2)
    {
        auto it_o = output.begin();
        while (it_o != output.end())
        {
            if (*it_o == *it2)
                it_o = output.erase(it_o);
            else
                ++it_o;
        }
    }
    
    return output;
}

// Segundo opción: La que ha dado la profesora
/*
list<int> operator+(const list<int>&L1, const list<int>&L2)
{
    list<int>output(L1);

    for (auto it2 = L2.cbegin(); it2 != L2.cend(); ++it2)
    {
        bool enc = false;
        auto it_o = output.begin();
        while (it_o != output.end() && !enc)
        {
            if (*it_o == *it2)
                enc = true;
            else
                ++it_o;
        }
        
        if (!enc)
            it_o = output.erase(it_o);
    }
    
    return output;
}
*/