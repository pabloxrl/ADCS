#ifndef ADCS_DISTURBANCE_TORQUES_COEFFICIENTS_H
#define ADCS_DISTURBANCE_TORQUES_COEFFICIENTS_H

const double aluminium_absortion_coefficient = 0.06;
const double aluminium_specular_reflection_coefficient = 0.1;
const double aluminium_diffuse_reflection_coefficient = 0.84;

const double MLI_absortion_coefficient = 0.05;
const double MLI_specular_reflection_coefficient = 0;
const double MLI_diffuse_reflection_coefficient = 0.95;

const double solar_array_absortion_coefficient = 0.92;
const double solar_array_specular_reflection_coefficient = 0.04;
const double solar_array_diffuse_reflection_coefficient = 0.04;

const double inertia_from_origin_to_center_of_mass[] = {0.005, 0.004, -0.003};

#endif /* ADCS_DISTURBANCE_TORQUES_COEFFICIENTS_H */
