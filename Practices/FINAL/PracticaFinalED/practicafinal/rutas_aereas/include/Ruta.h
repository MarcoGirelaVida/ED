/*!
 * @file Ruta.h
 * @brief Cabecera para la clase Ruta
 */

#include <string>
#include <list>
#include <iostream>
#include "Punto.h"
#include "imagen.h"
#include "Paises.h"


#ifndef RUTA
#define RUTA


/**
 *@brief T.D.A Ruta 
 * 
 * Una instancia del tipo de dato Abstracto Ruta nos permite
 * almacenar datos sobre un conjunto de Puntos que forman una
 * Ruta y ponerle un código identificatorio
 *  
 * Cada punto es un objeto de la clase Punto
 * 
 * El TDA también proporciona herramientas para su manipulación y uso
 * 
 * Para poder usar el TDA Ruta hay que incluir el fichero
 * 
 * \#include <Ruta.h>
 * 
 * 
 * TIPO DE REPRESENTACIÓN:
 *  Conjunto formado por una colección de puntos geográficos y un string que
 *  representa el recorrido de la ruta en un mapa y su identificador
 *  respectivamente.
 * 
 * FUNCION DE ABSTRACCIÓN:
 * f(puntos, string) -> Ruta con código [string] que pasa por los puntos [puntos]
 * 
 * INVARIANTE DE REPRESENTACIÓN:
 * Ir: {string puede ser casteado a un unsigned int, los puntos sucesivos son distintos entre sí (no puedo ir de A a A)}
 */
class Ruta{

    private:

        /**
         * @brief Colección de puntos geográficos 
         */
        list<Punto> puntos;

        /**
         *@brief Identificador de la ruta 
         */
        string code;

    public:

        /**
         * @brief Constructor por defecto
         * @post Genera una instancia de Ruta sin datos inicializados
         * @return Ruta, el objeto creado
         */
        Ruta(){};



        /**
         * @brief Inserción de un pais en el conjunto
         * @param n Punto que se va a insertar en la Ruta
         * @pre n es un Punto inicializado correctamente
         * @post El punto no se modifica. El conjunto es modificado
         * añadiendo el nuevo pais
         */
        void Insertar (const Punto & n);
        /**
         * @brief Borrado de un Punto del conjunto
         * @param n Punto que se va a borrar de la Ruta
         * @pre n es un Punto inicialiado correctamente
         * @post El Punto no se modifica. El conjunto es modificado
         * eliminando el nuevo pais
         */
        void Borrar (const Punto & n);
        /**
         * @brief Código identificatorio de la ruta
         * @return Código de la ruta en forma de string
         * @post La ruta no se modifica
         */
        string GetCode()const;

        /**
         * @brief Pintado de Aviones entre dos puntos de una ruta
         * @param f1 Coordenada X del primer punto
         * @param f2 Coordenada X del segundo punto
         * @param c1 Coordenada Y del primer punto
         * @param c2 Coordenada Y del segundo punto
         * @param I Imagen del Mapa donde se van a pintar los aviones
         * @param avion Imagen del avión que se va a usar para pintar
         * @param mindisf Mínimo de filas
         * @param mindisc Mínimo de columnas
         * @pre I y avion son Imágenes correctamente inicializadas
         * @post la imagen I se ve modificada.
         */
        void PintarAviones(int f1,int f2,int c1,int c2,Imagen &I, const Imagen &avion,int mindisf,int mindisc);
        /**
         * @brief Pintado de una ruta completa en un mapa 
         * @param mapa Imagen que contiene el mapa donde se va a pintar la ruta
         * @param paises Objeto de la clase Paises que contiene todos los paises existentes
         * @param FlagPath Path que lleva al directorio donde se encuentran las imagenes de las banderas
         * @param avion Imagen que contiene el avión que se usará para dibujar la ruta
         * @pre mapa y avion son Imagenes correctamente inicializadas
         * @post ninguna imagen se ve modificada, ni la colección de paises
         * @return Mapa con la ruta pintada
         */
        Imagen PintarRuta(const Imagen & mapa, Paises & paises, const string FlagPath, const Imagen & avion);


        /**
         * @brief Establece un código a la ruta
         * @param code código a asignar a la ruta
         * @post Se modifica el código de la ruta
         */
        void SetCode(const string & code);

        /**
         * @brief Sobrecarga del operador ==
         * @param R Ruta que se va a comparar con la que llama a la operación
         * @pre R es una Ruta inicializada correctamente
         * @post ninguna de las dos rutas se modifican
         * @return Devuelve @b true si el código y la colección de ambas rutas son iguales 
         * y @b false si no lo son
         */
        bool operator==(const Ruta & R)const;


        /**
         * @brief Sobrecarga del operador <
         * @param R Ruta que se va a comparar con la que llama a la operación
         * @pre R es una Ruta inicializada correctamente
         * @post ninguna de las dos rutas se modifican
         * @return Devuelve @b true si la ruta que llama tiene menos puntos que R
         * y @b false en caso contrario
         */
        bool operator<(const Ruta &R)const;

