#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define pi 3.14159


int main(){
  int n_points=100;
  int n_t=1000;
  int i,j;
  double x[n_points];
  double u_past[n_points];
  double u[n_points][n_t];
  double dx;
  double dt;
  double nu=0.07;
  double sigma=0.02;
  double alpha;
  FILE *fileout;
  double final=1.0;
  double inicial=0.0;

  dx=(final-inicial)/n_points;
  printf("%f\n",dx);
  for(i=0;i<n_points;i++){
    x[i]=i*dx;
    u[i][0]=0;
    if(x[i]<0.66 && x[i]>0.33){
      u[i][0]=1.0;
    }
  }
  dt=(sigma*pow(dx,2.0))/nu;
  printf("%f\n",dt);
  alpha=dt/pow(dx,2.0);
 

  for(j=0;j<n_t-1;j++){
    for(i=0;i<n_points;i++){
      u_past[i]=u[i][j];
    }
    for(i=1;i<(n_points-1);i++){
      u[i][j+1]=nu*alpha*u_past[i+1]+(1.0-2.0*nu*alpha)*u_past[i]+nu*alpha*u_past[i-1];
    }
    
  }
  
  fileout=fopen("ResultsDifusionAnim.dat","w");
  for(i=0;i<n_points;i++){
    fprintf(fileout,"%f ",x[i]);
    for(j=0;j<n_t;j++){
      fprintf(fileout,"%f ",u[i][j]);
    }
    fprintf(fileout,"\n");
  }
  fclose(fileout);

  return 0;
  
  /*
    Este codigo genera una archivo de resultados de nombre ResultsDifusionAnim.dat el cual tiene 100 filas y 1001 columnas. La primera columna tiene la discretización en x y las siguientes mil lineas corresponden a los perfiles de velocidad (segun la fila tiene su posicion en x) con respecto al delta_t (segun la columna).

  */

}
