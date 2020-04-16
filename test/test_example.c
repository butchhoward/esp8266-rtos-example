#include "unity_fixture.h"
#include "fff.h"
#include <stdbool.h>

DEFINE_FFF_GLOBALS;

FAKE_VOID_FUNC(example_mock);

TEST_GROUP(example);

TEST_SETUP(example) 
{
    RESET_FAKE(example_mock);
}

TEST_TEAR_DOWN(example) 
{
}

TEST(example, has_a_test_that_fails)
{
    TEST_ASSERT_EQUAL(1, example_mock_fake.call_count);
}

TEST(example, has_a_test_that_passes)
{
    TEST_ASSERT_TRUE(true);
}

TEST_GROUP_RUNNER(example) 
{
    RUN_TEST_CASE(example, has_a_test_that_fails);
    RUN_TEST_CASE(example, has_a_test_that_passes);
}
