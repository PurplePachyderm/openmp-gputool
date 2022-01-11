#include "include/gputool.h"


	// Callback functions

static void on_ompt_callback_device_initialize(
	int device_num,
	const char *type,
	ompt_device_t *device,
	ompt_function_lookup_t lookup,
	const char *documentation
) {

	printf("Entering ompt_callback_device_initialization\n");
	printf("Leaving ompt_callback_device_initialization\n");
}



static void on_ompt_callback_device_finalize(
	int device_num
) {

	printf("Entering ompt_callback_device_initialization\n");
	printf("Leaving ompt_callback_device_initialization\n");
}



// Executed at OpenMP initialization
int ompt_initialize(
	ompt_function_lookup_t lookup,
	int initial_device_num, ompt_data_t *tool_data
) {

	printf("Entering ompt_initialize\n");

	// Setup
	ompt_set_callback_t ompt_set_callback = (ompt_set_callback_t)lookup("ompt_set_callback");
	ompt_get_thread_data = (ompt_get_thread_data_t)lookup("ompt_get_thread_data");
	ompt_get_unique_id = (ompt_get_unique_id_t)lookup("ompt_get_unique_id");


	// Register callbacks
	// (device-related OMTP callbacks don't seem to be supported by any compiler for now)
	register_callback(ompt_callback_device_finalize);
	register_callback(ompt_callback_device_initialize);

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
