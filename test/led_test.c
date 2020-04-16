#include "unity_fixture.h"
#include "fff.h"
#include <stdbool.h>

#include "led.h"

DEFINE_FFF_GLOBALS;

FAKE_VALUE_FUNC(esp_err_t, gpio_set_level_mock,gpio_num_t, uint32_t);

TEST_GROUP(led);

TEST_SETUP(led) 
{
    RESET_FAKE(gpio_set_level_mock);
}

TEST_TEAR_DOWN(led) 
{
}

TEST(led, on_turns_builtin_led_on)
{
    gpio_set_level_impl = gpio_set_level_mock;
    led_on();
    TEST_ASSERT_EQUAL(1, gpio_set_level_mock_fake.call_count);
}

TEST_GROUP_RUNNER(led) 
{
    RUN_TEST_CASE(led, on_turns_builtin_led_on);
}
