/*
* @Author: prateek
* @Date:   2021-08-26 15:37:42
* @Last Modified by:   prateek
* @Last Modified time: 2021-08-26 15:43:45
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>

#define VECTOR_LENGTH 1000000

double dot_product (int N, double* A, double* B)
{
    double dot=0.0, *a,*b;
    int n,i, nthreads, tid;
	double start, end;
	

	start = omp_get_wtime (); //addition starts here
    #pragma omp parallel default (none) reduction (+: dot) shared (N,A,B) private (n,i, nthreads, tid, a,b)
    {
        nthreads = omp_get_num_threads();
        tid = omp_get_thread_num();

        n = N/nthreads; // Min iter for all threads
        a = A + n*tid; // Ptrs to this threads
        b = B + n*tid; // chunks of X & Y

        if ( tid == nthreads-1 )
            n += N-n*nthreads;

        for(int k=0;k<1000000;k++);

        dot = a[0]*b[0];
        for (i=1; i<n; i++)
            dot += a[i]*b[i];

    }


        end = omp_get_wtime (); //addition ends here
		printf ("%lf\n", end - start);

    return dot;
}

int main (int argc, char *argv[])
{
    int i;
    double vec_A[VECTOR_LENGTH], vec_B[VECTOR_LENGTH], sum;

    for (i=0; i<VECTOR_LENGTH; i++)
        vec_A[i] = vec_B[i] = 1.0*i;

    sum = dot_product(VECTOR_LENGTH, vec_A, vec_B);

    return 0;
}