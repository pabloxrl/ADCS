#include "adcs_api.h"
#include "adcs_errno.h"

#include <string.h>

ADCS_ERROR adcs_api_run_detumbling(AdcsOutput* output) {
  
  if (output == NULL) {
    return ADCS_ERROR_NULLPARAM;
  }
  
  return ADCS_ERROR_NONE;
}

ADCS_ERROR adcs_api_run_sunpointing(AdcsOutput* output) {
  
  if (output == NULL) {
    return ADCS_ERROR_NULLPARAM;
  }
  
  return ADCS_ERROR_NONE;
}
