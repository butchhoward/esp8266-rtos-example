#include "unity_fixture.h"
#include "fff.h"
#include <stdbool.h>

#include "blinken_lights.h"

#include "led.h"
#include "led_internal.h"


DEFINE_FFF_GLOBALS;

FAKE_VOID_FUNC(led_setup_pin_mock, gpio_num_t);
FAKE_VOID_FUNC(led_on_pin_mock, gpio_num_t);
FAKE_VOID_FUNC(led_off_pin_mock, gpio_num_t);
FAKE_VOID_FUNC(vTaskDelay_mock, const TickType_t); 


TEST_GROUP(blinken_lights);

TEST_SETUP(blinken_lights) 
{
    FFF_RESET_HISTORY();
    RESET_FAKE(led_setup_pin_mock);
    RESET_FAKE(led_on_pin_mock);
    RESET_FAKE(led_off_pin_mock);

    led_setup_pin = led_setup_pin_mock;
    led_on_pin = led_on_pin_mock;
    led_off_pin = led_off_pin_mock;
    vTaskDelay_impl = vTaskDelay_mock;
}

TEST_TEAR_DOWN(blinken_lights) 
{
    led_setup_pin = led_setup_pin_impl;
    led_on_pin = led_on_pin_impl;
    led_off_pin = led_off_pin_impl;
    vTaskDelay_impl = vTaskDelay;
}

TEST(blinken_lights, set_configures_leds)
{
    blinken_setup();

    TEST_ASSERT_EQUAL(2, led_setup_pin_mock_fake.call_count);
    TEST_ASSERT_EQUAL(LEDS_BUILTIN_RED, led_setup_pin_mock_fake.arg0_history[0]);
    TEST_ASSERT_EQUAL(LEDS_BUILTIN_BLUE, led_setup_pin_mock_fake.arg0_history[1]);
}

TEST(blinken_lights, loop_does_behavior)
{
    blinken_loop();

    TEST_ASSERT_EQUAL(fff.call_history[0], (void *)led_on_pin_mock);
    TEST_ASSERT_EQUAL(fff.call_history[1], (void *)vTaskDelay_mock);
    TEST_ASSERT_EQUAL(fff.call_history[2], (void *)led_on_pin_mock);
    TEST_ASSERT_EQUAL(fff.call_history[3], (void *)vTaskDelay_mock);
    TEST_ASSERT_EQUAL(fff.call_history[4], (void *)led_off_pin_mock);
    TEST_ASSERT_EQUAL(fff.call_history[5], (void *)led_off_pin_mock);
    TEST_ASSERT_EQUAL(fff.call_history[6], (void *)vTaskDelay_mock);
}

TEST_GROUP_RUNNER(blinken_lights) 
{
    RUN_TEST_CASE(blinken_lights, set_configures_leds);
    RUN_TEST_CASE(blinken_lights, loop_does_behavior);
}
