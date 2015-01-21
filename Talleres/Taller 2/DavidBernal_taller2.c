#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define pi 3.14159

// Compilar al final como cc DavidBernal_taller2.c -lm y graficar en gnuplot con splot "./Esfera-Homogenea.txt"

void make_points(double *x,double *y, double*z, int npoints);
void print_points(double *x,double *y, double*z, int npoints);

int main(int argc, char **argv){
  double *x,*y,*z;
  int npoints;
  int semilla;

  semilla=atoi(argv[1]);
  srand48(semilla);

  npoints=atoi(argv[1]);

  x=malloc(npoints*sizeof(double));
  y=malloc(npoints*sizeof(double));
  z=malloc(npoints*sizeof(double));
  make_points(x,y,z, npoints);
  print_points(x,y,z, npoints);
  return 0;

}


void make_points(double *x,double *y, double*z, int npoints){
  int i, j, k;
  double r, theta, phi;
  for(i=0;i<npoints; i++){
    r=drand48();
    theta=drand48()*pi;
    phi=drand48()*2*pi;
    x[i]=pow(r,1)*sin(theta)*cos(phi);
    y[i]=pow(r,1)*sin(theta)*sin(phi);
    z[i]=pow(r,1)*cos(theta);

  }
}


void print_points(double *x,double *y, double*z, int npoints){
  FILE *fileout;
  int i;
  fileout=fopen("Esfera-Homogenea.txt","w");
  for(i=0;i<npoints;i++){
    fprintf(fileout,"%f %f %f \n",x[i],y[i],z[i]);
  }
  fclose(fileout);
}
