#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
 double *v;
 int n = 1024*1024, i, j;

 for (i = 0; i < 500; i++) {
  v = malloc(n * sizeof(double));
  for (j = 0; j < n; j++) {
   v[j] = i;
  }
  printf("%lf", v[n-1]);
  //free(v); // Descomente esta linha para corrigir o problema
 }

 getchar();
 return 0;
}
