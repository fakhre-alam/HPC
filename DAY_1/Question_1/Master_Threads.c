#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[]) 
{
  int number_of_threads, tid, processor, maxthread, inparallel, dynamic, nested;


   #pragma omp parallel private(number_of_threads, tid)
       {

	   tid = omp_get_thread_num();

	   if (tid == 0) 
	{
	    printf("Thread %d getting environment info...\n", tid);

	    processor = omp_get_num_procs();
	    number_of_threads = omp_get_num_threads();
	    maxthread = omp_get_max_threads();
	    inparallel = omp_in_parallel();
	    dynamic = omp_get_dynamic();
	    nested = omp_get_nested();

	    printf("Number of processors = %d\n", processor);
	    printf("Number of threads = %d\n", number_of_threads);
	    printf("Max threads = %d\n", maxthread);
	    printf("In parallel? = %d\n", inparallel);
	    printf("Dynamic threads enabled? = %d\n", dynamic);
	    printf("Nested parallelism enabled? = %d\n", nested);

       }

     } 

}

