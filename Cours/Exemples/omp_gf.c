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
  int nthreads, tid;

  /* Fork a team of threads */
  #pragma omp parallel
  {
  /* Obtain thread number */
  tid = omp_get_thread_num();
  nthreads = omp_get_num_threads();
  printf("Greeting from thread = %d on %d \n", tid,nthreads);
  }  /* end of parallel region, all threads join master */
}


