 /**
  * @file imageIO.cpp
  * @brief Fichero con definiciones para la E/S de imágenes
  *
  * Permite la E/S de archivos de tipo PGM,PPM
  *
  */
#include <string>
#include <iostream>
#include <fstream>
#include <imageIO.h>
using namespace std;

ImageKind ReadKind(ifstream& f){
  char c1,c2;
  ImageKind res= IMG_UNKNOWN;

  if (f){
    c1=f.get();
    c2=f.get();
    if (f && c1=='P')
      switch (c2) {
        case '5': res= IMG_PGM; break;
        case '6': res= IMG_PPM; break;
        default: res= IMG_UNKNOWN;
      }
  }
  return res;
}

// _____________________________________________________________________________

ImageKind ReadImageKind(const char *nombre){
  ifstream f(nombre);
  return ReadKind(f);
}


// _____________________________________________________________________________

char SkipWhitespaces (ifstream& f){
  char c;
  do{
    c= f.get();
  } while (isspace(c));
  f.putback(c);
  return c;
}

// _____________________________________________________________________________

bool ReadHeader (ifstream& f, int& rows, int& cols){
    int maxvalor;
    string linea;

    // Salta los comentarios
    while (SkipWhitespaces(f) == '#')
      getline(f,linea);

    //Lee las dimensiones y el maxvalor
    f >> cols >> rows >> maxvalor;
    
    // No sé qué hace
    if (/*str &&*/ f && rows>0 && rows<5000 && cols>0 && cols<5000){
        f.get(); // Saltamos separador
        return true;
    }
    else 
      return false;
}



// _____________________________________________________________________________

unsigned char *ReadPGMImage (const char *path, int& rows, int& cols){
  unsigned char *res=0;
  rows=0;
  cols=0;
  ifstream f(path);
  
  if (ReadKind(f) == IMG_PGM){
    if (ReadHeader(f, rows, cols)){
      res= new unsigned char[rows*cols];
      f.read(reinterpret_cast<char *>(res),rows*cols);
      if (!f){
        delete[] res;
        res= 0;
      }
    }
  }
  return res;
}

// _____________________________________________________________________________

bool WritePGMImage (const char *nombre, const unsigned char *datos,
                    const int rows, const int cols){
  ofstream f(nombre);
  bool res= true;
  
  if (f){
    f << "P5" << endl;
    f << cols << ' ' << rows << endl;
    f << 255 << endl;
    f.write(reinterpret_cast<const char *>(datos),rows*cols);
    if (!f)
      res=false;
  }
  return res;
}

/*
// Lee los dos priemros argumentos de un programa y los almacena como origen y destino
void ReadOrignDest(int argc, char **&argv, char *&origin, char *&dest, Image &img)
{
  // Comprobar validez de la llamada
  if (argc >= 3){
    cerr << "Error: Numero incorrecto de parametros.\n";
    cerr << "Uso: negativo <FichImagenOriginal> <FichImagenDestino>\n";
    exit (1);
  }

  // Obtener argumentos
  origin  = argv[1];
  dest = argv[2];

  // Mostramos argumentos
  cout << endl;
  cout << "Fichero origen: " << origin << endl;
  cout << "Fichero resultado: " << dest << endl;

  // Leer la imagen del fichero de entrada
  if (!img.Load(origin)){
    cerr << "Error: No pudo leerse la imagen." << endl;
    cerr << "Terminando la ejecucion del programa." << endl;
    exit(1);
  }

  // Mostrar los parametros de la Imagen
  cout << endl;
  cout << "Dimensiones de " << origin << ":" << endl;
  cout << "   Imagen   = " << img.get_rows()  << " filas x " << img.get_cols() << " columnas " << endl;

}
*/
/* Fin Fichero: imagenES.cpp */

