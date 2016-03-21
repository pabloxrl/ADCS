#include "test_adcs_geomagnetic_field.h"

#include "adcs_geomagnetic_field.h"
#include "adcs_errno.h"

#include "gtest/gtest.h"

#include <string>

namespace {

TEST(Test_ADCS_Geomagnetic_Field, load_coefficients_from_file_with_nullparam)
{
  ADCS_ERROR err = adcs_geomagnetic_field_get_igrf_coefficients(NULL);

  EXPECT_EQ(err, ADCS_ERROR_NULLPARAM);
}

TEST(Test_ADCS_Geomagnetic_Field, load_coefficients_from_file_with_non_nullparam)
{
  double buffer[IGRF_COEFFICIENTS_SIZE];
  memset(buffer, 0, IGRF_COEFFICIENTS_SIZE);

  ADCS_ERROR err = adcs_geomagnetic_field_get_igrf_coefficients(buffer);

  EXPECT_NE(err, ADCS_ERROR_NULLPARAM);
}

TEST(Test_ADCS_Geomagnetic_Field, load_coefficients_from_file_can_find_the_file)
{
  double buffer[IGRF_COEFFICIENTS_SIZE];
  memset(buffer, 0, IGRF_COEFFICIENTS_SIZE);

  ADCS_ERROR err = adcs_geomagnetic_field_get_igrf_coefficients(buffer);

  EXPECT_NE(err, ADCS_ERROR_FILE_NOT_FOUND);
}

TEST(Test_ADCS_Geomagnetic_Field, parse_positive_exponents_from_coefficients)
{
  char str0[] = "e+000";
  EXPECT_EQ(1, parse_exponent_number(str0));

  char str1[] = "e+001";
  EXPECT_EQ(10, parse_exponent_number(str1));

  char str2[] = "e+002";
  EXPECT_EQ(100, parse_exponent_number(str2));

  char str3[] = "e+003";
  EXPECT_EQ(1000, parse_exponent_number(str3));

  char str4[] = "e+004";
  EXPECT_EQ(10000, parse_exponent_number(str4));
}

TEST(Test_ADCS_Geomagnetic_Field, parse_negative_exponents_from_coefficients)
{
  char str1[] = "e-001";
  EXPECT_EQ(0.1, parse_exponent_number(str1));

  char str2[] = "e-002";
  EXPECT_EQ(0.01, parse_exponent_number(str2));

  char str3[] = "e-003";
  EXPECT_EQ(0.001, parse_exponent_number(str3));

  char str4[] = "e-004";
  EXPECT_EQ(0.0001, parse_exponent_number(str4));
}

TEST(Test_ADCS_Geomagnetic_Field, parse_unsupported_exponents_from_coefficients)
{
  char str1[] = "e-006";
  EXPECT_EQ(-1, parse_exponent_number(str1));
}

TEST(Test_ADCS_Geomagnetic_Field, parse_string_number_to_double)
{
  char str0[] = "123.456";
  EXPECT_EQ(123.456, parse_base_number(str0));

  char str1[] = "0.000000000";
  EXPECT_EQ(0, parse_base_number(str1));

  char str2[] = "-123.456";
  EXPECT_EQ(-123.456, parse_base_number(str2));
}

TEST(Test_ADCS_Geomagnetic_Field, parse_coefficients_from_file) {

  int i;
  double coefficients[IGRF_COEFFICIENTS_SIZE];

  ADCS_ERROR ret = adcs_geomagnetic_field_get_igrf_coefficients(coefficients);

  EXPECT_EQ(ADCS_ERROR_NONE, ret);
}

} // namespace
