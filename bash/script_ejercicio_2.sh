#!/bin/bash
: << 'Header' 
Autor: Javier de Leon
Fecha: 27-2-22
Tipo de archivo: Script de bash
Ejecucio: ./script_ejercicio_2.sh
Resumen: hace lo que pide la practica
Header

#tomamos el input del nombre del archivo
echo "nombre de archivo a crear"
read nombre_archivo

#vemos si esta vacio o si tiene un nombre, si tiene nombre creamos otro archivo, si ya existe no hacemos nada
if [ -z "$nombre_archivo" ]; then
    echo "nombre no valido"
elif [ -n "$nombre_archivo" ]; then
#creamos un archivo con el header dado
    cat <<EOT >>  $nombre_archivo.c
    /*
    Autor: $USER
    Compilador: gcc 9.3.0
    Compilado: gcc $nombre_archivo.c -o $nombre_archivo
    librerias: stdio
    Resumen:
    Entrada:
    Salida
    */

    //librerias
    #include <stdio.h>
    //numerar los pasos del pseudocodigo
EOT
fi
