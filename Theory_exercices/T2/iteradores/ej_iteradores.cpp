#include <vector>
#include <iostream>
using namespace std;

// Cambiar todos los pares por -1
void Cambiar (vector<int> & v){
    vector<int>::iterator it;

    for(it=v.begin(); it != v.end(); it++){
        if ((*it)%2 == 0)
        {
            *it = -1;
        }
    }
}


// Imprimir un vector de atrás hacia adelante
void imprimir_inverso( vector<int> &v){
    vector<int>::iterator it = v.end();
    --it; // Porque el último elemento no es v.end(), sino v.end()-1

    while(it != v.begin()){
        cout << *it;
        --it;
    }

    cout << *it; //Porque el bucle termina cuando it == v.begin() y este no se imprime
}

//Opción 2: Con un do while
void imprimir_inverso( vector<int> &v){
    vector<int>::iterator it = v.end();
    --it; // Porque el último elemento no es v.end(), sino v.end()-1

    do
    {
        --it;
        cout << *it;
    } while (it != v.begin());
    
}