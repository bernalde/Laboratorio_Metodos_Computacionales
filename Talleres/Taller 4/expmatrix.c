
#include <stdio.h>
#include <stdlib.h>


float *load_matrix(char *filename, int *n, int *m);
void identidad(float *A, int n, int m);
void sumar(float *A, float *B, float *C, int n, int m);
void copiar(float *A, float *B, int n, int m);
void dividir(float *A, float *B, int n, int m, int fact);
void multiplicacion(float *A, float *B, float *C, int n, int m);
float factorial(int n);
int main(int argc, char **argv){
  float *matrix0;
  float *matrix1;
  float *matrix2;
  float *matrix3;
  float *matrix4;
  float *matrix5;
  int n_row, n_cols;
  int i, j, k, l;

  matrix0 = load_matrix(argv[1], &n_row, &n_cols);
  matrix1 = load_matrix(argv[1], &n_row, &n_cols);
  matrix2 = load_matrix(argv[1], &n_row, &n_cols);
  matrix3 = load_matrix(argv[1], &n_row, &n_cols);
  matrix4 = load_matrix(argv[1], &n_row, &n_cols);
  matrix5 = load_matrix(argv[1], &n_row, &n_cols);

  identidad(matrix0,n_row,n_cols);

  for(l=0;l<30;l++){
    copiar(matrix1,matrix2,n_row,n_cols);
    for(k=0;k<l;k++){
      multiplicacion(matrix2,matrix1,matrix3,n_row,n_cols);
      copiar(matrix3,matrix2,n_row,n_cols);
    }
    dividir(matrix3,matrix4,n_row,n_cols,l+1);
    sumar(matrix0,matrix4,matrix5,n_row,n_cols);
    copiar(matrix5,matrix0,n_row,n_cols);
  }


 for(i=0;i<n_row;i++){
    for(j=0;j<n_cols;j++){
      printf(" %f ", matrix0[i*n_cols + j]);
    }
    printf("\n");
  }

  return 0;
}


float factorial(n){
  if(n==0){
    return 1;
  }
  else{
    return n*factorial(n-1);
  }
}

void identidad(float *A, int n, int m){

  int i, j;
 
  for(i=0;i<n;i++){
    for(j=0;j<m;j++){
      if(i==j){
	A[i*m+j]=1;
      }
      else{
	A[i*m+j]=0;
      }
    }
  }
 
}

void copiar(float *A, float *B, int n, int m){

  int i, j;
 
  for(i=0;i<n;i++){
    for(j=0;j<m;j++){
      B[i*m+j]=A[i*m+j];
    }
  }
 
}

void dividir(float *A, float *B, int n, int m, int fact){

  int i, j;
 
  for(i=0;i<n;i++){
    for(j=0;j<m;j++){
      B[i*m+j]=A[i*m+j]/factorial(fact);
    }
  }
 
}

void sumar(float *A, float *B, float *C, int n, int m){

  int i, j;
 
  for(i=0;i<n;i++){
    for(j=0;j<m;j++){
      C[i*m+j]=A[i*m+j]+B[i*m+j];
    }
  }
 
}

void multiplicacion(float *A, float *B, float *C, int n, int m){

  int i, j, k;
 
  for(i=0;i<n;i++){
    for(j=0;j<m;j++){
      C[i*m+j]=0.0;
      for(k=0;k<n;k++){
	C[i*m+j]+=A[i*m+k]*B[k*m+j];
      }
    }
  }
 
}



float *load_matrix(char *filename, int *n, int *m){
  float *matrix;
  FILE *in;
  int n_row, n_cols;
  int i;
  int j;

  if(!(in=fopen(filename, "r"))){
    printf("Problem opening file %s\n", filename);
    exit(1);
  }

  fscanf(in, "%d %d\n", &n_row, &n_cols);

  matrix = malloc(n_row * n_cols * sizeof(float));

  for(i=0;i<n_row;i++){
    for(j=0;j<n_cols;j++){
      fscanf(in, "%f", &matrix[i*n_cols + j]);
    }
  }    
  *n = n_row;
  *m = n_cols;
  return matrix;
}

