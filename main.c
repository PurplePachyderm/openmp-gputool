#include <omp.h>
#include <stdio.h>
#include "gputool.h"

int main() {

	printf("Number of devices : %d\n", omp_get_num_devices());
	#pragma omp parallel num_threads(4)
	{
		printf("Hello from thread %i of %i!\n", omp_get_thread_num(),
		omp_get_num_threads());
	}

	return 0;
}
