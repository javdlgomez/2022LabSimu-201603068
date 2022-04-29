# 2do Parcial

### Primer Problema: 
#### Enunciado:
Realiza el experimento de ondas estacionarias con una cuerda. Le solicitan que genere un programa el cual cumpla con las siguientes condiciones:
- Una grafica que compare los valores tabulados y la recta que mejor aproxima el comportamiento. 
- Estimar el valor de la densidad lineal de la cuerda. La longitud de onda cuando la tension sea de 6N.

#### Metodología: 
Tomamos los datos del usuario de una tabla 2D arbitraria para realizar una regresión lineal de estos. La regresión se optimiza con mínimos cuadrados y toma como inputs los datos anteriores los cuales han sido almacenados en una estructura abstracta y se llaman como posiciones en un array de tamaño n. Esto no es una buena práctica de programación en C, recomendamos emplear un llamado por direcciones.
Luego de realizar la operación se reproduce una gráfica y se guarda en un archivo .eps empleando gnuplot, luego se obtienen los parámetros y estadísticos deseados tomando como inputs los valores obtenidos durante el proceso de la regresión. Para poder realizar las gráficas empleamos buffers. 

#### Variables de Entrada y Salida: 
->
- Tamaño de la Tabla: int n
- Coordenada x: float tabla.x
- Coordenada y: float tabla.y


<-
- Pendiente: float beta
- Intercepto: float epsilon
- float densidad
- float londa
- float pearson
###Diagrama de Flujo

 ![Diagrama1](/Untitled Diagram.drawio.png )
### Código
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
        // printf("cov: %f\n", cov);
        // printf("media: %f\n", mediay);
        // printf("x %f\n", v1.y);
      }
      stdx = sqrt(stdx / (length - 1));
      stdy = sqrt(stdy / (length - 1));
      cov = cov / (length - 1);
      pearson = cov / (stdx * stdy);
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
      linReg(coords, n, &parametrosRegresion);
      pearson(parametrosRegresion.sumx, parametrosRegresion.sumy, coords, n);
    
      char bufferx[1024];
      snprintf(bufferx, sizeof(bufferx),
               "plot 'TablaInicial.tmp' title 'Datos Medidos', "
               "%f*x+%f title 'Fit Lineal %.2fx+%.2f'",
               parametrosRegresion.beta, parametrosRegresion.epsilon,
               parametrosRegresion.beta, parametrosRegresion.epsilon);
      char *GnuCommands[] = {"set title \"presentacion2\"", "set xrange [0:6]",
                             bufferx, "save 'plotPres1.eps'"};
    
      for (int i = 0; i < 4; i++) {
    
        fprintf(gnupipe, "%s\n", GnuCommands[i]);
      }
    
      return 0;
    }
### Segundo Problema: 
#### Enunciado:
Utilizando un método numérico encuentre la raíz de la ecuación f(x) = cot(x)
Debe de realizar la grafica de la ecuación y comparar el resultado obtenido con el programa realizado en C.

- Una grafica que compare los valores tabulados y la recta que mejor aproxima el comportamiento. 
- Estimar el valor de la densidad lineal de la cuerda. La longitud de onda cuando la tension sea de 6N.

#### Metodología: 
Utilizamos el valor inicial dado, el número de iteraciones y la tolerancia de error para alimentar a nuestra implementación del algoritmo NR. En este caso no generalizamos el programa para realizar el cálculo de una función arbitraria pero es posible extenderlo agregando un método de derivación explícita y buffers.
Nuestro algoritmo es sumamente ineficiente ya que realiza una comparación de cada iteración del proceso de NR para comprobar si ya se obtuvo un valor menor a la tolerancia de error pedida. Al momento de cumplir la condición anterior el programa se detiene y en caso contrario el algoritmo continua hasta cumplir con el número de interaciones o la tolerancia de error pedida.

#### Variables de Entrada y Salida: 
->
- float x0
- int n
- float err


<-
- float x

### Diagrama de Flujo
 ![Diagrama1](/
Copy of Untitled Diagram.drawio(1).png )
### Código
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
    #include <stdlib.h>
    
    //definimos f para poder realizar NR
    float f(float x) { return (cos(x) / sin(x)); }
    
    float new_rap(float x0, int n, float err) {
      float x = x0;
      //x2 no hace nada pero no la hemos quitado
      float x2 = 0;
      float absErr = sqrt(pow(err, 2));
      for (int i = 0; i < n; i++) {
        x = x + sin(2 * x) / 2;
        
        x2 = pow(x, 2);
        
        //ciclo principal del algoritmo, no esta optimizado
        if (absErr > sqrt(pow(f(x), 2))) {
          printf("iteraciones: %i\n", n);
          return printf("posible raiz %f\n", x);
        } else if (absErr < sqrt(pow(f(x), 2)) & i == (n - 1)) {
          return printf("No se obtuvo una aproximacion suficiente");
        }
      }
      return 0;
    }
    
    int main() {
      float x00, x0, err = 0;
      int n = 0;
      printf("ingrese el valor inicial: ");
      scanf("%f", &x0);
      printf("ingrese el numero de iteraciones: ");
      scanf("%i", &n);
      x00 = x0;
      printf("ingrese la tolerancia de error: ");
      scanf("%f", &err);
      //control del ciclo
      // printf("posible raiz: %f", new_rap(x0, n,err));
      new_rap(x0, n, err);
    
      //usamos buffers para personalizar el plot
      char bufferx[1024];
      snprintf(bufferx, sizeof(bufferx), "set xrange [%f:%f]", x00 - 5, x00 + 5);
      char buffery[1024];
      snprintf(buffery, sizeof(buffery), "set yrange [%f:%f]", f(x00) - 5,
               f(x00) + 5);
      FILE *fp = NULL;
      FILE *gnupipe = NULL;
      char *GnuCommands[] = {
          "set title \"presentacion2\"", bufferx, buffery,
          "plot 'PuntoInicial.tmp' title 'Posible Raiz NR', cos(x)/sin(x)", "save 'plotPres2.eps'"};
    
      fp = fopen("PuntoInicial.tmp", "w");
      gnupipe = _popen("gnuplot -presistent", "w");
      // si no quieren guardar un archivo cambiar i 5->4
      fprintf(fp, "%f %f\n", x0, f(x0));
      for (int i = 0; i < 5; i++) {
    
        fprintf(gnupipe, "%s\n", GnuCommands[i]);
      }
      return 0;
    }
    
