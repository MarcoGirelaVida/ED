/**
 * @file imageop.cpp
 * @brief Fichero con definiciones para el resto de métodos de la clase Image
 */

#include <iostream>
#include <cmath>
#include <image.h>

#include <cassert>

bool Image::ValidSection(int &nrow, int &ncol, int &height, int &width) const
{
    bool result = true;

    if (!ValidRow(nrow) && !ValidCol(ncol))
        result = false;
    else if (!ValidRow(nrow) || !ValidRow(nrow+height))
    {
        if (nrow > get_rows())
            nrow = get_rows();
        else if (nrow+height > get_rows())
            height = get_rows()-nrow;
        else if (nrow < 0)
            nrow = 0;
    }
    else if (!ValidCol(ncol) || !ValidCol(ncol+width))
    {
        if(ncol > get_cols())
            ncol = get_cols();
        else if (ncol+width > get_cols())
            width = get_cols()-ncol;
        else if (ncol < 0)
            ncol = 0;
    }
    
    return result;
        

}

// 1. Genera una subimagen
Image Image::Crop(int nrow, int ncol, int height, int width) const
{
    //---Calculo las dimensiones que tendrá la imagen resultado---
    assert (ValidSection(nrow, ncol, height, width));
    unsigned int rows_cropped = nrow + height,
                cols_cropped = ncol + width;

    // Creo la imagen que contedrá la imagen recortada
    Image cropped_image(rows_cropped, cols_cropped);

    // Copio los datos del segmento de la imagen original a la
    // imagen recortada.
    for (size_t i = 0; i < rows_cropped; i++){
        for (size_t j = 0; j < cols_cropped; j++)
            cropped_image.set_pixel(i, j, get_pixel(i+nrow,j+ncol));
    }
    
    return cropped_image;
}

// Calcula la media de los píxeles de una imagen entera o de un fragmento de ésta.
double Image::Mean (int i, int j, int height, int width) const
{
    assert(ValidSection(i, j, height, width));
    // Declaro la sumatoria y la submatriz de la que calcular la media
    int sum = 0;

    // Sumo los valores de todos los píxeles
    for (size_t f = i; f < height; f++){
        for (size_t c = j; c < width; c++)
            sum += get_pixel(f,c);
    }
    
    // Devuelvo la media
    return sum/((float)(i+height)*(j+height));

    /*
    OPCIÓN 2, más ineficiente, pero quizás más modular
    // Declaro la sumatoria y la submatriz de la que calcular la media
    int sum = 0;
    Image cropped = Crop(i,j,height,width);
    int cropped_dimension = cropped.get_rows()*cropped.get_cols();

    // Sumo los valores de todos los píxeles
    for (size_t f = 0; f < cropped.get_rows(); f++){
        for (size_t c = 0; c < cropped.get_cols(); c++)
            sum += get_pixel(f,c);
    }
    
    // Devuelvo la media
    return sum/((float)cropped_dimension);
    
    */
}

// 2. Genera una imagen aumentada 2x.
Image Image::Zoom2X() const
{
    // Calculo la resolución de la imagen zoomeada
    unsigned int zoomed_rows = 2*get_rows() - 1,
                zoomed_cols = 2*get_cols() - 1,
                zoomed_res = zoomed_rows*zoomed_cols;

    // Creo la imagen producto vacía con la resolución calculada
    Image zoomed(zoomed_rows, zoomed_cols);

    // Relleno la matriz original
    // Un pixel será inventado siempre que el valor de su columna
    // o fila sea par
    size_t i_original = 0;
    for (size_t i = 0; i < zoomed_rows; i = i++){
        for (size_t j = 0; j < zoomed_cols; j = j++)
        {
            // Si alguno de los dos es impar,
            // será un pixel inventado
            if (i%2 || j%2)
            {
                double mean;
                // Si los dos valores son impares, será la media de los 4 que lo rodean
                if (i%2 && j%2)
                    mean = Mean(i/2, j/2, 1, 1);
                // Si el valor de la fila es par pero las columnas no,
                // será la media de las dos columnas consecutivas
                else if (!(i%2) && j%2)
                    mean = Mean(i/2, j/2, 0, 1);

                else // Sino será la media de las filas consecutivas
                    mean = Mean(i/2, j/2, 1, 0);

                zoomed.set_pixel(i,j,mean);
            }
            else //Sino es un pixel real
            {
                zoomed.set_pixel(i,j,get_pixel(i_original));
                i_original++;
            }
        }
    }

    return zoomed;
}

//3.  Genera un icono como reducción de una imagen
Image Image::Subsample(int factor) const
{

}

// 4. Modifica el contraste de una imagen
void Image::AdjustContrast(byte in1, byte in2, byte out1, byte out2)
{

}


void ShuffleRows()
{

}