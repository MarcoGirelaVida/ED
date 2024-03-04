/*!
 * @file Pais.h
 * @brief Cabecera para la clase Pais
 */
/*!
 * @file Pais.h
 * @brief Cabecera para la clase Pais
 */
#ifndef PAIS
#define PAIS

#include "Punto.h"


/**
 * @brief T.D.A Pais
 * 
 * Una instancia del tipo de dato Abstracto Pais nos permite almacenar 
 * datos sobre un Pais en un único dato
 * 
 * Estos datos son punto geográfico, nombre y bandera.
 * 
 * El TDA también proporciona herramientas para su manipulación y uso
 * 
 * Para poder usar el TDA Pais hay que incluir el fichero
 * 
 * 
 * \#include <Pais.h>
 * 
 * 
 * 
 * TIPO DE REPRESENTACIÓN:
 *  Conjunto formado por un Punto y dos String que representa
 *  posición geográfica, nombre y pathname de la bandera del pais 
 *  respectivamente
 * 
 * FUNCION DE ABSTRACCIÓN:
 * f(Punto, String1, String2) -> Pais llamado [string1] ubicado en [Punto] con bandera [imagen del path string2] 
 * 
 * INVARIANTE DE REPRESENTACIÓN:
 * Ir{punto es donde se encuentra el pais con nombre string1, la bandera ubicada en string2 es la que se corresponde con el pais de nombre string1}
 */

class Pais{
  private:

    /**
     * @brief Posición geográfica del pais
     */

    /**
     * @brief Posición geográfica del pais
     */
    Punto p;
    /**
     * @brief Nombre del pais
     */
    /**
     * @brief Nombre del pais
     */
    string pais;
    /**
     * @brief Nombre del fichero de la bandera
     */
    /**
     * @brief Nombre del fichero de la bandera
     */
    string bandera;
    
  public:

    /**
     * @brief Constructor por defecto
     * @post Genera una instancia de Pais sin datos inicializados
     * @return Pais, el objeto creado  
     */

    Pais(){};


    /**
     * @brief Punto geográfico del pais
     * @return Objeto de la clase Punto que representa el punto geográfico del Pais
     * @post El pais no se modifica
     */
    Punto GetPunto()const;


    /**
     * @brief Nombre del pais
     * @return Nombre del pais en forma de string
     * @post El pais no se modifica
     */


    /**
     * @brief Nombre del pais
     * @return Nombre del pais en forma de string
     * @post El pais no se modifica
     */
    string GetPais()const;



    /**
     * @brief Pathname de la imagen de la bandera
     * @return Pathname de la imagen de la bandera del Pais
     * @post El pais no se modifica
     */



    /**
     * @brief Pathname de la imagen de la bandera
     * @return Pathname de la imagen de la bandera del Pais
     * @post El pais no se modifica
     */
    string GetBandera()const;




    /**
     * @brief Sobrecarga del operador <
     * @param P Pais que se va a comparar con el que llama a la operación
     * @pre p es un Pais inicializado correctamente 
     * @post ninguno de los dos paises se modifican
     * @return Devuelve @b true si el punto del pais que llama es menor que el punto del pais @p p y @b false si ocurre el caso contrario
     */




    /**
     * @brief Sobrecarga del operador <
     * @param P Pais que se va a comparar con el que llama a la operación
     * @pre p es un Pais inicializado correctamente 
     * @post ninguno de los dos paises se modifican
     * @return Devuelve @b true si el punto del pais que llama es menor que el punto del pais @p p y @b false si ocurre el caso contrario
     */
    bool operator<(const Pais &P)const;



    /**
     * @brief Sobrecarga del operador ==
     * @param P Pais que se va a comparar con el que llama a la operación
     * @pre P es un Pais inicializado correctamente
     * @post ninguno de los dos paises se modifican
     * @return Devuelve @b true si ambos puntos de ambos paises tienen valores de latitud y longitud iguales 
     * y @b false si no lo son
     */


    /**
     * @brief Sobrecarga del operador ==
     * @param P Pais que se va a comparar con el que llama a la operación
     * @pre P es un Pais inicializado correctamente
     * @post ninguno de los dos paises se modifican
     * @return Devuelve @b true si ambos puntos de ambos paises tienen valores de latitud y longitud iguales 
     * y @b false si no lo son
     */
    bool operator==(const Pais &P)const;

    /**
     * @brief Sobrecarga del operador ==
     * @param P Punto que se va a comparar con el del pais que llama a la operación
     * @pre P es un Punto inicializado correctamente
     * @post ni el pais ni el punto se modifican
     * @return Devuelve @b true si el punto del pais y el punto @p p tienen valores de latitud y longitud iguales 
     * y @b false si no lo son
     */
    /**
     * @brief Sobrecarga del operador ==
     * @param P Punto que se va a comparar con el del pais que llama a la operación
     * @pre P es un Punto inicializado correctamente
     * @post ni el pais ni el punto se modifican
     * @return Devuelve @b true si el punto del pais y el punto @p p tienen valores de latitud y longitud iguales 
     * y @b false si no lo son
     */
     bool operator==(const Punto &P)const;



    /**
     * @brief Sobrecarga del flujo de entrada
     * @param is flujo de entrada a leer
     * @param P Objeto de la clase Pais donde se almacenarán los datos leidos de @p is  
     * @pre @p P es un Pais inicializado correctamente
     * @post Se rellenan los datos del Pais @p P con los datos leidos del flujo
     * @p is
     */


    /**
     * @brief Sobrecarga del flujo de entrada
     * @param is flujo de entrada a leer
     * @param P Objeto de la clase Pais donde se almacenarán los datos leidos de @p is  
     * @pre @p P es un Pais inicializado correctamente
     * @post Se rellenan los datos del Pais @p P con los datos leidos del flujo
     * @p is
     */
    friend istream & operator>>(istream & is, Pais & P);

    /**
     * @brief Sobrecarga del flujo de salida
     * @param is flujo de salida donde se escribirán datos
     * @param P Objeto de la clase Pais de donde se extraerán los datos a almacenar en @p is  
     * @pre @p P es un Pais inicializado correctamente
     * @post Se leen los datos del Pais @p P y se escriben en el flujo @p os
     */
    /**
     * @brief Sobrecarga del flujo de salida
     * @param is flujo de salida donde se escribirán datos
     * @param P Objeto de la clase Pais de donde se extraerán los datos a almacenar en @p is  
     * @pre @p P es un Pais inicializado correctamente
     * @post Se leen los datos del Pais @p P y se escriben en el flujo @p os
     */
    friend ostream & operator<<(ostream & os, const Pais &P);

};


#endif