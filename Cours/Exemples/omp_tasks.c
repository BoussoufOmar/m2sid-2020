#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[]) 
{
#pragma omp parallel
{
  int i;
  for (i=0;i<10;i++)
  {
      #pragma omp task
      {
      int tid = omp_get_thread_num();
      printf("hello world from a random thread %d \n",tid);
      }
  }
}
}
