#include"mpi.h"
#include<stdio.h>
#include<stdlib.h>
#define N 4                 
int A[N][N], B[N][N], C[N][N], D[N];

void fill_matrix(int m[N][N])
{
  static int n=0;
  int i, j;
  for (i=0; i<N; i++)
    for (j=0; j<N; j++)
      m[i][j] = n++;
}

void print_matrix(int m[N][N])
{
  int i, j = 0;
  for (i=0; i<N; i++) {
    printf("\n\t| ");
    for (j=0; j<N; j++)
      printf("%2d ", m[i][j]);
    printf("|");
  }
}


int main(int argc, char *argv[])
{
  int myrank, P, from, to, i, j, k;

  MPI_Status status;

  MPI_Init (&argc, &argv);
  MPI_Comm_rank(MPI_COMM_WORLD, &myrank);
  MPI_Comm_size(MPI_COMM_WORLD, &P);


  if (N%P!=0) {
    if (myrank==0) printf("Matrix size not divisible by number of processors\n");
    MPI_Finalize();
    exit(-1);
  }

  from = myrank * N/P;
  to = (myrank+1) * N/P;


  if (myrank==0) {
    fill_matrix(A);
   fill_matrix(B);
  }

  for (i=from; i<4;i++)


{
    for (j=0; j<N; j++) {
      C[i][j]=0;
      for (k=0; k<N; k++)
        C[i][j] += A[i][k]*B[k][j];
    }
        from=myrank * N/P;
        to=(myrank+1)*N/P;
}


        

  if (myrank==0) {
    printf("\n\n");
    print_matrix(A);
    printf("\n\n\t       * \n");
    print_matrix(B);
    printf("\n\n\t       = \n");
    print_matrix(C);
    printf("\n\n");
  }

  MPI_Finalize();
  return 0;
}

