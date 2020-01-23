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
  int count, tid;
  count=0;
  #pragma omp parallel private(tid)
  {
  tid=omp_get_thread_num();
  #pragma omp atomic
  count = count + 1 ; 
  printf("thread id = %d, count = %d \n", tid,count);
  }  
  printf("outside region count = %d \n", count);
}
