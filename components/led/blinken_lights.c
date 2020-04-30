#include "blinken_lights.h"

#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include "led.h"
#include "led_internal.h"

void blinken_setup(void)
{
    led_setup_pin(LEDS_BUILTIN_RED);
    led_setup_pin(LEDS_BUILTIN_BLUE);
}

void blinken_loop(void)
{
    led_on_pin(LEDS_BUILTIN_BLUE);
    vTaskDelay_impl(1000 / portTICK_RATE_MS);
    led_on_pin(LEDS_BUILTIN_RED);
    vTaskDelay_impl(1000 / portTICK_RATE_MS);

    led_off_pin(LEDS_BUILTIN_RED);
    led_off_pin(LEDS_BUILTIN_BLUE);
    vTaskDelay_impl(1000 / portTICK_RATE_MS);
}
