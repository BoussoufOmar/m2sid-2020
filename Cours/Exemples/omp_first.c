/******************************************************************************
 * * FILE: omp_gf.c
 * * DESCRIPTION:
 * *   OpenMP Example - Greetings from - C/C++ Version
 * ******************************************************************************/
#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[]) 
{
  int a, p;
  a=9000;
  p=0;
  /* Fork a team of threads */
  #pragma omp parallel
  {
  p=omp_in_parallel();
  printf("a = %d \n", a);
  }  /* end of parallel region, all threads join master */
  printf("p = %d \n", p);
}
