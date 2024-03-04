/*!
 * @file Punto.h
 * @brief Cabecera para la clase Punto
 */


#include <iostream>
using namespace std;


#ifndef PUNTO 
#define PUNTO


/**
 * @brief T.D.A. Punto
 * 
 * Una instancia del dito de dato abstracto Punto nos permite almacenar y representar
 * posiciones geográficas en la superficie de la Tierra.
 * 
 * Este T.D.A proporciona herramientas para la manipulación y uso de dichos Puntos
 * 
 * Para usar el T.D.A Punto hay que incluir el fichero
 * 
 * \#include <Punto.h>
 * 
 * 
 * 
 * TIPO DE REPRESENTACIÓN:
 *  Conjunto formado por dos numeros reales que representan
 *  la latitud y la longitud de un punto geográfico.
 * 
 * FUNCION DE ABSTRACCION
 *  f(int1, int2) -> Punto ubicado en latitud [int1] y longitud [int2]
 * 
 * INVARIANTE DE REPRESENTACIÓN
 * Ir: {-90 < int1 < 90, -180 < in2 < 180}
 */

class Punto{
    private:
    /**
     * @brief Posición geográfica del punto
     * 
     */
        float latitud,longitud;



    public:

        /**
         * @brief Constructor por defecto
         * @post Genera una instancia de Punto con la posición del punto por defecto a 0.0 , 0.0
         * @return Punto, el objeto creado  
         */
        Punto(){
            latitud=longitud=0;
        }


        /**
         * @brief Constructor con parámetros
         * @param l latitud del punto
         * @param L longitud del punto
         * @pre -90 < latitud < 90 y -180 < longitud < 180
         * @post Genera una instancia de Punto con l latitud y L longitud
         * @return Punto, el objeto creado
         */


        Punto(double l, double L):latitud(l),longitud(L){}

        /**
         * @brief Latitud del punto
         * @return valor de la latitud del punto
         * @post el punto no se modifica
         */
        double GetLatitud()const;

        /**
         * @brief Longitud del punto
         * @return valor de la longitud del punto
         * @post el punto no se modifica
         */
        double GetLongitud()const;

        /**
         * @brief Asigna el valor l a la latitud del punto
         * @param l latitud que se va a asignar al punto
         * @pre -90 < latitud < 90
         * @post la latitud del punto se modificará y contendrá l
         */

        void SetLatitud(double l);

        /**
         * @brief Asigna el valor l a la longitud del punto
         * @param l longitud que se va a asignar al punto
         * @pre -180 < longitud < 180
         * @post la longitud del punto se modificará y contedrá l
         */

        void SetLongitud(double l);


        /**
         * @brief Sobrecarga del operador <
         * @param p Punto que se va a comparar con el que llama a la operación
         * @pre p es un Punto inicializado correctamente 
         * @post ninguno de los dos puntos se modifican
         * @return Devuelve @b true si el punto que llama es menor que p y @b false si ocurre el caso contrario
         * Ser menor supone tener los dos valores menores al otro punto, o almenos uno menor y otro igual
         */

        bool operator<(const Punto &p)const;


        /**
         * @brief Sobrecarga del operador ==
         * @param p Punto que se va a comparar con el que llama a la operación
         * @pre p es un Punto inicializado correctamente
         * @post ninguno de los dos puntos se modifican
         * @return Devuelve @b true si ambos puntos tienen valores de latitud y longitud iguales 
         * y @b false si no lo son
         */
        bool operator==(const Punto &p)const;


        /**
         * @brief Sobrecarga del flujo de entrada
         * @param is flujo de entrada a leer
         * @param p Objeto de la clase Punto donde se almacenarán los datos leidos de @p is  
         * @pre @p p es un Punto inicializado correctamente
         * @post Se rellenan los datos del Punto @p p con los datos leidos del flujo
         * @p is
         */
        friend istream & operator>>(istream & is, Punto &p);


        /**
         * @brief Sobrecarga del flujo de salida
         * @param is flujo de salida donde se escribirán datos
         * @param p Objeto de la clase Punto de donde se extraerán los datos a almacenar en @p is  
         * @pre @p p es un Punto inicializado correctamente
         * @post Se leen los datos del Punto @p p y se escriben en el flujo @p os
         */
        friend ostream & operator<<(ostream & os, const Punto &p);
};

#endif
