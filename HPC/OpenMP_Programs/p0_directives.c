/******************************************************************************
 * * DESCRIPTION:
 * *   OpenMP Example - Get Environment Information - C/C++ Version
 * *   The master thread queries and prints selected environment information.
 * ******************************************************************************/
#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[]) 
{
	int nthreads, tid, procs, maxt, inpar, dynamic, nested;
	/* Start parallel region */
	#pragma omp parallel private(nthreads, tid)
  	{
		/* Obtain thread number */
		  tid = omp_get_thread_num();

		/* Only master thread does this */
		  if (tid == 0) 
		  {
			  printf("Thread %d getting Info..\n", tid);

			  /* Get environment information */
			  cores = omp_get_num_procs();
			  nthreads = omp_get_num_threads();
			  maxt = omp_get_max_threads();
			  inpar = omp_in_parallel();

			  /* Print environment information */
			  printf("Number of cores = %d\n", cores);
			  printf("Number of threads = %d\n", nthreads);
			  printf("Max threads = %d\n", maxt);
			  printf("In parallel? = %d\n", inpar);
		  }
	}  /* Done */
}
