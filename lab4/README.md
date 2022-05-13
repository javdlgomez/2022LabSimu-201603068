# Lab4

### Primer Problema: 



#### Metodología: 
Apartamos un espacio en memoria para el arreglo de enteros deseado, luego este se llena con números pares al multiplicarse por 2 el índice de un ciclo. Realizamos un ciclo que compare el valor dado por el usuario y el ordenamiento para realizar lo deseado. Y para terminar el orden deseado se obtiene iterando de forma ascendente o descendente nuestro arreglo e imprimiendolo.

#### Variables de Entrada y Salida: 
->
- char user_input


<-
- int vector[i]


### Diagrama de Flujo

[Diagrama 1](https://github.com/javdlgomez/2022LabSimu-201603068/blob/main/lab4/Untitled%20Diagram.drawio.png)
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
    Resumen:    Saca la media de 3 numeros
    */

    #include <stdio.h>
    #include <string.h>
    int main(){
    int vector[10];
    char user_input;
    char control;
    for(int i = 0; i < 10; i++)
    {
        vector[i] = 2*(i+1);
    }
    while (user_input != 'a' && user_input != 'd' ) {
        printf("ingresa el orden de los datos: \n");
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

[Diagrama 2](https://github.com/javdlgomez/2022LabSimu-201603068/blob/main/lab4/Copy%20of%20Untitled%20Diagram.drawio(1).png)

    ### Código
     /*
    Autor:      Javier de Leon
    Fecha:      12/5/22
    Compilador: gcc 12.0
    Compilar: gcc -o ejercicio1.out ejercicio1.c
    Librerías:  stdio
    Resumen:    Saca la media de 3 numeros
    */

    #include <stdio.h>

    int main(){

        int arr[5], x, y, temp;  


        printf("Ingrese los valores a guardar: ");

        for(x = 0; x < 5; x++)

            scanf("%d", &arr[x]);

        x = 0;

        while(x < 5){

            y = 0;        

            while(y < 5- x - 1){

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
