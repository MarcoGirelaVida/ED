#include "imagenES.h"
#include "imagen.h"
#include <iostream>
#include <cassert>
#include <cmath>
#include <cmath>
using namespace std;


  void Imagen::Borrar(){

    nf = 0;
    nc = 0;
    delete[] data;
    data = nullptr;
  }


  void Imagen::Copiar(const Imagen & I)
  {
    nf = I.nf;
    nc = I.nc;

    data = new Pixel*[nf];
    for (size_t i = 0; i < nf; i++)
    {
      data[i]=new Pixel[nc];
      for (int j=0;j<nc;j++){
        (*this)(i,j).r=I(i,j).r;
        (*this)(i,j).g=I(i,j).g;
        (*this)(i,j).b=I(i,j).b;
        (*this)(i,j).transp=I(i,j).transp;
      }
    }
  }

  Imagen::Imagen()
  {
    nf = 0;
    nc = 0;
    data = nullptr;
  }





  Imagen::Imagen(int f,int c)
  {
    nf = f;
    nc = c;
    data = new Pixel*[nf];
    for (size_t i = 0; i < nf; i++)
    {
      data[i]=new Pixel[nc];
      for (int j=0;j<nc;j++){
        (*this)(i,j).r=255;
        (*this)(i,j).g=255;
        (*this)(i,j).b=255;
        (*this)(i,j).transp=255;
      }
    }  
  }


  Imagen::Imagen(const Imagen & I)
  {
    // Constructor de copia

    //Copio filas y columnas
    nf = I.num_filas();
    nc = I.num_cols();


    // Reservo memoria y copio los datos
    data = new Pixel*[nf];
      for (size_t i = 0; i < nf; i++)
        data[i] = new Pixel[nc];

    Copiar(I);
  }



 Imagen & Imagen::operator=(const Imagen & I)
 {
      if (this != &I) { // Evita la autoasignación
          // Libero la memoria actual
          Borrar();
          Copiar(I);
      }
      return *this; // Permite encadenar asignaciones (a = b = c)
  }

  Imagen::~Imagen()
  {
    for (size_t i = 0; i < nf; i++)
      delete[] data[i];

    delete[] data;
  }

  /**********************************************/
  Pixel & Imagen::operator()(int i,int j)
  {
    assert(i >= 0 && i < nf && j >= 0 && j < nc);
    return data[i][j];
  }

  /**********************************************/
  const Pixel & Imagen::operator()(int i,int j) const
  {
    assert(i >= 0 && i < nf && j >= 0 && j < nc);
    return data[i][j];
  }

  /***********************************************/

  void Imagen::EscribirImagen(const char * nombre, bool getMascara){
        unsigned char * aux = new unsigned char [nf*nc*3];
        unsigned char * m = new unsigned char [nf*nc];
        
        int total = nf * nc * 3;
        for (size_t i = 0; i < total; i += 3)
        {
          int posi = i / (nc * 3);
          int posj = (i % (nc * 3)) / 3;
          
          aux[i]=(*this)(posi,posj).r;
          aux[i+1]=(*this)(posi,posj).g;
          aux[i+2]=(*this)(posi,posj).b;
          m[i/3]=(*this)(posi,posj).transp;
        
        }    
    
        if (!EscribirImagenPPM (nombre, aux, nf, nc))
          cerr<<"Ha habido un problema en la escritura de "<<nombre<<endl;
        delete[]aux;

        if(getMascara){
          string n_aux = "mascara_";
          n_aux =n_aux+nombre;
          std::size_t found =n_aux.find(".ppm");
          if (found!=std::string::npos){
            n_aux =n_aux.substr(0,found);
          }
          n_aux =n_aux+".pgm";

          
          if (!EscribirImagenPGM (n_aux.c_str(), m,nf,nc)){
            cerr<<"Ha habido un problema en la escritura de "<<n_aux<<endl;
          }	    
          delete []m;
        }
      
  }  
  /*********************************/
