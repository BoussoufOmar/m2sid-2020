#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[]) 
{
    int x, y, z;
    int a, b, c;
    #pragma omp parallel
    {
        #pragma omp single
        {
            #pragma omp task depend( out: x )
            {
                x = 2;
            }
            #pragma omp task depend( in: x ) depend( out: y)
            {
                y = x*x;
            }
            #pragma omp task depend( in: x ) depend( out: z)
            {
                z = x*x;
            }
            #pragma omp task depend( in: x, y,z  )
            {
                printf("x %d, y %d, z %d \n",x,y,z);
            }
        }
    } 
} 
