/**
 * @file maxqueue.h
 * @brief  Archivo de especificación del TDA MaxQueue
 * @author Marco Girela
 */

#include <iostream>
#include <stack>
#include <string>
#include "element.h"
using namespace std;
class MaxQueue
{
private:
    stack<element> underlying_container;

public:
    MaxQueue(){}

    bool empty() const;

    int size() const;   
    
    const element& front() const;

    void push(const element &e);

    void pop();
};