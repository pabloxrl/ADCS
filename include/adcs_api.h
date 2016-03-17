#ifndef ASDC_API_H
#define ASDC_API_H

#include "adcs_errno.h"

typedef struct _AdcsOutput {
	int dupa;
} AdcsOutput;

#ifdef __cplusplus
extern "C" {
#endif

ADCS_ERROR adcs_api_run_detumbling(AdcsOutput* output);

ADCS_ERROR adcs_api_run_sunpointing(AdcsOutput* output);

#ifdef __cplusplus
}
#endif

#endif /* ASDC_API_H */
