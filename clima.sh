#!/bin/bash
#escribimos el archivo con curl y utilizamos -s para que no muestre el proceso en consola

echo "$(curl -s wttr.in/Guatemala)" > info_clima.txt 

#escibimos en consola 7 lineas del header del archivo

echo "$(head -n 7 info_clima.txt)"

#borramos el archivo

rm info_clima.txt


