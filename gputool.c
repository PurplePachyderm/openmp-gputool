#include "gputool.h"


	// Callback functions

// Executed at OpenMP initialization
int ompt_initialize(
	ompt_function_lookup_t lookup,
	int initial_device_num, ompt_data_t *tool_data
) {

	printf("Entering ompt_initialize\n");
	printf("Leaving ompt_initialize\n");

	return 1; // success: activates tool
}



// Executed at OpenMP shutdown
void ompt_finalize(ompt_data_t *tool_data) {
	printf("Entering ompt_finalize\n");
	printf("Leaving ompt_finalize\n");
}



	// Tool initialization function

ompt_start_tool_result_t *ompt_start_tool(
	unsigned int omp_version,
	const char *runtime_version
) {
	printf("Entering ompt_start_tool\n");
	printf("Initializing tool\n");


	// Export tool
	static ompt_start_tool_result_t ompt_start_tool_result = {
		&ompt_initialize,
		&ompt_finalize,

		// omp_data_t
		{}
	};
	printf("Leaving ompt_start_tool\n");
	return &ompt_start_tool_result; // success: registers tool
}
