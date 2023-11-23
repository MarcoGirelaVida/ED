cmake_minimum_required(VERSION 3.13)
project(p04_tdas_no_lineales)

set(CMAKE_CXX_STANDARD 14)

set(BASE_FOLDER estudiante)

include_directories(${BASE_FOLDER}/include)

if (EXISTS ${CMAKE_SOURCE_DIR}/${BASE_FOLDER}/src/filtro.cpp)
  add_executable(filtro
    ${BASE_FOLDER}/src/filtro.cpp
    ${BASE_FOLDER}/src/guiatlf.cpp)
endif()

if (EXISTS ${CMAKE_SOURCE_DIR}/${BASE_FOLDER}/src/modificar.cpp)
  add_executable(modificar
    ${BASE_FOLDER}/src/modificar.cpp
    ${BASE_FOLDER}/src/guiatlf.cpp)
endif()

if (EXISTS ${CMAKE_SOURCE_DIR}/${BASE_FOLDER}/src/inter.cpp)
  add_executable(inter
    ${BASE_FOLDER}/src/inter.cpp
    ${BASE_FOLDER}/src/guiatlf.cpp)
endif()

if (EXISTS ${CMAKE_SOURCE_DIR}/${BASE_FOLDER}/src/union.cpp)
  add_executable(union
    ${BASE_FOLDER}/src/union.cpp
    ${BASE_FOLDER}/src/dictionary.cpp)
endif()

if (EXISTS ${CMAKE_SOURCE_DIR}/${BASE_FOLDER}/src/palabras_longitud.cpp)
  add_executable(palabras_longitud
    ${BASE_FOLDER}/src/palabras_longitud.cpp
    ${BASE_FOLDER}/src/dictionary.cpp)
endif()

if (EXISTS ${CMAKE_SOURCE_DIR}/${BASE_FOLDER}/src/apariciones.cpp)
  add_executable(apariciones
    ${BASE_FOLDER}/src/apariciones.cpp
    ${BASE_FOLDER}/src/dictionary.cpp)
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
