/**
 * @file barajar.cpp
 * @brief Recibe como parámetro el número de filas y columnas y muestra el tiempo en nanosegundos que tardaría en @b barajar una imagen con esas dimensiones
*/

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <chrono>

#include <image.h>

using namespace std;
using namespace std::chrono;

int main (int argc, char *argv[]){
 
  int num_filas, num_columnas;
  Image image;

  // Comprobar validez de la llamada
  if (argc != 3){
    cerr << "Error: Numero incorrecto de parametros.\n";
    cerr << "Uso: barajar <num_filas> <num_columnas>\n";
    exit (1);
  }

  // Obtener argumentos
  num_filas  = stoi(argv[1]);
  num_columnas = stoi(argv[2]);

  // Creo la imagen de prueba
  image = Image(num_filas, num_columnas);
  // Mostrar los parametros de la Imagen
  /*
  cout << endl;
  cout << "Dimensiones de la imagen de prueba:" << endl;
  cout << "   Imagen   = " << image.get_rows()  << " filas x " << image.get_cols() << " columnas " << endl;
  */
  time_point<steady_clock> instante_inicio = steady_clock::now();  // Mido los tiempos justo antes de ejecutar la función
  // Barajo las filas
  image.ShuffleRows();

  time_point<steady_clock> instante_final = steady_clock::now(); // Mido los tiempos justo despues de que ejecutar la función


  duration<float,micro> tiempo_total = instante_final - instante_inicio ;



  // Muestro el tiempo tomado en formato CSV num_filas, num_columnas, tiempo_total
  cout  << num_filas << "," << num_columnas << "," << tiempo_total.count() << endl;

  return 0;
}
