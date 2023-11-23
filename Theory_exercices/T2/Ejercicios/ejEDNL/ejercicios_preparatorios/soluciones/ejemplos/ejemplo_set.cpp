#include <iostream>
#include <set>

using namespace std;

void print_set(set<int> conjunto){
    for (auto it = conjunto.begin(); it!=conjunto.end(); it++)
        cout << *it << endl;
}

int main(){
    // Creo el set. Daros cuenta que los elementos se guardan en orden, de menor a mayor
    set<int> conjunto = {5,1,3,4,2};
    
    // Imprimo el set
    cout << "\nSet inicial" << endl;
    print_set(conjunto);
    
    // Tamaño
    cout << "Tamaño: " << conjunto.size() << endl;
    
    // Vacío
    cout << boolalpha << "Empty? " << conjunto.empty() << endl;
    
    // Insertar elemento
    conjunto.insert(178);
    conjunto.insert(2); // Como el elemento ya existe, no se inserta
    cout << "\nTras insertar" << endl;
    print_set(conjunto);
    
    // Eliminar elemento
    cout << "\nTras eliminar" << endl;
    conjunto.erase(178); // Por valor, no por índice
    print_set(conjunto);
    
    // Encontrar elemento (devuelve iterador a dicho elemento)
    auto it_elem = conjunto.find(3);
    cout << "\nSiguiente elemento: " << *++it_elem << endl;
    
    // Existe elemento
    cout << "4 en set?: " << ((conjunto.count(4) == 1) ? "Si" : "No") << endl;
    cout << "100 en set?: " << ((conjunto.count(100) == 1) ? "Si" : "No") << endl;
}
