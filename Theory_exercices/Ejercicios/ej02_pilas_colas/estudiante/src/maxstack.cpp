/**
 * @file maxstack.cpp
 * @brief  Archivo de implementación del TDA MaxStack
 * @author Marco Girela Vida
 */

#include "../include/maxstack.h"

bool MaxStack::empty() const
{
	return underlying_container.empty(); 
}

int MaxStack::size() const
{
	return underlying_container.size(); 
}

const element MaxStack::top()
{
    move_bottom_of_underlying_queue_to_top();
	element output = underlying_container.front(); 
    send_top_of_underlying_queue_to_bottom();
    return output;
}

void MaxStack::push(const element &e)
{
	return underlying_container.push(e); 
}

void MaxStack::pop()
{
    move_bottom_of_underlying_queue_to_top();
	underlying_container.pop();
};



// PRIVATE
void MaxStack::move_bottom_of_underlying_queue_to_top()
{
    for (size_t i = 1; i < size(); i++)
        send_top_of_underlying_queue_to_bottom();
}

void MaxStack::send_top_of_underlying_queue_to_bottom()
{
    underlying_container.push(underlying_container.front());
    underlying_container.pop();
}