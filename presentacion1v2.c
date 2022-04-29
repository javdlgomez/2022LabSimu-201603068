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

typedef struct coord {
  float x;
  float y;
} Coord;

typedef struct linregdat {
  float beta, epsilon, densidad, londa, sumx, sumy;

} linregdat;

void linReg(Coord *coords, int length, linregdat *resultadosRegresion) {

  float sumx, sumy, sumxy, errx = 0;
  float beta, epsilon, intervalo, densidad, londa = 0;
  for (int i = 0; i < length; i++) {
    Coord v1 = coords[i];
    sumx += v1.x;
    errx += v1.x * v1.x;
    sumy += v1.y;
    sumxy += v1.x * v1.y;
    printf("%f %f", v1.x, v1.y);

    // printf("%f", sumxy);
    // printf("iteracion: %i %f  %f %f %f \n", i, sumx, errx, sumy, sumxy);
  }

  intervalo = length * errx - sumx * sumx;

  beta = (length * sumxy - sumx * sumy) / intervalo;
  epsilon = (sumy * errx - sumx * sumxy) / intervalo;
  densidad = (beta) / (60 * 60 * 2 * coords[1].x);
  londa = (6 - epsilon) / beta;
  resultadosRegresion->beta = beta;
  resultadosRegresion->epsilon = epsilon;
  resultadosRegresion->sumx = sumx;
  resultadosRegresion->sumy = sumy;

  printf("%f  %f", beta, epsilon);
  ;
}

/*
float estimacion(float sumx, float sumy, float errx, float erry, Coord coords[],
                 int length) {
  float mediax, mediay;
  float stdx, stdy, estimacion, errest = 0;

  mediax = sumx / length;
  mediay = sumy / length;
  for (int i = 0; i < length; i++) {
    Coord v1 = coords[i];
    stdx += sqrt(pow((mediax - v1.x), 2));
    stdy += sqrt(pow((mediay - v1.y), 2));
  }
  stdx / sqrt(length - 1);
  stdy / sqrt(length - 1);

  estimacion = pow(mediax, 2) / mediay;
  errest = sqrt(pow(2 * pow(mediax, 2) * stdx / mediay, 2) +
                pow(stdy, 2) * pow(mediax / mediay, 4));
                printf("estimacion: %f errest: %f", &sumx, &sumy);
  return estimacion, errest;
}
*/
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
  printf("%f", coords[1].y);
  linReg(coords, n, &parametrosRegresion);

  char bufferx[1024];
  snprintf(bufferx, sizeof(bufferx),
           "plot 'TablaInicial.tmp' title 'Datos Medidos', "
           "%f*x+%f title 'Fit Lineal %.2fx+%.2f'",
           parametrosRegresion.beta, parametrosRegresion.epsilon,
           parametrosRegresion.beta, parametrosRegresion.epsilon);
  char *GnuCommands[] = {"set title \"presentacion2\"", "set xrange [0:6]",
                         bufferx};

  for (int i = 0; i < 3; i++) {

    fprintf(gnupipe, "%s\n", GnuCommands[i]);
  }

  return 0;
}