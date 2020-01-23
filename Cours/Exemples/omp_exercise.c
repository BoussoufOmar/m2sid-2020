#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[]) 
{
int   i, n, ilast;
int a[100000]; 

/* Some initializations */
n = 100000;
for (i=0; i < n; i++)
  a[i] = i ;

#pragma omp parallel for private(ilast) 
  for (i=0; i < n; i++){
    if ((a[i]%10000)== 0){
       ilast=i;
       printf("value found at ilast = %d \n",ilast);
    }
  }
}
