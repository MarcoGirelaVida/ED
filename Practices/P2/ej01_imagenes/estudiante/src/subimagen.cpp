// Fichero: negativo.cpp
// Calcula el negativo de una imagen PGM
//

#include <iostream>
#include <cstring>
#include <cstdlib>

#include <image.h>

using namespace std;

int main (int argc, char *argv[])
{
    char *origen, *destino; // nombres de los ficheros
    Image image;
    Image cropped;

    // Comprobar validez de la llamada
    if (argc != 7){
    cerr << "Error: Numero incorrecto de parametros.\n";
    cerr << "Uso: negativo <FichImagenOriginal> <FichImagenDestino> <nrow> <ncol> <height> <width>\n";
    exit (1);
    }

    // Obtener argumentos
    origen  = argv[1];
    destino = argv[2];
    int nrow = stoi(argv[3]);
    int ncol = stoi(argv[4]);
    int height = stoi(argv[5]);
    int width = stoi(argv[6]);

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

    cropped = image.Crop(nrow, ncol, height, width);

    // Guardar la imagen resultado en el fichero
    if (cropped.Save(destino))
    cout  << "La imagen se guardo en " << destino << endl;
    else{
    cerr << "Error: No pudo guardarse la imagen." << endl;
    cerr << "Terminando la ejecucion del programa." << endl;
    return 1;
    }

    return 0;
}
