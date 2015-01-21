#include <stdio.h>
#include <stdlib.h>
#define USAGE "USAGE: ./pi.x n_points seed"
#define PI 3.1459

int main(int argc, char **argv){
  int n_points;
  int seed;
  float *x;
  float *y;
  int i;
  int n_in;
  float integral;

  if(argc!=3){
    printf("%s\n", USAGE);
    exit(1);
  }

  n_points = atoi(argv[1]);
  seed = atoi(argv[2]);

  printf("Using %d points to integrate\n", n_points);
  printf("Expected value %f\n", PI);

  
  if(!(x=malloc(n_points * sizeof(float)))){
    printf("problem with memory allocation\n");
    exit(1);
  }


  if(!(y=malloc(n_points * sizeof(float)))){
    printf("problem with memory allocation\n");
    exit(1);
  }
  
  srand48(seed);
  
  n_in = 0;
  for(i=0;i<n_points;i++){
    x[i] = 2.0*(drand48() -0.5);
    y[i] = 2.0*(drand48() -0.5);

    if((x[i]*x[i]  + y[i]*y[i])<1.0){
      n_in++;
    }
  }
  integral = 4.0*n_in/n_points;
  
  printf("integral %f\n", integral);
  
  return 0;
}
























