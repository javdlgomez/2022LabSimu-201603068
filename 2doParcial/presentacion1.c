/*
Autor:      Javier de Leon
Fecha:      16/3/22
Compilador: gcc 12.0
Compilar: gcc -o ejercicio1.out ejercicio1.c
Librerías:  stdio
Resumen:    experimento de ondas estacionarias

*/

#include <math.h>
#include <stdio.h>

//Definimos Nuestra Estructura de Almacenamiento de datos Duros
typedef struct coord {
  float x;
  float y;
} Coord;
//Definimos Nuestra Estructura de Almacenamiento de Datos para Operar
typedef struct linregdat {
  float beta, epsilon, densidad, londa, sumx, sumy;

} linregdat;


//Es importante llamar a coords como array y no con puntero

void linReg(Coord coords[], int length, linregdat *resultadosRegresion) {

  float sumx, sumy, sumxy, errx = 0;
  float beta, epsilon, intervalo, densidad, londa = 0;
  sumx = 0;
  sumy = 0;
  for (int i = 0; i < length; i++) {
    Coord v1 = coords[i];
    sumx += v1.x;
    errx += v1.x * v1.x;
    sumy += v1.y;
    sumxy += v1.x * v1.y;
    //Controles del ciclo
    // printf("%f", sumxy);
    // printf("iteracion: %i %f  %f %f %f \n", i, sumx, errx, sumy, sumxy);
  }

  intervalo = length * errx - sumx * sumx;

  //Encontramos los parametros de la regresion
  
  beta = (length * sumxy - sumx * sumy) / intervalo;
  epsilon = (sumy * errx - sumx * sumxy) / intervalo;
  densidad = (beta) / (60 * 60 * 2 * coords[1].x);
  londa = (6 - epsilon) / beta;
  
  //Almacenamos nuestra estructura de estadisticos
  resultadosRegresion->beta = beta;
  resultadosRegresion->epsilon = epsilon;
  resultadosRegresion->sumx = sumx;
  resultadosRegresion->sumy = sumy;

  //output deseado
  printf("Pendiente:%f  Intercepto: %f\n", beta, epsilon);
  printf("Prediccion Densidad: %f  Long Onda T=6: %f\n", densidad, londa);
  ;
}


float pearson(float sumx, float sumy, Coord coords[], int length) {
  float mediax, mediay;
  float stdx, stdy, cov, pearson = 0;

  mediax = sumx / length;
  mediay = sumy / length;
  stdx = 0;
  stdy = 0;
  cov = 0;
  pearson = 0;
  for (int i = 0; i < length; i++) {
    Coord v1 = coords[i];

    stdx += (mediax - v1.x) * (mediax - v1.x);
    stdy += (mediay - v1.y) * (mediay - v1.y);
    cov += (mediax - v1.x) * (mediay - v1.y);
    // controles del ciclo
    // printf("cov: %f\n", cov);
    // printf("media: %f\n", mediay);
    // printf("x %f\n", v1.y);
  }
  stdx = sqrt(stdx / (length - 1));
  stdy = sqrt(stdy / (length - 1));
  cov = cov / (length - 1);
  pearson = cov / (stdx * stdy);
  //output deseado
  printf("Coeficiente de Pearson: %f\n", pearson);
  // printf("stdx %f stdy %f", stdx, stdy);
  return 0;
}

int main() {
  int n;
  FILE *fp = NULL;
  FILE *gnupipe = NULL;

  printf("ingrese el numero de datos: ");
  scanf("%d", &n);
  Coord coords[n];

  fp = fopen("TablaInicial.tmp", "w");
  gnupipe = _popen("gnuplot -presistent", "w");

  // aqui llenamos nuestra estructura abstracta con user inupt
  for (int i = 0; i < n; i++) {
    Coord tabla;
    printf("Ingresa la long onda: ");
    scanf("%f", &tabla.x);
    fflush(stdout);
    printf("Ingresa la Tension: ");
    scanf("%f", &tabla.y);
    // printf("input #%d {x=%f, y=%f}\n", i + 1, tabla.x, tabla.y);
    coords[i] = tabla;
    float archivox = tabla.x;
    float archivoy = tabla.y;
    // printf("%f %f ", tabla.x, tabla.y);
    fprintf(fp, "%f %f\n", archivox, archivoy);
  }
  printf("\n");
  // printf("beta: %f epsilon: %f", linReg(coords, n));
 
  linregdat parametrosRegresion;
  //es importante llamar por direccion a parReg
  //esta escrito en otro protocolo de nombramiento
  //para hacer claro que es distinto a coords
  //ya que la forma en la que funciona coords da overflow
  //y es necesario declarar explicitamente variables a 0 
  //cuando se vuelve a correr el programa para que funcione
  linReg(coords, n, &parametrosRegresion);
  pearson(parametrosRegresion.sumx, parametrosRegresion.sumy, coords, n);

  //ponemos 1024 para que no de error pero puede ser menos si se sabe el valor explicito
  char bufferx[1024];
  snprintf(bufferx, sizeof(bufferx),
           "plot 'TablaInicial.tmp' title 'Datos Medidos', "
           "%f*x+%f title 'Fit Lineal %.2fx+%.2f'",
           parametrosRegresion.beta, parametrosRegresion.epsilon,
           parametrosRegresion.beta, parametrosRegresion.epsilon);
  char *GnuCommands[] = {"set title \"presentacion2\"", "set xrange [0:6]",
                         bufferx, "save 'plotPres1.eps'"};
  //si no se desea guardar la grafica cambiar 4 -> 3
  for (int i = 0; i < 4; i++) {

    fprintf(gnupipe, "%s\n", GnuCommands[i]);
  }

  return 0;
}
