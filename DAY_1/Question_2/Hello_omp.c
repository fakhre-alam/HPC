#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

void main (int argc, char *argv[]) 
{
int nothreads, thrid;


#pragma omp parallel private(nothreads, thrid)
  {

 
  thrid = omp_get_thread_num();
  printf("Hello World from thread = %d\n", thrid);

 
  if (thrid == 0) 
    {
    nothreads = omp_get_num_threads();
    printf("Number of threads = %d\n", nothreads);
    }

  }  

}

