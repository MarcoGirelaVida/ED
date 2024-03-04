#include <iostream>
#include <cassert>
#include "Punto.h"

using namespace std;


double Punto::GetLatitud()const{
    return latitud;
}

double Punto::GetLongitud()const{
    return longitud;
}

void Punto::SetLatitud(double l){
    latitud = l;
}

void Punto::SetLongitud(double l){
    longitud = l;
}


bool Punto::operator<(const Punto &p)const{

    if (GetLatitud() < p.GetLatitud()) {
        return true;
    } else if (GetLatitud() == p.GetLatitud() && GetLongitud() < p.GetLongitud()) {
        return true;
    } else {
        return false;
    }

}

bool Punto::operator==(const Punto &p)const{

    return ((GetLatitud() == p.GetLatitud()) && GetLongitud() == p.GetLongitud()); 
        
}

istream & operator>>(istream & is, Punto &p){
    char par1, coma, par2;
    is >> par1 >> p.latitud >> coma >> p.longitud >> par2;
    return is;
}

ostream & operator<<(ostream & os, const Punto &p){
    os << "(" << p.GetLatitud() << "," << p.GetLongitud() << ")";
    return os;
}