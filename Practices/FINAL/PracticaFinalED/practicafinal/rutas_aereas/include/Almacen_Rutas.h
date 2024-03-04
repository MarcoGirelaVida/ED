/*!
 * @file Almacen_Rutas.h
 * @brief Cabecera para la clase Almacen de Rutas
 */


#include <string>
#include <map>
#include <iostream>
#include "Ruta.h"
#include "imagen.h"

#ifndef ALMACEN_RUTAS
#define ALMACEN_RUTAS


/**
 * @brief T.D.A Almacen de Rutas 
 * 
 * Una instancia del tipo de dato abstracto Almacen de Rutas nos permite
 * almacenar una colección de rutas y acceder a ellos con facilidad
 * mediante el uso de identificadores de ruta guardados como clave
 * 
 * El TDA proporciona herramientas para su manipulación y uso
 * 
 * Para poder usar el TDA Paises hay que incluir el fichero
 * 
 * \#include <Almacen_Rutas.h>
 * 
 * TIPO DE REPRESENTACIÓN:
 * 
 * Colección de claves con objetos asociados en los que la claves son
 * string y los objetos asociados son objetos de la clase Ruta.
 * 
 * La relación entre clave y objeto es la siguiente:
 * 
 * String = Ruta.GetCode
 */

class Almacen_Rutas{


    private:

        /**
         *@brief Conjunto ordenado de Rutas
         */
       map<string,Ruta> rutas;
    public:

        /**
         * @brief Constructor por defecto
         * @post Genera una instancia de Almacen_Rutas sin datos inicializados
         * @return Almacen_Rutas, el objeto creado
         */
        Almacen_Rutas(){};

        /**
         * @brief Inserción de una ruta en el conjunto
         * @param R Ruta que se va a insertar en el conjunto de rutas
         * @pre R es una Ruta inicializada correctamente
         * @post La ruta no se modifica. El conjunto es modificado añadiendo
         * la nueva Ruta
         */
        void Insertar(const Ruta & R);
        
        /**
         * @brief Borrado de una ruta del conjunto
         * @param R Ruta que se va a borrar del conjunto de rutas
         * @pre R es una Ruta inicializada correctamente
         * @post La ruta no se modifica. El conjunto es modificado eliminando
         * la Ruta R
         */
        void Borrar(const Ruta & R);

        /** @brief Ruta con número identificatorio concreto
         *  @param a Código identificatorio de la Ruta que se busca
         *  @post La colección no se modifica
         *  @return La ruta cuyo codigo coincide con el codigo a
         */
        Ruta GetRuta(const string & a);

/**
 * @brief Clase iterator no-constante
 * Para iterar sobre un almacen de rutas.
 *
 * Proporciona funcionalidades para iterar, acceder y modificar las rutas en la colección.
 */
    class iterator {
        private:
            map<string, Ruta>::iterator p; /**< Iterador apuntando a una ruta específica en la colección */

        public:
            /**
             * @brief Constructor por defecto para el iterador.
             */
            iterator() {}

            /**
             * @brief Operador de comparación de igualdad para iteradores.
             * @param i Iterador con el que comparar.
             * @return Verdadero si los iteradores son iguales, falso en caso contrario.
             */
            bool operator==(const iterator &i) { return p == i.p; }

            /**
             * @brief Operador de comparación de desigualdad para iteradores.
             * @param i Iterador con el que comparar.
             * @return Verdadero si los iteradores no son iguales, falso en caso contrario.
             */
            bool operator!=(const iterator &i) { return p != i.p; }

            /**
             * @brief Operador de incremento prefixado para el iterador.
             * @return Referencia al iterador después de incrementarlo.
             */
            iterator &operator++() {
                ++p;
                return *this;
            }

            /**
             * @brief Operador de decremento prefixado para el iterador.
             * @return Referencia al iterador después de decrementarlo.
             */
            iterator &operator--() {
                --p;
                return *this;
            }

            /**
             * @brief Operador de desreferencia para el iterador, proporcionando acceso a la ruta actual.
             * @return Referencia a la ruta apuntada por el iterador.
             */
            Ruta &operator*() {
                return p->second;
            }

            /**
             * @brief Declaración de amistad para permitir que la clase Almacen_Rutas acceda a miembros privados.
             */
            friend class Almacen_Rutas;

            /**
             * @brief Declaración de amistad para permitir que la clase const_iterator acceda a miembros privados.
             */
            friend class const_iterator;
    };

        /**
         * @brief Clase iterator constante
         * Para iterar sobre un almacen de rutas.
         *
         * Proporciona funcionalidades para iterar, acceder y modificar las rutas en la colección.
         */
        class const_iterator{
            private:
                map<string,Ruta>::const_iterator p;
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

                /**
                 * @brief Operador de desreferencia para el iterador, proporcionando acceso a la ruta actual.
                 * @return Referencia a la ruta apuntada por el iterador.
                 */
                const Ruta & operator*()const{
                        return p->second;
                }
                
        /**
         * @brief Declaración de amistad para permitir que la clase Almacen_Rutas acceda a miembros privados.
         */
        friend class Almacen_Rutas;
        };

        /**
         * @brief Inicio de la colección de Rutas
         * @post La colección no se ve modificada
         * @return Iterador que apunta a la primera Ruta de la colección
         */
        iterator begin();
        /**
         * @brief Inicio de la colección de Rutas
         * @post La colección no se ve modificada
         * @return Const_iterator que apunta a la primera Ruta de la colección
         */
        const_iterator begin()const;
        /**
         * @brief Final de la colección de Rutas
         * @post La colección no se ve modificada
         * @return Iterador que apunta a la ultima Ruta de la colección
         */
        iterator end();

        /**
         * @brief Final de la colección de Rutas
         * @post La colección no se ve modificada
         * @return Const_iterator que apunta a la ultima Ruta de la colección
         */
        const_iterator end()const;

        friend istream & operator >> (istream & is, Almacen_Rutas & AR);
        friend ostream & operator <<(ostream & os, const Almacen_Rutas &AR);


};

#endif