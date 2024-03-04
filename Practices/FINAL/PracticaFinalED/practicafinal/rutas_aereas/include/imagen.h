/**
 * @file imagen.h
 * @brief Cabecera para la clase Image  
 */
#ifndef _IMAGEN_H_
#define _IMAGEN_H_

#include <iostream>
using namespace std;

/**
 * @brief Enum que representa el tipo de pegado que se aplicará  
 * Opaco implica que se pega tal cual encima.  
 * Blending implica que se pega con una capa de trasparecia sobre la imagen.  
*/
enum Tipo_Pegado {OPACO, BLENDING};

/**
 * @brief T.D.A Pixel
 * Este biene representado por un struct de 4 bytes, tres de los cuales reprentan la intensidad de los colores rojo, verde y azul de dicho pixel y un carto que representa la transparenica.  
 * En el caso de los bytes de colores, 255 implica intensidad máxima y 0 mínima.  
 * Por otro lado, en el byte de transparencia, 0 es que no hay y 255 que sí.  
*/
struct Pixel{
  unsigned char r,g,b;
  unsigned char transp; //0 no 255 si
};  

/**
  @brief T.D.A. Imagen

  Una instancia del tipo de dato abstracto Imagen nos permite almacenar imágenes de intensidades.

  El TDA Imagen proporciona además distintas herramientas para la manipulación de dichas imágenes.

  Para poder usar el TDA Imagen se debe incluir el fichero

  \#include <Imagen.h>
**/
class Imagen{
/**
* @page page_repImagen Representación del TDA Imagen
* @section sec_Image_A Representación Tipo 1 (Actual)
* Dada una imagen de f filas y c columnas, está representada por:
* - _Pixel ** img_: Un puntero a un vector de punteros (Representa a la imagen completa)
* - _Pixel * filas[f]_ : Un vector con f punteros a bytes
* - _Pixel * m[f*c]_ : Un macro vector que almacena todos los bytes de la imagen secuencialmente
* Esta representación es preferible en aquellos casos en los que necesitamos operaciones que se apliquen secuencialmente sobre todos los píxeles de una imagen.
* @image html rep1.png "Rep 1"
* @section sec_Image_B Representación Tipo 2 (ej Barajar)
* Dada una imagen de f filas y c columnas, está representada por:
* - _Pixel ** img_ : Un puntero a un vector de punteros (La imagen completa)
* - _Pixel * filas[f]_ : Un vector con f punteros a vectores de píxeles (bytes)
* - _f Pixel * col[c]_ : f vectores de píxeles (bytes) con tamaño c (esto será cada columna)
* Esta representación es preferible en aquellos casos en los que hagamos operaciones directas sobre el orden de las filas de la imagen.
* @image html rep2.png "Rep 2"
*
* @section funcion_abstraccion Función de Abstracción (para tipo rep 1)
* Fa: _Pixel ** img_ -> imagen.png
* Fa: _img[n][m] -> pixel nxm de la imagen.png
*
* @section invariante Invariante de Representación
* Ir: {f ∈ N, c ∈ N}
**/

  private:
    /**
      @brief Puntero a la imagen almacenada

      img apunta a un array-2D dinámico de bytes que contiene la imagen en sí. Almacena tantos bytes como pixeles tenga la imagen.

    **/
    Pixel ** data;

    /**
      @brief Número de filas y columnas de la imagen.
    **/
    size_t nf,nc;

    /**
     * @brief Funcion para Borrardo.
     * @post Borra los datos de la imagen, que queda vacía.
    */
    void Borrar();

    /**
     * @brief Función de Copia
     * @param I Imagen fuente de donde se copia.
     * @post La imagen queda con los datos de la proporcionada como parámetro.
    */
    void Copiar(const Imagen & I);

  public:

    /**
    * @brief Constructor por defecto .
    * @post Genera una instancia de la clase Imagen con O filas y O colunmas.
    * @return Imagen, el objeto imagen creado.
    */
    Imagen();
    
    /**
    * @brief Constructor con parámetros.
    * @param nrows Número de filas de la imagen.
    * @param ncols Número de columnas de la imagen.
    * @pre n fils > O Y n_cols > O
    * @post La imagen creada es de n_fils y n_cols columnas. Estará inicializada a
    * @return Imagen, el objeto imagen creado.
    */
    Imagen(int f,int c);
    
    /**
    * @brief Constructor de copias.
    * @param I Referencia a la imagen original que se quiere copiar.
    * @return Imagen, el objeto imagen creado.
    */
    Imagen(const Imagen & I);
    
