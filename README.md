# HPC( High Performance Computing )
## Assignment Question 
                                             HPC Post Assignment

Q 1. OpenMP  Program for Get Environment Information - C/C++ Version The master thread queries and prints selected environment information. (Number of processors, Number of threads, Dynamic threads enabled? , Nested parallelism enabled?  )

Q2.Write any serial program convert that to openMP, to MPI program.

Q 3. WAP MPI Scatter (Collective Communications)
INPUT: sendbuf[4][4] = {
  {10.0, 20.0, 30.0, 40.0},
  {50.0, 60.0, 70.0, 80.0},
  {90.0, 100.0, 110.0, 120.0},
  {130.0, 140.0, 150.0, 160.0}  }


Q4. WAP for matrix multiplication with MPI

Q. 5 Write any program and apply compiler optimization options (-O1, -O2, -O3 ) and note down timings (apply same dataset)

Q. 6) Port MPI-HMMER application on PARAM SHAVAK and compare time with serial and parallel
Solution

Q. 7) apply gprof profiling for following code
Program: 1
//test_gprof.c
#include<stdio.h>
 
void new_func1(void);
 
void func1(void)
{
    printf("\n Inside func1 \n");
	int i = 0;
 
    for(;i<0xffffffff;i++);
    new_func1();
 
	return;
}
 
static void func2(void)
{
    printf("\n Inside func2 \n");
	int i = 0;
 
    for(;i<0xffffffaa;i++);
	return;
}
 
int main(void)
{
    printf("\n Inside main()\n");
	int i = 0;
 
    for(;i<0xffffff;i++);
	func1();
	func2();
 
	return 0;
}
Program: 2
//test_gprof_new.c
#include<stdio.h>
 
void new_func1(void)
{
    printf("\n Inside new_func1()\n");
	int i = 0;
 
    for(;i<0xffffffee;i++);
 
	return;
}
