#include "adcs_api.h"
#include "adcs_errno.h"

#include "geomagnetic_field/adcs_geomagnetic_field.h"
#include "disturbance_torques/adcs_face_div.h"

#include <string.h>

ADCS_ERROR adcs_api_run_detumbling(AdcsOutput* output) {
  double coefficients[IGRF_COEFFICIENTS_SIZE];
  SateliteFace faces[NFACES];

  ADCS_ERROR err = ADCS_ERROR_NONE;

  if (output == NULL) {
    return ADCS_ERROR_NULLPARAM;
  }

  memset(coefficients, 0, IGRF_COEFFICIENTS_SIZE);

  err = adcs_geomagnetic_field_get_igrf_coefficients(coefficients);
  if (err != ADCS_ERROR_NONE) {
    return err;
  }

  err = adcs_disturbance_torques_face_div(faces);
  if (err != ADCS_ERROR_NONE) {
    return err;
  }

  return ADCS_ERROR_NONE;
}

ADCS_ERROR adcs_api_run_sunpointing(AdcsOutput* output) {
  if (output == NULL) {
    return ADCS_ERROR_NULLPARAM;
  }

  return ADCS_ERROR_NONE;
}