    /**
    * @brief Operador de asignación .
    * @param orig Referencia a la imagen original que desea copiarse.
    * @return Una referencia al objeto imagen modificado.
    * @post Destroy cualquier información que contuviera previamente la imagen que llama al operador de asignación.
    */
    Imagen & operator=(const Imagen & I);
    
    /**
    * @brief Operador de tipo destructor.
    * @post El objeto Imagen destruido no puede usarse salvo que se haga sobre él una operacion Imagen().
    */
    ~Imagen();
    
    /**
    * @brief Consulta el valor del píxel (fil, col) de la imagen.
    * @param i Fila de la imagen en la que se encuentra el píxel a consultar.
    * @param j Columna de la imagen en la que se encuentra el píxel a consultar.
    * @pre O <= fil < I.Num_ Filas() II O <= col < I.Num Columnas()
    * @return referencia al valor del píxel contenido en (fil,col)
    * @post La imagen no se modifica pero puede modificarse
    * @post Si el pixel solicitado está fuera de rango se proporciona el pixel de la imagen más cercano disponible
    */
    Pixel & operator ()(int i,int j);
    
    /**
    * @brief Consulta el valor del píxel (fil, col) de la imagen.
    * @param i Fila de la imagen en la que se encuentra el píxel a consultar.
    * @param j Columna de la imagen en la que se encuentra el píxel a consultar.
    * @pre O <= fil < I.Num_ Filas() II O <= col < I.Num Columnas()
    * @return referencia al valor del píxel contenido en (fil,col)
    * @post La imagen no se modifica y no puede modificarse
    * @post Si el pixel solicitado está fuera de rango se proporciona el pixel de la imagen más cercano disponible
    */
    const Pixel & operator ()(int i,int j)const;
    
    /**
    * @brief Almacena imágenes en disco.
    * @param file_path Ruta donde se almacenará la imagen.
    * @pre file path debe ser una ruta válida donde almacenar el fichero de salida.
    * @return Devuelve true si la imagen se almacenó con éxito y false en caso contrario.
    * @post La imagen no se modifica.
    */
    void EscribirImagen(const char * nombre, bool getMascara);
    
    /**
    * @brief Carga en memoria una imagen de disco .
    * @param file_path Ruta donde se encuentra el archivo desde el que cargar la imagen.
    * @pre @p file_path debe ser una ruta válida que contenga un fichero . pgm
    * @return Devuelve @b true si la imagen se carga con éxito y @b false en caso contrario.
    * @post La imagen previamente almacenada en el objeto que llama a la función se destruye.
    */
    void LeerImagen (const char *nombre,const string &nombremascara="");

    /**
     * @brief Limpia las transparencias de una imagen
    */
    void LimpiarTransp();

    /**
    * @brief Filas de la imagen .
    * @return El número de filas de la imagen.
    * @post la imagen no se modifica.
    */
    int num_filas()const{return nf;}

    /**
    * @brief Columnas de la imagen.
    * @return El número de columnas de la imagen.
    * @post la imagen no se modifica.
    */
    int num_cols()const{return nc;}

    /**
     * @brief Pegar imagen
     * @param posi Fila inicial donde pegar
     * @param posj Columna inicial donde pegar
     * @param I Imagen a pegar
     * @param tipopegado Tipo de pegado que se aplicará
     * @pre 0 <= @p nrow < filas
     * @pre 0 <= @p ncol < columnas
     * @pre 0 <= @p I.rows and @p I.rows + @p nrow <= filas
     * @pre 0 <= @p I.cols and @p I.cols + @p ncol <= columnas
     * @post La imagen queda modificada con la imagen proporcionada pegada
    */
    void PutImagen(int posi,int posj, const Imagen &I,Tipo_Pegado tippegado=OPACO);

    /**
     * @brief Genera una subimagen
     * @param nrow Fila inicial para recortar
     * @param ncol Columna inicial para recortar
     * @param height Número de filas
     * @param width Número de columnas
     * @pre 0 <= @p nrow < filas
     * @pre 0 <= @p ncol < columnas
     * @pre 0 <= @p height and @p height + @p nrow <= filas
     * @pre 0 <= @p width and @p width + @p ncol <= columnas
     * @note Si uno o varios parámetros no cumplen los requisitos se modificarán conforme la función @ref ValidSectionSmart "ValidSectionSmart"
     * @return Imagen con el recorte
     * @post El objeto que llama a la función no se modifica
    */
    Imagen ExtraeImagen(int posi,int posj,int dimi,int dimj);

    /**
     * @brief Rota una imagen con el ángulo dado
     * @param Io Imagen de origen que será rotada
     * @param angulo Angulo con el que será rotada la imagen
     * @post La imagen de origen quedará rotada.
    */
    void Rota(const Imagen & Io,double angulo);
};   


#endif