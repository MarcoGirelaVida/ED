/*
Estructuras de Datos.
Tema 2: Abstracción.
Relación de Problema

Marco Girela Vida 2ºB
*/

#include <string>
using namespace std;

/*
1. Definir el T.D.A Servidor de red.

Un servidor es un punto de red que se encuentra identificado por una dirección ip.
Una dirección ip viene definida por cuatro dígitos que pueden tener valores que van desde 0 a 255.
Se pide:
◦ Dar la especificación del tipo Servidor. Además establecer las operaciones que
manejan al T.D.A
◦ Definir al menos dos tipo rep
◦ Escoger uno de los ttipo rep y para este establecer la función de abstracción e
invariante de representación
*/

// 1.1 ESPECIFICACIÓN: 
// Representa la dirección IP v4 A.B.C.D donde A,B,C,D son números de 8 bytes.
// 1.2 OPERACIONES:
// Consultar IP, consultar numero A, B, C o D

// 2. REPRESENTACIONES:
// Opción 1: un número de 32 bits (4 bytes)
struct Opción1
{
    unsigned int ip;
};

// Opción 2: 4 números de 4 bits (1 byte)
struct Opcion2 
{
    unsigned int A, B, C, D;
};

// 3.1 FUNCIÓN DE ABSTRACCIÓN
// Fa: {a,b,c,d} -> a.b.c.d
string funcion_abstraccion(Opcion2 IP)
{
    return to_string(IP.A) + to_string(IP.B) + to_string(IP.C) + to_string(IP.D);
}

// 3.2 INVARIANTE DE REPRESENTACIÓN
// Invariante representación: {255 >= a,b,c,d >= 0}
// La condición de ser mayor que 0 la cumplen por ser unsigned int.
bool invariante_representacion(Opcion2 IP)
{
    bool dato_valido = true;

    if (IP.A > 255 || IP.B > 255 || IP.C > 255 || IP.D > 255)
    {
        dato_valido = false;
    }
    
    return dato_valido;
}





// REQUIERE CORRECCIÓN PARA AÑADIR LOS VECTORES DE SERVIDORES
/*
2. Definir el T.D.A Subred.

Este T.D.A es una colección de servidores (s1,s2,...,sn), según se ha
definido el T.D.A Servidor en el ejercicio anterior. En el T.D.A. Subred también se almacena
si dos servidores están conectados (existe un enlace directo) entre ellos.
Se pide:
◦ Dar la especificación del tipo Subred. Además establecer las operaciones que
manejan a T.D.A
◦ Definir al menos dos tipo rep
◦ Escoger uno de los tipo rep y para este establecer la función de abstracción e
invariante de representación
*/
// 1. ESPECIFICACIÓN: Representa el conjunto de servidores conectados en una red y sus conexiones entre si.
// Lo hace en forma de matriz nxn siendo n el número de servidores, marcando una X allá donde haya una conexión.
// Ej:  s1 s2 s3 s4
//   s1 X
//   s2    X     X
//   s3       X
//   s4    X     X
// En ese caso hay 4 servidores donde únicamente estan conectados el 2 con el 4.

// 2. REPRESENTACIÓN: 
// Opción 1: Vector de nxn booleanos que representan las conexiones y un vector n que almacena los servidores
class Opcion1_subred
{
    private:
        int numero_servidores;
        bool ** conexiones;
    public:
        Opcion1_subred(int n_servidores = 0);
        ~Opcion1_subred();

        string funcion_abstraccion_subred();
};

Opcion1_subred::Opcion1_subred(int n_servidores)
{
    numero_servidores = n_servidores;
    conexiones = new bool * [numero_servidores];
    conexiones[0] = new bool[numero_servidores * numero_servidores];

    for (int i = 0; i < numero_servidores; i++)
        conexiones[i] = &conexiones[0][numero_servidores*i];

    
    for (int i = 0; i < numero_servidores; i++)
        conexiones[i][i] = true;

}

Opcion1_subred::~Opcion1_subred()
{
    delete [] conexiones[0];
    delete [] conexiones;
}

// Opción 2: Vector de punteros a vectores que representan las columnas de la matriz
class Opcion2_subred
{
    private:
        int numero_servidores;
        bool ** conexiones;
    public:
        Opcion2_subred(int n_servidores=0);
        ~Opcion2_subred();
};

Opcion2_subred::Opcion2_subred(int n_servidores)
{
    numero_servidores = n_servidores;
    conexiones = new bool * [n_servidores];

    for (int i = 0; i < n_servidores; i++)
        conexiones[i] = new bool[n_servidores];

    for(int i = 0; i < n_servidores; i++)
        conexiones[i][i] = true;
    
}

