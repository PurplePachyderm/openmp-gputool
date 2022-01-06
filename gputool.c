#include "gputool.h"

int ompt_initialize(
	ompt_function_lookup_t lookup,
	int initial_device_num, ompt_data_t *tool_data
) {
	printf(
		"libomp init time: %f\n",
		omp_get_wtime() - *(double *)(tool_data->ptr)
		   );

	*(double *)(tool_data->ptr) = omp_get_wtime();
	return 1; // success: activates tool
}



void ompt_finalize(ompt_data_t *tool_data) {
	printf(
		"application runtime: %f\n",
		omp_get_wtime() - *(double *)(tool_data->ptr)
	);
}



ompt_start_tool_result_t *ompt_start_tool(
	unsigned int omp_version,
	const char *runtime_version
) {
	printf("Initializing tool\n");

	static double time = 0; // static defintion needs constant assigment
	time = omp_get_wtime();

	static ompt_start_tool_result_t ompt_start_tool_result = {
		&ompt_initialize,
		&ompt_finalize,
		{.ptr = &time}
	};
	return &ompt_start_tool_result; // success: registers tool
}
