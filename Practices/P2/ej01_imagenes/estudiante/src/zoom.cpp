/**
 * @file zoom.cpp
 * @brief Amplía por dos la resolución de una sección de una imagen dada
*/

#include <iostream>
#include <cstring>
#include <cstdlib>

#include <image.h>

using namespace std;

int main (int argc, char *argv[])
{
  char *origen, *destino; // nombres de los ficheros
  Image image, zoomed;

  // Comprobar validez de la llamada
  if (argc != 6){
    cerr << "Error: Numero incorrecto de parametros.\n";
    cerr << "Uso: negativo <FichImagenOriginal> <FichImagenDestino> <fila> <cola> <lado>\n";
    exit (1);
  }

  // Obtener argumentos
  origen  = argv[1];
  destino = argv[2];
  int row = stoi(argv[3]);
  int col = stoi(argv[4]);
  int side = stoi(argv[5]);

  // Mostramos argumentos
  cout << endl;
  cout << "Fichero origen: " << origen << endl;
  cout << "Fichero resultado: " << destino << endl;

  // Leer la imagen del fichero de entrada
  if (!image.Load(origen)){
    cerr << "Error: No pudo leerse la imagen." << endl;
    cerr << "Terminando la ejecucion del programa." << endl;
    return 1;
  }

  // Mostrar los parametros de la Imagen
  cout << endl;
  cout << "Dimensiones de " << origen << ":" << endl;
  cout << "   Imagen   = " << image.get_rows()  << " filas x " << image.get_cols() << " columnas " << endl;

  // Recorta y amplia
  zoomed = image.Crop(row,col,side,side).Zoom2X();

  // Guardar la imagen resultado en el fichero
  if (zoomed.Save(destino))
    cout  << "La imagen se guardo en " << destino << endl;
  else{
    cerr << "Error: No pudo guardarse la imagen." << endl;
    cerr << "Terminando la ejecucion del programa." << endl;
    return 1;
  }


// TEST MEDIA
/*
    byte* buffer = new byte[4]{2, 2, 3, 3};

    Image test_mean;
    test_mean.Initialize(2, 2, buffer);

    cout << "Contenido de la imagen: " << endl;
    for (size_t i = 0; i < test_mean.get_rows(); i++)
    {
        for (size_t j = 0; j < test_mean.get_cols(); j++)
        {
            cout << static_cast<int>(test_mean.get_pixel(i,j)) << endl;
        }
    }
    cout << "Fin del contenido de la imagen" << endl << endl;
    
    cout << "La media del cuadrado es: " << test_mean.Mean(0,0,2,2) << endl;
    cout << "La media de la primera fila es: " << test_mean.Mean(0,0,2,1) << endl;
    cout << "La media si me intento salir por abajo: " << test_mean.Mean(1,0,2,2) << endl;
    cout << "La si me intento salir por dos lados: " << test_mean.Mean(1,1,2,2) << endl;
    cout << "La si me intento salir del todo: " << test_mean.Mean(2,2,2,2) << endl;
*/
  return 0;
}
