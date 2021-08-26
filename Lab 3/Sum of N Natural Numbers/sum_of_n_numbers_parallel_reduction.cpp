/*
* @Author: prateek
* @Date:   2021-08-26 17:19:25
* @Last Modified by:   prateek
* @Last Modified time: 2021-08-26 17:21:08
*/
#include <stdio.h>
#include <time.h>
#include <omp.h>

int main(int argc, char const *argv[])
{
    double sum = 0.0;
    double start, end;

    start = omp_get_wtime (); //addition starts here
    #pragma omp parallel for reduction (+:sum)
    
        for (int k = 0; k < 100000; k++)
        {
            sum = 0.0;
            for (int i = 0; i < 100000; i++)
            {
                sum += i;
            }
        }
    
    end = omp_get_wtime (); //addition starts here
    printf("%lf", end - start);

    return 0;
}