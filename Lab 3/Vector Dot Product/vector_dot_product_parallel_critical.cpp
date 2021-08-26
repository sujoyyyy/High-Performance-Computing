/*
* @Author: prateek
* @Date:   2021-08-26 16:20:56
* @Last Modified by:   prateek
* @Last Modified time: 2021-08-26 16:28:16
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>
#define VECTOR_LENGTH 10000
int main (int argc, char *argv[])
{

    double arr_1[VECTOR_LENGTH] ;
    double arr_2[VECTOR_LENGTH] ;
    double start, end;
    for (int i = 0; i < VECTOR_LENGTH; i++)
    {
        arr_1[i] = arr_2[i] = i * 1.0;
    }
    int i;
    double sum = 0;
    double psum = 0;

    start = omp_get_wtime();

    #pragma omp parallel shared(arr_1,arr_2,sum) private(i,psum)
    {   
        psum = 0.0;
        #pragma omp for
        for (int k = 0; k < 1000000; k++)
        {
            for ( i = 0; i < VECTOR_LENGTH; i++)
            {
                psum += arr_1[i] * arr_2[i];
            }
            #pragma omp critical    
            {
                sum+=psum;
            }
        }
    }
    end = omp_get_wtime();
    printf("%lf", end - start);

    return 0;

}