#include <iostream>
#include <set>

using namespace std;

void Imprimir(set<int> Conjunto){

   for(auto it=Conjunto.begin(); it!=Conjunto.end(); ++it)
      cout<< *it <<" ";
   cout << endl << endl;
}

set<int> interseccion(set<int> &A, set<int> &B)
{
   set<int> output;
   for (const auto &elemento_A : A)
      if (B.count(elemento_A))
         output.insert(elemento_A);

   return output;
}

set<int> union_negada(const set<int> &A, const set<int> &B)
{
   set<int> output;
   for (const auto &elemento_A : A)
      if (!B.count(elemento_A))
         output.insert(elemento_A);

   return output;
}

void inter(set<int> &A, set<int> &B, set<int> &C, set<int> &Resul)
{
   Resul.clear();

   // A que están en B pero no en C
      Resul.merge(union_negada(interseccion(A,B), C));

   // B que están en C pero no en A
      Resul.merge(union_negada(interseccion(B,C), A));

   // A que están en C pero no en B
      Resul.merge(union_negada(interseccion(A,C), B));
}


int main(){
   set<int> A={1,2,3,4,5,6};
   set<int> B={4,5,7,8,9,10};
   set<int> C={5,6,10,11,12,13};
   set<int> Result;
   
   cout<<"Conjunto A: ";
   Imprimir(A);
   cout<<"Conjunto B: ";
   Imprimir(B);
   cout<<"Conjunto C: ";
   Imprimir(C);
   
   inter(A,B,C,Result);
   
   cout<<"Conjunto Resultado: ";
   Imprimir(Result);
    
}

