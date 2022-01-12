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

