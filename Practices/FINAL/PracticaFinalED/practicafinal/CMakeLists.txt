cmake_minimum_required(VERSION 3.16)

# CMAKE_SOURCE_DIR es la carpeta donde se encuentra este fichero
# CMAKE_CURRENT_BINARY_DIR es donde se construyen el proyecto (donde se hace cmake), generalmente la carpeta "build"
# Define el nombre del proyecto
project(practicafinal)

add_compile_options(-Wall -Wextra)
set(CMAKE_CXX_STANDARD 14)

# Set the output directory for all executables
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/bin")
# Set the output directory for all libraries
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/lib")

#Define cual es la carpeta base del proyecto
set(BASE_FOLDER rutas_aereas)

# Define cuales son los directorios include (rutas_aereas/include)
include_directories(${BASE_FOLDER}/include)

# Genera librería imagen a partir de imagen.cpp e imagenES.cpp
# CAMBIO EN EL DIRECTORIO DE LOS FUENTES
add_library(imagen ${BASE_FOLDER}/src/imagen.cpp ${BASE_FOLDER}/src/imagenES.cpp)
add_library(paises ${BASE_FOLDER}/src/Pais.cpp ${BASE_FOLDER}/src/Paises.cpp ${BASE_FOLDER}/src/Punto.cpp ${BASE_FOLDER}/src/Ruta.cpp ${BASE_FOLDER}/src/Almacen_Rutas.cpp)
# Genera el ejecutable de X.cpp (si es que este fichero existe)
# E indica que depende de la libreria image
if (EXISTS ${CMAKE_SOURCE_DIR}/${BASE_FOLDER}/src/pruebarotacion.cpp)
    add_executable(pruebarotacion ${BASE_FOLDER}/src/pruebarotacion.cpp)
    target_link_libraries(pruebarotacion LINK_PUBLIC imagen)
endif()

if (EXISTS ${CMAKE_SOURCE_DIR}/${BASE_FOLDER}/src/pruebapegado.cpp)
    add_executable(pruebapegado ${BASE_FOLDER}/src/pruebapegado.cpp)
    target_link_libraries(pruebapegado LINK_PUBLIC imagen)
endif()

if (EXISTS ${CMAKE_SOURCE_DIR}/${BASE_FOLDER}/src/ruta_aerea.cpp)
    add_executable(ruta_aerea ${BASE_FOLDER}/src/ruta_aerea.cpp)
    target_link_libraries(ruta_aerea LINK_PUBLIC imagen paises)
endif()

# check if Doxygen is installed
find_package(Doxygen)
if (DOXYGEN_FOUND)
    # set input and output files
    set(DOXYGEN_IN ${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile.in)
    set(DOXYGEN_OUT ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile)

    # request to configure the file
    configure_file(${DOXYGEN_IN} ${DOXYGEN_OUT} @ONLY)
    message("Doxygen build started")

    # note the option ALL which allows to build the docs together with the application
    add_custom_target( doc_doxygen ALL
            COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_OUT}
            WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/${BASE_FOLDER}
            COMMENT "Generating API documentation with Doxygen"
            VERBATIM )
else (DOXYGEN_FOUND)
    message("Doxygen need to be installed to generate the doxygen documentation")
endif (DOXYGEN_FOUND)
