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
  int i,synch, nthreads, tid;
  synch=0;
  /* Fork a team of threads */
  #pragma omp parallel private(tid,nthreads)
  {
  tid=omp_get_thread_num();
  nthreads=omp_get_num_threads();
  if (tid == 0)
  {
     for (i=0;i<10000;i++)
     {
        #pragma omp flush(synch)
        if (synch == nthreads-1) break;
     }
     printf("master = %d, i = %d \n", tid,i);
  }
  else 
  {
     for (i=0;i<10000;i++)
     {
        #pragma omp flush(synch)
        if (synch == tid-1) break;
     }
     printf("thread id = %d, i = %d \n", tid,i);
  } 
  printf("thread id = %d, synch = %d \n", tid,synch);
  synch=tid;
  } 
}
