/*
* @Author: prateek
* @Date:   2021-08-26 17:23:12
* @Last Modified by:   prateek
* @Last Modified time: 2021-08-26 17:32:18
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>
#define N 100000
int main (int argc, char *argv[])
{

    double start, end;

    int i;
    double sum = 0;
    double psum = 0;

    start = omp_get_wtime();

    #pragma omp parallel shared(sum) private(i,psum)
    {
        #pragma omp for
        for (int k = 0; k < 100000; k++)
        {
            sum=0.0;
            psum = 0.0;
            for ( i = 0; i < N; i++)
            {
                psum += i;
            }
            #pragma omp critical
            {
                sum += psum;
            }
        }
    }
    end = omp_get_wtime();
    printf("%lf", end - start);

    return 0;

}