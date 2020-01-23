#include <stdlib.h>
#include <stdio.h>
float sum(const float *a, size_t n)
{
    // base cases
    if (n == 0) {
        return 0;
    }
    else if (n == 1) {
        return *a;
    }
    // recursive case
    size_t half = n / 2;
    return sum(a, half) + sum(a + half, n - half);
}


float omp_sum(const float *a, size_t n)
{
    // base cases
    if (n == 0) {
        return 0;
    }
    else if (n == 1) {
        return *a;
    }
    // recursive case
    size_t half = n / 2;
    float x, y;
    #pragma omp parallel
    {
      #pragma omp single //nowait
      {
        #pragma omp task shared(x) 
        x=omp_sum(a,half);
        #pragma omp task shared(y) 
        y=omp_sum(a+half,n-half);
        #pragma omp taskwait
        x+=y;
      }
    }
    return x;
}



int main(int argc, char *argv[])
{
    int i,n= atoi(argv[1]);
    float *a;
    float s;
    a = malloc(n * sizeof(float));
    for (i=0;i<n;i++)
        a[i]=i+1;
    s=omp_sum(a,n);
    printf("end a %f, s %f \n",a[n-1],s);
    free(a);
    return 0;
}
