#include "VD.h"

class Conjunto{
    private:
        VD<int> datos;
    
    public:
        Conjunto(){}; // El constructor por defecto ya llama al constructor de la clase VectorDinamico
        Conjunto(const Conjunto &C)
        {
            datos = C.datos;
        }
        // Tampoco hará falta implementar operador de asignación puesto que también hace uso del ya implementado en VectorDinamico

        int size(){
            return datos.size();
        }

        bool Esta(int x, int &pos){
            int ini = 0; 
            int fin = datos.size();
            bool encontrado = false;
            while (ini < fin && !encontrado)
            {
                int mitad = (ini + fin)/2;
                if (datos[mitad] == x)
                {
                    encontrado = true;
                    pos = mitad;
                }
                else if (datos[mitad] < x)
                {
                    ini = mitad + 1;
                }
                else
                {
                    fin = mitad;
                }
            }

            return encontrado;
        }

        void Add(int x);
        void Remove(int x);
}