void Imagen::LeerImagen(const char * nombre,const string &nombremascara)
{
      int f, c;
      unsigned char * aux,*aux_mask ;
      
      LeerTipoImagen(nombre, f, c);
      aux = new unsigned char [f * c * 3];
      LeerImagenPPM (nombre, f, c, aux);
      if (nombremascara != "")
      {
        int fm,cm;
        LeerTipoImagen(nombremascara.c_str(), fm, cm);
        aux_mask = new unsigned char [fm * cm];
        LeerImagenPGM(nombremascara.c_str(), fm, cm, aux_mask);
      }
      else
	      aux_mask=0;
      
      
      Imagen I(f,c);
      int total = f*c*3;
      for (size_t i = 0; i < total; i += 3)
      {
        int posi = i / (c * 3);
        int posj = (i % (c * 3)) / 3;
      //   cout<<posi<<" " <<posj<<endl;
          I(posi,posj).r=aux[i];
          I(posi,posj).g=aux[i+1];
          I(posi,posj).b=aux[i+2];
          if (aux_mask!=0)
            I(posi,posj).transp=aux_mask[i/3];
          else  
            I(posi,posj).transp=255;
	    }
 
      *this = I;

      if (aux_mask != 0)
        delete[] aux_mask;
      delete []aux;

      
}	


  /*********************************/
  void Imagen::LimpiarTransp(){


  
  
  
  // No se usa, no es necesario implementarlo
  
  
  
  
  }
 /*********************************/

  void Imagen::PutImagen(int posi,int posj, const Imagen &I,Tipo_Pegado tippegado){
      assert(nf>=posi+I.nf && nc>=posj+I.nc);
      
      posi-=I.nf/2;
      posj-=I.nc/2;

      for (int i=0;i<I.nf;i++)
        for (int j=0;j<I.nc;j++)
          if (i+posi>=0 && i+posi<nf && j+posj>=0 && j+posj<nc){
            if (I(i,j).transp!=0){
              if (tippegado==OPACO)
                (*this)(i+posi,j+posj)=I(i,j);
              else{
                (*this)(i+posi,j+posj).r=((*this)(i+posi,j+posj).r+I(i,j).r)/2;
                (*this)(i+posi,j+posj).g=((*this)(i+posi,j+posj).r+I(i,j).g)/2;
                (*this)(i+posi,j+posj).b=((*this)(i+posi,j+posj).r+I(i,j).b)/2;
              }  
            }  
          }	
        
  }

 /*********************************/
 Imagen Imagen::ExtraeImagen(int posi, int posj, int dimi,int dimj){

  
  Imagen aux = Imagen(dimi, dimj);

  for (int i=posi; i<dimi; i++){
    for (int j=posj; j<dimj; j++){
      aux(i-posi,j-posj).r = (*this)(i,j).r;
      aux(i-posi,j-posj).g = (*this)(i,j).g;
      aux(i-posi,j-posj).b = (*this)(i,j).b;
      aux(i-posi,j-posj).transp = (*this)(i,j).transp;
    }
  }

  return aux;
 }
  /*********************************/

  void Imagen::Rota(const Imagen & Io,double angulo){
    double rads=angulo;
    double coseno = cos(angulo);
    double seno = sin(angulo);
    //Para obtener las dimensiones de la imagen
    int rcorners[4],ccorners[4];
    int newimgrows,newimgcols;
    double new_row_min,new_col_min,new_row_max,new_col_max;
    double inter,inter1;
    rcorners[0]=0;
    rcorners[1]=0;
    ccorners[0]=0;
    ccorners[2]=0;
    rcorners[2]=Io.num_filas()-1;
    rcorners[3]=Io.num_filas()-1;
    ccorners[1]=Io.num_cols()-1;
    ccorners[3]=Io.num_cols()-1;
    new_row_min=0;
    new_col_min=0;
    new_row_max=0;
    new_col_max=0;
    newimgrows=0;
    newimgcols=0;
    for(int count=0;count<4;count++)
    {
	    inter=rcorners[count]*coseno+ccorners[count]*seno;
	   
	    if(inter<new_row_min)
		    new_row_min=inter;
	    if(inter>new_row_max)
		    new_row_max=inter;
	    inter1=-rcorners[count]*seno+ccorners[count]*coseno;
	   
	    if(inter1<new_col_min)
		    new_col_min=inter1;	
	    if(inter1>new_col_max)
		    new_col_max=inter1;
   }
    
    newimgrows=(unsigned)ceil((double)new_row_max-new_row_min);
    newimgcols=(unsigned)ceil((double)new_col_max-new_col_min);
   
    Imagen Iout(newimgrows,newimgcols);
    for(int rows=0;rows<newimgrows;rows++)
      {
	for(int cols=0;cols<newimgcols;cols++)
	{
	   float oldrowcos=((float)rows+new_row_min)*cos(-rads);
	   float oldrowsin=((float)rows+new_row_min)*sin(-rads);
	   float oldcolcos=((float)cols+new_col_min)*cos(-rads);
	   float oldcolsin=((float)cols+new_col_min)*sin(-rads);
	   float old_row=oldrowcos+oldcolsin;
	   float old_col=-oldrowsin+oldcolcos;
	   old_row=ceil((double)old_row);
	   old_col=ceil((double)old_col);
	   if((old_row>=0)&&(old_row<Io.num_filas())&&
	      (old_col>=0)&&(old_col<Io.num_cols()))
	   {
	      Iout(rows,cols)=Io(old_row,old_col);
              
	   }
	   else{
	     Iout(rows,cols).r=Iout(rows,cols).g=Iout(rows,cols).b=255;
       Iout(rows,cols).transp=0;
     }
       
	}
    }
    *this = Iout;
	  
}
