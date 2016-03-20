#include "api/test_adcs_api.h"
#include "geomagnetic_field/test_adcs_geomagnetic_field.h"

#include "gtest/gtest.h"

int main(int argc, char **argv) {

  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
