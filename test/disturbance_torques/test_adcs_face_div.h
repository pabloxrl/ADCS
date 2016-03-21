#ifndef TEST_ADCS_FACE_DIV_H
#define TEST_ADCS_FACE_DIV_H

class Test_ADCS_face_div {};

#ifdef __cplusplus
extern "C" {
#endif

void initialize_absortion_coefficient(double *coefficient, int i);

void initialize_specular_reflection_coefficient(double *coefficient, int i);

void initialize_diffuse_reflection_coefficient(double *coefficient, int i);

void initialize_center_of_pressure(double center_of_pressure[], int i);

void initialize_surface(double *surface, int i);

void initialize_unit_vector(double normal_vector[], int i);

#ifdef __cplusplus
}
#endif

#endif /* TEST_ADCS_FACE_DIV_H */
