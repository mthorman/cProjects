//Michael Thorman
//CSCI490/Fall 2021
//Use MPI to implement 1D Blocked Column Algorithm to compute double-precision Matrix Multiplication with 1xP processes
//Processes = 2, 4, 12, 24, 48, 64
//N values = 100, 200, 300, 400, 500, 600, 700, 800, 900, 1000
#include <stdlib.h>
#include <stdio.h>
#include "mpi.h"
#include <time.h>
#include <sys/time.h>
#include "cblas.h"

#define N 700

MPI_Status status;

double a[N][N],b[N][N],c[N][N];
double cblasA[N*N], cblasB[N*N], cblasC[N*N];
double start_time, finish_time, final_time;
int i, j, k;

int main(int argc, char **argv)
{
    double start_time, finish_time, final_time;
    int i, j, k;
    int num_procs, my_rank, task_count, source, dest, rows, offset;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
    MPI_Comm_size(MPI_COMM_WORLD, &num_procs);
    task_count = num_procs - 1;

 if (my_rank == 0) {

      for (i=0; i<N; i++){
         for (j=0; j<N; j++){
            a[i][j]= ((double)rand()*(10-1))/((double)RAND_MAX)+1;
            cblasA[i*N+j]=a[i][j];
         }
      }
      for (i=0; i<N; i++){
         for (j=0; j<N; j++){
            b[i][j]= ((double)rand()*(10-1))/((double)RAND_MAX)+1;
            cblasB[i*N+j]=b[i][j];
         }
      }
    cblas_dgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans,N, N, N,1.0,cblasA, N, cblasB, N, 1.0, cblasC, N);

    rows = N/task_count;
    offset = 0;
    start_time = MPI_Wtime();
    for (dest=1; dest <= task_count; dest++)
    {
      MPI_Send(&offset, 1, MPI_INT, dest, 1, MPI_COMM_WORLD);
      MPI_Send(&rows, 1, MPI_INT, dest, 1, MPI_COMM_WORLD);
      MPI_Send(&a[offset][0], rows*N, MPI_DOUBLE,dest,1, MPI_COMM_WORLD);
      MPI_Send(&b, N*N, MPI_DOUBLE, dest, 1, MPI_COMM_WORLD);
      offset = offset + rows;
    }

    for (int i = 1; i <= task_count; i++)
    {
      source = i;
      MPI_Recv(&offset, 1, MPI_INT, source, 2, MPI_COMM_WORLD, &status);
      MPI_Recv(&rows, 1, MPI_INT, source, 2, MPI_COMM_WORLD, &status);
      MPI_Recv(&c[offset][0], rows*N, MPI_DOUBLE, source, 2, MPI_COMM_WORLD, &status);
    }
      finish_time = MPI_Wtime();
      final_time = finish_time - start_time;
      printf("Finished computation in %f seconds.", final_time);
  }


  if (my_rank > 0) {
    source = 0;
    MPI_Recv(&offset, 1, MPI_INT, source, 1, MPI_COMM_WORLD, &status);
    MPI_Recv(&rows, 1, MPI_INT, source, 1, MPI_COMM_WORLD, &status);
    MPI_Recv(&a, rows*N, MPI_DOUBLE, source, 1, MPI_COMM_WORLD, &status);
    MPI_Recv(&b, N*N, MPI_DOUBLE, source, 1, MPI_COMM_WORLD, &status);
    for (int k = 0; k<N; k++) {
      for (int i = 0; i<rows; i++) {
        c[i][k] = 0.0;
        for (int j = 0; j<N; j++)
          c[i][k] = c[i][k] + a[i][j] * b[j][k];
      }
    }
    MPI_Send(&offset, 1, MPI_INT, 0, 2, MPI_COMM_WORLD);
    MPI_Send(&rows, 1, MPI_INT, 0, 2, MPI_COMM_WORLD);
    MPI_Send(&c, rows*N, MPI_DOUBLE, 0, 2, MPI_COMM_WORLD);
  }
  MPI_Finalize();
  return 0;
}


