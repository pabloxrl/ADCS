#include "test_adcs_face_div.h"
#include "adcs_face_div.h"
#include "adcs_disturbance_torques_coefficients.h"

#include "adcs_errno.h"

#include "gtest/gtest.h"

#include <math.h>

namespace {

TEST(Test_ADCS_face_div, retrieve_face_div_with_nullparam)
{
  ADCS_ERROR err = adcs_disturbance_torques_face_div(NULL);

  EXPECT_EQ(err, ADCS_ERROR_NULLPARAM);
}

TEST(Test_ADCS_face_div, initialize_face_number_zero)
{
  int n_face = 0;
  SateliteFace face;
  initialize_unit_vector(face.normal_vector, n_face);

  EXPECT_EQ(1, face.normal_vector[0]);
  EXPECT_EQ(0, face.normal_vector[1]);
  EXPECT_EQ(0, face.normal_vector[2]);

  initialize_surface(&face.surface, n_face);

  EXPECT_EQ(0.2 * 0.3, face.surface);

  initialize_center_of_pressure(face.center_of_pressure, n_face);

  EXPECT_EQ(0.05 - inertia_from_origin_to_center_of_mass[0], face.center_of_pressure[0]);
  EXPECT_EQ(0 - inertia_from_origin_to_center_of_mass[1], face.center_of_pressure[1]);
  EXPECT_EQ(0 - inertia_from_origin_to_center_of_mass[2], face.center_of_pressure[2]);

  initialize_diffuse_reflection_coefficient(&face.diffuse_reflection_coefficient, n_face);

  EXPECT_EQ((0.9 * solar_array_diffuse_reflection_coefficient) + (0.1 * aluminium_diffuse_reflection_coefficient), face.diffuse_reflection_coefficient);

  initialize_specular_reflection_coefficient(&face.specular_reflection_coefficient, n_face);

  EXPECT_EQ((0.9 * solar_array_specular_reflection_coefficient) + (0.1 * aluminium_specular_reflection_coefficient), face.specular_reflection_coefficient);

  initialize_absortion_coefficient(&face.absortion_coefficient, n_face);

  EXPECT_EQ((0.9 * solar_array_absortion_coefficient) + (0.1 * aluminium_absortion_coefficient), face.absortion_coefficient);
}

TEST(Test_ADCS_face_div, initialize_face_number_one)
{
  int n_face = 1;
  SateliteFace face;
  initialize_unit_vector(face.normal_vector, 1);

  EXPECT_EQ(0, face.normal_vector[0]);
  EXPECT_EQ(0, face.normal_vector[1]);
  EXPECT_EQ(1, face.normal_vector[2]);

  initialize_surface(&face.surface, n_face);

  EXPECT_EQ(0.1 * 0.1, face.surface);

  initialize_center_of_pressure(face.center_of_pressure, n_face);

  EXPECT_EQ(0 - inertia_from_origin_to_center_of_mass[0], face.center_of_pressure[0]);
  EXPECT_EQ(0 - inertia_from_origin_to_center_of_mass[1], face.center_of_pressure[1]);
  EXPECT_EQ(0.1 - inertia_from_origin_to_center_of_mass[2], face.center_of_pressure[2]);

  initialize_diffuse_reflection_coefficient(&face.diffuse_reflection_coefficient, n_face);

  EXPECT_EQ(aluminium_diffuse_reflection_coefficient, face.diffuse_reflection_coefficient);

  initialize_specular_reflection_coefficient(&face.specular_reflection_coefficient, n_face);

  EXPECT_EQ(aluminium_specular_reflection_coefficient, face.specular_reflection_coefficient);

  initialize_absortion_coefficient(&face.absortion_coefficient, n_face);

  EXPECT_EQ(aluminium_absortion_coefficient, face.absortion_coefficient);
}

TEST(Test_ADCS_face_div, initialize_face_number_two)
{
  int n_face = 2;
  SateliteFace face;
  initialize_unit_vector(face.normal_vector, 2);

  EXPECT_EQ(0, face.normal_vector[0]);
  EXPECT_EQ(0, face.normal_vector[1]);
  EXPECT_EQ(-1, face.normal_vector[2]);

  initialize_surface(&face.surface, n_face);

  EXPECT_EQ(0.1 * 0.1, face.surface);

  initialize_center_of_pressure(face.center_of_pressure, n_face);

  EXPECT_EQ(0 - inertia_from_origin_to_center_of_mass[0], face.center_of_pressure[0]);
  EXPECT_EQ(0 - inertia_from_origin_to_center_of_mass[1], face.center_of_pressure[1]);
  EXPECT_EQ(-0.1 - inertia_from_origin_to_center_of_mass[2], face.center_of_pressure[2]);

  initialize_diffuse_reflection_coefficient(&face.diffuse_reflection_coefficient, n_face);

  EXPECT_EQ(aluminium_diffuse_reflection_coefficient, face.diffuse_reflection_coefficient);

  initialize_specular_reflection_coefficient(&face.specular_reflection_coefficient, n_face);

  EXPECT_EQ(aluminium_specular_reflection_coefficient, face.specular_reflection_coefficient);

  initialize_absortion_coefficient(&face.absortion_coefficient, n_face);

  EXPECT_EQ(aluminium_absortion_coefficient, face.absortion_coefficient);
}

TEST(Test_ADCS_face_div, initialize_face_number_three)
{
  int n_face = 3;
  SateliteFace face;
  initialize_unit_vector(face.normal_vector, 3);

  EXPECT_EQ(-1, face.normal_vector[0]);
  EXPECT_EQ(0, face.normal_vector[1]);
  EXPECT_EQ(0, face.normal_vector[2]);

  initialize_surface(&face.surface, n_face);

  EXPECT_EQ(0.1 * 0.2, face.surface);

  initialize_center_of_pressure(face.center_of_pressure, n_face);

  EXPECT_EQ(-0.05 - inertia_from_origin_to_center_of_mass[0], face.center_of_pressure[0]);
  EXPECT_EQ(0 - inertia_from_origin_to_center_of_mass[1], face.center_of_pressure[1]);
  EXPECT_EQ(0 - inertia_from_origin_to_center_of_mass[2], face.center_of_pressure[2]);

  initialize_diffuse_reflection_coefficient(&face.diffuse_reflection_coefficient, n_face);

  EXPECT_EQ((0.5 * solar_array_diffuse_reflection_coefficient) + (0.5 * aluminium_diffuse_reflection_coefficient), face.diffuse_reflection_coefficient);

  initialize_specular_reflection_coefficient(&face.specular_reflection_coefficient, n_face);

  EXPECT_EQ((0.5 * solar_array_specular_reflection_coefficient) + (0.5 * aluminium_specular_reflection_coefficient), face.specular_reflection_coefficient);

  initialize_absortion_coefficient(&face.absortion_coefficient, n_face);

  EXPECT_EQ((0.5 * solar_array_absortion_coefficient) + (0.5 * aluminium_absortion_coefficient), face.absortion_coefficient);
}

TEST(Test_ADCS_face_div, initialize_face_number_four)
{
  int n_face = 4;
  SateliteFace face;
  initialize_unit_vector(face.normal_vector, 4);

  EXPECT_EQ((-sqrt(2)/2), face.normal_vector[0]);
  EXPECT_EQ((-sqrt(2)/2), face.normal_vector[1]);
  EXPECT_EQ(0, face.normal_vector[2]);

  initialize_surface(&face.surface, n_face);

  EXPECT_EQ(sqrt(2) * 0.1 * 0.2, face.surface);

  initialize_center_of_pressure(face.center_of_pressure, n_face);

  EXPECT_EQ(0 - inertia_from_origin_to_center_of_mass[0], face.center_of_pressure[0]);
  EXPECT_EQ(-0.1 - inertia_from_origin_to_center_of_mass[1], face.center_of_pressure[1]);
  EXPECT_EQ(0 - inertia_from_origin_to_center_of_mass[2], face.center_of_pressure[2]);

  initialize_diffuse_reflection_coefficient(&face.diffuse_reflection_coefficient, n_face);

  EXPECT_EQ((0.5 * MLI_diffuse_reflection_coefficient) + (0.45 * solar_array_diffuse_reflection_coefficient) + (0.05 * aluminium_diffuse_reflection_coefficient), face.diffuse_reflection_coefficient);

  initialize_specular_reflection_coefficient(&face.specular_reflection_coefficient, n_face);

  EXPECT_EQ((0.5 * MLI_specular_reflection_coefficient) + (0.45 * solar_array_specular_reflection_coefficient) + (0.05 * aluminium_specular_reflection_coefficient), face.specular_reflection_coefficient);

  initialize_absortion_coefficient(&face.absortion_coefficient, n_face);

  EXPECT_EQ((0.5 * MLI_absortion_coefficient) + (0.45 * solar_array_absortion_coefficient) + (0.05 * aluminium_absortion_coefficient), face.absortion_coefficient);
}

TEST(Test_ADCS_face_div, initialize_face_number_five)
{
  int n_face = 5;
  SateliteFace face;
  initialize_unit_vector(face.normal_vector, 5);

  EXPECT_EQ((-sqrt(2)/2), face.normal_vector[0]);
  EXPECT_EQ((sqrt(2)/2), face.normal_vector[1]);
  EXPECT_EQ(0, face.normal_vector[2]);

  initialize_surface(&face.surface, n_face);

  EXPECT_EQ(sqrt(2) * 0.1 * 0.2, face.surface);

  initialize_center_of_pressure(face.center_of_pressure, n_face);

  EXPECT_EQ(0 - inertia_from_origin_to_center_of_mass[0], face.center_of_pressure[0]);
  EXPECT_EQ(0.1 - inertia_from_origin_to_center_of_mass[1], face.center_of_pressure[1]);
  EXPECT_EQ(0 - inertia_from_origin_to_center_of_mass[2], face.center_of_pressure[2]);

  initialize_diffuse_reflection_coefficient(&face.diffuse_reflection_coefficient, n_face);

  EXPECT_EQ((0.5 * MLI_diffuse_reflection_coefficient) + (0.45 * solar_array_diffuse_reflection_coefficient) + (0.05 * aluminium_diffuse_reflection_coefficient), face.diffuse_reflection_coefficient);

  initialize_specular_reflection_coefficient(&face.specular_reflection_coefficient, n_face);

  EXPECT_EQ((0.5 * MLI_specular_reflection_coefficient) + (0.45 * solar_array_specular_reflection_coefficient) + (0.05 * aluminium_specular_reflection_coefficient), face.specular_reflection_coefficient);

  initialize_absortion_coefficient(&face.absortion_coefficient, n_face);

  EXPECT_EQ((0.5 * MLI_absortion_coefficient) + (0.45 * solar_array_absortion_coefficient) + (0.05 * aluminium_absortion_coefficient), face.absortion_coefficient);
}

}
