/*
ABBs
Operaciones:
    - Preguntar si existe un elemento
    - Insertar un nuevo elemento
    - Borrar un elemento

Los hijos a la derecha son siempre mayores que su padre
Los hijos a la izquierda son siempre menores que su padre

En el peor de los casos (si están mal equilibrados), la búsqueda será O(n), pero si están
equilibrados será O(log2(n)).
*/

// Ejercicio 1 - Construir un ABB con las siguientes chlaves {5,7,13,20,80,1,3,0,12}
/*
     5
  1     7
0   3       13
        12      20
                    80
*/


// Algoritmo de busqueda binaria - Implementación iterativa (no recursiva)
// Mi solución, no sé si está bien (probablemente si)
info_nodo<T> * Buscar(info_nodo<T>*n, const T &x) {

    tmp = n;
    bool final = false;

    while (x != tmp && final == false)
    {
        if (tmp == nullptr)
            final = true;
        else if (x < tmp)
            tmp = n->hijoq;
        else if (x > tmp)
            tmp = n->hijoq;
    }
    
    return tmp;
}


// Algoritmo para insertar elemento - Implementación iterativa (no recursiva)
// muy complicado, me he perdido copiándolo

// Algoritmo para borrar un elemento de un ABB


// Si el nodo a borrar es un nodo hoja:
info_nodo<T> *aux = n;      // n es el nodo del que queremos borrar (lo hemos encontrado antes usando el algoritmo de búsqueda)

if (aux->padre != nullptr)  // si n es el hijo a la derecha de su padre, borra el hijo a la derceha de su padre
{
    aux->padre->hder = nullptr;
}
else                        // si n es el hijo a la izquierda borramos el hijo a la izquierda de su padre
{
    aux->padre->hizq = nullptr;
}
delete aux;


// Si el nodo a borrar no es un nodo hoja pero solo tiene un hijo a la derecha
// (para solo un hijo a la izquierda es solo cambiar 4 cosas)
info_nodo<T> *padre = n->padre;
if (padre != nullptr)
{
    if (padre->hder == n)       // Si el nodo a borrar es el hijo a la derecha de su padre
    {
        padre->hder = n->hder;
        n->hder->padre == padre;
    }
    else                        // Si el nodo a borrar es el hijo a la izquierda de su padre
    {
        padre->hizq = n ->hizq;
        n->hizq->padre = padre;
    }
}


// Si el nodo a borrar tiene hijos a izquierda y derechha
// Ver diapositivas


// ARBOLES BALANCEADOS/EQUILIBRADOS
// Se dice que un arbol está equilibrado cuando ninguno de sus nodos tiene una diferencia
// de altura entre sus hijos mayor que 1.
// Es decir, si un nodo tiene un hijo que tiene altura 7 (7 niveles) y otro que tiene 5 no 
// está balanceado, pero si tuviese 6 si.

// En cuanto a la implementación es igual que los ABB en todo excepto que en el infonodo añadimos la altura

// INSERCIÓN
// Es todo igual solo que comprobar si tras la rotación se ha desbalanceado y si es así arreglarlo

// BALANCEAMIENTO
// Se pueden dar 4 casos:
//      - A: El desbalanceo está en el hijo a la izquierda del hijo a la izquierda <- Easy
//      - B: El desbalanceo está en el hijo a la derecha del hijo a la izquierda   <- Difficult
//      - C: El desbalanceo está en el hijo a la izquierda del hijo a la derecha   <- Difficult
//      - D: El desbalanceo está en el hijo a la derecha del hijo a la derecha     <- Easy

// Solución al caso A
// Para rotar a la derecha.
//      - Hijo a la derecha del que queremos rotar pasa a ser hijo a la izquierda del hijo a la derecha del que queremos rotar

// Solución al caso D
// Para rotar a la izquierda
//      - Hizo a la izquierda del que queremos rotar pasa a ser hijo a la derecha del hijo a la izquierda del que queremos rotar

// Solución al caso C
// 1. Se hace una rotación a la derecha sobre el hijo a la derecha del nodo problemático
// 2. Se hace una rotación a la izquierda sobre el nodo problemático

// Solución al caso B
// 1. Se hace una rotación a la izquierda sobre el hijo a la izquirda del nodo problemático
// 2. Se hace una rotación a la derecha sobre el nodo problemático

// EJERCICIO: Construir el AVL Con las siguientes claves {1,2,3,4,5,6,7,15,14,13,12,11,10,9}.
// Cuando haya que aplicar rotaciones especificar el tipo de rotación que se debe realizar


// Función para comprobar si es ABB
bool is_ABB(ArbolBinario<int> & ab){
    retrun is_ABB_n(ab.getraiz());
}

bool is_ABB_N(ArbolBinario<int>::nodo n){
    if (n.null())
    {
        return true;
    }
    else
    {
        int max = Maximo(n.hizq());
        int min = Minimo(n.hder());
        if (!n.hizq().null() && *n < *(n.hizq()))
            return false;
        if (!n.hder().null() && *n > (*(n.der())))
            return false;
        
        return is_ABB_n(n.hizq()) && is_ABB_n(n.hder());
        
    }
    
    // Versión 2
    if (n.null())
        return true;
    else if (!(*n) > min && *n <max)
        return false;
    else
        
}



int Maximo(ArbolBinario<int>::nodo n){
    if (n.null())
        return numeric_limit<int>::min();

    if (n.hizq().null() && n.hder().null())
    {
        return * n;
    }
    else
    {
        int mi = Maximo (n.hizq());
        int md = Maximo (n.der());
        int max = *n;
        if (max < mi)
        {
            max = mi
        }
        if (max < md)
        {
            max = md;
        }
        
        return max;
    }
    
}