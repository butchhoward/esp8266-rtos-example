#include "led.h"
#include "led_internal.h"

esp_err_t (*gpio_set_level_impl)(gpio_num_t, uint32_t) = gpio_set_level;
esp_err_t (*gpio_set_direction_impl)(gpio_num_t, gpio_mode_t) = gpio_set_direction;

void led_on(void)
{
    gpio_set_level_impl(LED_BUILTIN, LED_ON_LEVEL);
}

void led_setup(void)
{
    gpio_set_direction_impl(LED_BUILTIN, GPIO_MODE_OUTPUT);
}
