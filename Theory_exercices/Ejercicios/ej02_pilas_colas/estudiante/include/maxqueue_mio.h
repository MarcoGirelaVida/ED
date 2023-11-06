/**
 * @file maxqueue.h
 * @brief  Archivo de especificación del TDA MaxQueue
 * @author Marco Girela
 */

#include <iostream>
#include <queue>
#include <string>
#include "element.h"
using namespace std;

class MaxQueue
{
private:
    queue<element> underlying_container;

public:
    MaxQueue(){}

    bool empty() const;

    int size() const;   
    
    const element& front() const;

    void push(const element &e);

    void pop();
};