/**
 * @file maxqueue.cpp
 * @brief  Archivo de implementación del TDA MaxQueue
 * @author Marco Girela Vida
 */

#include "../include/maxqueue.h"

bool MaxQueue::empty() const
{
	return underlying_container.empty(); 
}

int MaxQueue::size() const
{
	return underlying_container.size(); 
}

const element& MaxQueue::front() const
{
	return underlying_container.top(); 
}

void MaxQueue::push(const element &e)
{
	return underlying_container.push(e); 
}

void MaxQueue::pop()
{
	return underlying_container.pop();
};