#include <iostream>
#include <set>
#include <map>
#include <vector>

using namespace std;

// <FUNCIÓN A IMPLEMENTAR>
void only1(vector<set<int> > &vs, set<int> &s1)
{
	multiset <int> blacklist;
	for (const auto &set_i : vs)
		for (const auto &elemento_set_i : set_i)
			blacklist.insert(elemento_set_i);

	auto it_blacklist = blacklist.cbegin();
	while (it_blacklist != blacklist.cend())
	{
		if (blacklist.count(*it_blacklist) == 1)
			s1.insert(*it_blacklist);

		it_blacklist = blacklist.upper_bound(*it_blacklist);
	}
}

// Sobrecarga de operador << por si se necesitaran imprimir std:pair
template <class T1, class T2>
ostream& operator<<(ostream& os, const pair<T1, T2>& p) {
    os << "[" << p.first << "] = " << p.second;
    return os;
}

// Imprime todos los elementos del contenedor
template <class Contenedor>
void imprime_contenedor(const Contenedor &c){
	for (auto it=c.cbegin(); it!=c.cend(); it++)
		cout << *it << ' ';
		
	cout << endl;
}

// Simplemente comprueba que la solución para el vector de sets "in" es correcta
// Devuelve 1 si correcto, 0 si falso
int test_sol(vector<set<int> > in, const set<int> &sol){
	cout << "\nResultado: ";
	set<int> set_output;
	only1(in, set_output);
	imprime_contenedor(set_output);
	
	cout << "Solución:  ";
	imprime_contenedor(sol);
	
	bool es_correcta = set_output==sol;
	cout << "Solución correcta?: " << (es_correcta ? "YES" : "NO") << endl;
	
	return (es_correcta ? 1 : 0);
}

int main(){
	// Simple contador para contar el número de soluciones correctas
	int num_correctas = 0;
	int total_ejercicios = 4;

	vector<set<int>> in1 = {{0,1,2,3}, {2,3,4,5}};
	set<int> sol1 = {0,1,4,5};
	num_correctas += test_sol(in1, sol1);
	
	vector<set<int>> in2 = {{0,1,5,8,17}};
	set<int> sol2 = {0,1,5,8,17};
	num_correctas += test_sol(in2, sol2);
	
	vector<set<int>> in3 = {{0,1,2,3,4,5}, {3,4,5}, {4,5,17}, {5}};
	set<int> sol3 = {0,1,2,17};
	num_correctas += test_sol(in3, sol3);
	
	vector<set<int>> in4 = {{2,4}, {2,4}};
	set<int> sol4 = {};
	num_correctas += test_sol(in4, sol4);
	
	if (num_correctas == total_ejercicios)
		cout << "\n << Felicidades! Has aprobado :) >>" << endl;
	else
		cout << "\n << Inténtalo de nuevo :( >>" << endl;
}
