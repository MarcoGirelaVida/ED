
#ifndef RACIONAL
#define RACIONAL

#include <iostream>
using namespace std;

/**
* ESPECIFICACIÓN: El TDA Racional representa un n perteneciente a los racionales
* o lo que es lo mismo, todo número que pueda expresarse como cociente enteros.
* Se representa como n/n. (Se representa de verdad así, no me refiero a la representación
* de la interna)

* OPERACIONES ESENCIALES : 
*      -Consultores/Modificadores de numerador/denominador
*      -Constructor/Destructor de Racionales

* TIPO DE REPRESENTACIÓN (interna)
*      -Opción 1: vector de dos enteros (numerador y denominador)
*      -Opción 2: Dos enteros (numerador, denominador)
*      -Opción 3: Un string con dos caracteres numéricos (numerador, denominador)
*      (este último es más cutre y no veo razón para hacerlo así, pero dado que
*      la opción dos ya venía dada por el ejemplo, veía feo solo dar una representación mia)

* FUNCIÓN DE ABSTRACCIÓN (para tipo rep 1)
* Fa: [int n][int d] -> r[0] "/" r[1]

* INVARIANTE DE LA REPRESENTACIÓN
* Ir: {n ∈ N, d ∈ N, d != 0}
*/

class Racional
{
    private:
        int * numero;
    
    public:
      /**
        * @brief Constructor por defecto.
        * @return Devuelve un racional con 1 en el numerador y denominador (1/1)
        */
        Racional();

      /** 
        * @brief Constructor con parámetros.
        * @param n Numerador del racional a crear.
        * @param d Denominador del racional a crear
        * @post Devuelve un racional con el numerador n y denominador d.
        */
        Racional(int n, int d);

        Racional (Racional & r);
      /**
        * @brief Destructor.
        */
        ~Racional();

      /**
        * @brief Consultor del numerador
        * @return Devuelve el valor del numerador del racional
        */
        int getNumerador();

      /**
        * @brief Consultor del denominador
        * @return Devuelve el valor del denominador del racional.
        */
        int getDenominador();

      /**
        * @brief Modificador del numerador
        * @param n Nuevo valor asociado al numerador
        * @return Devuelve el racional que ha sido modificado ya modificado
        */
        Racional & setNumerador(int n);

      /**
        * @brief Modificador del denominador
        * @param d Nuevo valor asociado al denominador
        * @return Devuelve el racional que ha sido modificado ya modificado.
        */
        Racional & setDenominador(int d);

        friend Racional & operator+= (Racional & r1, Racional & r2);
        friend bool operator== (Racional & r1, Racional & r2);
        friend bool operator!= (Racional & r1, Racional & r2);
        friend bool operator< (Racional & r1, Racional & r2);
        friend bool operator<= (Racional & r1, Racional & r2);
        friend bool operator> (Racional & r1, Racional & r2);
        friend bool operator>= (Racional & r1, Racional & r2);


    
};

#endif