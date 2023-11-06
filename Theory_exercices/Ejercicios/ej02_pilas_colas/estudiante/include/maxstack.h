/**
 * @file maxstack.h
 * @brief  Archivo de especificación del TDA MaxStack
 * @author Marco Girela
 */

#include <iostream>
#include <queue>
#include <string>
#include "element.h"
using namespace std;

class MaxStack
{
private:
    queue<element> underlying_container;

public:
    MaxStack(){}

    bool empty() const;

    int size() const;   
    
    const element top();

    void push(const element &e);

    void pop();

private:
    void move_bottom_of_underlying_queue_to_top();
    void send_top_of_underlying_queue_to_bottom();
};