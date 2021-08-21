/*
* @Author: prateek
* @Date:   2021-08-19 15:41:50
* @Last Modified by:   prateek
* @Last Modified time: 2021-08-19 17:08:29
*/

#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <time.h>
#define n 100000
#define m 100000

int main()
{
	double a[n],b[n], c[n], rand_a, rand_b;
	float startTime, endTime,execTime;
	int i;
	int omp_rank;
	srand(time(0));
    // Get the start time 
	startTime = omp_get_wtime();
	#pragma omp parallel private (i) shared (a,b,c)
	{
		#pragma omp for	
		for(i=0;i<n;i++)
		{
			rand_a = rand() , rand_b = rand();
			omp_rank = omp_get_thread_num();
			a[i] = i * rand_a;  	
			b[i] = i * rand_b;	

			for(int j=0;j<m;j++)
				c[i] = a[i] * b[i];
				c[i] = a[i] * b[i];
		}		
	
	}
	// Get the end time 
	endTime = omp_get_wtime();

	// Get the total execution time : 
	execTime = endTime - startTime;
	printf("%f \n",execTime);
	return(0);
}