#ifndef ADCS_FACE_DIV_H
#define ADCS_FACE_DIV_H

#include "adcs_errno.h"

#define NFACES  6

typedef struct _SateliteFace {
  double normal_vector[3];
  double surface;
  double center_of_pressure[3];
  double diffuse_reflection_coefficient;
  double specular_reflection_coefficient;
  double absortion_coefficient;
} SateliteFace;

#ifdef __cplusplus
extern "C" {
#endif

ADCS_ERROR adcs_disturbance_torques_face_div(SateliteFace* faces);

#ifdef __cplusplus
}
#endif

#endif /* ADCS_FACE_DIV_H */
