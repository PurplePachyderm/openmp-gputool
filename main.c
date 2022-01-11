#include <stdio.h>
#include <string.h>

#include "include/gputool.h"
#include "include/tests.h"


void displayHelp() {
	printf("\n");

	printf("Usage : main [param]\n");
	printf("Please, choose only one of the following parameters to test the tool :\n\n");

	printf("	-t: simply launch a few threads printing their number\n");
	printf("	-s: launch a saxpy kernel\n");

	printf("\n");
}


int main(int argc, char * argv[]) {

	if(argc != 2) {
		displayHelp();
		return 1;
	}

	printf("Version: %d.\n", _OPENMP);
	printf("Number of devices : %d\n", omp_get_num_devices());


	char * param = argv[1];

	if(!strcmp(param, "-t")) {
		launchThreads();
	}
	else if(!strcmp(param, "-s")) {
		launchSaxpy();
	}
	else {
		displayHelp();
		return 1;
	}

	return 0;
}