Opcion2_subred::~Opcion2_subred()
{
    for (int i = 0; i < numero_servidores; i++)
    {
        delete [] conexiones[i];
    }
    
    delete [] conexiones;
}

// 3.1 FUNCIÓN DE ABSTRACCIÓN
// Fa: {vector[n_servidores*n_servidores]} -> matriz con X
string Opcion1_subred::funcion_abstraccion_subred()
{
    string matriz_resultante;
    for (int i = 0; i < numero_servidores; i++){
        for (int j=0; j < numero_servidores; j++)
            matriz_resultante += (conexiones[i][j]) ? 'X' : ' ';
        matriz_resultante += '\n';
    }

    return matriz_resultante;
}

// 3.2 INVARIANTE DE REPRESENTACIÓN
// Invariante de representación: {1 >= m[i][j] >= 0}
// Se cumple por el hecho de ser tipos de dato bool 




/*
3. Definir el T.D.A Punto Geográfico.

Un punto geográfico se define por una latitud y longitud.
La latitud es la distancia en grados desde la línea del Ecuador a los Polos.
Su rango va desde -90º a 90º.
La longitud es la distancia desde el meriadiano 0 al punto donde estamos.
El rango de valores que adopta va desde -180º a 180º.
Se pide
◦ Dar la especificación del tipo Punto Geográfico. Además establecer las operaciones
que manejan a T.D.A
◦ Definir al menos dos tipo rep
◦ Escoger uno de los tipo rep y para este establecer la función de abstracción e
invariante de representación
*/
// 1. ESPECIFICACIÓN: Representa un punto geográfico mediante un dato de latitud y otro de longitud
// en el siguiente formato: [lat,long]
// 1.2 OPERACIONES: Consultar (lat, long), crear punto, modificar (lat, long)


// 2. REPRESENTACIONES
// Opción 1: vector de dos flotantes
// Opción 2: dos flotantes

// 3. FUNCIÓN DE ABSTRACCIÓN
// Fa : {float a, float b} -> [a,b]
// 3.2 INVARIANTE DE REPRESENTACIÓN
// {-90 < a < 90, -180 < b < 180}

// NOTA: Se podría hacer también con minutos y segundos haciendo dos vectores de tres elementos (grados, minutos, segundos)



/*
4. Definir el T.D.A Ruta.

Una ruta es una secuencia de puntos geográficos (ver ejercicio anterior).
Se pide:
◦ Dar la especificación del tipo Ruta. Además establecer las operaciones que manejan
a T.D.A
◦ Definir al menos dos tipo rep
◦ Escoger uno de los tipo rep y para este establecer la función de abstracción e
invariante de representación
*/

// 1.1 ESPECIFICACIÓN:
//  Conjunto de n puntos geográficos conectados entre si
// sucesivamente (p1 -> p2 -> p3 ...)

// 1.2 OPERACIONES:
// Crear ruta, Consultar punto n, insertar unto, eliminar punto, añadir punto, modificar punto (aunque se puede hacer con eliminar y añadir)

// 2. REPRESENTACIÓN
// Opción 1: Vector de objetos punto.
// Opcioń 2: Lista enlazada (un dato con un puntor que apunta al siguiente nodo)

// 3.1 FUNCIÓN DE ABSTRACCIÓN
// Fa: {[a,b,c,d]} -> a->b->c->d
// 3.2 INVARIANTE DE REPRESENTACIÓN
// Ninguno que se me ocurra, todas las combinaciones posibles de puntos son válidas siempre 
// que los puntos sean válidos, y la validez de los mismos la controla su propio TDA.
// Quizás que cada punto solo se pueda conectar con un punto, pero eso ya se limita por los 
// propios tipos de representaciones



/*
5. Dar una especificación para la función que permite derivar un polinomio.
Suponiendo quetenemos el TDA Polinomio, la cabecera de la función derivada sería asi:
void Derivar(const Polinomio & p_origen, Polinomio & p_derivada);
*/
// ESPECIFICACIÓN: Función que dado un polinomio xn + xn-1 + ... + c devuelve otro polinomio
// n*xn-1 + ... + c. O lo que es lo mismo f'(Pn(x)) = Pn'(x) (no es una definición muy matemática pero bueno jajajaj)



// DUDAS:
// -¿Cómo sé qué operaciones necesita? Prácticamente con hacer un struct el
// resto de operciones se pueden implementar externamente, no hay realmente
// ninguna operación "imprescindible".