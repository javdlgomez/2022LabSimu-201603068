#Ejemplo: Fibonacci
1) Enunciado: Realizar un programa el cual solicite un numero y este devuelva la serie de fibonacci para
este numero.
2) Metodolog ́ıa: La serie de fibonacci inicia desde el numero 0 y esta suma dos numeros para dar un tercero,  ́
asumamos que se debe obtener la serie de fibonacci para un valor n=4, esta se representa de la siguente forma
0 1 1 2 3 5 8 = 0 1 (0 + 1) (1 + 1) (1 + 2) (2 + 3) (3 + 5)
La funcion general tiene dos partes, las condiciones iniciales y la suma de los elementos  ́

f(a,n) = (

a1 = a2 = 1
an = an−1 +an−2,n >= 3

Para las condiciones iniciales como estas no cambian simplemente podemos validar que se cumplan. Para
las operaciones siguientes, necesitamos un set de datos en un tipo de vector para que se pueda ir navegando
entre las posiciones de estos y realizar las operaciones. Dado a que la respuesta del numero siguiente es la
operacion de los anteriores, estamos bajo las condiciones de un elemento recursivo  ́
0 1 (0+1) (1 + (0 + 1)) ((0 + 1) + (1 + (0 + 1))) ...
3) Variables de Entrada y salida: Debido a que solicitaremos el numero n, el usuario ingresara un valor
entero, como salida obtendremos el numero entero de la serie en forma de texto.
→ entero (n)
← texto (valor)
* variable local de conteo (k)
