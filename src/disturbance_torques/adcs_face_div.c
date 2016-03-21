#include "disturbance_torques/adcs_face_div.h"
#include "disturbance_torques/adcs_disturbance_torques_coefficients.h"

#include <string.h>
#include <math.h>

void initialize_absortion_coefficient(double *coefficient, int i) {
  switch(i) {
    case 0:
      *coefficient = (0.9 * solar_array_absortion_coefficient) + (0.1 * aluminium_absortion_coefficient);
      break;
    case 1:
    case 2:
      *coefficient = aluminium_absortion_coefficient;
      break;
    case 3:
      *coefficient = (0.5 * solar_array_absortion_coefficient) + (0.5 * aluminium_absortion_coefficient);
      break;
    case 4:
    case 5:
      *coefficient = (0.5 * MLI_absortion_coefficient) + (0.45 * solar_array_absortion_coefficient) + (0.05 * aluminium_absortion_coefficient);
      break;
    default:
      break;
  }
}

void initialize_specular_reflection_coefficient(double *coefficient, int i) {
  switch(i) {
    case 0:
      *coefficient = (0.9 * solar_array_specular_reflection_coefficient) + (0.1 * aluminium_specular_reflection_coefficient);
      break;
    case 1:
    case 2:
      *coefficient = aluminium_specular_reflection_coefficient;
      break;
    case 3:
      *coefficient = (0.5 * solar_array_specular_reflection_coefficient) + (0.5 * aluminium_specular_reflection_coefficient);
      break;
    case 4:
    case 5:
      *coefficient = (0.5 * MLI_specular_reflection_coefficient) + (0.45 * solar_array_specular_reflection_coefficient) + (0.05 * aluminium_specular_reflection_coefficient);
      break;
    default:
      break;
  }
}

void initialize_diffuse_reflection_coefficient(double *coefficient, int i) {
  switch(i) {
    case 0:
      *coefficient = (0.9 * solar_array_diffuse_reflection_coefficient) + (0.1 * aluminium_diffuse_reflection_coefficient);
      break;
    case 1:
    case 2:
      *coefficient = aluminium_diffuse_reflection_coefficient;
      break;
    case 3:
      *coefficient = (0.5 * solar_array_diffuse_reflection_coefficient) + (0.5 * aluminium_diffuse_reflection_coefficient);
      break;
    case 4:
    case 5:
      *coefficient = (0.5 * MLI_diffuse_reflection_coefficient) + (0.45 * solar_array_diffuse_reflection_coefficient) + (0.05 * aluminium_diffuse_reflection_coefficient);
      break;
    default:
      break;
  }
}

void initialize_center_of_pressure(double center_of_pressure[], int i) {
  switch(i) {
    case 0:
      center_of_pressure[0] = 0.05;
      center_of_pressure[1] = 0;
      center_of_pressure[2] = 0;
      break;
    case 1:
      center_of_pressure[0] = 0;
      center_of_pressure[1] = 0;
      center_of_pressure[2] = 0.1;
      break;
    case 2:
      center_of_pressure[0] = 0;
      center_of_pressure[1] = 0;
      center_of_pressure[2] = -0.1;
      break;
    case 3:
      center_of_pressure[0] = -0.05;
      center_of_pressure[1] = 0;
      center_of_pressure[2] = 0;
      break;
    case 4:
      center_of_pressure[0] = 0;
      center_of_pressure[1] = -0.1;
      center_of_pressure[2] = 0;
      break;
    case 5:
      center_of_pressure[0] = 0;
      center_of_pressure[1] = 0.1;
      center_of_pressure[2] = 0;
      break;
    default:
      break;
  }

  center_of_pressure[0] -= inertia_from_origin_to_center_of_mass[0];
  center_of_pressure[1] -= inertia_from_origin_to_center_of_mass[1];
  center_of_pressure[2] -= inertia_from_origin_to_center_of_mass[2];
}

void initialize_surface(double *surface, int i) {
  switch(i) {
    case 0:
      *surface = 0.2 * 0.3;
      break;
    case 1:
    case 2:
      *surface = 0.1 * 0.1;
      break;
    case 3:
      *surface = 0.1 * 0.2;
      break;
    case 4:
    case 5:
      *surface = sqrt(2) * 0.1 * 0.2;
      break;
    default:
      break;
  }
}

void initialize_unit_vector(double normal_vector[], int i) {
  switch(i) {
    case 0:
      normal_vector[0] = 1;
      normal_vector[1] = 0;
      normal_vector[2] = 0;
      break;
    case 1:
      normal_vector[0] = 0;
      normal_vector[1] = 0;
      normal_vector[2] = 1;
      break;
    case 2:
      normal_vector[0] = 0;
      normal_vector[1] = 0;
      normal_vector[2] = -1;
      break;
    case 3:
      normal_vector[0] = -1;
      normal_vector[1] = 0;
      normal_vector[2] = 0;
      break;
    case 4:
      normal_vector[0] = -sqrt(2) / 2;
      normal_vector[1] = -sqrt(2) / 2;
      normal_vector[2] = 0;
      break;
    case 5:
      normal_vector[0] = -sqrt(2) / 2;
      normal_vector[1] = sqrt(2) / 2;
      normal_vector[2] = 0;
      break;
    default:
      break;
  }
}

ADCS_ERROR adcs_disturbance_torques_face_div(SateliteFace* faces) {
  int i;

  if (faces == NULL) {
    return ADCS_ERROR_NULLPARAM;
  }

  for (i = 0; i < NFACES; i++) {
    memset(faces, 0, sizeof(SateliteFace) * NFACES);
  }

  for (i = 0; i < NFACES; i++) {
    initialize_unit_vector(faces[i].normal_vector, i);
    initialize_surface(&faces[i].surface, i);
    initialize_center_of_pressure(faces[i].center_of_pressure, i);
    initialize_diffuse_reflection_coefficient(&faces[i].diffuse_reflection_coefficient, i);
    initialize_specular_reflection_coefficient(&faces[i].specular_reflection_coefficient, i);
    initialize_absortion_coefficient(&faces[i].absortion_coefficient, i);
  }

  return ADCS_ERROR_NONE;
}
