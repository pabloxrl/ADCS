#include "adcs_api.h"
#include "adcs_errno.h"

#include <string.h>

ADCS_ERROR ADCS_api_run_detumbling(AdcsOutput* output) {

  if (!output) {
    return ADCS_ERROR_NULLPARAM;
  }

  memset(output, 0, sizeof(AdcsOutput));

  return ADCS_ERROR_NONE;
}

ADCS_ERROR ADCS_api_run_sunpointing(AdcsOutput* output) {

  if (!output) {
    return ADCS_ERROR_NULLPARAM;
  }

  memset(output, 0, sizeof(AdcsOutput));

  return ADCS_ERROR_NONE;
}
