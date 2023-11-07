/*
Dada una cola de listas de enteros devolver otra cola de enteros que contenga en cada 
posición la suma de los elementos en la lista correspondiente en la cola original. La 
cabecera de la función sería la siguiente: 
queue<int> GetSumas(queue<list<int> > & ql); 
Ejemplo 
 ql={{1,2,3},{4,5},{3,7,2}} → Qout={6,9,12} 
            ^ 
         front
*/

#include <iostream>
#include <queue>
#include <list>
using namespace std;

int popAndAdd(queue<list<int>> &q)
{
   int suma_total = 0;
   list<int> aux = q.front();
   q.pop();

   for (list<int>::const_iterator it = aux.cbegin(); it != aux.cend(); ++it)
      suma_total += (*it);

   cout << "Suma_total: " << suma_total << endl;
   return suma_total;
}


int main()
{
   queue<list<int>> Q1;
   queue<int> Qout;

   Q1.push({1,2,3});
   Q1.push({4,5});
   Q1.push({3,7,2});

   while (!Q1.empty())
      Qout.push(popAndAdd(Q1));

   return 0;
}