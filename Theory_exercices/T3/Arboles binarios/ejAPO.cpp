list<int> caminodemenores( conts bintree<int> &1){
    return cm_node(A.getraiz()).first();
}

pair<list<int>,int> cm_node (const bintree<int>::node n)
{
    if(n.null())
        retrun make_pair(list<int>(), 0);
    else{
        pair<list<int>, int> izq, der;
        izq = cm_node(n.hizq());
        der = cm_node(n.chder());

        if()
    }
}