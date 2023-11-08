#!/bin/bash

# Parámetros
f=$1
c=$2
programa="barajar"
fichero_csv_comun="datos${f}f_${c}c.csv"
fichero_csv_cols="datos_${f}c.csv"
fichero_csv_fils="datos_${c}f.csv"

# Creamos el fichero CSV si no existe
touch "$fichero_csv_comun"
touch "$fichero_csv_cols"
touch "$fichero_csv_fils"

for (( columna=1; columna<=c; columna++ )); do
  output=$("./$programa" "$f" "$columna")
  # Guardamos el output en el archivo CSV, si no existe se creará el fichero  
  echo "$output" >> "$fichero_csv_cols"
done

# Ejecutamos el programa para cada f y  c con el otro constante
for (( fila=1; fila<=f; fila++ )); do
  output=$("./$programa" "$fila" "$c")
  # Guardamos el output en el archivo CSV, si no existe se creará el fichero  
  echo "$output" >> "$fichero_csv_fils"
done

# Ejecutamos el programa para cada combinación de n y f
for (( i=1; i<f; i++ )); do
  for (( j=1; j<c; j++ )); do
    # Ejecutamos el programa
    output=$("./$programa" "$i" "$j")
    # Guardamos el output en el archivo CSV, si no existe se creará el fichero  
    echo "$output" >> "$fichero_csv_comun"
  done
done

# Añado el contenido de fichero_csv_cols y fichero_csv_fils a fichero_csv_comun para no repetir iteraciones
cat "$fichero_csv_cols" >> "$fichero_csv_comun"
cat "$fichero_csv_fils" >> "$fichero_csv_comun"

# Scripts de Gnuplot, me los ha hecho chatgpt pa que te voy a mentir, pero el resto le he hecho yo
gnuplot << EOF
# Configuración del gráfico
set terminal pngcairo enhanced font 'Arial,12' size 800,600
set output "grafica_$fichero_csv_comun.png"
set title "Gráfico 3D de Tiempo de Ejecución"
set xlabel "Columna"
set ylabel "Fila"
set zlabel "Tº de Ejecución"
set key top left

# Configuración de los datos
set datafile separator ","
splot "$fichero_csv_comun" using 2:1:3 with points title "Tiempo de Ejecución"

EOF

# Para grafica de las filas
gnuplot << EOF
# Configuración del gráfico
set terminal pngcairo enhanced font 'Arial,12' size 800,600
set output "grafica_$fichero_csv_fils.png"
set title "Relación Tº Ejecución - nº Filas"
set xlabel "Fila"
set ylabel "Tº de Ejecución"
set key top left

# Configuración de los datos
set datafile separator ","
plot "$fichero_csv_fils" using 1:3 with points title "Tiempo de Ejecución"

EOF

# Para grafica de las columnas
gnuplot <<EOF
# Configuración del gráfico
set terminal pngcairo enhanced font 'Arial,12' size 800,600
set output "grafica_$fichero_csv_cols.png"
set title "Relación Tº Ejecución - nº Columnas"
set xlabel "Columna"
set ylabel "Tº Ejecución"
set key top left

# Configuración de los datos
set datafile separator ","
plot "$fichero_csv_cols" using 2:3 with points title "Tº Ejecución"

EOF