#include "Ruta.h"
#include <string>
#include <list>
#include <iostream>
#include <cmath>

using namespace std;

void Ruta::Insertar (const Punto & n){

    puntos.push_back(n);

}

void Ruta::Borrar(const Punto & n){

    puntos.remove(n);

}

string Ruta::GetCode()const{

    return code;

}

void Ruta::SetCode(const string & code){

    this->code = code;

}




void Ruta::PintarAviones(int f1,int f2,int c1,int c2,Imagen &I, const Imagen &avion,int mindisf,int mindisc){
      
    int fila,col;
    if (abs(f2-f1)>=mindisf || abs(c2-c1)>=mindisc){ 
	
        if (c1!=c2){
            double a,b;
            a= double(f2-f1)/double(c2-c1);
            b= f1-a*c1;
            col = (int)(c1+c2)/2;
            fila = (int)rint(a*col+b);
        }  
        else{
            col = c1;
            fila = (f1+f2)/2;
        }  
    
	  
        double angulo = atan2((f2-f1),(c2-c1));
        Imagen Irota;
        Irota.Rota(avion,angulo);
        
        I.PutImagen(fila,col,Irota);//pensar si debe ser opaco o blending
        
        angulo = atan2((f2-fila),(c2-col));
        Irota.Rota(avion,angulo);
        
        I.PutImagen(f2,c2,Irota);//pensar si debe ser opaco o blending
        angulo = atan2((fila-f1),(col-c1));
        Irota.Rota(avion,angulo);
        
        I.PutImagen(f1,c1,Irota);//pensar si debe ser opaco o blending
	
    }
     
}  










Imagen Ruta::PintarRuta(const Imagen & mapa, Paises & paises, const string FlagPath, const Imagen & avion){

    iterator it1 = begin();
    iterator it2 = begin(); ++it2;

    Imagen out = Imagen(mapa);

    while (it2 != end()){ // mientras no lleguemos al fin

        // Buscamos el pais que corresponde al punto 1
        Pais pais1 = *(paises.find((*it1)));
        Pais pais2 = *(paises.find((*it2)));

        Imagen im_pais_1, im_pais_2, im_avion;
        im_pais_1.LeerImagen((FlagPath + '/' + pais1.GetBandera()).c_str());
        im_pais_2.LeerImagen((FlagPath + '/' + pais2.GetBandera()).c_str());

        pair<double,double> pos1_mapa, pos2_mapa;
        pos1_mapa.first = (mapa.num_filas()/180.0)*(90-(*it1).GetLatitud());
        pos1_mapa.second = (mapa.num_cols()/360.0)*(180+(*it1).GetLongitud());

        pos2_mapa.first = (mapa.num_filas()/180.0)*(90-(*it2).GetLatitud());
        pos2_mapa.second = (mapa.num_cols()/360.0)*(180+(*it2).GetLongitud());

        PintarAviones(pos1_mapa.first, pos2_mapa.first, pos1_mapa.second, pos2_mapa.second, out, avion, 0, 0);


        // Pegamos las imagenes de los mapas
        out.PutImagen(pos1_mapa.first,pos1_mapa.second,im_pais_1);
        out.PutImagen(pos2_mapa.first,pos2_mapa.second,im_pais_2);

        ++it1;
        ++it2;

    }

    return out;

}

bool Ruta::operator==(const Ruta & R)const{

    return (puntos == R.puntos && code == R.code);
}

bool Ruta::operator<(const Ruta &R)const{

    return (puntos.size() < R.puntos.size());
}

Ruta::iterator Ruta::begin(){
    iterator it;
    it.p = puntos.begin();
    return it;
}  

Ruta::const_iterator Ruta::begin()const{
    const_iterator it;
    it.p = puntos.cbegin();
    return it;
}

Ruta::iterator Ruta::end(){
    iterator it;
    it.p = puntos.end();
    return it;
}
Ruta::const_iterator Ruta::end()const{
    const_iterator it;
    it.p = puntos.cend();
    return it;
}

Ruta::iterator Ruta::find(const Punto &p){
    
    iterator it;
    list<Punto>::iterator i;
    for (i=puntos.begin(); i!=puntos.end() && !((*i) == p); ++i)
        it.p=i;
    return it;
}

istream & operator>>(istream & is, Ruta & R){
    
    int numPuntos;
    is >> R.code;
    is >> numPuntos;

    for (int i=0; i<numPuntos; i++){
        Punto p_aux;
        is >> p_aux;
        R.puntos.emplace_back(p_aux);
    }
    
    return is;
}

ostream & operator<<(ostream & os, const Ruta &R){

    os << R.code << " " << R.puntos.size() << " ";

    Ruta::const_iterator it;
    for (it = R.begin(); it != R.end(); ++it){
        os << (*it);
        os << " ";
    }

    return os;

}