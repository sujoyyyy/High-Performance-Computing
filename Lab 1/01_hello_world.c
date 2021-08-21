#include <omp.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
	int omp_rank, omp_threads;
	#pragma omp parallel private(omp_rank)

	{
		omp_set_dynamic(0);

		omp_rank = omp_get_thread_num();
		omp_threads = omp_get_num_threads();
		printf("Hello World (%d) from total threads : (%d) \n", omp_rank, omp_threads);
	}


	return 0;
}