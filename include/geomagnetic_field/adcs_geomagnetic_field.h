#ifndef ADCS_GEOMAGNETIC_FIELD_H
#define ADCS_GEOMAGNETIC_FIELD_H

#include "adcs_errno.h"

#define IGRF_COEFFICIENTS_N_COLUMNS   4
#define IGRF_COEFFICIENTS_N_ROWS      104

#define IGRF_COEFFICIENTS_SIZE ((IGRF_COEFFICIENTS_N_COLUMNS)*(IGRF_COEFFICIENTS_N_ROWS))

#ifdef __cplusplus
extern "C" {
#endif

ADCS_ERROR adcs_geomagnetic_field_get_igrf_coefficients(double* coefficients);

#ifdef __cplusplus
}
#endif

#endif /* ADCS_GEOMAGNETIC_FIELD_H */
