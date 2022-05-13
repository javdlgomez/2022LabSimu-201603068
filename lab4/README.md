# Lab4
Link https://github.com/javdlgomez/2022LabSimu-201603068

### Primer Problema: 



#### Metodología: 
Apartamos un espacio en memoria para el arreglo de enteros deseado, luego este se llena con números pares al multiplicarse por 2 el índice de un ciclo. Realizamos un ciclo que compare el valor dado por el usuario y el ordenamiento para realizar lo deseado. Y para terminar el orden deseado se obtiene iterando de forma ascendente o descendente nuestro arreglo e imprimiendolo.

#### Variables de Entrada y Salida: 
->
- char user_input


<-
- int vector[i]


### Diagrama de Flujo

[Diagrama 1](https://github.com/javdlgomez/2022LabSimu-201603068/blob/main/lab4/Untitled%20Diagram(5).drawio.png)
### Pseudo Código
1 Iniciar el arreglo y el caracter que escogerá el usuario en memoria.
2 Llenar el arreglo con números pares en el intervalo deseado
por medio de un ciclo tal que cada casilla sea el doble del índice iterador.
3 Recibir y comparar la entrada del usuario con el ordenamiento deseado, de
no ser así repetir el proceso hasta conseguir uno de los caracteres deseados.
4 Imprimir el arreglo en la forma pedida por medio de la impresión ascendiente
o descendiente de los índices.
    
### Código
        /*
    Autor:      Javier de Leon
    Fecha:      10/5/22
    Compilador: gcc 12.0
    Compilar: gcc -o ejercicio1.out ejercicio1.c
    Librerías:  stdio
    Resumen:    ordenar de forma descendente o ascendente numeros pares de 2 a 20
    */

    #include <stdio.h>
    #include <string.h>
    int main(){
    int vector[10];
    char user_input;
    //esto ya no se necesito pero ahi se queda como el recuerdo de algo que pudo haber sido
    char control;
    for(int i = 0; i < 10; i++)
    {
        vector[i] = 2*(i+1);
    }
    //aqui es importante usar las comillas
    while (user_input != 'a' && user_input != 'd' ) {
        printf("ingresa el orden de los datos: \n");
        //aqui es muy importante llamar al valor
        scanf("%c",&user_input);

    }
    if (user_input == 'a'){
        for (int i = 0; i<10; i++){
            printf("%i ", vector[i]);
        }}
    else{
        for (int i = 9; i>=0; i--){
            printf("%i ", vector[i]);
    }
    }
    return 0;
    }
    
### Segundo Problema: 


#### Metodología: 
El algoritmo de ordenamiento de burbuja es una de las peores implementaciones para un sistema pero es fácil de implementar. Al guardar los valores deseados es posible emplear este método para obtener el orden deseado.

#### Variables de Entrada y Salida: 
->
- int x

<-
- int arr[5]



### Diagrama de Flujo

[Diagrama 2](https://github.com/javdlgomez/2022LabSimu-201603068/blob/main/lab4/Copy%20of%20Untitled%20Diagram.drawio(2).png)
### Pseudo Código
1 Iniciar el arreglo y las variables del algoritmo de burbuja.
2 Llenar el arreglo con los inputs del usuario.
3 Realizar la implementación del algoritmo de burbuja.
4 Imprimir el arreglo en ordenado.

### Código
     /*
    Autor:      Javier de Leon
    Fecha:      12/5/22
    Compilador: gcc 12.0
    Compilar: gcc -o ejercicio1.out ejercicio1.c
    Librerías:  stdio
    Resumen:    ordenar un arreglo de 5 usando el algoritmo de burbuja
    */

    #include <stdio.h>

    int main(){
    //esta implementación no es mía

        int arr[5], x, y, temp;  


        printf("Ingrese los valores a guardar: ");

        for(x = 0; x < 5; x++)
            //importante llamar por valor
            scanf("%d", &arr[x]);

        x = 0;

        while(x < 5){

            y = 0;        

            while(y < 5- x - 1){
                //esta parte es basicamente el ordenamiento las antereiores
                //solo son para recorrer el arreglo
                if(arr[y] > arr[y + 1]){

                    temp = arr[y];

                    arr[y] = arr[y + 1];

                    arr[y + 1] = temp;

                }

                y++;

            }       

            x++;

        }   

        printf("Numeros ordenados: ");

        for(x = 0; x < 5; x++)

            printf("%d  \n", arr[x]);

        return 0;

    }
    
    
    
### Tercer Problema: 


#### Metodología: 
Las operaciones deseadas se realizan operando componente a componente vectores en R3, para ello vamos a tomar los arreglos dentro de ciclos y realizar de forma explícita las operaciones binarias.

#### Variables de Entrada y Salida: 
->
- float v1[3]
- float v2[3]

<-
- buffer output
- float magnitud, suma, dot, vect

### Diagrama de Flujo

[Diagrama 3](https://github.com/javdlgomez/2022LabSimu-201603068/blob/main/lab4/Copy%20of%20Copy%20of%20Untitled%20Diagram.drawio.png)

    
### Código
        /*
    Autor:      Javier de Leon
    Fecha:      12/5/22
    Compilador: gcc 12.0
    Compilar: gcc -o ejercicio1.out ejercicio1.c
    Librerías:  stdio
    Resumen:    calcular varias operaciones entre 2 vectores en R3
    */
    #include <stdio.h>
    #include <math.h>

        
    //basicamente uso las mismas variables en las funciones para que se entienda
    //que tienen exactamente el mismo rol aunuqe matematicamente no sean precisas

    void magnitud(int v[3], int n){
        float suma = 0;
        for( int i = 0; i<3; i++){
        //no es necesario usar matematica pero ya es costumbre
            suma += pow((v[i]),2);

        }
        printf("La magnitud del vector %i es: %f \n",n,sqrt(suma));

    }
    void suma(int v1[3], int v2[3]){
        float suma = 0;
        for( int i = 0; i<3; i++){
            suma += v1[i]+v2[i];

        }
        printf("La suma es: %f \n",suma);

    }
    void dot(int v1[3], int v2[3]){
        float suma = 0;
        for( int i = 0; i<3; i++){
            suma += v1[i]*v2[i];

        }
        printf("El producto interno es: %f \n",suma);

    }
    //esto se puede hacer de una forma mas elegante
    //pero no me acordaba como hacerlo y sale mas rapido
    //haciendo la fuerza bruta porque (i+1)%3 no sirve
    void vect(int v1[3], int v2[3]){
        float v[3];
        v[0] = v1[1]*v2[2]-v2[1]*v2[2];
        v[1] = -(v1[0]*v2[2]-v2[0]*v1[2]);
        v[2] = v1[0]*v2[1]-v2[0]*v1[1];
        printf("La componente x del producto cruz es: %f\n",&v[0]);
        printf("La componente y del producto cruz es: %f\n",&v[1]);
        printf("La componente x del producto cruz es: %f\n",&v[2]);

    }



    int main(){
    int v1[3];
    int v2[3];
    for(int i = 0; i<3;i++){
        printf("Input v1 %i coord: ",i+1);
        scanf("%i", &v1[i]);
        printf("Input v2 %i coord: ",i+1);
        scanf("%i", &v2[i]);

    }
    magnitud(v1,1);
    magnitud(v2,2);
    suma(v1,v2);
    dot(v1,v2);
    vect(v1,v2);
        return 0;
    }

### Quinto Problema: 


#### Metodología: 
El factorial es la multiplicación de todos los enteros posteriores junto con el número deseado a evaluar, esto se presta fácilmente para recursividad ya que se puede repetir el proceso de evaluación hasta llegar al número 1 en el cual detenemos la recursión.

#### Variables de Entrada y Salida: 
->
- int num

<-
- buffer output float factorial(num))

[Diagrama 5](https://github.com/javdlgomez/2022LabSimu-201603068/blob/main/lab4/Copy%20of%20Copy%20of%20Copy%20of%20Untitled%20Diagram.drawio.png)

    
### Código
    /*
    Autor:      Javier de Leon
    Fecha:      10/5/22
    Compilador: gcc 12.0
    Compilar: gcc -o ejercicio1.out ejercicio1.c
    Librerías:  stdio
    Resumen:    factorial de un numero entero positivo
    */
    #include <stdio.h>
    #include<conio.h>
    int factorial(int n){
    //casos especiales
        if (n <= 1){
            return(1);
        }
       //esta es la recurrencia, literalmente solo se repite la función hasta que n sea 1
        return(n*factorial(n-1));

    }
    int main(){
        int num = 0;
        printf("ingrese el numero para el factorial:");
        scanf("%i",&num);
        printf("el factorial es: %i",factorial(num));




        return 0;
    }





### Sexto Problema: 


#### Metodología: 
Evaluar una sumatoria es posible mediante cualquier tipo de ciclo, solo es importante tener cuidado a la diferencia de terminología en matemática y computación para tomar en cuenta el último valor deseado. La implementación de todos estos problemas es equivalente por tanto se realizará un esquema general que es equivalente en todas las soluciones.

#### Variables de Entrada y Salida: 
->
- int n

<-
- buffer output float sumatoria(num)

[Diagrama 6](https://github.com/javdlgomez/2022LabSimu-201603068/blob/main/lab4/Copy%20of%20Copy%20of%20Copy%20of%20Copy%20of%20Untitled%20Diagram.drawio.png)

    
### Código 6a
    /*
    Autor:      Javier de Leon
    Fecha:      10/5/22
    Compilador: gcc 12.0
    Compilar: gcc -o ejercicio1.out ejercicio1.c
    Librerías:  stdio
    Resumen:    calcula una sumatoria
    */
    #include <stdio.h>
    float sumatoria(int n){
        float suma = 0;
        //esta es la sumatoria especifica
        for (int i = 1; i<=n;i++){
            suma += i*i*(i-3);
        }
        return suma;
    }

    int main(){
        int n = 0;
        printf("Ingrese el n para la sumatoria: ");
        scanf("%i", &n);
        printf("La sumatoria es: %f", sumatoria(n));


        return 0;
    }

    
### Código 6b
    /*
    Autor:      Javier de Leon
    Fecha:      10/5/22
    Compilador: gcc 12.0
    Compilar: gcc -o ejercicio1.out ejercicio1.c
    Librerías:  stdio
    Resumen:    calcula una sumatoria
    */
    #include <stdio.h>
    float sumatoria(int n){
        float suma = 0;
        for (float i = 2; i<=n;i++){
        //lo unico importante en este ejercicio
        //es declarar i como float para que no colapse
            suma += 3*(1/(i-1));
            // printf("%f\n" ,suma);
        }
        return suma;
    }

    int main(){
        int n = 0;
        printf("Ingrese el n para la sumatoria: ");
        scanf("%i", &n);
        printf("La sumatoria es: %f", sumatoria(n));


        return 0;
    }

    }

### Código 6c
    /*
    Autor:      Javier de Leon
    Fecha:      10/5/22
    Compilador: gcc 12.0
    Compilar: gcc -o ejercicio1.out ejercicio1.c
    Librerías:  stdio
    Resumen:    calcula una sumatoria
    */
    #include <stdio.h>
    #include <math.h>
    double sumatoria(int n){
        double suma = 0;
        for (int i = 1; i<=n;i++){
        //esto es basicamente fibonacci, solo que como estaba en la hoja
        tiene un typo. A menos que haya asumido mal y si era así
            // pow(((1+sqrt(5))/2),n)-pow(((1-sqrt(5))/2),n)
            suma += (pow(((1+sqrt(5))/2),i)-pow(((1-sqrt(5))/2),i))/sqrt(5);
        }
        return suma;
    }
    /*
    //habia hecho una implementacion para checkar lo anterior
    float fibonaci(int n){
        if (n>2){
            return fibonaci(n-1)+fibonaci(n-2);
        }
        return 1;
    }   
    */
    int main(){
        int n = 0;
        printf("Ingrese el n para la sumatoria: ");
        scanf("%i", &n);
        sumatoria(n);
        printf("La sumatoria es: %f \n", sumatoria(n));
        // printf("El resultado es: %f", fibonaci(n));

        return 0;
    }


### Código 6d
    /*
    Autor:      Javier de Leon
    Fecha:      10/5/22
    Compilador: gcc 12.0
    Compilar: gcc -o ejercicio1.out ejercicio1.c
    Librerías:  stdio
    Resumen:    calcula una sumatoria
    */
    #include <stdio.h>
    #include <math.h>
    double sumatoria(int n){
        double suma = 0;
        for (int i = 2; i<=n;i++){
            suma += .1*(3*pow(2,i-1)+4);
        }
        return suma;
    }
    /*
    //que hace fibonacci aqui? cuando yo hice este codigo solo Dios y yo sabiamos
    //pero ahora solo Dios sabe
    float fibonaci(int n){
        if (n>2){
            return fibonaci(n-1)+fibonaci(n-2);
        }
        return 1;
    }   
    */
    int main(){
        int n = 0;
        printf("Ingrese el n para la sumatoria: ");
        scanf("%i", &n);
        sumatoria(n);
        printf("La sumatoria es: %f \n", sumatoria(n));

        return 0;
    }
