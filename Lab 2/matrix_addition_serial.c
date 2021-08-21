/*
* @Author: prateek
* @Date:   2021-08-19 17:20:58
* @Last Modified by:   prateek
* @Last Modified time: 2021-08-19 17:33:27
*/

#include <stdio.h>
#include <time.h>
#include <omp.h>

#define size 100

int main ()
{
	int i, j, p;
	
	double a[size][size] = {999.956};
	double b[size][size] = {4516.524};
	double c[size][size];
	double start, end;


		start = omp_get_wtime (); //addition starts here

			for (i = 0; i < size; i++)
			{
				for (j = 0; j < size; j++)
				{

					for(int k = 0;k<100000;k++)
					c[i][j] = a[i][j] + b[i][j];
				}
			}

		end = omp_get_wtime (); //addition ends here

		printf ("%f \n", end - start);
		
		return 0;
	}

