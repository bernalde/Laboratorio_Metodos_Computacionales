David Esteban Bernal Neira
200921359
Taller 4 Laboratorio Métodos Computacionales
Para correr este código se debe compilar con el comando cc y luego ejecutar el archivo de salida de la forma ./a.out matrix.dat, donde matrix.dat es un archivo de texto con el formato propuesto por el curso para que sea capaz de ser leído por el archivo dado en la clase magistral. El formato es:
n m
A11 A12 ... A1m
A21 A22 ... A2m
.   ...      .
.            .
.            .
An1 An2 ... Anm
Donde n es el numero de filas, m el numero de columnas y Aij el elemento en la posicion i,j de la matriz A.
En esta carpeta se encuentran 4 archivos nombrados matrix_().dat los cuales incluyen matrices en ese formato para probar el código.
Cabe resaltar que el ejemplo mostrado en http://en.wikipedia.org/wiki/Matrix_exponential#Illustrations es el correspondiente a matrix_A.dat.
Al evaluar la exponencial de esta matriz con este código y comparando con la solución analítica, vemos que los valores obtenidos por el código dividido por componente en la solución analítica son:
0.9991 0.9991 0.9994
0.9989 0.9989 0.9994
0.9989 0.9989 0.9994
Esto se debe a que la suma es hasta infinito y en este código solo se tomaron los 30 primeros valores de la serie (no se tomaron más debido a la evaluación del factorial).

