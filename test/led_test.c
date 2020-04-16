#include "unity_fixture.h"
#include "fff.h"
#include <stdbool.h>

#include "led.h"
#include "led_internal.h"

DEFINE_FFF_GLOBALS;

FAKE_VALUE_FUNC(esp_err_t, gpio_set_level_mock,gpio_num_t, uint32_t);
FAKE_VALUE_FUNC(esp_err_t, gpio_set_direction_mock, gpio_num_t, gpio_mode_t);

TEST_GROUP(led);

TEST_SETUP(led) 
{
    RESET_FAKE(gpio_set_level_mock);
    RESET_FAKE(gpio_set_direction_mock);
}

TEST_TEAR_DOWN(led) 
{
}

TEST(led, on_turns_builtin_led_on)
{
    gpio_set_level_impl = gpio_set_level_mock;
    led_on();
    TEST_ASSERT_EQUAL(1, gpio_set_level_mock_fake.call_count);
    TEST_ASSERT_EQUAL(LED_BUILTIN, gpio_set_level_mock_fake.arg0_history[0]);
    TEST_ASSERT_EQUAL(LOW_LEVEL, gpio_set_level_mock_fake.arg1_history[0]);
}

TEST(led, setup_configures_led_output)
{
    gpio_set_direction_impl = gpio_set_direction_mock;
    led_setup();
    TEST_ASSERT_EQUAL(1, gpio_set_direction_mock_fake.call_count);
    TEST_ASSERT_EQUAL(LED_BUILTIN, gpio_set_direction_mock_fake.arg0_history[0]);
    TEST_ASSERT_EQUAL(GPIO_MODE_OUTPUT, gpio_set_direction_mock_fake.arg1_history[0]);
}


TEST_GROUP_RUNNER(led) 
{
    RUN_TEST_CASE(led, on_turns_builtin_led_on);
    RUN_TEST_CASE(led, setup_configures_led_output);

}
