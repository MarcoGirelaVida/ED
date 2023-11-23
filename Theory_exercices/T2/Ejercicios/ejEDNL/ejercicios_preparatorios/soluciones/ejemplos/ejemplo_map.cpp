#include <iostream>
#include <map>

using namespace std;

void print_dict(map<char,int> dict){
    for (auto it = dict.begin(); it!=dict.end(); it++)
        cout << (*it).first << ' ' << (*it).second << endl;
}

int main(){
    // Creo el map. Los elementos se guardan ordenados por key
    map<char,int> dict;
    dict['b']=10; // Con [] puedo añadir un valor
    dict['a']=2;
    dict['c']=5;
    
    // Imprimo el diccionario. Cada elemento es de tipo std::pair<char,int>
    // Se puede apreciar cómo se guardan en orden de clave
    cout << "\nDiccionario inicial" << endl;
    print_dict(dict);
    
    // Cambio el valor de un elemento usando []
    dict['b']=30;
    cout << "\nDiccionario tras modificacion" << endl;
    print_dict(dict);
    
    // Tamaño
    cout << "Tamaño: " << dict.size() << endl;
    // Vacio
    cout << "Vacio?: " << boolalpha << dict.empty() << endl;
    
    // ¿Que pasa cuando accedo con una clave que no existe?
    cout << "Valor para clave inexistente: " << dict['z'] << endl;
    
    // Elimino un elemento
    dict.erase('a'); // Por clave
    cout << "\nDiccionario tras erase" << endl;
    print_dict(dict);
    
    // Encontrar elemento (devuelve iterador a dicho elemento)
    auto it_elem = dict.find('b'); // Por clave
    cout << "\nElemento: " << (*it_elem).second << endl;
    
    // Existe elemento
    cout << "b en map?: " << ((dict.count('b') == 1) ? "Si" : "No") << endl; // Se cuenta por clave
    cout << "g en map?: " << ((dict.count('g') == 1) ? "Si" : "No") << endl;
}