/*
Autor:      Javier de Leon
Fecha:      16/3/22
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