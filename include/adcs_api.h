#ifndef ASDC_API_H
#define ASDC_API_H

#include "adcs_errno.h"

typedef struct _AdcsOutput {
  int dupa;
} AdcsOutput;

ADCS_ERROR asdc_api_run_detumbling(AdcsOutput* output);

ADCS_ERROR asdc_api_run_sunpointing(AdcsOutput* output);

#endif /* ASDC_API_H */
