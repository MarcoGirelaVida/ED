/*
Los iteradores nos permiten acceder a los elementos de un contenedor (vector, lista...)

Abstracción por iteración ->
establece las características comunes para recorrer un contenedor sin preocupartnos
de los detalles de la estructura contenedora

¿CÓMO SE USAN LOS ITERADORES?
    1. Iniciar el iterador a la primera posición del contenedor (con el método begin())
    2. Saber cómo avanzar por los elementos del contenedor (operator ++, --)
    3. Saber cómo acceder al elemento que apunta el iterador (operator *)
    4. Saber cómo terminar de recorrer nuestro contenedor (método end())
*/

#include <vector>
#include <iostream>
using namespace std;

int main() {
    vector<int> numeros = {5, 15, 20, 14};
    vector<int>::iterator it;

    for (it = numeros.begin(); it != numeros.end(); ++it){
        cout << *it << endl;
    }
}