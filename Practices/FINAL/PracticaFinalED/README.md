# PracticaFinalED

## Programas a implementar

- Especificación de:
  - Punto
  - Ruta
  - Almacen de Rutas
  - Imagen
- Definir operacionse
- Usar STL
- Decidir que TDA es el más adecuado en cada caso
- Decidir a que inicializar un byte "nulo" al hacer el load especial

### Rotar Imagen

(
    - Operador ()
    - Métodos .r .g .b
)

- Parametros

### Pegar

(
    - Contructor con máscara
)

- Los pasos que salen en la guia
- La máscara debe tener las mismas dimensiones que la imagen base

### Ruta aerea

- Los argumetos proporcionados:
  - Lita_paises.txt
  - mapa.ppm
  - Directorio donde están las imagenes de las banderas
  - almacenrutas.txt
  - avion.pgm
  - mascaraavion.pgm
- Procedimiento
    1. Printea almacenrutas.txt
    2. El usuario elige cual quiere
    3. Se almacena imagen cuyo nombre del fichero es el código de la ruta
       1. En la imagen se pinta en cada pais por donde pasa, un avion
       2. Y entre ambos puntos otro avion
    4. Printea la secucencia de paises por donde pasa
    5. (Aplicar la formula para pasar de latitud/longitud a un pixel)

## Imagenes

Tres tipos:
    - Blanco/negro
    - Escala de grises
    - RGB
    - MIX imagen-mascara (puede ser un RGB con caracteres nulos)

## Ficheros

### Fichero de entrada

- "#Rutas"
- Ruta/linea
- ["#Puntos_de_interes" endl PuntoInteres/Linea] 

### Ruta

- Codigo de la ruta ("R5")
- Puntos separados por espacios

### Punto

- "(Latitud, Lonsgitud)"

### Paises

(como un csv pero con espacios en blanco)

- ITERATOR DE IMAGEN (basicamente el for con el k)

## Modulo Pais/ses

- TDA Pais
  - Punto geogrfico asociado
  - Nombre
  - Bandera
- TDA Paises (set paises)
- Clase Punto
- clase Rutas
- Clase Almacén de Rutas

## Dudas

- Uso herencia para los tipos de imagenes? O templates?
- No deberíamos usar algo de eso? Sino como representamos las imagenes en blaco y negro, con la implementaciones de las diapositivas no es posible
- A que inicializar un byte "nulo" al hacer el load con máscara
- Se pueden repetir paises en una ruta?
- Rotate no debería ir en el propio image
- Pasa algo si pongo las implementaciones de la práctica anterior
- Pasa algo si hago mis propias implementaciones distintas a las de las diapositivas
- Pasa algo si lo pongo en inglés
- Hace falta implementar "limpiartransparencia"