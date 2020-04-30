#include "unity_fixture.h"
#include "fff.h"
#include <stdbool.h>

#include "led.h"
#include "led_internal.h"

#include "fake_gpio.h"

DEFINE_FFF_GLOBALS;

FAKE_VALUE_FUNC(esp_err_t, gpio_set_level_mock,gpio_num_t, uint32_t);
FAKE_VALUE_FUNC(esp_err_t, gpio_set_direction_mock, gpio_num_t, gpio_mode_t);

//Faking this is limited because the pointer that is passed is on the stack during led_setup, so is 
//gone by the time we get back to the test function
//This is why the function in 'mock/fake_gpio.c' captures the data and uses the helper functions 
//to access it.
//
// FAKE_VALUE_FUNC(esp_err_t, gpio_config_mock, const gpio_config_t*);

TEST_GROUP(led);

TEST_SETUP(led) 
{
    FFF_RESET_HISTORY();
    RESET_FAKE(gpio_set_level_mock);
    RESET_FAKE(gpio_set_direction_mock);
    clear_gpio_config_fake_last_arg();
}

TEST_TEAR_DOWN(led) 
{
    gpio_set_level_impl = gpio_set_level;
    gpio_set_direction_impl = gpio_set_direction;
    gpio_config_impl = gpio_config;
}

TEST(led, on_turns_builtin_led_on)
{
    gpio_set_level_impl = gpio_set_level_mock;
    led_on();
    TEST_ASSERT_EQUAL(1, gpio_set_level_mock_fake.call_count);
    TEST_ASSERT_EQUAL(LED_BUILTIN, gpio_set_level_mock_fake.arg0_history[0]);
    TEST_ASSERT_EQUAL(LOW_LEVEL, gpio_set_level_mock_fake.arg1_history[0]);
}

TEST(led, off_turns_builtin_led_off)
{
    gpio_set_level_impl = gpio_set_level_mock;
    led_off();
    TEST_ASSERT_EQUAL(1, gpio_set_level_mock_fake.call_count);
    TEST_ASSERT_EQUAL(LED_BUILTIN, gpio_set_level_mock_fake.arg0_history[0]);
    TEST_ASSERT_EQUAL(HIGH_LEVEL, gpio_set_level_mock_fake.arg1_history[0]);
}


TEST(led, setup_configures_led_output)
{
    led_setup();

    gpio_config_t gpio_config_arg = get_gpio_config_fake_last_arg();

    TEST_ASSERT_EQUAL((1ULL << LED_BUILTIN), gpio_config_arg.pin_bit_mask);
    TEST_ASSERT_EQUAL(GPIO_MODE_OUTPUT, gpio_config_arg.mode);
}


TEST_GROUP_RUNNER(led) 
{
    RUN_TEST_CASE(led, on_turns_builtin_led_on);
    RUN_TEST_CASE(led, off_turns_builtin_led_off);
    RUN_TEST_CASE(led, setup_configures_led_output);
    // RUN_TEST_CASE(led, setup_really_configures_led_output);

}
