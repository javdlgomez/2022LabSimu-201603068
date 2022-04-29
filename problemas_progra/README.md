# Problemas de programación
Dentro de esta carpeta se documentaran y se mostrará el código de los problemas dejados en clase.

## Problema 1
![Problema1](/2022LabSimu-201603068/problemas_progra/ejercicio1.c )
### Variables de entrada:
    i: Contador de números ingresados
    n: Contador de números positivos ingresados.
    x: Almacena temporalmente el número ingresado.
    media: Almacena la suma de los números ingresados.
### Compilación y ejecución:
    $ gcc -o problema1.out problema1.c && ./problema1.out

## Problema 2
![Problema2]( /2022LabSimu-201603068/problemas_progra/ejercicio2.c )
### Variables de entrada:
    n: Contador de números ingresados.
    x: Almacena temporalmete el número ingresado.
    med: Almacena la suma de los números ingresados (mayores o iguales a cero).
    min: Almacena el número de menor valor.
    max: Almacena el número de mayor valor.
### Compilación y ejecución:
    $ gcc -o problema2.out problema2.c && ./problema2.out

## Problema 3
![Problema3]( /2022LabSimu-201603068/problemas_progra/ejercicio3.c )
### Variables de entrada:
    n: Entero positivo al que se le calculará su "raíz"
    r: Entero positivo que aproximará a la raíz.
### Compilación y ejecución:
    $ gcc -o problema3.out problema3.c && ./problema3.out

## Problema 4
![Problema4](/2022LabSimu-201603068/problemas_progra/ejercicio4.c )
### Variables de entrada:
    n: Contiene el número ingresado
    i: Cambia su valor progresivamente para poder obtener el residuo de (n) con distintos números.
    primo: Vale 1 si el número es primo y 0 si no.
### Compilación y ejecución:
    $ gcc -o problema4.out problema4.c && ./problema4.out

## Problema 5
![Problema5](/2022LabSimu-201603068/problemas_progra/ejercicio5.c )
### Variables de entrada:
    n1: Número entero positivo que define el principio del rango. Es mayor a 1.
    n2: Número entero positivo que define el final del rango. Es mayor a n1.
    i: Variable de conteo cuyo valor aumenta progresivamente desde n1 hasta n2.
    j: Para cada valor de i, cambia su valor progresivamente (desde 2 hasta i-1) para poder obtener el residuo i%j con distintos valores de (j).
    primo: Vale 1 si el número es primo y 0 si no.
### Compilación y ejecución:
    gcc -o problema5.out problema5.c && ./problema5.out

## Problema 6
![Problema6](/2022LabSimu-201603068/problemas_progra/ejercicio6.c )
### Variables de entrada:
    FM: Contiene el número de vértices del polígono.
    N: No es necesaria, pero facilita la comprensión de la matemática. Representa la longitud del arreglo, contando desde cero.
### Variables de conteo:
    fila: Para "movernos" por las filas del arreglo.
    i: Para la sumatoria.
### Variables de salida:
    A: Guarda el valor de la sumatoria en todo momento.
### Compilación y ejecución:
    $ gcc -o problema4.out problema4.c && ./problema4.out

