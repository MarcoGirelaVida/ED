#include<iostream>
#include<set>
using namespace std;

class Red
{
private:
    set<string> ips;

public:
    Red();
    ~Red();

    class iterator
    {
    private:
        set<string>::iterator it;

    public:
        iterator();
        bool operator==(const iterator&i) const;
        bool operator!=(const iterator&i) const;
        iterator&operator++();
        const string &operator*(){return *it;}
    };
    
    int size() const{ return ips.size();}
    set<string>::iterator estaIp( const string & ip);
    void insert(const string &ip);
    void erase(const string &ip);
};

Red::Red()
{

}

set<string>::iterator Red::estaIp(const string & ip)
{
    return ips.find(ip);
}

void Red::erase(const string &ip)
{
    set<string>::iterator it;
    if ((it=estaIp(ip)) != ips.end())
    {
        ips.erase(it);
    }
    
}