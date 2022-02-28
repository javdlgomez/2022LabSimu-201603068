#!/bin/bash
: << 'Header' 
Autor: Javier de Leon
Fecha: 27-2-22
Tipo de archivo: Script de bash
Ejecucio: ./script_ejercicio_2.sh
Resumen: hace lo que pide la practica
Header

echo "nombre de archivo a crear"
read nombre_archivo
if [ -z "$nombre_archivo" ]; then
    echo "nombre no valido"
elif [ -n "$nombre_archivo" ]; then
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