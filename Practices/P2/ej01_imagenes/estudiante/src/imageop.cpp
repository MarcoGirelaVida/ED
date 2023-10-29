/**
 * @file imageop.cpp
 * @brief Fichero con definiciones para el resto de métodos de la clase Image
 */

#include <iostream>
#include <cmath>
#include <image.h>
#include <cassert>
using namespace std;

bool Image::ValidSection(const int nrow, const int ncol, const int height, const int width) const
{
    return ValidRow(nrow) && ValidCol(ncol) && ValidRow(nrow+height-1) && ValidRow(ncol+width-1);
}

// IMPORTANTE: No funciona si se pone un nrow/ncol negativo y un height/width > max_row/col_valid
// Lo arreglaría pero es un coñazo y no me parece tan importante :(
bool Image::ValidSectionSmart(int &nrow, int &ncol, int &height, int &width) const
{
    bool isValid = ValidSection(nrow, ncol, height, width);
    int max_col_valid = get_cols() - 1;
    int min_col_valid = 0;
    int max_row_valid = get_rows() - 1;
    int min_row_valid = 0;

    //DEBUG
    /*
    cerr << "PREPROCESADO" << endl;
    cerr << "Max row: " << get_rows() - 1 << endl;
    cerr << "Max col: " << get_cols() - 1 << endl;
    cerr << "Nrow: " << nrow << endl;
    cerr << "Ncol: " << ncol << endl;
    cerr << "Height: " << height << endl;
    cerr << "Width: " << width << endl;
    */

    if (!isValid)
    {
        if (!ValidRow(nrow))
            nrow = (nrow < 0) ? min_row_valid : max_row_valid;
        else
            height = max_row_valid - nrow + 1;

        if (!ValidCol(ncol))
            ncol = (ncol < 0) ? min_col_valid : max_col_valid;
        else
            width = max_row_valid - ncol + 1; 
    }
    
    if (!ValidSection(nrow, ncol, height, width))
    {
        cerr << "IRREPARABLE INVALID SECTION" << endl;
        cerr << "Max row: " << get_rows() - 1 << endl;
        cerr << "Max col: " << get_cols() - 1 << endl;
        cerr << "Nrow: " << nrow << endl;
        cerr << "Ncol: " << ncol << endl;
        cerr << "Height: " << height << endl;
        cerr << "Width: " << width << endl;
    }
    
    return ValidSection(nrow, ncol, height, width);
}

// 1. Genera una subimagen
Image Image::Crop(int nrow, int ncol, int height, int width) const
{
    //---Calculo las dimensiones que tendrá la imagen resultado---
    assert (ValidSectionSmart(nrow, ncol, height, width));
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
double Image::Mean (int nrow, int ncol, int height, int width) const
{
    assert(ValidSectionSmart(nrow, ncol, height, width));
    // Declaro la sumatoria y la submatriz de la que calcular la media
    int sum = 0;

    // Sumo los valores de todos los píxeles
    for (size_t i = nrow; i < height+nrow; i++){
        for (size_t j = ncol; j < width+ncol; j++)
            sum += get_pixel(i,j);
    }

    // Devuelvo la media
    return sum / static_cast<double>(height*width);
}

// 2. Genera una imagen aumentada 2x.
Image Image::Zoom2X() const
{
    // Creo la imagen producto vacía con la resolución calculada
    Image zoomed(2*get_rows(), 2*get_cols());

    // Relleno la matriz original
    for (size_t i = 0; i < zoomed.get_rows(); i++){
        for (size_t j = 0; j < zoomed.get_cols(); j++)
        {
            if (i%2 || j%2) // Si alguno de los dos es impar, será un pixel inventado
            {
                if (i%2 && j%2) // Si ambas son impares, será la media de los 4 que lo rodean
                    zoomed.set_pixel(i,j,Mean(i/2, j/2, 2, 2));

                else if (i%2 && !(j%2)) // Si la fila es impar pero la columnas no, será la media de las filas adyacentes
                    zoomed.set_pixel(i,j,Mean(i/2, j/2, 2, 1));

                else // Sino será la media de las columnas consecutivas
                    zoomed.set_pixel(i,j,Mean(i/2, j/2, 1, 2));
            }
            else //Sino es un pixel real
                zoomed.set_pixel(i,j,get_pixel(i/2,j/2));
        }
    }
    return zoomed;
}

//3.  Genera un icono como reducción de una imagen
Image Image::Subsample(int factor) const
{
    // Creo la imagen producto vacía con la resolución calculada
    int rows_icon = static_cast<int>(get_rows()/factor);
    int cols_icon = static_cast<int>(get_cols()/factor);
    Image icon(rows_icon, cols_icon);

    for (size_t i = 0; i < rows_icon; i++)
        for (size_t j = 0; j < cols_icon; j++)
            icon.set_pixel(i, j, round(Mean(i*factor, j*factor, factor, factor)));

    return icon;
}

// 4. Modifica el contraste de una imagen
void Image::AdjustContrast(byte in1, byte in2, byte out1, byte out2)
{
    double scalling_factor = (out2-out1)/(in2-in1);

    for (size_t i = 0; i < get_rows()*get_cols(); i++)
    {
        byte p = get_pixel(i);
        if (p > in1 && p < in2)
            set_pixel(i, round(out1+scalling_factor*(p-in1)));
    }
}


void Image::ShuffleRows()
{
    const int p = 9973;
    Image temp(rows, cols);
    int newr;

    for (size_t i = 0; i < rows; i++){
        newr = i*p % rows;
        for (size_t j = 0; j < cols; j++)
            temp.set_pixel(i,j,get_pixel(newr,j));
    }
    
    Copy(temp);
}
