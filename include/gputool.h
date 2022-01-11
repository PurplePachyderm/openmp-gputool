#include <stdio.h>
#include <assert.h>
#include <execinfo.h>
#include <inttypes.h>
#include <omp.h>
#include <omp-tools.h>
#include <stdio.h>
#include <sys/resource.h>



static ompt_get_thread_data_t ompt_get_thread_data;
static ompt_get_unique_id_t ompt_get_unique_id;


	// Callbacks registration

#define register_callback_t(name, type)                                        \
  do {                                                                         \
    type f_##name = &on_##name;                                                \
    if (ompt_set_callback(name, (ompt_callback_t)f_##name) == ompt_set_never)  \
      printf("0: Could not register callback '" #name "'\n");                  \
  } while (0)

#define register_callback(name) register_callback_t(name, name##_t)


	// Tool data

static unsigned int nDevices = 0;


	// Callback functions


int ompt_initialize(
	ompt_function_lookup_t lookup,
	int initial_device_num, ompt_data_t *tool_data
);

void ompt_finalize(ompt_data_t *tool_data);

ompt_start_tool_result_t *ompt_start_tool(
	unsigned int omp_version,
	const char *runtime_version
);

typedef void (*ompt_callback_device_initialize_t) (
	int device_num,
	const char *type,
	ompt_device_t *device,
	ompt_function_lookup_t lookup,
	const char *documentation
);


	// Tool initialization function

ompt_start_tool_result_t *ompt_start_tool(
	unsigned int omp_version,
	const char *runtime_version
);