        /**
         * @brief Clase iterator n-constante
         * Para iterar sobre los destinos de una ruta.
         *
         * Proporciona funcionalidades para iterar, acceder y modificar los puntos de una ruta.
         */
        class iterator{
            private:
                list<Punto>::iterator p;
            public:
                /**
                 * @brief Constructor por defecto para el iterador.
                 */
                iterator(){}

                /**
                 * @brief Operador de comparación de igualdad para iteradores.
                 * @param i Iterador con el que comparar.
                 * @return Verdadero si los iteradores son iguales, falso en caso contrario.
                 */
                bool operator == (const iterator &i){return p == i.p;}

                /**
                 * @brief Operador de comparación de desigualdad para iteradores.
                 * @param i Iterador con el que comparar.
                 * @return Verdadero si los iteradores no son iguales, falso en caso contrario.
                 */ 
                bool operator != (const iterator &i){return p != i.p;}

                /**
                 * @brief Operador de incremento prefixado para el iterador.
                 * @return Referencia al iterador después de incrementarlo.
                 */
                iterator & operator++(){
                    ++p;
                    return *this;
                }

                /**
                 * @brief Operador de decremento prefixado para el iterador.
                 * @return Referencia al iterador después de decrementarlo.
                 */
                iterator& operator--(){
                    --p;
                    return *this;
                }

                /**
                 * @brief Operador de desreferencia para el iterador, proporcionando acceso a la ruta actual.
                 * @return Referencia a la ruta apuntada por el iterador.
                 */
                Punto & operator*(){
                    return *p;
                }
                
            friend class Ruta;
            friend class const_iterator;
	    }; 

        /**
         * @brief Clase iterator constante
         * Para iterar sobre los destinos de una ruta.
         *
         * Proporciona funcionalidades para iterar, acceder y modificar los puntos de una ruta.
         */
        class const_iterator{
            private:
                list<Punto>::const_iterator p;
            public:
                /**
                 * @brief Constructor por defecto para el iterador.
                 */
                const_iterator(){}

                /**
                 * @brief Operador de comparación de igualdad para iteradores.
                 * @param i Iterador con el que comparar.
                 * @return Verdadero si los iteradores son iguales, falso en caso contrario.
                 */
                bool operator == (const const_iterator &i){return p == i.p;}

                /**
                 * @brief Operador de comparación de desigualdad para iteradores.
                 * @param i Iterador con el que comparar.
                 * @return Verdadero si los iteradores no son iguales, falso en caso contrario.
                 */
                bool operator != (const const_iterator &i){return p != i.p;}

                /**
                 * @brief Operador de incremento prefixado para el iterador.
                 * @return Referencia al iterador después de incrementarlo.
                 */
                const_iterator & operator++(){
                    ++p;
                    return *this;		
                }

                /**
                 * @brief Operador de decremento prefixado para el iterador.
                 * @return Referencia al iterador después de decrementarlo.
                 */
                const_iterator & operator--(){
                    --p;
                    return *this;
                }
                
                const Punto & operator*()const{
                    return *p;
                }

                friend class Ruta;
            
        };

        /**
         * @brief Inicio de la colección de Puntos de la Ruta 
         * @post La ruta no se ve modificada
         * @return Iterador que apunta al primer punto de la Ruta
         */
        iterator begin();

        /**
         * @brief Inicio de la colección de Puntos de la Ruta 
         * @post La ruta no se ve modificada
         * @return Const_iterator que apunta al primer punto de la Ruta
         */
        const_iterator begin()const;
        /**
         * @brief Final de la colección de Puntos de la Ruta 
         * @post La ruta no se ve modificada
         * @return Iterador que apunta al último punto de la Ruta
         */
        iterator end();

        /**
         * @brief Final de la colección de Puntos de la Ruta 
         * @post La ruta no se ve modificada
         * @return Const_iterator que apunta al último punto de la Ruta
         */
        const_iterator end()const;


        /**
         * @brief Búsqueda de un Punto en la Ruta
         * @param p Punto a buscar en la ruta
         * @pre p es un Punto inicializado correctamente
         * @post La ruta no se ve modificada
         * @return iterador que apunta al Punto encontrado
         */
        iterator find(const Punto &p);

        /**
         * @brief Sobrecarga del flujo de entrada
         * @param is flujo de entrada a leer
         * @param R Objeto de la clase Ruta donde se almacenarán los datos leidos de @p is  
         * @pre @p R es una Ruta inicializada correctamente
         * @post Se rellenan los datos de la Ruta @p R con los datos leidos del flujo
         * @p is
         */
        friend istream & operator>>(istream & is, Ruta & R);

        /**
        * @brief Sobrecarga del flujo de salida
        * @param is flujo de salida donde se escribirán datos
        * @param R Objeto de la clase Ruta de donde se extraerán los datos a almacenar en @p is  
        * @pre @p R es una Ruta inicializada correctamente
        * @post Se leen los datos de la Ruta @p R y se escriben en el flujo @p os
        */
        friend ostream & operator<<(ostream & os, const Ruta &R);


};

#endif