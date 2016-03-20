#include "test_adcs_api.h"

#include "adcs_api.h"
#include "adcs_errno.h"

#include "gtest/gtest.h"

namespace {

TEST(Test_ADCS_API, run_detumbling_with_null_parameter)
{
	AdcsOutput output;
	ADCS_ERROR err = adcs_api_run_detumbling(nullptr);

	EXPECT_EQ(err, ADCS_ERROR_NULLPARAM);
}

TEST(Test_ADCS_API, run_detumbling_with_non_null_parameter)
{
	AdcsOutput output;
	ADCS_ERROR err = adcs_api_run_detumbling(&output);

	EXPECT_NE(err, ADCS_ERROR_NULLPARAM);
}

TEST(Test_ADCS_API, run_sunpointing_with_null_parameter)
{
	AdcsOutput output;
	ADCS_ERROR err = adcs_api_run_detumbling(nullptr);

	EXPECT_EQ(err, ADCS_ERROR_NULLPARAM);
}

TEST(Test_ADCS_API, run_sunpointing_with_non_null_parameter)
{
	AdcsOutput output;
	ADCS_ERROR err = adcs_api_run_detumbling(&output);

	EXPECT_NE(err, ADCS_ERROR_NULLPARAM);
}

} // namespace
