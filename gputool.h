#include <omp.h>
#include <omp-tools.h>
#include <stdio.h>

int ompt_initialize(
	ompt_function_lookup_t lookup,
	int initial_device_num, ompt_data_t *tool_data
);

void ompt_finalize(ompt_data_t *tool_data);

ompt_start_tool_result_t *ompt_start_tool(
	unsigned int omp_version,
	const char *runtime_version
);
